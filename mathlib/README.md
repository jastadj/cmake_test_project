TODO - Generate Findmylib.cmake file

Build
=====
mkdir build
cd build
cmake .. -DBUILD_SHARED_LIBS=<OFF|ON>
cmake --build . --target install

Build Outputs
=============
Build outputs are installed to <build_dir>/buildoutput

Usage
=====
If including mathlib static library in a project, define MATHLIB_STATIC