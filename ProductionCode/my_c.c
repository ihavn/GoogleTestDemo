#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <stdlib.h>

#include "my_c.h"

void * allocateMem(int bytes) {
	return malloc(bytes);
}
void freeMem(void* p) {
	free(p);
}