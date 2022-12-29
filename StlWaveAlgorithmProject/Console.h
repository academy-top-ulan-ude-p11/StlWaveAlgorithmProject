#include <iostream>
#include <windows.h>
#pragma once
class Console
{
	HANDLE hOut;
	HANDLE hIn;
public:
	Console(std::string title = "Консоль Windows")
	{
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		hIn  = GetStdHandle(STD_INPUT_HANDLE);
		SetConsoleTitle((LPCTSTR)title.c_str());
	}
};

