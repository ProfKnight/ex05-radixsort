//
// Created by aknight on 9/22/18.
//

#ifndef RADIXSORT_RADIXSORT_H
#define RADIXSORT_RADIXSORT_H

#include <cstdlib>
#include <memory>

namespace edu { namespace vcccd { namespace vc { namespace csv15 {
    template<typename T>
    void radixsort(T array[], size_t size, size_t radix=10) {
        if (array == nullptr) return;
        T bins[radix][size];
        size_t sizes[radix];
        bool done = true;
        for (size_t curr = 1; done; curr *= radix) {
            std::uninitialized_fill(sizes, sizes+radix, 0);
            done = false;
            for (size_t i = 0; i < size; i++) {
                T &val = array[i];
                size_t bin = (val / curr) % radix;
                bins[bin][sizes[bin]++] = val;
                done = done || ((int)radix >= (int)(radix * curr - val));
            }

            if (sizes[0] == size) continue;

            T *h = array;
            for (size_t i = 0; i < radix; i++) {
                for (size_t j = 0; j < sizes[i]; j++) *h++ = bins[i][j];
            }
        }
    }
}}}}
#endif //RADIXSORT_RADIXSORT_H
