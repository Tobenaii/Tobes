#include "PhysicsTestApp.h"

int main() {
	
	// allocation
	auto app = new PhysicsTestApp();

	// initialise and loop
	app->run("AIE", 800, 800, false);
	app->setVSync(false);

	// deallocation
	delete app;

	return 0;
}