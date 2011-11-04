#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "user.h"
#include "connection.h"
#include <list>
#include "message.h"
#include "login.h"

void* do_client(void *xxx)
{
    pthread_detach (pthread_self ());
    cout<<"thread created!"<<endl;
  connection mycon =*((connection *)xxx);
    string h;
    message mymsg = message();
    if(mycon.recive())
    {
        cout << "Data corupted"<<endl;
        return NULL;
    }
    login mylog= login(mycon.get_msg());//login wird erstellt mit den string "name\npasswd"
    if(mylog.proof())
    {
        mycon.say_err();
        cout<<"bad login"<<endl;
        return NULL;
    }
    mycon.say_ok();
    user myusr = user(mylog.get_name());
    while(1)
    {
        if(mycon.recive())
        {
            cout<<"Data corupted 2"<<endl;
            return NULL;
        }
        mymsg.open(mycon.get_msg());
        switch(mymsg.get_type())
        {
        case 's':
             h= mymsg.get_betreff()+ "\n"+ mymsg.get_message();
      //       cout <<"entire message " << h<< endl;
            myusr.send(mymsg.get_reciver(),h);
            cout<<mymsg.get_message()<<endl;
            mycon.say_ok();
            break;
        case 'l':
            //cout <<"sende list... "<<endl;
            mycon.say_message(myusr.do_list());
            break;
        case 'r':
            myusr.do_read(mymsg.get_msg_nmb());
            break;
        case 'd':
            myusr.do_del(mymsg.get_msg_nmb());
            break;
        }

    }
    close (mycon.get_sock());
    return NULL;
}
using namespace std;
int main()
{
    int debug=0;
    string test;
    list <pthread_t *> threads;
    connection *mycon= new connection();
    connection * copy = NULL;
    while(1)
    {
        if(!(*mycon).connect())
        {
            threads.push_back(new pthread_t);
            cout << "createing thread..."<<endl;
          //  cout <<"ip: "<< debug <<endl;


copy = new connection(* mycon);
            pthread_create( threads.back(), NULL, do_client,(void*) copy);
        }

        //  pthread_create( threads.back(), NULL, do_client, (void*) &debug);
    }
    return EXIT_SUCCESS;
    return 0;
}

