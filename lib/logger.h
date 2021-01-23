#ifndef LOGGER_H
#define LOGGER_H

#include <stddef.h>

#define PROGRESS_BAR_LENGTH 28
#define TERM_COLOR_RESET "\x1B[0m"
#define TERM_COLOR_GREEN "\x1B[32m"
#define TERM_COLOR_RED "\x1B[31m"

struct progress
{
    size_t progress_count;
    size_t progress_total;
    char *complete_message;
};

/// @brief Advance the progress bar
void progress_advance(struct progress *progress);

/// @brief Init the progress bar
/// @param _progress_total The max number of item in the progress bar
/// @param _complete_message The message when completed
/// @return A progress struct
struct progress *progress_init(size_t _progress_total, char *_complete_message);

/// @brief Print a success message
/// @param msg The message
void print_success(char *msg);

/// @brief Print an error message
/// @param msg The error message
void print_fatal(char *msg);

#endif // LOGGER_H
