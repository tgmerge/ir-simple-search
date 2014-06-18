ir-simple-search
================

Usage
-----
`ir-simple-search "query string"`

`query string`可以使用`AND, OR, NOT`和括号，括号前后必须用空格分隔。例如

`said AND ( wheat OR search ) AND NOT tag`

`/python`路径下是一个bottle写的web端，运行`Soda.py`即可。之后请访问

`http://localhost:8080/`


CTokenizer 
-------
This class will procees all the documents and create <term, Doc ID> things in a Temp directory. In this directory each token will be a binary file, and in that file is Doc ID which this token is appear in. Every Doc ID is 4-bytes long(int). Below is a demo.<br>
* file name: `zhejiang`<br>
* file content: `04e0 0000` `0a53 0000` `17be 0000` `23ea 0000`<br>

we can know that the term `zhejiang` appeared in `4` documents.

BoolQuery
---------

public方法:

* `ResultSet query(string queryStr)`
    - 以queryStr作检索，返回符合要求的docID列表

自定义类型:

* `typedef vector<long> resultSet`