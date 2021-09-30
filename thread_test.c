//Name: Augustus Crosby

#include "threads.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int vari1 = 0;

void test1(void) {
	int lvari1 = 0;
	
	for(;;) {
		printf("Global: %d\nCounter: %d\n", vari1, lvari1);
		vari1++;
		lvari1++;
		sleep(1);
		yield();
	}
	return;
}

void test2(void) { //fibo seque
	int lvari2 = 1;
	int lvari3 = 1;
	int temp = lvari2 + lvari3;

	printf("Fibo: %d\n Fibo: %d\n Fibo: %d\n", lvari2, lvari3, temp);


	for(;;) {
		lvari2 = lvari3;
		lvari3 = temp;
		temp = lvari2 + lvari3;
		
		printf("Global: %d\nFibo: %d\n", vari1, temp);
		vari1++;
		sleep(1);
		yield();
	}
	return;
}
		



int main() {

	RunQ = (struct queue*) malloc(sizeof(struct queue));

	InitQueue(RunQ);

	start_thread(test1);
	start_thread(test2);
	run();

	return 0;
}

	
