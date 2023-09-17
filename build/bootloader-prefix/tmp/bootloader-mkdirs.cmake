# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/opt/esp/esp-idf/components/bootloader/subproject"
  "/Users/michel/Documents/esp/switch/build/bootloader"
  "/Users/michel/Documents/esp/switch/build/bootloader-prefix"
  "/Users/michel/Documents/esp/switch/build/bootloader-prefix/tmp"
  "/Users/michel/Documents/esp/switch/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/michel/Documents/esp/switch/build/bootloader-prefix/src"
  "/Users/michel/Documents/esp/switch/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/michel/Documents/esp/switch/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/michel/Documents/esp/switch/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
