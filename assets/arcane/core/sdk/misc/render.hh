#pragma once

#include <vector>

#include "../../ifaces/ifaces.hh"
#include "../../../dependencies/fgui/FGUI.hh"

namespace arcane::sdk::misc {
	inline std::vector< fgui::font > fonts;

	extern void create_font( fgui::font&, std::string_view, std::int32_t, std::int32_t, bool );
	extern void get_screen_size( std::int32_t&, std::int32_t& );
	extern fgui::dimension get_text_size( const fgui::font&, std::string_view );
	extern void rectangle( std::int32_t, std::int32_t, std::int32_t, std::int32_t, fgui::color );
	extern void outlined_rectangle( std::int32_t, std::int32_t, std::int32_t, std::int32_t, fgui::color );
	extern void line( std::int32_t, std::int32_t, std::int32_t, std::int32_t, fgui::color );
	extern void polygon( std::int32_t, fgui::vertex*, fgui::color );
	extern void text( std::int32_t, std::int32_t, fgui::color, DWORD, std::string_view );
	extern void circle( std::int32_t, std::int32_t, std::int32_t, std::int32_t, fgui::color );
	extern void gradient( std::int32_t, std::int32_t, std::int32_t, std::int32_t, std::int32_t, std::int32_t, fgui::color, bool );
	extern void colored_gradient( std::int32_t, std::int32_t, std::int32_t, std::int32_t, fgui::color, fgui::color, bool );
	extern void get_alpha_value( std::int32_t, std::int32_t, std::int32_t, std::int32_t );
	extern void clip_rectangle( std::int32_t, std::int32_t, std::int32_t, std::int32_t );

	extern void setup_render_funcs( );
}
