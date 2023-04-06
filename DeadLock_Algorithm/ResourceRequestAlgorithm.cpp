#include "SafetyAlgorithm.cpp"
#include <bits/stdc++.h>
using namespace std;
bool isSafeRequest(Snapshot snapshot, int proces, vector<int> requested_resources) {
  auto allocation = snapshot.allocation;
  for (int i = 0; i < snapshot.m; i++) {
    allocation[proces][i] += requested_resources[i];
  }
  Snapshot new_snapshot(snapshot.n, snapshot.m, allocation, snapshot.maximum, snapshot.available);
  return safe_proces_sequence(new_snapshot).size() == snapshot.n;
}

int main() {
  Snapshot snapshot = take_input();
  snapshot.print();
  auto result = safe_proces_sequence(snapshot);
  if (result.size() == snapshot.n) {
    cout << "The System is in Safe State" << endl;
    cout << "Safe Proces Sequence is: " << endl;
    for (int i = 0; i < result.size(); i++) {
      cout << "P" << 1 + result[i] << " ";
    }
    cout << endl;

  } else {
    cout << "The System is in Unsafe State" << endl;
  }
  while (true) {
    cout << "Enter the Proces Number: " << endl;
    int proces;
    cin >> proces;
    cout << "Enter the Requested Resources: " << endl;
    vector<int> requested_resources(snapshot.m);
    for (auto &it : requested_resources) {
      cin >> it;
    }
    cout << "Your Request is for the proces : " << proces << endl;
    for (auto it : requested_resources) {
      cout << it << " ";
    }
    cout << endl;
    if (isSafeRequest(snapshot, proces - 1, requested_resources)) {
      cout << "The Request is Safe" << endl;
      for (int i = 0; i < snapshot.m; i++) {
        snapshot.allocation[proces - 1][i] += requested_resources[i];
        snapshot.available[i] -= requested_resources[i];
      }
    } else {
      cout << "The Request is Unsafe" << endl;
    }
    cout << "Do you want to continue? (y/n)" << endl;
    char ch;
    cin >> ch;
    if (ch == 'n') {
      cout << "Thank You" << endl;
      break;
    }
  }

  return 0;
}