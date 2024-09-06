#ifndef IN_MODULE_INTERFACE
#include <math.h>
#include "MathFunctions.h"
#include "mysqrt.h"
#else
module;
#include <math.h>

module Math;
#endif

namespace mathfunctions::detail {
	double sqrt(double x) {
		return ::sqrt(x);
	}
}
