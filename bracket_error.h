#pragma once
#include <iostream>
#include <exception>
using namespace std;

class bracket_error :
    public exception
{
private:
	string message;

public:
	bracket_error()noexcept = default;

	bracket_error(string message_p) : message{ message_p } {}

	virtual const char* what()const noexcept final override { return message.c_str(); }

	virtual ~bracket_error() = default;
};

