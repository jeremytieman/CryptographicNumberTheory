#include <vector>

namespace CodexMachina
{
  auto gcd(unsigned long x, unsigned long y) -> unsigned long
  {
    if (y > x) return gcd(y, x);
    if (y == 1) return 1;
    if (y == 0) return x;
    return gcd(y, x % y);
  }

  // m, x
  auto extended_euclidean_algorithm(unsigned long x, unsigned long y) -> unsigned long
  {
    std::vector<long> r;
    r.push_back(x);
    r.push_back(y);
    std::vector<long> a;
    a.push_back(0);
    a.push_back(1);
    std::vector<long> q;
    q.push_back(0);
    q.push_back(0);

    while (r[r.size() - 1] != 0)
    {
      auto r1 = r[r.size() - 1];
      auto r2 = r[r.size() - 2];
      r.push_back(r2 % r1);
      q.push_back(r2 / r1);
      auto a1 = r[r.size() - 1];
      auto a2 = r[r.size() - 2];
      a.push_back((a2 - (q[q.size() - 1] * a1)) % x);
    }

    if (r[r.size() - 2] != 1) return 0;
    return a[a.size() - 2];
  }
}