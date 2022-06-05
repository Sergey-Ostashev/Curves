#pragma once
#include "Curve.h"

namespace CurvesLib
{
	class Helix : public Curve
	{
	public:
		Helix(double r, double step);

		Point GetPoint(double t) const override;
		Point Derivative(double t) const override;
	private:
		double m_r;
		double m_step;
	};
}

