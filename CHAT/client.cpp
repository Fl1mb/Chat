#include "Client.h"

void client::checkOther() {
	if (other_users.size() == 0) {
		std::cout << "noone is online :(" << std::endl;
		return;
	}
	for (unsigned int i = 0; i < other_users.size(); i++) {
		std::cout << i + 1 << ". " << other_users[i] << " is online!" << std::endl;
	}
	std::cout << std::endl;
}

void client::InfOther() {

	std::string number = Recieve();
	int num = std::stoi(number);

	std::vector<std::string>temp;

	for (int i = 0; i < num; i++) {
		std::string name = Recieve();
		temp.push_back(name);
	}

	other_users = temp;


}
void client::startSocket() {
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	socket_addr.sin_family = AF_INET;
	socket_addr.sin_port = htons(PORT);
	inet_pton(AF_INET, ip.c_str(), &socket_addr.sin_addr);
	bind(clientSocket, (sockaddr*)&socket_addr, sizeof(socket_addr));
	listen(clientSocket, 1);
}

void client::stopSocket() {
	closesocket(clientSocket);
}

client::client() {
	this->startUp();
}

bool client::signUP() {
	SendData(this->login);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	SendData(this->password);
	std::string answer = Recieve();
	if (answer == "false") {
		return false;
	}
	return true;

}

void client::startUp() {
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsadata);
	if (iResult != NO_ERROR) {
		throw std::logic_error("Error of winsock");
		return;
	}
}

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

void client::connection() {
	if (connect(clientSocket, reinterpret_cast<sockaddr*>(&socket_addr), sizeof(socket_addr)) == SOCKET_ERROR) {
		throw std::logic_error("Error of connection");
		WSACleanup();
		return;
	}

}

void client::SendData(std::string& data) {
	if (send(clientSocket, data.c_str(), data.size(), 0) == SOCKET_ERROR) {
		throw std::logic_error("error of sending msg");
		WSACleanup();
		return;
	}
}

void client::get_msg() {
	while (true) {
		try {
			std::string msg = Recieve();

		}
		catch (const std::logic_error& ex) {
			continue;
		}
	}
}

std::string client::Recieve() {
	char buffer[1024];
	int bytes_recv = recv(clientSocket, buffer, sizeof(buffer), 0);
	if (bytes_recv <= 0) {
		throw std::logic_error("Error of recv msg");
		WSACleanup();
		return "";
	}
	return std::string(buffer, bytes_recv);
}

