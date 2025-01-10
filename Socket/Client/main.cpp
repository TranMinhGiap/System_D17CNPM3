#include <stdio.h>
#include <winsock2.h>
#include <conio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	/* Khai báo bien */
	WSADATA wsaData;
	SOCKADDR_IN rAddr;
	//char buffer[20]="Hello2";
	int iRc;
	/* Nap thu vien va khoi tao socket */
	iRc = WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET sk = socket(AF_INET, SOCK_STREAM, 0);
	/* Ket noi den Server */
	rAddr.sin_family = AF_INET;
	rAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	rAddr.sin_port = htons(1024);
	iRc = connect(sk, (LPSOCKADDR)&rAddr, sizeof(rAddr));
	
	string c;
	while(1)
	{
		fflush(stdin);getline(cin,c);
//	send(sk, c.c_str(), c.length(), 0);
		if(c == "bye")
			break;
		printf("%s\n", c.c_str());
	}//while

	
	/* Ðóng socket và giai phong tai nguyen */
	closesocket(sk);
	WSACleanup();
	
	getch();
	return 0;
}

