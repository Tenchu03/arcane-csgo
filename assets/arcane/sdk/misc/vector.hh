#pragma once

#include <cmath>

namespace arcane::sdk::misc {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/mathlib/vector.h
	
	struct vector {
		float x, y, z;

		explicit vector( const float w = 0, const float h = 0, const float r = 0 ) {
			x = w;
			y = h;
			z = r;
		}

		void normalize( ) {
			x = std::isfinite( x ) ? std::remainderf( x, 360.0f ) : 0.0f;
			y = std::isfinite( y ) ? std::remainderf( y, 360.0f ) : 0.0f;
			z = 0.0f;
		}

		vector operator+( const vector& angle ) const {
			return vector( x + angle.x, y + angle.y, z + angle.z );
		}
	};
}
