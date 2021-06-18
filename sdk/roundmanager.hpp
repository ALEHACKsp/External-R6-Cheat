#pragma once
#include "../includes.hpp"

enum class round_t {
	round_swap = 0,
	operator_selection,
	prep_phase,
	action_phase,
	round_end,
	main_menu
};

class c_roundmanager { 
private:
	std::uintptr_t address;
public:
	c_roundmanager(std::uintptr_t address) : address(address) {};

	auto get_round() -> round_t {
		auto round = impl::memory->read<std::uint32_t>(this->address + 0xC0);
		return static_cast<round_t>(_rotl(_rotl(round, 17) - 0x3704E0D6, 19));
	};
};