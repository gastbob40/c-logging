#include <unistd.h>

#include "lib/logger.h"

int main(void)
{
    print_success("Some good news");
    print_fatal("Some bad news");

    struct progress *progress = progress_init(100, "All is good");

    for (size_t i = 0; i < 100; i++)
    {
        progress_advance(progress);
        usleep(1000 * 100);
    }
}