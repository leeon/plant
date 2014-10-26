#Bootstrap

使用框架的前提基础是理解HTML中的类和ID选择和组合。

###网格系统
高大上的前端开源框架，使用12\*12的网格布局。

`div.cntainer` 表示一个容器

`div.row` 表示一行，需要在container中

`div.col-md-12` 表示一列，需要在row中

`col-xs-`手机  `col-sm-`平板 `col-md-`桌面 `col-lg`桌面，分别表示不同尺寸的屏幕，选择其中一种，在大于该尺寸的设备上都会适用该样式，并且会覆盖针对小屏幕设置的样式。也就是说`col-md-`适用于普通桌面和更大的桌面。

如果都使用`col-md-`的话，表格在桌面上会水平分布，但是在手机和平板上，会出现堆叠。解决的方法是针对不同的屏幕尺寸设置分栏的效果。例如：
    
    <div class="row">
        <div class="col-xs-12 col-md-8">...</div>
        <div class="col-xs-6 col-md-4">...</div>
    </div>


`col-md-offset-` 表示照原来位置的偏移




###new in 3.x
`<img src="..." class="img-responsive" alt="Responsive image">` 

响应式图片
