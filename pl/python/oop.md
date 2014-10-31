#面向对象编程

###封装--属性+方法
在Python中定义一个类非常的简单，直接使用`class`关键字，所有的类都继承自object，类的绑定方法，第一个参数为`self`表示当前的对象，在实际调用的时候不用传入，当调用时
    
    MyObject.method(arg1, arg2)
Python会自动转为

    MyClass.method(MyObject, arg1, arg2）

下面的代码演示了一个类的封装

    # coding=utf-8

    class Book(object):

        type = "book"#类的属性
        
        #构造函数
        """docstring for Book class"""
        def __init__(self,name):
            self.name = name  #实例的属性

        #实例方法
        def save(self):
            """
            对象实例的方法
            实例调用时，实例本身作为第一个参数传递；类调用时，手动传递实例作为第一个参数"""
            print "{0} is saved.".format(self.name)

        @classmethod
        def getType(cls):
            """类的方法
               类和实例都可以调用，类作为参数传递默认传递
               避免类实例化的开销
            """
            print "The type of reading is .{}".format(cls.type)


        @staticmethod
        def join(a,b):
            """
               当方法不依赖类的属性时，使用此方法
            """
            print a+b
            

    book1 = Book("Gone with wind")
    book2 = Book("The kite runner")

    #two ways to invoke instance method
    book1.save();
    Book.save(book2);

    #invoke classmethod
    Book.getType();
    #invoke static method
    Book.join(book1.name, book2.name)

###生命周期
类的构造方法是`__init__`，以双下划线开头。`__del__`方法，是对象消亡的时候调用的，但是在实际编码中并不能确定其具体的调用时机，除非显式的使用`del`关键字。

###权限
Python中并没有提供一个严格的类属性和方法的访问权限，理论上可以访问所有的对象。如果要保护某一个方法或者变量不被直接访问可以使用双下划线开头,这样就可以防止调用者*直接*访问了，但是实际上Python只是转换了双下划线开头的变量了而已，并非真的为其设定了权限。

    class Student:
        '''Student doc string'''
        #vars 
        def __init__(self,name,age):
            """Constructor for Class Student"""
            self.name = name
            self.age = age
    
        def say(self):
            print "hello, I am "+ self.name
    
        def __whisper(self):
            print "I am %d years old." %self.age
    
    
    s = Student("susie",20) #create an instance of Student
    s.say()
    #s.__whisper() error code
    s._Student__whisper()
    
比如定义了`__whisper`这个私有方法，其实他被解释器改为了新的名字，下划线+类名+方法名。同样可以调用，因此Python开发中尝尝约定，单下划线开始的变量为私有，当然这只是编码习惯上的约束而已。

###继承
Python 中支持多重继承，子类和可以调用或者覆写父类中的方法。

###hasattr(obj,str)
在处理多态的问题时候可以使用h`hasattr()`方法来确定某一个类是否支持某一种行为，比如：

    hasattr(duck,"talk") #can a duck talk?
