---
layout:     note
title:      MySQL 使用例子
description: 常用的命令
---




###交换同一个表中两列的数据

    UPDATE t_my_table t1, t_my_table t2
    SET t1.col1 = t2.col2, t1.col2 = t2.col1
    WHERE t1.id = t2.id

这条语句体现了，MySQL数据操作实际上是对于表的引用操作。t1 和 t2 都是对原始表的引用，我们用 t1来进行数据修改，使用t2作为原始数据的参照。




