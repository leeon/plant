---
layout:     note
title:      基础
description: 一些基本概念
---


> 源码参考 `src/basic.cc`

#关于C++
C++同时支持不同的编程范式，包括面向过程的C风格的编程，使用类机制进行面向对象编程，使用Template进行模板元编程。




#存储作用域 & 生命周期
不同类型的变量拥有不同的作用域和生命周期，不同类型的变量也存储在不同的区域。

局部变量作用域就是其定义所在的作用域。离开作用域后释放。例如一个函数内部定义变量只能在其函数内部访问。
全局变量作用域是整个程序，其他文件引用全局变量，

静态局部变量，生命周期扩大为所在文件的生命周期，作用域不变。
静态全局变量，作用域会缩小至其所在的文件。

> 类的静态成员有其他面向对象中的含义。

###栈
存储局部变量和函数参数。由编译器自动分配和释放。

进入局部作用域，局部变量进栈，离开作用域，对应的变量出栈，后进先出。

###堆
存储程序通过malloc函数或者new关键字动态申请的内存空间。需要程序通过free函数或者delete关键字主动释放。

###静态存储区 和 全局存储区
存储静态类型和全局类型。





#声明 & 定义

###声明式

声明式是向编译器(compiler)指明一个东西的名字的和类型, 可能是变量、函数、或者对象，使得编译器可以找到它。编译器无需关注实现细节。例如：

    extern int i;   // 声明一个整型变量
    int max_num(int x, int y);   //声明一个函数
    class MyClassType;    //声明一个类

###定义式

定义式用来实例化或者实现声明使得链接器(Linker)可以链接到，在这里进行内存分配等具体细节操作。例如:

    int i;    //定义一个整型变量
    int max_num(int x, int y){return x>y?x:y}
    class foo{}; 


###关联与区别

只要需要访问变量或者函数，就可以先声明。但是定义只能出现一次，否则linker就无法知道要链接哪一个。


###关于staic成员变量

    class X
    {
    public:
          static int i;
    };
    int X::i = 0; // definition outside class declaration

C++的静态成员列表, 不是定义而是声明。理解：类的静态成员是属于类而非对象，即使没有任何实例化对象，类的静态 成员也依然存在，而且只有一份，类内定义会导致重复定义。

**特例**:如果一个静态成员为const static 整型类型（包括 int, char, bool），并且没有取地址操作，可以直接在类成员列表中进行声明同时定义。

    class X
    {
    public:
          static const int i = 12;
    };




#运算符优先级
个人观点：请适当的用括号包裹表达式，消除一切不明确的运算符运算。




#参考资料

+ [Sina App Engine Blog](http://blog.sae.sina.com.cn/archives/3202)
+ [Effective C++]()
+ [IBM Knowledge Center](http://www-01.ibm.com/support/knowledgecenter/SSGH3R_8.0.0/com.ibm.xlcpp8a.doc/language/ref/cplr038.htm%23cplr038)
+ [What is the difference between a definition and a declaration?](http://stackoverflow.com/questions/1410563/what-is-the-difference-between-a-definition-and-a-declaration)
