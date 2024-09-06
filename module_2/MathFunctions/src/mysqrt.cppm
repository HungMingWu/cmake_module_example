module;
#include <math.h>

export module Math:detail;

export namespace mathfunctions::detail {
	double sqrt(double x) {
		return ::sqrt(x);
	}
}
