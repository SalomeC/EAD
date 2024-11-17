#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

#include "EventSystem.h"
#include <string>

namespace EngineNamespace{

    class Window {
        public:
            Window(int width, int height, const std::string& title);
            ~Window();

            void init();
            void update();
            bool shouldClose() const; 

            EventSystem* eventSystem;

        private:
            int m_width;
            int m_height;
            std::string m_title;
            void* m_window; //Placeholder for GLFWindow pointer

            void initGLFW(); //Internal GLFW initialisation

    };
}

#endif // ENGINE_WINDOW_H