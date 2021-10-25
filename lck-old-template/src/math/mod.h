#pragma once
#include "../general.h"
#include "euclid.h"

struct Mod {
  ll x;
  Mod(ll x) : x(x % MOD) {}
  Mod operator+(Mod b) { return Mod(x + b.x); }
  Mod operator-(Mod b) { return Mod(x - b.x + MOD); }
  Mod operator*(Mod b) { return Mod(x * b.x); }
  Mod operator/(Mod b) { return *this * invert(b); }
  Mod invert(Mod a) {
    ll x, y, g = euclid(a.x, MOD, x, y);
    return Mod((x + MOD) % MOD);
  }
  Mod operator^(ll p) {
    if (!p) return Mod(1);
    Mod r = *this ^ (p / 2);
    r = r * r;
    return p & 1 ? *this * r : r;
  }
};