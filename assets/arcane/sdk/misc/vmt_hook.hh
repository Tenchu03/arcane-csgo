#pragma once

#include <memory>

namespace arcane::sdk::misc {
	class vmt_hook final {
	public:
		vmt_hook( ) = default;

		explicit vmt_hook( void* table ) {
			base = static_cast< std::uintptr_t** >( table );

			while ( static_cast< std::uintptr_t* >( *base )[ size ] )
				++size;

			total = *base;
			current = std::make_unique< std::size_t[ ] >( size );

			std::memcpy( current.get( ), total, size * sizeof( std::size_t ) );

			*base = current.get( );
		}

		~vmt_hook( ) {
			*base = total;
		}

		bool hook_func( const std::size_t index, void* func ) const {
			if ( index > size )
				return false;

			current[ index ] = reinterpret_cast< std::uintptr_t >( func );

			return true;
		}

		bool unhook_func( const std::size_t index ) const {
			if ( index > size )
				return false;

			current[ index ] = total[ index ];

			return true;
		}

		template < typename T = void* > T get_orig_func( const std::size_t index ) {
			return reinterpret_cast< T >( total[ index ] );
		}

	private:
		std::size_t size = 0;
		std::uintptr_t** base = nullptr;
		std::uintptr_t* total = nullptr;
		std::unique_ptr< std::uintptr_t[ ] > current = nullptr;
	};
}
