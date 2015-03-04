---
layout:     note
title:      基础
description: 一些基本概念
---

#注释
    
    #Python中使用单行注释
    
    #多行
    #注释
    
    """
       还可以使用
       文档字符串
       进行多行注释
    """

#使用Python2.7
Python采用缩进控制代码的结构，这是其直观的特点。作为脚本语言，你可以直接使用Python命令，进行交互式操作。如果代码中有中文字符，在文件头添加：
    
    # coding=utf-8

> 中文编码是Python的痛点，但是可以用好的编程实践来弥补，中文使用Unicode字符串，保持IDE编码一致，特别是团队开发。当然，如果愿意抽出一部分时间研究一下Ascii, GBK, Unicode, Utf-8等编码之间的关系，也可以让我们更加的清晰。


#操作符
先看一下Python中支持的操作符

+ 加减乘除 `+`  `-`  `*`  `/` `//` 
+ 取摸`%` 
+ 指数`**`
+ 比较大小 `>`  `<`  `<= ` `>=`
+ 与 或 异或  `&`  `|` `^`
+复合加减乘除 `+=`  `-=`  `*=` `\=` 
+等与不等`==`  `!=`

**其中**`/`表示普通除法， `//`表示执行整除，其结果舍弃小数位.


#Input&Output

    print "This is from your python program."

    name = "leeon"
    age = 24

    print "My name is %s , and I am %d years old." %(name,age)
    print "My name is {0} , and I am {1} years old".format(name,age)#recommended
    print "My name is {myname} , and I am {myage} years old.".format(myname=name,myage=age) #format函数功能很强大

    name = raw_input("what's your name?\n")
    age = input("then how about yoaur age ?\n")

input和raw_input的主要区别是后者将输入转为String，而前者要求输入是合法的Python表达式，比如数字`12`，或者`"tom"`，而不能输入`tom`。大部分情况下你应该是用后者。


-------

#模块

###import
Python提供模块机制来组织不同文件中的代码。每一个Python文件都被视为一个模块，彼此可以进行引用。

    # module.py 
    def test_add(a, b):
        return a+b

当需要调用`test_add`方法的时候，可以使用下面的语句：
    
    import module
    print module.test_add(1,2)
    #or
    from module import test_add
    print test_module(1,3)
    
    #or even 
    import module
    my_add = module.test_add
    print my_add(1,2)

###\_\_main__
    
    #script.py
    if __name__ == "__main__":
    import sys
    do_sth(int(sys.argv[1]))

通过下面的命令执行
    
    python script.py <arguments>
    
###搜索路径
当遇到`import someModule`语句 时，Python会进行下面的搜索，寻找模块。

1. 首先会去内置模块中寻找`someModule`
2. 如果没有找到，在`sys.path`中寻找。

`sys.path`包括当前脚本执行目录，PYTHON_PATH。


--------


#控制流

###赋值

Python中没有传统语言中的变量声明，当我们第一次对一个变量进行赋值的时候，就表示声明了一个变量。Python在提供单个变量赋值的同时，还支持多个变量的一起赋值，比如：

    (a,b,c) = (1,2,3)
    
就完成了三个变量的同时赋值。



###逻辑
其中逻辑比较的操作符包括，当比较内建类型或者常量的时候不建议使用`is`，因为`is`比较的是对象的虚拟内存地址，内建类型经常被优化，比如两个值相同的整形变量会指向同一块地址，因此`is`会返回`True`.

    a > b
    a < b
    a >= b
    a <= b
    a == b #判断值是否相等
    a is b #判断是否为同一对象
    a is not b
    a in b #判断元素是否在制定集合中
    a not in b 

逻辑的与或非分别用 `and`, `or `,`not`表示，Python中同样采用`逻辑短路`原则，即`and`前的布尔值为假，则后面的条件表达式不再被执行。

###if/else/elif

    age = input('How old are you? ')
    if age > 20:
        print 'you are older than me.'
    elif age < 20:
        print 'you are younger than me.'
    else:
        print 'we are the same age!'

###while

    while condtion:
        pass

###for

基础用法，遍历一个列表
    
    team = ['duncan','parker','spliter','bannor']
    for player in team:
        print player

高级用法：TODO itertools

###break/continue
同其他语言一样：

+ `break` 不再执行当前循环体内下面的语句，循环结束
+ `continue` 不再直行当前循环体内下面的语句，循环继续


-----------

#异常

Python使用从`try.. except`语句来捕获异常。
    
    try:
        f = open("file_not_exist")
    except IOError:
        print "file not exist"
    finally:
        pass
        #do some cleaning
