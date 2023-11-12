cmake_minimum_required (VERSION 3.8)

set (project_engine "Engine")
set (project_editor "Editor")
set (source_dir "${CMAKE_SOURCE_DIR}/src")

# Habilite a Recarga Dinâmica para compiladores MSVC, se houver suporte.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (Towell)

add_subdirectory("${source_dir}/${project_engine}")
add_subdirectory("${source_dir}/${project_editor}")