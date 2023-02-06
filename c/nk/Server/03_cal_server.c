/*
	�� ���� ����&Ŭ���̾�Ʈ ���ø����̼� �������� ����.
		
		- Ŭ���̾�Ʈ�� ������ �������ڸ��� �ǿ������� ���������� 1����Ʈ �������·� �����Ѵ�.
		- Ŭ���̾�Ʈ�� ������ �����ϴ� ���� �ϳ��� 4����Ʈ�� ǥ���Ѵ�.
		- ������ ������ �������� ������ ������ �����Ѵ�. ���������� 1����Ʈ�� �����Ѵ�.
		- ���� +, -, * �� �ϳ��� �����ؼ� �����Ѵ�.
		- ������ �������� 4����Ʈ ������ ���·� Ŭ���̾�Ʈ���� �����Ѵ�.
		- �������� ���� Ŭ���̾�Ʈ�� �������� ������ �����Ѵ�.
*/	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
#include "myError.h"

#define BUF_SIZE 1024
#define OPSZ 4

int calculate(int opnum, int opnds[], char oprator);

int main(void)
{
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	char opinfo[BUF_SIZE];
	int result, opndCnt, i;
	int recvCnt, recvLen;
	SOCKADDR_IN servAdr, clntAdr;
	int clntAdrSize;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		Error("WSAStartup() error!!");
	
	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET)
		Error("socket() error!!");
	
	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi("8080"));
	
	if (bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		Error("bind() error!!");
	if (listen(hServSock, 5) == SOCKET_ERROR)
		Error("listen() error!!");
	clntAdrSize = sizeof(clntAdr);

	for (i = 0; i < 5; i++)
	{
		opndCnt = 0;
		hClntSock = accept(hServSock, (SOCKADDR*)&clntAdr, &clntAdrSize);
		printf("������ �� 5������ ���� -> ���� %d��° Ŭ�󸮾�Ʈ�� ����!!\n", i+1);
		recv(hClntSock, &opndCnt, 1, 0);

		recvLen = 0;
		while ((opndCnt * OPSZ + 1) > recvLen)
		{
			recvCnt = recv(hClntSock, &opinfo[recvLen], BUF_SIZE - 1, 0);
			recvLen += recvCnt;
		}
		result = calculate(opndCnt, (int*)opinfo, opinfo[recvLen - 1]);
		
		send(hClntSock, (char*)&result, sizeof(result), 0);
		closesocket(hClntSock);
	}
	closesocket(hServSock);
	WSACleanup();

	return 0;
	
}

int calculate(int opnum, int opnds[], char op)
{
	int result = opnds[0], i;
	
	switch (op)
	{
	case '+':
		for (i = 1; i < opnum; i++) result += opnds[i];
		break;
	case '-':
		for (i = 1; i < opnum; i++) result -= opnds[i];
		break;
	case '*':
		for (i = 1; i < opnum; i++) result *= opnds[i];
		break;
	}
	
	return result;
}