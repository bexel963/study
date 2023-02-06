#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
#include "myError.h"

#define BUF_SIZE 30

int main(void)
{
	WSADATA wsaData;
	SOCKET hSocket;
	FILE* fp;

	char buf[BUF_SIZE];
	int readCnt;
	SOCKADDR_IN servAdr;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		Error("WSAStartup() error!!");

	fp = fopen("receive.txt", "wb");
	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET)
		Error("socket() error!!");
	else
		puts("클라이언트 소켓 생성!!");

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAdr.sin_port = htons(atoi("8080"));
	puts("서버 주소 가져옴.");

	if (connect(hSocket, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		Error("connect() error!!");
	else
		puts("서버에 연결 요청!!");

	while ((readCnt = recv(hSocket, buf, BUF_SIZE, 0)) != 0)
		fwrite((void*)buf, 1, readCnt, fp);

	puts("Received file data");
	send(hSocket, "Thank you", 10, 0);
	fclose(fp);
	closesocket(hSocket);
	WSACleanup();

	getch();

	return 0;
}