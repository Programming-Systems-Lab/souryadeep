#NOTE: PLEASE DECIDE WHICH OF THE BELOW IS NEEDED AND COMMENT OUT ACCORDINGLY
#      BEFORE RUNNING. THIS SCRIPT DOES NOT RUN AS IS

#this is to observe one port at once
#need to run this across multiple tmux sessions/multiple terminals
#better granularity to observe

sudo tcpdump -i any -nn port 9000
sudo tcpdump -i any -nn port 9001
sudo tcpdump -i any -nn port 9002
sudo tcpdump -i any -nn port 9003
sudo tcpdump -i any -nn port 9004

#this is to observe all ports at once
#sudo tcpdump -i any port {9000 or 9001 or 9002 or 9003 or 9004}
