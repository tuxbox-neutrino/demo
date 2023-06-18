#include <iostream>
#include <string>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

int main()
{
	std::string version = "1.0";

#ifdef HAVE_CONFIG_H
	version = PACKAGE_VERSION;
#endif

	std::cout << "Hello, World! " << version << std::endl;

	return 0;
}

