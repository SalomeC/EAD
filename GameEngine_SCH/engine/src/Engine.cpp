#include "Engine.h"
#include "Logger.h"
#include <iostream>

namespace EngineNamespace {

    Engine::Engine() {
        Logger::init();
        Logger::info("Engine Constructor: Engine Initialized.");
    }

    Engine::~Engine() {
        Logger::info("Engine Destructor: Cleaning up Engine.");
    }

    void Engine::Initialize() {
 
        Logger::info("Engine Initialization Started.");
    }

    void Engine::Run() {
        Logger::info("Engine Running!");
    }

    void Engine::Start() {
        Logger::info("Engine Start: Starting the Engine.");
    }

    void Engine::Stop() {
        Logger::info("Engine Stop: Stopping the Engine.");
    }

} // namespace EngineNamespace