# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /opt/clion-2017.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning

# Include any dependencies generated for this target.
include CMakeFiles/losning.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/losning.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/losning.dir/flags.make

CMakeFiles/losning.dir/main.c.o: CMakeFiles/losning.dir/flags.make
CMakeFiles/losning.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/losning.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/losning.dir/main.c.o   -c /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/main.c

CMakeFiles/losning.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/losning.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/main.c > CMakeFiles/losning.dir/main.c.i

CMakeFiles/losning.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/losning.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/main.c -o CMakeFiles/losning.dir/main.c.s

CMakeFiles/losning.dir/main.c.o.requires:

.PHONY : CMakeFiles/losning.dir/main.c.o.requires

CMakeFiles/losning.dir/main.c.o.provides: CMakeFiles/losning.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/losning.dir/build.make CMakeFiles/losning.dir/main.c.o.provides.build
.PHONY : CMakeFiles/losning.dir/main.c.o.provides

CMakeFiles/losning.dir/main.c.o.provides.build: CMakeFiles/losning.dir/main.c.o


CMakeFiles/losning.dir/ValidateInput.c.o: CMakeFiles/losning.dir/flags.make
CMakeFiles/losning.dir/ValidateInput.c.o: ValidateInput.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/losning.dir/ValidateInput.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/losning.dir/ValidateInput.c.o   -c /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/ValidateInput.c

CMakeFiles/losning.dir/ValidateInput.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/losning.dir/ValidateInput.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/ValidateInput.c > CMakeFiles/losning.dir/ValidateInput.c.i

CMakeFiles/losning.dir/ValidateInput.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/losning.dir/ValidateInput.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/ValidateInput.c -o CMakeFiles/losning.dir/ValidateInput.c.s

CMakeFiles/losning.dir/ValidateInput.c.o.requires:

.PHONY : CMakeFiles/losning.dir/ValidateInput.c.o.requires

CMakeFiles/losning.dir/ValidateInput.c.o.provides: CMakeFiles/losning.dir/ValidateInput.c.o.requires
	$(MAKE) -f CMakeFiles/losning.dir/build.make CMakeFiles/losning.dir/ValidateInput.c.o.provides.build
.PHONY : CMakeFiles/losning.dir/ValidateInput.c.o.provides

CMakeFiles/losning.dir/ValidateInput.c.o.provides.build: CMakeFiles/losning.dir/ValidateInput.c.o


CMakeFiles/losning.dir/FileWriter.c.o: CMakeFiles/losning.dir/flags.make
CMakeFiles/losning.dir/FileWriter.c.o: FileWriter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/losning.dir/FileWriter.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/losning.dir/FileWriter.c.o   -c /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/FileWriter.c

CMakeFiles/losning.dir/FileWriter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/losning.dir/FileWriter.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/FileWriter.c > CMakeFiles/losning.dir/FileWriter.c.i

CMakeFiles/losning.dir/FileWriter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/losning.dir/FileWriter.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/FileWriter.c -o CMakeFiles/losning.dir/FileWriter.c.s

CMakeFiles/losning.dir/FileWriter.c.o.requires:

.PHONY : CMakeFiles/losning.dir/FileWriter.c.o.requires

CMakeFiles/losning.dir/FileWriter.c.o.provides: CMakeFiles/losning.dir/FileWriter.c.o.requires
	$(MAKE) -f CMakeFiles/losning.dir/build.make CMakeFiles/losning.dir/FileWriter.c.o.provides.build
.PHONY : CMakeFiles/losning.dir/FileWriter.c.o.provides

CMakeFiles/losning.dir/FileWriter.c.o.provides.build: CMakeFiles/losning.dir/FileWriter.c.o


CMakeFiles/losning.dir/FileReader.c.o: CMakeFiles/losning.dir/flags.make
CMakeFiles/losning.dir/FileReader.c.o: FileReader.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/losning.dir/FileReader.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/losning.dir/FileReader.c.o   -c /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/FileReader.c

CMakeFiles/losning.dir/FileReader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/losning.dir/FileReader.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/FileReader.c > CMakeFiles/losning.dir/FileReader.c.i

CMakeFiles/losning.dir/FileReader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/losning.dir/FileReader.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/FileReader.c -o CMakeFiles/losning.dir/FileReader.c.s

CMakeFiles/losning.dir/FileReader.c.o.requires:

.PHONY : CMakeFiles/losning.dir/FileReader.c.o.requires

CMakeFiles/losning.dir/FileReader.c.o.provides: CMakeFiles/losning.dir/FileReader.c.o.requires
	$(MAKE) -f CMakeFiles/losning.dir/build.make CMakeFiles/losning.dir/FileReader.c.o.provides.build
