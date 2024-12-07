#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>

#define DEBUG_MODE 1

#if DEBUG_MODE
    #define DEBUG_PRINT(x) std::cout << x << std::endl;
#else
    #define DEBUG_PRINT(x)
#endif

#endif // UTIL_H_