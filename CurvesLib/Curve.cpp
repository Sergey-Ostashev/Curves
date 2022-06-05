#include "pch.h"
#include "Curve.h"

namespace CurvesLib
{
	std::ostream& operator<<(std::ostream& s, const Point& p)
	{
		s << "(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return s;
	}
}