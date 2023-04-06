#include<bits/stdc++.h>
using namespace std;

pair<char, int>frame[3];

void printFrame()
{
    cout << "Frame : ";
    for(int i=0; i<3; i++)
    {
        cout << frame[i].first << " ";
    }
    cout << endl;
}

void add(char x, int index)
{
    frame[index].first = x;
    frame[index].second = index;
}

bool checkIsExist(char x, int index)
{
    bool check = false;
    for(int i=0; i<3; i++)
    {
        if(frame[i].first==x)
        {
            check = true;
            frame[i].second = index;
            break;
        }
    }
    return check;
}

void replacepage(char x, int index)
{
    int r = -1;
    int ii = 9999;
    for(int i=0; i<3; i++) // finding the index
    {
        if(ii>frame[i].second)
        {
            r = i;
            ii = frame[i].second;
        }
    }
    frame[r].first = x;
    frame[r].second = index;
}

int main()
{
    string input = "123215216256313";
    //string input = "1232";
    int s_size = input.size();
    int mis = 0;
    int hit = 0;
    for(int i=0; i<s_size; i++)
    {
        cout << input[i] << endl;
        if(checkIsExist(input[i], i))
        {
            hit++;
            cout << "H" << endl;
        }
        else if(i<3)
        {
            cout << "M" << endl;
            add(input[i], i);
            mis++;
        }
        else
        {
            cout << "M" << endl;
            mis++;
            replacepage(input[i], i);
        }
        printFrame();
    }
    cout << "Page Fault : " << mis << endl;

}
