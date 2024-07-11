include_directories("include")

add_executable (lr2   "src/main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lr2 PROPERTY CXX_STANDARD 20)
endif()
