#include<bits/stdc++.h>
using namespace std;
// kono ekta moment e jar kaj er poriman sob theke kom se age jeye 1 sec er kaj kore felbe.

struct Proces{
    int process_id;
    int arrival_time;
    int total_job_time;
    int remaining_job_time;
    int waiting_time;
    int turn_around_time;
    int completion_time;
    int response_time;

    Proces(int process_id, int arrival_time, int total_job_time){
        this->process_id = process_id;
        this->arrival_time = arrival_time;
        this->total_job_time = total_job_time;
        this->remaining_job_time = total_job_time;
        this->waiting_time = 0;
        this->turn_around_time = 0;
        this->completion_time = 0;
        this->response_time = 0;
    }

};
bool compare(Proces a, Proces b){
    return a.arrival_time < b.arrival_time;
}
bool compare2(Proces a, Proces b){
    if(a.remaining_job_time == b.remaining_job_time)
        return a.process_id > b.process_id; // id er theke choto theke boro
    return a.remaining_job_time < b.remaining_job_time;
}

int main(){
    cout << "Enter the number of process: ";
    int n;
    cin >> n;
    vector<Proces>process;
    cout << "Enter the arrival time and total job time of each process: " << endl;
    for(int i = 1; i <= n ; i++){
        int arrival_time, total_job_time;
        cin >> arrival_time >> total_job_time;
        process.push_back(Proces(i, arrival_time, total_job_time));
    }
    sort(process.begin(), process.end(), compare);
    int time = 0;
    stringstream grantt_chart;
    stringstream time_interval;
    grantt_chart << '|';
    time_interval << '|';

    vector<Proces>ready_queue;
    int index = 0;
    while(index < n || ready_queue.size() != 0){

        while(index < n && process[index].arrival_time == time){
            ready_queue.push_back(process[index]);
            index++;
        }
        sort(ready_queue.rbegin(), ready_queue.rend() , compare2);
        if(ready_queue.size() == 0){
            grantt_chart << "IDLE|";
            time_interval << setfill('-') << setw(4) << time << '|';
        }
        else{
            Proces current_process = ready_queue.back();
            ready_queue.pop_back();

            grantt_chart << "P" << setfill(' ') << setw(3) << current_process.process_id << '|';
            time_interval << setfill(' ') << setw(4) << time << '|';
            current_process.remaining_job_time--;
            if(current_process.remaining_job_time == 0){
                current_process.completion_time = time + 1;
                current_process.turn_around_time = current_process.completion_time - current_process.arrival_time;
                current_process.waiting_time = current_process.turn_around_time - current_process.total_job_time;
                current_process.response_time = current_process.waiting_time;
                process[current_process.process_id - 1] = current_process;
            }
            else{
                ready_queue.push_back(current_process);
            }
        }
        time++;


    } 
    cout << "Process ID\tArrival Time\tTotal Job Time\tCompletion Time\tTurn Around Time\tWaiting Time\tResponse Time" << endl;
    for(int i = 0; i < n; i++){
        cout << process[i].process_id << "\t\t" << process[i].arrival_time << "\t\t" << process[i].total_job_time << "\t\t" << process[i].completion_time << "\t\t" << process[i].turn_around_time << "\t\t\t\t" << process[i].waiting_time << "\t\t" << process[i].response_time << endl;
    }
    cout << endl;
    int size = grantt_chart.str().size();
    cout << setfill('-') << setw(15 + size) << '-' << endl;
    cout << "Grantt Chart:  ";
    cout << grantt_chart.str() << endl;
    cout << setfill('-') << setw(15 + size) << '-' << endl;
    cout << "Time Interval: ";
    cout << time_interval.str() << endl;
    cout << setfill('-') << setw(15 + size) << '-' << endl;

    int total_waiting_time = 0;
    int total_turn_around_time = 0;
    int total_response_time = 0;
    for(auto it : process){
        total_response_time += it.response_time;
        total_turn_around_time += it.turn_around_time;
        total_waiting_time += it.waiting_time;
    }
    cout << "Average Waiting Time: " << (double)total_waiting_time / n << endl;
    cout << "Average Turn Around Time: " << (double)total_turn_around_time / n << endl;
    cout << "Average Response Time: " << (double)total_response_time / n << endl;
    return 0;
}
