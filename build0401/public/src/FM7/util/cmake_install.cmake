# Install script for directory: /Users/jingzhao/24783_project/rothberg-run/src/public/src/FM7/util

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/jingzhao/24783_project/rothberg-run/build0401/public/src/FM7/util/lib/cmake_install.cmake")
  include("/Users/jingzhao/24783_project/rothberg-run/build0401/public/src/FM7/util/d77/cmake_install.cmake")
  include("/Users/jingzhao/24783_project/rothberg-run/build0401/public/src/FM7/util/t77/cmake_install.cmake")
  include("/Users/jingzhao/24783_project/rothberg-run/build0401/public/src/FM7/util/disk2tape/cmake_install.cmake")
  include("/Users/jingzhao/24783_project/rothberg-run/build0401/public/src/FM7/util/rawReadToD77/cmake_install.cmake")
  include("/Users/jingzhao/24783_project/rothberg-run/build0401/public/src/FM7/util/rs232cTfr/cmake_install.cmake")
  include("/Users/jingzhao/24783_project/rothberg-run/build0401/public/src/FM7/util/misc/machinGoToBASIC/cmake_install.cmake")
  include("/Users/jingzhao/24783_project/rothberg-run/build0401/public/src/FM7/util/misc/srecdump/cmake_install.cmake")
  include("/Users/jingzhao/24783_project/rothberg-run/build0401/public/src/FM7/util/77AVTyper/cmake_install.cmake")
  include("/Users/jingzhao/24783_project/rothberg-run/build0401/public/src/FM7/util/D77ToRS232C/cmake_install.cmake")
  include("/Users/jingzhao/24783_project/rothberg-run/build0401/public/src/FM7/util/T77ToRS232C/cmake_install.cmake")

endif()

