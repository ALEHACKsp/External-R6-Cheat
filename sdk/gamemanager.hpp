#pragma once
#include "../includes.hpp"

class c_gamemanager {
private:
	std::uintptr_t address;
public:
	c_gamemanager(std::uintptr_t address) : address(address) {};

	auto get_controller_list() -> std::uintptr_t {
		auto list_encrypted = (impl::memory->read<std::uintptr_t>(this->address + 0x178) ^ 0xA4B142E68329A1B8) - 0x3C6D1896C18C7E52;
		auto list = (list_encrypted >> 10) | (list_encrypted << 54);

		return list;
	}
	auto get_controller_count() -> std::uint32_t {
		auto count_encrypted = (impl::memory->read<std::uintptr_t>(this->address + 0x180) ^ 0xA4B142E68329A1B8) - 0x3C6D1896C18C7E52;
		auto count = (count_encrypted >> 10) | (count_encrypted << 54);

		return static_cast<std::uint32_t>(count) & 0x3FFFFFFF;
	}
};