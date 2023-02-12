#include <bits/stdc++.h>
using namespace std;

const int N=100005;

struct process
{
    int priority;
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int finishing_time;
    int turn_around_time;
};

int n;
process P[N];

bool operator<(process A, process B)
{
    if(A.priority < B.priority)
    {
        return true;
    }
    if(A.priority == B.priority)
    {
        return A.arrival_time < B.arrival_time;
    }
    return false;
}


void Priority(void)
{
    sort(P, P+n);
    double total_waiting_time = 0.0;
    double total_turn_around_time = 0.0;

    for(int i=0; i<n; i++)
    {
        P[i].finishing_time = P[i-1].finishing_time + P[i].burst_time;
        P[i].turn_around_time = P[i].finishing_time - P[i].arrival_time;
        P[i].waiting_time = P[i].turn_around_time - P[i].burst_time;

        total_waiting_time += P[i].waiting_time;
        total_turn_around_time += P[i].turn_around_time;
    }
    cout<<fixed<<setprecision(2);
    cout<<"Average Waiting Time: "<<(total_waiting_time/n)<<"\n";
    cout<<"Average Turn Around Time: "<<(total_turn_around_time/n)<<"\n";
    return;
}

void print_table(process p[], int n)
{
    int i;

    puts("+-----+------------+--------------+-----------------+");
    puts("| PID | Burst Time | Waiting Time | Turnaround Time |");
    puts("+-----+------------+--------------+-----------------+");

    for(i=0; i<n; i++) {
        printf("| %2d  |     %2d     |      %2d      |        %2d       |\n"
               , p[i].id, p[i].burst_time, p[i].waiting_time, p[i].turn_around_time );
        puts("+-----+------------+--------------+-----------------+");
    }

}

void print_gantt_chart(process p[], int n)
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
    cout<<"Number of P: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout << "Enter the Process ID : ";
        cin >> P[i].id;
        cout << "Enter the Burst Time :";
        cin >> P[i].burst_time;
        cout << "Enter the priority : ";
        cin >> P[i].priority;
        P[i].arrival_time = 0; // by default set to zero
        cout << endl;
    }

    Priority();
    cout << endl;
    print_table(P, n);
    print_gantt_chart(P, n);

    return 0;
}
