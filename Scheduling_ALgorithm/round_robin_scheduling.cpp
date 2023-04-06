#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
int main(){
    //freopen("in.txt", "r", stdin);

    cout << "Enter the process number: " << endl;

    int number_of_process;
    cin >> number_of_process;

    cout <<  "Enter the size of quantam size: " << endl;
    int quantam;
    cin >> quantam;

    queue<ii> brust_times;


    int index = 1;
    for(int i = 0 ; i < number_of_process; i++){
        int x;
        cin >> x;
        brust_times.push({x , index++ });
    }
    stringstream grantt_chart;
    stringstream time_interval;
    int t = 0;
    while(!brust_times.empty()){
        auto it  = brust_times.front();
        int rem_time = it.first;
        int proces_number = it.second;
        brust_times.pop();

        if(rem_time <= quantam){
            grantt_chart << '|' << setfill(' ') << setw(3) <<  proces_number;
            time_interval << '|' << setfill(' ') << setw(3) << t;
            for(int i = 0; i < rem_time; i++){
                grantt_chart << " ";
                time_interval << ' ';
            }
            t += rem_time;
        }
        else {
            grantt_chart << '|' << setfill(' ') << setw(3) <<  proces_number;
            time_interval << '|' << setfill(' ') << setw(3) << t;
            for(int i = 0; i < quantam; i++){
                grantt_chart << " ";
                time_interval << ' ';
            }
            rem_time -= quantam;
            t += quantam;
            brust_times.push({rem_time ,proces_number });

        }
    }
    grantt_chart << '|';
    time_interval << '|';
    time_interval << t ;
    cout << " ";
    for(char ch : grantt_chart.str()){
        cout << '-';
    }
    cout << endl;
    cout << grantt_chart.str() << endl;
    cout << " ";
    for(char ch : grantt_chart.str()){
        cout << '-';
    }
    cout << endl;
    cout << time_interval.str() << endl;


}
