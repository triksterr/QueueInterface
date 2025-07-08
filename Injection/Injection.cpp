#include <iostream>
#include "..\idbg.hpp"

class Injection
{
public:
	Injection(){}
	~Injection(){}
	
	void envelope(){}
	
	void injection()
	{
		std::cout << "Injection" << std::endl;
	}
	
	void injection2(){}
	
	void check(){}
private:
};

class Implementation 
{
public:
	
	Implementation(): data(0) {}
	
	Implementation(int data): data(data)
	{}
	
	virtual ~Implementation(){}
	
	int get() const 
	{
		return data;
	}
	
	void set(int data) 
	{
		this->data = data;
	}
	
	void print() 
	{
		injection(); 

		std::cout << data << "\n";
	}
	
	virtual void injection() {}  
private:
	int data;
};

class SimplRel : public Implementation
{};

class AddRel : public Injection, public Implementation
{
public:
	void injection() override
	{
		Injection::injection();  
	}
};

int main()
{
    std::cout << "Hi!\n";

	SimplRel a1;
	a1.set(17);
	a1.print();

	AddRel a2;
	a2.set(1234);
	a2.print();
}

