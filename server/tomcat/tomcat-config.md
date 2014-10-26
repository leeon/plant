---
layout:     note
title:      Tomcat
description: Tomcat环境配置
---

* 目录(this text will be scraped).
{:toc}

#Tomcat

前提是已经安装配置好jdk

##安装
    
移动安装包到/usr/local目录下

    mv apache-tomcat-7.0.29.tar.gz /usr/local
        
解压

    tar -zxv -f apache-tomcat-7.0.29.tar.gz
    rm apache-tomcat-7.0.29.tar.gz
    nv apache-tomcat-7.0.29 tomcat

##启动

    /usr/local/tomcat/bin/startup.sh


