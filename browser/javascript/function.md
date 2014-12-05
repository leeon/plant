---
layout:     note
title:      JavaScript 函数
description: 无
---


#函数基础

JavaScript中函数的定义主要有两种形式：第一种叫做函数声明，缩写是FD，第二种是函数表达式缩写是FE. FD和FE之间主要的区别在于函数引用会不会添加到VO中，详细阅读[JavaScript核心概念](http://octsky.com/post/63/).

    function func1(){
        console.log("this is function a");
    }

    func2 = function(){
        console.log("this is function b")
    }

#内置函数
常用的内置函数

**parseInt（string,radix）** 讲string转换为10进制整型，radix表示第一个参数的基数。

**Math.floor(x)**  返回小于x的最大整数

**Math.ceil(x)** 返回大于x的最小整数

#闭包

>闭包没有那么神秘，他只是一个封闭的包（函数），他可以把局部数据返回给包(函数)返回给外面的数据。

如果你有OO的基础，一定想到了JAVA语言中的getXX方法之类的，没错，闭包可以实现JavaScript中的私有变量访问。

    function f (){
        var a = 12
        function get_a(){return a}
        return get_a
    }

上面就是一个闭包，它实际上利用了JavaScript这类语言作用域链的特性，即子函数可以访问父函数域的变量，但是反过来则不行。例子中，f不可以访问get\_a中的变量，但是get\_a可以访问f中的a，因此可以在f中直接返回get_a方法，这样外部就可以访问a了。

#函数式编程

###柯里化

>函数的柯里化是把接受多个参数的函数变换成接受一个单一参数（最初函数的第一个参数）的函数，并且返回接受余下的参数而且返回结果的新函数的技术


#默认参数

JavaScript中默认不支持函数的默认参数，但是每一个函数在创建时，其上下文环境中都有一个arguments对象，arguments类似一个数组但不是数组。它只具备数组的length属性。我们可以遍历arguments获取函数中的所有参数。

