#include <iostream>
#include "tabtenn0.h"

TableTennisPlayer::TableTennisPlayer(const std::string &fn, 
    const std::string &ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht)
{
    
}

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname << std::endl;
}

//继承类的以下两种构造方式都可以
RatedPlayer::RatedPlayer(unsigned int r, const std::string &fn,
                         const std::string &ln, bool ht) : TableTennisPlayer(fn ,ln, ht)
{
    this->rating = r;   
}
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp):TableTennisPlayer(tp), rating(r)
{

}


