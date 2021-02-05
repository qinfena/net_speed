/*
 * Our own header, to be included before all standard system headers.
 */
#ifndef _APUE_H
#define _APUE_H

#include <sys/stat.h>

#include <stdio.h>    /* for convenience */
#include <stdlib.h>     /* for convenience */
#include <unistd.h>    /* for convenience */
#include <string.h>    /* for convenience */

#define MAXLINE 4019    /* max line length */

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

void err_sys(const char *, ...) __attribute__((noreturn));

#endif    /* _APUE_H */
