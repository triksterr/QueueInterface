
#include <iostream>
#include <__msvc_ostream.hpp>
#include <exception>
#include <stdexcept>

int main()
{
	using namespace std;
	setlocale(0, "");
	
	try
	{	
		throw std::runtime_error("Текст описания ошибки!");
	}
	catch(const std::exception &e) 
	{
		std::cerr << "Поймано исключение: " << e.what() << std::endl;
		
		exit(1);
	}

	std::cout << "Hello World!\n";
}

