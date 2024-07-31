include_directories("include")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable (lr4 "src/main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lr4 PROPERTY CXX_STANDARD 20)
endif()
