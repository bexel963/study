/*
	- ������
		: send(), recv() �� ȣ��� ������ ���ڿ� ������ ���� ������� �̷�����.
		  ������ TCP�� �������� ��谡 �������� �ʴ´�.
		  ��, �� �̻��� send()ȣ��� ���޵� ���ڿ� ������ ������ �ѹ��� ������ ���۵� �� �ִ�.
		  �׸��� �׷��� ��Ȳ�� �߻��ϸ� Ŭ���̾�Ʈ�� �ѹ��� �� �̻��� ���ڿ� ������ �����κ��� �ǵ��� �޾Ƽ�, ���ϴ� ����� ���� ���� �� �ִ�.

		  �� �ٸ� ����, ������ �ѹ��� send()ȣ��� ������ ������ ���������, ������ �������� ũ�Ⱑ ũ�ٸ� OS�� ���������� �̸� ���� ���� 
		  �������� ������ Ŭ���̾�Ʈ���� ������ ���� �ִ� ���̴�.
		  �׸��� �� �������� �������� ��� ������ Ŭ���̾�Ʈ���� ���۵��� �ʾ������� �ұ��ϰ�, Ŭ���̾�Ʈ�� read�Լ��� ȣ�������� �𸥴�.
		  �� ��� ������ TCP�� ������ ����Ư������ ��Ե� ���̴�.
*/
#include <stdio.h>
#include <winsock2.h>
#include <stdlib.h>
#include <string.h>
#pragma comment(lib, "ws2_32.lib")

#define BUF_SIZE 1024
void ErrorHandling(char* message);

void main()
{
	printf("----Ŭ���̾�Ʈ----\n");
	WSADATA wsaData;
	SOCKET hSocket;
	char message[BUF_SIZE];
	int strLen;
	SOCKADDR_IN servAdr;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) ErrorHandling("WSAStartup() error!");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET) ErrorHandling("socket() error!");
	
	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAdr.sin_port = htons(atoi("9190"));

	if (connect(hSocket, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		ErrorHandling("connect() error!");
	else
		puts("\nConnected.............");

	while (1)
	{
		fputs("\nInput message(Q to quit): ", stdout);
		fgets(message, BUF_SIZE, stdin);

		if (!strcmp(message, "q\n") || !strcmp(message, "Q\n")) break;

		send(hSocket, message, strlen(message), 0);
		strLen = recv(hSocket, message, BUF_SIZE - 1, 0);
		message[strLen] = 0;
		printf("Message from server: %s \n", message);
	}
	closesocket(hSocket);
	WSACleanup();
}

void ErrorHandling(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}