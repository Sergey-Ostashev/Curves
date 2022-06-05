#include "pch.h"
#include "Circle.h"

namespace CurvesLib
{
	Circle::Circle(double r) : m_r(r) {}

	Point Circle::GetPoint(double t) const
	{
		return { m_r * cos(t), m_r * sin(t), 0 };
	}

	Point Circle::Derivative(double t) const
	{
		return { -m_r * sin(t), m_r * cos(t), 0 };
	}
}