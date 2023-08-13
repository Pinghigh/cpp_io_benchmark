#include <cstdio>
#include <iostream>
namespace IO {
    const int sz = 1 << 22;
    FILE *in = fopen("data.in", "r"), *out = fopen("res.out", "w");
    char a[sz + 5], b[sz + 5], *p1 = a, *p2 = a, *t = b, p[105];
    inline char gc() {
        return p1 == p2 ? (p2 = (p1 = a) + fread(a, 1, sz, in), p1 == p2 ? EOF : *p1++) : *p1++;
    }
    template <class T>
    void gi(T& x) {
        x = 0;
        static bool f;
        f = false;
        static char c;
        c = gc();
        for (; c < '0' || c > '9'; c = gc())
            if (c == '-') f = true;
        for (; c >= '0' && c <= '9'; c = gc())
            x = x * 10 + (c ^ 48);
        if (f) x = -x;
    }
    inline void flush() {
        fwrite(b, 1, t - b, out), t = b;
    }
    inline void pc(char x) {
        *t++ = x;
        if (t - b == sz) flush();
    }
    template <class T>
    void pi(T x, char c = '\n') {
        if (x == 0)
            pc('0');
        else if (x < 0)
            pc('-'), x = -x;
        int t = 0;
        for (; x; x /= 10)
            p[++t] = x % 10 ^ '0';
        for (; t; --t)
            pc(p[t]);
        pc(c);
    }
    struct F {
        ~F() {
            flush();
            fclose(in);
            fclose(out);
        }
    } f;
}  // namespace IO
using IO::gi;
using IO::pi;

using i64 = long long;

i64 a, b;

int main() {
    gi(a);

    while (a--) {
        gi(b);
        pi(b, ' ');
    }

    return 0;
}
