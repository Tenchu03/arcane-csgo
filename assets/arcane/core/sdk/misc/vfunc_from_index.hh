#pragma once

namespace arcane::sdk::misc {
	template < typename T > static T vfunc_from_index( void* base, const std::size_t index ) {
		return ( *reinterpret_cast< T** >( base ) )[ index ];
	}
}
