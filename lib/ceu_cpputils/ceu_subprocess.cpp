//
// Created by yuzj on 1/17/22.
//

#include <cstdlib>
#include <cerrno>
#include <string>
#include "ceu_cpputils/ceu_subprocess.hpp"

namespace ceu
{
namespace subprocess
{

int execute_shell_command(const std::string &command)
{
    char const *command_cstr = command.c_str();
    int retv = system(command_cstr);
    if (retv == -1) {
        throw SubProcessException(errno);
    }
    else if (retv == 127) {
        throw SubProcessException(ENOENT);
    }
    else {
        return retv;
    }
}

}
}
