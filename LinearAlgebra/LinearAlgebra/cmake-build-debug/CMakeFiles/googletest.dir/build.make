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

# Utility rule file for googletest.

# Include the progress variables for this target.
include CMakeFiles/googletest.dir/progress.make

CMakeFiles/googletest: CMakeFiles/googletest-complete


CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-install
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-mkdir
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-download
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-patch
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-configure
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-build
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'googletest'"
	/cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E make_directory /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/CMakeFiles
	/cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E touch /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/CMakeFiles/googletest-complete
	/cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E touch /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-prefix/src/googletest-stamp/googletest-done

googletest-prefix/src/googletest-stamp/googletest-install: googletest-prefix/src/googletest-stamp/googletest-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing install step for 'googletest'"
	cd /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-build && $(MAKE) install
	cd /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-build && /cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E touch /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-prefix/src/googletest-stamp/googletest-install

googletest-prefix/src/googletest-stamp/googletest-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'googletest'"
	/cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E make_directory /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-src
	/cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E make_directory /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-build
	/cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E make_directory /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-prefix
	/cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E make_directory /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-prefix/tmp
	/cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E make_directory /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-prefix/src/googletest-stamp
	/cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E make_directory /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-prefix/src
	/cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E make_directory /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-prefix/src/googletest-stamp
	/cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E touch /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-prefix/src/googletest-stamp/googletest-mkdir

googletest-prefix/src/googletest-stamp/googletest-download: googletest-prefix/src/googletest-stamp/googletest-gitinfo.txt
googletest-prefix/src/googletest-stamp/googletest-download: googletest-prefix/src/googletest-stamp/googletest-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'googletest'"
	/cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -P /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-prefix/tmp/googletest-gitclone.cmake
	/cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E touch /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-prefix/src/googletest-stamp/googletest-download

googletest-prefix/src/googletest-stamp/googletest-patch: googletest-prefix/src/googletest-stamp/googletest-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No patch step for 'googletest'"
	/cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E echo_append
	/cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E touch /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-prefix/src/googletest-stamp/googletest-patch

googletest-prefix/src/googletest-stamp/googletest-configure: googletest-prefix/tmp/googletest-cfgcmd.txt
googletest-prefix/src/googletest-stamp/googletest-configure: googletest-prefix/src/googletest-stamp/googletest-skip-update
googletest-prefix/src/googletest-stamp/googletest-configure: googletest-prefix/src/googletest-stamp/googletest-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Performing configure step for 'googletest'"
	cd /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-build && /cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -DCMAKE_INSTALL_PREFIX=/cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/external -Dgtest_build_tests=OFF "-GCodeBlocks - Unix Makefiles" /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-src
	cd /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-build && /cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E touch /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-prefix/src/googletest-stamp/googletest-configure

googletest-prefix/src/googletest-stamp/googletest-build: googletest-prefix/src/googletest-stamp/googletest-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Performing build step for 'googletest'"
	cd /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-build && $(MAKE)
	cd /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-build && /cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E touch /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-prefix/src/googletest-stamp/googletest-build

googletest-prefix/src/googletest-stamp/googletest-skip-update: googletest-prefix/src/googletest-stamp/googletest-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Skipping update step for 'googletest'"
	cd /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/googletest-src && /cygdrive/c/Users/talth/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E echo_append

googletest: CMakeFiles/googletest
googletest: CMakeFiles/googletest-complete
googletest: googletest-prefix/src/googletest-stamp/googletest-install
googletest: googletest-prefix/src/googletest-stamp/googletest-mkdir
googletest: googletest-prefix/src/googletest-stamp/googletest-download
googletest: googletest-prefix/src/googletest-stamp/googletest-patch
googletest: googletest-prefix/src/googletest-stamp/googletest-configure
googletest: googletest-prefix/src/googletest-stamp/googletest-build
googletest: googletest-prefix/src/googletest-stamp/googletest-skip-update
googletest: CMakeFiles/googletest.dir/build.make

.PHONY : googletest

# Rule to build all files generated by this target.
CMakeFiles/googletest.dir/build: googletest

.PHONY : CMakeFiles/googletest.dir/build

CMakeFiles/googletest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/googletest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/googletest.dir/clean

CMakeFiles/googletest.dir/depend:
	cd /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug /cygdrive/c/Users/talth/Documents/GitHub/LinearAlgebra/LinearAlgebra/LinearAlgebra/cmake-build-debug/CMakeFiles/googletest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/googletest.dir/depend

