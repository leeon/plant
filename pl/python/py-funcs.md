

#函数

###结构

函数定义以关键字 `def` 开始，之后是函数名，在之后是参数列表。如同类一样，每一个函数可以在第一行声明一个`doc string`,然后就是函数体，Python中病不要求显式的`return`语句，正如你在函数名前也没有见到函数的返回值类型。

虽然Python不要求返回值，但是即使没有return，函数也会一个内置的类型 `None`

    def function(params):
        '''doc string'''
        pass
        return 

Python中支持函数的嵌套声明，比如:

    def produce():
        print"in the process of producing.."
        def pack():
            print"in the process of packing..."
        pack()


###作用域
调用函数的时候，Python会创建一个新的作用域，解释器维护一个新的符号表，当遇到一个变量的时候，解释器会首先在当前符号表中寻找，然后是上一级作用域。如果要在函数体内引用全局的变量，需要使用`global`关键字。

Python使用字典维护变量的作用域，下面两个方法比较重要：

+ locals() 获取局部作用域中的变量字典
+ globals()  获取全局变量字典


  

###参数
python 函数参数支持比较丰富，主要包括：

+ 位置参数
+ 关键字参数
+ 收集参数

####位置参数
调用的时候需要按照特地的顺序传递参数，缺点比较明显，你需要记住参数列表，形如：

    def func(param1,param2):
        pass
    func(1,2) #bad code hard to read
    func(param1 = 1,param2 =2) #keyword arguments

####关键字参数
在定义函数的时候，可以指明参数的默认值，调用的时候，传递参数显式声明参数名，虽然写起来有点多，但是在调用的时候方便了很多。比如大项目中，当调用某些函数的时候，调用者可以选择性的填充参数。

    def func(param1=value1,param2=value2):
        pass

####收集参数or可变参数列表
Python提供了很好的可变参数列表的支持，`*params`表示一个参数元组，而`**params`表示参数字典，一个小例子就可以看明白，例如：

    def params_collect(*params):
        print params

    def params_collect_dict(**params):
        print params

    params_collect_dict(name="liyang",sex="man",location="HIT")
    params_collect(1,2,3,4)

    # you can also use *params and **params to invoke functions
    dict_params = {name:'liyang',sex:'man',location:'HIT'}
    tuple_params = (1,2,3,4)

    params_collect_dict(**dict_params)
    params_collect(*tuple_params)

至于如何使用这些参数，看打印结果就知道我们已经获得元组或者字典了，怎么用，你懂的。

这些参数的使用是可以综合在一起的。




#内置函数
这里包含了日常编码中可能会用到的内置函数

###内存

####id()
返回一个对象的id


###字符串

####str()
将一个对象转换为可读的字符串

####repr()
讲一个对象转换为解释器可读的字符串


###集合
####len()
返回一个对象的长度


####range()和xrange()
两个函数都常用在循环中,主要区别在于前者返回一个list而后者返回一个生成器
    
    for i in range(0,10) 
        print i  
    #output: 0,1,2,3,4,5,6,7,8,9



####zip()
返回一个元素为元组的列表，接收不同数量的列表或元组，将这些列表按照元素对应的位置合并。

    x = [1,2,3]
    y = ['a','b','c']
    zipped = zip(x,y)
    tx,ty = zip(*zipped) # like unzip
    
    for xx , yy in zip(x,y):
        print xx,yy




#函数表达式

###生成器表达式和列表表达式

生成器表达式和列表表达式借鉴于Haskell。用于在list和迭代器操作中得快速操作。


    line_list = ['  line 1\n', 'line 2  \n', ...]

    # Generator expression -- 返回一个Iterator
    stripped_iter = (line.strip() for line in line_list)

    # List comprehension -- 返回一个列表
    stripped_list = [line.strip() for line in line_list]



生成器表达式用`()`包围。列表表达式使用`[]`包围。如前面所说，如果要操作一个无限非常大得结合，最好使用生成器表达式，因为它每次迭代产生数据，而不是一次性的读完。其语法可以表示为：

    ( expression for expr in sequence1
             if condition1
             for expr2 in sequence2
             if condition2
             for expr3 in sequence3 ...
             if condition3
             for exprN in sequenceN
             if conditionN )

