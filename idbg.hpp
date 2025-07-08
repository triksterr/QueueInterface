#pragma once
#ifndef __IDBG_HPP__
#define __IDBG_HPP__

#include <iostream>

void idbg() 
{
#if defined(_DEBUG) && !defined(NDEBUG) 
	std::cout << std::endl;
#endif
}

template<typename T, typename... Args>
void idbg(T first, Args... args) 
{
#if defined(_DEBUG) && !defined(NDEBUG) 
	std::cout << first;  

#pragma warning(suppress:4984) 
	if constexpr(sizeof...(args) > 0) 
	{
		std::cout << " ";  
		idbg(args...); 
	}
	else
	{
		std::cout << std::endl;  
	}
#endif
}

#endif 
