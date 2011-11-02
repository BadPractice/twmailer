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

void * do_client(void *xxx)
{
    while(1)
    {
        connection *mycon = (connection*)xxx;
        message mymsg = message();
        if(!(*mycon).recive())
        {
            return NULL;
        }
        login mylog= login((*mycon).get_msg());
        if(!mylog.proof())
        {
           (*mycon).say_err();
            return NULL;
        }
        (*mycon).say_ok();
        user myusr = user(mylog.get_name());
        if(!(*mycon).recive())
        {
            return NULL;
        }
        mymsg.open((*mycon).get_msg());
        }

    return 0;
}
using namespace std;
int main()
{
    list <pthread_t *> threads;
    connection *mycon;

    while(1)
    {
        mycon = new connection();
        if((*mycon).connect())
        {
            threads.push_back(new pthread_t);
            pthread_create( threads.back(), NULL, do_client, (void*) mycon);
        }

        // pthread_create( threads.back(), NULL, do_client, (void*) mycon);
        delete mycon;
    }
    return EXIT_SUCCESS;
    return 0;
}

