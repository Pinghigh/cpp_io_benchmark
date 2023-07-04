读入输出测试

测试 1：150000 个随机小数与 150000 个随机 64 位整数  
测试 2：300000 个随机 64 位整数

depends: `lolcat`, `figlet`, `clang++`, `g++`, `polly`, `fish`

`clang++` 和 `polly` 用来编译数据生成器和主程序，可以在 `start.sh` 和 `benchmark.cxx` 里面替换。

默认 10 次取平均数


硬件：
```
╔═════════ Hardware Information ═════════╗
  HST => VMware7,1
  CPU => Intel i5-12400 (6) @ 2.496001 GHz
╟───────── Software Information ─────────╢
  SYS => Arch Linux x86_64
  KER => 6.4.1-1-cachyos-lto
  SHE => fish 3.6.1
╚════════════════════════════════════════╝
```

测试结果

```
 ___ ___    _____         _     ____          _____ _ _              _ _       
|_ _/ _ \  |_   _|__  ___| |_  | __ ) _   _  |_   _(_) |__  _ __ ___| | | __ _ 
 | | | | |   | |/ _ \/ __| __| |  _ \| | | |   | | | | '_ \| '__/ _ \ | |/ _` |
 | | |_| |   | |  __/\__ \ |_  | |_) | |_| |   | | | | |_) | | |  __/ | | (_| |
|___\___/    |_|\___||___/\__| |____/ \__, |   |_| |_|_.__/|_|  \___|_|_|\__,_|
                                      |___/                                    
This test program will generate data and test for 10 times, then take the average for the final result

Start test 1.5e6 random long long int and 1.5e6 random double input and output

freopen + scanf + printf 0.935sec
ifstream + ofstream 0.791sec
freopen + cin + cout 0.787sec

Start test 3e6 random long long int input and output

freopen + scanf + printf 0.812sec
ifstream + ofstream 0.200sec
freopen + cin + cout 0.517sec
fastio + cstdio 0.489sec
fastio + fstream 0.698sec
```