.PHONY : CMakeFiles/losning.dir/FileReader.c.o.provides

CMakeFiles/losning.dir/FileReader.c.o.provides.build: CMakeFiles/losning.dir/FileReader.c.o


CMakeFiles/losning.dir/Util.c.o: CMakeFiles/losning.dir/flags.make
CMakeFiles/losning.dir/Util.c.o: Util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/losning.dir/Util.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/losning.dir/Util.c.o   -c /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/Util.c

CMakeFiles/losning.dir/Util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/losning.dir/Util.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/Util.c > CMakeFiles/losning.dir/Util.c.i

CMakeFiles/losning.dir/Util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/losning.dir/Util.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/Util.c -o CMakeFiles/losning.dir/Util.c.s

CMakeFiles/losning.dir/Util.c.o.requires:

.PHONY : CMakeFiles/losning.dir/Util.c.o.requires

CMakeFiles/losning.dir/Util.c.o.provides: CMakeFiles/losning.dir/Util.c.o.requires
	$(MAKE) -f CMakeFiles/losning.dir/build.make CMakeFiles/losning.dir/Util.c.o.provides.build
.PHONY : CMakeFiles/losning.dir/Util.c.o.provides

CMakeFiles/losning.dir/Util.c.o.provides.build: CMakeFiles/losning.dir/Util.c.o


CMakeFiles/losning.dir/md5.c.o: CMakeFiles/losning.dir/flags.make
CMakeFiles/losning.dir/md5.c.o: md5.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/losning.dir/md5.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/losning.dir/md5.c.o   -c /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/md5.c

CMakeFiles/losning.dir/md5.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/losning.dir/md5.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/md5.c > CMakeFiles/losning.dir/md5.c.i

CMakeFiles/losning.dir/md5.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/losning.dir/md5.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/md5.c -o CMakeFiles/losning.dir/md5.c.s

CMakeFiles/losning.dir/md5.c.o.requires:

.PHONY : CMakeFiles/losning.dir/md5.c.o.requires

CMakeFiles/losning.dir/md5.c.o.provides: CMakeFiles/losning.dir/md5.c.o.requires
	$(MAKE) -f CMakeFiles/losning.dir/build.make CMakeFiles/losning.dir/md5.c.o.provides.build
.PHONY : CMakeFiles/losning.dir/md5.c.o.provides

CMakeFiles/losning.dir/md5.c.o.provides.build: CMakeFiles/losning.dir/md5.c.o


# Object files for target losning
losning_OBJECTS = \
"CMakeFiles/losning.dir/main.c.o" \
"CMakeFiles/losning.dir/ValidateInput.c.o" \
"CMakeFiles/losning.dir/FileWriter.c.o" \
"CMakeFiles/losning.dir/FileReader.c.o" \
"CMakeFiles/losning.dir/Util.c.o" \
"CMakeFiles/losning.dir/md5.c.o"

# External object files for target losning
losning_EXTERNAL_OBJECTS =

losning: CMakeFiles/losning.dir/main.c.o
losning: CMakeFiles/losning.dir/ValidateInput.c.o
losning: CMakeFiles/losning.dir/FileWriter.c.o
losning: CMakeFiles/losning.dir/FileReader.c.o
losning: CMakeFiles/losning.dir/Util.c.o
losning: CMakeFiles/losning.dir/md5.c.o
losning: CMakeFiles/losning.dir/build.make
losning: CMakeFiles/losning.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable losning"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/losning.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/losning.dir/build: losning

.PHONY : CMakeFiles/losning.dir/build

CMakeFiles/losning.dir/requires: CMakeFiles/losning.dir/main.c.o.requires
CMakeFiles/losning.dir/requires: CMakeFiles/losning.dir/ValidateInput.c.o.requires
CMakeFiles/losning.dir/requires: CMakeFiles/losning.dir/FileWriter.c.o.requires
CMakeFiles/losning.dir/requires: CMakeFiles/losning.dir/FileReader.c.o.requires
CMakeFiles/losning.dir/requires: CMakeFiles/losning.dir/Util.c.o.requires
CMakeFiles/losning.dir/requires: CMakeFiles/losning.dir/md5.c.o.requires

.PHONY : CMakeFiles/losning.dir/requires

CMakeFiles/losning.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/losning.dir/cmake_clean.cmake
.PHONY : CMakeFiles/losning.dir/clean

CMakeFiles/losning.dir/depend:
	cd /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning /home/bragalund/Documents/C/ovingsoppgaver/Leksjon6/losning/CMakeFiles/losning.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/losning.dir/depend

