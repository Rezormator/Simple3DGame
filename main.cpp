#include "Application/Application.h"

int main() {
    Application::crate();
    Application::run();
    Application::shut();
    return 0;
}
