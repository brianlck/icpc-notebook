#pragma once
#include "general.h"

template<typename T>
void make_unique(T &v) {
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
} 

template<typename T>
void chkmin(T &lhs, T rhs) {
    lhs = min(lhs, rhs);
}

template<typename T>
vec<vec<T>> exhaust(T mn, T mx, int n, bool unique = false) {
    vec<vec<T>> res;
    unordered_set<T> used;
    vec<T> cur;

    function<void(int)> dfs =
        [&] (int len) {
            if (len == n) {
                res.push_back(cur);
                return;
            }
            rep(i, mn, mx+1) {
                if (unique && used.count(i)) continue;
                cur.push_back(i);
                if (unique) used.insert(i);
                dfs(len + 1);
                if (unique) used.erase(i);
                cur.pop_back();
            }            
        };
    dfs(0);
    return res;
}

template<typename T>
vec<vec<T>> exhaust(vec<T> alphabets, int n, bool unique = false) {
    vec<vec<T>> res;
    unordered_set<T> used;
    vec<T> cur;

    function<void(int)> dfs =
        [&] (int len) {
            if (len == n) {
                res.push_back(cur);
                return;
            }
            for (const auto i : alphabets) {
                if (unique && used.count(i)) continue;
                cur.push_back(i);
                if (unique) used.insert(i);
                dfs(len + 1);
                if (unique) used.erase(i);
                cur.pop_back();
            }            
        };
    dfs(0);
    return res;
}


template<typename T>
void chkmax(T &lhs, T rhs) {
    lhs = max(lhs, rhs);
}
