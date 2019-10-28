#pragma once

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/tier1/utlvector.h
	
	template < typename T > struct utl_vector {
		T& operator[ ]( std::int32_t i ) {
			return memory[ i ];
		}

		T* memory;
		
		std::int32_t allocation_count;
		std::int32_t grow_size;
		std::int32_t size;
		
		T* elements;
	};
}
