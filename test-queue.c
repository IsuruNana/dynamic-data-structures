#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "integer.h"
#include "queue.h"

static void showItems(QUEUE *items) {
	printf("displayQUEUE method call: ");
	displayQUEUE(stdout, items);
	printf("\n");
}

static void visualizeCall(QUEUE *items) {
	printf("visualizeQUEUE method call: ");
	visualizeQUEUE(stdout, items);
	printf("\n");
}

static void sizeCall(QUEUE *items) {
	int size = sizeQUEUE(items);
	printf("sizeQUEUE method call: %d\n\n", size);
}

static void queueCall(QUEUE *items, INTEGER *integer) {
	printf("enqueue method call: ");
	enqueue(items, integer);
	showItems(items);
	visualizeCall(items);	
}

static void dequeueCall(QUEUE *items) {
	printf("dequeueCall method call: ");
	dequeue(items);
	visualizeCall(items);
}

static void peekCall(QUEUE *items) {
	printf("peekCall method call: ");
	void* value = peekQUEUE(items);
	displayINTEGER(stdout, value);
	printf("\n");
}

int main(int argc, char **argv) {
	int i;
	if (argc != 1) {
		fprintf(stderr, "usage: %s\n", argv[0]);
		exit(1);
	}

	int SIZE_10 = 10;
	QUEUE *items = newQUEUE(displayINTEGER);
	
	showItems(items);
	visualizeCall(items);
	sizeCall(items);
	
	for(i = 0; i < SIZE_10; i++)
	{
		queueCall(items, newINTEGER(i+1));
	}
	
	peekCall(items);

	showItems(items);
        visualizeCall(items);
        sizeCall(items);
	
	for(i = 0; i < SIZE_10; i++)
	{
		dequeueCall(items);
	}
	
	showItems(items);
        visualizeCall(items);
        sizeCall(items);

	for(i = 0; i < 8; i++)
        {
                queueCall(items, newINTEGER(i+1));
        }

	for(i = 0; i < 3; i++)
        {
               dequeueCall(items);
        }

	peekCall(items);

	for(i = 0; i < 4; i++)
        {
                queueCall(items, newINTEGER(i+1));
        }

	for(i = 0; i < 9; i++)
        {
               dequeueCall(items);
        }

	return 0;
}


