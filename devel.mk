

CC ?= $(which gcc)
CXX ?= $(which g++)


.PHONY: fmt
fmt:
	bash fmt.sh


.PHONY: html
html:
	doxygen Doxyfile.ini

.PHONY: doc
doc: html
	$(MAKE) -C doxygen.out.d/latex

.PHONY: autotools-build
autotools-build:
	autoreconf -if -Wall
	mkdir -p autotools-build
	cd autotools-build && ../configure

.PHONY: cmake-build
cmake-build:
	rm -fr cmake-build cmake-install
	mkdir -p cmake-build cmake-install
	env -i -C cmake-build  PATH='/usr/bin' \
		cmake \
		-Wdev \
		-Wdeprecated \
		--warn-uninitialized \
		-DCMAKE_BUILD_TYPE=Debug .. \
		-DCMAKE_INSTALL_PREFIX=$(CURDIR)/cmake-install
	env -i -C cmake-build  PATH='/usr/bin' \
		cmake --build . --clean-first --parallel 40
	env -i -C cmake-build  PATH='/usr/bin' \
    	ctest
	env -i -C cmake-build  PATH='/usr/bin' \
		cmake --install .

.PHONY: xmake-build
xmake-build:
	mkdir -p xmake-build && \
	cd xmake-build && \
	xmake build -P ..
