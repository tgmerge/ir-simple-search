ir-simple-search
================

一个简单的使用倒排索引的布尔搜索引擎，大概是课程作业 'w'。

by [icdomer](https://github.com/icdomer), [AmemiyaYuko](https://github.com/AmemiyaYuko) and [tgmerge](http://tgmerge.me)

Usage
-----

### EXE

`ir-simple-search "query string"`

query string中可以使用AND, OR, NOT和括号，括号前后必须用空格分隔。例如

`ir-simple-search "said AND ( wheat OR search ) AND NOT tag"`

### WEB

`/python`路径下是一个bottle写的web端，运行`Soda.py`即可。之后请访问

`http://localhost:8080/`

### 其他数据

`data.rar`是已经建立好的索引和Reuters文本，解压缩至根目录下即可。

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