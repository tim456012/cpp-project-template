#include <fstream>
#include <iostream>

int main()
{
	std::ifstream file("./config.txt", std::ios::in | std::ios::binary);
	if (!file.is_open()) {
		std::cerr << "Error opening file" << std::endl;
		return 1;
	}

	std::string line;
	while (getline(file, line)) {
		std::cout << line << std::endl;
	}

	file.close();
	return 0;
}