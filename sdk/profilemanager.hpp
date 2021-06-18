#pragma once
#include "../includes.hpp"

class c_profilemanager {
private:
	std::uintptr_t address;
public:
	c_profilemanager(std::uintptr_t address) : address(address) {};
};