#!/bin/fish

set BINDIR $PWD/out

echo "==> 正在编译，请稍等"

clang++ i_f/data.cxx -o $BINDIR/i_f/data -Ofast -flto=thin -march=native -mtune=native -mavx2 -mfma -mlzcnt -mpopcnt -mbmi -mbmi2 -mssse3 -Xclang -load -Xclang LLVMPolly.so -mllvm -polly -mllvm -polly-parallel -lgomp -mllvm -polly-omp-backend=LLVM -mllvm -polly-vectorizer=stripmine
clang++ int/data.cxx -o $BINDIR/int/data -Ofast -flto=thin -march=native -mtune=native -mavx2 -mfma -mlzcnt -mpopcnt -mbmi -mbmi2 -mssse3 -Xclang -load -Xclang LLVMPolly.so -mllvm -polly -mllvm -polly-parallel -lgomp -mllvm -polly-omp-backend=LLVM -mllvm -polly-vectorizer=stripmine

g++ i_f/cstdio.cxx -o $BINDIR/i_f/cstdio -O2
g++ i_f/fstream.cxx -o $BINDIR/i_f/fstream -O2
g++ i_f/iostream.cxx -o $BINDIR/i_f/iostream -O2

g++ int/cstdio.cxx -o $BINDIR/int/cstdio -O2
g++ int/fstream.cxx -o $BINDIR/int/fstream -O2
g++ int/iostream.cxx -o $BINDIR/int/iostream -O2
g++ int/fastio_with_fstream.cxx -o $BINDIR/int/fastio_with_fstream -O2
g++ int/fastio_with_stdio.cxx -o $BINDIR/int/fastio_with_stdio -O2

clang++ benchmark.cxx -o $BINDIR/benchmark -Ofast -flto=thin -march=native -mtune=native -mavx2 -mfma -mlzcnt -mpopcnt -mbmi -mbmi2 -mssse3 -Xclang -load -Xclang LLVMPolly.so -mllvm -polly -mllvm -polly-parallel -lgomp -mllvm -polly-omp-backend=LLVM -mllvm -polly-vectorizer=stripmine

echo "==> 编译完成，开始测试"

$BINDIR/benchmark
