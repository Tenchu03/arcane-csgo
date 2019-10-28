#pragma once

namespace arcane::sdk::enums {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/game/shared/in_buttons.h#L15
	
	enum button {
		button_attack = ( 1 << 0 ),
		button_jump = ( 1 << 1 ),
		button_duck = ( 1 << 2 ),
		button_forward = ( 1 << 3 ),
		button_back = ( 1 << 4 ),
		button_use = ( 1 << 5 ),
		button_cancel = ( 1 << 6 ),
		button_left = ( 1 << 7 ),
		button_right = ( 1 << 8 ),
		button_move_left = ( 1 << 9 ),
		button_move_right = ( 1 << 10 ),
		button_right_attack = ( 1 << 11 ),
		button_run = ( 1 << 12 ),
		button_reload = ( 1 << 13 ),
		button_left_alt = ( 1 << 14 ),
		button_right_alt = ( 1 << 15 ),
		button_score = ( 1 << 16 ),
		button_speed = ( 1 << 17 ),
		button_walk = ( 1 << 18 ),
		button_zoom = ( 1 << 19 ),
		button_first_weapon = ( 1 << 20 ),
		button_second_weapon = ( 1 << 21 ),
		button_bull_rush = ( 1 << 22 ),
		button_first_grenade = ( 1 << 23 ),
		button_second_grenade = ( 1 << 24 ),
		button_middle_attack = ( 1 << 25 )
	};
}
