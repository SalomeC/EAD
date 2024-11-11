#include <iostream>
#include "Engine.h"

int main() {
    EngineNamespace::Engine engine;
    engine.Initialize();
    engine.Run();
    return 0;
}
