# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/opt/esp/esp-idf/components/bootloader/subproject"
  "/opt/esp/esp-rainmaker/examples/switch/build/bootloader"
  "/opt/esp/esp-rainmaker/examples/switch/build/bootloader-prefix"
  "/opt/esp/esp-rainmaker/examples/switch/build/bootloader-prefix/tmp"
  "/opt/esp/esp-rainmaker/examples/switch/build/bootloader-prefix/src/bootloader-stamp"
  "/opt/esp/esp-rainmaker/examples/switch/build/bootloader-prefix/src"
  "/opt/esp/esp-rainmaker/examples/switch/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/opt/esp/esp-rainmaker/examples/switch/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/opt/esp/esp-rainmaker/examples/switch/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
