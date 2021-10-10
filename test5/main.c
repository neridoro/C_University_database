/***********
* neria doron
* 315351445
* 01
* main.c
***********/

#include "ex5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/***********************************************************************************
* Function name: main
* Input: NONE
* Output:NONE
* Function Operation: create sturcts send to program and free all in the end
***********************************************************************************/
int main() {
	Curse* curseHead = (Curse*)malloc(sizeof(Curse));
	Student* studentHead = (Student*)malloc(sizeof(Student));
	Inputs* inputsHead = (Inputs*)malloc(sizeof(Inputs));
	inputsHead->input = NULL;
	curseHead->id = NULL;
	studentHead->name = NULL;
	char input;
	printMenu();
	scanf(" %c", &input);
	while (input != '0') {
		if (input > '6' ||
			input < '0') {
			printf("Error: unrecognized operation.\n");
			printf("Select the next operation (insert 6 for the entire menu):\n");
		}
		else {
			mainswitch(input,curseHead,studentHead,inputsHead);
		}
		scanf(" %c", &input);
	}
	makeMeFree(curseHead, studentHead, inputsHead);
}