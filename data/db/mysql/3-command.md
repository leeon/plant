---
layout:     note
title:      MySQL 命令
description: 常用的命令
---




#User

###登录

    mysql -u root -p
    mysql -h 127.0.0.1 -P 3306 -u rrot -p 
    mysql db_name


###权限

创建一个新用户，并将该数据库的权限赋给他

    GRANT ALL ON learn_db.* to ‘newdbuser’ identified by ‘dbuserpassword’;

更新权限

    flush privileges;



-----------


#Database

###查看

    SHOW DATABASES;

###使用
    
    USE learn_db;

###创建

    CREATE DATABASE learn_db;

###修改

设置某个数据库编码

    ALTER DATABASE learn_db character SET utf8;


------------


#Table 

###查看

    SHOW TABLES;

###创建



###修改

