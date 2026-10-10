/* 
 * applytest.c --- 
 * 
 * Author: Matthew Morales
 * Created: 10-03-2026
 * Version: 1.0
 */

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// Nessecary Functions                                                                                                
car_t *make_c(char *platep, double price, double year) {

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

void printUnit(car_t *cp){
	printf("Current Element:\nPlate: %s\nPlate Number: %.2f\nYear: %d\n\n", cp->plate, cp->price, cp->year);
	return;
}

int main (){
	
	// Test 1: Using the apply() function to an empty list (List is currently empty since put has not been used)
	printf("Test 1: Using apply() with a print function on an empty list\n\n");

	printf("Expected Result: Nothing should be printed to the terminal, no action should be taken and a null pointer\n\n");

	lapply(printUnit);

	printf("Test 1: Completed.\n\n");

	printf("Moving onto the next test...\n\n");

	printf("Test 2: Using the apply() function to a list of only one element\n\n");

	// Test 2: Using the apply() function to a list of one element
	car_t *car1 = make_c("MattCar", 100, 2001);

	lput(car1);
	lapply(printUnit);
	
	printf("Test 2 Complete. Check for the proper output:\n\nExpected Output:\nPlate: %s\nPlate Number: %.2f\nYear: %d\n\n", car1->plate, car1->price, car1->year);
	
	printf("Test 3: Using apply() with a print function on an three element  list\n\n");

	// Test 3: Using the apply() function to a non-empty list
		car_t *car2 = make_c("EveCar", 200, 2002);
	car_t *car3 = make_c("GenCar", 300, 2003);
	car_t *curr = NULL;
	
	lput(car2);
	lput(car3);

	printf("\nThe following is the correct list that should be printed\n");
	for (curr = car3; curr != NULL; curr=curr->next){
		printUnit(curr);
	}

	printf("The control list has been printed.\n");

	lapply(printUnit);

	printf("SUCCESS: Testing executed successfully, please check visually to ensure proper functionality\n\n");
	return(EXIT_SUCCESS);
}

