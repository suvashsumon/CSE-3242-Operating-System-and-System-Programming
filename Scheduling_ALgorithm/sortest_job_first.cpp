#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int main(){

    freopen("in.txt", "r", stdin);
    cout << "Enter the number of process : " << "\n";
    int number_of_process;
    cin >> number_of_process;

    vector < ii > bus_times(number_of_process);
    int index = 1;
    int sum = 0;
    for(auto &bus_time : bus_times){
        cin >> bus_time.first;
        sum += bus_time.first + 4;
        bus_time.second = index++;
    }
    sort(bus_times.begin(), bus_times.end());
    cout << " ";
    for(int i = 0; i < sum - 1 ; i++){
        cout << "_";
    }
    cout << endl;
    for(auto it : bus_times){
        cout << "|";
        printf("%3d", it.second);
        for(int i = 0 ; i < it.first; i++)
            cout << " ";
    }
    cout << "|" << endl;
    cout << " ";
    for(int i = 0; i < sum;i++){
        cout << "-";
    }
    cout << endl;
    //cout << " ";
    int t = 0;
    for(auto it: bus_times){
        printf("%-3d", t);
        t += it.first;

        for(int i = 0; i <= it.first; i++){
            cout << " ";
        }
    }
    cout << t;
    cout << endl;
    return 0;
}
