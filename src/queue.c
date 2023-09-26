#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
    if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
	if (q == NULL || proc == NULL) return;
	q->proc[q->size] = proc;
	q->size++;
	/*
        if (q->size < MAX_QUEUE_SIZE)
	{
		q->proc[q->size] = proc;
		q->size++;
	}*/
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
	if (empty(q)) return NULL;
	int highest_priority = q->proc[0]->prio;
	int highest_index = 0;

	for (int i = 1; i < q->size; i++) {
		if (q->proc[i]->prio < highest_priority) {
			highest_priority = q->proc[i]->prio;
			highest_index = i;
		}
	}

	struct pcb_t* proc = q->proc[highest_index];

	for (int i = highest_index; i < q->size - 1; i++) {
		q->proc[i] = q->proc[i + 1];
	}

	q->size--;

	return proc;
	/*
        int index = 0;
	int i;
	struct pcb_t *ret = NULL;
	if (q->size > 0)
	{
		int HIGHEST_PRIO = q->proc[0]->priority;
		for (i = 1; i < q->size; i++)
		{
			if (q->proc[i]->priority > HIGHEST_PRIO)
			{
				HIGHEST_PRIO = q->proc[i]->priority;
				index = i;
			}
		}
		ret = q->proc[index];
		for(i = index; i < q->size - 1; i++)
		{
			q->proc[i] = q->proc[i + 1];
		}
		q->proc[q->size - 1] = NULL;
		q->size--;
	}
	return ret;
	*/
}

