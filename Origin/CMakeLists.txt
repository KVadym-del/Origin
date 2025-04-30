file(GLOB src 
  "src/*.cpp"
)

find_package(fmt CONFIG REQUIRED)	
find_package(Boost REQUIRED COMPONENTS tokenizer)
find_package(Boost REQUIRED COMPONENTS spirit)

add_executable (Origin ${src})

if (CMAKE_VERSION VERSION_GREATER 3.25)
  set_property(TARGET Origin PROPERTY CXX_STANDARD 26)
endif()

target_link_libraries(Origin PRIVATE fmt::fmt)
target_link_libraries(Origin PRIVATE Boost::tokenizer)
target_link_libraries(Origin PRIVATE Boost::spirit)
