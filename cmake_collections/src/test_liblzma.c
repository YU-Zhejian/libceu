#include <stddef.h>
#include <stdio.h>
#include <lzma.h>
#include <string.h>


int main()
{
	printf("liblzma version: %s\n", LZMA_VERSION_STRING);
	return 0;
}
