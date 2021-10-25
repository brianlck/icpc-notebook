#pragma once
#include "general.hpp"

template<typename T>
vector<vector<T>> exhaust(T mn, T mx, int n, bool unique = false) {
    vector<vector<T>> res;
    unordered_set<T> used;
    vector<T> cur;

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
vector<vector<T>> exhaust(vector<T> alphabets, int n, bool unique = false) {
    vector<vector<T>> res;
    unordered_set<T> used;
    vector<T> cur;

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