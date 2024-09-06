#pragma once

#ifdef IN_MODULE_INTERFACE
#define EXPORT export
#else
#define EXPORT
#endif

namespace mathfunctions {
	EXPORT double sqrt(double x);
}
