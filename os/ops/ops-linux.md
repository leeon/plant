
#管道
管道是不得不说的Linux命令技巧，不同的命令通过管道组合起来可以实现很多方便的功能。



#文件目录操作

------------------

### _find_

查找文件命令，根据名字的目录或者文件

`find [dir] [-name] [name]` 

*arguments:* 

-  *-ls* 查找文件并显示



### _ls_
显示目录下的文件

`ls [arguments] [Dir]`

*arguments:* 

- *-a* 显示所有文件（包括隐藏）
- *-l* 显示文件的详细信息
- *-i* 显示文件索引节点信息


### _ln_
创建连接（使用绝对路径创建链接）,默认创建硬连接

`ln [arguments] [sourceFile] [targetFile]`

*arguments:* 

- *-s* 创建软连接 [关于软链接](http://www.cnblogs.com/itech/archive/2009/04/10/1433052.html)


### _cat_
显示文件或者链接文件并且打印

`cat filename` 显示一个文件

`cat > filename` 从输入创建一个文件

`cat file1 file2` 将file1的内容追加到file2

*arguments:* 

- *-n*在每一行上加上编号
- *-b*非空行加上编号




###_more_
显示文件内容


###_less_
和more类似也是显示文本，但是可以向前或者向前看

###_head_
从头开始显示一个文件的一部分，默认无参输出10行

`head [-n count] [file ...]`

例如：

    head -n 4 file.md  #显示一个文件的前5行

###_tail_
与head相反，可以和head命令连用来截取部分文本查看

*arguments*

- *-f* 保持刷新读取

例如：

    head -n 20 a.txt | tail -n 2  #显示文件第19行到20行
    tail -f a.log | grep "user1"  #实时查看包含user1的日志内容


###_tar_
tar命令涉及两个概念，打包和压缩。

`tar [option] [target file] [source file]`

*arguments*

- *-c*创建包
- *-x*解开包
- *-t*列出包得内容
- *-r*增加文件到指定包中
- *-u*更新包中的文件

上述命令是tar的五个基本命令，其中每一个都可以搭配参数

- *-v*显示打包解包过程
- *-z*创建或者解开包的时候使用gzip
- *-j*创建活着解开包得时候使用bzip2
- *-f*指定文件的名字

例如：

    tar -vczf img.tar *.jpg  #将当前目录下得jpg文件打包
    tar -vxzf img.tar #将压缩包解包


###_scp_ 

功能和cp一样，但是可以用于远程地址目录之间的数据传输，如果不使用远程地址，它就变成cp命令了，于rsync传输相比优点是对系统io的消耗比较低

`scp [options] [from] [to]`

例如：

    scp /path/local.log user@127.0.0.1:/home/user/path/




#系统监控

### _ps_
查看进程信息

例如：

    ps  #查看当前用户在当前terminal下的进程信息
    ps aux|grep xxx

*arguments:*

- *x* 既显示有终端控制的进程也显示没有终端控制的进程，X只显示有终端控制的

- *-A*显示所有的进程信息
- *-c*不显示进程的绝对路径
- *grep*用正则过滤查看进程
- *-u*指定用户进程
- *-f*显示进程关系



###_top_
性能监测，用于查看各个进程的资源占用情况,动态刷新显示

top [options]

top显示的结果分为两个部分，第一个部分是统计信息区域，包含了当前系统时间、进程统计情况、cpu状态、内存状态、网络情况。第二部分是各个进程的监控，包含信息如下：

+ PID 进程号
+ USER 进程所有者
+ PR 优先级
+ %CPU 
+ %MEM 物理内存
+ COMMAND进程名
+ TIME 进程使用CPU时间

交互式命令：

+ q退出
+ s设置时间间隔
+ t CPU显示开关
+ m 内存显示开关
+ T 按MITE排名
+ P 按CPU排名
+ M 按内存排名
+ u 指定用户进程
+ i 只显示正在运行的进程


###_netstat_
Network status, 检查网络情况

*arguments*

- *-a* 显示有所的socket连接
- *-p* 显示正在使用Socket程序识别码和程序名称
- *-t* 显示TCP连接
- *-u* 显示UDP连接
- *-n* 以数字形式显示数数字




###_df_ 
Disk free, 检查磁盘的使用情况，如果指定dir，则会显示dir所挂载的磁盘空余情况。

`df [options] [dir]`

*arguments:*

- *-h* human-readable 显示方便用户阅读的格式
- *-i* 显示节点情况

###_du_
Disk usage，显示某个目录的所占用的磁盘空间

`du [options] [dir]`

###_lsof_
list open files 用于查看你的进程打开的文件以及其相关进程、端口，需要root权限。

lsof包含的信息包括：

+ COMMAND 进程名称
+ PID 进程标识
+ PPID 父进程标识
+ USER 进程所有者
+ PGID 进程所属组
+ FD 文件描述符

例如：

    lsof file  #显示使用file的所有进程
    lsof +D /usr/lib 递归查找
    lsof | grep '/usr/lib' 与上面同样效果，速度更快
    lsof -u leeon 显示被用户leeon打开的文件
    lsof -c nginx 查看程序Nginx打开的文件 
    lsof -p 1001 查看进程1001打开的文件
    lsof -i 列出所有的网络连接
    lsof -i udp:53 查看53端口的udp连接使用的文件
    lsof -a -u leeon -i 显示用户leeon所有的网络连接




###_iostat_
对系统的整体磁盘情况进行分析

*arguments*

- *-C*显示CPU使用情况
- *-d*显示磁盘使用情况
- *-m*以M为单位
- *-k*以KB为单位
- *-x*显示详细信息


###_vmstat_
用于检测系统的内存运行情况，Unix下使用vm_stat，主要特点是可以按照固定的时间间隔监控内存的使用，显示参数如下：

+ r 运行队列
+ b 阻塞进程数
+ swap 可用交换内存，单位k
+ free 空余物理内存 单位k
+ buff 系统目录等缓冲占用内存大小
+ cache 缓存占用内存大小
+ bi 块设备每秒接收的块数量
+ bo 块设备每秒发出的快数量
+ in 每秒cpu终端次数
+ cs 每秒上下文切换次数（比如系统函数调用引发上下文切换）
+ us 用户cpu时间
+ sy 系统cpu时间
+ id 空闲cpu时间
+ wt 等待io cpu的时间 

例如：

    vmstat 3 #每隔3秒显示刷新一次数据







#权限操作

###_chmod_
改变目录或者文件的权限

> 一个文件权限描述分为10位，第一位表示文件类型，d表示目录，-表示文件。后面9位，每3位一组，分别表示 文件拥有者（u）、同组用户(g)和其他用户(o)的权限。

例如：

    drwxr-xr-x  
    #表示这是一个目录，拥有者可以读写并执行，同组用户只读可执行，其他用户只读可执行
    chmod a+w 1.log  
    #给所有用户加上写权限
    chmod g+x 1.log  
    #给同组用户加上可执行权限
    chmod 777 1.log  
    #给当前用户加上文件的所有权限，777三位分别对应三个用户组权限的2进制

###_chown_
改变一个文件的所属用户或者所属的组

`chown [options] owner[:group] file`

*arguments:*

- *-R*递归的作用于当前目录下得所有目录


#工具

###_sed_

sed是一种流编辑器，通过程序来编辑文本，其基本思路就是正则匹配。

入门（参考CoolShell）：

    sed "s/Steve/Cook/g" AppleInc.txt
    sed "s/Steve/Cook/1" AppleInc.txt  #只替换每行第一个Steve
    sed "s/Steve/Cook/2" AppleInc.txt  #只替换每行第2个Steve
    sed "s/Steve/Cook/3g" AppleInc.txt  #只替换每行第3个Steve之后的

    sed "1,2s/Steve/Cook/g" AppleInc.txt #替换1-2行的内容

s 命令表示替换，我们要把Steve替换为Cook, g表示一行上替换所有匹配，sed不会改变元文本的内容，而是将新的内容重定向。默认输出到屏幕，如果需要更改则使用`-i`命令。

    sed "s/^/#/g" src.cpp

在每一行的开头加上`#`,同理在结尾加可以使用`$`进行匹配

    sed "s/Steve/[&]/g" AppleInc.txt

`&`可以用来表示变量，上面的语句执行后，所有的`Steve`两边会加上`[]`。


###_awk_

awk同样是高大上的工具，主要用于从复杂的文本中抽取特定规则的信息。它的基本工作原理是将一行文本分隔为不同的列，默认以**空格**或者****

入门（参考CoolShell）：

    awk '{print $1 , $4}' AppleInc.txt  #显示文件中第1和第4列的内容

$n表示第n列，其中$0表示整行

    awk '$3==0 && $5=="Steve"' AppleInc.txt #过滤除第3列值为0，第5列值为Steve的数据
    awk '$3>0 {print $0}' AppleInc.txt 过滤和输出结合使用


###_grep_

grep是Linux最常用的过滤文本内容的命令,grep命令常常与Linux管道组合。grep的pattern支持正则匹配。

`grep [options] pattern file`

例如：

    grep Steve AppleInc.txt #在文件中寻找Steve
    grep -i Steve AppleInc.txt #忽略大小写
    grep -n Steve AppleInc.txt #显示行号
    grep -v Steve AppleInc.txt #输出不匹配的行
    grep -c #输出匹配的行数

    grep -R Steve AppleInc.txt #递归子目录




###_wc_

wc命令word count 用于文本统计

例如：

    wc -l #统计行数
    wc -c #统计字节数
    wc -m 统计字符数


 
