#ifndef IN_MODULE_INTERFACE
#include "MathFunctions.h"
#include "mysqrt.h"
#else
module Math;
#endif

namespace mathfunctions {
	double sqrt(double x) {
		return detail::sqrt(x);
	}
}
