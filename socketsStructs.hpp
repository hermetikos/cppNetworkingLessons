#ifndef SOCKETSTRUCTS_H
#define SOCKETSTRUCTS_H

//addrinfo
//	a struct to prep socket addr structs for use
//	also used to lookup host & service names
//	first thing called when making a connection
//	note that a call to getaddrinfo() can mostly fill
//	this out for you
struct addrinfo {
	int		ai_flags; 			//AI_PASSIVE, AI_CANONNAME, etc.
	int		ai_family;			//AF_INET (IPv4), AF_INET6 (IPv6), AF_UNSPEC (agnostic)
	//used to set which version of IP protocol to use
	int		ai_socktype;		//SOCK_STREAM, SOCK_DGRAM
	//describes the socket type to be used (stream or datagram)
	
	size_t 	ai_addrlen;			//size of ai_addr in bytes
	struct 	sockaddr* ai_addr;	//struct sockaddr_in or _in6
	//holds details of IP addr structure
	char*	ai_canonname;		//full canonical hostname
	
	struct addrinfo* ai_next;	//linked list, next node
	//this points to one of several next elements
	//	usually you use 1st working element,
	//	but circumstances dictate how to choose
}
//sockaddr
//	holds socket info for many types of sockets
struct sockaddr {
	unsigned short sa_family;	//address family, AF_xxx
	//Used mainly to state either AF_INET (IPv4) OR AF_INET6 (IPv6)
	//	and occasionally other things
	char		   sa_data;		//14 bytes of protocol address
	//holds the destination addr & the port number for the socket
}

//sockaddr_in
//	a complimentary class to sockaddr
//	the "_in" stands for internet, and is used w/ IPv4
//
struct sockaddr_in {
	short int			sin_family;		//Address family, AF_INET
	//corresponds to sa_family in sockaddr, and must be set to AF_INET
	unsigned short int	sin_port;		//port number
	//must be in Network Byte Order (i.e. Big Endian)
	struct in_addr		sin_addr;		//Internet addr
	unsigned char		sin_zero[8];	//Same size as struct sockaddr
	//used to pad stucture to length of sockaddr by using memset()
	//	(a function which copies n bytes of a const into mem)
}

#endif