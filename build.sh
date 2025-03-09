export CC=cc
export CXX=c++
export RISCV=/home/peeters/master-thesis/chipyard/.conda-env/riscv-tools

mkdir -p build
cd build
../configure --prefix=$RISCV
gmake
make install