下面是对应的等价的一个普通代码结构：

    for expr1 in sequence1:
        if not (condition1):
            continue   # Skip this element
        for expr2 in sequence2:
            if not (condition2):
                continue    # Skip this element
            ...
            for exprN in sequenceN:
                 if not (conditionN):
                     continue   # Skip this element

                 # Output the value of
                 # the expression.



#lambda 表达式

Python中lambda表达式用于快速的编写一些小型的函数，比如编写一个加法函数

adder = lambda x,y : x+y

###什么时候用？

一般说来，lambda表达式写起来方便，但是在一些场景下并没有带来更好的可读性。我觉得如果需要一个比较小的函数，并且调用的次数较少使用lambda可以增加代码的可维护性，并且减少了过得函数跳转。



#装饰器

Python提供的装饰器可以使我们进行函数式编程。在使用装饰器之前，用该先了解一些基本的概念。在Python中函数也是对象，因此也可以作为参数进行传递。

###高阶函数
定义两个函数，将A作为参数传给B，则B是A的高阶函数：
    
    def A():
        print 'Invoke Function A'

    def B(func):
        print 'Invoke Function B'
        def wrapper():
            func()

        return wrapper

    a = B(A)
    a()

###闭包
提到函数式编程，就不免提到闭包，闭包在javascript中非常常见，通俗的可以理解为，一个函数B包装好一些数据，外面是无法访问这些数据的，但是在函数B内部顶一个函数wraper，这个函数拥有访问权限，现在B将wraper作为返回值返回，外界就可以通过wraper来得到数据了。就像一座神秘的城堡B，wraper就是来自这个城堡的信使，大家只能通过它来得知城堡的秘密。

利用上面的例子，改写函数B

    def B(func):
        name = 'Function B'
        print 'Invoke Function B'
        def wrapper():
            print 'In Enviroment {0}'.format(name)
            func()

        return wrapper

###Decorator
发现函数B就像把A包装(装饰)起来了，这就是装饰器的原型了，Python提供了简洁的装饰器语法，改写上面的例子,被装饰的方法A写法如下：

    @B
    def A():
        print 'Invoke Function A'

而装饰器B的定义如下

    def B(func):
        name = 'Function B'  #只有定义A的时候执行
        print 'Invoke Function B'
        def wrapper():
            #每次调用A都执行
            print 'In Enviroment {0}'.format(name)
            func()

        return wrapper

当解释器遇到@B装饰器时，会首先编译A函数，然后把A作为参数传递给B函数。然后装饰器B返回wrapper作为新的A，并且与A这个名字绑定。所以上面定义A函数等价于

    A = B(A)

####带参数的Decorator
有时我们需要动态的调整装饰器，所以需要往装饰器中传入参数，同时被装饰函数的参数也需要解析，下面改写上面的例子

    def B(type='default'):
        print 'Decoreated by {0}'.format(type)
        env = 'Function B'
        print 'Invoke Function B'
        def func_wrapper(func):
            def wrapper():
                print 'In Enviroment {0}'.format(env)
                func()
            return wrapper
        return func_wrapper

    @B(type='log')
    def A():
        print 'Invoke Function A'

    A()

因为需要传入的参数增加，所以新增加一层wrapper。



####副作用
实际上我们发现，装饰器实际上是返回了一个wrapper函数取代了原来被修饰的函数。例如下面的例子

    def say(fn):
        def wrapper():
            print 'before {0} is Invoked'.format(fn.__name__)
            fn()
            print 'After {0} is Invoked'.format(fn.__name__)
        return wrapper


    @say
    def hello():
        print 'I am Hello'

print hello.__name__

打印显示的hello.__name__是wrapper，并不是原来的函数了。解决办法是利用Python functools，改变代码如下

    from functools import wraps

    def say(fn):
        @wraps(fn)
        def wrapper():
            print 'before {0} is Invoked'.format(fn.__name__)
            fn()
            print 'After {0} is Invoked'.format(fn.__name__)
        return wrapper


    @say
    def hello():
        print 'I am Hello'

    print hello.__name__



