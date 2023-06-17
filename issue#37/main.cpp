#include "classA.h"
#include "classB.h"
#include "iostream"

int main() {
    std::string temp = "HELLO";
    easr::nnlm::strops::lower(temp);  
    easr::strops::lower(temp);  
    return 0;
}
