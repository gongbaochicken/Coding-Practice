## uptime
Check how long does the server(machine) gets up.
```
jz-MBP:~ jz$ uptime
22:29  up 1 day, 23:04, 2 users, load averages: 1.70 1.87 1.91
```

## pipe
Using the output of one command as standard input for the consequent command.
> who | sort
> df -m | sort 

## finger
Check the INFO of users who logged in.(Usually for local user, instea of remote user. Use 'users' for both local/remote user name)

```
jiazhuos-MBP:~ jiazhuo$ finger
Login    Name                 TTY  Idle  Login  Time   Office  Phone
jiazhuo  Jason Zhuo Jia      *con    1d  Tue    23:26
jiazhuo  Jason Zhuo Jia       s00        Tue    23:27
```

For more detail, you can do:
```
jiazhuos-MBP:~ jiazhuo$ finger Jason
Login: jiazhuo        			Name: Jason Zhuo Jia
Directory: /Users/jiazhuo           	Shell: /bin/bash
On since Tue May  8 23:26 (PDT) on console, idle 1 day 23:12 (messages off)
On since Tue May  8 23:27 (PDT) on ttys000
On since Thu May 10 21:47 (PDT) on ttys001 (messages off)
No Mail.
No Plan.
```

Ohter user information cmd:
> who
> whoami
> logname
> id

## combining
sequencial, but stop if any of them fails.
> cmd1 && cmd2 && cmd3

sequencial, but stop if any of them is successfully done.
> cmd1 || cmd2 || cmd3