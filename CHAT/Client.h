#pragma once
#include <iostream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <vector>
#include <thread>

#pragma comment (lib, "Ws2_32.lib")



class client {
private:


	WSADATA wsadata;
	SOCKET clientSocket;
	sockaddr_in socket_addr;

	std::vector<std::string> other_users;



public:
	client();
	std::string login;
	std::string password;
	std::string ip;
	int PORT;
	void startUp();
	void bindSocket();
	void connection();
	void SendData(std::string& data);
	std::string Recieve();
	bool signUP();
	~client() {
		closesocket(clientSocket);
	}

	void InfOther();
	void checkOther();
	void get_msg();
	void stopSocket();
	void startSocket();


};


