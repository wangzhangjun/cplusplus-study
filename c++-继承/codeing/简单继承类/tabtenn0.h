#ifndef __CODEING_TABTENN0_H__
#define __CODEING_TABTENN0_H__

#include <string>

class TableTennisPlayer{
    private:
        std::string firstname;
        std::string lastname;
        bool hasTable;
    public:
        TableTennisPlayer(const std::string &fn, const std::string &ln, bool ht);
        void Name() const;
        bool HasTable() const{
            return hasTable;
        }
        void ResetTable(bool v){
            hasTable = v;
        }
};

class RatedPlayer : public TableTennisPlayer
{
    private:
        unsigned int rating;
    public:
        RatedPlayer(unsigned int r, const std::string &fn, const std::string &ln, bool ht);
        RatedPlayer(unsigned int r, const TableTennisPlayer &tp);
        unsigned int Rating() const{
            return rating;
        }
        void ResetRating(unsigned int r){
            rating = r;
        }
};

#endif //!__CODEING_TABTENN0_H__