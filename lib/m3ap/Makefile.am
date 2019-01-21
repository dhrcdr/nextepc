## Process this file with automake to produce Makefile.in

SUBDIRS = asn1c

pkglib_LTLIBRARIES = libm3ap.la

libm3ap_la_SOURCES = \
	m3ap_decoder.c m3ap_encoder.c m3ap_free.c \
	$(NULL)

libm3ap_la_DEPENDENCIES = \
    $(top_srcdir)/lib/core/src/libcore.la \
    $(top_srcdir)/lib/m3ap/asn1c/libm3apasn1c.la \
	$(NULL)

libm3ap_la_LIBADD = \
    $(top_srcdir)/lib/core/src/libcore.la \
    $(top_srcdir)/lib/m3ap/asn1c/libm3apasn1c.la \
	$(NULL)

AM_LDFLAGS = \
	-version-info @LIBVERSION@

AM_CPPFLAGS = \
    -I$(top_srcdir)/lib/core/include \
    -I$(top_srcdir)/lib/m3ap/asn1c \
	$(NULL)

AM_CFLAGS = \
	-Wall -Werror \
	$(NULL)

MAINTAINERCLEANFILES = Makefile.in 
MOSTLYCLEANFILES = *.stackdump
