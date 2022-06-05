#include "pch.h"
#include "Ellipse.h"

namespace CurvesLib
{
	Ellipse::Ellipse(double rx, double ry) : m_rx(rx), m_ry(ry) {}

	Point Ellipse::GetPoint(double t) const
	{
		return { m_rx * cos(t), m_ry * sin(t), 0 };
	}

	Point Ellipse::Derivative(double t) const
	{
		return { -m_rx * sin(t), m_ry * cos(t), 0 };
	}
}