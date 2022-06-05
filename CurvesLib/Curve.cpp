#include "pch.h"
#include "Curve.h"

namespace CurvesLib
{
	size_t Curve::GetTypeHash() const
	{
		const std::type_info& ti = typeid(*this);
		return ti.hash_code();
	}
}