---
layout:     note
title:      MySQL Config
description: 服务端MySQL配置
---


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



