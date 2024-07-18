include_directories("include")

add_executable (lr3)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lr3 PROPERTY CXX_STANDARD 20)
endif()
