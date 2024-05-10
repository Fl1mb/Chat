#include "Client.h"

client::~client() {
	closesocket(clientSocket);
	WSACleanup();
}

client::client() {
	this->startUp();
}


/// <>
/// Запуск сокета клиента
/// <>
void client::startUp() {
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsadata);
	if (iResult != NO_ERROR) {
		throw std::logic_error("Error of winsock");
		return;
	}
}


void client::connection() {
	if (connect(clientSocket, reinterpret_cast<sockaddr*>(&socket_addr), sizeof(socket_addr)) == SOCKET_ERROR) {
		throw std::logic_error("Error of connection");
		WSACleanup();
		return;
	}
	conn = true;

}

/// <summary>
/// Метод для настройки сокета
/// Задаем здесь ip и port, на который клиент должен подключиться
/// </summary>
void client::bindSocket() {
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket == INVALID_SOCKET) {
		throw std::logic_error("error of creating socket");
		WSACleanup();
		return;
	}
	socket_addr.sin_family = AF_INET;
	socket_addr.sin_port = htons(this->PORT);
	inet_pton(AF_INET, this->ip.c_str(), &socket_addr.sin_addr);
}


/////////////////////////////////////////
/// Геттеры и сеттеры 
std::string& client::get_ip() { return this->ip; }
std::string& client::get_login() { return this->login; }
std::string& client::get_password() { return this->password; }

void client::set_ip(std::string ip) { this->ip = ip; }
void client::set_login(std::string log) { this->login = log; }
void client::set_password(std::string pass) { this->password = pass; }
void client::set_port(int port) { this->PORT = port; }

////////////////////////////////////////////////////


bool client::signUP() {
	SendData(this->login);
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	SendData(this->password);
	std::string answer = Recieve();
	if (answer == "false") {
		return false;
	}
	return true;

}


/// <summary>
/// При вызове этого метода, он посылает серверу сообщение о том, что минус один пользователь
/// Сообщение такое странное, чтобы не считалось за сообщение и наоборот
/// </summary>
void client::disconnect() {
	std::string c = "1jdbnksajndy297dolsadsadsa";
	SendData(c);
	closesocket(clientSocket);
	conn = false;
}


/// <summary>
//////////////////////////////////////////////////
//Методы для отправки и получение сообщения с сервера
void client::SendData(std::string& data) {
	if (send(clientSocket, data.c_str(), data.size(), 0) == SOCKET_ERROR) {
		throw std::logic_error("error of sending msg");
		WSACleanup();
		return;
	}
}

std::string client::Recieve() {
	char buffer[1024];
	int bytes_recv = recv(clientSocket, buffer, sizeof(buffer), 0);
	if (bytes_recv <= 0) {
		throw std::logic_error("Error of recv msg");
		return "";
	}
	return std::string(buffer, bytes_recv);
}


///////////////////////////////////////
