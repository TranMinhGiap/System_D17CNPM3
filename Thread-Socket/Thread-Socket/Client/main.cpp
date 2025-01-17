#include <iostream>
#include <winsock2.h>
#include <thread>
#include <string>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

void receiveMessages(SOCKET serverSocket) {
    char buffer[1024];
    while (true) {
        int bytesReceived = recv(serverSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0'; // Ð?m b?o buffer có chu?i k?t thúc
            cout << "Server: " << buffer << endl;
        } else if (bytesReceived == 0) {
            cout << "Server disconnected!" << endl;
            break;
        } else {
            cerr << "Error receiving data! Error code: " << WSAGetLastError() << endl;
            break;
        }
    }
}

void sendMessages(SOCKET serverSocket) {
    string message;
    while (true) {
        getline(cin, message);
        int bytesSent = send(serverSocket, message.c_str(), message.length(), 0);
        if (bytesSent == SOCKET_ERROR) {
            cerr << "Error sending message! Error code: " << WSAGetLastError() << endl;
            break;
        }
    }
}

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup failed! Error code: " << WSAGetLastError() << endl;
        return 1;
    }

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "Error creating socket! Error code: " << WSAGetLastError() << endl;
        return 1;
    }

    sockaddr_in serverAddr = {};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(1024);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "Error connecting to server! Error code: " << WSAGetLastError() << endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    cout << "Connected to server!" << endl;

    thread recvThread(receiveMessages, clientSocket);
    thread sendThread(sendMessages, clientSocket);

    recvThread.join();
    sendThread.join();

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}

