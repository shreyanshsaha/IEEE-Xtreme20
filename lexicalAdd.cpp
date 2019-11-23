#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<long long> arr) {
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
}

// Driver program
int main() {
  long long n, a, b;
  // long long tempN;
  long long count;
  cin >> n >> a >> b;

  if (a > b) {
    cout << "NO\n";
    return 0;
  }
  // TODO: Add boundry condition when b divides n, then that is the answer
  if (n % b == 0) {
    cout << "YES\n";
    for (int i = 0; i < n / b; i++) cout << b << " ";
    return 0;
  }

  long long q = ceilf(n / b) + 1;
  // cout<<b*q<<endl;

  vector<long long> arr(q, b);

  // cout << tempN << endl;
  // printArr(arr);

  long long currentSum = q * b;

  // Reduce until sum is n
  long long i = 0;
  long long limit = 0;

  while (currentSum > n) {
    limit++;
    if (arr[i % arr.size()] > a) {
      limit = 0;
      long long diff = min(abs(n - currentSum), (arr[i % arr.size()] - a));
      arr[i % arr.size()] -= diff;
      currentSum -= diff;
    }
    i++;
    if (limit > arr.size()) break;
  }

  // cout<<"SUM: "<<currentSum<<endl;
  // Check if the sum is reduced,
  // i.e is it possible to get the array or no
  if (currentSum > n) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";

  // i think the array is already sorted,
  // but just to be safe
  sort(arr.begin(), arr.end());
  // printArr(arr);

  // Reduce lexicographical order
  long long j = distance(arr.begin(), max_element(arr.begin(), arr.end()));
  if (j == 0) j = arr.size() - 1;
  i = 0;
  while (i<arr.size() && arr[i] == a) i++;
  while (arr[j] == b) j--;
  i = max((long long)0, i - 1);
  j = min((long long)arr.size() - 1, j + 1);

  // cout << "I: " << i << ", J:" << j << endl;
  while (i < j && i<arr.size() && j<arr.size()) {
    long long cost = min((arr[i] - a), (b - arr[j]));
    while(j<arr.size() && cost == 0 && arr[j] == b) {
      j--;
      // continue;
    }
    while(i<arr.size() && cost == 0 && arr[i] == a) {
      i++;
      // continue;
    }
    if(i>=j || i>arr.size()-1 || j>arr.size()-1) break;
    // cout << "COST: " << cost << " " << i << " " << j << endl;
    arr[i] -= cost;
    arr[j] += cost;
    // i++;
    j--;
  }

  sort(arr.begin(), arr.end());
  printArr(arr);
  return 0;
}
