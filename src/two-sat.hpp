#include "general.hpp"
#include "tarjan.hpp"

struct TwoSat : public SCC {
    int n;
    TwoSat(int n) : n(n), SCC(2*n, vector<vector<int>>(2*n)) {
        values.resize(n);
    }
    int get_actual(int x) {
        return x < 0 ? ((~x) << 1 | 1) : (x << 1);
    }
    /*
       @param 
    */
    void either(int x, int y) {
        x = get_actual(x);
        y = get_actual(y);
        gr[x ^ 1].push_back(y);
        gr[y ^ 1].push_back(x);
    }
    void setValue(int x) { either(x, x); }
    bool run() {
        SCC::run();
        for (int i = 0; i < n; ++i) {
            if (id[i << 1] == id[i << 1 | 1]) return false;
            values[i] = id[i << 1] < id[i << 1 | 1];
        }
        return true;
    }
    vector<bool> values;
};