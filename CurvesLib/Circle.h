#pragma once
#include "Curve.h"

namespace CurvesLib
{
	class Circle : public Curve
	{
	public:
		Circle(double r);

		Point GetPoint(double t) const override;
		Point Derivative(double t) const override;
	private:
		double m_r;
	};
}

