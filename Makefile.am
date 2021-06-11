ACLOCAL_AMFLAGS="-Im4"
AM_CPPFLAGS = -I$(top_srcdir)/include

lib_LTLIBRARIES = libunifyfs_api.la
libunifyfs_api_la_SOURCES = src/unifyfs_api.c \
		    include/unifyfs_api.h

otherincludedir = $(includedir)/unifyfs
otherinclude_HEADERS = include/unifyfs_api.h

include_HEADERS = include/unifyfs_rc.h \
		  include/unifyfs_configurator.h

libunifyfs_api_la_CPPFLAGS = -I${srcdir}/include

TESTS = tests/rdwr
tests_rdwr_LDADD = libunifyfs_api.la

check_PROGRAMS = ${TESTS}

