#pragma once
#include "Curve.h"

namespace CurvesLib
{
	class Ellipse : public Curve
	{
	public:
		Ellipse(double rx, double ry);
		Point GetPoint(double t) const override;
		Point Derivative(double t) const override;
	private:
		double m_rx;
		double m_ry;
	};
}

