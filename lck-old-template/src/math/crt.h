#pragma once

#include "../general.h"
#include "euclid.h"

#define CRT_H

ll crt(ll a, ll m, ll b, ll n) {
  if (n > m) swap(a, b), swap(m, n);
  ll x, y, g = euclid(m, n, x, y);
  x = (b - a) % n * x % n / g * m + a;
  return x < 0 ? x + m * n / g : x;
}