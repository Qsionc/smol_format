if (UNIT_TEST)
    set(SMORMAT_TEST_SOURCE ${CMAKE_SOURCE_DIR}/source)
    find_package(GTest REQUIRED)
    add_executable(smormat_test ${SMORMAT_TEST_SOURCE}/main-test.cpp)
    target_link_libraries(smormat_test PRIVATE
            GTest::GTest
            smormat)
endif ()