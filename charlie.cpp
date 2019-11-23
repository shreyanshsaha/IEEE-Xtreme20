#include <algorithm>
#include <iostream>
#include <vector>

int dp[10][100];

using namespace std;
long long b;
int n;

long long getMaxPrice(long long currB, int* options,
                      vector<vector<long long> > componentPrice, int i, int j) {
  // cout << i << " " << j << " " << currB << endl;
	// if(dp[i][j]!=-1) return dp[i][j];
  if (i > n || j > options[i]) {
    return 0;
  }
	// cout<<currB<<" "<<i<<" "<<j<<endl;
  if (i == n) {
    if (currB + componentPrice[i][j] > b) return 0;
    // cout << "LAST: " << currB + componentPrice[i][j] << endl;
    return currB + componentPrice[i][j];
  }

  int val = max(getMaxPrice(currB, options, componentPrice, i, j + 1),
             getMaxPrice(componentPrice[i][j] + currB, options, componentPrice,
                         i + 1, 0));
	dp[i][j] = val;
	return dp[i][j];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int numTestCases;
  long long maxPrice;

  cin >> numTestCases;
  while (numTestCases--) {
		for(int i=0; i<10; i++){
			for(int j=0; j<100; j++){
				dp[i][j]=-1;
			}
		}
    cin >> b;  // Max amount
    cin >> n;  // # Components

    int options[n];
    vector<vector<long long> > componentPrice(n, vector<long long>(100, 0));

    // options for each component
    for (int i = 0; i < n; i++) cin >> options[i];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < options[i]; j++) {
        cin >> componentPrice[i][j];
      }
    }

    n--;
    for (int i = 0; i < n; i++) options[i]--;
    maxPrice = 0;

    maxPrice = getMaxPrice(0, options, componentPrice, 0, 0);

    cout << maxPrice << endl;
  }
}

/*
1
50
4
3 2 1 2
15 10 49
11 17
10
13 23
*/