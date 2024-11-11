#include "Engine.h"
#include <iostream>

namespace EngineNamespace {

    Engine::Engine() {
        std::cout << "Engine Constructor: Engine Initialized." << std::endl;
    }

    Engine::~Engine() {
        std::cout << "Engine Destructor: Cleaning up Engine." << std::endl;
    }

    void Engine::Initialize() {
        std::cout << "Engine Initialization Started." << std::endl;
    }

    void Engine::Run() {
        std::cout << "Engine Running!" << std::endl;
    }

    void Engine::Start() {
        std::cout << "Engine Start: Starting the Engine." << std::endl;
    }

    void Engine::Stop() {
        std::cout << "Engine Stop: Stopping the Engine." << std::endl;
    }

} // namespace EngineNamespace