#include <sys/types.h>
#include <sys/socket.h> // socket/bind
#include <netdb.h> // getaddrinfo
#include <cstring> // memset
#include <iostream>
#include <unistd.h> // sleep

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
	const char *servaddr = "localhost";

	int rv = getaddrinfo(servaddr, port, &hints, &out_info);
	if(rv < 0) cout << "getaddrinfo failed!\n";

	// make socket and connect
	for(addrinfo *i = out_info; i != nullptr; i = i->ai_next)
	{
		sock = socket(i->ai_family, i->ai_socktype, i->ai_protocol);
		if(sock < 0) 
		{
			cout << "socket failed!\n"; 
			continue;
		}

		int bindrv = connect(sock, i->ai_addr, i->ai_addrlen);
		if(bindrv < 0)
		{
			cout << "connect failed (is server up?)!\n"; 
			sock = -1;
			continue;
		}

		if(sock > 0 && bindrv > 0)
			break;
	}     
	freeaddrinfo(out_info);

	if(sock == -1)
		return 0;

	cout << "connecting to " << servaddr << ":" << port << "\n";

	// start sending data
	while(1)
	{
		char buffer[1024];
		memset(&buffer, 0 , 1024);
		cout << "enter msg: ";
		cin >> buffer;
		
		send(sock, &buffer, strlen(buffer), 0);

		sleep(1);	
	}

}














