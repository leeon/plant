---
layout:     note
title:      JavaScript 语法基础
description: 数据类型和控制流
---


#数据类型


JavaScript是弱类型的语言，可以通过如下方式定义一个变量：

    var m = 12;

支持的六种数据类型有 **numbers**, **string**, **boolean**, **object**, **undefined**, **null**

###undefined

`undefined`表示没有被赋值过的变量。检查一个变量是否为undefined的时候，可以使用`===`,最佳的实践方案是，使用`typeof`来判断，避免未定义变量报错。

    var bar = null;
    if( bar === undefined){
        //false
    }
    if(bar == undefined){
        //true，because == also check null
    }

    if(typeof xx == 'undefined')


###numbers:

`NaN`内置变量表示非数字。可以使用`isNaN()`方法判断。

`parseInt(string,radix)`用于string和数字之间的转换，如果无法转换为数字，返回`NaN`.radix是可选参数,其中radix是可选参数，表示转换数字的基数，也就是要转化为进制为多少的数字。

    parseInt("12",10); //12
    +"12";   //12 another quick way to get a number from str.


###array
JavaScript中的数组和Python一样，支持多种数据类型。例如：

    var mList = ['name',23,{type:"students"}];
    var mArray = new Array(3);

使用数组是一件很有意思的事情：比如 [JavaScript中多变的数组](http://atleeon.com/code/2013/10/17/js-array.html)

> object可以表示成JSON格式。

#操作符

###in

in操作符的右侧必须是一个object，它用来判断右边的object是否包含左边的属性.

    'length' in new String("hello")  // true,'length' is a property of a string obj

> 容易误用in操作符判断元素是否属于一个数组,建议使用array.indexOf(obj),该方法返回obj的下标,如果元素不存在返回-1.

###delete

delete操作符删除一个object的属性.
    
    delete object.property
    delete object['property']


#语句
> 语句后的`;`是可选的,感兴趣可以看[『知乎』的讨论](http://www.zhihu.com/question/20298345)

###if else

    if(a > b){
        //do
    }else{
        //do
    }
    
###for

    for(var i = 1; i < 10; i++ ){
        //get i
    }
    
###for in

for in 语句的原型是 `for (var in object)`，所以是用来迭代一个对象的属性的，数组也是一个对象，下标就是数组的属性key,对应着每一个value。

    var mList = [1,2,3];
    for(i in mList){
        console.log(mList[i]);
    }

> 注意与Python不同，JavaScript迭代的是元素的index，而不是元素本身

###while
    
    while(true){
        //do
    }
    
    do{
        //do
    }while(true)
    
###break & continue
和C语言相同，break跳出本次循环，并结束循环；continue结束本次循环，继续下一次循环

###switch
    
    switch(n){
        case 1:
        //do
        break;
        case 2:
        //do
        break;
        default:
        //do
    }

###try catch

    try{
        throw "myException";
    }
    catch(e){
        handleErrors（e);
    }

#作用域
JavaScript的作用域与C不同，并不是以`{}`块来进行区分的，而是根据函数而确定，所以下面代码会打印5。

    if(true){
        var a  = 5;
    }
    log.console(a); //output 5

###全局作用域

+ 在所有函数之外定义的变量拥有全局作用域
+ 没有使用`var`定义的变量拥有全局作用域

###函数作用域

指在某个函数内部定义的变量，只具有函数内的访问权限


#更加深入的理解javascript

[JavaScript中的 变量、作用域链、执行上下文](http://atleeon.com/code/2014/02/26/javascript-basic/)

[JavaScript Scoping and Hoisting](http://atleeon.com/code/2014/03/06/javascript-scoping-hoisting/)



