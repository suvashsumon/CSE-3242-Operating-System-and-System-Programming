#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int page_frame = 3;
int page_fault = 0;
int q_len = 0;

bool fifo(int x)
{
    // check if x is present in queue
    queue<int>tq;
    tq = q;
    while(!tq.empty())
    {
        int a = tq.front();
        tq.pop();
        if(a==x) return true;
    }
    if(q_len==page_frame)
    {
        q.pop();
        q.push(x);
    }
    else {
        q.push(x);
        q_len++;
    }
    page_fault++;
    return false;
}

void print_q()
{
    queue<int>tq;
    tq = q;
    while(!tq.empty())
    {
        int a = tq.front();
        cout << a << " ";
        tq.pop();
    }
    cout << endl;
}



int main()
{
    while(1)
    {
        int x;
        cin >> x;
        if(x<0) break;
        bool output = fifo(x);
        if(output) cout << "Hit" << endl;
        else  cout << "Miss" << endl;
        cout << "Page Fault : " << page_fault << endl;
        cout << "Current Queue : ";
        print_q();
    }
}
