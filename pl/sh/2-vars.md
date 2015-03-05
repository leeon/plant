---
layout:     note
title:      变量
description: 灵活的使用sh变量
---


#默认值
shll在使用变量的时候，如果变量不存在，则可以使用默认值。

###使用默认值

`:-` 表示如果一个变量不存在或者为null,就会使用符号后面指定的默认值。`-`表示如果一个变量不存在的情况才会使用默认值。

    unset foo
    echo ${foo:-foos default value}
    echo ${foo-foos default value}

    foo=
    echo ${foo:-foos default value}
    echo ${foo-foos default value}
    
###用默认值赋值

`:=`表示如果一个变量不存在或者为null，就会把符号后面指定的默认值赋值给变量。`=`表示如果一个变量不存在的情况才会把默认值赋值给变量。

    unset foo
    echo ${foo:=foos default value}
    echo $foo


 