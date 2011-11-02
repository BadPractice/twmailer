#include "user.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>
#include <sys/stat.h>
#include <dirent.h>
#include <ctime>

using namespace std;

user::user(string aaa)
{
    name=aaa;
    mkdir(name.c_str(),0700);

}

bool user::sortnumb (string first, string second){
    if (atoi(first.c_str())<atoi(second.c_str())) return true;
    return false;
}

void user::del()
{

}

void user::send(string to, string message)
{
    message=name + "\n" + message;
    mkdir(to.c_str(),0700);
    ofstream handle;
    time_t now;
    stringstream strm;
    string convert;
    time(&now);
    strm << now;
    convert=strm.str();
    convert=to +"/"+ convert;
    cout << convert<< endl;
    handle.open(convert.c_str(),ios::out);
    handle<<message;
    handle.close();
}

list <string> user::do_list()
{
    list<string> filenames;
     list<string>::iterator it;
    string handle;
    this->getfilenames(&filenames);
    filenames.sort();//user::sortnumb);
    for( it=filenames.begin() ; it != filenames.end(); it++ ){
        *it=this->getfile(*it,1);
    }
    return filenames;
}

string user::do_read(int msg)
{
    string message,line;
    int i;
 //   log.seekg(0, std::ios::beg);
    for(i=1; i<msg; i++)
    {
        while (line.compare("."))
        {
 //           getline (log,line);
        }
    }
  //  getline (log,line);
    message.append(line + "\n");
    while (line.compare("."))
        {
        //    getline (log,line);
            message.append(line+"\n");
        }
//    send(new_socket, message.c_str(), strlen(message.c_str()),0);
 return message;
}
string user::getfile(string filename,int rows)
{
    int i=0;
    string back, line;
    filename = name + "/"+ filename;
    ifstream handle;
    handle.open(filename.c_str(), ios::in);
    while (handle.good()&&(i!=rows+1))
    {
        getline (handle,line);
        back=back+line;
    }
    return back;
}

int user::getfilenames(list <string> *namelist){
    DIR *dp;
    int i=0;
    struct dirent *dirp;

    dp = opendir(name.c_str());
    if(dp == NULL) {
        cout << "did not get filenames" << endl;
        return -1;
    }
    while ((dirp = readdir(dp)) != NULL)
    {
        i++;
        (*namelist).push_back(string(dirp->d_name));
        if( (*namelist).back() == "." ||  (*namelist).back()=="..")
        {
             (*namelist).pop_back();
        }
    }
    closedir(dp);
    return i;
}

int user::writefile(string message)
{
    ofstream handle;
    time_t now;
    stringstream strm;
    string convert;
    time(&now);
    strm << now;
    convert=strm.str();
    convert=name +"/"+ convert;
    cout << convert<< endl;
    handle.open(convert.c_str(),ios::out);
    handle<<message;
    handle.close();
    return 0;
}

user::~user()
{

}
