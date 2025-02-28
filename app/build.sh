#! /bin/bash

rm -rf build
mkdir build
pushd build
cmake ..
cmake --build . --target install
popd

