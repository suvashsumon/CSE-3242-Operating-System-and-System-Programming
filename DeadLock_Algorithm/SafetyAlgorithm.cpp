#include <bits/stdc++.h>
using namespace std;
struct Snapshot {
  int n, m;
  vector<vector<int>> allocation, maximum, need;
  vector<int> available;
  Snapshot(int n, int m, vector<vector<int>> allocation, vector<vector<int>> maximum, vector<int> available) {
    this->n = n;
    this->m = m;
    this->allocation = allocation;
    this->maximum = maximum;
    this->available = available;
    need = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        need[i][j] = maximum[i][j] - allocation[i][j];
      }
    }
  }
  void print() {
    cout << "Allocation Matrix" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << allocation[i][j] << " ";
      }
      cout << endl;
    }
    cout << "Maximum Matrix" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << maximum[i][j] << " ";
      }
      cout << endl;
    }
    cout << "Available Matrix" << endl;
    for (int i = 0; i < m; i++) {
      cout << available[i] << " ";
    }
    cout << endl;
  }
};

Snapshot take_input() {
  int number_of_proces, number_of_resorce;
  cout << "Enter The Number of Proces: " << endl;
  cin >> number_of_proces;

  cout << "Enter The number of resources: " << endl;
  cin >> number_of_resorce;

  cout << "Enter the Alocation Matrix: " << endl;
  cout << "Mat[i][j] will indicate alocated jth resource of i'th proces" << endl;
  int n = number_of_proces;
  int m = number_of_resorce;

  vector<vector<int>> allocation(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> allocation[i][j];
    }
  }
  cout << "Enter the Max Matrix: " << endl;
  cout << "Mat[i][j] will indicate max need of jth resource of i'th proces " << endl;
  vector<vector<int>> maximum(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> maximum[i][j];
    }
  }
  cout << "Enter Available resource: " << endl;
  vector<int> available(m);
  for (auto &it : available) {
    cin >> it;
  }
  return Snapshot(n, m, allocation, maximum, available);
}
vector<int> safe_proces_sequence(Snapshot &snapshot) {
  vector<int> safe_sequence;
  vector<bool> finish(snapshot.n, false);
  vector<int> work = snapshot.available;
  int count = 0;

  while (count < snapshot.n) {

    bool found = false;

    for (int i = 0; i < snapshot.n; i++) {

      if (!finish[i]) {
        int j = 0;
        for (; j < snapshot.m; j++) {
          if (snapshot.need[i][j] > work[j]) {
            break;
          }
        }
        if (j == snapshot.m) {
          for (int k = 0; k < snapshot.m; k++) {
            work[k] += snapshot.allocation[i][k];
          }
          safe_sequence.push_back(i);
          finish[i] = true;
          found = true;
          count++;
          break;
        }
      }
    }
    if (!found) {
      break;
    }
  }

  if (count == snapshot.n) {
    return safe_sequence;
  }
  return {};
  // return safe_sequence;
}

// int main() {
// auto it = take_input();
// it.print();
// auto safe_sequence = safe_proces_sequence(it);
// cout << "Safe Sequence is: " << endl;
// for (auto &it : safe_sequence) {
// cout << "P-" << it + 1 << " ";
// }
// cout << endl;
// }