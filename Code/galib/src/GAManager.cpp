#include "../includes/GAManager.h"

using namespace galib;

GAManager* GAManager::instance = nullptr;


void GAManager::SetWorld(GAWorldBase* world) {
	targetWorld = world;
}

void GAManager::Run() {
	targetWorld->Run();
}