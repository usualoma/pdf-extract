#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.68)
AC_INIT(pdf-extract, 0.0.2, taku@toi-planning.net)
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([src/pdf-extract-outline.cc])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES(GLIB, glib-2.0)

# Checks for header files.
AC_CHECK_LIB(poppler, [c; char c; int main], , [AC_MSG_ERROR([Can not find poppler.])])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL

# Checks for library functions.

AC_CONFIG_FILES([Makefile src/Makefile test/Makefile])
AC_OUTPUT
