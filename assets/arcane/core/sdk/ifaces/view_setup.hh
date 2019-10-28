#pragma once

#include "../misc/macros.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/view_shared.h

	struct view_setup {
		PAD( pad_1, 176 );
		
		float view_model_fov;
	};
}
