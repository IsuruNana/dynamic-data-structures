#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "da.h"
#include "integer.h"

static void showItems(DA *items) {
	printf("displayDA method call: ");
	displayDA(stdout, items);
	printf("\n");
}

static void visualizeCall(DA *items) {
	printf("visualizeDA method call: ");
	visualizeDA(stdout, items);
	printf("\n");
}

static void sizeCall(DA *items) {
	int size = sizeDA(items);
	printf("sizeDA method call: %d\n\n", size);
}

static void insertValue(DA *items, INTEGER *integer)
{
	printf("inserting %d: ", getINTEGER(integer));
	insertDA(items, integer);
	visualizeCall(items);
}

static void deleteValue(DA *items)
{
	printf("deleting value: ");
	removeDA(items);
	visualizeCall(items);
}

static void getCall(DA *items, int index)
{	
        printf("value at %d: ", index);
        void *value = getDA(items, index);
	displayINTEGER(stdout, value);
	printf("\n");
}

static void setCall(DA *items, int index, void *value)
{
        void *oldValue = setDA(items, index, value);
        if(oldValue != NULL) 
	{
	printf("replaced %d with %d\n", getINTEGER(oldValue), getINTEGER(value));
	}
	else
	{
	printf("Value is NULL\n");
	}
 
}

int main(int argc, char **argv) {
	if (argc != 1) {
		fprintf(stderr, "usage: %s\n", argv[0]);
		exit(1);
	}

	int i;
	int SIZE_10 = 10;
	DA *items = newDA(displayINTEGER);
	DA *items2 = newDA(displayINTEGER);

	showItems(items);
	visualizeCall(items);
	sizeCall(items);
	
	for(i = 0; i < SIZE_10; i++) insertValue(items, newINTEGER(i+1));

	for(int i = 0; i < SIZE_10; i++) deleteValue(items);
	
	for(i = 0; i < SIZE_10; i++) insertValue(items, newINTEGER(i+1));
	for(i = 0; i < 5; i++) insertValue(items2, newINTEGER(i+1));
	
	unionDA(items, items2);
	
	visualizeCall(items);
	visualizeCall(items2);
	
	for(i = 0; i < 8; i++) insertValue(items2, newINTEGER(i+1));
		
	for(i = 0; i < sizeDA(items)-5; i++) getCall(items, i);
	
	extractDA(items);
	for(i = 0; i < SIZE_10; i++) insertValue(items, newINTEGER(i+1));	

	for(i = 0; i < sizeDA(items); i++) 
	{
		setCall(items, i, newINTEGER(i+30));	
	}
	
	visualizeCall(items);
	sizeCall(items);

	setCall(items, sizeDA(items), newINTEGER(9));
	setCall(items, sizeDA(items), newINTEGER(343));
	setCall(items, sizeDA(items), newINTEGER(213));
	visualizeCall(items);
	/*printf("DA tester: 1,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-1-3.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    void *p = 0;
    printf("inserting items into array d\n");
    insertDA(d,newINTEGER(807));
    insertDA(d,newINTEGER(89));
    insertDA(d,newINTEGER(656));
    insertDA(d,newINTEGER(991));
    insertDA(d,newINTEGER(44));
    insertDA(d,newINTEGER(921));
    insertDA(d,newINTEGER(365));
    insertDA(d,newINTEGER(880));
    insertDA(d,newINTEGER(1));
    insertDA(d,newINTEGER(303));
    insertDA(d,newINTEGER(981));
    insertDA(d,newINTEGER(948));
    insertDA(d,newINTEGER(28));
    insertDA(d,newINTEGER(419));
    insertDA(d,newINTEGER(894));
    insertDA(d,newINTEGER(318));
    insertDA(d,newINTEGER(701));
    insertDA(d,newINTEGER(642));
    insertDA(d,newINTEGER(688));
    insertDA(d,newINTEGER(928));
    insertDA(d,newINTEGER(823));
    insertDA(d,newINTEGER(619));
    insertDA(d,newINTEGER(993));
    insertDA(d,newINTEGER(517));
    insertDA(d,newINTEGER(567));
    insertDA(d,newINTEGER(97));
    insertDA(d,newINTEGER(532));
    insertDA(d,newINTEGER(135));
    insertDA(d,newINTEGER(72));
    insertDA(d,newINTEGER(877));
    insertDA(d,newINTEGER(510));
    insertDA(d,newINTEGER(879));
    insertDA(d,newINTEGER(318));
    insertDA(d,newINTEGER(519));
    insertDA(d,newINTEGER(223));
    printf("array d: ");
    visualizeDA(stdout,d);
    printf("\n");
    printf("removing all but one item from array d\n");
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    printf("array d: ");
    visualizeDA(stdout,d);
    printf("\n");
    printf("removing the last item from array d\n");
    p = removeDA(d);
    printf("array d: ");
    visualizeDA(stdout,d);
    printf("\n");
    printf("inserting one item into array d\n");
    insertDA(d,newINTEGER(715));
    printf("array d: ");
    visualizeDA(stdout,d);
    printf("\n");
    printf("removing that item\n");
    p = removeDA(d);
    printf("array d: ");
    visualizeDA(stdout,d);
    printf("\n");
    printf("last element removed: ");
    displayINTEGER(stdout,p);
    printf("\n");*/

	return 0;
}
