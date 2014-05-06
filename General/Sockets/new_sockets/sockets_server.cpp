#include <sys/types.h>
#include <sys/socket.h> // socket/bind
#include <netdb.h> // getaddrinfo
#include <cstring> // memset
#include <iostream>


using std::cout;
using std::cin;

int main()
{
	addrinfo hints, *out_info;
	int sock = -1;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	const char *port = "8081";

	int rv = getaddrinfo(nullptr, port, &hints, &out_info);
	if(rv < 0) cout << "getaddrinfo failed!\n";

	// make socket and bind
	for(addrinfo *i = out_info; i != nullptr; i = i->ai_next)
	{
		sock = socket(i->ai_family, i->ai_socktype, i->ai_protocol);
		if(sock < 0) 
		{
			cout << "socket failed!\n"; 
			continue;
		}

		int bindrv = bind(sock, i->ai_addr, i->ai_addrlen);
		if(bindrv < 0)
		{
			cout << "bind failed!\n"; 
			sock = -1;
			continue;
		}

		if(sock > 0 && bindrv > 0)
			break;
	}     

	if(sock == -1)
		return 0;


	// start listening for and accepting connections
	cout << "listening for connections on port "<< port << "\n";
	listen(sock, 1);
	int acceptsock = accept(sock, 0, 0);
	shutdown(sock, 2);

	// wait to receive data
	while(1)
	{
		char buffer[1024];
		int bytesReceived = recv(acceptsock, &buffer, 1024, 0);
		if(bytesReceived)
		{
			buffer[bytesReceived] = '\0';
			cout << bytesReceived << " bytes recvd:\t"; 
			cout << buffer << "\n";
		}
		else
		{
			cout << "connection ended\n";
			break;
		}
	}

}














