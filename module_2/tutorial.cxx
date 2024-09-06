#include <cmath>
#include <iostream>
#include <string>
#include "config.h"
import Math;

int main(int argc, char* argv[])
{
	std::cout << "Project Version: " << PROJECT_VERSION_MAJOR << "." << PROJECT_VERSION_MINOR << std::endl;
	std::cout << "Author: " << AUTHOR_NAME << std::endl;

	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " number" << std::endl;
		return 1;
	}

	// convert input to double
	const double inputValue = atof(argv[1]);

	// calculate square root
	const double outputValue = mathfunctions::detail::sqrt(inputValue);
	std::cout << "The square root of " << inputValue << " is " << outputValue
		<< std::endl;
	return 0;
}
