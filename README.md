# smol::format

Small library allowing for safe-type formatting of strings

# Table of contents

1. [Motivation](#motivation)
2. [Description](#description)
3. [Example usage](#example-usage)
4. [Conclusion](#conclusion)

# Motivation

Personal practice of CMake and C++ project creation, as well as practice of template programming.<br>
I decided to create this library to help to develop my personal skills. 

Any additional insight and criticism is appreciated!

# Description

smol::format is simple formatting library allowing for string formatting similar to sprintf C function,
but is type safe, meaning it does not matter what type additional arguments are.
All there is needed is proper format string and input arguments list.

Library currently does not support additional information regarding, for example, decimal numbers. It puts data raw into strings.

# Example usage

```c++
#include <iostream>
#include "format.h"

int main() {
    std::cout << smol::format("{1} {0} {} {}", 42, "string", 3.14) << std::endl; // Outputs to stdout string: "string 42 3.140000 "
    std::string result = smol::format("{a}, b{}, {4}, {5}", 42, "string", 3.14); // result: "42, bstring, 3.140000, "
    return 0;
}
```

# Conclusion

This library is simple personal attempt to create viable string formatting.

Future work: adding support for additional format information, like precision, to upper or to lower string format, etc.