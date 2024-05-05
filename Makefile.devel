.PHONY: fmt
fmt:
	bash fmt.sh


.PHONY: html
html:
	doxygen Doxyfile.ini

.PHONY: doc
doc: html
	$(MAKE) -C doxygen.out.d/latex

.PHONY: autotools
autotools:
	autoreconf -if -Wall
	mkdir -p autotools
	cd autotools && ../configure

.PHONY: cmake-build
cmake-build:
	mkdir -p cmake-build && \
	cd cmake-build && \
	cmake -Wdev -Wdeprecated --warn-uninitialized -DCMAKE_BUILD_TYPE=Debug .. && \
	cmake --build . --clean-first --parallel 40 && \
	ctest

.PHONY: xmake-build
xmake-build:
	mkdir -p xmake-build && \
	cd xmake-build && \
	xmake build -P ..
