set(SMORMAT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_library(smormat INTERFACE)
target_include_directories(smormat INTERFACE
        $<BUILD_INTERFACE:${SMORMAT_INCLUDE_DIR}>)

file(GLOB_RECURSE SMORMAT_INCLUDES ${SMORMAT_INCLUDE_DIR}/*.h)

install(TARGETS smormat
        EXPORT smormat-lib
        INCLUDES DESTINATION ${CMAKE_INSTALL_PREFIX}/include/smormat
        ARCHIVES DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        LIBRARIES DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        CONFIGURATIONS Release)
install(EXPORT smormat-lib
        FILE smormat-config.cmake
        NAMESPACE smormat::
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake
        CONFIGURATIONS Release)
install(FILES
        ${SMORMAT_INCLUDES}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/smormat
        CONFIGURATIONS Release)