# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LinearAlgebra_tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LinearAlgebra_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LinearAlgebra_tests.dir/flags.make

CMakeFiles/LinearAlgebra_tests.dir/Tests/LLL_Tests.cpp.o: CMakeFiles/LinearAlgebra_tests.dir/flags.make
CMakeFiles/LinearAlgebra_tests.dir/Tests/LLL_Tests.cpp.o: ../Tests/LLL_Tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LinearAlgebra_tests.dir/Tests/LLL_Tests.cpp.o"
	C:/cygwin64/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LinearAlgebra_tests.dir/Tests/LLL_Tests.cpp.o -c /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/Tests/LLL_Tests.cpp

CMakeFiles/LinearAlgebra_tests.dir/Tests/LLL_Tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LinearAlgebra_tests.dir/Tests/LLL_Tests.cpp.i"
	C:/cygwin64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/Tests/LLL_Tests.cpp > CMakeFiles/LinearAlgebra_tests.dir/Tests/LLL_Tests.cpp.i

CMakeFiles/LinearAlgebra_tests.dir/Tests/LLL_Tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LinearAlgebra_tests.dir/Tests/LLL_Tests.cpp.s"
	C:/cygwin64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/Tests/LLL_Tests.cpp -o CMakeFiles/LinearAlgebra_tests.dir/Tests/LLL_Tests.cpp.s

# Object files for target LinearAlgebra_tests
LinearAlgebra_tests_OBJECTS = \
"CMakeFiles/LinearAlgebra_tests.dir/Tests/LLL_Tests.cpp.o"

# External object files for target LinearAlgebra_tests
LinearAlgebra_tests_EXTERNAL_OBJECTS =

LinearAlgebra_tests.exe: CMakeFiles/LinearAlgebra_tests.dir/Tests/LLL_Tests.cpp.o
LinearAlgebra_tests.exe: CMakeFiles/LinearAlgebra_tests.dir/build.make
LinearAlgebra_tests.exe: libLinearAlgebra.dll.a
LinearAlgebra_tests.exe: CMakeFiles/LinearAlgebra_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LinearAlgebra_tests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LinearAlgebra_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LinearAlgebra_tests.dir/build: LinearAlgebra_tests.exe

.PHONY : CMakeFiles/LinearAlgebra_tests.dir/build

CMakeFiles/LinearAlgebra_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LinearAlgebra_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LinearAlgebra_tests.dir/clean

CMakeFiles/LinearAlgebra_tests.dir/depend:
	cd /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/CMakeFiles/LinearAlgebra_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LinearAlgebra_tests.dir/depend

