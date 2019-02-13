#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

typedef __int128 ll;

ll quick_pow (ll x, ll p, ll MOD = -1) {
    ll ans = 1;
    while (p) {
        if (p & 1) {
            ans *= x;
            if (MOD > 0)
                ans %= MOD;
        }
        x *= x;
        if (MOD > 0)
            x %= MOD;
        p >>= 1;
    }
    return ans;
}

ll log_2 (ll x) {
    ll l = 0, r = 127, mid, ans = -1, bs = 1;
    while (l <= r) {
        mid = l + r >> 1;
        if (((ll)bs << (ll)mid) < x)
            l = mid + bs;
        else
            ans = mid, r = mid - bs;
    }
    return ans;
}
