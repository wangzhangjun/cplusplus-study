#include "my_error.h"

netd::errorcode::netd_error_category::netd_error_category(){

}

const char * netd::errorcode::netd_error_category::name() const _NOEXCEPT{
    return "my error code category";
}

std::string netd::errorcode::netd_error_category::message(int ev) const {
    switch (static_cast<netd::errorcode::netd_error_code>(ev))
    {
        case netd::errorcode::netd_error_code::errorCode1 :
            return "this is error_code1";
            break;
        case netd::errorcode::netd_error_code::errorCode2:
            return "this is error_code2";
        default:
            return "this is unknow error_code";
            break;
    }
}

const std::error_category& netd::errorcode::netd_error_category::get()
{
    const static netd::errorcode::netd_error_category category_const;
    
    return category_const;
}

std::error_code netd::errorcode::make_error_code(netd_error_code e){
    std::cout << "in  make_error_code" << std::endl;
    return std::error_code(static_cast<int>(e), 
        netd::errorcode::netd_error_category::get());
}

