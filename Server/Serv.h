#pragma once

#pragma comment(lib, "Ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include <string>
#include <WS2tcpip.h>
#include <map>
#include <thread>
#include <vector>


class Server{
private:
	WSADATA wsadata;
	SOCKET server_socket;
	sockaddr_in server_addr;
	std::map<std::string, SOCKET> Clients;
	std::string Ip;
	int PORT;
	std::map<std::string, std::string> logs;
	std::vector<std::thread>clients_thread;
	std::vector<std::string>users;

	fd_set master_fds;
	int max_fd;
	

public:
	void StartUP();
	void CreateSocket(const std::string ip, const int PORT);
	void BindToListen();
	Server(const std::string ip, const int port);
	~Server();
	bool reg(std::string log, std::string pass);
	bool authorize(std::string log, std::string pass);

	void ClientHandler(std::string login);
	std::string CONNECT();
	void SendData(const std::string& data, std::string& login);
	std::string RecieveData(std::string& login);
	std::string SIGNUP(SOCKET& client);
	void disconnect(std::string& login);
	void SendDataBase(std::string& login);

	bool checkConnection(std::string &login);
	void delete_user(std::string& login);
	void SendDataBaseToAll();



};
