#pragma once
#include "Curve.h"

namespace CurvesLib
{
	class CURVESLIB_API Circle : public Curve
	{
	public:
		Circle(double r);
		double GetRadius() const;

		Point GetPoint(double t) const override;
		Point Derivative(double t) const override;
	private:
		double m_r;
	};
}

