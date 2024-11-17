#ifndef ENGINE_EVENT_H
#define ENGINE_EVENT_H

#include <string>

namespace EngineNamespace {

    // Base class for all events
    class Event {
    public:
        virtual ~Event() = default;
        virtual std::string getType() const = 0;  // Event type identifier
    };

    // Window Close Event
    class WindowCloseEvent : public Event {
    public:
        std::string getType() const override { return "WindowCloseEvent"; }
    };

    // Key Press Event
    class KeyPressEvent : public Event {
    public:
        KeyPressEvent(int keyCode) : m_keyCode(keyCode) {}

        std::string getType() const override { return "KeyPressEvent"; }
        int getKeyCode() const { return m_keyCode; }

    private:
        int m_keyCode;  // The key that was pressed
    };

}

#endif // ENGINE_EVENT_H
