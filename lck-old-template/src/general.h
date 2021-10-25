#pragma once
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define vec vector
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};

template <typename T>
T sgn(const T& x) {
  return x < 0 ? -1 : 1;
}
template <typename T>
T div(T& a, T& b) { // floored division
  return a / b - ((a ^ b) < 0 && a % b);
}
