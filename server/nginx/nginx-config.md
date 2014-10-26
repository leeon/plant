
#Info
Nginx（发音同engine x）是一款由俄罗斯程序员Igor Sysoev所开发轻量级的网页服务器、反向代理服务器以及电子邮件（IMAP/POP3）代理服务器。Nginx相较于Apache、lighttpd具有占有内存少，稳定性高等优势，并且依靠并发能力强，丰富的模块库以及友好灵活的配置而闻名。

# Setup

###OS X 
开发环境中，在`Mac OS`上安装Nginx非常简单，可以用port或者`homebrew`等软件来安装比如：

    brew install nginx

brew会自动的安装nginx所依赖的其他软件包，新版本`1.2.7`安装完成后会自动开启在`8080`端口。当使用下面命令时：

    sudo nginx

nginx会在`80`端口开启。


###CentOS 


####准备

    yum -y install pcre-devel openssl openssl-devel

####安装
centos yum中默认没有nginx包可以从官网找到rpm

    wget http://nginx.org/packages/centos/6/noarch/RPMS/nginx-release-centos-6-0.el6.ngx.noarch.rpm
    rpm -ivh nginx-release-centos-6-0.el6.ngx.noarch.rpm

上面的包会给yum添加nginx源，下面开始安装

    yum install nginx

####目录

    whereis nginx
    nginx: /usr/sbin/nginx /etc/nginx /usr/share/nginx


1 配置所在目录：/etc/nginx/
2 PID目录：/var/run/nginx.pid
3 错误日志：/var/log/nginx/error.log
4 访问日志：/var/log/nginx/access.log
5 默认站点目录：/usr/share/nginx/html


####issue

**403问题**：设置html所有父目录为755权限，设置文件为644权限可以避免权限不正确



#添加站点

在/etc/nginx/conf.d/ 目录下添加 site.conf文件。

###配置Django站点


###配置Tomcat站点


