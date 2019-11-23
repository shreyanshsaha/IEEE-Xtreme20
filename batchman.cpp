
#include <bits/stdc++.h>
using namespace std;

// n is size of arr[] and m is sizeof gcd[]
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int solve(vector<int> &A) {
  bool a[10000];
  int i, j, n = A.size(), s = 0, prev, f;
  for (i = 1; i <= 10000; i++) a[i] = false;
  for (i = 1; i <= 1000; i++) {
    if (a[i]) {
      s++;
      continue;
    }
    f = false;
    prev = -1;
    for (j = 0; j < n; j++) {
      if (A[j] % i == 0) {
        if (f == false) {
          prev = A[j];
          f = true;
        } else
          prev = __gcd(A[j], prev);
      }
    }
    if (prev == i)
      s++;
    else if (prev)
      a[prev] = true;
  }
  return s;
}

// Driver program
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k, temp;
  cin >> n >> k;
  // vector<int> arr(n);
  set<int> arr;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    arr.insert(temp);
  }

  if (k <= 1) {
    cout << arr.size();
    return 0;
  }
  vector<int> arr1(arr.begin(), arr.end());
  cout << solve(arr1);
  return 0;
}

// int main()
// {
//   ios::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);

// 	int n,k;
// 	cin>>n>>k;

// 	int temp;

// 	set <int> arr;
// 	set <int>::iterator it,jt;

// 	set <int> gcdSet;
// 	set <int>::iterator itr;

// 	for(int i = 0; i<=n; i++){
// 	  cin>>temp;
// 	  arr.insert(temp);
// 	  gcdSet.insert(temp);
// 	}
// if(k<=1){
//   cout<<gcdSet.size();
//  // return 0;
// }
// 	for(it=arr.begin(); it!= arr.end();){
// 	  for(jt=++it; jt!= arr.end();jt++){
// 	    gcdSet.insert(gcd(*it,*jt));

// 	  }
// 	}
