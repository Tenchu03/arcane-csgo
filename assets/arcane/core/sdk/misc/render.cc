#include "render.hh"

namespace arcane::sdk::misc {
	void create_font( fgui::font& font, const std::string_view family, const std::int32_t size, const std::int32_t flags, const bool bold ) {
		font = core::ifaces::get_ifaces.surface->create_font( );

		core::ifaces::get_ifaces.surface->set_font_glyph_set( font, family.data( ), size, bold ? 800 : 0, 0, 0, flags, 0, 0 );
	}

	void get_screen_size( std::int32_t& x, std::int32_t& y ) {
		core::ifaces::get_ifaces.surface->get_screen_size( x, y );
	}

	fgui::dimension get_text_size( const fgui::font& font, const std::string_view text ) {
		fgui::dimension dimension = { 0, 0 };

		core::ifaces::get_ifaces.surface->get_text_size( font, std::wstring( text.begin( ), text.end( ) ).data( ), dimension.width, dimension.height );

		return dimension;
	}

	void rectangle( const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const fgui::color color ) {
		core::ifaces::get_ifaces.surface->draw_set_color( color.m_red, color.m_green, color.m_blue, color.m_alpha );
		core::ifaces::get_ifaces.surface->draw_filled_rectangle( x, y, x + w, y + h );
	}

	void outlined_rectangle( const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const fgui::color color ) {
		core::ifaces::get_ifaces.surface->draw_set_color( color.m_red, color.m_green, color.m_blue, color.m_alpha );
		core::ifaces::get_ifaces.surface->draw_outlined_rectangle( x, y, x + w, y + h );
	}

	void line( const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const fgui::color color ) {
		core::ifaces::get_ifaces.surface->draw_set_color( color.m_red, color.m_green, color.m_blue, color.m_alpha );
		core::ifaces::get_ifaces.surface->draw_line( x, y, w, h );
	}

	void polygon( const std::int32_t count, fgui::vertex* vertex, const fgui::color color ) {
		static auto texture = core::ifaces::get_ifaces.surface->create_new_texture_id( true );

		std::uint8_t buffer[4] = { 255, 255, 255, 255 };

		core::ifaces::get_ifaces.surface->draw_set_texture_rgba( texture, buffer, 1, 1 );
		core::ifaces::get_ifaces.surface->draw_set_color( color.m_red, color.m_green, color.m_blue, color.m_alpha );
		core::ifaces::get_ifaces.surface->draw_set_texture( texture );
		core::ifaces::get_ifaces.surface->draw_textured_polygon( count, vertex, true );
	}

	void text( const std::int32_t x, const std::int32_t y, const fgui::color color, const DWORD font, const std::string_view text ) {
		const auto converted_text = std::wstring( text.begin( ), text.end( ) );

		core::ifaces::get_ifaces.surface->draw_set_text_color( color.m_red, color.m_green, color.m_blue, color.m_alpha );
		core::ifaces::get_ifaces.surface->draw_set_text_font( font );
		core::ifaces::get_ifaces.surface->draw_set_text_pos( x, y );
		core::ifaces::get_ifaces.surface->draw_print_text( converted_text.c_str( ), std::wcslen( converted_text.c_str( ) ) );
	}

	void circle( const std::int32_t x, const std::int32_t y, const std::int32_t radius, const std::int32_t segments, const fgui::color color ) {
		core::ifaces::get_ifaces.surface->draw_set_color( color.m_red, color.m_green, color.m_blue, color.m_alpha );
		core::ifaces::get_ifaces.surface->draw_outlined_circle( x, y, radius, segments );
	}

	void gradient( const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const std::int32_t first_alpha, const std::int32_t second_alpha, const fgui::color color, const bool horizontal ) {
		core::ifaces::get_ifaces.surface->draw_set_color( color.m_red, color.m_green, color.m_blue, color.m_alpha );
		core::ifaces::get_ifaces.surface->draw_filled_rectangle_fade( x, y, x + w, y + h, first_alpha, second_alpha, horizontal );
	}

	void colored_gradient( const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const fgui::color first_color, const fgui::color second_color, const bool is_horizontal ) {
		if ( is_horizontal ) {
			rectangle( x, y, w, h, first_color );

			for ( auto i = 0; i < w; i++ )
				rectangle( x + i, y, 1, h, fgui::color( second_color.m_red, second_color.m_red, second_color.m_blue, i / w * 255 ) );
		} else {
			rectangle( x, y, w, h, first_color );

			for ( auto i = 0; i < w; i++ )
				rectangle( x, y + i, w, 1, fgui::color( second_color.m_red, second_color.m_red, second_color.m_blue, i / w * 255 ) );
		}
	}

	void get_alpha_value( const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h ) {
		for ( auto i = 0; i < h / 5; i++ ) {
			for ( auto t = 0; t < w / 5; t++ ) {
				const auto pixel = static_cast< std::int32_t >( std::roundf( t ) );
				const auto line = static_cast< std::int32_t >( std::roundf( i ) );
				const auto is_brick_light = line % 2 ? pixel % 2 : pixel % 2 == 0;
				const auto new_color = is_brick_light ? fgui::color( 60, 60, 60 ) : fgui::color( 40, 40, 40 );

				rectangle( x + t * 5, y + i * 5, 5, 5, new_color );
			}
		}
	}

	void clip_rectangle( const std::int32_t x, const std::int32_t y, const std::int32_t width, const std::int32_t height ) {
		const fgui::rect viewport = { x, y, ( x + width ), ( y + height ) };

		core::ifaces::get_ifaces.surface->set_clip_rectangle( viewport.left, viewport.top, viewport.right, viewport.bottom );
	}

	void setup_render_funcs( ) {
		fgui::render.create_font = create_font;
		fgui::render.get_screen_size = get_screen_size;
		fgui::render.get_text_size = get_text_size;
		fgui::render.rect = rectangle;
		fgui::render.gradient = gradient;
		fgui::render.colored_gradient = colored_gradient;
		fgui::render.outline = outlined_rectangle;
		fgui::render.line = line;
		fgui::render.polygon = polygon;
		fgui::render.circle = circle;
		fgui::render.text = text;
		fgui::render.alpha = get_alpha_value;
		fgui::render.clip_rect = clip_rectangle;

		fonts.push_back( CONV_TO_TYPE( std::int32_t, enums::font::font_watermark ) );
		fonts.push_back( CONV_TO_TYPE( std::int32_t, enums::font::font_visuals ) );

		fgui::render.create_font( fonts[ CONV_TO_TYPE( std::int32_t, enums::font::font_watermark ) ], "Tahoma", 12, fgui::external::font_flags::SHADOW, false );
		fgui::render.create_font( fonts[ CONV_TO_TYPE( std::int32_t, enums::font::font_visuals ) ], "Tahoma", 16, fgui::external::font_flags::SHADOW, false );
	}
}
