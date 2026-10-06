/* 
 * list.c --- 
 * 
 * Author: Genevieve M. Powell, Matthew, Eve
 * Created: 09-29-2026
 * Version: 1.0
 * 
 * Description: Implements list.h and creates various functions to call on a list of cars 
 * 
 */

#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static car_t *front=NULL;

car_t *make_car(char *platep, double price, double year) {
	car_t* cp;

	if(!(cp = (car_t*)malloc(sizeof(car_t)))) {
		printf("[Error: malloc failed allocating car]\n");
		return NULL;
	}

	cp->next = NULL;
	strcpy(cp->plate, platep);
	cp->price = price;
	cp->year = year;
	return cp;
}

/* put(): place a car at the beginning of the list
 * returns 0 if successful; nonzero otherwise
 */
int32_t lput(car_t *cp) {

	// MM NOTE: I realized that because there is no check on cp itself, which I am passing in as a already created car, then the if statement evaluates true if there is an empty list which then tries to access nonexistent memory with the "front -> next=cp" line

	// Proposed Edit

	// Initial check if, what should be a car is properly initialized (cp), and not null
	if (cp == NULL) {
		return 1;
	}

	cp->next=front;

	front=cp;

	return 0;
	// Version 1
	//if (front == NULL || front->next == NULL) {
	//	front->next=cp;
	//	cp->next = NULL;
	//	return 0;
		
	//}  else {
	//	cp->next=front->next;
	//	front->next=cp;
	//	return 0;
	//}
}

/* get(): remove and return the first car in the list;
 * return NULL if the list is empty
 */
car_t *lget() {
	car_t *current;

	if (front == NULL) { //list is empty
		return NULL;
	} else { 
		current = front; //store front as return variable
		front = front->next; //front pointer now points to the second element
		return current;
	}

	// OLD VERSION - was returning the second element rather than the first
	//I think this was from our former confusion about front
	/*if (front == NULL || front->next == NULL) {
		return NULL;
	} else {
		current = front->next;
		front->next = current->next;
		current->next = NULL; //otherwise would point to the list it was in
		return current;
	}*/
}

/*apply a function to every car in the list */
void lapply(void (*fn)(car_t *cp)) {

	// Change made due to not printing a single element list the OR caused the front->next condition to always evaluate true with a single element list since with a list of length 1 still has a front->next alue of NULL
	//Code Changed: if (front == NULL || front->next == NULL) {
	if (front == NULL) {
		return;
		
	} else {
		for (car_t *p=front; p!=NULL; p=p->next)  {
			fn(p);
			// Below return ended the loop before full iteration
			//return;
		}
		return;
	}
}

/* remove(): find, remove, and return any car with                                                                         
 * the designated plate; return NULL if not present
 */
car_t *lremove(char *platep) {

	car_t *current = NULL;
	car_t *p = NULL;
	car_t *match = NULL;

	//if the list is empty -- reoved the or statement for same reason as lget (Eve)
	if (front == NULL) {
		return NULL; 
	}

	//if first plate matches - seperate to ensure that front pointer is maintained
	if (strcmp(platep, front->plate) == 0) { //p was never defined so p->next to front->next
		match = front;
		front = front->next; //changed the naming in order to remove and return the front without losing the list
		return(match);
	}

	current = front->next;
	//while loop to find plate match
	while ((current != NULL) && (strcmp(platep, current->plate) != 0)) { //switched to checking the currents plate
			p = current;
			current = current->next;
	}

	//if the value was not found
	if (current == NULL) {
			return NULL;
	}

	//otherwise we found the plate
	match = current; //store match address before changing list
	p->next = current->next; //list now jumps over current (removed)
	//current->next = NULL; - this would cut off the rest of the list
	return(match);
}	
