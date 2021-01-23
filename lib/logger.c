#include "logger.h"

#include <stdio.h>
#include <stdlib.h>

struct progress *progress_init(size_t _progress_total, char *_complete_message)
{
    struct progress *progress = malloc(sizeof(struct progress));
    progress->progress_count = 0;
    progress->progress_total = _progress_total;
    progress->complete_message = _complete_message;
}

void progress_advance(struct progress *progress)
{
    progress->progress_count++;
    // Go at the beginning of the line
    printf(" \33[2K\r%zu/%zu [", progress->progress_count,
           progress->progress_total);

    // Get the % of the list
    size_t progress_done = progress->progress_count * PROGRESS_BAR_LENGTH
        / progress->progress_total;
    size_t progress_percentage =
        progress->progress_count * 100 / progress->progress_total;

    for (size_t i = 0; i < progress_done; i++)
        printf("=");

    printf(">");
    for (size_t i = progress_done + 1; i < PROGRESS_BAR_LENGTH; i++)
        printf("-");

    printf("] %zu%%", progress_percentage);

    fflush(stdout);

    if (progress->progress_count == progress->progress_total)
    {
        print_success(progress->complete_message);
        free(progress);
    }
}

void print_success(char *msg)
{
    printf("\33[2K\r%s[OK] %s%s\n", TERM_COLOR_GREEN, TERM_COLOR_RESET, msg);
}

void print_fatal(char *msg)
{
    printf("\33[2K\r%s[ERROR] %s%s\n", TERM_COLOR_RED, TERM_COLOR_RESET, msg);
}