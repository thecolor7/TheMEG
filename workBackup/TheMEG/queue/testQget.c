/* 
 * testQget.c --- tests the gput function for an uninitialized, empty, and initialized queue
 * 
 * Author: Genevieve M. Powell
 * Created: 10-08-2026
 * Version: 1.0
 * 
 * Description: tries qget on unopened queue, empty queue, then opened queue
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

int main(void){
	queue_t* testQueue = NULL;
	int testItem = 0;

	//Fails uninitialized queue
	if (qget(testQueue) == NULL) {
		printf("Correctly failed for uninitialized queue\n");
	} else {
		printf("Uninitialized queue check failed\n");
		exit(EXIT_FAILURE);
	}

	//Initialize queue
	testQueue = qopen();

	//Fails empty queue
	if (qget(testQueue) == NULL) {
		printf("Correctly failed for empty queue\n");
	} else {
		printf("Empty queue check failed\n");
		exit(EXIT_FAILURE);
	}

	qput(testQueue, &testItem);
	
	//Fails uninitialized queue
	if (qget(testQueue) == testItem) {
		printf("Correctly got for initialized, nonempty queue\n");
	} else {
		printf("Failed to get for initialized, nonempty queue\n");
		qclose(testQueue);
		exit(EXIT_FAILURE);
	}
	
	//Test for if the list is empty after the only item was got
	if (qget(testQueue) == NULL) {                                                   
    printf("Correctly failed for queue emptied by get function\n");                          
  } else {                                                                         
    printf("Emptied queue check failed\n");                                  
    exit(EXIT_FAILURE);                                                            
  }

	qclose(testQueue);
	exit(EXIT_SUCCESS);
	return(0);
}
