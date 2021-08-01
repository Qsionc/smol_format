# smol::format

Small header library allowing for type-safe formatting of strings in C-style manner, like `sprintf(...)`

# Table of contents

1. [Motivation](#motivation)
2. [Description](#description)
3. [Installation](#installation)
4. [Example usage](#example-usage)
5. [Conclusion](#conclusion)

## Motivation

Personal practice of CMake and C++ project creation, as well as practice of template programming.<br>
I decided to create this library to help to develop my personal skills.

Library itself, together with my SingletonWrapper is part of project to create small OpenGL Engine.<br>
smol::format is part of engine logger library, which will come SOON™.

Any additional insight and criticism is appreciated!

## Description

smol::format is simple formatting library allowing for string formatting similar to sprintf C function, but is type
safe, meaning it does not matter what type additional arguments are. All there is needed is proper format string and
input arguments list.

Library currently does not support additional information regarding, for example, floating point precision. It puts data
raw into strings.

## Installation

Download zip or clone repository to chosen folder. There, create build folder and call `cmake` from there.

```shell
git clone "url/to/repository"
mkdir build
cd build
```

I recommend using custom CMAKE_INSTALL_PREFIX, for example /home/user-name/.local:

```shell
cmake .. -DCMAKE_INSTALL_PREFIX:STRING="${HOME}/.local"
cmake --build . --target install
```

This way all header files will be placed in `/home/user-name/.local/include/smormat` folder and additional sub-folders,
and `smormat-config.cmake` file will be placed in `${CMAKE_INSTALL_PREFIX}/lib/smormat/cmake` folder.<br>
This will make system files safer and allow for easy removal of said library.

You can change relative destination or provide full path by editing `install(EXPORT...)` target
in `cmake/smol-library.cmake` file

Unit tests are implemented by simple googletest fixture in `source/main.cpp` file.

## Example usage

To use in your `CMakeLists.txt` use `find package(...)` to find `smormat` library and link it to chosen targets, for example:
```cmake
find_package(smormat REQUIRED)
...
add_executable(some_exec some_source.cpp)
target_link_libraries(some_exec PRIVATE smormat::smormat)
```

Then, include `format.h` file in your chosen files. 
```c++
#include <format.h>
```

This example program demonstrated usage of `smol::format` class. It has overridden `std::ostream& operator<<(...)`<br>
and is implicitly convertible to `std::string`.

It is best to use smol::format objects as temporary objects in expressions, although you can store it for later.<br>
Implicit conversion to std::string is only viable for expressions that require std::string. Explicit conversion can be
omitted, by using `smol::format::get() const` member method that returns `std::string const&`.


Working example:
```c++
_[#include <iostream>
#include <format.h>

int main() {
    std::cout << smol::format("{1} {0} {} {}", 42, "string", 3.14) << std::endl; // Outputs to stdout string: "string 42 3.140000 "
    std::string result = smol::format("{a}, b{}, {4}, {5}", 42, "string", 3.14); // result: "42, bstring, 3.140000, "
    return 0;
}
```

# Conclusion

This library is simple personal attempt to create viable string formatting. It does not by any means claim to be best
practice, <Br>
so any criticism and comments are appreciated.

Future work:<br>
1. Adding support for additional format information, like precision, to upper or to lower string format, etc.