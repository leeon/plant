
#配置FTP服务器

###安装vsftp
使用yum命令安装vsftp
    
    yum install vsftpd -y
###添加ftp帐号和目录
先检查一下nologin的位置，通常在/usr/sbin/nologin或者/sbin/nologin下。
使用下面的命令创建帐户，该命令指定了/home/data为用户pwftp的家目录，您可以自己定义帐户名和目录：
    
    useradd -d /home/data -s /sbin/nologin pwftp

修改该帐户密码:
    
    passwd pwftp

修改指定目录的权限
    
    chown -R pwftp.pwftp /home/data

###配置vsftp
编辑vsftp配置文件，命令如下：
    
    vi /etc/vsftpd/vsftpd.conf

将配置文件中`anonymous_enable=YES`改为 `anonymous_enable=NO`
取消如下配置前的注释符号：
    
    local_enable=YES
    write_enable=YES
    chroot_local_user=YES

保存修改，按ESC键，输入：wq

###修改shell配置
vi编辑/etc/shells，如果该文件里没有/usr/sbin/nologin或者/sbin/nologin（具体看当前系统配置）则追加进去

###启动vsftp服务并测试登录
使用命令启动vsftp服务：

    service vsftpd start

然后用帐号pwftp测试下是否可以登陆ftp。目录是/home/data。