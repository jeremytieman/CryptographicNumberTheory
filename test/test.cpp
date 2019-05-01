#include <iostream>

#include "NumberTheory.hpp"

void main()
{
  std::cout << "GCD of 2017 and 1024: " << CodexMachina::gcd(2017, 1024) << "\n";
  std::cout << "GCD of 1071 and 462: " << CodexMachina::gcd(1071, 462) << "\n";
  std::cout << "\n";

  std::cout << "Inverse of 7 mod 11: " << CodexMachina::inverse(7, 11) << "\n";
  std::cout << "Inverse of 2000 mod 2017: " << CodexMachina::inverse(2000, 2017) << "\n";
  std::cout << "Inverse of 14019 mod 1247290: " << CodexMachina::inverse(14019, 1247290) << "\n";
  std::cout << "\n";

  std::cout << "Prime test 817: " << CodexMachina::primeTest(817) << "\n";
  std::cout << "Prime test 679: " << CodexMachina::primeTest(679) << "\n";
  std::cout << "Prime test 563: " << CodexMachina::primeTest(563) << "\n";
  std::cout << "Prime test 423: " << CodexMachina::primeTest(423) << "\n";
  std::cout << "\n";

  std::cout << "Prime factorization of 6469693230: ";
  auto pf = CodexMachina::primeFactorization(6469693230U);
  for (auto f : pf) std::cout << f << " ";
  std::cout << "\n";
  std::cout << "\n";

  std::cout << "GCD of 3187869 and 2739621: " << CodexMachina::gcd(3187869, 2739621) << "\n";
  std::cout << "\n";

  std::cout << "Are 153739 and 657 relatively prime: " << CodexMachina::relativelyPrimeTest(153739, 657) << "\n";
  std::cout << "Inverse of 153739 mod 657: " << CodexMachina::inverse(153739, 657) << "\n";
  std::cout << "Are 153737 and 657 relatively prime: " << CodexMachina::relativelyPrimeTest(153737, 657) << "\n";
  std::cout << "Inverse of 153737 mod 657: " << CodexMachina::inverse(153737, 657) << "\n";
  std::cout << "Are 3271 and 657 relatively prime: " << CodexMachina::relativelyPrimeTest(3271, 657) << "\n";
  std::cout << "Inverse of 3271 mod 657: " << CodexMachina::inverse(3271, 657) << "\n";
  std::cout << "Are 47 and 657 relatively prime: " << CodexMachina::relativelyPrimeTest(47, 657) << "\n";
  std::cout << "Inverse of 47 mod 657: " << CodexMachina::inverse(47, 657) << "\n";
  std::cout << "\n";

  std::cout << "Inverse of 153739 mod 65491: " << CodexMachina::inverse(159437, 65491) << "\n";
  std::cout << "\n";

  std::cout << "Are 819 and 990 relatively prime: " << CodexMachina::relativelyPrimeTest(819, 990) << "\n";
  std::cout << "Are 527 and 612 relatively prime: " << CodexMachina::relativelyPrimeTest(527, 612) << "\n";
  std::cout << "Are 91 and 343 relatively prime: " << CodexMachina::relativelyPrimeTest(91, 343) << "\n";
  std::cout << "Are 796 and 982 relatively prime: " << CodexMachina::relativelyPrimeTest(796, 982) << "\n";
  std::cout << "\n";

  std::cout << "GCD of 1071 and 462: " << CodexMachina::gcd(930, 992) << "\n";
  std::cout << "\n";

  std::cout << "Are -4 and 4 congruent: " << CodexMachina::congruenceTest(-4, 4, 13) << "\n";
  std::cout << "Are -17 and 9 congruent: " << CodexMachina::congruenceTest(-17, 9, 13) << "\n";
  std::cout << "Are 3 and 113 congruent: " << CodexMachina::congruenceTest(3, 113, 13) << "\n";
  std::cout << "Are 21001 and 21013 congruent: " << CodexMachina::congruenceTest(21001, 21013, 13) << "\n";
  std::cout << "\n";

  std::cout << "Are 16 and 47 relatively prime: " << CodexMachina::relativelyPrimeTest(16, 47) << "\n";
  std::cout << "Inverse of 16 mod 47: " << CodexMachina::inverse(16, 47) << "\n";
  std::cout << "\n";

  std::cout << "Are 219 and 220 relatively prime: " << CodexMachina::relativelyPrimeTest(219, 220) << "\n";
  std::cout << "Inverse of 219 mod 220: " << CodexMachina::inverse(219, 220) << "\n";
  std::cout << "\n";

  return;
}