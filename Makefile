.PHONY: clang-format
clang-format:
	bash clang-format-all.sh

.PHONY: doc
doc:
	doxygen Doxyfile
	$(MAKE) -C doxygen.out.d/latex
