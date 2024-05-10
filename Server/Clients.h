#pragma once
#pragma comment(lib, "Ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include <string>
#include <WS2tcpip.h>
#include <map>
#include <thread>
#include <vector>
#include "Header.h"

class Client {
public:

	struct UserData {
		std::string UserLogin;
		std::string UserPassword;
	};

	UserData client;

	std::vector<std::string>FrientdsLogins;

protected:



};