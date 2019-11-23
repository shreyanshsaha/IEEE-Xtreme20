#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int minSwaps(vector<int> arr, int n) {
  // Create an array of pairs where first
  // element is array element and second element
  // is position of first element
  pair<int, int> arrPos[n];
  for (int i = 0; i < n; i++) {
    arrPos[i].first = arr[i];
    arrPos[i].second = i;
  }

  // Sort the array by array element values to
  // get right position of every element as second
  // element of pair.
  sort(arrPos, arrPos + n);

  // To keep track of visited elements. Initialize
  // all elements as not visited or false.
  vector<bool> vis(n, false);

  // Initialize result
  int ans = 0;

  // Traverse array elements
  for (int i = 0; i < n; i++) {
    // already swapped and corrected or
    // already present at correct pos
    if (vis[i] || arrPos[i].second == i) continue;

    // find out the number of  node in
    // this cycle and add in ans
    int cycle_size = 0;
    int j = i;
    while (!vis[j]) {
      vis[j] = 1;

      // move to next node
      j = arrPos[j].second;
      cycle_size++;
    }

    // Update answer by adding current cycle.
    if (cycle_size > 0) {
      ans += (cycle_size - 1);
    }
  }

  // Return result
  return ans;
}

bool isGrouped(string str) {
  int n = str.length(), i;
  set<char> st;
  st.insert(str[0]);
  for (i = 1; i < n; i++) {
    // If similar chars side by side, continue
    if (str[i] == str[i - 1]) continue;

    if (st.find(str[i]) != st.end()) return false;

    st.insert(str[i]);
  }
  // cout<<str<<" is grouped\n";
  return true;
}

int numSwaps(string str, char* strArr) {
  int count = 0;
  int i = 0;
  bool swapped = true;
  vector<int> arr(str.length());
  char index = '1';
  char revIndex[4] = {'\0'};
  // int i = 0;
  string newString = "";
  if (!isGrouped(str)) {
    // Convert to new index
    for (int i = 0; i < str.length(); i++) {
      if (strArr[str[i] - 'A'] == '\0') {
        strArr[str[i] - 'A'] = (char)index;
        revIndex[index - '1'] = str[i];
        index = (char)(index + 1);
      }
      arr[i] = strArr[str[i] - 'A'];
    }
    // for (char i : arr) {
    //   cout << i << " ";
    // }
    // cout << endl;

    // sort(arr.begin(), arr.end());
    // for (char i : arr) {
    //   cout << i << " ";
    // }
    // cout << endl;

    for (int i = 0; i < str.length(); i++) {
      newString += revIndex[arr[i] - '1'];
    }
    // cout << newString << endl;
    int minCount = INT_MAX;
    string minString = newString;
    for (int i = 0; i < str.length(); i++) {
      count = 0;
      for (int i = 0; i < str.length(); i++) {
        if (str[i] != newString[i]) {
          count++;
        }
      }
      rotate(newString.begin(), newString.begin() + 1, newString.end());
      rotate(arr.begin(), arr.begin() + 1, arr.end());
      if (count < minCount) {
        minCount = count;
        minString = newString;
      }
      // minCount = min(minCount, count);
    }
    cout << minSwaps(arr, arr.size()) << endl;
    return minCount;
  }
  cout << 0 << endl;
  return 0;
}

int main() {
  int numTestCases;
  string str;
  cin >> numTestCases;
  while (numTestCases--) {
    cin >> str;
    char strArr[4] = {'\0'};
    while (str[0] == str[str.length() - 1]) {
      rotate(str.begin(), str.begin() + 1, str.end());
    }
    // cout << str << endl;
    numSwaps(str, strArr);
    // cout << count << endl;
  }
}