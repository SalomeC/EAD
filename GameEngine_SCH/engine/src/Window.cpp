#include "Window.h"
#include "Logger.h"
#include <GLFW/glfw3.h>

namespace EngineNamespace {

    Window::Window(int width, int height, const std::string& title)
        : m_width(width), m_height(height), m_title(title), m_window(nullptr) {}

    Window::~Window() {
        if (m_window) {
            glfwDestroyWindow(static_cast<GLFWwindow*>(m_window));
        }
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
        } else {
            Logger::info("GLFW window created successfully");
        }
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