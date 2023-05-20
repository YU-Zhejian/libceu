//
// Created by yuzj on 1/17/22.
//
#include "ceu_check/check_os.h"
#include "ceu_cpputils/ceu_users.hpp"
#ifdef CEU_ON_POSIX
#include <unistd.h>
namespace ceu
{
namespace users
{
bool is_running_as_root()
{
    return geteuid() == 0;
}

bool is_running_as_someone_else()
{
    return getuid() == geteuid();
}
}
}

#else
#include <securitybaseapi.h>
namespace ceu {
    namespace users {
        // From https://docs.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-checktokenmembership
        bool is_running_as_root() {
            bool b;
            SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
            PSID AdministratorsGroup;
            b = AllocateAndInitializeSid(
                &NtAuthority,
                2,
                SECURITY_BUILTIN_DOMAIN_RID,
                DOMAIN_ALIAS_RID_ADMINS,
                0, 0, 0, 0, 0, 0,
                &AdministratorsGroup);
            if (b)
            {
                if (!CheckTokenMembership(NULL, AdministratorsGroup, &b))
                {
                    b = FALSE;
                }
                FreeSid(AdministratorsGroup);
            }
            return(b);
        }

        bool is_running_as_someone_else()
        {
            return false; // TODO
        }
    }
}
#endif // CEU_ON_POSIX




