#include "Engine.h"
#include "Logger.h"
#include <iostream>

namespace EngineNamespace {

    Engine::Engine() : m_window(800, 600, "Engine Window"),
        m_eventSystem(std::make_unique<EventSystem>()) {
        Logger::init();
        Logger::info("Engine Constructor: Engine Initialized.");
    }

    Engine::~Engine() {
        Logger::info("Engine Destructor: Cleaning up Engine.");
        m_window.~Window();
        m_eventSystem.reset();
    }

    void Engine::Initialize() {
        m_window.eventSystem = m_eventSystem.get();

        //Subscribing to Events
        m_window.eventSystem->subscribe("WindowCloseEvent", [](const Event& event){
            Logger::info("Window Close Event received");
        });
        m_window.eventSystem->subscribe("KeyPressEvent", [](const Event& event){
            const auto& keyEvent = static_cast<const KeyPressEvent&>(event);
            Logger::info("Key Pressed: " + std::to_string(keyEvent.getKeyCode()));
        });

        m_window.init();
        Logger::info("Engine Initialization Started.");
        
    }

    void Engine::Run() {
        int logFreq = 100;
        int cnt = 0;
        while (! m_window.shouldClose()){
            m_window.update();
            if(cnt % logFreq == 0){
                Logger::info("Engine Running!");
            }
            cnt++;
        }
    }

    void Engine::Start() {
        Logger::info("Engine Start: Starting the Engine.");
    }

    void Engine::Stop() {
        Logger::info("Engine Stop: Stopping the Engine.");
    }


} // namespace EngineNamespace