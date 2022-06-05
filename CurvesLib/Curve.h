#pragma once
#include <ostream>
#include <typeinfo>
#include "CurvesLib.h"

namespace CurvesLib
{
	struct Point {
		double m_x;
		double m_y;
		double m_z;
	};

	CURVESLIB_API std::ostream& operator<<(std::ostream& s, const Point& p);

	class CURVESLIB_API Curve
	{
	public:
		size_t GetTypeHash() const;
		virtual Point GetPoint(double t) const = 0;
		virtual Point Derivative(double t) const = 0;
	};
}

