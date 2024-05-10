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

	std::string login;
	std::string password;
	std::string ip;
	bool conn = false;
	int PORT;



public:
	client();
	
	void startUp();
	void bindSocket();
	void connection();
	void SendData(std::string& data);
	std::string Recieve();
	bool signUP();
	~client();
	std::string& get_login();
	std::string& get_password();
	std::string& get_ip();

	void set_login(std::string log);
	void set_password(std::string pass);
	void set_ip(std::string ip);
	void set_port(int port);

	void disconnect();


};


