//
// Created by yuzj on 1/16/22.
//
#include <cstdio>
#include <cstring>
#include <gtest/gtest.h>

#include "ceu_cpputils/ceu_filesystem.hpp"
#include "ceu_cpputils/ceu_subprocess.hpp"
#include "ceu_cpputils/ceu_users.hpp"
#include "ceu_check/check_all.h"
using namespace ceu::filesystem;

namespace test_ceu_filesystem
{
class CEU_FS_TEST: public testing::Test
{
//protected:
//    CpptetgsTest(){};
//    ~CpptetgsTest() override {};
//    void SetUp() override{};
//    void TearDown() override{};
};
TEST_F(CEU_FS_TEST, test_is_absolute_path)
{
    // TODO: POSIX platform, Windows not tested
    EXPECT_FALSE(is_absolute_path(""));
    EXPECT_TRUE(is_absolute_path("/"));
    EXPECT_TRUE(is_absolute_path("/aaa"));
    EXPECT_TRUE(is_absolute_path("/aaa/"));

    EXPECT_FALSE(is_absolute_path("aaa"));
    EXPECT_FALSE(is_absolute_path("aaa/"));
    EXPECT_FALSE(is_absolute_path("~/aaa/"));
    EXPECT_FALSE(is_absolute_path("D:\\aaa"));
}

std::string ensure_tailing_slash(std::string input_str)
{
    if (input_str.back() == CEU_FILESYSTEM_SEP) {
        return input_str;
    }
    else {
        return input_str + CEU_FILESYSTEM_SEP;
    }
}

TEST_F(CEU_FS_TEST, test_get_absolute_path)
{
    // TODO: POSIX platform, Windows not tested
    std::string HOMES = ensure_tailing_slash(HOME);
    std::string PWDS = ensure_tailing_slash(PWD);
    EXPECT_EQ(get_absolute_path(""), "");
    EXPECT_EQ(get_absolute_path("/"), "/");

    EXPECT_EQ(get_absolute_path("/aaa"), "/aaa");
    EXPECT_EQ(get_absolute_path("/aaa/"), "/aaa");

    EXPECT_EQ(get_absolute_path("."), PWD);
    EXPECT_EQ(get_absolute_path("./"), PWD);
    EXPECT_EQ(get_absolute_path("./aaa"), PWDS + "aaa");

    EXPECT_EQ(get_absolute_path("aaa"), PWDS + "aaa");
    EXPECT_EQ(get_absolute_path("aaa/"), PWDS + "aaa");

    EXPECT_EQ(get_absolute_path("~/aaa/"), HOMES + "aaa");
    EXPECT_EQ(get_absolute_path("~"), HOME);
    EXPECT_EQ(get_absolute_path("~/"), HOME);
}
TEST_F(CEU_FS_TEST, test_stat)
{
    EXPECT_TRUE(is_directory("/"));
    EXPECT_TRUE(is_directory("~"));
    EXPECT_TRUE(is_directory("~/"));
    EXPECT_TRUE(is_directory("//"));
    EXPECT_TRUE(is_directory("/tmp"));
    EXPECT_TRUE(is_directory("/var/"));

    EXPECT_FALSE(is_regular_file("/"));
    EXPECT_FALSE(is_regular_file("~"));
    EXPECT_FALSE(is_regular_file("~/"));
    EXPECT_FALSE(is_regular_file("//"));
    EXPECT_FALSE(is_regular_file("/tmp"));
    EXPECT_FALSE(is_regular_file("/var/"));

    EXPECT_TRUE(is_regular_file("/etc/fstab"));
    EXPECT_FALSE(is_directory("/etc/fstab"));
    EXPECT_TRUE(is_readable("/etc/fstab"));
    EXPECT_EQ(is_writable("/etc/fstab"), ceu::users::is_running_as_root());
    EXPECT_FALSE(is_executable("/etc/fstab"));
    EXPECT_FALSE(is_readable("/etc/shadow"));

}

TEST_F(CEU_FS_TEST, test_filename_dirname)
{
    // TODO: POSIX platform, Windows not tested
    std::string HOMES = ensure_tailing_slash(HOME);
    std::string PWDS = ensure_tailing_slash(PWD);
    EXPECT_EQ(get_filename("/etc/fstab"), "fstab");
    EXPECT_EQ(get_filename("/etc/fstab/"), "fstab");
    EXPECT_EQ(get_filename("/fstab/"), "fstab");
    EXPECT_EQ(get_filename("/etc/fstab"), "fstab");
    EXPECT_EQ(get_filename("~/fstab/"), "fstab");
    EXPECT_EQ(get_filename("./fstab/"), "fstab");
    EXPECT_EQ(get_filename("fstab/"), "fstab");
    EXPECT_EQ(get_filename("fstab"), "fstab");

    EXPECT_EQ(get_directory_name("/etc/fstab"), "/etc");
    EXPECT_EQ(get_directory_name("/etc/fstab/"), "/etc");
    EXPECT_EQ(get_directory_name("//app/etc/fstab/"), "/app/etc");
    EXPECT_EQ(get_directory_name("/fstab/"), "/");
    EXPECT_EQ(get_directory_name("/etc/fstab"), "/etc");
    EXPECT_EQ(get_directory_name("~/fstab/"), HOME);
    EXPECT_EQ(get_directory_name("./fstab/"), PWD);
    EXPECT_EQ(get_directory_name("fstab/"), PWD);
    EXPECT_EQ(get_directory_name("fstab"), PWD);
}
TEST_F(CEU_FS_TEST, test_ls_ls_r)
{
    std::string tmp_dir = make_temp(false);
    std::string tmp_file = tmp_dir + CEU_FILESYSTEM_SEP + "aaa" + CEU_FILESYSTEM_SEP + "a";
    std::string symlink = tmp_dir + CEU_FILESYSTEM_SEP + "aa1" + CEU_FILESYSTEM_SEP + "a1";
    std::string symlink2 = tmp_dir + CEU_FILESYSTEM_SEP + "aa1" + CEU_FILESYSTEM_SEP + "a2";
    std::string empty_dir = tmp_dir + CEU_FILESYSTEM_SEP + "bbb";

    ensure_file_exists(tmp_file);
    ensure_directory_exists(empty_dir);
    make_link(tmp_file, symlink, false);
    make_link(symlink, symlink2, false);

    EXPECT_TRUE(file_exists(tmp_dir));
    EXPECT_TRUE(file_exists(tmp_file));
    EXPECT_TRUE(file_exists(symlink));
    EXPECT_TRUE(file_exists(empty_dir));
    EXPECT_TRUE(is_regular_file(tmp_file));
    EXPECT_FALSE(is_regular_file(symlink));
    EXPECT_TRUE(is_directory(empty_dir));
    EXPECT_EQ(resolve_soft_link_recursive(symlink2), tmp_file);

//    std::vector<std::string> retv_dir = list_file_under_directory_recursive(tmp_dir);
//    for (int i = retv_dir.size() - 1; i >= 0; i--) {
//        printf("%s\n", retv_dir[i].c_str());
//    }

    recursive_deletion(tmp_dir);
    EXPECT_FALSE(file_exists(tmp_file));
    EXPECT_FALSE(file_exists(symlink));
    EXPECT_FALSE(file_exists(empty_dir));
    EXPECT_FALSE(file_exists(tmp_dir));
}
}

int main(int argc, char **argv)
{
    char buff[4096];
    memset(buff, 0, sizeof(buff));
    get_full_info(buff);
    printf("%s\n", buff);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

