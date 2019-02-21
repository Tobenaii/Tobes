#include "PhysicsTestApp.h"

int main() {
	
	// allocation
	auto app = new PhysicsTestApp();

	// initialise and loop
	app->run("Tobes Physics Test", sWidth, sHeight, false);

	// deallocation
	delete app;

	return 0;
}