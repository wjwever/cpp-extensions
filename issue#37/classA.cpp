#include "classA.h"

namespace easr {
namespace nnlm {
    void strops::lower(std::string& str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    }
}
} // namespace naclass_simple
