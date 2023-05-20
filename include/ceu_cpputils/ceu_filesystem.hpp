//
// Created by yuzj on 1/16/22.
//

#include <sstream>
#include <vector>
#include "ceu_check/check_os.h"

#ifndef CEU_FILESYSTEM_HPP
#define CEU_FILESYSTEM_HPP


#if defined(CEU_ON_POSIX)

static const char CEU_FILESYSTEM_SEP = '/';

constexpr const char *CEU_FILESYSTEM_SEP_STR = "/";

#else

static const char CEU_FILESYSTEM_SEP = '\\';

static const char *CEU_FILESYSTEM_SEP_STR = "\\";

#endif


namespace ceu
{
namespace filesystem
{
/***
 * @class FSException
 *
 * @description A class which represents underlying C error.
 * @param input_filename Filename which causes error.
 * @param c_error Error number of underlying C error.
 */
class FSException: public std::exception
{
public:
    FSException(std::string const &input_filename, int c_errorno)
    {
        _input_filename = input_filename;
        _c_errorno = c_errorno;
        static std::ostringstream ss;
        ss.str("");
        ss << "FSException from file " << _input_filename << " error=" << _c_errorno << " desc="
           << strerror(errno);
        _return_info = ss.str();
    }

    const char *what() const throw() final
    {
        return _return_info.c_str();
    }

    int _c_errorno;
    std::string _input_filename;
    std::string _return_info;
};

//! A non-except version of getenv.
inline std::string getenv_noexcept(const std::string &env_name)
{
    char *buff = getenv(env_name.c_str());
    if (buff == nullptr) {
        throw FSException(env_name, ENOENT);
    }
    else {
        return std::string(buff);
    }
}

//! Value of `${HOME}` environment variable, indicating user home.
const std::string HOME = getenv_noexcept("HOME");

//! Value of `${PWD}` environment variable, indicating the working directory.
const std::string PWD = getenv_noexcept("PWD");

bool is_absolute_path(const std::string &input_path);

std::string normalize_path(const std::string &input_path);

std::string get_absolute_path(const std::string &input_path);

bool file_exists(const std::string &input_path);

bool is_regular_file(const std::string &input_path);

bool is_file(const std::string &input_path);

bool is_directory(const std::string &input_path);

bool is_readable(const std::string &input_path);

bool is_writable(const std::string &input_path);

bool is_executable(const std::string &input_path);

std::string get_filename(const std::string &input_path);

std::string get_directory_name(const std::string &input_path);

void ensure_directory_exists(const std::string &input_path);

void ensure_file_exists(const std::string &input_path);

std::vector<std::string> list_file_under_directory(const std::string &input_path);

std::vector<std::string> list_file_under_directory_recursive(const std::string &input_path);

void recursive_deletion(const std::string &input_path);

std::string make_temp(bool is_file);

void make_link(std::string &from_path, std::string &to_path, bool is_hard);

std::string resolve_soft_link(const std::string &input_path);

std::string resolve_soft_link_recursive(const std::string &input_path);
/**
 * @description Functions inside deals with C functions and reports errors.
 */
namespace core
{
void core_mkdir(const std::string &input_path);

void core_touch(const std::string &input_path);

struct stat core_stat(const std::string &input_path);

void core_remove(const std::string &input_path);

bool core_access(const std::string &input_path, int check, int c_errorno);

void core_mkfifo(const std::string &input_path);

void core_softlink(const std::string &from_path, const std::string &to_path);

void core_hardlink(const std::string &from_path, const std::string &to_path);

bool can_be_tmp_dir(const std::string &input_path);

std::string get_temp_dir();

std::string core_make_temp(bool is_file, const std::string &temp_template);

std::vector<std::string> split_string(const std::string &s, const std::string &c);
}
}
}
#endif //CEU_FILESYSTEM_HPP
