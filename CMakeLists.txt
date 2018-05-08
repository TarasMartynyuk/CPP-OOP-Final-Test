cmake_minimum_required(VERSION 3.5)
project(OOPFinalExam)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11 -std=gnu++11 -fext-numeric-literals")
message(${CMAKE_CXX_FLAGS})

set({CMAKE_BINARY_DIR} cmake-build-debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Download and unpack dateh at configure time
configure_file(CMakeLists.txt.in dateh-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/dateh-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/dateh-download" )

# Add dateh directly to our build.
add_subdirectory("${CMAKE_BINARY_DIR}/dateh-src" "${CMAKE_BINARY_DIR}/dateh-build")

file(GLOB_RECURSE store_src ./Store/*.h ./Store/*.cpp)
file(GLOB_RECURSE test_src ./Test/*.h ./Test/*.cpp)

add_executable(OOPFinalExam ${store_src} ${test_src} main.cpp)

# Include headers dir to enable intellisence
target_include_directories(OOPFinalExam PRIVATE . Store/Headers Store/Purchasing)
target_include_directories(OOPFinalExam PRIVATE . Test/Headers)
target_include_directories(OOPFinalExam PRIVATE "${CMAKE_BINARY_DIR}/dateh-src/include/date")

target_link_libraries(OOPFinalExam tz)