#pragma once
#include <ostream>

namespace CurvesLib
{
	struct Point {
		double m_x;
		double m_y;
		double m_z;
	};

	std::ostream& operator<<(std::ostream& s, const Point& p);

	class Curve
	{
	public:
		virtual Point GetPoint(double t) const = 0;
		virtual Point Derivative(double t) const = 0;
	};
}

