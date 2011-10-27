#ifndef CONNECTION_H
#define CONNECTION_H
#include <string>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#define BUF 1024
#define PORT 6543
using namespace std;

class connection
{
    public:
        connection();
        int connect();
        int recive();
        void say_ok();
        void say_err();
        ~connection();
    protected:
    private:
        int create_socket, new_socket;
        socklen_t addrlen;
        string buffer;
        int size;
        struct sockaddr_in address, cliaddress;
};

#endif // CONNECTION_H
