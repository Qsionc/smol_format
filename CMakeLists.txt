cmake_minimum_required(VERSION 3.20)

include(cmake/linux-setup.cmake)
project(smolformat VERSION 0.1 LANGUAGES CXX)

include(cmake/smol-library.cmake)
include(cmake/unit-tests.cmake)