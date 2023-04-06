#include <bits/stdc++.h>
#include <unistd.h>
#include<limits>
#include<dirent.h>
#include<sys/types.h>
#include<filesystem>

using namespace std;
void print_file_in_directory(char* dir_name){
    string path = string(dir_name);
    for (const auto & entry : std::filesystem::directory_iterator(path)){
        cout << entry.path() << endl;
    }
}
void print_directory(char* dir_name){
    string path = string(dir_name);
    for(const auto& it : std::filesystem::directory_iterator(path)){
        cout << it.path() << endl;
    }
}
void copy(char *from , char *to){
    ifstream ini_file{
        from,ios_base::in | ios_base::binary
    };
    ofstream out_file{
        to,ios_base::out | ios_base::binary
    };
    const int buff_size = 4096;
    if(ini_file && out_file){
            char  buf[buff_size];
        do{
            ini_file.read(&buf[0],buff_size);
            out_file.write(&buf[0],ini_file.gcount());
        } while(ini_file.gcount() > 0);
        cout << "Copy finished" << endl;
    }else cout << "Copy Failed" << endl;
}

void copy_test(char* from, char* to){
    ifstream input_file{
        from, ios_base::in | ios_base::binary
    };

    ofstream output_file{
        to, ios_base::out | ios_base::binary
    };
    const int buffer_size = 1 << 12;
    if(input_file && out_file){
        char buffer[buffer_size];
        do{
            input_file.read(&buffer[0], buffer_size);
            output_file.write((&buffer[0], input_file.gcount();
        }while(input_file.gcount() > 0);
        cout << "Copy Finished" << endl;
    }else cout << "Copy Failed" << endl;
}


int32_t main(int argc, char** argv){
   string line;
   string command = argv[1];
   //cout << command << endl;

   if (command == "copy"){
        char* from = argv[2];
        char* to = argv[3];
        copy(from,to);
        
   } else if (command == "mov"){
        char* dir_to_mov = argv[3];
        //strcat(dir_to_mov,argv[2]);

        if(rename(argv[2],dir_to_mov) == 0){
            cout << "Mov Successful" << endl;
        }
        else cout << "Mov Failed" << endl;
    }
     else if (command == "rename"){
        if(rename(argv[2],argv[3]) == 0){
            cout << "rename Successful" << endl;
        }
        else cout << "rename Failed" << endl;
    }else if(command == "dir"){
        char dirc[4096];
        getcwd(dirc,sizeof(dirc));
        cout << "Your current directory is : " << dirc << endl;
    }else if(command == "ls"){
        char dir_name[4096];
        getcwd(dir_name,sizeof(dir_name));
        char* dir_ = dir_name;
        if(argc > 2) dir_ = argv[2];
        print_file_in_directory(dir_);
    }
    else{
        cout << "Unknown Command" << endl;
    }


    return 0;
}

