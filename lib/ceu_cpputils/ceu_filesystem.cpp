//
// Created by yuzj on 1/16/22.
//

#include <dirent.h>
#include <cerrno>
#include <fcntl.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/stat.h>
#include <libgen.h>
#include <unistd.h>

#include <string>
#include <vector>

#include "ceu_cpputils/ceu_filesystem.hpp"

namespace ceu
{
namespace filesystem
{

bool is_absolute_path(const std::string &input_path)
{
#ifdef CEU_ON_POSIX
    if (input_path.length() == 0) {
        return false;
    }
    return input_path[0] == CEU_FILESYSTEM_SEP;
#else
    if (input_path.length() < 3){
        return false;
    }
    return 'a' < input_path[0] < 'z' || 'A' < input_path[0] < 'Z' &&
    input_path[1] == ':' &&
    input_path[2] == CEU_FILESYSTEM_SEP
#endif
}

std::string normalize_path(const std::string &input_path)
{
    std::string tmppath = input_path;
    std::string outpath = tmppath;
    // Resolve . and ..
    std::vector<std::string> input_abspath_split = core::split_string(outpath, CEU_FILESYSTEM_SEP_STR);
    std::vector<std::string> input_abspath_join;
    std::stringstream ss; // POSIX version, Windows version not purposed
    for (auto &&item: input_abspath_split) {
        if (item == ".") {
            continue;
        }
        else if (item == "..") {
            input_abspath_join.pop_back();
        }
        else {
            input_abspath_join.push_back(item);
        }
    }
    for (auto &&item: input_abspath_join) {
        ss << CEU_FILESYSTEM_SEP << item;
    }
    outpath = ss.str();
    // Resolve //
    tmppath = outpath;
    ss.str("");
    char curchar = 0;
    char prevchar;
    for (size_t i = 1; i < tmppath.length() + 1; i++) {
        curchar = tmppath[i];
        prevchar = tmppath[i - 1];
        if (curchar != CEU_FILESYSTEM_SEP || prevchar != CEU_FILESYSTEM_SEP) {
            ss << prevchar;
        }
    }
    if (curchar != 0 && curchar != CEU_FILESYSTEM_SEP) {
        ss << curchar;
    }

    outpath = ss.str();
    while (outpath.length() > 1 && outpath.back() == CEU_FILESYSTEM_SEP) {
        outpath.pop_back();
    }
    return outpath;
}

std::string get_absolute_path(const std::string &input_path)
{
    if (is_absolute_path(input_path) || input_path.length() == 0) {
        return normalize_path(input_path);
    }
    std::string tmppath = input_path;
    std::string outpath = tmppath;
    // Resolve ~
    if (input_path[0] == '~') {
        tmppath = HOME + CEU_FILESYSTEM_SEP + input_path.substr(1);
        outpath = tmppath;
    }
    // Resolve ${PWD}
    if (!is_absolute_path(outpath)) {
        tmppath = PWD + CEU_FILESYSTEM_SEP + outpath;
        outpath = tmppath;
    }
    return normalize_path(outpath);
}

bool file_exists(const std::string &input_path)
{
    return core::core_access(input_path, F_OK, ENOENT);
}

bool is_file(const std::string &input_path)
{
    return !is_directory(input_path);
}

bool is_regular_file(const std::string &input_path)
{
    struct stat path_stat = core::core_stat(input_path);
    return S_ISREG(path_stat.st_mode);
}

// TODO: character device, etc.
bool is_directory(const std::string &input_path)
{
    struct stat path_stat = core::core_stat(input_path);
    return S_ISDIR(path_stat.st_mode);
}
bool is_softlink(const std::string &input_path)
{
    struct stat path_stat = core::core_stat(input_path);
    return S_ISLNK(path_stat.st_mode);
}
bool is_readable(const std::string &input_path)
{
    return core::core_access(input_path, R_OK, EACCES);
}

bool is_writable(const std::string &input_path)
{
    return core::core_access(input_path, W_OK, EACCES);
}
bool is_executable(const std::string &input_path)
{
    return core::core_access(input_path, X_OK, EACCES);
}

std::string get_filename(const std::string &input_path)
{
//    std::string::size_type pos;
//    pos = input_path.rfind(CEU_FILESYSTEM_SEP);
//    if (pos == std::string::npos) {
//        return input_path;
//    }
//    else {
//        return input_path.substr(pos);
//    }
    std::string input_abspath = get_absolute_path(input_path);
    auto *input_abspath_cstr = const_cast<char *>(input_abspath.c_str());
    std::string rets = basename(input_abspath_cstr);
    return rets;
}

std::string get_directory_name(const std::string &input_path)
{
//    std::string::size_type pos;
//    pos = input_path.rfind(CEU_FILESYSTEM_SEP);
//    if (pos == std::string::npos) {
//        return input_path;
//    }
//    else {
//        return input_path.substr(0, pos);
//    }
    std::string input_abspath = get_absolute_path(input_path);
    auto *input_abspath_cstr = const_cast<char *>(input_abspath.c_str());
    std::string rets = dirname(input_abspath_cstr);
    return rets;
}

void ensure_directory_exists(const std::string &input_path)
{
    std::string input_abspath = get_absolute_path(input_path);
    if (file_exists(input_abspath)) {
        if (is_directory(input_abspath)) {
            return;
        }
        else {
            throw FSException(input_abspath, ENOTDIR);
        }
    }
    std::vector<std::string> input_abspath_split = core::split_string(input_abspath, CEU_FILESYSTEM_SEP_STR);
    std::string sb = CEU_FILESYSTEM_SEP_STR; // POSIX version, Windows version not purposed
    for (auto &&item: input_abspath_split) {
        sb.append(item);
        if (file_exists(sb)) {
            if (!is_directory(sb)) {
                throw FSException(sb, ENOTDIR);
            }
        }
        else {
            core::core_mkdir(sb);
        }
        sb.append(CEU_FILESYSTEM_SEP_STR);
    }
}

void ensure_file_exists(const std::string &input_path)
{
    std::string input_abspath = get_absolute_path(input_path);
    if (file_exists(input_abspath)) {
        if (is_file(input_abspath)) {
            return;
        }
        else {
            throw FSException(input_abspath, EISDIR);
        }
    }
    std::string filename = get_filename(input_abspath);
    std::string dirname = get_directory_name(input_abspath);
    ensure_directory_exists(dirname);
    core::core_touch(input_abspath);
}

std::vector<std::string> list_file_under_directory(const std::string &input_path)
{
    std::string input_abspath = get_absolute_path(input_path);
    if (file_exists(input_abspath)) {
        if (!is_directory(input_abspath)) {
            return std::vector<std::string>{input_abspath};
        }
    }
    else {
        throw FSException(input_abspath, ENOENT);
    }
    DIR *dir;
    struct dirent *dir_ptr;
    std::vector<std::string> retv{input_abspath};
    const char *input_abspath_cstr = input_abspath.c_str();
    dir = opendir(input_abspath_cstr);
    if (dir == nullptr) {
        throw FSException(input_abspath, errno);
    }
    while ((dir_ptr = readdir(dir)) != nullptr) {
        if (strcmp(dir_ptr->d_name, ".") != 0 && strcmp(dir_ptr->d_name, "..") != 0) {
            std::string path = input_abspath + CEU_FILESYSTEM_SEP + dir_ptr->d_name;
            retv.emplace_back(path);
        }
    }
    closedir(dir);
    return retv;
}
std::vector<std::string> list_file_under_directory_recursive(const std::string &input_path)
{
    std::string input_abspath = get_absolute_path(input_path);
    std::vector<std::string> retv = list_file_under_directory(input_abspath);
    std::vector<std::string> dirs;
    for (auto &&name: retv) {
        if (is_directory(name) && name != input_abspath) {
            dirs.emplace_back(name);
        }
    }
    for (auto &&dir_name: dirs) {
        std::vector<std::string> retv_dir = list_file_under_directory_recursive(dir_name);
        retv.insert(retv.end(), retv_dir.begin() + 1, retv_dir.end());
    }
    return retv;
}

void recursive_deletion(const std::string &input_path)
{
    std::string input_abspath = get_absolute_path(input_path);
    if (!file_exists(input_abspath)) {
        return;
    }
    std::vector<std::string> retv_dir = list_file_under_directory_recursive(input_abspath);
    if (retv_dir.empty()) {
        return;
    }
    for (size_t i = retv_dir.size() - 1; i > 0; i--) {
        // printf("%s\n", retv_dir[i].c_str());
        core::core_remove(retv_dir[i]);
    }
    core::core_remove(input_abspath);
}

std::string make_temp(bool is_file)
{
    std::string temp_template = core::get_temp_dir() + CEU_FILESYSTEM_SEP + "temp.XXXXXX";
    return core::core_make_temp(is_file, temp_template);
}

void make_link(std::string &from_path, std::string &to_path, bool is_hard)
{
    std::string to_dirname_abspath = get_directory_name(get_absolute_path(to_path));
    ensure_directory_exists(to_dirname_abspath);
    if (is_hard) {
        core::core_hardlink(from_path, to_path);
    }
    else {
        core::core_softlink(from_path, to_path);
    }
}

std::string resolve_soft_link(const std::string &input_path)
{
    std::string input_abspath = get_absolute_path(input_path);
    auto const *input_abspath_cstr = input_abspath.c_str();
    char buf[1024];
    ssize_t len;
    if ((len = readlink(input_abspath_cstr, buf, sizeof(buf) - 1)) != -1) {
        buf[len] = '\0';
        return std::string(buf);
    }
    else {
        throw FSException(input_abspath, errno);
    }
}

std::string resolve_soft_link_recursive(const std::string &input_path)
{
    std::string tmp_path = get_absolute_path(input_path);
    while (is_softlink(tmp_path)) {
        tmp_path = resolve_soft_link(tmp_path);
    }
    return tmp_path;
}

namespace core
{
void core_mkdir(const std::string &input_path)
{
    std::string input_abspath = get_absolute_path(input_path);
    const char *input_abspath_cstr = input_abspath.c_str();
    if (mkdir(input_abspath_cstr, S_IRWXU) == -1) {
        throw FSException(input_abspath, errno);
    }
}
void core_touch(const std::string &input_path)
{
    std::string input_abspath = get_absolute_path(input_path);
    const char *input_abspath_cstr = input_abspath.c_str();
    int fd = open(input_abspath_cstr, O_CREAT | O_APPEND);
    if (fd == -1) {
        throw FSException(input_abspath, errno);
    }
    close(fd);
}
struct stat core_stat(const std::string &input_path)
{
    std::string input_abspath = get_absolute_path(input_path);
    const char *input_abspath_cstr = input_abspath.c_str();
    struct stat path_stat;
    if (lstat(input_abspath_cstr, &path_stat) == -1) {
        throw FSException(input_abspath, errno);
    }
    return path_stat;
}

void core_remove(const std::string &input_path)
{
    std::string input_abspath = get_absolute_path(input_path);
    const char *input_abspath_cstr = input_abspath.c_str();
    if (is_directory(input_abspath)) {
        if (rmdir(input_abspath_cstr) != 0) {
            throw FSException(input_abspath, errno);
        }
    }
    else {
        if (remove(input_abspath_cstr) != 0) {
            throw FSException(input_abspath, errno);
        }
    }
}

bool core_access(const std::string &input_path, int check, int c_errorno)
{
    std::string input_abspath = get_absolute_path(input_path);
    const char *input_abspath_cstr = input_abspath.c_str();
    if (access(input_abspath_cstr, check) == 0) {
        return true;
    }
    else {
        if (errno == c_errorno) {
            return false;
        }
        else {
            throw FSException(input_abspath, errno);
        }
    }
}

void core_mkfifo(const std::string &input_path)
{
    std::string input_abspath = get_absolute_path(input_path);
    const char *input_abspath_cstr = input_abspath.c_str();
    if (mkfifo(input_abspath_cstr, 0666) != 0) {
        throw FSException(input_abspath, errno);
    }
}

void core_softlink(const std::string &from_path, const std::string &to_path)
{
    std::string from_abspath = get_absolute_path(from_path);
    const char *from_abspath_cstr = from_abspath.c_str();
    std::string to_abspath = get_absolute_path(to_path);
    const char *to_abspath_cstr = to_abspath.c_str();
    if (symlink(from_abspath_cstr, to_abspath_cstr) != 0) {
        throw FSException(from_abspath + "->" + to_abspath, errno);
    }
}

void core_hardlink(const std::string &from_path, const std::string &to_path)
{
    std::string from_abspath = get_absolute_path(from_path);
    const char *from_abspath_cstr = from_abspath.c_str();
    std::string to_abspath = get_absolute_path(to_path);
    const char *to_abspath_cstr = to_abspath.c_str();
    if (link(from_abspath_cstr, to_abspath_cstr) != 0) {
        throw FSException(from_abspath + "->" + to_abspath, errno);
    }
}

//! Internal method telling whether a directory can be temp.
bool can_be_tmp_dir(const std::string &input_path)
{
    std::string input_abspath = get_absolute_path(input_path);
    return file_exists(input_abspath) &&
        is_directory(input_abspath) &&
        is_writable(input_abspath) &&
        is_executable(input_abspath);
}

std::string get_temp_dir()
{
    // Firstly, try to get TMP, TMPDIR or TEMP environment variable.
    std::vector<std::string> try_env_list = {
        "TMP", "TMPDIR", "TMP_DIR", "TEMP", "TEMPDIR", "TEMP_DIR"
    };
    for (auto &&env_name: try_env_list) {
        char *env_val = getenv(env_name.c_str());
        if (env_val != nullptr) {
            std::string dir_name = env_val;
            if (can_be_tmp_dir(dir_name)) {
                return dir_name;
            }
        }
    }

// Try common names
#ifdef CEU_ON_POSIX
    std::vector<std::string> try_dir_list = {
        "/tmp",
        "/var/tmp",
        "/usr/tmp",
    };
#else
    std::vector<std::string> try_dir_list = {
        "~\\AppData\\Local\\Temp",
        "C:\\TEMP",
        "C:\\TMP",
    };
#endif
    for (auto &&dir_name: try_dir_list) {
        if (can_be_tmp_dir(dir_name)) {
            return dir_name;
        }
    }
    // Finally, ${PWD}.
    std::string dir_name = get_absolute_path("tmp") + CEU_FILESYSTEM_SEP + "tmp";
    ensure_directory_exists(dir_name);
    return dir_name;
}

std::string core_make_temp(bool is_file, const std::string &temp_template)
{
    auto *temp_template_cstr = const_cast<char *>(temp_template.c_str());
    char const *ret_desc;
    if (is_file) {
        ret_desc = mktemp(temp_template_cstr);
    }
    else {
        ret_desc = mkdtemp(temp_template_cstr);
    }
    if (ret_desc == nullptr) {
        throw FSException("mktemp", errno);
    }
    else {
        return std::string(ret_desc);
    }
}
std::vector<std::string> split_string(const std::string &s, const std::string &c)
{
    std::vector<std::string> v;
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2) {
        v.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
    return v;
}
}
}
}


