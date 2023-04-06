#include <bits/stdc++.h>
using namespace std;
struct Snapshot {
  int n, m;
  vector<vector<int>> allocation, request;
  vector<int> available;
  Snapshot(int n, int m, vector<vector<int>> allocation, vector<vector<int>> request, vector<int> available) {
    this->n = n;
    this->m = m;
    this->allocation = allocation;
    this->request = request;
    this->available = available;
  }
  bool isDeadLock() {
    vector<int> work = available;
    vector<bool> finish(n, false);
    int count = 0;

    while (count < n) {
      bool found = false;
      for (int i = 0; i < n; i++) {
        if (finish[i] == false) {
          int j;
          for (j = 0; j < m; j++) {
            if (request[i][j] > work[j]) {
              break;
            }
          }
          if (j == m) {
            for (int k = 0; k < m; k++) {
              work[k] += allocation[i][k];
            }
            finish[i] = true;
            found = true;
            count++;
          }
        }
      }
      if (found == false) {
        return true;
      }
    }
    return false;
  }
};

Snapshot take_input() {
  int n, m;
  cout << "Enter number of processes: ";
  cin >> n;
  cout << "Enter number of resources: ";
  cin >> m;
  cout << "Enter Allocation matrix: " << endl;
  vector<vector<int>> allocation(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> allocation[i][j];
    }
  }
  cout << "Enter Request matrix: " << endl;
  vector<vector<int>> request(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> request[i][j];
    }
  }
  cout << "Enter Available resource: " << endl;
  vector<int> available(m);
  for (auto &it : available) {
    cin >> it;
  }
  return Snapshot(n, m, allocation, request, available);
}
int main() {
  auto snapshot = take_input();
  if (snapshot.isDeadLock()) {
    cout << "System is in DeadLoak" << endl;
  } else {
    cout << "System is runnig good" << endl;
  }
}