rm -rf build
mkdir build
cd build

cmake \
    -DBLT_CXX_STD=c++11\
    -DCMAKE_CXX_COMPILER=g++\
    -DCMAKE_C_COMPILER=gcc\
    -DENABLE_TESTS=Off\
    -DENABLE_EXAMPLES=Off\
    -DENABLE_OPENMP=Off\
    -DENABLE_CUDA=On\
    -DENABLE_CUB=Off\
    -DCUDA_ARCH=sm_60\
    ..

make -j
