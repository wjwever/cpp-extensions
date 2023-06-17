#include "classB.h"

namespace easr {
    void strops::lower(std::string& str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    }
} // namespace naclass_simple
