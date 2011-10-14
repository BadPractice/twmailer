#include "user.h"
#include <string>
#include <string>
#include <fstream>
#include <iostream>
#include <sys/stat.h>

using namespace std;

user::user(string aaa)
{
    string filepath;
    name=aaa;
    filepath= name + "/mails.txt";
    mkdir(name.c_str(),0600);
    log.open(filepath.c_str(), ios::in|ios::out|ios::ate);
    log<<flush;

}

void user::del()
{
    log.close();
    log.open(name.c_str(), ios::in|ios::out);
    log<<flush;

}

void user::send(string to, string message)
{
    int len;
    string line="<"+to+">\n";
    log.write(line.c_str(),line.size());
    if(message.size()>80) len=80; //limits the message length to 80
    else len=message.size();
    line="<"+ message.substr(0,len) +">\n.\n";
    log.write(line.c_str(),line.size());
}

void user::list()
{
    string mylist,line;
    int i=0;
    log.seekg(0, std::ios::beg);
    while(log.good())
    {
        getline (log,line);
        line.append("\n");
        mylist.append(line);
        i++;
        while (log.good()&&line.compare("."))
        {
            getline (log,line);
        }
    }
  //  mylist=mylist;
//    send(new_socket, mylist, strlen(mylist),0);
    cout<<"<"<<i<<">"<<endl<<mylist<<endl;

}

void user::read(int msg)
{
    string message,line;
    int i;
    log.seekg(0, std::ios::beg);
    for(i=1; i<msg; i++)
    {
        getline (log,line);
        while (line.compare("."))
        {
            getline (log,line);
        }
    }
    getline (log,line);
    message.append(line + "\n");
    while (line.compare("."))
        {
            getline (log,line);
            message.append(line+"\n");
        }
//    send(new_socket, message.c_str(), strlen(message.c_str()),0);

}

user::~user()
{
    log.close();//dtor
}
