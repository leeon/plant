---
layout:     note
title:      C++ 控制流
description: 面向过程的控制流
---

#Control



###if

    if(bOneWayChosen)
    {
        //enjoy it 
    }
    else
    {
        //forget it
    }


###for

    for(int i = 10; i > 0; i--)
    {
        // 10 count down 
    }


###while

    while(condition)
    {
        // loop
    }


###do while

    do
    {
        // do just for once
    }while(0)



###条件表达式

使用条件表达式替代简单的if语句做逻辑判断使代码具有更好的可读性。

    bool bPassExam = (iScore > 60) ? true : false;

