# ps
查看进程的命令。

> ps

### output meaning:
* F 代表这个程序的旗标 (flag)， 4 代表使用者为 super user
* UID 程序被该 UID 所拥有
* PID 进程的ID
* PPID 则是其上级父程序的ID
* C CPU 使用的资源百分比
* TTY 登入者的终端机位置
* CMD 所下达的指令为何

### Common Usage:
显示所有进程信息，连同命令行
> ps -ef

显示具体进程信息，连同命令行
> ps -ef | grep ssh