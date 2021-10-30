#include "../src/general.hpp"
#include "../src/string-hash.hpp"

int main() {
    int n = 100, q = 1000;
    string str;
    for (int i = 0; i < n; ++i) {
        str.push_back(rand() % 26 + 'a');
    }
    StringHash hsh(str);
    for (int i = 0; i < q; ++i) {
        int st = rand() % n;
        int len = rand() % (n - st) + 1;
        string str2 = str.substr(st, len);
        StringHash hsh2(str2);
        assert(hsh.query(st, st+len-1) == hsh2.hsh.back());
    }
}