#pragma once

namespace arcane::sdk::enums {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/const.h
	
	enum class flags {
		flags_on_ground = ( 1 << 0 ),
		flags_ducking = ( 1 << 1 ),
		flags_water_jump = ( 1 << 2 ),
		flags_on_train = ( 1 << 3 ),
		flags_in_rain = ( 1 << 4 ),
		flags_frozen = ( 1 << 5 ),
		flags_controls = ( 1 << 6 ),
		flags_client = ( 1 << 7 ),
		flags_fake_client = ( 1 << 8 ),
		flags_in_water = ( 1 << 9 ),
		flags_fly = ( 1 << 10 ),
		flags_swim = ( 1 << 11 ),
		flags_conveyor = ( 1 << 12 ),
		flags_npc = ( 1 << 13 ),
		flags_god_mode = ( 1 << 14 ),
		flags_no_target = ( 1 << 15 ),
		flags_aim_target = ( 1 << 16 ),
		flags_partial_ground = ( 1 << 17 ),
		flags_static_prop = ( 1 << 18 ),
		flags_graphed = ( 1 << 19 ),
		flags_grenade = ( 1 << 20 ),
		flags_step_movement = ( 1 << 21 ),
		flags_dont_touch = ( 1 << 22 ),
		flags_base_velocity = ( 1 << 23 ),
		flags_world_brush = ( 1 << 24 ),
		flags_object = ( 1 << 25 ),
		flags_kill_me = ( 1 << 26 ),
		flags_on_fire = ( 1 << 27 ),
		flags_dissolving = ( 1 << 28 ),
		flags_trans_rag_doll = ( 1 << 29 ),
		flags_unblockable_by_player = ( 1 << 30 )
	};
}
