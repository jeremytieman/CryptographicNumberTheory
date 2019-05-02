#include <tuple>
#include <vector>

namespace CodexMachina
{
  // Not mine
  /*
  int modInverse(int a, int m)
  {
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1) return 0;

    while (a > 1)
    {
      // q is quotient 
      int q = a / m;
      int t = m;

      // m is remainder now, process same as 
      // Euclid's algo 
      m = a % m, a = t;
      t = y;

      // Update y and x 
      y = x - q * y;
      x = t;
    }

    // Make x positive 
    if (x < 0) x += m0;
    return x;
  }
  */

  auto gcd(const unsigned long long x, const unsigned long long y) -> unsigned long long
  {
    if (y == 0) return x;
    return gcd(y, x % y);
  }

  // Not mine
  /*
  auto extended_gcd(int a, int b) -> std::tuple<int, int, int>
  {
    if (a == 0) return std::make_tuple(b, 0, 1);
    int gcd, x, y;
    std::tie(gcd, x, y) = extended_gcd(b % a, a);
    return std::make_tuple(gcd, (y - (b / a) * x), x);
  }
  */

  auto inverse(const long long x, const long long modulus) -> unsigned long long
  {
    auto r2 = modulus;
    auto r1 = x;
    std::vector<long long> a;
    auto a2 = 0LL;
    auto a1 = 1LL;

    while (r1 != 0)
    {
      auto qn = (r2 / r1);
      auto oldR2 = r2;
      r2 = r1;
      r1 = oldR2 % r1;
      auto subResult = a2 - (qn * a1);
      a2 = a1;
      a1 = subResult % modulus;
    }

    if (r2 != 1) return 0;
    auto result = a2;
    return (result < 0) ? modulus + result : result;
  }

  auto primeTest(const long long x)
  {
    if (x == 0) return false;
    if (x == 1) return false;
    if (x == 2) return true;
    if ((x % 2) == 0) return false;

    for (long long i = 3; i <= (x / 2) + 1; i += 2)
    {
      if (gcd(x, i) > 1) return false;
    }

    return true;
  }

  auto relativelyPrimeTest(const unsigned long long x, const unsigned long long y)
  {
    return gcd(x, y) == 1;
  }

  auto primeFactorization(const long long x)
  {
    if ((x == 0) || (x == 1)) return std::vector<unsigned long long>{};
    auto result = std::vector<unsigned long long>{};
    auto curValue = x;

    for (long long i = 2; (i <= (x / 2) + 1) && (curValue != 1); i += 2)
    {
      if (!primeTest(i)) continue;

      while ((curValue % i) == 0)
      {
        result.push_back(i);
        curValue /= i;
      }

      if (i == 2) --i;
    }

    return result;
  }

  auto congruenceTest(long long x, long long y, const long long modulus)
  {
    if (x < 0) x = 0 - x;
    if (y < 0) y = 0 - y;
    return ((x + y) % modulus) == 0;
  }
}