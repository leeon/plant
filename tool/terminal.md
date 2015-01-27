---
layout:     note
title:      iTerm + Zsh
description: 终端利器
---

#iTerm 2

iTerm 2 是一款替代原生系统终端工具的利器，它支持多窗口多标签的操作，同时允许用户自定义很多种主题。

我喜欢的特性：

###自定义主题
在preferences -> Profiles -> Colors -> loadPresets下可以导入本地的主题文件。

我使用的主题文件是：[Solarized](https://github.com/leeon/dotFiles/tree/master/res/iterm)

###多窗口管理
我们可以使用多窗口，也可以使用多标签来操作。

分割当前的窗口可以使用：

`cmd + d` 水平分割窗口

`cmd + shift + d` 垂直分割窗口

`cmd + [` 和 `cmd + ]`在分割窗口之间切换



使用多标签页可以采用

`cmd + n` 创建新的标签页

`cmd + 数字`  在不同的标签中切换

`cmd + w`关闭当前的标签页


其他操作:
`cmd + ;` 显示历史命令
`ctrl + u` 清除当前行命令
`ctrl + a` 快速移到行首
`ctrl + e` 快速移到行尾



#zsh

在Mac上开始

    brew install zsh

    # change shell fot current user
    chsh -s /bin/zsh 


如果觉得每天不断的敲cd命令烦死了人，或者被各种tab扰乱，那么肯能你就是需要换一个终端环境了，那就是zsh。

zsh和原来的bash相比主要的优势就是更多的人性化的操作体验，我喜欢的Feature有:

###命令补全
输入命令加`TAB`键

    cd /u/l/b

得到

    cd /usr/local/bin

###参数选项提示
输入命令加`TAB`键

    ls -

得到ls命令的选项参数列表



###命令历史
输入命令加`UP`键
    
    vim 

得到vim命令后面打开历史


###内置命令映射

    alias | grep cd

可以看到

    -='cd -'
    ..='cd ..'
    ...='cd ../..'
    1='cd -'
    2='cd -2'





### oh-my-zsh
oh-my-zsh是很多程序员使用zsh的一个重要的原因，他是一个管理zsh配置的工具，提供了主题和插件等的管理，下面一段是来自其Github主页的介绍：

> A community-driven framework for managing your zsh configuration. Includes 120+ optional plugins (rails, git, OSX, hub, capistrano, brew, ant, macports, etc), over 120 themes to spice up your morning, and an auto-update tool so that makes it easy to keep up with the latest updates from the community.

安装方法：
可以参照 Github项目主页 ：[链接](https://github.com/robbyrussell/oh-my-zsh)

安装完成后，可以看到你的`~`目录下，多了`.oh-my-zsh`，里面包含了很多主题和插件，可以在`.zshrc`下面进行具体的配置，动手吧。

###参考
我的配置文件放在Github上进行管理，[链接](https://github.com/leeon/dotFiles)









#参考资料

+ [My favourite Zsh features](http://code.joejag.com/2014/why-zsh.html)
