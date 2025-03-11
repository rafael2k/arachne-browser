
ARACHNE_FILES=distrib/arachne-svgalib-1.95/

all:
	@ echo "Choose the build option:"
	@ echo "sdl2"
	@ echo "svgalib"
	@ echo
	@ echo "To install:"
	@ echo "install_sdl2"
	@ echo "install_svgalib"

sdl2:
	make -C sdl2

svgalib:
	make -C svgalib

install_sdl2: install
	install -D -m 755 -o root -g root sdl2/arachne-sdl2 /usr/bin/arachne-sdl2

install_svgalib: install
	install -D -m 755 -o root -g root svgalib/arachne-svgalib /usr/bin/arachne-svgalib

install:
	install -D -m 644 -o root -g root $(ARACHNE_FILES)/man/man1/arachne.1 /usr/share/man/man1/arachne.1
	mkdir -p /usr/share/doc/arachne/html/
	install -D -m 644 -o root -g root $(ARACHNE_FILES)/doc/arachne/html/* /usr/share/doc/arachne/html/
	mkdir -p /usr/share/arachne/gui/
	install -D -m 644 -o root -g root $(ARACHNE_FILES)/share/arachne/gui/* /usr/share/arachne/gui/
	mkdir -p /usr/share/arachne/ikons/
	install -D -m 644 -o root -g root $(ARACHNE_FILES)/share/arachne/ikons/* /usr/share/arachne/ikons/
	mkdir -p /usr/share/arachne/iso-8859-1/
	cp -r $(ARACHNE_FILES)/share/arachne/iso-8859-1/* /usr/share/arachne/iso-8859-1/
	mkdir -p /usr/share/arachne/iso-8859-2/
	cp -r $(ARACHNE_FILES)/share/arachne/iso-8859-2/* /usr/share/arachne/iso-8859-2/
	mkdir -p /usr/share/arachne/
	install -D -m 644 -o root -g root $(ARACHNE_FILES)/share/arachne/mime.conf /usr/share/arachne/mime.cfg
	install -D -m 644 -o root -g root $(ARACHNE_FILES)/share/arachne/templates/toolbar.cfg /usr/share/arachne/toolbar.cfg
	install -D -m 644 -o root -g root $(ARACHNE_FILES)/share/arachne/templates/entity.cfg /usr/share/arachne/entity.cfg
	install -D -m 644 -o root -g root docs/arachne.cfg /usr/share/arachne/arachne.cfg
clean:
	make -C sdl2 clean
	make -C svgalib clean

.PHONY: sdl2 svgalib clean
