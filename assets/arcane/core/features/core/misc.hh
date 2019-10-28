#pragma once

#include <cmath>

#include "../../ifaces/ifaces.hh"
#include "../../menu/menu.hh"
#include "../../sdk/sdk.hh"
#include "../../../dependencies/fgui/FGUI.hh"

namespace arcane::core::features {
	extern void auto_bunny_hop( sdk::ifaces::user_cmd* );
	extern void rank_revealer( );
	extern void disconnect_to_lobby( );
	extern void clamp_view_angles( sdk::ifaces::user_cmd* );
}
