#ifndef USER_H
#define USER_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class user
{
    public:
        user(string aaa);
        void send(string to, string message);
        void list();
        void del();
        void read(int msg);
         ~user();
    protected:
    private:
    string name;
    fstream log;
};

#endif // USER_H
