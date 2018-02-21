#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "da.h"
#include "integer.h"
#include "stack.h"

static void showItems(STACK *items) {
	printf("displaySTACK method call: ");
	displaySTACK(stdout, items);
	printf("\n");
}

static void visualizeCall(STACK *items) {
	printf("visualizeSTACK method call: ");
	visualizeSTACK(stdout, items);
	printf("\n");
}

static void sizeCall(STACK *items) {
	int size = sizeSTACK(items);
	printf("sizeSTACK method call: %d\n\n", size);
}

static void popCall(STACK *items, INTEGER *integer) {
	printf("pop method call: ");
	void* value = pop(items);
        displayINTEGER(stdout, value);
	printf("\n");
}

static void peekCall(STACK *items) {
	printf("peekSTACK method call: ");
	void* value = peekSTACK(items);
	displayINTEGER(stdout, value);
	printf("\n");
	showItems(items);
	visualizeCall(items);
}

static void pushCall(STACK *items, INTEGER *integer) {
	printf("push method call: %d", getINTEGER(integer));
	push(items, integer);
	printf("\n");
}

int main(int argc, char **argv) {
	int i;
	if (argc != 1) {
		fprintf(stderr, "usage: %s\n", argv[0]);
		exit(1);
	}

	int SIZE_10 = 10;
	STACK *items = newSTACK(displayINTEGER);
	
	showItems(items);
	visualizeCall(items);
	sizeCall(items);
	
	for(i = 0; i < SIZE_10; i++)
	{
		pushCall(items, newINTEGER(i+1));
		peekCall(items);
	} 
	
	for(i = 0; i < 5; i++) popCall(items, newINTEGER(i+1));
	
	showItems(items);
	visualizeCall(items);
	sizeCall(items);
	
	for(i = 0; i < 5; i++) popCall(items, newINTEGER(i+1));	
	
        showItems(items);
        visualizeCall(items);
        sizeCall(items);
	
        for(i = 0; i < SIZE_10; i++)
        {
                pushCall(items, newINTEGER(i+1));
                peekCall(items);
        }
	return 0;
}


