#include <iostream>
#include <stdio.h>
#include <winsock2.h>// bat buoc
#include <conio.h>
int main()
{
	/* Khai bao bien */
	WSADATA wsaData;
	SOCKADDR_IN serAddr, cliAddr;
	int iRc;
	int adsize;
	char buffer[256];
	
	/* Nap thu vien va khoi tao socket */
	iRc = WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET ssk = socket(AF_INET, SOCK_STREAM, 0);
	
	/* Thiet lap dia chi cho socket */
	serAddr.sin_family = AF_INET;
	serAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serAddr.sin_port = htons(1024);
	
	/* Gan dia chi va thuc hien ket noi*/
	iRc = bind(ssk, (LPSOCKADDR)&serAddr, sizeof(serAddr));
	iRc = listen(ssk, 5);
	adsize = sizeof(cliAddr);
	SOCKET sk = accept(ssk, (LPSOCKADDR)&cliAddr, &adsize);
	while(1)
	{
		char c;
		iRc = recv(sk, &c,1, 0);
		if(c==27)
			break;
		printf("%c\n",c);
	}// while
	/* ??ng socket v? giai ph?ng t?i nguy?n */
	closesocket(sk);
	closesocket(ssk);
	WSACleanup();
	
	getch();
	return 0;
}

