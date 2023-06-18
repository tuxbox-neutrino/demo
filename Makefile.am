## Define here the name of your app
bin_NAME = demo

ACLOCAL_AMFLAGS = \
	-I m4

AM_CXXFLAGS =  \
	-std=c++11

## Uncomment the following line to enable static build
#AM_LDFLAGS = -static

## Define the binary files to be compiled.
## Apps will be built and automatically installed in <prefix>/<bindir>.
bin_PROGRAMS = $(bin_NAME)

## Uncomment the following line if the apps should be installed in <prefix>/<sbindir>.
# sbin_PROGRAMS = $(bin_NAME)

## Uncomment the following line to build apps that will not be installed.
# noinst_PROGRAMS

## Destination install dir, must be used inside install-data-hook.
demodir = $(PLUGINDIR)

## Required source files for compiling
demo_SOURCES = \
	$(bin_NAME).cpp

## Additional data files. Must be handled inside install-data-hook.
demo_DATA = \
	$(bin_NAME).cfg \
	$(bin_NAME)_hint.png

## The variable PN is required to utilize configure options for program names:
##  --program-prefix=PREFIX
##  --program-suffix=SUFFIX
##  --program-transform-name=PROGRAM
## NOTE: All names listed under bin_PROGRAMS, etc., are automatically renamed. This is only necessary for file names 
## that share the same base name, as is typically the case with Neutrino plugins. These plugins are usually installed together 
## with their corresponding .cfg and .png files, or any other files you want to synchronize.
## This ensures synchronized installation or uninstallation within install-data-hook and uninstall-hook and
## allows building functionally equivalent apps from different sources, even if they have the same names (e.g., some forks),
## with customized names. As a result, they can be installed without conflicts.
PN = $(shell echo $(bin_NAME) | sed -e '$(transform)')

install-data-hook:
	ln -sfv $(DESTDIR)/$(bindir)/${PN} $(DESTDIR)/$(demodir)/${PN}.so
	if [ "$(PN)" != "$(bin_NAME)" ]; then \
		mv -f $(DESTDIR)/$(demodir)/$(bin_NAME).cfg $(DESTDIR)/$(demodir)/${PN}.cfg; \
		mv -f $(DESTDIR)/$(demodir)/$(bin_NAME)_hint.png $(DESTDIR)/$(demodir)/${PN}_hint.png; \
	fi
	install -d 644 $(sysconfdir)/$(bin_NAME)

uninstall-hook:
	-rm -f $(DESTDIR)/$(demodir)/${PN}*
	-rm -f $(DESTDIR)/$(bindir)/${PN}

