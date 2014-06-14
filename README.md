ir-simple-search
================
CTokenizer 
-------
This class will procees all the documents and create <term, Doc ID> things in a Temp directory. In this directory each token will be a binary file, and in that file is Doc ID which this token is appear in. Every Doc ID is 4-bytes long(int). Below is a demo.<br>
* file name: zhejiang<br>
* file content: 04e0 0000 0a53 0000 17be 0000 23ea 0000<br>

we can know that the term zhejiang appeared in 4 documents.
