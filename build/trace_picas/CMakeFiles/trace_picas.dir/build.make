# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/sauron/ros2-picas/ros2-picas-example/trace_picas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sauron/ros2-picas/build/trace_picas

# Include any dependencies generated for this target.
include CMakeFiles/trace_picas.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/trace_picas.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/trace_picas.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/trace_picas.dir/flags.make

CMakeFiles/trace_picas.dir/src/trace_function.cpp.o: CMakeFiles/trace_picas.dir/flags.make
CMakeFiles/trace_picas.dir/src/trace_function.cpp.o: /home/sauron/ros2-picas/ros2-picas-example/trace_picas/src/trace_function.cpp
CMakeFiles/trace_picas.dir/src/trace_function.cpp.o: CMakeFiles/trace_picas.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sauron/ros2-picas/build/trace_picas/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/trace_picas.dir/src/trace_function.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/trace_picas.dir/src/trace_function.cpp.o -MF CMakeFiles/trace_picas.dir/src/trace_function.cpp.o.d -o CMakeFiles/trace_picas.dir/src/trace_function.cpp.o -c /home/sauron/ros2-picas/ros2-picas-example/trace_picas/src/trace_function.cpp

CMakeFiles/trace_picas.dir/src/trace_function.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/trace_picas.dir/src/trace_function.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sauron/ros2-picas/ros2-picas-example/trace_picas/src/trace_function.cpp > CMakeFiles/trace_picas.dir/src/trace_function.cpp.i

CMakeFiles/trace_picas.dir/src/trace_function.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/trace_picas.dir/src/trace_function.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sauron/ros2-picas/ros2-picas-example/trace_picas/src/trace_function.cpp -o CMakeFiles/trace_picas.dir/src/trace_function.cpp.s

# Object files for target trace_picas
trace_picas_OBJECTS = \
"CMakeFiles/trace_picas.dir/src/trace_function.cpp.o"

# External object files for target trace_picas
trace_picas_EXTERNAL_OBJECTS =

libtrace_picas.a: CMakeFiles/trace_picas.dir/src/trace_function.cpp.o
libtrace_picas.a: CMakeFiles/trace_picas.dir/build.make
libtrace_picas.a: CMakeFiles/trace_picas.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sauron/ros2-picas/build/trace_picas/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libtrace_picas.a"
	$(CMAKE_COMMAND) -P CMakeFiles/trace_picas.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/trace_picas.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/trace_picas.dir/build: libtrace_picas.a
.PHONY : CMakeFiles/trace_picas.dir/build

CMakeFiles/trace_picas.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/trace_picas.dir/cmake_clean.cmake
.PHONY : CMakeFiles/trace_picas.dir/clean

CMakeFiles/trace_picas.dir/depend:
	cd /home/sauron/ros2-picas/build/trace_picas && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sauron/ros2-picas/ros2-picas-example/trace_picas /home/sauron/ros2-picas/ros2-picas-example/trace_picas /home/sauron/ros2-picas/build/trace_picas /home/sauron/ros2-picas/build/trace_picas /home/sauron/ros2-picas/build/trace_picas/CMakeFiles/trace_picas.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/trace_picas.dir/depend
