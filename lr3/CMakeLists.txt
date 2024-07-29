include_directories("include")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable (lr3 "src/Manager.cpp" "include/Manager.h" "src/main.cpp" "include/Office.h" "src/Office.cpp" "include/Jack.h" "src/Jack.cpp" "include/Service.h"   "src/Service.cpp" "include/PlayerTask.h" "src/PlayerTask.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lr3 PROPERTY CXX_STANDARD 20)
endif()
