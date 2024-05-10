#include "Serv.h"



int main() {

	try {
		Server test("127.0.0.1", 12345);
	}
	catch (const std::logic_error& ex) {
		std::cout << ex.what() << std::endl;
	}



	return 0;

}