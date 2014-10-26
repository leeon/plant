#编程语言配置



###Java

选择Java SE JDK 7,下载 rpm包

    http://www.oracle.com/technetwork/java/javase/downloads/jdk7-downloads-1880260.html

安装
    
    rpm -ivh jdk-7-linux-x64.rpm

配置`/etc/profile`

    JAVA_HOME=/usr/java/jdk1.7.0_55
    JRE_HOME=/usr/java/jdk1.7.0_55jre
    PATH=$PATH:$JAVA_HOME/bin:$JRE_HOME/bin
    CLASSPATH=.:$JAVA_HOME/lib/dt.jar:$JAVA_HOME/lib/tools.jar:$JRE_HOME/lib
    export JAVA_HOME JRE_HOME PATH CLASSPATH

###Python

确保安装gcc
    
    yum -y install gcc

下载资源文件

    wget http://python.org/ftp/python/2.7.5/Python-2.7.5.tar.bz2 

解压

    tar -jxvf Python-2.7.5.tar.bz2

安装
    
    cd Pyhton-2.7.5
    ./configure
    make all
    make install
    make clean
    make distclean

备份原有Python版本，并且设置新安装的Python为默认

    mv /usr/bin/python /usr/bin/python2.x
    ln -s /usr/local/bin/python /usr/bin/python

> yum不支持Python2.7 可以修改/usr/bin/yum文件