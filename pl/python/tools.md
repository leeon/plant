#Profile

Profile是Python提供的检测函数性能的工具，比如我们想测试一个函数`foo()`的执行情况：
    
    import profile

    profile.run('foo()')
    profile.run('foo()',filename='foo_profile.md') #输出信息到文件

在显示的结果中包含下面的信息

+ ncalls 函数调用次数
+ tottime 函数总计运行时间，不包含函数中调用的函数运行时间
+ percall 函数运行一次的平均时间，=tottime/ncalls
+ cumtime 函数总计运行时间，包含调用的函数运行时间
+ percall 函数运行一次的平均时间，等于cumtime/ncalls
+ filename:lineno(function) 函数所在的文件名，函数的行号，函数名





