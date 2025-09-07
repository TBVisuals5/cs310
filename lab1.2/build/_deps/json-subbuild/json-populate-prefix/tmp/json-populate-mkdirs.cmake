# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/workspaces/cs310/lab1.2/build/_deps/json-src"
  "/workspaces/cs310/lab1.2/build/_deps/json-build"
  "/workspaces/cs310/lab1.2/build/_deps/json-subbuild/json-populate-prefix"
  "/workspaces/cs310/lab1.2/build/_deps/json-subbuild/json-populate-prefix/tmp"
  "/workspaces/cs310/lab1.2/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
  "/workspaces/cs310/lab1.2/build/_deps/json-subbuild/json-populate-prefix/src"
  "/workspaces/cs310/lab1.2/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/workspaces/cs310/lab1.2/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/workspaces/cs310/lab1.2/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
