#include "login.h"

login::login(string msg)
{
    int pos;
    pos=msg.find("\n",0);
    name=msg.substr(0,pos);
    name=msg.substr(pos);
}

int login::proof()
{
    return 0;

}
string login::get_name()
{
    return name;
}
login::~login()
{
    //dtor
}
