## host
Host can help to look DNS information of a website:
```
jiazhuos-MBP:~ jiazhuo$ host www.sap.com
www.sap.com is an alias for www.www.sap.com.akadns.net.
www.www.sap.com.akadns.net is an alias for www.sap.com.cn.edgekey.net.
www.sap.com.cn.edgekey.net is an alias for e7714.x.akamaiedge.net.
e7714.x.akamaiedge.net is an alias for user-att-108-255-192-0.e7714.x.akamaiedge.net.
user-att-108-255-192-0.e7714.x.akamaiedge.net has address 23.205.62.95
jiazhuos-MBP:~ jiazhuo$ host 23.205.62.95
95.62.205.23.in-addr.arpa domain name pointer a23-205-62-95.deploy.static.akamaitechnologies.com.
```

Also, it can be used to look up a website url by using a Ip address.
For example, using the IP in above example:
```
jiazhuos-MBP:~ jiazhuo$ host 23.205.62.95
95.62.205.23.in-addr.arpa domain name pointer a23-205-62-95.deploy.static.akamaitechnologies.com.
```
As you can see, SAP website uses Akamai services, which is a tech giant stands behind stage. It reminds my fav. professor Dr.Bruce Mags in Duke, who is Co-Founder of Akamai lol.

Use specific option, we can filter the result by using option -t:
> jiazhuos-MBP:~ jiazhuo$ host -t CNAME www.sap.com
> www.sap.com is an alias for www.www.sap.com.akadns.net.

## hostname
Print the name of computer or server, can print will short(-s) or full(-f) name.
> hostname
> hostname -s
> hostname -f

## ping
Chekding if the remote server is available. More in detail, it sends small packages(ICMP) to remote server, and waiting for response.

Using -c to restrict total package number.
```
jiazhuos-MBP:~ jiazhuo$ ping -c 2 google.com
PING google.com (216.58.194.46): 56 data bytes
64 bytes from 216.58.194.46: icmp_seq=0 ttl=51 time=46.482 ms
64 bytes from 216.58.194.46: icmp_seq=1 ttl=51 time=47.544 ms

--- google.com ping statistics ---
2 packets transmitted, 2 packets received, 0.0% packet loss
round-trip min/avg/max/stddev = 46.482/47.013/47.544/0.531 ms
```

## traceroute
Print the path from the local host to target server host.
```
jiazhuos-MBP:~ jiazhuo$ traceroute www.google.com
traceroute to www.google.com (216.58.194.36), 64 hops max, 52 byte packets
 1  homeportal (192.168.1.254)  3.368 ms  2.870 ms  3.340 ms
 2  172-9-236-1.lightspeed.sntcca.sbcglobal.net (172.9.236.1)  24.640 ms  111.628 ms  6.628 ms
 3  71.148.149.38 (71.148.149.38)  5.517 ms  7.943 ms  5.370 ms
 4  * * *
 5  12.83.39.197 (12.83.39.197)  8.627 ms
    12.83.39.193 (12.83.39.193)  7.437 ms
	...
```

## ifconifg
Display the network interface
> ifconifg

Or just show only one interface
```
jiazhuos-MBP:~ jiazhuo$ ifconfig bridge0
bridge0: flags=8863<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 1500
	options=63<RXCSUM,TXCSUM,TSO4,TSO6>
	ether 3e:15:c2:ec:96:00 
	Configuration:
		id 0:0:0:0:0:0 priority 0 hellotime 0 fwddelay 0
		maxage 0 holdcnt 0 proto stp maxaddr 100 timeout 1200
		root id 0:0:0:0:0:0 priority 0 ifcost 0 port 0
		ipfilter disabled flags 0x2
	member: en1 flags=3<LEARNING,DISCOVER>
	        ifmaxaddr 0 port 5 priority 0 path cost 0
	member: en2 flags=3<LEARNING,DISCOVER>
	        ifmaxaddr 0 port 6 priority 0 path cost 0
	Address cache:
	nd6 options=1<PERFORMNUD>
	media: <unknown type>
	status: inactive
```