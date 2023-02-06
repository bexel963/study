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

/*
	- ���� Ŭ���̾�Ʈ�� ���ڿ��� write�Լ� ȣ���� ���� �ѹ濡 �����ϰ�, read�Լ��� ���� �ڽ��� ������ ���ڿ� �����͸� �ѹ濡 �����ϱ⸦ ���Ѵٴ� ������ �ִ�.
	  �ð��� �� ������ 100% ������ �� ������ �̴� ��ġ�� �´� Ŭ���Ʈ�� �ƴϴ�.
	  ��ġ�� �´� Ŭ���̾�Ʈ���, ���ڿ� �����Ͱ� ���۵Ǿ��� �� �̸� ��� �о ����ؾ� �Ѵ�.

	- ���� Ŭ���̾�Ʈ�� ��� �����ؾ� �� �������� ũ�⸦ �̸� �˰� �ֱ� ������ �� ũ�⸸ŭ�� �����͸� ������ �� ���� �ݺ��ؼ� read�Լ��� ȣ���ϸ� �ȴ�.

	- ������ �������� ũ�⸦ �ľ��ϴ� ���� �Ұ����� ��쿡 �ʿ��� ���� �ٷ� ���ø����̼� ���������� �����Ǵ�.
			ex) "Q�� ���޵Ǹ� ������ �����Ѵ�."
	  �� ó�� �������� �ۼ��� �������� �������� ���� �ľ��� ���ִ� ���������� ������ �����ؼ� �������� ���� ǥ���ϰų�, �ۼ��ŵ� �������� ũ�⸦ �̸� �˷��༭
	  �׿� ���� ��� �����ؾ� �Ѵ�.
	  ����, Ŭ���̾�Ʈ�� ���� �������� �̷��� �ϳ�, �Ѿ� ��������� ����� ��Ƽ� '���ø����̼� ��������' �̶�� �Ѵ�.
	  ��, ���ø����̼� ���������� ������ �´� ���α׷��� ������ ���� �����ϰ� �Ǵ� ��ӿ� ������ �ʴ´�.
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
	SOCKADDR_IN servAdr;
	int str_len, recv_len, recv_cnt;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) ErrorHandling("WSAStartup() error!");
	else
		puts("���� ���� ���� ����.");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET) ErrorHandling("socket() error!");
	else
		printf("Ŭ���̾�Ʈ ���� ����. %d\n", hSocket);
	
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

		str_len = send(hSocket, message, strlen(message), 0);
		
		recv_len = 0;
		while (recv_len < str_len)
		{
			recv_cnt = recv(hSocket, message, BUF_SIZE - 1, 0);
			if (recv_cnt == -1) ErrorHandling("recv() error!");
			recv_len += recv_cnt;
		}

		/*
			str_len = recv(hSocket, message, BUF_SIZE - 1, 0);
		*/		
		message[recv_len] = 0;
		printf("Message from server: %s \n", message);
	}
	closesocket(hSocket);
	WSACleanup();
}

void ErrorHandling(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	getchar();
	exit(1);
}