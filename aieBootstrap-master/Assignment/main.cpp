#include "AssignmentApp.h"

int main() {
	// allocation
	auto app = new AssignmentApp();
	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}