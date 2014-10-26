---
layout:     note
title:      MySQL
description: 服务端MySQL配置
---


* 目录(this text will be scraped).
{:toc}

#安装

    yum install mysql-server

#配置

###随系统启动

    /sbin/chkconfig --levels 235 mysqld on

###启动守护进程

    /etc/init.d/mysqld start

### 安全脚本配置

    mysql_secure_installation


### 编码配置

检查编码情况 

    show variables like "character%";

修改 /etc/init.d/my.cnf

    [mysqld]
    default-character-set=utf8
    [client]
    default-character-set=utf8
    [mysql]
    default-character-set=utf8

重启服务
    
    /etc/init.d/mysqld restart


设置某个数据库编码

    alter database testdb character set utf8;

###使用root登录

    mysql -u root -p

###创建新的数据库
    
    create database test_db

###用户权限
创建一个新用户，并将该数据库的权限赋给他

    grant all on test_db.* to ‘newdbuser’ identified by ‘dbuserpassword’;

更新权限

    flush privileges;


