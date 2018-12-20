## Disk Free

> df
```
Filesystem    512-blocks      Used Available Capacity  iused   ifree %iused  Mounted on
/dev/disk1     234610432 211269424  22829008    91% 26472676 2853626   90%   /
devfs                365       365         0   100%      632       0  100%   /dev
map -hosts             0         0         0   100%        0       0  100%   /net
map auto_home          0         0         0   100%        0       0  100%   /home
/dev/disk2s1   253425664 246855168   6570496    98%   964278   25666   97%   /Volumes/Transcend
```

Options:
```
// show in MB
df -m

// For better readable
df -h

// Display only that type
df -t type
```
