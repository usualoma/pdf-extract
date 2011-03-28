#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.68)
AC_INIT(pdf-extract, 0.0.4, taku@toi-planning.net)
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([src/pdf-extract-outline.cc])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
AC_CHECK_LIB([gtest], [main])
AM_CONDITIONAL(HAVE_LIBGTEST, test x$ac_cv_lib_gtest_main = xyes)
AC_CHECK_LIB([poppler], [main], , [AC_MSG_ERROR([Can not find poppler.])])

# Checks for header files.
AC_CHECK_HEADER(
                [poppler/poppler-config.h],
                ,
                [AC_MSG_ERROR([Can not find "poppler/poppler-config.h".])]
                )

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 test/Makefile])
AC_OUTPUT
