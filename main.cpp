#include "Application/Application.h"

int main() {
    Application::create("Simple 3D game");
    Application::run();
    Application::terminate();
    return 0;
}
