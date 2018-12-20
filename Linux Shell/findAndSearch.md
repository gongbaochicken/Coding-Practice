## 查找文件
### find
> find [dir] [expr]

Option选项超级多
常见通过名字：
> find . -type f -name "*SQLScriptQuery*"


##  查找文件的位置
### whereis
> whereis [option] [file]

只找source code
> whereis -s [file]

只找可执行文件
> whereis -s [file]

## 通过内容：
### grep
常用
> grep -r "ABC" <dir>

忽略大小写
> grep -ri "ABC" <dir>

显示周围几行，比如2行：
> grep -ri -C2 "ABC" <dir>

使用例子：通过grep查询CPU核数。
> grep -c ^processor /proc/cpuinfo

### egrep
同grep类似，但是支持正则表达式。