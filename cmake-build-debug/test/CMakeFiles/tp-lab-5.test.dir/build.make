# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Programs\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programs\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mushka\Desktop\tp-lab-5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mushka\Desktop\tp-lab-5\cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/tp-lab-5.test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/tp-lab-5.test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/tp-lab-5.test.dir/flags.make

test/CMakeFiles/tp-lab-5.test.dir/AllTests.cpp.obj: test/CMakeFiles/tp-lab-5.test.dir/flags.make
test/CMakeFiles/tp-lab-5.test.dir/AllTests.cpp.obj: test/CMakeFiles/tp-lab-5.test.dir/includes_CXX.rsp
test/CMakeFiles/tp-lab-5.test.dir/AllTests.cpp.obj: ../test/AllTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mushka\Desktop\tp-lab-5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/tp-lab-5.test.dir/AllTests.cpp.obj"
	cd /d C:\Users\mushka\Desktop\tp-lab-5\cmake-build-debug\test && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tp-lab-5.test.dir\AllTests.cpp.obj -c C:\Users\mushka\Desktop\tp-lab-5\test\AllTests.cpp

test/CMakeFiles/tp-lab-5.test.dir/AllTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tp-lab-5.test.dir/AllTests.cpp.i"
	cd /d C:\Users\mushka\Desktop\tp-lab-5\cmake-build-debug\test && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mushka\Desktop\tp-lab-5\test\AllTests.cpp > CMakeFiles\tp-lab-5.test.dir\AllTests.cpp.i

test/CMakeFiles/tp-lab-5.test.dir/AllTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tp-lab-5.test.dir/AllTests.cpp.s"
	cd /d C:\Users\mushka\Desktop\tp-lab-5\cmake-build-debug\test && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mushka\Desktop\tp-lab-5\test\AllTests.cpp -o CMakeFiles\tp-lab-5.test.dir\AllTests.cpp.s

test/CMakeFiles/tp-lab-5.test.dir/tests.cpp.obj: test/CMakeFiles/tp-lab-5.test.dir/flags.make
test/CMakeFiles/tp-lab-5.test.dir/tests.cpp.obj: test/CMakeFiles/tp-lab-5.test.dir/includes_CXX.rsp
test/CMakeFiles/tp-lab-5.test.dir/tests.cpp.obj: ../test/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mushka\Desktop\tp-lab-5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/tp-lab-5.test.dir/tests.cpp.obj"
	cd /d C:\Users\mushka\Desktop\tp-lab-5\cmake-build-debug\test && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tp-lab-5.test.dir\tests.cpp.obj -c C:\Users\mushka\Desktop\tp-lab-5\test\tests.cpp

test/CMakeFiles/tp-lab-5.test.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tp-lab-5.test.dir/tests.cpp.i"
	cd /d C:\Users\mushka\Desktop\tp-lab-5\cmake-build-debug\test && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mushka\Desktop\tp-lab-5\test\tests.cpp > CMakeFiles\tp-lab-5.test.dir\tests.cpp.i

test/CMakeFiles/tp-lab-5.test.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tp-lab-5.test.dir/tests.cpp.s"
	cd /d C:\Users\mushka\Desktop\tp-lab-5\cmake-build-debug\test && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mushka\Desktop\tp-lab-5\test\tests.cpp -o CMakeFiles\tp-lab-5.test.dir\tests.cpp.s

# Object files for target tp-lab-5.test
tp__lab__5_test_OBJECTS = \
"CMakeFiles/tp-lab-5.test.dir/AllTests.cpp.obj" \
"CMakeFiles/tp-lab-5.test.dir/tests.cpp.obj"

# External object files for target tp-lab-5.test
tp__lab__5_test_EXTERNAL_OBJECTS =

test/tp-lab-5.test.exe: test/CMakeFiles/tp-lab-5.test.dir/AllTests.cpp.obj
test/tp-lab-5.test.exe: test/CMakeFiles/tp-lab-5.test.dir/tests.cpp.obj
test/tp-lab-5.test.exe: test/CMakeFiles/tp-lab-5.test.dir/build.make
test/tp-lab-5.test.exe: src/libtp-lab-5.dll.a
test/tp-lab-5.test.exe: test/CMakeFiles/tp-lab-5.test.dir/linklibs.rsp
test/tp-lab-5.test.exe: test/CMakeFiles/tp-lab-5.test.dir/objects1.rsp
test/tp-lab-5.test.exe: test/CMakeFiles/tp-lab-5.test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mushka\Desktop\tp-lab-5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tp-lab-5.test.exe"
	cd /d C:\Users\mushka\Desktop\tp-lab-5\cmake-build-debug\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tp-lab-5.test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/tp-lab-5.test.dir/build: test/tp-lab-5.test.exe

.PHONY : test/CMakeFiles/tp-lab-5.test.dir/build

test/CMakeFiles/tp-lab-5.test.dir/clean:
	cd /d C:\Users\mushka\Desktop\tp-lab-5\cmake-build-debug\test && $(CMAKE_COMMAND) -P CMakeFiles\tp-lab-5.test.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/tp-lab-5.test.dir/clean

test/CMakeFiles/tp-lab-5.test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mushka\Desktop\tp-lab-5 C:\Users\mushka\Desktop\tp-lab-5\test C:\Users\mushka\Desktop\tp-lab-5\cmake-build-debug C:\Users\mushka\Desktop\tp-lab-5\cmake-build-debug\test C:\Users\mushka\Desktop\tp-lab-5\cmake-build-debug\test\CMakeFiles\tp-lab-5.test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/tp-lab-5.test.dir/depend

