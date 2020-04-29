#include <iostream>
#include <deque>
#include <string>
#include <cmath>

using namespace std;

typedef long long ull;

namespace
{
typedef deque<ull> bigint;
const ull base = 9;
const ull base10 = pow(10, base);

class BigInteger
{
public:
    static void print(bigint a)
    {
        for (ull i = 0; i < a.size(); ++i)
        {
            int ndigits = a[i] > 0 ? (int) log10 ((double) a[i]) + 1 : 1;
            if (ndigits < base && i != 0)
            {
                for (int j = 0; j < base - ndigits; ++j)
                    cout << 0;
            }
            cout << a[i];
        }
        cout << endl;
    }
 
    static bigint str_to_bigint(string str)
    {
        bigint res;
        for (ull i = 0; i < str.length(); i += base)
        {
            ull shift = i + base;
            if (shift > str.length()) shift -= shift - str.length();
            string curr_digit_str(str.end() - shift, str.end() - i);
            res.push_front(atoi(curr_digit_str.c_str()));
        }
        return res;
    }
 
    static bigint mul(bigint a, bigint b)
    {
        ull cnt = 0;
        bigint res;
        for (ull i = b.size() - 1; i >= 0; --i)
        {
            bigint r = mul(a, b[i]);
            for (ull i = 0; i < cnt; ++i) { r.push_back(0); }
            res = add(res, r);
            cnt++;
        }
 
        return res;
    }

    static bigint mul(bigint a, ull b)
    {
        bigint res;
        ull mem = 0;
        for (ull i = a.size() - 1; i >= 0; --i)
        {
            ull r = a[i] * b + mem;
            res.push_front(r % base10);
            mem = (r - r % base10) / base10;
        }
        if (mem != 0) res.push_front(mem); 
 
        return res;
    }
 
    static bigint add(bigint a, bigint b)
    {
        if (a.size() < b.size()) while (a.size() != b.size()) { a.push_front(0); }
        else if (a.size() > b.size()) while (a.size() != b.size()) { b.push_front(0); }
 
        bigint res;
        ull mem = 0;
        for (ull i = a.size() - 1; i >= 0; --i)
        {
            ull r = a[i] + b[i] + mem;
            res.push_front(r % base10);
            mem = (r - r % base10) / base10;
        }
        if (mem != 0) res.push_front(mem);
 
        return res;
    }
};

}

ull a, b;
bigint biga, bigb;

bigint modified_fib(ull n)
{
    for (int i = 0; i < n - 2; ++i)
    {
        bigint r = BigInteger::add(BigInteger::mul(bigb, bigb), biga);
        biga = bigb;
        bigb = r;
    }

    return bigb;
}

int main()
{
    cin >> a >> b;

    biga.push_back(a);
    bigb.push_back(b);

    ull N;
    cin >> N;

    bigint res = modified_fib(N);

    BigInteger::print(res);

    return 0;
}
