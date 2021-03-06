set(python_tests
    import_test.py
    example_test.py
    logging_test.py
    geometry/area_test.py
    geometry/coordinate_test.py
    geometry/level_test.py
    geometry/line_segment_test.py
    geometry/spatial_vector_test.py
    geometry/special_area_test.py
    geometry/length_unit_test.py
)

foreach(test ${python_tests})
    add_test(
        NAME ${test}
        COMMAND ${Python_EXECUTABLE} -B -m pytest -p no:cacheprovider
            ${CMAKE_CURRENT_SOURCE_DIR}/${test}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )

    set_tests_properties(${test} PROPERTIES
        ENVIRONMENT PYTHONPATH=${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/$<$<BOOL:${WIN32}>:$<CONFIG>>
    )
endforeach()
