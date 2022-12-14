project(CLOX)
cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(lox_internal STATIC 
    src/error.cpp
    src/scanner.cpp
    src/token.cpp
)


add_executable(lox src/main.cpp)
target_include_directories(lox
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(lox_internal 
    PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(lox
    PRIVATE 
       lox_internal
)




#############################################
# test
enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(example src/main.cpp)
target_link_libraries(example gtest_main lox_internal)
target_include_directories(example PRIVATE  ${PROJECT_SOURCE_DIR}/include)
add_test(NAME example_test COMMAND example)
