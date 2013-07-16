#####################
SFML Game Development
Code Base
#####################

This file explains how to build the code accompanying the book SFML Game Development.

There are 10 directories that correspond to each of the chapters in the book. For example, 02_Resources contains the code for Chapter 2. The code for all chapters can be built at once.


================
I. Install CMake
================
Install CMake, preferably CMake-GUI (www.cmake.org or the cmake-gui package in Linux).


================
II. Install SFML
================
Download SFML 2 (www.sfml-dev.org). We recommend using a precompiled version of SFML which can be directly downloaded. 

It is also possible to build SFML yourself, in this case make sure that it is *installed* (make install, or compile the INSTALL project). Refer to the online tutorials for more details.

Eventually, you should have a directory with at least the subdirectories "include" and "lib" that contain headers and binaries of the SFML library, for example C:\SFML in Windows or /usr/local in Linux.


=====================================
III. Generate the build configuration
=====================================
1. Start cmake-gui.

2. In the field "Where is the source code", enter the path of the directory containing this ReadMe.txt file. Use forward slashes.

3. In the field "Where to build the binaries", enter a different path, where you want the intermediate build files of the book's code to be generated.

4. Click "Configure" and choose your compiler.

5. After, an error message might appear, telling that SFML is not found. This is intended. In order to fix it, enter the path to SFML in the field next to the SFML_ROOT variable. This is the directory mentioned in step II with the "lib" and "include" subdirectories (e.g. C:/SFML or /usr/local).

6. Choose your build configuration by setting CMAKE_BUILD_TYPE to either "Release" or "Debug". We recommend "Release" (it should be the default).

7. In Windows, check the box next to SFML_STATIC_LIBRARIES if you want to link SFML statically. Leave it unchecked if you prefer linking SFML dynamically and using DLL files.

8. Set the CMAKE_INSTALL_PREFIX to the path where you want the executables of the book's code to be installed. Choose a different directory (it can be a subdirectory of this one).

9. Click again "Configure". Now, there should be no more error messages.

10. Click "Generate".


====================
IV. Compile the code
====================
1. Switch to the build directory (the one you entered in "Where to build the binaries").

2. Now you should see the files required to compile the code. 

   For g++ or clang, this will be a Makefile. In the terminal, type "make install".
   If you use MinGW on Windows, you might have to type "mingw32-make install" instead.

   For Visual Studio, you will see a .sln solution. Open it, choose the correct build configuration ("Release" or "Debug") and build the INSTALL project.
   
   For other integrated development environments, it will be similar. Compile the INSTALL project.

3. After compiling, the executables and media files should be output to the directory you specified with CMAKE_INSTALL_PREFIX.


==========
V. Results
==========
The executables for each chapter are located in the install directory (CMAKE_INSTALL_PREFIX).

If you like to inspect the code itself, the current directory comes with 10 subdirectories, each containing the source and header files of the corresponding chapter. Also, the media files can be found for each chapter.