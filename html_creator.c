/*
	compile: gcc -Wall html_creator.c -o html_creator
	duplicates file, but doubling the next ones size
	usage: experimenting with a multi-server application over multi-port hop
	to test efficiency of a XDP filter, vs tradition nftables and iptable filters

	ls -al; check whether each file is double the size of the previous file
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFSIZE 4096
#define MAXLENGTH 3

/*create 100 files of doubling size*/
#define NUMFILES 100 


void itoa(int n, char s[]);
void reverse(char s[]);

int main(int argc, char* argv[]){

	int i = 1;

	if (argc != 2) {
		fprintf (stderr, "usage: ./html_creator <file_to_dup>\n");
		exit(1);
	}

	int fd_read, fd_write;

	for (int i = 1; i <= NUMFILES; ++i) {

		char s[MAXLENGTH];

		char *tmpname = malloc (strlen(argv[1] + 7));
		strcpy (tmpname,argv[1]);
		itoa (i,s);
		strcat (tmpname, s);
		strcat (tmpname, ".html");
		
		fd_write = open (tmpname, O_RDWR | O_CREAT, 0666);

		for (int j = 0; j < i; ++j) {
			
			fd_read = open (argv[1], O_RDONLY, S_IRWXU);

			int n;
			char buf[BUFFSIZE];

			while (n = read(fd_read, buf, BUFFSIZE)) {
				write (fd_write, buf, n);
			}

			close(fd_read);
		}

		free (tmpname);				
		close (fd_write);
	}

	return 0;
}


void itoa(int n, char s[]){

	int i, sign;
	
	sign = n;
	i = 0;

	do {					
		s[i++] = abs(n%10) + '0';
	} while((n/=10));

	if(sign < 0)
		s[i++] = '-';

	s[i] = '\0';

	reverse(s);

}

void reverse(char s[]){

	char reversed[MAXLENGTH];
	int i = 0;
	int j = strlen(s);

	while(s[i] != '\0') {

		reversed[i] = s[j-1-i];
		i++;
	}
	s[i] = '\0';
}
