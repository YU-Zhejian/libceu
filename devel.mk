export SHELL ?= $(shell which bash || which sh)
export CC ?= $(shell which gcc)
export CXX ?= $(shell which g++)
export CMAKE_GENERATOR ?= $(shell which -s ninja && echo "Ninja" || echo "Unix Makefiles")
export CMAKE_BUILD_TYPE ?= Debug

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
	rm -fr autotools-build autotools-install
	mkdir -p autotools-build autotools-install
	autoreconf -ifv -Wall
	env -i -C autotools-build PATH='/usr/bin' ../configure --prefix=$(pwd)/autotools-install

.PHONY: cmake-build
cmake-build:
	rm -fr cmake-build cmake-install
	mkdir -p cmake-build cmake-install
	env -i -C cmake-build PATH='/usr/bin' \
		cmake \
		-G $(CMAKE_GENERATOR) \
		-Wdev \
		-Wdeprecated \
		--warn-uninitialized \
		-DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE) \
		-DCMAKE_INSTALL_PREFIX=$(CURDIR)/cmake-install \
		-DCMAKE_C_COMPILER=$(CC) \
		-DCMAKE_CXX_COMPILER=$(CXX) \
		 ..
	env -i -C cmake-build PATH='/usr/bin' cmake --build . --clean-first --parallel 40
	env -i -C cmake-build PATH='/usr/bin' ctest
	env -i -C cmake-build PATH='/usr/bin' cmake --install .
	env -i -C cmake-build PATH='/usr/bin' cpack --config CPackConfig.cmake -G TGZ

.PHONY: xmake-build
xmake-build:
	mkdir -p xmake-build && \
	cd xmake-build && \
	xmake build -P ..
