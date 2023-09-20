读入输出测试

测试 1：300000 个随机双精度浮点数  
测试 2：150000 个随机双精度浮点数与 150000 个随机 64 位有符号整数  
测试 3：300000 个随机 64 位有符号整数  
测试 4：300000 个随机 64 位无符号整数

depends: `g++`, `fish`

安装依赖：
Ubuntu(NOI Linux)/Debian: `sudo apt update && sudo apt install fish`  
Fedora/RHEL/CentOS: `sudo dnf update && sudo dnf install fish`  
Arch Linux/Manjaro: `sudo pacman -Sy fish`  
OpenSUSE: `sudo zypper install fish`

测试方法：
```
chmod +x start.sh
./start.sh
```

默认 10 次取平均数


硬件：
```
╔═════════ Hardware Information ═════════╗
  HST => Windows Subsystem for Linux - Arch (2.0.0.0)
  CPU => Intel(R) Core(TM) i5-10400 (12) @ 2.903998 GHz
╟───────── Software Information ─────────╢
  SYS => Arch Linux x86_64
  SHE => fish 3.6.1
  FON => monospace (15.0pt)
╚════════════════════════════════════════╝
```
以防磁盘 IO 对文件 IO 影响过大，给出自己的磁盘信息：ZHITAI SC001 Active-512GB-B，没有 IO 调度器（`none`）

测试结果

```
This test program will generate data and test for 5 times, then take the average for the final result

Start test 3e6 random double input and output

freopen + scanf + printf 1.279sec
ifstream + ofstream 1.436sec
freopen + cin + cout 1.468sec

Start test 1.5e6 random long long int and 1.5e6 random double input and output

freopen + scanf + printf 1.227sec
ifstream + ofstream 1.281sec
freopen + cin + cout 1.227sec

Start test 3e6 random long long int input and output

freopen + scanf + printf 0.615sec
ifstream + ofstream 0.583sec
freopen + cin + cout 0.593sec
fastio + cstdio 0.576sec
fastio + fstream 1.022sec
fread + fwrite 0.236sec

Start test 3e6 random unsigned long long int input and output

freopen + scanf + printf 0.603sec
ifstream + ofstream 0.580sec
freopen + cin + cout 0.586sec
fastio + cstdio 0.584sec
fastio + fstream 1.019sec
fread + fwrite 0.245sec
```

合理选择 IO 方式！

- `freopen + scanf + printf` 顾名思义。
- `freopen + cin + cout` 去了流同步和绑定，具体看代码。
- `ifstream + ofstream` 直接开的两个对应类型，不需要加任何优化（实测 `std::ios::sync_with_stdio(false)` 对其无影响）
- `fastio + cstdio` 传统快读，使用 `getchar_unlocked` 和 `putchar_unlocked`。貌似使用普通 `getchar` 和 `putchar` 耗时至少是 `unlocked` 的 1.5 倍，之前同学改用 `unlocked` 时间砍到 1/2。
- `fastio + fstream` 之前在洛谷有人说用 `fstream` 的 `get` 和 `put` 读写字符非常快，于是用 `istream::get` 和 `ostream::get` 实现了一个传统快读。

由于小数快读和 ~~`fread` `fwrite` 快读快写~~实现难度较大，对比赛没有太大帮助，就没测~~我不会~~

changelog:

- 2023-8-13: ~~模拟赛搞到了河北领袖 Hs_Black 提供的 fread/fwrite 程序~~ 用自己笔记本（R7-4800H）重测了一发。并添加了 3e6 纯双精度浮点数的测试。  
  ~~相应的，`int/fread.cxx` 不使用 GPLv3 授权（等我自己实现一份），请勿用于其他项目~~。

- 2023-9-20 自己实现了 fread/fwrite 程序，重测。
