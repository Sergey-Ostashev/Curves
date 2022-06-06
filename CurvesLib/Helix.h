#pragma once
#include "Curve.h"
#include "Consts.h"

namespace CurvesLib
{
	class CURVESLIB_API Helix : public CurveImpl<HELIX_TYPE_ID>
	{
	public:
		Helix(double r, double step);
		double GetRadius() const;
		double GetStep() const;
		std::string Description() const override;
		Point GetPoint(double t) const override;
		Point Derivative(double t) const override;
	private:
		double m_r;
		double m_step;
	};
}

