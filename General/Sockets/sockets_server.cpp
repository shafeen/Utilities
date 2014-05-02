
#include <sys/types.h>
#include <sys/socket.h> // bind(...)
#include <netinet/in.h> // socket stuff
#include <string.h> // memset
#include <cstdio> // printf
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;


int main()
{
	// create a TCP/IP socket
	int mysock = socket(AF_INET, SOCK_STREAM, 0);

	// fill in socket address and port details
	sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY); // link to any IP
	addr.sin_port = htons(12345); // pick a random port

	// bind the socket
	unsigned int addrSize = sizeof(addr);
	bind(mysock, (sockaddr *)&addr, addrSize);
	getsockname(mysock, (sockaddr *)&addr, &addrSize); // needed for random port
	cout << "bound socket to port = " << ntohs(addr.sin_port) << endl;

	// since we are doing this for the server we
	// are going to listen on our socket for data
	cout << "accepting connections."  << endl;
	listen(mysock, 1);
	int acceptsock = accept(mysock, 0, 0); // start accepting connections
	shutdown(mysock, 2); // no need to listen for any more connections

	// start receiving data from client connection
	while(true)
	{	
		unsigned int BUF_SIZE = 1024;
		char buffer[1024];
		int bytesReceived = recv(acceptsock, &buffer, BUF_SIZE, 0);
		if(bytesReceived)
		{
			buffer[bytesReceived] = '\0';
			printf("%d bytes received, message: %s\n", bytesReceived, buffer);
		}
		else
		{
			printf("%s\n", "connection ended.");
			return 0;
		}	
	}



	return 0;
}