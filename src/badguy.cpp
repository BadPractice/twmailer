#include "badguy.h"
#define TIMEOUT 5000

badguy::badguy(string arg)
{
    //ctor
    time(&mytime);
    mytime=mytime + TIMEOUT;
    name=arg;
}

time_t badguy::get_time()
{
    return mytime;
}

string badguy::get_name()
{
    return name;
}


badguy::~badguy()
{
    //dtor
}
