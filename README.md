## Spring Semester 2022 MS Project  

Name	: Souryadeep Sen  
UNI	: ss6400

Overview: 

- Application of extended-BPF to improving system perf w.r.t network I/O  
- Test the performance of a TCP XDP e-BPF filter used for port forwarding and compare to nftable port forwarding performance.


### Usage: on a Debian linux machine

```
- Tools to download to use [libbpf](https://github.com/libbpf/libbpf) library:

	- sudo apt install zlib-devel
	- sudo apt-get install -y libelf-dev
	- ensure kernel is built with: CONFIG_DEBUG_INFO_BTF=y
	- Clang 11 and later required
	- git clone --recursive https://github.com/libbpf/libbpf-bootstrap
	- Running the minimal and bootstrap apps
		- cd libbpf-bootstrap/examples/c
		- change llvm-strip to whichever version exists on your pc in the makefile. for eg. llvm-strip-7
		- make
		- sudo ./minimal OR sudo ./bootstrap

- To run the filter in this repo, install the following python bcc package:
	- ensure you are using python3
	- sudo apt install python3-bpfcc 
	- please note, pip install bcc does not work for python3
	- to load and run filter: sudo python3 main.py
	- more info for bcc: https://github.com/iovisor/bcc

- Some other tools required to set up port hops:
	- sudo apt install socat
	- sudo apt install nftables
	- sudo apt install iptables
	- sudo apt install netcat
	- sudo apt install siege
```		


