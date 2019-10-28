#pragma once

#include "../misc/macros.hh"
#include "../../fgui/FGUI.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/vgui/ISurface.h

	struct surface {
		OFFSET( clipping_enabled( ), bool, 0x280 );

		VFUNC( draw_set_color( const std::int32_t r, const std::int32_t g, const std::int32_t b, const std::int32_t a ), 15, void( __thiscall* )( void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t ), r, g, b, a );
		VFUNC( draw_filled_rectangle( const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h ), 16, void( __thiscall* )( void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t ), x, y, w, h );
		VFUNC( draw_outlined_rectangle( const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h ), 18, void( __thiscall* )( void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t ), x, y, w, h );
		VFUNC( draw_line( const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h ), 19, void( __thiscall* )( void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t ), x, y, w, h );
		VFUNC( draw_set_text_font( const DWORD font ), 23, void( __thiscall* )( void*, DWORD ), font );
		VFUNC( draw_set_text_color( const std::int32_t r, const std::int32_t g, const std::int32_t b, const std::int32_t a ), 25, void( __thiscall* )( void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t ), r, g, b, a );
		VFUNC( draw_set_text_pos( const std::int32_t x, const std::int32_t y ), 26, void( __thiscall* )( void*, std::int32_t, std::int32_t ), x, y );
		VFUNC( draw_print_text( const wchar_t* text, const std::int32_t len ), 28, void( __thiscall* )( void*, const wchar_t*, std::int32_t, std::int32_t ), text, len, 0 );
		VFUNC( draw_set_texture_file( const std::int32_t texture_id, const char* texture_name, const std::int32_t hardware_filter, const bool force_reload ), 36, void( __thiscall* )( void*, std::int32_t, const char*, std::int32_t, bool ), texture_id, texture_name, hardware_filter, force_reload );
		VFUNC( draw_set_texture_rgba( const std::int32_t texture_id, unsigned const char* rgba_data, const std::int32_t width, const std::int32_t height ), 37, void( __thiscall* )( void*, std::int32_t, unsigned const char*, std::int32_t, std::int32_t ), texture_id, rgba_data, width, height );
		VFUNC( draw_set_texture( const std::int32_t texture_id ), 38, void( __thiscall* )( void*, std::int32_t ), texture_id );
		VFUNC( draw_textured_rectangle( const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h ), 41, void( __thiscall* )( void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t ), x, y, w, h );
		VFUNC( is_texture_id_valid( const std::int32_t texture_id ), 42, bool( __thiscall* )( void*, std::int32_t ), texture_id );
		VFUNC( create_new_texture_id( const bool is_procedural ), 43, std::int32_t( __thiscall* )( void*, bool ), is_procedural );
		VFUNC( get_screen_size( std::int32_t& x, std::int32_t& y ), 44, void( __thiscall* )( void*, std::int32_t&, std::int32_t& ), x, y );
		VFUNC( create_font( ), 71, DWORD( __thiscall* )( void* ) );
		VFUNC( set_font_glyph_set( const DWORD font, const char* font_name, const std::int32_t tall, const std::int32_t weight, const std::int32_t blur, const std::int32_t scan_lines, const std::int32_t flags, const std:: int32_t min_range, const std::int32_t max_range ), 72, void( __thiscall* )( void*, DWORD, const char*, std::int32_t, std::int32_t, std::int32_t, std::int32_t, std:: int32_t, std::int32_t, std::int32_t ), font, font_name, tall, weight, blur, scan_lines, flags, min_range, max_range );
		VFUNC( get_text_size( const DWORD font, const wchar_t* text, std::int32_t& wide, std::int32_t& tall ), 79, void( __thiscall* )( void*, DWORD, const wchar_t*, std::int32_t&, std::int32_t& ), font, text, wide, tall );
		VFUNC( play_sound(const char* file_name), 82, void(__thiscall*)(void*, const char*), file_name );
		VFUNC( get_cursor_position(std::int32_t& x, std::int32_t& y), 100, void(__thiscall*)(void*, std::int32_t&, std::int32_t&), x, y );
		VFUNC( draw_outlined_circle( const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h ), 103, void( __thiscall* )( void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t ), x, y, w, h );
		VFUNC( draw_textured_polygon( const std::int32_t vertex_count, fgui::vertex* vertex, const bool clip_vertices ), 106, void( __thiscall* )( void*, std::int32_t, fgui::vertex*, bool ), vertex_count, vertex, clip_vertices );
		VFUNC( draw_filled_rectangle_fade( const std::int32_t x, const std::int32_t y, const std::int32_t w, const std:: int32_t h, const std::int32_t first_alpha, const std::int32_t second_alpha, const bool is_horizontal ), 123, void( __thiscall* )( void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t, std::uint32_t, std:: uint32_t, bool ), x, y, w, h, first_alpha, second_alpha, is_horizontal );
		VFUNC( get_clip_rectangle( std::int32_t& x, std::int32_t& y, std::int32_t& w, std::int32_t& h), 146, void( __thiscall* )( void*, std::int32_t&, std::int32_t&, std::int32_t&, std::int32_t& ), x, y, w, h );
		VFUNC( set_clip_rectangle( const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h), 147, void( __thiscall* )( void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t ), x, y, w, h );
	};
}
