#include "pch.h"
#include "Circle.h"

namespace curves
{
	Circle::Circle(double r) : m_r(r) {}

	double Circle::GetRadius() const
	{
		return m_r;
	}

	Point Circle::GetPoint(double t) const
	{
		return { m_r * cos(t), m_r * sin(t), 0 };
	}

	Point Circle::Derivative(double t) const
	{
		return { -m_r * sin(t), m_r * cos(t), 0 };
	}

	std::string Circle::Description() const
	{
		std::stringstream s;
		s << "Circle: radius = " << GetRadius();
		return s.str();
	}
}