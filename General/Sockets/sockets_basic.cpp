// A basic example for sockets
// 
// General Process for sockets:
// 
// 1. create a socket (mention the type: IP = AF_INET, etc)
// 2. create variable (struct) to hold address details,
//    for IP, this is an instance of a "sockaddr_in" struct
// 3. fill in the address details of the socket: (IP address, port)
// 4. bind the socket to the socket address
// 5. start sending/receiving data 

#include <sys/types.h>
#include <netinet/in.h> // sockaddr_in/socket(...)
#include <sys/socket.h> // bind
#include <string.h> // memset
#include <arpa/inet.h> // inet_ntop() / inet_pton() / inet_addr()
#include <iostream>


using std::cout;
using std::cerr;
using std::endl;

unsigned short portNumber = 0; 



int main()
{		
	// create a TCP/IP socket (descriptor)
	int sock = socket(AF_INET, SOCK_STREAM, 0); // can return < 0

	// fill in address and details for our socket
	sockaddr_in addr;
	memset((void *)&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET; 
	addr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY if you don't need a specific IP
	// addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // alternative way of specifying IP
	// inet_pton(AF_INET, "0.0.0.0", &(addr.sin_addr)); // alternative way of specifying IP
	addr.sin_port = htons(portNumber); // 0 indicates random available port (call getsockname after)


	// bind the socket to the address
	if(bind(sock, (sockaddr *)&addr, sizeof(addr)) < 0) // can return < 0
	{
		std::cerr << "bind failed";
		return 0;	
	}

	// the call to getsockname is necessary if you asked system to choose port
	if(portNumber == 0)
	{
		unsigned int addr_len = sizeof(addr);
		if(getsockname(sock, (sockaddr *)&addr, &addr_len) < 0)
		{
			std::cerr << "getsockname failed";
			return 0;
		}
	}
	
	// print the IP address 
	char buffer[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &(addr.sin_addr), buffer, INET_ADDRSTRLEN);    
	cout << "IP address: " << buffer << endl;

	// print the port
	cout << "bound socket to port: " << ntohs(addr.sin_port) << endl;




	return 0;
}


