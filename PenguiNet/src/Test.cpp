#include "Test.h"
#include <enet/enet.h>

void TestEnet::Init()
{
	enet_initialize();
	std::cout << "ENet Initialized" << std::endl;
}
