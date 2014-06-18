# -*- coding: utf-8 -*-
from bottle import route, run, Bottle, template, get, request
import subprocess
import os

os.chdir("./../")

simpleSearch = Bottle()

docPath = "./Reuters/"
exePath = "./ir-simple-search.exe"

with simpleSearch:
    @route('/')
    def index():
        return template("./python/index")

    @route('/doc/<id>')
    def staticFile(id):
        print "### get doc: %s" % id
        with open(docPath + id + ".html", "r") as docFile:
            return template("./python/doc", docID=id, doc=docFile.read())

    @get('/query')
    def query():
        q = request.GET.get('q')

        print "### get query: %s" % q

        rawOutput = subprocess.check_output([exePath, q])
        outLines = rawOutput.split("\r\n")
        for x in outLines:
            if x.find("result count") > 0:
                docCount = x.rsplit('##', 2)[1]
                break
        docIDs = [x.rsplit('##', 2)[1] for x in outLines if x.find("##id##") > 0]

        print "### found %s" % docCount

        return template('./python/query',
                        query=q,
                        resultCount=docCount,
                        results=docIDs)

run(app=simpleSearch, host='0.0.0.0', port=8080)
