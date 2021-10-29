/*
  2018-2019 ACM-ICPC, Asia Seoul Regional Contest
  Task K
  https://codeforces.com/gym/304671
*/

#include "../src/general.hpp"
#include "../src/two-sat.hpp"

int main() {
    int k, n; cin >> k >> n;
    TwoSat ts(k);
    for (int i = 1; i <= n; ++i) {
        int a, c, e;
        char b, d, f;
        cin >> a >> b >> c >> d >> e >> f;
        a--; c--; e--;
        if (b == 'B') a = ~a;
        if (d == 'B') c = ~c;
        if (f == 'B') e = ~e;
        ts.either(a, c);
        ts.either(a, e);
        ts.either(c, e);
    }
    if (!ts.run()) {
        cout << -1 << endl;
        return 0;
    }
    for (auto x : ts.values) {
        cout << (x ? 'B' : 'R');
    }
    cout << endl;
}