#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "cda.h"
#include "integer.h"

static void showItems(CDA *items) {
	printf("displayCDA method call: ");
	displayCDA(stdout, items);
	printf("\n");
}

static void visualizeCall(CDA *items) {
	printf("visualizeCDA method call: ");
	visualizeCDA(stdout, items);
	printf("\n");
}

static void sizeCall(CDA *items) {
	int size = sizeCDA(items);
	printf("sizeCDA method call: %d\n\n", size);
	printf("\n");
}

static void insertValueFront(CDA *items, INTEGER *integer)
{
	printf("inserting %d at front: ", getINTEGER(integer));
	insertCDAfront(items, integer);
	visualizeCall(items);
}

static void insertValueBack(CDA *items, INTEGER *integer)
{
	printf("inserting %d at back: ", getINTEGER(integer));
	insertCDAback(items, integer);
	visualizeCall(items);
}

static void deleteValueFront(CDA *items)
{
	printf("deleting front: ");
	removeCDAfront(items);
	visualizeCall(items);
}

static void deleteValueBack(CDA *items)
{
	printf("deleting back: ");
	removeCDAback(items);
	visualizeCall(items);
}

static void extractValues(CDA* items)
{
	printf("extracting cda\n\n");
	extractCDA(items);
}

static void setCall(CDA* items, int index, void *value)
{
        void *oldValue = setCDA(items, index, value);
        if(value  != NULL)
	{
	printf("Replaced %d with %d\n", getINTEGER(oldValue), getINTEGER(value));
	}
	else
	{
	printf("Value is NULL\n");
	}	
}

/*static void getCall(CDA* items, int index)
{
        void *value = getCDA(items, index);
        if(value  != NULL)
        {
       // printf("Value is %d\n", getINTEGER(value));
	 displayINTEGER(stdout, value);
        }
}*/

int main(int argc, char **argv) {
	if (argc != 1) {
		fprintf(stderr, "usage: %s\n", argv[0]);
		exit(1);
	}

	int i;
	int SIZE_10 = 10;
	CDA *items = newCDA(displayINTEGER);
	CDA *items2 = newCDA(displayINTEGER);

	showItems(items);
	visualizeCall(items);
	sizeCall(items);

	for(i = 0; i < SIZE_10; i++) insertValueFront(items, newINTEGER(i+1));

	for(i = 0; i < SIZE_10; i++) deleteValueFront(items);

	//insertValueFront(items, newINTEGER(11));

	extractValues(items);
	showItems(items);
	visualizeCall(items);
	sizeCall(items);

	for(i = 0; i < SIZE_10; i++) insertValueBack(items, newINTEGER(i+1));

	for(i = 0; i < SIZE_10; i++) deleteValueBack(items);

	extractValues(items);
	showItems(items);
	visualizeCall(items);
	sizeCall(items);

	insertValueFront(items, newINTEGER(1));
	insertValueFront(items, newINTEGER(2));
	insertValueFront(items, newINTEGER(3));
	insertValueFront(items, newINTEGER(4));
	insertValueBack(items, newINTEGER(5));
	insertValueBack(items, newINTEGER(6));
	insertValueBack(items, newINTEGER(7));
	insertValueBack(items, newINTEGER(8));
	insertValueFront(items, newINTEGER(9));
	insertValueFront(items, newINTEGER(10));
	insertValueFront(items, newINTEGER(11));

	for(int i = 0; i < sizeCDA(items); i++) deleteValueBack(items);
	for(int i = 0; i < SIZE_10; i++) insertValueBack(items, newINTEGER(i+1));
	for(int i = 0; i < SIZE_10; i++) insertValueFront(items2, newINTEGER(i+1));

	unionCDA(items, items2);
	visualizeCall(items);
	sizeCall(items);
	int size0 =  sizeCDA(items);
	for(int i = 0; i < size0; i++) deleteValueFront(items);
	
	visualizeCall(items);
	
	printf("size 5\n");
	for(i = 0; i < 5; i++) insertValueBack(items, newINTEGER(i));

	visualizeCall(items);

	for(i = 0; i < sizeCDA(items); i++) setCall(items, i, newINTEGER(i+50));
	
	visualizeCall(items);

        setCDA(items, -1, newINTEGER(0));
	visualizeCall(items);
	setCDA(items, -1, newINTEGER(200));
	setCDA(items, sizeCDA(items), newINTEGER(1));
	setCDA(items, sizeCDA(items), newINTEGER(56));
	setCDA(items, sizeCDA(items), newINTEGER(72));
	visualizeCall(items);
	setCDA(items, 0, newINTEGER(9999));
	visualizeCall(items);

	extractValues(items);
	
	visualizeCall(items);

	insertValueFront(items, newINTEGER(50));
	visualizeCall(items);	
	deleteValueBack(items);
	visualizeCall(items);
	insertValueFront(items, newINTEGER(50));

	/*printf("CDA tester: 1,4\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-1-4.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    void *p = 0;
    printf("inserting items into array d\n");
    insertCDAback(d,newINTEGER(102));
    insertCDAfront(d,newINTEGER(468));
    insertCDAback(d,newINTEGER(448));
    insertCDAfront(d,newINTEGER(595));
    insertCDAback(d,newINTEGER(466));
    insertCDAfront(d,newINTEGER(949));
    insertCDAfront(d,newINTEGER(465));
    insertCDAfront(d,newINTEGER(106));
    insertCDAfront(d,newINTEGER(109));
    insertCDAback(d,newINTEGER(341));
    insertCDAback(d,newINTEGER(131));
    insertCDAfront(d,newINTEGER(217));
    insertCDAfront(d,newINTEGER(787));
    insertCDAfront(d,newINTEGER(685));
    insertCDAback(d,newINTEGER(98));
    insertCDAfront(d,newINTEGER(928));
    insertCDAfront(d,newINTEGER(900));
    insertCDAback(d,newINTEGER(323));
    insertCDAfront(d,newINTEGER(901));
    insertCDAfront(d,newINTEGER(338));
    insertCDAback(d,newINTEGER(316));
    insertCDAback(d,newINTEGER(555));
    insertCDAback(d,newINTEGER(922));
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("removing all but one item from array d\n");
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("removing the last item from array d\n");
    p = removeCDAback(d);
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("inserting one item into array d\n");
    insertCDAfront(d,newINTEGER(598));
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("removing that item\n");
    p = removeCDAback(d);
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("looking at the last element removed\n");
    printf("last element removed: ");
    displayINTEGER(stdout,p);
    printf("\n");*/
	
	return 0;
}
