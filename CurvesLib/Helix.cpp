#include "pch.h"
#include "Helix.h"

namespace curves
{
	Helix::Helix(double r, double step) : m_r(r), m_step(step) {}

	Point Helix::GetPoint(double t) const
	{
		return { m_r * cos(t), m_r * sin(t), t / (2.0 * M_PI) * m_step};
	}

	Point Helix::Derivative(double t) const
	{
		return { -m_r * sin(t), m_r * cos(t), m_step / (2 * M_PI) };
	}

	double Helix::GetRadius() const
	{
		return m_r;
	}

	double Helix::GetStep() const
	{
		return m_step;
	}

	std::string Helix::Description() const
	{
		std::stringstream s;
		s << "Helix: radius = " << GetRadius() << ", step = " << GetStep();
		return s.str();
	}
}