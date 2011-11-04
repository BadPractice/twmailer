#ifndef IPLIST_H
#define IPLIST_H
#include <list>
#include <string>
#include "badguy.h"
using namespace std;
class iplist
{
    public:
        iplist();
        void add(string);
        int check(string);
        void clear();
        void refresh();
        virtual ~iplist();
    protected:
    private:
        list <badguy> badguys;
};

#endif // IPLIST_H
