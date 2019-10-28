#pragma once

#include "../misc/vector.hh"
#include "../misc/netvar_tree.hh"

namespace arcane::sdk::ifaces {
	struct entity {
		NETVAR( get_health( ), std::int32_t, "DT_BasePlayer", "m_iHealth" );
		NETVAR( get_armor_value( ), std::int32_t, "DT_CSPlayer", "m_ArmorValue" );
		NETVAR( get_flags( ), std::int32_t, "DT_BasePlayer", "m_fFlags" );
		NETVAR( get_team( ), std::int32_t, "DT_BaseEntity", "m_iTeamNum" );
		NETVAR( get_round_kills( ), std::int32_t, "DT_CSPlayer", "m_iNumRoundKills" );

		NETVAR( is_scoped( ), bool, "DT_CSPlayer", "m_bIsScoped" );
		NETVAR( is_controlling_bot( ), bool, "DT_CSPlayer", "m_bIsControllingBot" );
		NETVAR( has_helmet( ), bool, "DT_CSPlayer", "m_bHasHelmet" );
		NETVAR( has_defuse_kit( ), bool, "DT_CSPlayer", "m_bHasDefuser" );

		NETVAR( get_flash_duration( ), float, "DT_CSPlayer", "m_bHasDefuser" );
		NETVAR( get_flash_alpha( ), float, "DT_CSPlayer", "m_flFlashMaxAlpha" );
		NETVAR( get_health_shot_boost_expiration_time( ), float, "DT_CSPlayer", "m_flHealthShotBoostExpirationTime" );

		NETVAR( get_vec_origin( ), misc::vector, "DT_BaseEntity", "m_vecOrigin" );

		OFFSET( is_dormant( ), bool, 0xED );
	};
}
