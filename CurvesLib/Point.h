#pragma once
#include <ostream>
#include "CurvesLib.h"

namespace CurvesLib
{
	struct Point {
		double m_x;
		double m_y;
		double m_z;
	};

	CURVESLIB_API std::ostream& operator<<(std::ostream& s, const Point& p);
}