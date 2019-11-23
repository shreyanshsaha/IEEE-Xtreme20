#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
/*
Equal

*/

int main() {
  long long k, j, n, combination;
  long long ans, count = -1;
  cin >> k >> j;

  if ((k == 0 || j == 0) || (k == 1 && j == 1)) {
    count = 0;
  } else if (k == 1 || j == 1) {
    count = 1;
  } else {
    if (abs(k - j) <= 2) {
      count = floor((k + j) / 3);
    } else {
			count = min((long long)floor(max(k, j)/2), min(k,j));
    }
  }
  cout << count;

  return 0;
}