#include<bits/stdc++.h>
#include <fstream>
#include <windows.h>
using namespace std;

void createFile(char filename[])
{
    fstream file;
    file.open(filename,ios::out);
    if(!file)
    {
        cout << "Error in creating file!!!";
    }
    else cout << "File created" << endl;
    file.close();
}

void deleteFile(char filename[])
{
    int status;
    status = remove(filename);
    if(status==0) cout << "File is deleted" << endl;
    else cout << "File does not deleted" << endl;
}

void renameFile(char oldname[], char newname[])
{
    if(rename(oldname, newname)==0)
    {
        cout << "File renamed successfully." << endl;
    }
    else perror("Error");
}

void copyFile(char source[], char destination[])
{
    if(CopyFile(source,destination,true))
    {
        cout << "File copied successfully." << endl;
    }
    else cout << "Error occured." << endl;
}

void moveFile(char source[], char destination[])
{
    if(CopyFile(source,destination,true))
    {
        int status = remove(source);
        cout << "File moved successfully." << endl;
    }
    else cout << "Error occured." << endl;
}

int compare(char a[],char b[]){
    for(int i=0;a[i]!='\0';i++){
        if(a[i]!=b[i])
            return 0;
    }
    return 1;
}

int main(int argc, char** argv)
{
    //copyFile("c:/Users/CSE/Desktop/OS Lab (Suvash)/myfile.txt", "c:/Users/CSE/Desktop/OS Lab (Suvash)/copy/myfile.txt");
    //moveFile("c:/Users/CSE/Desktop/OS Lab (Suvash)/myfile.txt", "c:/Users/CSE/Desktop/OS Lab (Suvash)/copy/myfile.txt");
    if(argc==1)
    {
        cout << "No command inputed." << endl;
    }
    else
    {
        char create[] = "create";
        char del[] = "delete";
        char mov[] = "move";
        char ren[] = "rename";
        char cp[] = "copy";
        if(compare(argv[1], create))
        {
            createFile(argv[2]);
        }
        else if(compare(argv[1], del))
        {
            deleteFile(argv[2]);
        }
        else if(compare(argv[1], mov))
        {
            moveFile(argv[2], argv[3]);
        }
        else if(compare(argv[1], ren))
        {
            renameFile(argv[2], argv[3]);
        }
        else if(compare(argv[1], cp))
        {
            copyFile(argv[2], argv[3]);
        }
    }
}
