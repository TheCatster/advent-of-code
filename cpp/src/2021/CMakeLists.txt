add_executable(day1 day1.cpp ${HEADER_FILES})
target_include_directories(day1 PRIVATE ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(day1 advent-of-code)

add_executable(day2 day2.cpp ${HEADER_FILES})
target_include_directories(day2 PRIVATE ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(day2 advent-of-code)

add_executable(day3 day3.cpp ${HEADER_FILES})
target_include_directories(day3 PRIVATE ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(day3 advent-of-code)

add_executable(day4 day4.cpp ${HEADER_FILES})
target_include_directories(day4 PRIVATE ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(day4 advent-of-code)