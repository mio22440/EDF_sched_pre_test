# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:/code/EDF_sched_pre_test/v1.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:/code/EDF_sched_pre_test/v1.0/build

# Include any dependencies generated for this target.
include CMakeFiles/edf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/edf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/edf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/edf.dir/flags.make

CMakeFiles/edf.dir/edf.c.obj: CMakeFiles/edf.dir/flags.make
CMakeFiles/edf.dir/edf.c.obj: F:/code/EDF_sched_pre_test/v1.0/edf.c
CMakeFiles/edf.dir/edf.c.obj: CMakeFiles/edf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:/code/EDF_sched_pre_test/v1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/edf.dir/edf.c.obj"
	C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/edf.dir/edf.c.obj -MF CMakeFiles/edf.dir/edf.c.obj.d -o CMakeFiles/edf.dir/edf.c.obj -c F:/code/EDF_sched_pre_test/v1.0/edf.c

CMakeFiles/edf.dir/edf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/edf.dir/edf.c.i"
	C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:/code/EDF_sched_pre_test/v1.0/edf.c > CMakeFiles/edf.dir/edf.c.i

CMakeFiles/edf.dir/edf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/edf.dir/edf.c.s"
	C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:/code/EDF_sched_pre_test/v1.0/edf.c -o CMakeFiles/edf.dir/edf.c.s

CMakeFiles/edf.dir/main.c.obj: CMakeFiles/edf.dir/flags.make
CMakeFiles/edf.dir/main.c.obj: F:/code/EDF_sched_pre_test/v1.0/main.c
CMakeFiles/edf.dir/main.c.obj: CMakeFiles/edf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:/code/EDF_sched_pre_test/v1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/edf.dir/main.c.obj"
	C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/edf.dir/main.c.obj -MF CMakeFiles/edf.dir/main.c.obj.d -o CMakeFiles/edf.dir/main.c.obj -c F:/code/EDF_sched_pre_test/v1.0/main.c

CMakeFiles/edf.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/edf.dir/main.c.i"
	C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:/code/EDF_sched_pre_test/v1.0/main.c > CMakeFiles/edf.dir/main.c.i

CMakeFiles/edf.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/edf.dir/main.c.s"
	C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:/code/EDF_sched_pre_test/v1.0/main.c -o CMakeFiles/edf.dir/main.c.s

# Object files for target edf
edf_OBJECTS = \
"CMakeFiles/edf.dir/edf.c.obj" \
"CMakeFiles/edf.dir/main.c.obj"

# External object files for target edf
edf_EXTERNAL_OBJECTS =

edf.exe: CMakeFiles/edf.dir/edf.c.obj
edf.exe: CMakeFiles/edf.dir/main.c.obj
edf.exe: CMakeFiles/edf.dir/build.make
edf.exe: CMakeFiles/edf.dir/linkLibs.rsp
edf.exe: CMakeFiles/edf.dir/objects1
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:/code/EDF_sched_pre_test/v1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable edf.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/edf.dir/objects.a
	C:/MinGW/bin/ar.exe qc CMakeFiles/edf.dir/objects.a @CMakeFiles/edf.dir/objects1
	C:/MinGW/bin/gcc.exe -g -Wl,--whole-archive CMakeFiles/edf.dir/objects.a -Wl,--no-whole-archive -o edf.exe -Wl,--out-implib,libedf.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/edf.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/edf.dir/build: edf.exe
.PHONY : CMakeFiles/edf.dir/build

CMakeFiles/edf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/edf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/edf.dir/clean

CMakeFiles/edf.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" F:/code/EDF_sched_pre_test/v1.0 F:/code/EDF_sched_pre_test/v1.0 F:/code/EDF_sched_pre_test/v1.0/build F:/code/EDF_sched_pre_test/v1.0/build F:/code/EDF_sched_pre_test/v1.0/build/CMakeFiles/edf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/edf.dir/depend

