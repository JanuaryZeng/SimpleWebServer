# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zxj/project/job_related/SimpleServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zxj/project/job_related/SimpleServer/build

# Include any dependencies generated for this target.
include CMakeFiles/SimpleServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SimpleServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SimpleServer.dir/flags.make

CMakeFiles/SimpleServer.dir/src/connection_pool/connection_pool.cpp.o: CMakeFiles/SimpleServer.dir/flags.make
CMakeFiles/SimpleServer.dir/src/connection_pool/connection_pool.cpp.o: ../src/connection_pool/connection_pool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxj/project/job_related/SimpleServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SimpleServer.dir/src/connection_pool/connection_pool.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleServer.dir/src/connection_pool/connection_pool.cpp.o -c /home/zxj/project/job_related/SimpleServer/src/connection_pool/connection_pool.cpp

CMakeFiles/SimpleServer.dir/src/connection_pool/connection_pool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleServer.dir/src/connection_pool/connection_pool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxj/project/job_related/SimpleServer/src/connection_pool/connection_pool.cpp > CMakeFiles/SimpleServer.dir/src/connection_pool/connection_pool.cpp.i

CMakeFiles/SimpleServer.dir/src/connection_pool/connection_pool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleServer.dir/src/connection_pool/connection_pool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxj/project/job_related/SimpleServer/src/connection_pool/connection_pool.cpp -o CMakeFiles/SimpleServer.dir/src/connection_pool/connection_pool.cpp.s

CMakeFiles/SimpleServer.dir/src/http/http_conn.cpp.o: CMakeFiles/SimpleServer.dir/flags.make
CMakeFiles/SimpleServer.dir/src/http/http_conn.cpp.o: ../src/http/http_conn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxj/project/job_related/SimpleServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SimpleServer.dir/src/http/http_conn.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleServer.dir/src/http/http_conn.cpp.o -c /home/zxj/project/job_related/SimpleServer/src/http/http_conn.cpp

CMakeFiles/SimpleServer.dir/src/http/http_conn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleServer.dir/src/http/http_conn.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxj/project/job_related/SimpleServer/src/http/http_conn.cpp > CMakeFiles/SimpleServer.dir/src/http/http_conn.cpp.i

CMakeFiles/SimpleServer.dir/src/http/http_conn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleServer.dir/src/http/http_conn.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxj/project/job_related/SimpleServer/src/http/http_conn.cpp -o CMakeFiles/SimpleServer.dir/src/http/http_conn.cpp.s

CMakeFiles/SimpleServer.dir/src/log/logger.cpp.o: CMakeFiles/SimpleServer.dir/flags.make
CMakeFiles/SimpleServer.dir/src/log/logger.cpp.o: ../src/log/logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxj/project/job_related/SimpleServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SimpleServer.dir/src/log/logger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleServer.dir/src/log/logger.cpp.o -c /home/zxj/project/job_related/SimpleServer/src/log/logger.cpp

CMakeFiles/SimpleServer.dir/src/log/logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleServer.dir/src/log/logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxj/project/job_related/SimpleServer/src/log/logger.cpp > CMakeFiles/SimpleServer.dir/src/log/logger.cpp.i

CMakeFiles/SimpleServer.dir/src/log/logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleServer.dir/src/log/logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxj/project/job_related/SimpleServer/src/log/logger.cpp -o CMakeFiles/SimpleServer.dir/src/log/logger.cpp.s

CMakeFiles/SimpleServer.dir/src/log/logstream.cpp.o: CMakeFiles/SimpleServer.dir/flags.make
CMakeFiles/SimpleServer.dir/src/log/logstream.cpp.o: ../src/log/logstream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxj/project/job_related/SimpleServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SimpleServer.dir/src/log/logstream.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleServer.dir/src/log/logstream.cpp.o -c /home/zxj/project/job_related/SimpleServer/src/log/logstream.cpp

CMakeFiles/SimpleServer.dir/src/log/logstream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleServer.dir/src/log/logstream.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxj/project/job_related/SimpleServer/src/log/logstream.cpp > CMakeFiles/SimpleServer.dir/src/log/logstream.cpp.i

CMakeFiles/SimpleServer.dir/src/log/logstream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleServer.dir/src/log/logstream.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxj/project/job_related/SimpleServer/src/log/logstream.cpp -o CMakeFiles/SimpleServer.dir/src/log/logstream.cpp.s

CMakeFiles/SimpleServer.dir/src/timer/timer.cpp.o: CMakeFiles/SimpleServer.dir/flags.make
CMakeFiles/SimpleServer.dir/src/timer/timer.cpp.o: ../src/timer/timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxj/project/job_related/SimpleServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SimpleServer.dir/src/timer/timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleServer.dir/src/timer/timer.cpp.o -c /home/zxj/project/job_related/SimpleServer/src/timer/timer.cpp

CMakeFiles/SimpleServer.dir/src/timer/timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleServer.dir/src/timer/timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxj/project/job_related/SimpleServer/src/timer/timer.cpp > CMakeFiles/SimpleServer.dir/src/timer/timer.cpp.i

CMakeFiles/SimpleServer.dir/src/timer/timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleServer.dir/src/timer/timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxj/project/job_related/SimpleServer/src/timer/timer.cpp -o CMakeFiles/SimpleServer.dir/src/timer/timer.cpp.s

CMakeFiles/SimpleServer.dir/src/util/config.cpp.o: CMakeFiles/SimpleServer.dir/flags.make
CMakeFiles/SimpleServer.dir/src/util/config.cpp.o: ../src/util/config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxj/project/job_related/SimpleServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SimpleServer.dir/src/util/config.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleServer.dir/src/util/config.cpp.o -c /home/zxj/project/job_related/SimpleServer/src/util/config.cpp

