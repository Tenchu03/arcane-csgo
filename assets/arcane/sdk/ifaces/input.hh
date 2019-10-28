#pragma once

#include "../misc/macros.hh"
#include "../misc/vector.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/game/shared/cam_thirdperson.h
	
	struct input {
		PAD( pad_1, 12 );
		
		bool is_track_ir_available;
		bool is_mouse_initialized;
		bool is_mouse_active;
		
		PAD( pad_2, 158 );
		
		bool is_camera_in_third_person;
		
		std::byte pad_3;
		
		misc::vector camera_offset;
	};
}
