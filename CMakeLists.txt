cmake_minimum_required(VERSION 3.5)
project(OOPFinalExam)

set(CMAKE_CXX_STANDARD 11)

FILE(GLOB sources ./*.cpp ./*.h  ./*/*.cpp ./*/*.h  ./*/*/*.cpp ./*/*/*.h)

include_directories(. Store Store/DateTime)
include_directories(Test Test/Headers)
add_executable(OOPFinalExam ${sources})

