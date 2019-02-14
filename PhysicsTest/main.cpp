#include "PhysicsTestApp.h"

int main() {
	
	// allocation
	auto app = new PhysicsTestApp();

	// initialise and loop
	app->run("Tobes Physics Test", 800, 800, false);
	app->setVSync(false);

	// deallocation
	delete app;

	return 0;
}