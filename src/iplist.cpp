#include "iplist.h"
#define TRY_LIMIT 3
iplist::iplist()
{
    //ctor
}


void iplist::add(string arg)
{
    badguys.push_back(badguy(arg));
}
int check(struct in_addr);
{
    int count=0, ret=0;
    time_t mytime;
    time(&mytime);
    mytime=mytime;
    list<badguy>::iterator it;
    it=badguys.begin();



    while((*it).get_time()<mytime||it==badguys.end()) it++;

    do
    {


        if(!(*it).get_name.compare(arg1))
        {
            count++;
            if(count=TRY_LIMIT)
            {
                ret++;
                break
            }
        }


    }
    while(it!=badguy.end())
        return break;
}
void clear();

void refresh();
int ipllist::check

iplist::~iplist()
{
    //dtor
}

