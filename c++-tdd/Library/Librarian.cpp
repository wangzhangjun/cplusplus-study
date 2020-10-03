#include "Librarian.h"
#include <string>
#include <stdexcept>
Librarian::Librarian()
{
}
unsigned int Librarian::store(const std::string &name)
{
    books_.insert(name);
    return books_.size();
}
unsigned int Librarian::borrow(const std::string &name)
{
    if (this->books_.size() == 0)
    {
        throw std::runtime_error("no books");
    }
    else
    {
        this->books_.erase(name);
    }
    return this->books_.size();
}