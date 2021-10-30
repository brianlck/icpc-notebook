#include "general.hpp"
#include "modint.hpp"


template<ll BASE = 113, ll MOD = 1000000007>
struct StringHash {
    using HashMod = Mod<MOD>;

    string_view str;
    size_t len;
    vector<HashMod> hsh;
    vector<HashMod> inv;
    HashMod base;

    StringHash(string_view str) : str(str), base(1) {
        len = str.length();
        hsh.assign(len, 0);
        inv.assign(len, 0);
        for (int i = 0; i < len; ++i) {
            hsh[i] = (i == 0 ? 0 : hsh[i-1]) + 
                    HashMod(str[i]) * base;
            inv[i] = HashMod::invert(base);
            base = base * BASE;
        }
    }

    HashMod query(int l, int r) {
        return (hsh[r] - (l == 0 ? 0 : hsh[l-1])) * inv[l]; 
    }
};