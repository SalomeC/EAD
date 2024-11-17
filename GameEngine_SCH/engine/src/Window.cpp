#include "Window.h"
#include "Logger.h"
#include <GLFW/glfw3.h>

namespace EngineNamespace {

    //Static callback for GLFW key events:
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
        if(action == GLFW_PRESS){
            Window* userWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
            if(userWindow && userWindow->eventSystem){
                KeyPressEvent keyEvent(key);
                userWindow->eventSystem->dispatch(keyEvent);
            }
        }
    }

    //Static callback for GLFW window close event
    static void windowCloseCallback(GLFWwindow* window){
        Window* userWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
        if(userWindow && userWindow->eventSystem){
            WindowCloseEvent closeEvent;
            userWindow->eventSystem->dispatch(closeEvent);
        }
    }




    //Class member functions

    Window::Window(int width, int height, const std::string& title)
        : m_width(width), m_height(height), m_title(title), m_window(nullptr) {}

    Window::~Window() {
        if (m_window) {
            // Reset callbacks before destroying the window
            glfwSetKeyCallback(static_cast<GLFWwindow*>(m_window), nullptr);
            glfwSetWindowCloseCallback(static_cast<GLFWwindow*>(m_window), nullptr);

            glfwDestroyWindow(static_cast<GLFWwindow*>(m_window));
        }
        m_window = nullptr;
        glfwTerminate();
    }


    void Window::init() {
        initGLFW();
    }

    void Window::initGLFW() {
        if (!glfwInit()) {
            Logger::error("Failed to initialize GLFW");
            return;
        }

        m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
        if (!m_window) {
            Logger::error("Failed to create GLFW window");
            glfwTerminate();
            return;
        }

        Logger::info("GLFW window created successfully");

        glfwSetWindowUserPointer(static_cast<GLFWwindow*>(m_window), this);

        // Setting the GLFW callbacks
        glfwSetKeyCallback(static_cast<GLFWwindow*>(m_window), keyCallback);
        glfwSetWindowCloseCallback(static_cast<GLFWwindow*>(m_window), windowCloseCallback);
        
    }

    void Window::update() {
        if (m_window) {
            glfwPollEvents();
            glfwSwapBuffers(static_cast<GLFWwindow*>(m_window));
        }
    }

    bool Window::shouldClose() const {
        return m_window && glfwWindowShouldClose(static_cast<GLFWwindow*>(m_window));
    }

}