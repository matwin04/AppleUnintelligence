# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/mwiner/Projects/SerialD

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mwiner/Projects/SerialD/build

# Include any dependencies generated for this target.
include CMakeFiles/denon_avr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/denon_avr.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/denon_avr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/denon_avr.dir/flags.make

CMakeFiles/denon_avr.dir/main.cpp.o: CMakeFiles/denon_avr.dir/flags.make
CMakeFiles/denon_avr.dir/main.cpp.o: /home/mwiner/Projects/SerialD/main.cpp
CMakeFiles/denon_avr.dir/main.cpp.o: CMakeFiles/denon_avr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mwiner/Projects/SerialD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/denon_avr.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/denon_avr.dir/main.cpp.o -MF CMakeFiles/denon_avr.dir/main.cpp.o.d -o CMakeFiles/denon_avr.dir/main.cpp.o -c /home/mwiner/Projects/SerialD/main.cpp

CMakeFiles/denon_avr.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/denon_avr.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mwiner/Projects/SerialD/main.cpp > CMakeFiles/denon_avr.dir/main.cpp.i

CMakeFiles/denon_avr.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/denon_avr.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mwiner/Projects/SerialD/main.cpp -o CMakeFiles/denon_avr.dir/main.cpp.s

CMakeFiles/denon_avr.dir/avr.cpp.o: CMakeFiles/denon_avr.dir/flags.make
CMakeFiles/denon_avr.dir/avr.cpp.o: /home/mwiner/Projects/SerialD/avr.cpp
CMakeFiles/denon_avr.dir/avr.cpp.o: CMakeFiles/denon_avr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mwiner/Projects/SerialD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/denon_avr.dir/avr.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/denon_avr.dir/avr.cpp.o -MF CMakeFiles/denon_avr.dir/avr.cpp.o.d -o CMakeFiles/denon_avr.dir/avr.cpp.o -c /home/mwiner/Projects/SerialD/avr.cpp

CMakeFiles/denon_avr.dir/avr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/denon_avr.dir/avr.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mwiner/Projects/SerialD/avr.cpp > CMakeFiles/denon_avr.dir/avr.cpp.i

CMakeFiles/denon_avr.dir/avr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/denon_avr.dir/avr.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mwiner/Projects/SerialD/avr.cpp -o CMakeFiles/denon_avr.dir/avr.cpp.s

# Object files for target denon_avr
denon_avr_OBJECTS = \
"CMakeFiles/denon_avr.dir/main.cpp.o" \
"CMakeFiles/denon_avr.dir/avr.cpp.o"

# External object files for target denon_avr
denon_avr_EXTERNAL_OBJECTS =

denon_avr: CMakeFiles/denon_avr.dir/main.cpp.o
denon_avr: CMakeFiles/denon_avr.dir/avr.cpp.o
denon_avr: CMakeFiles/denon_avr.dir/build.make
denon_avr: CMakeFiles/denon_avr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/mwiner/Projects/SerialD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable denon_avr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/denon_avr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/denon_avr.dir/build: denon_avr
.PHONY : CMakeFiles/denon_avr.dir/build

CMakeFiles/denon_avr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/denon_avr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/denon_avr.dir/clean

CMakeFiles/denon_avr.dir/depend:
	cd /home/mwiner/Projects/SerialD/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mwiner/Projects/SerialD /home/mwiner/Projects/SerialD /home/mwiner/Projects/SerialD/build /home/mwiner/Projects/SerialD/build /home/mwiner/Projects/SerialD/build/CMakeFiles/denon_avr.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/denon_avr.dir/depend

