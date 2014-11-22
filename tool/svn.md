---
layout:     note
title:      SVN
description: SVN 是一款集中式的版本控制工具
---

#Make it clear
使用svn最好要了解它是一个集中式的版本控制工具,我们每个人的开发机上安装的一般是客户端，大家通过一个服务端中央仓库共享数据，每一次提交操作就会有一个通信请求，更新中央仓库。

这样就会理解当我们提交代码后：
    
    svn commit    # commit the code
    svn log       # can't see our latest commit, why?

查看提交历史居然没有我们最新的提交记录，原因就是这些变更记录在了中央仓库,需要我们拉取更新后才能看到

    svn update    # update our workspace with centeral repo
    svn log       # see out commit logs




#基础操作

本部分命令为版本库读取操作。

###svn cat
查看版本库中的一个文件，默认选择`HEAD`版本。

    svn cat http://your-repo.com/some.txt
    svn cat http://your-repo.com/some.txt -r20   #查看特定版本下的文件
    svn cat http://your-repo.com/some.txt.r20    #重定向文件内容到一个文件

###svn list
列出版本库中的目录信息，默认显示`HEAD`版本。
    
    svn list http://your-repo.com/

###svn info
查看目录文件版本信息
    
    svn info url    # remember url can also be local dir or a file



------------

此部分文件目录写操作相关

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



-------


此部分为版本管理相关

###svn checkout
从版本库中检出一个项目到本地。

    svn checkout http://remote.com/repo your-lcoal-dir


###svn add
将文件或者目录加到版本库中，开始跟踪。默认递归添加文件。

    svn add path/dir



###svn log
打印提交记录

    svn log  #显示当前目录下的所有log，从最近开始
    svn log -l 10  #显示最近的10条提交记录
    svn log a.c  #显示某个文件的提交记录
    svn log > commit.log   #将log信息打印到文件里面

> svn log 显示信息不全可能是没有及时`update`导致。
