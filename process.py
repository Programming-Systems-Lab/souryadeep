#!/usr/bin/env python3

import csv
import os
import pdb

def process(): 

	#f = open('./socat2hops2.csv', 'a')

	directory = os.fsencode("./")

	for filename in os.listdir(directory):
    	
		pdb.set_trace()
		elems = [] 
		elems.append(filename)

		with open (os.path.join(directory, filename), 'rt') as myfile:  # Open lorem.txt for reading
			for myline in myfile:              # For each line, read to a string,

				if ("elapsed" in myline):
					#print(myline[22:])
					print(myline[22:].split(',')[0])
					# and print the string.
					elems.append(myline[22:].split(',')[0])
				if ("data_transferred" in myline):
					#print(myline)                  # and print the string.
					print(myline[22:].split(',')[0])
					elems.append(myline[22:].split(',')[0])

		with open('./socat2hops.csv', 'a',encoding='utf-8') as csvfile: 
			csvwriter = csv.writer(csvfile) 
			csvwriter.writerows(elems)	

if __name__ == "__main__":
	print ("processing starting...\n")
	process()


