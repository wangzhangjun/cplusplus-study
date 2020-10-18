#ifndef __MY_ERROR_H__
#define __MY_ERROR_H__

#include <iostream>
#include <system_error>

namespace netd{
    namespace errorcode{
        enum class netd_error_code {
            errorCode1 = 1,
            errorCode2 = 2
        };
        class netd_error_category : public std::error_category
        {
            public:
                netd_error_category();
                const char* name() const _NOEXCEPT override;
                std::string message(int ev) const override;
                const static error_category& get();
        };
        std::error_code make_error_code(netd_error_code e);
    }
}


namespace std
{
    template <>
    struct is_error_code_enum<netd::errorcode::netd_error_code> : std::true_type
    {
    };
} 

#endif 