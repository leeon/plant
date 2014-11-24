---
layout:     note
title:      MySQL 命令
description: 常用的命令
---




#User

###登录

    mysql -u root -p


###权限

创建一个新用户，并将该数据库的权限赋给他

    grant all on test_db.* to ‘newdbuser’ identified by ‘dbuserpassword’;

更新权限

    flush privileges;



-----------


#Database

###创建

    create database test_db

###修改

设置某个数据库编码

    alter database testdb character set utf8;


------------


#Table 

###创建



###修改

