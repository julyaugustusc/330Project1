#include "q.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue* RunQ;

void start_thread(void (*function)(void))
{ // begin pseudo code
	//allocate a stack(via malloc) of a certain size(choose 8192)
		//allocate a TCB(via malloc)
		//call init_TCB with appropriate arguments
		//call addQ to add this TCB into the “RunQ” which is a global header pointer
		//end pseudo code

	void* stack = (void*)malloc(8192);
	TCB_t* item = NewItem();
	init_TCB(item, function, stack, 8192);
	AddQueue(RunQ, item);

}

void run()

{   // real code

	ucontext_t parent;     // get a place to store the main context, for faking

	getcontext(&parent);   // magic sauce

	swapcontext(&parent, &(RunQ->header->context));  // start the first thread
}



void yield() // similar to run
{
	//rotate the run Q;
	//swap the context, from previous thread to the thread pointed to by RunQ

	ucontext_t old, nnew;
	getcontext(&old);
	RunQ->header->context = old;

	RotateQ(RunQ);

	nnew = RunQ->header->context;
	swapcontext(&old, &nnew);

}
