#include <stdio.h>
#include <winsock2.h>
#include <string.h>
#pragma comment(lib, "ws2_32.lib")

void ErrorHandling(char* message);

void main() {

	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) ErrorHandling("WSAStartup() error!!");

	char* addr = "127.212.124.78";
	unsigned long conv_addr = inet_addr(addr);

	if (conv_addr == INADDR_NONE) printf("Error occured! \n");
	else printf("Network ordered integer addr: %#lx \n", conv_addr);

	struct sockaddr_in saddr;
	char* strPtr;
	char strArr[20];

	saddr.sin_addr.s_addr = htonl(0x1020304);
	strPtr = inet_ntoa(saddr.sin_addr);
	strcpy(strArr, strPtr);
	printf("Dotted-Decimal notation3 %s \n", strArr);

	WSACleanup();
}

void ErrorHandling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}