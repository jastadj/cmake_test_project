TODO - Generate Findmylib.cmake file

Dependencies
============
- Requires that mathlib has been built and installed, see mathlib doc

Build
=====
mkdir build
cd build
cmake .. -DBUILD_SHARED_LIBS=<ON/OFF> -Dmathlib_DIR=<path_to_mathlib*.cmake files>
cmake --build . --target install

Build Outputs
=============
Build outputs are installed to <build_dir>/buildoutput

Usage
=====
If including mylib static library in a project, define MYLIB_STATIC