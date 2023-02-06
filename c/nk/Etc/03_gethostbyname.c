#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include "myError.h"

int main(void)
{
	WSADATA wsaData;
	int i;
	struct hostent* host;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		Error("WSAStartup() error!!");

	host = gethostbyname("www.naver.com");
	if (!host)
		Error("gethost.....error");

	printf("Official name: %s\n", host->h_name);
	for (i = 0; host->h_aliases[i]; i++)
		printf("Aliases %d: %s\n", i + 1, host->h_aliases[i]);
	printf("Address type: %s\n", (host->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6");
	for (i = 0; host->h_addr_list[i]; i++)
		printf("IP addr %d: %s\n", i + 1, inet_ntoa(*(struct in_addr*)host->h_addr_list[i]));
	WSACleanup();

	return 0;
}