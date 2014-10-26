---
layout:     note
title:      SVN
description: SVN 是一款集中式的版本控制工具
---


* 目录(this text will be scraped).
{:toc}


#基础操作

###svn mkdir 
在版本库中创建目录

    svn mkdir mydir

###svn cp
拷贝版本库中的文件或者目录


###svn mv
移动版本库中的文件或目录 

    svn mv name1.log name2.log 
    svn mv a.c b.c subdir   #将a.c 和 b.c 移动到subdir下
    svn url1 url2  #移动版本库文件

> svn mv 命令相当于 svn cp 和 svn delete 的组合



###svn delete
从本地或者版本库中删除文件

**用例**

####删除本地文件以及版本库中对应文件

    svn delete myfile
    svn commit -m "Delete myfile by path"

也可以直接通过URL直接从版本库中删除

    svn delete -m "delete myfile from url" file:///svn/url/myfile

####删除一个已经修改的文件

    svn delete --force mfile

####删除一个版本库中的文件而不影响本地文件

    svn delete --keep-local file.o
    svn commit -m "delete a file from repository"


###svn log
打印提交记录

    svn log  #显示当前目录下的所有log，从最近开始
    svn log -l 10  #显示最近的10条提交记录
    svn log a.c  #显示某个文件的提交记录
    svn log > commit.log   #将log信息打印到文件里面

> svn log 显示信息不全可能是没有及时`update`导致。
