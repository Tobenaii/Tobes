#pragma once
#include <enet/enet.h>
#include "Tobes/Core.h"

class NetHost
{
public:
	TOBES_API NetHost();
	void StartHost(const char* merp);
};
