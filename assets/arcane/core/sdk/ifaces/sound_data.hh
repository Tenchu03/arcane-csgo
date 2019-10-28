#pragma once

#include "../misc/macros.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/SoundEmitterSystem/isoundemittersystembase.h
	
	struct sound_data {
		PAD( pad_1, 4 );
		
		std::int32_t entity_index;
		std::int32_t channel;
		
		const char* sound_entry;
		
		PAD( pad_2, 8 );
		
		float volume;
		
		PAD( pad_3, 44 );
	};
}