//
// Created by yuzj on 1/17/22.
//

#ifndef CEU_SUBPROCESS_HPP
#define CEU_SUBPROCESS_HPP

#include <sstream>
#include <cstring>

namespace ceu
{
namespace subprocess
{
/***
 * @class SubProcessException
 *
 * @description A class which represents underlying C error.
 * @param input_filename Filename which causes error.
 * @param c_error Error number of underlying C error.
 */
class SubProcessException: public std::exception
{
public:
    explicit SubProcessException(int c_errorno)
    {
        _c_errorno = c_errorno;
        static std::ostringstream ss;
        ss.str("");
        ss << "SubProcessException " << _c_errorno << "desc" << strerror(errno);
        _return_info = ss.str();
    }

    const char *what() const throw() final
    {
        return _return_info.c_str();
    }

    int _c_errorno;
    std::string _return_info;
};

int execute_shell_command(const std::string &command);
}
}
#endif //CEU_SUBPROCESS_HPP
