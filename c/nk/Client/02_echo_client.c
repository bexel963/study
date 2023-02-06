/*
	- 문제점
		: send(), recv() 가 호출될 때마다 문자열 단위로 실제 입출력이 이뤄진다.
		  하지만 TCP는 데이터의 경계가 존재하지 않는다.
		  즉, 둘 이상의 send()호출로 전달된 문자열 정보가 묶여서 한번에 서버로 전송될 수 있다.
		  그리고 그러한 상황이 발생하면 클라이언트는 한번에 둘 이상의 문자열 정보를 서버로부터 되돌려 받아서, 원하는 결과를 얻지 못할 수 있다.

		  또 다른 경우로, 서버는 한번의 send()호출로 데이터 전송을 명령했지만, 전송할 데이터의 크기가 크다면 OS는 내부적으로 이를 여러 개의 
		  조각으로 나눠서 클라이언트에게 전송할 수도 있는 일이다.
		  그리고 이 과정에서 데이터의 모든 조각이 클라이언트에게 전송되지 않았음에도 불구하고, 클라이언트는 read함수를 호출할지도 모른다.
		  이 모든 문제가 TCP의 데이터 전송특성에서 비롯된 것이다.
*/

/*
	- 에코 클라이언트는 문자열을 write함수 호출을 통해 한방에 전송하고, read함수를 통해 자신이 전송한 문자열 데이터를 한방에 수신하기를 원한다는 문제가 있다.
	  시간이 좀 지나면 100% 수신할 수 있지만 이는 이치에 맞는 클라언트가 아니다.
	  이치에 맞는 클라이언트라면, 문자열 데이터가 전송되었을 때 이를 모두 읽어서 출력해야 한다.

	- 에코 클라이언트의 경우 수신해야 할 데이터의 크기를 미리 알고 있기 때문에 그 크기만큼의 데이터를 수신할 때 까지 반복해서 read함수를 호출하면 된다.

	- 수산할 데이터의 크기를 파악하는 것이 불가능한 경우에 필요한 것이 바로 어플리케이션 프로토콜의 정의의다.
			ex) "Q가 전달되면 연결을 종료한다."
	  예 처럼 데이터의 송수신 과정에서 데이터의 끝을 파악할 수있는 프로토콜을 별도로 정의해서 데이터의 끝을 표현하거나, 송수신될 데이터의 크기를 미리 알려줘서
	  그에 따른 대비가 가능해야 한다.
	  서버, 클라이언트의 구현 과정에서 이렇게 하나, 둘씩 만들어지는 약속을 모아서 '어플리케이션 프로토콜' 이라고 한다.
	  즉, 어플리케이션 프로토콜은 목적에 맞는 프로그램의 구현에 따라서 정의하게 되는 약속에 지나지 않는다.
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
	printf("----클라이언트----\n");
	WSADATA wsaData;
	SOCKET hSocket;
	char message[BUF_SIZE];
	SOCKADDR_IN servAdr;
	int str_len, recv_len, recv_cnt;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) ErrorHandling("WSAStartup() error!");
	else
		puts("소켓 버전 정보 설정.");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET) ErrorHandling("socket() error!");
	else
		printf("클라이언트 소켓 생성. %d\n", hSocket);
	
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