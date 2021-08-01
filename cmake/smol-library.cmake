set(SMORMAT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_library(smormat INTERFACE)
target_include_directories(smormat INTERFACE
        $<BUILD_INTERFACE:${SMORMAT_INCLUDE_DIR}>)

install(TARGETS smormat
        EXPORT smormat-lib
        INCLUDES DESTINATION ${CMAKE_INSTALL_PREFIX}/include/smormat
        ARCHIVES DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        LIBRARIES DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        CONFIGURATIONS Release)
install(EXPORT smormat-lib
        FILE smormat-config.cmake
        NAMESPACE smormat::
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/smormat/cmake
        CONFIGURATIONS Release)
install(FILES
        ${CMAKE_SOURCE_DIR}/include/detail/format_settings.h
        ${CMAKE_SOURCE_DIR}/include/detail/to_string.h
        ${CMAKE_SOURCE_DIR}/include/detail/formatting.h
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/smormat/detail
        CONFIGURATIONS Release)
install(FILES
        ${CMAKE_SOURCE_DIR}/include/implementation/any_type_const_implementation.h
        ${CMAKE_SOURCE_DIR}/include/implementation/format_class_implementation.h
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/smormat/implementation
        CONFIGURATIONS Release)
install(FILES
        ${CMAKE_SOURCE_DIR}/include/any_type_const.h
        ${CMAKE_SOURCE_DIR}/include/format.h
        ${CMAKE_SOURCE_DIR}/include/format_class.h
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/smormat
        CONFIGURATIONS Release)
