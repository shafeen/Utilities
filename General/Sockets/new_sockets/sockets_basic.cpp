// A basic example on how to use sockets 
// with the more modern -> getaddrinfo(..)
//
//
// getaddrinfo function prototype:
// ---------------------------------
// int getaddrinfo(const char *nodename, const char *servname,
//                 const struct addrinfo *hints, struct addrinfo **res);
//
// void freeaddrinfo(struct addrinfo *ai); // used to free output addrinfo
//
// addrinfo struct details:
// ---------------------------------
// struct addrinfo {
//   int     ai_flags;          // AI_PASSIVE, AI_CANONNAME, ...
//   int     ai_family;         // AF_xxx
//   int     ai_socktype;       // SOCK_xxx
//   int     ai_protocol;       // 0 (auto) or IPPROTO_TCP, IPPROTO_UDP 
//
//   socklen_t  ai_addrlen;     // length of ai_addr
//   char   *ai_canonname;      // canonical name for nodename
//   struct sockaddr  *ai_addr; // binary address
//   struct addrinfo  *ai_next; // next structure in linked list
// };
//
// This will demonstrate creating and binding of a TCP/IP socket:
// 

#include <sys/types.h>
#include <sys/socket.h>
#include <cstring> // memset
#include <netdb.h>
#include <iostream>

using std::cout;
using std::cin;

int main()
{
	// hints to use as input
	// out_info will contain getaddrinfo output
	addrinfo hints, *out_info;
	int sock = -1; // used for our socket descriptor
	
	// fill in the hints addrinfo struct with our connection details
	// we will create a TCP/IPV4 socket using our IP address
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET; // we can used AF_UNSPEC as well for both ipv4/v6
	hints.ai_socktype = SOCK_STREAM; // TCP socket
	hints.ai_flags = AI_PASSIVE; // use current ip address

	// getaddrinfo can return -1 on failure but we can ignore that now
	// we will assume that getaddrinfo will just work without any errors
	const char *port = "8080";
	int rv = getaddrinfo(nullptr, port, &hints, &out_info);

	// now try to bind with the first possible result
	for(addrinfo *i = out_info; i != nullptr; i = i->ai_next)
	{
		// create socket (can return -1 on error)
		sock = socket(i->ai_family, i->ai_socktype, i->ai_protocol);
		if(sock < 0)
		{
			cout << "cannot create this socket\n";
			continue;
		}

		// bind socket (OR connect if this is a client)
		int bindrv = bind(sock, i->ai_addr, i->ai_addrlen);
		if(bindrv < 0)
		{
			cout << "cannot bind this socket\n";
			sock = -1;
			continue;
		}

		// if we get here bind worked!
		break;
	}	
	freeaddrinfo(out_info); // to avoid memory leaks for out_info


	if(sock != -1)
		cout << "succesfully bound socket to port:" << port << "\n";
	else
		cout << "failed to bind socket to port:" << port << "\n";


	// after we bind the socket we are free to send and recv data now
	// ...
}