---
layout:     note
title:      Sublime Text 3
description: 性感的编辑器
---


> 我使用的是Sublime Text 3

#Usage in terminal

我们可以用过软连接，将`subl`作为terminal可以识别的命令 *（for mac os）*
    
    ln -s "/Applications/Sublime Text.app/Contents/SharedSupport/bin/subl" ~/bin/subl

#Package Control

` command + \`` 调出console，输入下面的代码即可安装

    import urllib.request,os,hashlib; h = '7183a2d3e96f11eeadd761d777e62404' + 'e330c659d4bb41d3bdf022e94cab3cd0'; pf = 'Package Control.sublime-package'; ipp = sublime.installed_packages_path(); urllib.request.install_opener( urllib.request.build_opener( urllib.request.ProxyHandler()) ); by = urllib.request.urlopen( 'http://sublime.wbond.net/' + pf.replace(' ', '%20')).read(); dh = hashlib.sha256(by).hexdigest(); print('Error validating download (got %s instead of %s), please try manual install' % (dh, h)) if dh != h else open(os.path.join( ipp, pf), 'wb' ).write(by)

`shift+command+p` 调出command pannel,通过键入`install`可以快速的安装新的包。


#Config

我的个人配置列表

    {
      "color_scheme": "Packages/User/base16-flat.dark (SL).tmTheme",
      "draw_white_space": "all",
      "font_face": "Ubuntu Mono",
      "font_size": 19.0,
      "highlight_line": true,
      "ignored_packages":
      [
        "Vintage"
      ],
      "tab_size": 4,
      "translate_tabs_to_spaces": true,
      "wide_caret": true,
      "file_exclude_patterns": ["*.pyc", "*.pyo", "*.exe", "*.dll", "*.obj","*.o", "*.d","*.a", "*.lib", "*.so", "*.dylib", "*.ncb", "*.sdf", "*.suo", "*.pdb", "*.idb", "._*", "*.class", "*.psd","*.tgz", "*.sublime-workspace"]
    }




#Features

###Editing 

`command  d` 多选，选择于当前选中words相同的文本

`command  j` join lines 

`command  左右` 行首行尾切换

`command  shift  左右` 快速选中光标至行首\行尾的文本

`alt  左右`  光标跳到下一个或上一个单词

`ctrl  j` 选择Html标签内容

`ctrl  command  上下` 移动某一行


###Navigation

`command  P` 快速的切换文件

`command  R` 在当前文件中切换不同的方法 == `command + P`+`@`

`ctrl  -` 回到上次的位置，相反命令是 `ctrl  shift  +`

`command f` 查找

`commans shift f` 目录查找，可以全局搜索也可以针对目录搜索
 
###Windows and tabs

`command  数字` 快速切换到对应编号的标签页

> sublime中每一个新的窗口成为一个group

`ctrl  数字` 切换光标到对应编号的group

`alt  数字` 将某个文件移到对应编号的组   *修改了默认 key-bindings*

`alt  command  数字` 将窗口分为几列 

`shift  alt  command  数字` 将窗口分为几行



# Plugins

插件的安装方法：

1. 打开command pannel
2. 打开package control
3. 输入要安装的插件


------------


###Emmet

一个用来快速编写前端代码的插件，采用`Zen Coding`的语法规则。

最简单的使用是直接敲标签的名字，比如`div`然后按`Tab`键，会直接产生`<div></div>`的代码，当然emmet还支持更加丰富以及高级的代码生成，类似CSS的选择器，你可以通过快速的编写下面的语句来快速的生成代码。

输入`ul>li`

    <ul>
      <li></li>
    </ul>

输入`ul > li*3`

    
    <ul>
      <li></li>
      <li></li>
      <li></li>
    </ul>

输入`div#navbar>ul>li.item{text}*3`

    <div id="navbar">
      <ul>
        <li class="item">text</li>
        <li class="item">text</li>
        <li class="item">text</li>
      </ul>
    </div>

当然上面的只是emmet很少的一部分功能，作为非前端的用户，已经很方便了。了解详细的语法可以参照emmet的 
<a href="http://docs.emmet.io/" target=_blank>文档</a>


###Git Gutter
Git增强插件，可以显示那些代码是相对于版本库变化的。

![](https://camo.githubusercontent.com/272854f332fd374f50a58060615af911b9798fbc/68747470733a2f2f7261772e6769746875622e636f6d2f6a69736161636b732f4769744775747465722f6d61737465722f73637265656e73686f742e706e67)

###Codecs33
Sublime Text 3 编码支持插件。

###ConvertToUTF8
支持UTF-8 编码。


###AllAutocomplete
Sublime默认只支持单个文件内代码补全提示，这个插件支持全文范围内的代码补全。


###CTags
CTags是一个快速为代码生成索引的工具，通过其创建的索引，可以实现在subl打开的项目中进行数据类型和函数定义的跳转。

在Mac系统中首先安装ctags工具：

    brew install ctags

在SUblime中通说package control安装ctags插件，保证 `/usr/bin/ctags`路径中版本是最新安装的。

**使用:**在项目目录中运行ctags，生成索引：

    ctags -R -f .tags

索引生成完成后，在subl中按住 `cmd+shift` 鼠标点击即可实现跳转。或者直接快捷键`ctrl + t`实现跳转。




#Issues

###有时插件失效

使用Package Control 的Enable Package 重新唤醒插件。


