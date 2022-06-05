#include "pch.h"
#include "Helix.h"

namespace CurvesLib
{
	Helix::Helix(double r, double step) : m_r(r), m_step(step) {}

	Point Helix::GetPoint(double t) const
	{
		return { m_r * cos(t), m_r * sin(t), t / (2.0 * M_PI) * m_step};
	}

	Point Helix::Derivative(double t) const
	{
		return { -m_r * sin(t), m_r * cos(t), 0.5 / M_PI };
	}
}