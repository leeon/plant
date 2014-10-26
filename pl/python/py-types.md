基本数据类型


Python提供numerics, sequences, mappings, files, classes, instances 和 exceptions等内置类型。

每个对象主要由三个要素组成，分别是Type,Id和Value。比如用等值符比较的时候，`is`比较的是两个对象的id,而`==`比较的是两个对象的value是不是相等。


###布尔

`True`和`False`两个内置类型用来表示布尔值，除此之外：

+ 0 is false; all other numbers are true.
+ An empty string ("") is false, all other strings are true.
+ An empty list ([]) is false; all other lists are true.
+ An empty tuple (()) is false; all other tuples are true.
+ An empty dictionary ({}) is false; all other dictionaries are true.


###数字类型
Python中包含，整型、长整型、浮点和复数


###序列类型
Python有七种基本的序列类型，包括strings, Unicode strings, lists, tuples, bytearrays, buffers, 和 xrange objects

-----


#迭代器和生成器

###迭代器
迭代器用于封装一个集合，并提供统一的方法进行遍历处理。Python中定义了Iterable和Iterator.

其中Iterable是一个拥有可以返回Iterator的`__iter__`方法或者定义了`__getItem__`方法的对象。所以可以理解为Iterable是可以用来创建Iterator的对象。

Iterator就是一个包含`next`方法的对象，每次调用返回一个对象。要创建一个Iterator，可以使用内置的`iter()`方法，或者在`in`关键字的表达式中。比如：

    list = [1,2,3]
    for item in list:
        print item

    str = 'abc'
    it = iter(str)

此外创建一个Iterator还可以使用生成器。


###生成器和Yield
生成器的作用是产生一个Iterator。包含`Yield`表达式的函数叫做一个生成器函数，这类函数比较特殊，当调用时并不是去执行内部代码，而是返回一个生成器。生成器是一个功能更加丰富的迭代器，下面是一个生成器的例子：
    
    def gen_num():
    """This is a generator function"""
        for i in xrange(100):
            yield i 

    number_generator = gen_num()
    number_generator.next()


生成器强大的地方在于，每当遇到yield表达式的时候会返回yield表达式的值，然后保存当前的状态，让出CPU。然后可以通过`next`方法或者`send(value)`方法唤醒，继续执行直到再次遇到yield.

###为什么使用生成器
就像一个问题，为什么`xrange`比`range`好，因为range返回的是一个list，而xrange返回一个类似迭代器的对象。前者所占用的内存是O(n)的，而后者则是O(1).原因就是前面提到的。生成器有中断，任何时候总是保存着一个单一的值，而不是把所有对象load到内存中。

-----

#字符串

Python中字符串属于序列类型，使用`"`或者`'`进行包围,这意味着字符串支持序列的操作，

###编码
Python的对象有两种编码表示，一种是str，属于8bit的字节流，另一种是unicode编码，Python内部用这种形式表示。unicode序列以`u`开头，比如`u"name"`。

因此`decode`方法是将其他字符编码解码为`nicode`，而`encode`是将unicode编码为其他编码。下面两种硬编码定义中文的例子：

    str = "中文"
    ustr = u"中文"

第一种的中文实际编码会根据当前文件的编码而决定，编码解码需要知道具体的编码，而后者自动编码为Python的内置编码unicode，因此更值得推荐。


###转换
其他数据类型转换为String可以使用Python的两个内置函数，`str()`和`repr()`前者主要用于将一个对象转换为方便人可读的字符串，而后者用于将对象转换为方便解释器可读的字符串，对于很多类型，repr方法会尝试转成`eval`方法可以接受的参数。同时给一个class编写`__repr__`方法可以返回类似自定义的字符串，类似Java在类中重写`toString`方法。



###操作
String支持很多和序列相同的操作。常用的操作有：

####str.count(sub[, start[, end]])
返回sub在str中出现的次数，可选参数表示计算的区间例如`str.count('a',0,12)`表示检测a在str[0,12)区间上出现的次数。

####str.find(sub[, start[, end]])
在str中查找sub,并返回第一次出现的index，如果没有出现返回-1，官方建议只有需要知道sub具体位置的时候才用此方法，如果只是检查sub是否为str的子串，可以使用`in`操作符。

>rfind方法表示从右侧开始查找，即返回最后一次出现的index

####str.format(*args, **kwargs)
格式化字符串，此方法使用参数列表中得元组或者字典去填充{}内容，例如：

    'Hello {},I am {} years old'.format('apressz',2) # Hello apressz,I am 1 years old
    'Hello {name},I am {age} years old'.format(name='apressz',age=2) # same as above

####str.join(iterable)
用str做分隔符，连接iterable中的字符串。

####str.partition(sep)
以sep为准，将字符串分成一个三元组('string_before_sep','sep','string_after_sep')

>rpartition方法表示从右侧开始寻找sep并进行分割

####str.replace(old,new,[count])
用new替换old,并返回一个拷贝,count限定替换的个数


####str.split([sep[, maxsplit]])
用sep分割字符串，输出一个list,sep为空表示用空格分割，maxsplit限定最大的分割的次数

>rsplit表示从字符串的右侧开始分割

####str.strip([chars])
去除字符串左边和右面的空格，chars参数表示要额外剔除的字符











