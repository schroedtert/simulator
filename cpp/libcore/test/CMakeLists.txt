add_executable(test-core
    test_simulation.cpp
    test_dependency_availability.cpp

    util/test_identifiable.cpp

    geometry/test_length_unit.cpp

    math/test_int_pow.cpp
)

target_link_libraries(test-core
    PRIVATE
        core
        fmt::fmt
        GTest::gtest_main
        GTest::gtest
        GTest::gmock
)

gtest_discover_tests(test-core)


target_compile_options(test-core PRIVATE
    -fPIC
)

add_executable(length_unit_assert_fail geometry/test_length_unit_assert_fail.cpp)
target_link_libraries(length_unit_assert_fail
        PRIVATE
        core
        fmt::fmt
        GTest::gtest_main
        GTest::gtest
        GTest::gmock
        )
set_target_properties(length_unit_assert_fail PROPERTIES
        EXCLUDE_FROM_ALL TRUE
        EXCLUDE_FROM_DEFAULT_BUILD TRUE)

add_test(NAME test_length_unit_assert_fail COMMAND ${CMAKE_COMMAND} --build . --target length_unit_assert_fail --config $<CONFIGURATION>
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
set_tests_properties(test_length_unit_assert_fail PROPERTIES WILL_FAIL TRUE)
