sudo iptables-legacy -A INPUT -p tcp --dport 12345 -j LOG --log-level 4 --log-prefix ipt-input

sudo iptables-legacy -A INPUT -p tcp --dport 12345 -j DROP

sudo iptables-legacy -A OUTPUT -p tcp --sport 12345 -j LOG --log-level 4 --log-prefix ipt-output


