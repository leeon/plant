

>Android中所有UI对象的父类都是View 或者ViewGroup

#Layout

布局是Android UI 部分的基础，提供Android应用程序的基本交互界面。我们可以通过下面两种方式定义一个布局：

+ 在XML文件中声明UI元素，Android创建了XML元素与UI类之间的映射。
+ 在运行时初始化UI元素(通过Java代码实现)

Android允许自由定义UI元素，一般的可以在XML文件中定义好基本的界面元素，在运行的时候随着用户的交互来动态的变化UI元素的状态。

使用XML定义界面的优势是可以将界面的表现层和业务控制分离开来。可以通过XML文件来针对不同的屏幕尺寸、方向、语言来定义界面。并且XML可以进行界面的可视化，方面代码调试。


通常，xml中定义UI元素的命名规则和UI类是一致的，例如`EditText`有一个属性叫做`text`，它和`EditText.setText`是对应的。


###编写XML

每一个布局xml文件必须只有一个根元素(View或者ViewGroup).在根元素中就可以嵌套的定义UI元素了，下面是官方文档中的一个`LinearLayout`的例子。

    <?xml version="1.0" encoding="utf-8"?>
    <LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
                  android:layout_width="fill_parent" 
                  android:layout_height="fill_parent" 
                  android:orientation="vertical" >
        <TextView android:id="@+id/text"
                  android:layout_width="wrap_content"
                  android:layout_height="wrap_content"
                  android:text="Hello, I am a TextView" />
        <Button android:id="@+id/button"
                android:layout_width="wrap_content"
                android:layout_height="wrap_content"
                android:text="Hello, I am a Button" />
    </LinearLayout>

布局文件位于 `res/layout/filename.xml`，可以在Java代码中和其他xml文件中进行引用：

+ In Java: R.layout.filename
+ In XML: @[package:]layout/filename


###ID
布局文件中的每一个元素都可以定义一个唯一的ID，比如`android:id="@+id/text"`，其中`+`表示如果不存在则创建。引用Android系统的内置资源的时候，需要在id前制定包名例如`android:id = "@android:id/empty"`,这样就不会访问本地的资源了。



#Layout Parameters

xml布局的属性命名一般为`layout_something`.每一个ViewGroup 都实现了一个 ` ViewGroup.LayoutParams`，布局参数中包含了每一个子View的大小以及位置等信息。

每一个`LayoutParames`子类都有属于自己特殊的语法，当然有一些是通用的，比如`layout_height`和`layout_width`. 每一个View都需要设置这两个属性，它的值可以是：

+ wrap_content 占据本身内容大小
+ match_parent 占据父元素的空间
+ 具体数值(推荐使用dp单位)



###布局位置

在Android中View是一个矩形，其位置信息是一个思维向量，包括了（x,y,width,height）,我们可以使用`getLeft()`和`getTop()`获得其相对父元素的坐标位置。为了方便计算，Android提供了多个获取位置信息方法，例如`getRight = getLeft + getWidth` 

###Size,Paddings,Margins

类似CSS,android中的View也包含了尺寸、内边距、外边距等属性。一个View实际上拥有两对(width,height).第一对叫做`measured width`和`measured height`，他们定义了View元素期望的大小。第二对叫做`width`和`height`，这是View元素实际被绘制的大小。


>注意View支持Padding，但是不支持Margin，ViewGroup可以支持Margin.



#常用布局
Android内置了几种常用的布局，包括LieanerLayout、RelativeLayout等。

#Adapter View

有些UI元素是动态绑定数据的，比如一个新闻列表，Android提供了一些继承自AdapterView的类来实现这些需求，比如ListView、GridView等。AdapterView使用Adapter进行数据填充。

###填充Adapter数据

AdapterView中提供了不同的Adapter来填充不同类型的数据。最常用的两种是ArrayAdapter和SimpleCursorAdapter。

####ArrayAdapter


例如向一个ListView中填充字符串，首先定义一个ArrayAdapter:

    ArrayAdapter adapter = new ArrayAdapter<String>(this, 
            android.R.layout.simple_list_item_1, myStringArray);

然后获取ListView并进行数据填充

    ListView listView = (ListView) findViewById(R.id.listview);
    listView.setAdapter(adapter);

这个例子中，默认每一个View都是一个TextView，如果希望扩展这个View，比如希望显示一些图片，就需要覆写`getView`方法。

####SimpleCursorAdapter


###处理单击事件


    // Create a message handling object as an anonymous class.
    private OnItemClickListener mMessageClickedHandler = new OnItemClickListener() {
        public void onItemClick(AdapterView parent, View v, int position, long id) {
            // Do something in response to the click
        }
    };

    listView.setOnItemClickListener(mMessageClickedHandler); 







