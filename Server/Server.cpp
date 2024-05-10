#include "Serv.h"



Server::~Server() {
	for (auto it : Clients) {
		closesocket(it.second);
	}
	WSACleanup();
}

Server::Server(const std::string ip, const int port) : Ip(ip), PORT(port) {
	this->StartUP();
	this->CreateSocket(Ip, PORT);
	std::thread bindThread(&Server::BindToListen, this);
	bindThread.join();
	
}
/// 
/// Метод для запуска сервера
void Server::StartUP() {
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
		throw std::logic_error("Error of inizialize WinSock");
	}
	FD_ZERO(&master_fds);
	max_fd = server_socket;

}

/// <summary>
/// Метод для создания Сокета для работы сервера
void Server::CreateSocket(const std::string ip, const int PORT) {
	server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (server_socket == INVALID_SOCKET) {
		throw std::logic_error("Error creating socket");
		WSACleanup();
		return;
	}
	Ip = ip;
	inet_pton(AF_INET, ip.c_str(), &server_addr.sin_addr);
	server_addr.sin_port = htons(PORT);
	server_addr.sin_family = AF_INET;

}

//Метод для настройки сокета. Здесь мы его биндим и выставляем на прослушивание.
void Server::BindToListen() {
	if (bind(server_socket, (sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
		throw std::logic_error("Error binding socket ");
		WSACleanup();
		return;
	}

	if (listen(server_socket, SOMAXCONN) == SOCKET_ERROR) {
		throw std::logic_error(" Error listening ");
		WSACleanup();
		return;
	}
	std::cout << "Server listening port is " << server_addr.sin_port << std::endl;
	std::cout << "Server ip is " << Ip << std::endl;

	//При каждом новом подключении создается пара - логин/сокет и выделяется поток для работы с клиентом
	while (true) {
		std::string login = CONNECT();
		if (login.empty()) continue;
		clients_thread.emplace_back([this, login]() { this->ClientHandler(login); });
	}


}

/// <summary>
/// При подключении к сокету
/// Этот  метод запрашивает логин/пароль
/// Проходит авторизацию, а также обновляет количество пользователей в онлайн
std::string Server::CONNECT() {
	SOCKET socket;
	socket = accept(server_socket, NULL, NULL);
	if (socket == INVALID_SOCKET) {
		throw std::logic_error("Error accepting connection");
		WSACleanup();
		return "";
	}
	std::cout << " New Client connected " << std::endl;


	while (true) {
		std::string login = SIGNUP(socket);
		std::string pass = SIGNUP(socket);
		Clients[login] = socket;

		//Когда пользователь присылает пароль и логин на проверку, мы к логину привязываем его пароль
		//В случае, если под таким же логином захочется еще раз зайти, то придется вводить старый пароль

		if (reg(login, pass)) {
			SendData("You have been signed up!", login);
			users.push_back(login);
			std::this_thread::sleep_for(std::chrono::microseconds(10));
			SendDataBaseToAll();

		}
		else if (authorize(login, pass)) {
			SendData("You have been signed up!", login);
			users.push_back(login);
			std::this_thread::sleep_for(std::chrono::microseconds(10));
			SendDataBaseToAll();
		}
		else {
			SendData("false", login);
			continue;
		}

		return login;
	}

}


/////////////////////////////////////////////////////////////

//Основной метод для работы с клиентом
void Server::ClientHandler(std::string login) {
	try {
		SOCKET socket = Clients[login];
		while (checkConnection(login)) {
			try {
				std::string msg = RecieveData(login);
				if (msg == "1jdbnksajndy297dolsadsadsa") { break; }
				for (std::string it : users) {
					SendData(login, it);
					SendData(msg, it);
				}
			}
			catch (const std::logic_error& ex) {
				break;
			}
		}
		disconnect(login);
		delete_user(login);
		SendDataBaseToAll();
		std::cout << login << " has been disconnected " << std::endl;
	}
	catch (const std::logic_error& ex) {
		std::cout << ex.what() << std::endl;
	}
}


////////////////////////////////////////////////////////////
void Server::disconnect(std::string& login) {
	closesocket(Clients[login]);
}


//Методы для отправки/получения сообщений от клиента
//////////////////////////////////////////////////////////
std::string Server::RecieveData(std::string &login) {
	char buffer[1024];
	int bytes_recv = recv(Clients[login], buffer, sizeof(buffer), 0);
	if (bytes_recv <= 0) {
		throw std::logic_error("Error of recv msg");
		WSACleanup();
		return "";
	}
	return std::string(buffer, bytes_recv);
}

void Server::SendData(const std::string& data, std::string& login) {
	if (send(Clients[login], data.c_str(), data.size(), 0) == SOCKET_ERROR) {
		throw std::logic_error("Error of sending message");
		WSACleanup();
		return;
	}
}
///////////////////////////////////////////////////////////

//МЕТОДЫ для регистрации клиента, а также авторизации

bool Server::reg(std::string log, std::string pass) {
	if (logs[log] == "") {
		logs[log] = pass;
		return true;
	}
	return false;
}
bool Server::authorize(std::string log, std::string pass) {
	if (logs[log] == pass) {
		return true;
	}
	return false;
}

std::string Server::SIGNUP(SOCKET& client) {
	char buffer[1024];
	int bytes_recv = recv(client, buffer, sizeof(buffer), 0);
	if (bytes_recv <= 0) {
		throw std::logic_error("Error of recv msg");
		WSACleanup();
		return "";
	}
	return std::string(buffer, bytes_recv);
}

/////////////////////////////////////////////////



void Server::SendDataBase(std::string& login) {
	SendData("&dsa9dwaldwoaiddwahgdgy872coac" + std::to_string(users.size()), login);
}

bool Server::checkConnection(std::string& login) {
	int error = 0;
	socklen_t len = sizeof(error);
	int result = getsockopt(Clients[login], SOL_SOCKET, SO_ERROR, (char*)&error, &len);
	if (result == SOCKET_ERROR) {
		return false;
	}
	return error == 0;
}

void Server::delete_user(std::string& login) {
	auto iter = std::find(users.begin(), users.end(), login);
	users.erase(iter);

	Clients.erase(login);
}

void Server::SendDataBaseToAll() {
	for (std::string& it : users) {
		SendDataBase(it);
	}
}