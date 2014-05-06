CFLAGS=-c -Wall
LDFLAGS=-std=c++11
CC=g++

all: server client

# create executables

server: sockets_server.o
	$(CC) sockets_server.o $(LDFLAGS) -o server

client: sockets_client.o
	$(CC) sockets_client.o $(LDFLAGS) -o client

# create object files

sockets_server.o: sockets_server.cpp
	$(CC) $(CFLAGS) sockets_server.cpp $(LDFLAGS)

sockets_client.o: sockets_client.cpp
	$(CC) $(CFLAGS) sockets_client.cpp $(LDFLAGS)


clean:
	rm -rf server client 