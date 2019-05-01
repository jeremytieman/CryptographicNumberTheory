#include <vector>

namespace CodexMachina
{
  auto modulo(const long long x, const long long modulus)
  {
    return x - (modulus * (x / modulus));
  }

  auto gcd(const unsigned long long x, const unsigned long long y) -> unsigned long long
  {
    if (y > x) return gcd(y, x);
    if (y == 1) return 1;
    if (y == 0) return x;
    return gcd(y, modulo(x, y));
  }

  // m, x
  auto inverse(const long long x, const unsigned long long modulus) -> unsigned long long
  {
    std::vector<long long> r;
    r.push_back(modulus);
    r.push_back(x);
    std::vector<long long> a;
    a.push_back(0);
    a.push_back(1);

    while (r[r.size() - 1] != 0)
    {
      auto r1 = r[r.size() - 1];
      auto r2 = r[r.size() - 2];
      r.push_back(modulo(r2, r1));
      auto qn = (r2 / r1);
      auto a1 = a[a.size() - 1];
      auto a2 = a[a.size() - 2];
      auto subResult = a2 - (qn * a1);
      auto modResult = modulo(subResult, modulus);
      a.push_back(modResult);
    }

    if (r[r.size() - 2] != 1) return 0;
    auto result = a[a.size() - 2];
    return (result < 0) ? modulus + result : result;
  }

  auto primeTest(const unsigned long long x)
  {
    if (x == 0) return false;
    if (x == 1) return false;
    if (x == 2) return true;
    if (modulo(x, 2) == 0) return false;

    for (unsigned long long i = 3; i <= (x / 2) + 1; i += 2)
    {
      if (gcd(x, i) > 1) return false;
    }

    return true;
  }

  auto relativelyPrimeTest(const unsigned long long x, const unsigned long long y)
  {
    return gcd(x, y) == 1;
  }

  auto primeFactorization(const unsigned long long x)
  {
    if ((x == 0) || (x == 1)) return std::vector<unsigned long long>{};
    auto result = std::vector<unsigned long long>{};
    auto curValue = x;

    for (unsigned long long i = 2; (i <= (x / 2) + 1) && (curValue != 1); i += 2)
    {
      if (!primeTest(i)) continue;

      while (modulo(curValue, i) == 0)
      {
        result.push_back(i);
        curValue /= i;
      }

      if (i == 2) --i;
    }

    return result;
  }

  auto congruenceTest(long long x, long long y, const unsigned long long modulus)
  {
    if (x < 0) x = 0 - x;
    if (y < 0) y = 0 - y;
    return modulo((x + y), modulus) == 0;
  }
}