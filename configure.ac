#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([unifyapi-stub], [0.1], [robl@mcs.anl.gov])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects silent-rules])
AM_SILENT_RULES([yes])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([include/unifyfs_api.h])
AC_CONFIG_HEADERS([config.h])
LT_PREREQ([2.2])
AM_PROG_AR
LT_INIT([dlopen])

# Checks for programs.
AC_PROG_CC
AC_PROG_CC_C_O

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([ftruncate])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
