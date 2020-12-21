// OnvifTools.cpp : Defines the entry point for the application.
//

#include "OnvifTools.h"
#include "test_onvif.h"

int main(int argc, char ** argv)
{
	std::cout << "Hello CMake." << std::endl;
	TestOnvif::Inst()->test_main(argc, argv);
	return 0;
}
