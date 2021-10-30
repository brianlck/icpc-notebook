#include "general.hpp"
#include "euclid.hpp"

template<ll MOD = 1000000007>
struct Mod {
  ll x;
  Mod(ll x) : x(x % MOD) {}
  Mod operator+(Mod b) { return Mod(x + b.x); }
  Mod operator-(Mod b) { return Mod(x - b.x + MOD); }
  Mod operator*(Mod b) { return Mod(x * b.x); }
  Mod operator/(Mod b) { return *this * invert(b); }
  static Mod invert(Mod a) {
    ll x, y, g = euclid(a.x, MOD, x, y);
    return Mod((x + MOD) % MOD);
  }
  Mod operator^(ll p) {
    if (!p) return Mod(1);
    Mod r = *this ^ (p / 2);
    r = r * r;
    return p & 1 ? *this * r : r;
  }
  bool operator==(const Mod rhs) {
    return x == rhs.x;
  }
};