#ifndef USER_H
#define USER_H
#include <string>
#include <fstream>
#include <iostream>
#include <list>
using namespace std;

class user
{
    public:
        user(string aaa);
        void send(string to, string message);
        void do_list();
        void del();
        void read(int msg);
        int writefile(string);
         ~user();
    protected:
    private:
        string name;
        int getfilenames(list<string>, string, string );
        string getfile(string filename, int anz);
    };

#endif // USER_H
