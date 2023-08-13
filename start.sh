#!/bin/fish

set BINDIR $PWD/out

echo "==> 正在编译，请稍等"

set FLAGS -O3 -ffast-math -flto -march=native -mtune=native

g++ float/data.cxx -o $BINDIR/float/data $FLAGS
g++ i_f/data.cxx -o $BINDIR/i_f/data $FLAGS
g++ int/data.cxx -o $BINDIR/int/data $FLAGS
g++ uint/data.cxx -o $BINDIR/uint/data $FLAGS

g++ i_f/cstdio.cxx -o $BINDIR/float/cstdio -O2
g++ i_f/fstream.cxx -o $BINDIR/float/fstream -O2
g++ i_f/iostream.cxx -o $BINDIR/float/iostream -O2

g++ i_f/cstdio.cxx -o $BINDIR/i_f/cstdio -O2
g++ i_f/fstream.cxx -o $BINDIR/i_f/fstream -O2
g++ i_f/iostream.cxx -o $BINDIR/i_f/iostream -O2

g++ int/cstdio.cxx -o $BINDIR/int/cstdio -O2
g++ int/fstream.cxx -o $BINDIR/int/fstream -O2
g++ int/iostream.cxx -o $BINDIR/int/iostream -O2
g++ int/fastio_with_fstream.cxx -o $BINDIR/int/fastio_with_fstream -O2
g++ int/fastio_with_stdio.cxx -o $BINDIR/int/fastio_with_stdio -O2
g++ int/fread.cxx -o $BINDIR/int/fread -O2

g++ uint/cstdio.cxx -o $BINDIR/uint/cstdio -O2
g++ uint/fstream.cxx -o $BINDIR/uint/fstream -O2
g++ uint/iostream.cxx -o $BINDIR/uint/iostream -O2
g++ uint/fastio_with_fstream.cxx -o $BINDIR/uint/fastio_with_fstream -O2
g++ uint/fastio_with_stdio.cxx -o $BINDIR/uint/fastio_with_stdio -O2
g++ uint/fread.cxx -o $BINDIR/uint/fread -O2

g++ benchmark.cxx -o $BINDIR/benchmark $FLAGS

echo "==> 编译完成，开始测试"

$BINDIR/benchmark
