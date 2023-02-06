#include <stdio.h>
#include "myError.h"
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define BUF_SIZE 1024
#define RLT_SIZE 4
#define OPSZ 4

int main(void)
{
	WSADATA wsaData;
	SOCKET hSocket;
	char opmsg[BUF_SIZE];
	int result, opndCnt, i;
	SOCKADDR_IN servAdr;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		Error("WSAStartup() error!!");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET)
		Error("socket() error!!");

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = inet_addr("192.168.45.156");
	servAdr.sin_port = htons(atoi("8080"));

	if (connect(hSocket, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		Error("connect() error!!");
	else
		puts("Connected...............");
	fputs("Operand count: ", stdout);
	scanf("%d", &opndCnt);
	opmsg[0] = (char)opndCnt;

	for (i = 0; i < opndCnt; i++)
	{
		printf("Operand %d: ", i + 1);
		scanf("%d", (int*)&opmsg[i * OPSZ + 1]);
	}
	fgetc(stdin);
	fputs("Operator: ", stdout);
	scanf("%c", &opmsg[opndCnt * OPSZ + 1]);
	
	send(hSocket, opmsg, opndCnt * OPSZ + 2, 0);
	puts("데이터 전송!!");
	recv(hSocket, &result, RLT_SIZE, 0);
	puts("데이터 수신!!");

	printf("Operation result: %d\n", result);
	closesocket(hSocket);
	WSACleanup();

	getch();
	
	return 0;
}