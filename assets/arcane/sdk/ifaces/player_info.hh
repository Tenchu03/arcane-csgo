#pragma once

#include "../misc/macros.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/cdll_int.h
	
	struct player_info {
		std::int64_t reserved;

		union {
			std::int64_t steam_id_64;
			std::int32_t xuid_low;
			std::int32_t xuid_high;
		};

		char name[ 128 ];

		std::int32_t user_id;

		char guid[ 20 ];

		PAD( pad, 16 );

		DWORD friends_id;

		char friends_name[ 128 ];

		bool fake_player;
		bool is_hltv;

		std::uint32_t custom_files[ 4 ];
		std::uint8_t files_downloaded;
	};
}
