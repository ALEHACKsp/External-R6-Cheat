#pragma once
#include "../includes.hpp"

inline std::uintptr_t camera_right = 0x1B0;
inline std::uintptr_t camera_up = 0x1C0;
inline std::uintptr_t camera_forward = 0x1D0;
inline std::uintptr_t camera_translation = 0x1E0;
inline std::uintptr_t camera_fovx = 0x370;
inline std::uintptr_t camera_fovy = 0x374;

class c_cameramanager {
private:
	std::uintptr_t address;
public:
	c_cameramanager(std::uintptr_t address) : address(address) {};

	auto world_to_screen(vec3_t& world_pos, vec3_t& screen_pos) -> bool {
		if (!this->address)
			return false;

		vec3_t temp = world_pos - impl::memory->read<vec3_t>(this->address + camera_translation);

		float x = temp.dot(impl::memory->read<vec3_t>(this->address + camera_right));
		float y = temp.dot(impl::memory->read<vec3_t>(this->address + camera_up));
		float z = temp.dot(impl::memory->read<vec3_t>(this->address + camera_forward) * -1.f);

		screen_pos.x = (globals::width / 2.f) * (1.f + x / -impl::memory->read<float>(this->address + camera_fovx) / z);
		screen_pos.y = (globals::height / 2.f) * (1.f - y / -impl::memory->read<float>(this->address + camera_fovy) / z);
		return z >= 1.0f;
	}
};