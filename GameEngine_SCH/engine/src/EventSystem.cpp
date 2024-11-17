#include "EventSystem.h"

namespace EngineNamespace {

    void EventSystem::subscribe(const std::string& eventType, EventCallback callback) {
        m_listeners[eventType].push_back(callback);
    }

    void EventSystem::dispatch(const Event& event) {
        auto& listeners = m_listeners[event.getType()];
        for (auto& listener : listeners) {
            listener(event);  // Call each subscribed listener
        }
    }

}