CMakeFiles/SimpleServer.dir/src/util/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleServer.dir/src/util/config.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxj/project/job_related/SimpleServer/src/util/config.cpp > CMakeFiles/SimpleServer.dir/src/util/config.cpp.i

CMakeFiles/SimpleServer.dir/src/util/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleServer.dir/src/util/config.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxj/project/job_related/SimpleServer/src/util/config.cpp -o CMakeFiles/SimpleServer.dir/src/util/config.cpp.s

CMakeFiles/SimpleServer.dir/src/util/util.cpp.o: CMakeFiles/SimpleServer.dir/flags.make
CMakeFiles/SimpleServer.dir/src/util/util.cpp.o: ../src/util/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxj/project/job_related/SimpleServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SimpleServer.dir/src/util/util.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleServer.dir/src/util/util.cpp.o -c /home/zxj/project/job_related/SimpleServer/src/util/util.cpp

CMakeFiles/SimpleServer.dir/src/util/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleServer.dir/src/util/util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxj/project/job_related/SimpleServer/src/util/util.cpp > CMakeFiles/SimpleServer.dir/src/util/util.cpp.i

CMakeFiles/SimpleServer.dir/src/util/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleServer.dir/src/util/util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxj/project/job_related/SimpleServer/src/util/util.cpp -o CMakeFiles/SimpleServer.dir/src/util/util.cpp.s

CMakeFiles/SimpleServer.dir/src/main.cpp.o: CMakeFiles/SimpleServer.dir/flags.make
CMakeFiles/SimpleServer.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxj/project/job_related/SimpleServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SimpleServer.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleServer.dir/src/main.cpp.o -c /home/zxj/project/job_related/SimpleServer/src/main.cpp

CMakeFiles/SimpleServer.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleServer.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxj/project/job_related/SimpleServer/src/main.cpp > CMakeFiles/SimpleServer.dir/src/main.cpp.i

CMakeFiles/SimpleServer.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleServer.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxj/project/job_related/SimpleServer/src/main.cpp -o CMakeFiles/SimpleServer.dir/src/main.cpp.s

CMakeFiles/SimpleServer.dir/src/webserver.cpp.o: CMakeFiles/SimpleServer.dir/flags.make
CMakeFiles/SimpleServer.dir/src/webserver.cpp.o: ../src/webserver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxj/project/job_related/SimpleServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/SimpleServer.dir/src/webserver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleServer.dir/src/webserver.cpp.o -c /home/zxj/project/job_related/SimpleServer/src/webserver.cpp

CMakeFiles/SimpleServer.dir/src/webserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleServer.dir/src/webserver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxj/project/job_related/SimpleServer/src/webserver.cpp > CMakeFiles/SimpleServer.dir/src/webserver.cpp.i

CMakeFiles/SimpleServer.dir/src/webserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleServer.dir/src/webserver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxj/project/job_related/SimpleServer/src/webserver.cpp -o CMakeFiles/SimpleServer.dir/src/webserver.cpp.s

# Object files for target SimpleServer
SimpleServer_OBJECTS = \
"CMakeFiles/SimpleServer.dir/src/connection_pool/connection_pool.cpp.o" \
"CMakeFiles/SimpleServer.dir/src/http/http_conn.cpp.o" \
"CMakeFiles/SimpleServer.dir/src/log/logger.cpp.o" \
"CMakeFiles/SimpleServer.dir/src/log/logstream.cpp.o" \
"CMakeFiles/SimpleServer.dir/src/timer/timer.cpp.o" \
"CMakeFiles/SimpleServer.dir/src/util/config.cpp.o" \
"CMakeFiles/SimpleServer.dir/src/util/util.cpp.o" \
"CMakeFiles/SimpleServer.dir/src/main.cpp.o" \
"CMakeFiles/SimpleServer.dir/src/webserver.cpp.o"

# External object files for target SimpleServer
SimpleServer_EXTERNAL_OBJECTS =

../SimpleServer: CMakeFiles/SimpleServer.dir/src/connection_pool/connection_pool.cpp.o
../SimpleServer: CMakeFiles/SimpleServer.dir/src/http/http_conn.cpp.o
../SimpleServer: CMakeFiles/SimpleServer.dir/src/log/logger.cpp.o
../SimpleServer: CMakeFiles/SimpleServer.dir/src/log/logstream.cpp.o
../SimpleServer: CMakeFiles/SimpleServer.dir/src/timer/timer.cpp.o
../SimpleServer: CMakeFiles/SimpleServer.dir/src/util/config.cpp.o
../SimpleServer: CMakeFiles/SimpleServer.dir/src/util/util.cpp.o
../SimpleServer: CMakeFiles/SimpleServer.dir/src/main.cpp.o
../SimpleServer: CMakeFiles/SimpleServer.dir/src/webserver.cpp.o
../SimpleServer: CMakeFiles/SimpleServer.dir/build.make
../SimpleServer: CMakeFiles/SimpleServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zxj/project/job_related/SimpleServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ../SimpleServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SimpleServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SimpleServer.dir/build: ../SimpleServer

.PHONY : CMakeFiles/SimpleServer.dir/build

CMakeFiles/SimpleServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SimpleServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SimpleServer.dir/clean

CMakeFiles/SimpleServer.dir/depend:
	cd /home/zxj/project/job_related/SimpleServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zxj/project/job_related/SimpleServer /home/zxj/project/job_related/SimpleServer /home/zxj/project/job_related/SimpleServer/build /home/zxj/project/job_related/SimpleServer/build /home/zxj/project/job_related/SimpleServer/build/CMakeFiles/SimpleServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SimpleServer.dir/depend

