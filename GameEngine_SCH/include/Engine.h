#ifndef MYENGINE_H
#define MYENGINE_H

// Define MYENGINE_API based on the platform
#ifdef __linux__
   #define MYENGINE_API __attribute__((visibility("default")))
#elif defined(_WIN32)
   #ifdef ENGINE_EXPORTS
      #define MYENGINE_API __declspec(dllexport)
   #else
      #define MYENGINE_API __declspec(dllimport)
   #endif
#else
   #define MYENGINE_API
#endif

namespace EngineNamespace {
    class MYENGINE_API Engine {
    public:
        Engine();
        ~Engine();

        void Initialize();
        void Run();
        void Start();  // Kept from the previous code
        void Stop();   // Kept from the previous code
    };
}

#endif // MYENGINE_H

