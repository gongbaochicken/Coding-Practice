# scp
scp是secure copy的简写.在Linux下进行远程拷贝文件可以使用该的命令，和它类似的命令有cp，不过cp只是在本机进行拷贝不能跨服务器，而且scp传输是加密的。

当你服务器硬盘变为只读 read only system时，用scp可以帮你把文件移出来。

### 命令：
scp [param] [old dir] [target dir]

> $scp root@12.26.159.51:/opt/soft/file.tar /opt/soft/