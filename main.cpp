#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "user.h"
#include "connection.h"
using namespace std;
int do_send(char* aaa)
{
    int pos;
    string buffer=aaa,sender,rcver,subj;
 //   cout<<buffer<<endl;
    pos=buffer.find("\n",0);
    sender=buffer.substr(0,pos);
    buffer=buffer.substr(pos+1);
    pos=buffer.find("\n",0);
    rcver=buffer.substr(0,pos);
    buffer=buffer.substr(pos+1);
        pos=buffer.find("\n",0);
    subj=buffer.substr(0,pos);
    buffer=buffer.substr(pos+1);
    cout<<"sender: "<<sender<<endl<<"reciver: "<<rcver<<endl<<"subject: "<<subj<<endl<<"message: "<<buffer;
        pos=buffer.find("\n",0);
    rcver=buffer.substr(0,pos);
    buffer=buffer.substr(pos+1);
    return EXIT_SUCCESS;
}
int main()
{
    string message;
    connection markus = connection();
    message = markus.connect();
    cout<<message<<endl;
    while (1)
    {

    }
    return EXIT_SUCCESS;
    return 0;
}

