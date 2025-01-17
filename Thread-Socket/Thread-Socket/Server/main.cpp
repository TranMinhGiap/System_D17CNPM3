#include <iostream>
#include <winsock2.h>
#include <thread>
#include <string>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

void receiveMessages(SOCKET clientSocket) {
    char buffer[1024];
    while (true) {
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0'; // Ð?m b?o buffer có chu?i k?t thúc
            cout << "Client: " << buffer << endl;
        } else if (bytesReceived == 0) {
            cout << "Client disconnected!" << endl;
            break;
        } else {
            cerr << "Error receiving data! Error code: " << WSAGetLastError() << endl;
            break;
        }
    }
}

void sendMessages(SOCKET clientSocket) {
    string message;
    while (true) {
        getline(cin, message);
        int bytesSent = send(clientSocket, message.c_str(), message.length(), 0);
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

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        cerr << "Error creating socket! Error code: " << WSAGetLastError() << endl;
        return 1;
    }

    sockaddr_in serverAddr = {};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(1024);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "Error binding socket! Error code: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "Error listening on socket! Error code: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Server is listening on port 1024..." << endl;

    SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "Error accepting connection! Error code: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Client connected!" << endl;

    // G?i tin nh?n chào m?ng d?n client
    send(clientSocket, "Welcome to the server!", 22, 0);

    thread recvThread(receiveMessages, clientSocket);
    thread sendThread(sendMessages, clientSocket);

    recvThread.join();
    sendThread.join();

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}

