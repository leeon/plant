---
layout:     note
title:      数据类型
description: 基础数据类型
---

#集合

Python中支持四种集合

+ List
+ Tuple
+ Dictionary
+ Set


#序列（List & Tuple）
python中的序列主要有list和tuple,后者是一种不可变的list。list类似于一个动态的数组，可以动态添加元素，同时允许每一个元素可以为不同类型，支持嵌套。

    aList = [] #set a new empty list
    
###索引
序列支持正向和负向的索引,`0`表示左边第一个元素，`-1`表示从右边数第一个元素。比如：

    aList = ['a','b','c','d']
    aList[0] #'a'
    aList[-1] #'d'
    'hello'[2] #also support this way , 'l'

###切片
分片（slice）操作是为了获取序列中的某一个子序列，其基本语法是:

`'squence'[start:end:step]`

其中索引是左闭右开的。

`'sequence'[1:2]` 等价于`'sequence'[1:2:1]'`

如果把start或者end置为空，就表示尽可能取最长,几个例子：

    'hello'[1：2] #‘e’
    'hello'[1:] #‘ello’
    'hello[:]' #actually the whole string 可以生成一份当前list的副本

列表的索引还可以是负数，表示负向索引，从右边开始选。例如
    
    'hello'[1,-1]  #'ell'

下面的图可以帮助你更好的理解索引

     +---+---+---+---+---+
     | H | e | l | p | A |
     +---+---+---+---+---+
     0   1   2   3   4   5
    -5  -4  -3  -2  -1
    
    

###代码示例

     # coding=utf-8
     # Filename : list.py
     # Date: 2012 11 20
 
     # 创建一个list方式
     heatList = ['wade','james','bosh','haslem']
     tableList = list('123')  #list方法接受一个iterable的参数
 
     print 'Miami heat has ',len(heatList),' NBA Stars , they are:'
 
     #遍历list中的元素
     for player in heatList:
         print player,
 
     #向list添加元素
     heatList.append('allen') #方式一：向list结尾添加 参数object
     print '\nAfter allen join the team ,they are: '
     print heatList
 
     heatList.insert(4,'lewis') #方式二：插入一个元素 参数一：index位置 参数二：object
     print 'After lewis join the team, they are:'
     print heatList
 
     heatList.extend(tableList)  #方式三：扩展列表，参数：iterable参数
     print 'After extend a table list,now they are :'
     print heatList
 
     #从list删除元素
     heatList.remove('1')   #删除方式一：参数object 如有重复元素，只会删除最靠前的
     print" Remove '1' ..now '1' is gone\n",heatList
 
     heatList.pop()   #删除方式二：pop 可选参数index删除指定位置的元素 默认为最后一个元素
     print "Pop the last element '3'\n",heatList
 
     del heatList[6] #删除方式三：可以删除制定元素或者列表切片
     print "del '3' at the index 6\n",heatList
 
     #逻辑判断
     #统计方法 count 参数：具体元素的值
     print 'james apears ',heatList.count('wade'),' times'
 
     #in 和 not in 
     print 'wade in list ? ',('wade' in heatList)
     print 'wade not in list ? ',('wade' not in heatList)
 
     #定位 index方法：参数：具体元素的值 可选参数：切片范围
     print 'allen in the list ? ',heatList.index('allen')
     #下一行代码会报错，因为allen不在前三名里
     #print 'allen in the fisrt 3 player ? ',heatList.index('allen',0,3)
 
     #排序和反转代码
     print 'When the list is reversed : '
     heatList.reverse()
     print heatList
 
     print 'When the list is sorted: '
     heatList.sort() #sort有三个默认参数 cmp=None,key=None,reverse=False 因此可以制定排序参数以后再讲
     print heatList
 
     #list 的分片[start:end] 分片中不包含end位置的元素
     print 'elements from 2nd to 3rd ' , heatList[1:3]

> 表和元组的区别 :前者可变，后者只读

-----


#字典

###创建
字典是python中目前仅有的内置mapping类型。其基本数据结构为{key:value..}，是一种`无序`的存储结构。其中key是不可变类型，而value可以是任何类型。

    aPerson = {} # set a new empty dict
    aPerson = {'name':'sara','age':22} #set a new dict
    aPerson = dict([('name','sara'),('age',22)]) # set dict from a list

###基本使用
    
    aPerson = {'name':'sara','age':22}
    len(aPerson) # return the number of keys in a dict
    aPerson['age'] = 21 # set the value of a key
    aPerson['age'] #read the value of a key, I prefer using get()
    del aPerson['age'] # delete a particular key
    'age' in aPerson # True

###內置函数
    
    aPerson = {'name':'sara','age':22}
    aPerson.get('name','someone') 
    # recommend! if name not in dict return 'someone'  PS:like getItem() in HTML5
    aPerson.keys() # get all the keys in the form of list
    aPerson.values() # get all the values in the form of list
    aPerson.items() # guess !
    aPerson.pop('age') # act the same as pop in stack
    aPerson.clear() # clean the dict --> {}
    aPerson.fromkeys([1,2,3],0) # set a dict from a list of keys with default value 0
    aPerson.copy() #swallow copy of a dict
    
###遍历

基本有兩種實現方式：一是遍歷`items()`生成的list,二是通過iteritems()生成的迭代器，後者效率更高。

    aPerson = {'name':'sara','age':22}
    for k,v in aPerson.iteritems():
        print k,v

------

#集合

Python中的集合和数学中集合的概念相同，具有**无序性**和**唯一性**，它支持添加、遍历、判断是否包含某个元素等操作，但是不支持索引、分片等序列化的操作。

一般集合用在数学计算的场景，例如将一个list转换为set,Python还提供了`frozenset`表示已经创建就不会再改变的集合。


    mSet = set(mList)
    num = len(mSet) #count
    




