#include<bits/stdc++.h>
using namespace std;

#define MAX 100

struct Process {
    int pid;
    int burst_time;
    int waiting_time;
};

int total_waiting_time;

void sort_by_burst_time(Process p[], int n)
{
    Process temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(p[j].burst_time>p[j+1].burst_time)
            {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void calculate_waiting_time(Process p[], int n)
{
    total_waiting_time = 0;
    p[0].waiting_time = 0;
    for(int i=1; i<n; i++)
    {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
        total_waiting_time += p[i].waiting_time;
    }
}


void print_gantt_chart(Process p[], int n)
{
    int i, j;
    int last = p[n-1].burst_time + ( n== 1 ? 0 : p[n-1].waiting_time);
    // printing top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    // middle position
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time-1; j++) printf(" ");
        printf("p%d", p[i].pid);
        for(j=0; j<p[i].burst_time-1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    // printing waiting time
    int minus = 0;
    for(i=0; i<n; i++) {
        if(p[i].waiting_time>9) printf(" ");
        printf("%d", p[i].waiting_time);
        if(p[i+1].waiting_time>9){
          minus = 1;
        }
        if(i+1 == n )  if (last>9) minus = 1;
        for(j=0; j<p[i].burst_time-minus; j++) printf("  ");

    }
    if(last>9) printf(" ");
    printf("%d\n", last);
}


int main()
{
    Process p[MAX];
    int n;
    cout << "Enter the number of process : ";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cout << "Burst time of Process " << i+1 << ": ";
        cin >> p[i].burst_time;
        p[i].pid = i+1;
    }

    sort_by_burst_time(p, n);
    calculate_waiting_time(p, n);

    double average_waiting_time = (double) total_waiting_time/n;
    cout << "Average waiting Time : " << average_waiting_time << endl;
    print_gantt_chart(p, n);
}
