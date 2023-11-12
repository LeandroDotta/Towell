file(GLOB source_files "*.cpp")
add_executable(Towell ${source_files})
target_link_libraries(Towell Engine)