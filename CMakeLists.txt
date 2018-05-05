cmake_minimum_required(VERSION 3.5)
project(OOPFinalExam)

set(CMAKE_CXX_STANDARD 11)

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

# Include headers dir to enable intellisence
include_directories("${CMAKE_BINARY_DIR}/dateh-src/include/date")

FILE(GLOB sources ./*.cpp ./*.h  ./*/*.cpp ./*/*.h  ./*/*/*.cpp ./*/*/*.h)
include_directories(. Store Store/Date Store/Headers Store/Purchasing)
include_directories(Test Test/Headers)
add_executable(OOPFinalExam ${sources})

target_link_libraries(OOPFinalExam tz)