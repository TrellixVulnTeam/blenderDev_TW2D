# Generated by CMake 2.8.12.1

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget xml_static pcre_static ftoa_static buffer_static UTF_static MathMLSolver_static OpenCOLLADABaseUtils_static OpenCOLLADAFramework_static GeneratedSaxParser_static OpenCOLLADASaxFrameworkLoader_static OpenCOLLADAStreamWriter_static)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target xml_static
add_library(xml_static STATIC IMPORTED)

# Create imported target pcre_static
add_library(pcre_static STATIC IMPORTED)

# Create imported target ftoa_static
add_library(ftoa_static STATIC IMPORTED)

# Create imported target buffer_static
add_library(buffer_static STATIC IMPORTED)

# Create imported target UTF_static
add_library(UTF_static STATIC IMPORTED)

# Create imported target MathMLSolver_static
add_library(MathMLSolver_static STATIC IMPORTED)

# Create imported target OpenCOLLADABaseUtils_static
add_library(OpenCOLLADABaseUtils_static STATIC IMPORTED)

# Create imported target OpenCOLLADAFramework_static
add_library(OpenCOLLADAFramework_static STATIC IMPORTED)

# Create imported target GeneratedSaxParser_static
add_library(GeneratedSaxParser_static STATIC IMPORTED)

# Create imported target OpenCOLLADASaxFrameworkLoader_static
add_library(OpenCOLLADASaxFrameworkLoader_static STATIC IMPORTED)

# Create imported target OpenCOLLADAStreamWriter_static
add_library(OpenCOLLADAStreamWriter_static STATIC IMPORTED)

# Load information for each installed configuration.
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/OpenCOLLADATargets-*.cmake")
foreach(f ${CONFIG_FILES})
  include(${f})
endforeach()

# Loop over all imported files and verify that they actually exist
foreach(target ${_IMPORT_CHECK_TARGETS} )
  foreach(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    if(NOT EXISTS "${file}" )
      message(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_IMPORT_CHECK_FILES_FOR_${target})
endforeach()
unset(_IMPORT_CHECK_TARGETS)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
