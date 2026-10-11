/* 
 * testremove.c --- tests the remove function
 * 
 * Author: Eve H. Belding
 * Created: 09-30-2026
 * Version: 1.0
 * 
 * Description: Return NULL if does not exist or if the list is empty, return the car matching
 * the license plate an delete that car from list regardless of placement in the list 
 *
 * Current Status: Test successful but no valgrind
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

//Print the license plates of the current list
void printCurrList(car_t *head) {
	printf("\nCurrent List:\n");
	for (car_t *i = head; i != NULL; i = i->next) {
		printf("%s\n", i->plate);
	}
	printf("\n");
}

int main(void){
  //test cars for the list
  static car_t *testcar1=NULL;
  static car_t *testcar2=NULL;
	static car_t *testcar3=NULL;
	static car_t *testcar4=NULL;
	static car_t *testcar5=NULL;
	
	//try on empty list before adding more - only exits if failure
	if (lremove("1SAMPLE") == NULL) {
		printf("Test succeeded - empty list\n");
	}
	else {
		printf("Test failed - empty list\n");
		exit(EXIT_FAILURE);
	}

	//Build list for testing
	testcar1 = make_c("1SAMPLE", 1000000, 2018);
	testcar2 = make_c("2SAMPLE", 1000000, 2018);
	testcar3 = make_c("3SAMPLE", 1000000, 2018);
	testcar4 = make_c("4SAMPLE", 1000000, 2018);
	testcar5 = make_c("5SAMPLE", 1000000, 2018);

	lput(testcar1);
	lput(testcar2);
	lput(testcar3);
	lput(testcar4);
	lput(testcar5);

	//Sould be 5,4,3,2,1
	printCurrList(testcar5);
	
	//test if license plate is not in the list
	if (lremove("6SAMPLE") == NULL) {
		printf("Test Succeeded - not in list\n");
	}
	else {
		printf("Test Failed - not in list\n");
		free(testcar1);
		free(testcar2);
		free(testcar3);
		free(testcar4);
		free(testcar5);
		exit(EXIT_FAILURE);
	}

	//test for beginning, end, and middle
	if ((lremove("1SAMPLE") == testcar1) && (testcar2->next == NULL)) {
		printf("Test Succeeded - end\n");
  }
  else {
    printf("Test Failed - end\n");
		free(testcar1);
    free(testcar2);
    free(testcar3);
    free(testcar4);
    free(testcar5);
    exit(EXIT_FAILURE);
  }

	//Should be 5,4,3,2
	printCurrList(testcar5);

	if ((lremove("3SAMPLE") == testcar3) && (testcar4->next == testcar2)) {
		printf("Test Succeeded - middle\n");
  }
  else {
    printf("Test Failed - middle\n");
		free(testcar1);
    free(testcar2);
    free(testcar3);
    free(testcar4);
    free(testcar5);
    exit(EXIT_FAILURE);
  }

	//Should be 5,4,2
	printCurrList(testcar5);

	if ((lremove("5SAMPLE") == testcar5) && (lget() == testcar4)) {
    printf("Test Succeeded - end\n");
		free(testcar1);
    free(testcar2);
    free(testcar3);
    free(testcar4);
    free(testcar5);
		exit(EXIT_SUCCESS); //only exit success if this test succeeds and none of the earlier elses exited
  }
  else {
    printf("Test Failed - end\n");
		free(testcar1);
    free(testcar2);
    free(testcar3);
    free(testcar4);
    free(testcar5);
    exit(EXIT_FAILURE);
  }
}

	
