/* 
 * puttest.c --- 
 * 
 * Author: Matthew Morales
 * Created: 09-30-2026
 * Version: 1.0
 * 
 * Description: A test file that tests the functionality of using the put() command from the list.h header file and implementation in the list.c file
 */


// Loading Neccesary Libraries and Header Files
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
# include "list.h"


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

// First Test Case
int main(){

	car_t *testList = NULL;
	car_t *emptyList = NULL;
		int count = 0;
	int testResult = 0;
	int failures = 0;
	
	// Test 1: Checking that a car_t struct was created properly
	printf("Test 1: Testing make_car() for proper creation and initialization of a single element of a linked list");
	
	testList = make_c("MattCar", 50, 2005);

	if (testList != NULL && (!strcmp("MattCar",testList->plate)) == 1 && testList->price == 50 && testList->year == 2005){
		testResult = 1;

		printf("\n\nTest 1 Passed: A list element was created with the following:\nPlate: %s\nPlate Number: %f\nYear: %d", testList->plate, testList->price, testList->year);
	} else {
		printf("\n\nTest 1 Failed: A list element was not successfully created with the expected contents");
		failures++;
	}

	// Reseting before next test...
	testResult = 0;
	printf("\n\nProceeding to next test...\n\n");
	
	// Test 2: Checking if the put commands adds to the front of the list and is of length 2
	printf("\n\nTest 2: Calling put() on an empty list\n\n");
	testResult = lput(testList);
	printf("Expected Result: This should return a linked list of size 1\n\n");

	if (testResult == 0 && testList->next == NULL){
		printf("SUCCESS: Test 2 Passed...first element of the linked list was created properly\n\n");
	} else {
		printf("Error: Test 2 Failed...function failed and linked list was not initialized properly\n\n");
		failures++;
	}
	
	// Test 3: Checking if calling put a couples time successfully creates a linked list of size three

	// First to create the lput()
	car_t *car2 = make_c("EveCar",1000,2009);
	car_t *car3 = make_c("GenCar",2000,2010);

	testResult = lput(car2);

	if(testResult == 0 && (car2->next == testList) ) {
		printf("Test 2 update...element two was successfullly created\n\n");
	} else {
		printf("Test 2 Failed: lput() did not initialize and add element two to the list properly\n\n");
		failures++;
	}
	
	lput(car3);

	for (car_t *curr = car3; curr != NULL; curr = curr->next) {
		count++;
		printf("\n\n Current Element:\nPlate: %s\nPlate Number: %f\nYear: %d\n\n", curr->plate, curr->price, curr->year);
	}
	
	if (count == 3) {
		printf("\n\nTest 3 Success: lput() was successfully used to create of list of %d elements\n\n", count);
	}
	
	// Reseting before next test...
	testResult = 0;
	printf("\n\nProceeding to next test...\n\n");	

	printf("Test 4: Calling put() with a NULL pointer\n\n");

	printf("Expected Result: The returned pointer should still be NULL\n\n");
	lput(emptyList);

	if(emptyList == NULL) {
		printf("SUCCESS: Test 4 passed... pointer remained NULL\n\n");
	} else {
		printf("SUCCESS: Test 4 failed\n\n");
		failures++;
	}
	
	if (failures == 0) {
		printf("\n\nSUCCESS: All tests passed!\n\n");
		return EXIT_SUCCESS;
	} else if (failures > 0) {
		printf("\n\nFAILED: %d tests Failed\n\n", failures);
		return EXIT_FAILURE;
	}
	
}


