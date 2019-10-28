#pragma once

#define FMT_HEADER_ONLY

#include "../../ifaces/ifaces.hh"
#include "../../mem/mem.hh"
#include "../../menu/menu.hh"
#include "../../sdk/sdk.hh"
#include "../../../dependencies/fgui/FGUI.hh"
#include "../../../dependencies/fmt/format.hh"

namespace arcane::core::features {
	extern void watermark( );
	extern void window( );
	extern void player( );
	extern void grenade_preview( );
	extern void flash_alpha( );
	extern void view_model_fov( sdk::ifaces::view_setup* );
}
