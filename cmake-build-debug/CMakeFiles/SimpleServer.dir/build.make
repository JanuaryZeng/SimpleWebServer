# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/zxj/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7142.21/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zxj/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7142.21/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zxj/project/CLionProjects/NetCode/SimpleServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zxj/project/CLionProjects/NetCode/SimpleServer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SimpleServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SimpleServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SimpleServer.dir/flags.make

CMakeFiles/SimpleServer.dir/src/main.cpp.o: CMakeFiles/SimpleServer.dir/flags.make
CMakeFiles/SimpleServer.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxj/project/CLionProjects/NetCode/SimpleServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SimpleServer.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleServer.dir/src/main.cpp.o -c /home/zxj/project/CLionProjects/NetCode/SimpleServer/src/main.cpp

CMakeFiles/SimpleServer.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleServer.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxj/project/CLionProjects/NetCode/SimpleServer/src/main.cpp > CMakeFiles/SimpleServer.dir/src/main.cpp.i

CMakeFiles/SimpleServer.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleServer.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxj/project/CLionProjects/NetCode/SimpleServer/src/main.cpp -o CMakeFiles/SimpleServer.dir/src/main.cpp.s

CMakeFiles/SimpleServer.dir/src/lock/lock.cpp.o: CMakeFiles/SimpleServer.dir/flags.make
CMakeFiles/SimpleServer.dir/src/lock/lock.cpp.o: ../src/lock/lock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxj/project/CLionProjects/NetCode/SimpleServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SimpleServer.dir/src/lock/lock.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleServer.dir/src/lock/lock.cpp.o -c /home/zxj/project/CLionProjects/NetCode/SimpleServer/src/lock/lock.cpp

CMakeFiles/SimpleServer.dir/src/lock/lock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleServer.dir/src/lock/lock.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxj/project/CLionProjects/NetCode/SimpleServer/src/lock/lock.cpp > CMakeFiles/SimpleServer.dir/src/lock/lock.cpp.i

CMakeFiles/SimpleServer.dir/src/lock/lock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleServer.dir/src/lock/lock.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxj/project/CLionProjects/NetCode/SimpleServer/src/lock/lock.cpp -o CMakeFiles/SimpleServer.dir/src/lock/lock.cpp.s

CMakeFiles/SimpleServer.dir/src/thread_pool/thread_pool.cpp.o: CMakeFiles/SimpleServer.dir/flags.make
CMakeFiles/SimpleServer.dir/src/thread_pool/thread_pool.cpp.o: ../src/thread_pool/thread_pool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxj/project/CLionProjects/NetCode/SimpleServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SimpleServer.dir/src/thread_pool/thread_pool.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleServer.dir/src/thread_pool/thread_pool.cpp.o -c /home/zxj/project/CLionProjects/NetCode/SimpleServer/src/thread_pool/thread_pool.cpp

CMakeFiles/SimpleServer.dir/src/thread_pool/thread_pool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleServer.dir/src/thread_pool/thread_pool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxj/project/CLionProjects/NetCode/SimpleServer/src/thread_pool/thread_pool.cpp > CMakeFiles/SimpleServer.dir/src/thread_pool/thread_pool.cpp.i

CMakeFiles/SimpleServer.dir/src/thread_pool/thread_pool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleServer.dir/src/thread_pool/thread_pool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxj/project/CLionProjects/NetCode/SimpleServer/src/thread_pool/thread_pool.cpp -o CMakeFiles/SimpleServer.dir/src/thread_pool/thread_pool.cpp.s

CMakeFiles/SimpleServer.dir/src/server/webServer.cpp.o: CMakeFiles/SimpleServer.dir/flags.make
CMakeFiles/SimpleServer.dir/src/server/webServer.cpp.o: ../src/server/webServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxj/project/CLionProjects/NetCode/SimpleServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SimpleServer.dir/src/server/webServer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleServer.dir/src/server/webServer.cpp.o -c /home/zxj/project/CLionProjects/NetCode/SimpleServer/src/server/webServer.cpp

CMakeFiles/SimpleServer.dir/src/server/webServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleServer.dir/src/server/webServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxj/project/CLionProjects/NetCode/SimpleServer/src/server/webServer.cpp > CMakeFiles/SimpleServer.dir/src/server/webServer.cpp.i

CMakeFiles/SimpleServer.dir/src/server/webServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleServer.dir/src/server/webServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxj/project/CLionProjects/NetCode/SimpleServer/src/server/webServer.cpp -o CMakeFiles/SimpleServer.dir/src/server/webServer.cpp.s

# Object files for target SimpleServer
SimpleServer_OBJECTS = \
"CMakeFiles/SimpleServer.dir/src/main.cpp.o" \
"CMakeFiles/SimpleServer.dir/src/lock/lock.cpp.o" \
"CMakeFiles/SimpleServer.dir/src/thread_pool/thread_pool.cpp.o" \
"CMakeFiles/SimpleServer.dir/src/server/webServer.cpp.o"

# External object files for target SimpleServer
SimpleServer_EXTERNAL_OBJECTS =

SimpleServer: CMakeFiles/SimpleServer.dir/src/main.cpp.o
SimpleServer: CMakeFiles/SimpleServer.dir/src/lock/lock.cpp.o
SimpleServer: CMakeFiles/SimpleServer.dir/src/thread_pool/thread_pool.cpp.o
SimpleServer: CMakeFiles/SimpleServer.dir/src/server/webServer.cpp.o
SimpleServer: CMakeFiles/SimpleServer.dir/build.make
SimpleServer: CMakeFiles/SimpleServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zxj/project/CLionProjects/NetCode/SimpleServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable SimpleServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SimpleServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SimpleServer.dir/build: SimpleServer

.PHONY : CMakeFiles/SimpleServer.dir/build

CMakeFiles/SimpleServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SimpleServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SimpleServer.dir/clean

CMakeFiles/SimpleServer.dir/depend:
	cd /home/zxj/project/CLionProjects/NetCode/SimpleServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zxj/project/CLionProjects/NetCode/SimpleServer /home/zxj/project/CLionProjects/NetCode/SimpleServer /home/zxj/project/CLionProjects/NetCode/SimpleServer/cmake-build-debug /home/zxj/project/CLionProjects/NetCode/SimpleServer/cmake-build-debug /home/zxj/project/CLionProjects/NetCode/SimpleServer/cmake-build-debug/CMakeFiles/SimpleServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SimpleServer.dir/depend

