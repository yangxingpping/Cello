
#include "ud.h"

#include "../include/Cello.h"

#include "vld.h"


void alloc1(var args) {
	printf("user alloc1\n");
	struct UserAllocMem* p = get(args, $I(0));
	p->len = c_int(get(get(args, $I(1)), $I(2)));
	p->pt = (char*)malloc(p->len);

	int y = 1;
}

void delloc1(var self) {
	struct UserAllocMem* p = get(self, $I(0));
	printf("user delloc1\n");
	if (p)
	{
		if (p->pt)
		{
			free(p->pt);
			p->pt = NULL;
			p->len = 0;
		}
	}
}

int main(int argc, char** argv)
{
	with(f in new(Demo, new(Function, &alloc1), new(Function, &delloc1), $I(32)))
	{
		
	}

	/*with(f in new(File, $S("hello.txt"), $S("r"))) {

	}*/

    return 0;
}
