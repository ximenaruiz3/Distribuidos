# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /opt/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/david/CLionProjects/ProyectoSD

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/CLionProjects/ProyectoSD/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProyectoSD.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProyectoSD.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProyectoSD.dir/flags.make

CMakeFiles/ProyectoSD.dir/Server.cpp.o: CMakeFiles/ProyectoSD.dir/flags.make
CMakeFiles/ProyectoSD.dir/Server.cpp.o: ../Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/CLionProjects/ProyectoSD/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProyectoSD.dir/Server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProyectoSD.dir/Server.cpp.o -c /home/david/CLionProjects/ProyectoSD/Server.cpp

CMakeFiles/ProyectoSD.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProyectoSD.dir/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/CLionProjects/ProyectoSD/Server.cpp > CMakeFiles/ProyectoSD.dir/Server.cpp.i

CMakeFiles/ProyectoSD.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProyectoSD.dir/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/CLionProjects/ProyectoSD/Server.cpp -o CMakeFiles/ProyectoSD.dir/Server.cpp.s

CMakeFiles/ProyectoSD.dir/Server.cpp.o.requires:

.PHONY : CMakeFiles/ProyectoSD.dir/Server.cpp.o.requires

CMakeFiles/ProyectoSD.dir/Server.cpp.o.provides: CMakeFiles/ProyectoSD.dir/Server.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProyectoSD.dir/build.make CMakeFiles/ProyectoSD.dir/Server.cpp.o.provides.build
.PHONY : CMakeFiles/ProyectoSD.dir/Server.cpp.o.provides

CMakeFiles/ProyectoSD.dir/Server.cpp.o.provides.build: CMakeFiles/ProyectoSD.dir/Server.cpp.o


CMakeFiles/ProyectoSD.dir/Client.cpp.o: CMakeFiles/ProyectoSD.dir/flags.make
CMakeFiles/ProyectoSD.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/CLionProjects/ProyectoSD/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ProyectoSD.dir/Client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProyectoSD.dir/Client.cpp.o -c /home/david/CLionProjects/ProyectoSD/Client.cpp

CMakeFiles/ProyectoSD.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProyectoSD.dir/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/CLionProjects/ProyectoSD/Client.cpp > CMakeFiles/ProyectoSD.dir/Client.cpp.i

CMakeFiles/ProyectoSD.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProyectoSD.dir/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/CLionProjects/ProyectoSD/Client.cpp -o CMakeFiles/ProyectoSD.dir/Client.cpp.s

CMakeFiles/ProyectoSD.dir/Client.cpp.o.requires:

.PHONY : CMakeFiles/ProyectoSD.dir/Client.cpp.o.requires

CMakeFiles/ProyectoSD.dir/Client.cpp.o.provides: CMakeFiles/ProyectoSD.dir/Client.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProyectoSD.dir/build.make CMakeFiles/ProyectoSD.dir/Client.cpp.o.provides.build
.PHONY : CMakeFiles/ProyectoSD.dir/Client.cpp.o.provides

CMakeFiles/ProyectoSD.dir/Client.cpp.o.provides.build: CMakeFiles/ProyectoSD.dir/Client.cpp.o


CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.o: CMakeFiles/ProyectoSD.dir/flags.make
CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.o: ../ClientInfo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/CLionProjects/ProyectoSD/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.o -c /home/david/CLionProjects/ProyectoSD/ClientInfo.cpp

CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/CLionProjects/ProyectoSD/ClientInfo.cpp > CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.i

CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/CLionProjects/ProyectoSD/ClientInfo.cpp -o CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.s

CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.o.requires:

.PHONY : CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.o.requires

CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.o.provides: CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProyectoSD.dir/build.make CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.o.provides.build
.PHONY : CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.o.provides

CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.o.provides.build: CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.o


CMakeFiles/ProyectoSD.dir/SendFiles.cpp.o: CMakeFiles/ProyectoSD.dir/flags.make
CMakeFiles/ProyectoSD.dir/SendFiles.cpp.o: ../SendFiles.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/CLionProjects/ProyectoSD/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ProyectoSD.dir/SendFiles.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProyectoSD.dir/SendFiles.cpp.o -c /home/david/CLionProjects/ProyectoSD/SendFiles.cpp

CMakeFiles/ProyectoSD.dir/SendFiles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProyectoSD.dir/SendFiles.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/CLionProjects/ProyectoSD/SendFiles.cpp > CMakeFiles/ProyectoSD.dir/SendFiles.cpp.i

CMakeFiles/ProyectoSD.dir/SendFiles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProyectoSD.dir/SendFiles.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/CLionProjects/ProyectoSD/SendFiles.cpp -o CMakeFiles/ProyectoSD.dir/SendFiles.cpp.s

CMakeFiles/ProyectoSD.dir/SendFiles.cpp.o.requires:

.PHONY : CMakeFiles/ProyectoSD.dir/SendFiles.cpp.o.requires

