# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/CookiieZ/Downloads/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/CookiieZ/Downloads/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/CookiieZ/Epitech/mandatory/my_sokoban/my_sokoban

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/CookiieZ/Epitech/mandatory/my_sokoban/my_sokoban/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/my_sokoban.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_sokoban.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_sokoban.dir/flags.make

CMakeFiles/my_sokoban.dir/main.c.o: CMakeFiles/my_sokoban.dir/flags.make
CMakeFiles/my_sokoban.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/CookiieZ/Epitech/mandatory/my_sokoban/my_sokoban/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/my_sokoban.dir/main.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_sokoban.dir/main.c.o   -c /home/CookiieZ/Epitech/mandatory/my_sokoban/my_sokoban/main.c

CMakeFiles/my_sokoban.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_sokoban.dir/main.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/CookiieZ/Epitech/mandatory/my_sokoban/my_sokoban/main.c > CMakeFiles/my_sokoban.dir/main.c.i

CMakeFiles/my_sokoban.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_sokoban.dir/main.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/CookiieZ/Epitech/mandatory/my_sokoban/my_sokoban/main.c -o CMakeFiles/my_sokoban.dir/main.c.s

# Object files for target my_sokoban
my_sokoban_OBJECTS = \
"CMakeFiles/my_sokoban.dir/main.c.o"

# External object files for target my_sokoban
my_sokoban_EXTERNAL_OBJECTS =

my_sokoban: CMakeFiles/my_sokoban.dir/main.c.o
my_sokoban: CMakeFiles/my_sokoban.dir/build.make
my_sokoban: CMakeFiles/my_sokoban.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/CookiieZ/Epitech/mandatory/my_sokoban/my_sokoban/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable my_sokoban"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_sokoban.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_sokoban.dir/build: my_sokoban

.PHONY : CMakeFiles/my_sokoban.dir/build

CMakeFiles/my_sokoban.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_sokoban.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_sokoban.dir/clean

CMakeFiles/my_sokoban.dir/depend:
	cd /home/CookiieZ/Epitech/mandatory/my_sokoban/my_sokoban/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/CookiieZ/Epitech/mandatory/my_sokoban/my_sokoban /home/CookiieZ/Epitech/mandatory/my_sokoban/my_sokoban /home/CookiieZ/Epitech/mandatory/my_sokoban/my_sokoban/cmake-build-debug /home/CookiieZ/Epitech/mandatory/my_sokoban/my_sokoban/cmake-build-debug /home/CookiieZ/Epitech/mandatory/my_sokoban/my_sokoban/cmake-build-debug/CMakeFiles/my_sokoban.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_sokoban.dir/depend

