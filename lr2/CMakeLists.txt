include_directories("include")

add_executable (lr2     "include/Environment.h"   "include/Agent.h" "src/Agent.cpp" "src/Environment.cpp" "include/Manager.h" "src/Manager.cpp" "src/main.cpp" "include/MagicCell.h" "src/MagicCell.cpp" "include/Cell.h" "src/Cell.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lr2 PROPERTY CXX_STANDARD 20)
endif()