CMakeFiles/ProyectoSD.dir/SendFiles.cpp.o.provides: CMakeFiles/ProyectoSD.dir/SendFiles.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProyectoSD.dir/build.make CMakeFiles/ProyectoSD.dir/SendFiles.cpp.o.provides.build
.PHONY : CMakeFiles/ProyectoSD.dir/SendFiles.cpp.o.provides

CMakeFiles/ProyectoSD.dir/SendFiles.cpp.o.provides.build: CMakeFiles/ProyectoSD.dir/SendFiles.cpp.o


CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.o: CMakeFiles/ProyectoSD.dir/flags.make
CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.o: ../ReciveFiles.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/CLionProjects/ProyectoSD/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.o -c /home/david/CLionProjects/ProyectoSD/ReciveFiles.cpp

CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/CLionProjects/ProyectoSD/ReciveFiles.cpp > CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.i

CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/CLionProjects/ProyectoSD/ReciveFiles.cpp -o CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.s

CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.o.requires:

.PHONY : CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.o.requires

CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.o.provides: CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProyectoSD.dir/build.make CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.o.provides.build
.PHONY : CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.o.provides

CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.o.provides.build: CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.o


CMakeFiles/ProyectoSD.dir/main.cpp.o: CMakeFiles/ProyectoSD.dir/flags.make
CMakeFiles/ProyectoSD.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/CLionProjects/ProyectoSD/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ProyectoSD.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProyectoSD.dir/main.cpp.o -c /home/david/CLionProjects/ProyectoSD/main.cpp

CMakeFiles/ProyectoSD.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProyectoSD.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/CLionProjects/ProyectoSD/main.cpp > CMakeFiles/ProyectoSD.dir/main.cpp.i

CMakeFiles/ProyectoSD.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProyectoSD.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/CLionProjects/ProyectoSD/main.cpp -o CMakeFiles/ProyectoSD.dir/main.cpp.s

CMakeFiles/ProyectoSD.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ProyectoSD.dir/main.cpp.o.requires

CMakeFiles/ProyectoSD.dir/main.cpp.o.provides: CMakeFiles/ProyectoSD.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProyectoSD.dir/build.make CMakeFiles/ProyectoSD.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ProyectoSD.dir/main.cpp.o.provides

CMakeFiles/ProyectoSD.dir/main.cpp.o.provides.build: CMakeFiles/ProyectoSD.dir/main.cpp.o


# Object files for target ProyectoSD
ProyectoSD_OBJECTS = \
"CMakeFiles/ProyectoSD.dir/Server.cpp.o" \
"CMakeFiles/ProyectoSD.dir/Client.cpp.o" \
"CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.o" \
"CMakeFiles/ProyectoSD.dir/SendFiles.cpp.o" \
"CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.o" \
"CMakeFiles/ProyectoSD.dir/main.cpp.o"

# External object files for target ProyectoSD
ProyectoSD_EXTERNAL_OBJECTS =

ProyectoSD: CMakeFiles/ProyectoSD.dir/Server.cpp.o
ProyectoSD: CMakeFiles/ProyectoSD.dir/Client.cpp.o
ProyectoSD: CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.o
ProyectoSD: CMakeFiles/ProyectoSD.dir/SendFiles.cpp.o
ProyectoSD: CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.o
ProyectoSD: CMakeFiles/ProyectoSD.dir/main.cpp.o
ProyectoSD: CMakeFiles/ProyectoSD.dir/build.make
ProyectoSD: CMakeFiles/ProyectoSD.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/CLionProjects/ProyectoSD/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ProyectoSD"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProyectoSD.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProyectoSD.dir/build: ProyectoSD

.PHONY : CMakeFiles/ProyectoSD.dir/build

CMakeFiles/ProyectoSD.dir/requires: CMakeFiles/ProyectoSD.dir/Server.cpp.o.requires
CMakeFiles/ProyectoSD.dir/requires: CMakeFiles/ProyectoSD.dir/Client.cpp.o.requires
CMakeFiles/ProyectoSD.dir/requires: CMakeFiles/ProyectoSD.dir/ClientInfo.cpp.o.requires
CMakeFiles/ProyectoSD.dir/requires: CMakeFiles/ProyectoSD.dir/SendFiles.cpp.o.requires
CMakeFiles/ProyectoSD.dir/requires: CMakeFiles/ProyectoSD.dir/ReciveFiles.cpp.o.requires
CMakeFiles/ProyectoSD.dir/requires: CMakeFiles/ProyectoSD.dir/main.cpp.o.requires

.PHONY : CMakeFiles/ProyectoSD.dir/requires

CMakeFiles/ProyectoSD.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProyectoSD.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProyectoSD.dir/clean

CMakeFiles/ProyectoSD.dir/depend:
	cd /home/david/CLionProjects/ProyectoSD/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/CLionProjects/ProyectoSD /home/david/CLionProjects/ProyectoSD /home/david/CLionProjects/ProyectoSD/cmake-build-debug /home/david/CLionProjects/ProyectoSD/cmake-build-debug /home/david/CLionProjects/ProyectoSD/cmake-build-debug/CMakeFiles/ProyectoSD.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProyectoSD.dir/depend
