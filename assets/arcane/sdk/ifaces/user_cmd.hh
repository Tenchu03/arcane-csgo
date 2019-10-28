#pragma once

#include "../misc/macros.hh"
#include "../misc/vector.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/game/shared/usercmd.h
	
	struct user_cmd {
		PAD( pad, 4 );

		std::int32_t command_number;
		std::int32_t tick_count;

		misc::vector view_angles;
		misc::vector aim_direction;

		float forward_move;
		float side_move;
		float up_move;

		std::int32_t buttons;
		std::uint8_t impulse;
		std::int32_t weapon_select;
		std::int32_t weapon_subtype;
		std::int32_t random_seed;
		std::uint16_t mouse_x;
		std::uint16_t mouse_y;

		bool has_been_predicted;
	};
}
