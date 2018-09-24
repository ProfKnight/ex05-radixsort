#include <iostream>

#include "radixsort.h"

int main() {
    uint64_t values[] = {101, 208, 109, 307, 406, 505, 604, 703, 802, 901};
    edu::vcccd::vc::csv15::radixsort(values, 10);
    std::cout << "{ ";
    for (uint64_t value: values) {
        std::cout << value << " ";
    }
    std::cout << "}" << std::endl;
    return 0;
}