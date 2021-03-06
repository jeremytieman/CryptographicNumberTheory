#include <numeric>
#include <set>
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

  auto modularExponentiation(long long base, long long exponent, long long modulus)
  {
    auto modBase = base % modulus;
    auto result = 1LL;

    while (exponent > 0)
    {
      if ((exponent % 2) == 1)
      {
        result *= modBase;
        result %= modulus;
      }

      exponent >>= 1;
      modBase *= modBase;
      modBase %= modulus;
    }

    return result;
  }

  auto totient(long long modulus)
  {
    auto result = std::set<long long>{};

    for (auto i = 0LL; i < modulus; ++i)
    {
      if (gcd(i, modulus) == 1) result.insert(i);
    }

    return result;
  }

  auto sieveOfEratosthenes(const long long n)
  {
    auto numbers = std::vector<long long>(n - 1);
    std::iota(std::begin(numbers), std::end(numbers), 2);
    auto prime = std::vector<bool>(n - 1, false);

    for (auto i = 0; i < numbers.size(); ++i)
    {
      if (!prime[i]) continue;
      const auto number = numbers[i];
      const auto start = number * number;
      if (start > n) break;
      for (auto j = start; j <= n; j += number) prime[j] = false;
    }

    auto result = std::vector<long long>{};

    for (auto i = 0; i < numbers.size(); ++i)
    {
      if (!prime[i]) continue;
      result.push_back(numbers[i]);
    }

    return result;
  }

  auto fermatPrimalityTest(const long long n, size_t k)
  {
    for (size_t i = 0; i < k; ++i)
    {
      // Replace 6 with random value 1 < a < n - 2
      auto a = 6;
      auto val = a ^ (n - 1);
      auto mod = val % n;
      if (mod != 1) return false;
    }

    return true;
  }

  auto millerRabinPrimalityTest(const long long n)
  {
    // Replace 6 with random value 1 < a < n - 2
    const auto a = 6;
    auto d = n - 1;
    auto s = 0;

    while ((d % 2LL) == 0)
    {
      ++s;
      d /= 2LL;
    }

    auto val = a ^ d;

    for (int j = 0; j < s; ++j)
    {
      const auto mod = val % n;
      if (mod == -1) return true;
      if ((j == 0) && (mod == 1)) return true;
      val *= val;
    }

    return false;
  }
}