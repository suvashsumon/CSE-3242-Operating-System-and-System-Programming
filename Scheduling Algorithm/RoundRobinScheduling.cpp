#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n,quantum_time;
struct process
{
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int finishing_time;
    int turn_around_time;
    int remaining_time;
};
process P[N];
vector<process>Q;
void RoundRobin()
{
    int complete,current_time,change;
    double total_waiting_time = 0.0;
    double total_turn_around_time = 0.0;

    for(int i=0; i<n; i++)
        P[i].remaining_time = P[i].burst_time;

    complete = 0;
    current_time = 0;

    while(complete < n)
    {
        int q_index = 0;
        change = 0;
        for(int i=0; i<n; i++)
        {
            if(P[i].arrival_time <= current_time && P[i].remaining_time > 0)
            {
                process q = P[i];
                if(P[i].remaining_time <= quantum_time)
                {
                    complete++;
                    current_time += P[i].remaining_time;

                    P[i].finishing_time = current_time;
                    P[i].turn_around_time = P[i].finishing_time - P[i].arrival_time;
                    P[i].waiting_time = P[i].turn_around_time - P[i].burst_time;

                    total_waiting_time += P[i].waiting_time;
                    total_turn_around_time += P[i].turn_around_time;

                    q.burst_time = P[i].remaining_time;


                    P[i].remaining_time = 0;
                }
                else
                {
                    current_time += quantum_time;
                    P[i].remaining_time -= quantum_time;
                    q.burst_time = quantum_time;
                }
                change++;
                q.turn_around_time = current_time;
                Q.push_back(q);
            }
        }
        if(change == 0)
        {
            current_time++;
        }
    }
    cout << endl;
    cout<<fixed<<setprecision(2);
    cout<<"Average Waiting Time: "<<(total_waiting_time/n)<<"\n";
    cout<<"Average Turn Around Time: "<<(total_turn_around_time/n)<<"\n";
    return;
}

void print_gantt_chart(vector<process>p, int n)
{
    int i, j;
    // print top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    // printing process id in the middle
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time - 1; j++) printf(" ");
        printf("P%d", p[i].id);
        for(j=0; j<p[i].burst_time - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // printing bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    // printing the time line
    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("  ");
        if(p[i].turn_around_time > 9) printf("\b"); // backspace : remove 1 space
        printf("%d", p[i].turn_around_time);

    }
    printf("\n");

}

int main()
{
    freopen("input.txt", "r", stdin);
    cout<<"Number of Processes: ";
    cin>>n;

    cout<<"Quantum time: ";
    cin>>quantum_time;

    for(int i=0; i<n; i++)
    {
        cout<<"Process Ids: ";
        cin>>P[i].id;

        cout<<"Process Burst Times: ";
        cin>>P[i].burst_time;

        //cout<<"Process Arrival Times: ";
        //cin>>P[i].arrival_time;
        P[i].arrival_time = 0; // by default assigned zero
    }


    RoundRobin();
    print_gantt_chart(Q, Q.size());

    return 0;
}

