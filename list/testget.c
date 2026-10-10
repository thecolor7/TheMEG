/* 
 * testget.c --- tests the get function for list.c
 * 
 * Author: Eve H. Belding
 * Created: 09-30-2026
 * Version: 1.0
 * 
 * Description: Prints success for each test that works as expected - tests get for an empty list and a nonempty list
 *
 * Current Status: Test working but no valgrind yet
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// Nessecary Functions
//make car
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
	//Must free cars in main before exiting
}

int main(void){
	//test cars for the list
	//static car_t *head=NULL;
	static car_t *testcar1=NULL;
	static car_t *testcar2=NULL;
	static car_t *testcar3=NULL;
	
	//test get for empty list (front points to NULL)
	if (lget() == NULL) {
		printf("Test succeeded - empty list\n");
  }
	else {
		printf("Test failed - empty list\n");
		exit(EXIT_FAILURE); //only exit if failure
	}

	//add 3 cars and use lput()
	testcar1 = make_c("1SAMPLE", 100000, 2018);
	testcar2 = make_c("2SAMPLE", 200000, 2020);
	testcar3 = make_c("3SAMPLE", 300000, 2022);
	
	lput(testcar1);
	lput(testcar2);
	lput(testcar3);

	//list should now look like testcar3->testcar2->testcar1 (adds to the front) - double check that list looks right
	if (testcar3->next == NULL) {
		printf("list not created\n");
	}
	printf("\nCurrent List (just plates listed):\n");
	for (car_t *temp = testcar3; temp != NULL; temp = temp->next) {
		printf("%s\n", temp->plate);
	}
	
	//test get again - should return testcar1 and remove testcar1 from the list
	//a second test of get should then return testcar2 if the list updated correctly
	
	if (lget() == testcar3) {
		if (lget() == testcar2) { //second round should point to the formerly second car
			printf("\nTest succeeded - nonempty list\n");
			free(testcar1);
			free(testcar2);
			free(testcar3);
			exit(EXIT_SUCCESS);
	  }
	}
  else {
    printf("\nTest failed - nonempty list\n");
		free(testcar1);
		free(testcar2);
		free(testcar3);
    exit(EXIT_FAILURE);
  }

	return(0);
}
