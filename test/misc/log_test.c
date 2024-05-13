#include "ceu_thirdparty/log.h"
#include <ceu_basic/ceu_fast_macros.h>
#include <stdio.h>

int main(void)
{
    log_set_level(LOG_TRACE);
    log_trace("%d", LOG_TRACE);
    log_debug("%d", LOG_DEBUG);
    log_info("%d", LOG_INFO);
    log_warn("%d", LOG_WARN);
    log_error("%d", LOG_ERROR);
    log_fatal("%d", LOG_FATAL);
    printf("Version: %s\n", LOG_VERSION);
    return EXIT_SUCCESS;
}
