
#include <sys/types.h>
#include <sys/socket.h> // bind(...)
#include <netinet/in.h> // socket stuff
#include <arpa/inet.h> // inet_* functions
#include <string.h> // memset
#include <iostream>
#include <netdb.h>
#include <unistd.h>
#include <cstdio>


using std::cout;
using std::cerr;
using std::endl;


int main(int argc, char **argv)
{	
	// create a TCP/IP socket
	int	mysock = socket(AF_INET, SOCK_STREAM, 0);
	
	// address and port details for the server 
	struct sockaddr_in serverAddr;
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	hostent *hp = gethostbyname(argv[1]); // gethostbyname is deprecated
	// memcpy(&(serverAddr.sin_addr.s_addr), hp->h_addr, hp->h_length);
	serverAddr.sin_addr.s_addr = inet_addr(hp->h_name); // alternative to above
	serverAddr.sin_port = htons(12345);

	// connect to the server (similar to bind)
	connect(mysock, (sockaddr *) &serverAddr, sizeof(serverAddr));

	// start sending data to the server
    while(true)
    {
    	char msg[1024];
    	printf("%s: ", "enter message");
    	std::cin >> msg;
   		
   		send(mysock, msg, strlen(msg), 0);
       	
       	sleep(2);
    }


	return 0;
}