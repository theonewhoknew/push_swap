# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild

# Utility rule file for imgui-populate.

# Include the progress variables for this target.
include CMakeFiles/imgui-populate.dir/progress.make

CMakeFiles/imgui-populate: CMakeFiles/imgui-populate-complete


CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-install
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-mkdir
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-download
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-update
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-patch
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-configure
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-build
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-install
CMakeFiles/imgui-populate-complete: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'imgui-populate'"
	/usr/bin/cmake -E make_directory /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles
	/usr/bin/cmake -E touch /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles/imgui-populate-complete
	/usr/bin/cmake -E touch /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-done

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-install: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No install step for 'imgui-populate'"
	cd /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-build && /usr/bin/cmake -E echo_append
	cd /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-build && /usr/bin/cmake -E touch /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-install

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'imgui-populate'"
	/usr/bin/cmake -E make_directory /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-src
	/usr/bin/cmake -E make_directory /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-build
	/usr/bin/cmake -E make_directory /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix
	/usr/bin/cmake -E make_directory /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/tmp
	/usr/bin/cmake -E make_directory /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp
	/usr/bin/cmake -E make_directory /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src
	/usr/bin/cmake -E make_directory /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp
	/usr/bin/cmake -E touch /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-mkdir

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-download: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-gitinfo.txt
imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-download: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'imgui-populate'"
	cd /home/diego/repos/push_swap/push_swap_visualizer/build/_deps && /usr/bin/cmake -P /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/tmp/imgui-populate-gitclone.cmake
	cd /home/diego/repos/push_swap/push_swap_visualizer/build/_deps && /usr/bin/cmake -E touch /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-download

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-update: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Performing update step for 'imgui-populate'"
	cd /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-src && /usr/bin/cmake -P /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/tmp/imgui-populate-gitupdate.cmake

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-patch: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'imgui-populate'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-patch

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-configure: imgui-populate-prefix/tmp/imgui-populate-cfgcmd.txt
imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-configure: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No configure step for 'imgui-populate'"
	cd /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-build && /usr/bin/cmake -E echo_append
	cd /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-build && /usr/bin/cmake -E touch /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-configure

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-build: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No build step for 'imgui-populate'"
	cd /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-build && /usr/bin/cmake -E echo_append
	cd /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-build && /usr/bin/cmake -E touch /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-build

imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-test: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No test step for 'imgui-populate'"
	cd /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-build && /usr/bin/cmake -E echo_append
	cd /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-build && /usr/bin/cmake -E touch /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-test

imgui-populate: CMakeFiles/imgui-populate
imgui-populate: CMakeFiles/imgui-populate-complete
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-install
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-mkdir
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-download
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-update
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-patch
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-configure
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-build
imgui-populate: imgui-populate-prefix/src/imgui-populate-stamp/imgui-populate-test
imgui-populate: CMakeFiles/imgui-populate.dir/build.make

.PHONY : imgui-populate

# Rule to build all files generated by this target.
CMakeFiles/imgui-populate.dir/build: imgui-populate

.PHONY : CMakeFiles/imgui-populate.dir/build

CMakeFiles/imgui-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/imgui-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/imgui-populate.dir/clean

CMakeFiles/imgui-populate.dir/depend:
	cd /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild /home/diego/repos/push_swap/push_swap_visualizer/build/_deps/imgui-subbuild/CMakeFiles/imgui-populate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/imgui-populate.dir/depend

