#ifndef __LIBRARY_LIBRARIAN_H__
#define __LIBRARY_LIBRARIAN_H__

#include <set>
#include <string>

class Librarian
{
private:
    std::set<std::string> books_;

public:
    Librarian();
    unsigned int store(const std::string &name);
    unsigned int borrow(const std::string &name);
};
#endif //!__LIBRARY_LIBRARIAN_H__