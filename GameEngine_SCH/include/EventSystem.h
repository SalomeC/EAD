#ifndef ENGINE_EVENTSYSTEM_H
#define ENGINE_EVENTSYSTEM_H

#include "Event.h"
#include <functional>
#include <unordered_map>
#include <vector>
#include <string>

namespace EngineNamespace {

    class EventSystem {
    public:
        using EventCallback = std::function<void(const Event&)>;

        // Subscribe to an event type
        void subscribe(const std::string& eventType, EventCallback callback);

        // Dispatch an event to all subscribers
        void dispatch(const Event& event);

    private:
        std::unordered_map<std::string, std::vector<EventCallback>> m_listeners;
    };

}

#endif // ENGINE_EVENTSYSTEM_H
