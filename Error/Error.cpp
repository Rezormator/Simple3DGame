#include "Error.h"
#include <iostream>
#include "../Application/Application.h"

void Error::massage(const char *target, const char *dsicripton) {
    std::cerr << "ERROR::" << target << "::" << dsicripton << std::endl;
    Application::shut();
}
