/***********
* neria doron
* 315351445
* 01
* ex5.c
***********/

#define MAX_NAME_SZ 201
#define MAX_COURSE_DIGIT 5
#define MAX_COURSE 5
#define MAX_COURSE_NAME 30
#define MAX_STUDENT_NAME 20
#define MAX_GRADE 100
#include "ex5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//declerations
void mainswitch(char input, Curse* curseHead, Student* studentHead, Inputs* inputsHead);
void printMenu();
void printCurse(Curse* cuurrent, int option, int sum, int students, int max, int min);
void printCurseAvrage(Curse* head, Student* headStudent, int option);
void printCurseStudent(Curse* currentCurse, Student* head);
void printCaseFiveOptions();
void copyArray(Student* copy, Student* current);
void sortAllStudents(Student* headStudent);
void initiateStudent(Student* current);
void createHeadCurse(Curse* head, char* name);
int createBodyCurse(Curse* head, char* name, char* nameCopy);
void createHeadStudent(char* name, char* classId, char* classGrade, Curse* Cursehead, Student* studentHead);
void createBodyStudent(char* name, char* classId, char* classGrade, Curse* Cursehead, Student* studentHead);
void modifyStudent(char* fullinput, Curse* Cursehead, Student* studentHead);
void removeThisStudentFromClass(Curse* curse, Student* student);
void removeStudent(char* fullinput, Curse* Cursehead, Student* studentHead);
void switchCaseOne(char input, Curse* head, Inputs* inputsHead);
void switchCaseTwo(char input, Curse* head, Student* studentHead, Inputs* inputsHead, int thisCase);
void switchCaseFour(char input, Curse* head, Student* studentHead);
void switchCaseFive(char input, Curse* head, Student* studentHead);
int validCharOverall(char* name, size_t len);
int validateClassId(char* name, size_t len);
void trimLeading(char* str);
int validateClassName(char* nameCopy, size_t len);
int validateStudentName(char* name, size_t len);
int validateClassGrade(char* grade, size_t len);
int existClassId(char* id, size_t len, Curse* head);
int checkArrays(int indexExist[5], Student* student);
int dontDeleteAll(char* input, Student* student, Curse* headcurse);
int classLocInsideStudent(Curse* currentClass, Student* currentStudent);
int studentAndGradeInput(char* input, Curse* head);
Curse* classPointer(char* id, size_t len, Curse* head);
Student* studentPointer(char* name, size_t len, Student* head);
void saveInputs(char* fullinput, Inputs* head);
void makeMeFree(Curse* headCurse, Student* currentStudent, Inputs* headInputs);


/***********************************************************************************
* Function name: mainswitch
* Input: char input,Curse* curseHead,Student* studentHead,Inputs* inputsHead
* Output:no output
* Function Operation: get input and send to current place
***********************************************************************************/
void mainswitch(char input,Curse* curseHead,Student* studentHead,Inputs* inputsHead) {
	switch (input) {
	case '0':
		break;
	case '1':
		switchCaseOne(input, curseHead, inputsHead);
		printf("Select the next operation (insert 6 for the entire menu):\n");
		break;
	case '2':
		switchCaseTwo(input, curseHead, studentHead, inputsHead, 2);
		printf("Select the next operation (insert 6 for the entire menu):\n");
		break;
	case '3':
		switchCaseTwo(input, curseHead, studentHead, inputsHead, 3);
		printf("Select the next operation (insert 6 for the entire menu):\n");
		break;
	case '4':
		switchCaseFour(input, curseHead, studentHead);
		printf("Select the next operation (insert 6 for the entire menu):\n");
		break;
	case '5':
		switchCaseFive(input, curseHead, studentHead);
		printf("Select the next operation (insert 6 for the entire menu):\n");
		break;
	case '6':
		printMenu();
		break;
	}
}
/***********************************************************************************
* Function name: printMenu
* Input: NONE
* Output:no output
* Function Operation: print full menu
***********************************************************************************/
void printMenu() {
	printf("Please select an operation:\n"
		"\t0. Exit.\n"
		"\t1. Insert or update a class.\n"
		"\t2. Insert or update a student.\n"
		"\t3. Remove a student from classes.\n"
		"\t4. Print a class.\n"
		"\t5. Print all classes with their computed scores.\n"
		"\t6. Print the menu.\n");
}
/***********************************************************************************
* Function name: printCaseFiveOptions
* Input: NONE
* Output:no output
* Function Operation:print case 5 menu
***********************************************************************************/
void printCaseFiveOptions() {
	printf("Please select the aggregation method:\n"
		"\ta. Average Grade.\n"
		"\tb. Maximal Grade.\n"
		"\tc. Minimal Grade.\n"
		"\td. Sum.\n"
		"\te. Count.\n"
		"\t0. Return to the main menu.\n");
}
/***********************************************************************************
* Function name: printCurse
* Input: Curse* cuurrent, int option, int sum, int students, int max, int min
* Output:no output
* Function Operation: depens on input can print (avrg/sum/count/min/max)
***********************************************************************************/
void printCurse(Curse* cuurrent, int option, int sum, int students, int max, int min) {
	if (option == 1) {
		printf("%s %s, %d\n", cuurrent->id, cuurrent->name, (sum / students));
	}
	if (option == 2) {
		printf("%s %s, %d\n", cuurrent->id, cuurrent->name, max);
	}
	if (option == 3) {
		printf("%s %s, %d\n", cuurrent->id, cuurrent->name, min);
	}
	if (option == 4) {
		printf("%s %s, %d\n", cuurrent->id, cuurrent->name, sum);
	}
	if (option == 5) {
		printf("%s %s, %d\n", cuurrent->id, cuurrent->name, students);
	}

}
/***********************************************************************************
* Function name: printCprintCurseAvrageurse
* Input: Curse* head, Student* headStudent, int option
* Output:no output
* Function Operation:print info about all curses
* depens on input can print (avrg/sum/count/min/max)
***********************************************************************************/
void printCurseAvrage(Curse* head, Student* headStudent, int option) {
	Curse* currentCurse = head;
	Student* currentStudent;
	//loop all curses
	while (currentCurse != NULL) {
		int sum = 0;
		int students = 0;
		int index = 0;
		int max = 0;
		int min = MAX_GRADE;
		int atLeastOne = 0;
		currentStudent = headStudent;
		//loop all students
		while (currentStudent != NULL &&
			currentStudent->name != NULL) {
			//find the location of the class inside the student struct
			index = classLocInsideStudent(currentCurse, currentStudent);
			//calculate max min sum and count
			if (index < MAX_COURSE) {
				students++;
				atLeastOne++;
				sum = sum + atoi(currentStudent->Grade[index]);
				if (max < atoi(currentStudent->Grade[index])) {
					max = atoi(currentStudent->Grade[index]);
				}
				if (min > atoi(currentStudent->Grade[index])) {
					min = atoi(currentStudent->Grade[index]);
				}
			}
			currentStudent = currentStudent->next;
		}
		if (atLeastOne == 0) {
			printf("Class \"%s %s\" has no students.\n", currentCurse->id, currentCurse->name);
		}
		else {
			printCurse(currentCurse, option, sum, students, max, min);
		}
		currentCurse = currentCurse->next;
	}
}
/***********************************************************************************
* Function name: printCurseStudent
* Input: Curse* currentCurse, Student* head
* Output:no output
* Function Operation:printing all students in a given curse
***********************************************************************************/
void printCurseStudent(Curse* currentCurse, Student* head) {
	Student* current = head;
	int atLeastOne = 0;
	int Gradeindex;
	while (current != NULL &&
		head->name != NULL) {
		//find what index the class is in the array
		Gradeindex = classLocInsideStudent(currentCurse, current);
		if (Gradeindex < MAX_COURSE) {
			if (atLeastOne == 0) {
				printf("Class \"%s %s\" students:\n", currentCurse->id, currentCurse->name);
			}
			atLeastOne++;
			printf("%s, %s\n", current->name, current->Grade[Gradeindex]);
		}
		current = current->next;
	}
	if (atLeastOne == 0) {
		printf("Class \"%s %s\" has no students.\n", currentCurse->id, currentCurse->name);
	}
}
/***********************************************************************************
* Function name: copyArray
* Input:Student* copy, Student* current
* Output:no output
* Function Operation:Copy structer array from other struct array
***********************************************************************************/
void copyArray(Student* copy, Student* current) {
	copy->name = current->name;
	for (int count = 0; count < MAX_COURSE; count++) {
		copy->Grade[count] = current->Grade[count];
		copy->classes[count] = current->classes[count];
	}
}
/***********************************************************************************
* Function name: sortAllStudents
* Input:Student* headStudent
* Output:no output
* Function Operation:sorting all students in list in alphabetic way
***********************************************************************************/
void sortAllStudents(Student* headStudent) {
	if (headStudent->next != NULL &&
		headStudent->name != NULL) {
		int sorted = 0;
		Student* currentStudent;
		Student* nextStudent;
		Student* tempStudent = (Student*)malloc(sizeof(Student));
		//loop while list is not sorted
		while (sorted == 0) {
			currentStudent = headStudent;
			nextStudent = headStudent->next;
			while (nextStudent != NULL) {
				//if a value is bigger then the one after him swap them and break;
				if (strcmp(currentStudent->name, nextStudent->name) > 0) {
					copyArray(tempStudent, currentStudent);
					copyArray(currentStudent, nextStudent);
					copyArray(nextStudent, tempStudent);
					break;
				}
				//contiue loop for all
				currentStudent = currentStudent->next;
				nextStudent = nextStudent->next;
			}
			//if you got this far the list is alredy sorted.
			if (nextStudent == NULL) {
				sorted = 1;
			}
		}
		free(tempStudent);
	}
}
/***********************************************************************************
* Function name: initiateStudent
* Input:Student* current
* Output:no output
* Function Operation:when student is created fill his arrays with NULL
***********************************************************************************/
void initiateStudent(Student* current) {
	for (int counter = 1; counter < MAX_COURSE; counter++) {
		current->classes[counter] = NULL;
		current->Grade[counter] = NULL;
	}
}
/***********************************************************************************
* Function name: createHeadCurse
* Input:Curse* head, char* name
* Output:no output
* Function Operation:create the head curse
***********************************************************************************/
void createHeadCurse(Curse* head, char* name) {
	char* token = strtok(name, " ");
	head->id = token;
	token = strtok(NULL, "\n");
	trimLeading(token);
	head->name = token;
	head->next = NULL;
	printf("Class \"%s %s\" added.\n", head->id, head->name);
}
/***********************************************************************************
* Function name: createBodyCurse
* Input:Curse* head, char* name, char* nameCopy
* Output:no output
* Function Operation:create the body of the curse curse
***********************************************************************************/
int createBodyCurse(Curse* head, char* name, char* nameCopy) {
	Curse* current = head;
	int counter = 1;
	while (current != NULL) {
		//update a class if input is same
		if (strcmp(current->id, nameCopy) == 0) {
			char* token = strtok(name, " ");
			token = strtok(NULL, "\n");
			trimLeading(token);
			current->name = token;
			printf("Class \"%s %s\" updated.\n", current->id, current->name);
			return 1;
		}
		//create a body curse and connect to tail
		else if ((current->next == NULL) &&
			(counter < MAX_COURSE)) {
			Curse* body = (Curse*)malloc(sizeof(Curse));
			char* token = strtok(name, " ");
			body->id = token;
			token = strtok(NULL, "\n");
			trimLeading(token);
			body->name = token;
			body->next = NULL;
			current->next = body;
			printf("Class \"%s %s\" added.\n", body->id, body->name);
			return 1;
		}
		current = current->next;
		counter++;
		if (counter > MAX_COURSE) {
			printf("Unfortunately, there is no room for more classes.\n");
		}
	}
}
/***********************************************************************************
* Function name: createHeadStudent
* Input:char* name, char* classId, char* classGrade, Curse* Cursehead, Student* studentHead
* Output:no output
* Function Operation:creating the head student
***********************************************************************************/
void createHeadStudent(char* name, char* classId, char* classGrade, Curse* Cursehead, Student* studentHead) {
	Curse* current = Cursehead;
	while (current != NULL) {
		if (strcmp(current->id, classId) == 0) {
			break;
		}
		current = current->next;
	}
	studentHead->name = name;
	studentHead->classes[0] = current;
	studentHead->Grade[0] = classGrade;
	initiateStudent(studentHead);
	studentHead->next = NULL;
	printf("Student \"%s\" added to class \"%s %s\" with grade %s.\n", name, current->id, current->name, classGrade);
}
/***********************************************************************************
* Function name: createBodyStudent
* Input:char* name, char* classId, char* classGrade, Curse* Cursehead, Student* studentHead
* Output:no output
* Function Operation:creating the body student
***********************************************************************************/
void createBodyStudent(char* name, char* classId, char* classGrade, Curse* Cursehead, Student* studentHead) {
	int updated = 0;
	Curse* thisCurse = classPointer(classId, strlen(classId), Cursehead);
	Student* currentStudent = studentHead;
	while (currentStudent != NULL) {
		if (strcmp(currentStudent->name, name) == 0) {
			int counter = 0;
			while (currentStudent->classes[counter] != NULL) {
				Curse* currentcurse = currentStudent->classes[counter];
				if (strcmp(currentcurse->id, classId) == 0) {
					currentStudent->Grade[counter] = classGrade;
					printf("Student \"%s\" updated on \"%s %s\" with grade %s.\n", name, currentcurse->id, currentcurse->name, currentStudent->Grade[counter]);
					updated = 1;
					break;
				}
				counter++;
			}
			if (updated == 0) {
				currentStudent->classes[counter] = thisCurse;
				currentStudent->Grade[counter] = classGrade;
				printf("Student \"%s\" added to class \"%s %s\" with grade %s.\n", name, thisCurse->id, thisCurse->name, classGrade);
				break;
			}
		}
		if (updated == 0 &&
			currentStudent->next == NULL) {
			Student* body = (Student*)malloc(sizeof(Student));
			currentStudent->next = body;
			body->name = name;
			body->classes[0] = thisCurse;
			body->Grade[0] = classGrade;
			initiateStudent(body);
			body->next = NULL;
			printf("Student \"%s\" added to class \"%s %s\" with grade %s.\n", name, thisCurse->id, thisCurse->name, classGrade);
			break;
		}
		currentStudent = currentStudent->next;
	}
}
/***********************************************************************************
* Function name: modifyStudent
* Input:char* name,char* fullinput, Curse* Cursehead, Student* studentHead
* Output:no output
* Function Operation:check if input is valid if it is add student to body or create the head.
***********************************************************************************/
void modifyStudent(char* fullinput, Curse* Cursehead, Student* studentHead) {
	int print = 0;
	char* myName = strtok(fullinput, ":");
	char* classId = strtok(NULL, ",");
	if (!classId) {
		printf("Error: invalid name, class number or grade.\n");
	}
	char* classGrade = strtok(NULL, ";");
	trimLeading(classId);
	trimLeading(classGrade);
	while (classId != NULL &&
		classId[0] != '\n') {
		if (existClassId(classId, strlen(classId), Cursehead) == 1 &&
			validateClassGrade(classGrade, strlen(classGrade)) == 1) {
			if (studentHead->name == NULL) {
				createHeadStudent(myName, classId, classGrade, Cursehead, studentHead);
			}
			else {
				createBodyStudent(myName, classId, classGrade, Cursehead, studentHead);
			}
		}
		else {
			printf("Error: invalid name, class number or grade.\n");
		}
		classId = strtok(NULL, ",");
		classGrade = strtok(NULL, ";");
		trimLeading(classId);
		trimLeading(classGrade);
	}
}
/***********************************************************************************
* Function name: modifyremoveThisStudentFromClassStudent
* Input:char* name,Curse* curse, Student* student
* Output:no output
* Function Operation:remove a given student from a given curse
***********************************************************************************/
void removeThisStudentFromClass(Curse* curse, Student* student) {
	Curse* current;
	for (int counter = 0; counter < MAX_COURSE; counter++) {
		current = student->classes[counter];
		if (current &&
			strcmp(curse->id, current->id) == 0) {
			student->classes[counter] = NULL;
			student->classes[counter] = NULL;
			printf("Student \"%s\" removed from class \"%s %s\".\n", student->name, curse->id, curse->name);
		}
	}
}
/***********************************************************************************
* Function name: modifyremoveThisStudentFromClassStudent
* Input:char* fullinput, Curse* Cursehead, Student* studentHead
* Output:no output
* Function Operation:validate input and loop on student and remove the wanted curses
***********************************************************************************/
void removeStudent(char* fullinput, Curse* Cursehead, Student* studentHead) {
	char* nameCopy = malloc(MAX_NAME_SZ);
	strcpy(nameCopy, fullinput);
	char* myName = strtok(nameCopy, ":");
	Student* currentStudent = studentPointer(myName, strlen(myName), studentHead);
	char* classId = strtok(NULL, ",");
	if (!classId ||
		!currentStudent) {
		printf("Error: invalid name, class number or grade.\n");
	}
	else {
		char* nameCopy2 = malloc(MAX_NAME_SZ);
		strcpy(nameCopy2, fullinput);
		//make sure u dont delete all curses
		int inputOption = dontDeleteAll(nameCopy2, currentStudent, Cursehead);
		classId = strtok(fullinput, ":");
		classId = strtok(NULL, ",");
		if (inputOption == 0) {
			printf("Error: student cannot be removed from all classes.\n");
		}
		else if (inputOption == 1) {
			while (classId &&
				classId[0] != '\n') {
				trimLeading(classId);
				Curse* currentCurse = classPointer(classId, strlen(classId), Cursehead);
				removeThisStudentFromClass(currentCurse, currentStudent);
				classId = strtok(NULL, ",");
				trimLeading(classId);
			}
		}
		else if (inputOption == 2) {
			printf("Error: invalid name, class number or grade.\n");
		}
		free(nameCopy2);
	}
	free(nameCopy);
}
/***********************************************************************************
* Function name: switchCaseOne
* Input:char input, Curse* head, Inputs* inputsHead
* Output:no output
* Function Operation:validate input and send to create body or head curse
* also saves all the input from the user (to use in the struct)
***********************************************************************************/
void switchCaseOne(char input, Curse* head, Inputs* inputsHead) {
	scanf("%c", &input);
	char* name = malloc(MAX_NAME_SZ);
	fgets(name, MAX_NAME_SZ, stdin);
	trimLeading(name);
	char* nameCopy = malloc(MAX_NAME_SZ);
	strcpy(nameCopy, name);
	if (validateClassId(nameCopy, strlen(nameCopy)) == 1 &&
		validateClassName(nameCopy, strlen(nameCopy)) == 1) {
		if (head->id == NULL) {
			createHeadCurse(head, name);
		}
		else {
			createBodyCurse(head, name, nameCopy);
		}
		saveInputs(name, inputsHead);
	}
	else {
		printf("Error: invalid class number or name.\n");
		free(name);
	}
	free(nameCopy);
}
/***********************************************************************************
* Function name: switchCaseTwo
* Input:char input, Curse* head, Student* studentHead, Inputs* inputsHead, int option
* Output:no output
* Function Operation:validate input and send to create student or delete student
* depens on option 2 or 3 the function will send to delete or create
* also saves all the input from the user (to use in the struct)
***********************************************************************************/
void switchCaseTwo(char input, Curse* head, Student* studentHead, Inputs* inputsHead, int option) {
	scanf("%c", &input);
	char* fullinput = malloc(MAX_NAME_SZ);
	fgets(fullinput, MAX_NAME_SZ, stdin);
	trimLeading(fullinput);
	//two name copys are needed because its a function for 2 almost the same functions(logicaly)
	char* nameCopy = malloc(MAX_NAME_SZ);
	strcpy(nameCopy, fullinput);
	char* nameCopy2 = malloc(MAX_NAME_SZ);
	strcpy(nameCopy2, fullinput);
	char* name = strtok(nameCopy, ":");
	if (option == 2 &&
		validateStudentName(name, strlen(name)) == 1 &&
		studentAndGradeInput(nameCopy2,head)==1){
		modifyStudent(fullinput, head, studentHead);
		saveInputs(fullinput, inputsHead);
	}
	else if (option == 3 &&
		validateStudentName(name, strlen(name)) == 1) {
		removeStudent(fullinput, head, studentHead);
		free(fullinput);
	}
	else {
		printf("Error: invalid name, class number or grade.\n");
		free(fullinput);
	}
	free(nameCopy);
	free(nameCopy2);
}
/***********************************************************************************
* Function name: switchCaseFour
* Input:char input, Curse* head, Student* studentHead
* Output:no output
* Function Operation:validate input and send to sort student alphabeticly
* then print the students from a given curse
* also saves all the input from the user (to use in the struct)
***********************************************************************************/
void switchCaseFour(char input, Curse* head, Student* studentHead) {
	scanf("%c", &input);
	char* fullinput = malloc(MAX_NAME_SZ);
	fgets(fullinput, MAX_NAME_SZ, stdin);
	trimLeading(fullinput);
	char* id = strtok(fullinput, "\n");
	Curse* currentClass = classPointer(id, strlen(id), head);
	if (currentClass == NULL) {
		printf("Error: invalid class number.\n");
	}
	else {
		sortAllStudents(studentHead);
		printCurseStudent(currentClass, studentHead);
	}
	free(fullinput);
}
/***********************************************************************************
* Function name: switchCaseFive
* Input:char input, Curse* head, Student* studentHead
* Output:no output
* Function Operation:do the avrage function to all classes
*  depens on input can print (avrg/sum/count/min/max)
***********************************************************************************/
void switchCaseFive(char input, Curse* head, Student* studentHead) {
	scanf("%c", &input);
	if (head->id != NULL) {
		char* fullinput;
		int stop = 0;
		printCaseFiveOptions();
		fullinput = malloc(MAX_NAME_SZ);
		fgets(fullinput, MAX_NAME_SZ, stdin);
		switch (*fullinput) {
		case '0':
			stop = 1;
			break;
		case 'a':
			printCurseAvrage(head, studentHead, 1);
			break;
		case 'b':
			printCurseAvrage(head, studentHead, 2);
			break;
		case 'c':
			printCurseAvrage(head, studentHead, 3);
			break;
		case 'd':
			printCurseAvrage(head, studentHead, 4);
			break;
		case 'e':
			printCurseAvrage(head, studentHead, 5);
			break;
		}
		free(fullinput);
	}
	else {
		printf("Error: there are no classes.\n");
	}
}
/***********************************************************************************
* Function name: validCharOverall
* Input:char* name, size_t len
* Output:no output
* Function Operation:check input is only char or digit or space and not !@#$
***********************************************************************************/
int validCharOverall(char* name, size_t len) {
	for (int counter = 0; counter < len; counter++) {
		if (!isdigit(name[counter]) &&
			!isspace(name[counter]) &&
			!isalpha(name[counter])) {
			return 0;
		}
	}
	return 1;
}
/***********************************************************************************
* Function name: validateClassId
* Input:char* name, size_t len
* Output:0 or 1 true or false
* Function Operation:check input is only exactly 5 digit 
***********************************************************************************/
int validateClassId(char* name, size_t len) {
	if (validCharOverall(name, len) == 0 ||
		len < MAX_COURSE_DIGIT) {
		return 0;
	}
	int digitcounter = 0;
	for (int counter = 0; counter < len; counter++) {
		if (digitcounter == 5) {
			if (name[counter] != ' ') {
				return 0;
			}
			else {
				digitcounter++;
			}
		}
		else if (isdigit(name[counter])) {
			digitcounter++;
		}
		else if (isspace(name[counter]) &&
			digitcounter < MAX_COURSE_DIGIT &&
			digitcounter>0) {
			digitcounter++;
			return 0;
		}
		else if (isalpha(name[counter]) &&
			digitcounter < MAX_COURSE_DIGIT) {
			return 0;
		}
	}
	return 1;
}
/***********************************************************************************
* Function name: trimLeading
* Input:char* str
* Output:0 or 1 true or false
* Function Operation:remove leading spaces from string
***********************************************************************************/
void trimLeading(char* str) {
	if (str) {
		int index, i, j;
		index = 0;
		while (str[index] == ' ') {
			index++;
		}
		if (index != 0) {
			i = 0;
			while (str[i + index] != '\0') {
				str[i] = str[i + index];
				i++;
			}
			str[i] = '\0';
		}
	}
}
/***********************************************************************************
* Function name: validateClassName
* Input:char* nameCopy, size_t len
* Output:no output
* Function Operation:check input is a valid class name
***********************************************************************************/
int validateClassName(char* nameCopy, size_t len) {
	if (len <= MAX_COURSE_DIGIT + 2) {
		return 0;
	}
	char* token = strtok(nameCopy, " ");
	token = strtok(NULL, "\n");
	trimLeading(token);
	if (strlen(token) == 0 ||
		strlen(token) > MAX_COURSE_NAME) {
		return 0;
	}
	return 1;
}
/***********************************************************************************
* Function name: validateStudentName
* Input:char* name, size_t len
* Output:0 or 1 true or false
* Function Operation:check input is a valid student name
***********************************************************************************/
int validateStudentName(char* name, size_t len) {
	if (len == 0 ||
		len > MAX_STUDENT_NAME ||
		validCharOverall(name, len) == 0) {
		return 0;
	}
	for (int counter = 0; counter < len; counter++) {
		if (isalpha(name[counter]) ||
			isspace(name[counter])) {
		}
		else {
			return 0;
		}
	}
	return 1;
}
/***********************************************************************************
* Function name: validateClassGrade
* Input:char* grade, size_t len
* Output:0 or 1 true or false
* Function Operation:check input is a valid grade number
***********************************************************************************/
int validateClassGrade(char* grade, size_t len) {
	for (int counter = 0; counter < len; counter++) {
		if (isdigit(grade[counter])) {}
		else {
			return 0;
		}
	}
	if (atoi(grade) <= 100 &&
		len > 0) {
		return 1;
	}
	return 0;
}
/***********************************************************************************
* Function name: existClassId
* Input:char* id, size_t len, Curse* head
* Output:0 or 1 true or false
* Function Operation:check if id is in a struct
***********************************************************************************/
int existClassId(char* id, size_t len, Curse* head) {
	if (validateClassId(id, len) == 1) {
		Curse* current = head;
		while (current->id != NULL) {
			if (strcmp(current->id, id) == 0) {
				return 1;
			}
			current = current->next;
			if (current == NULL) {
				break;
			}
		}
	}
	return 0;
}
/***********************************************************************************
* Function name: checkArrays
* Input:int indexExist[5], Student* student
* Output:0 or 1 true or false
* Function Operation:check if user want to delete a student from all the classes
* if so the arrays given and student class array will be the same
***********************************************************************************/
int checkArrays(int indexExist[5], Student* student) {
	int deleteNum = 0;
	int numClasses = 0;
	for (int counter = 0; counter < MAX_COURSE; counter++) {
		if (indexExist[counter] == 1) {
			deleteNum++;
		}
		if (student->classes[counter] != NULL) {
			numClasses++;
		}
	}
	if (deleteNum < numClasses) {
		return 1;
	}
	return 0;
}
/***********************************************************************************
* Function name: dontDeleteAll
* Input:char* input, Student* student, Curse* headcurse
* Output:0 or 1 true or false
* Function Operation:validate the input and
*check if user want to delete a student from all the classes
* if so the arrays given and student class array will be the same
***********************************************************************************/
int dontDeleteAll(char* input, Student* student, Curse* headcurse) {
	char* name = strtok(input, ":");
	if (strcmp(name, student->name) != 0) {
		return 0;
	}
	char* id = strtok(NULL, ",");
	trimLeading(id);
	int indexExist[MAX_COURSE];
	Curse* currentClass;
	Curse* ThisCurse;
	while (id &&
		id[0] != '\n') {
		ThisCurse = classPointer(id, strlen(id), headcurse);
		if (ThisCurse == NULL) {
			return 2;
		}
		for (int counter = 0; counter < MAX_COURSE; counter++) {
			currentClass = student->classes[counter];
			if (currentClass &&
				strcmp(currentClass->id, id) == 0) {
				indexExist[counter] = 1;
				break;
			}
			if (counter == 4) {
				return printf("Error: student is not a member of class \"%s %s\".\n", ThisCurse->id, ThisCurse->name);
			}
		}
		id = strtok(NULL, ",");
		trimLeading(id);

	}
	return checkArrays(indexExist, student);
}
/***********************************************************************************
* Function name: classLocInsideStudent
* Input:Curse* currentClass, Student* currentStudent
* Output:find location of class inside a given student (0-4) 
* Function Operation:find location of class inside a given student
***********************************************************************************/
int classLocInsideStudent(Curse* currentClass, Student* currentStudent) {
	for (int count = 0; count < MAX_COURSE; count++) {
		if (currentStudent->classes[count] == currentClass) {
			return count;
		}
	}
	return (MAX_COURSE);
}
/***********************************************************************************
* Function name: studentAndGradeInput
* Input:char* input, Curse* head
* Output:0 or 1 true or false
* Function Operation:check if student curse and grade are valid befor we save them
* and create new students
***********************************************************************************/
int studentAndGradeInput(char* input, Curse* head) 
{
	char name=strtok(input, ":");
	char* classId = strtok(NULL, ",");
	trimLeading(classId);
	char* classGrade = strtok(NULL, ";");
	trimLeading(classGrade);
	while (classId != NULL &&
		classId[0] != '\n') {
		if (existClassId(classId, strlen(classId), head) != 1 ||
			validateClassGrade(classGrade, strlen(classGrade)) != 1) {
			return 0;
		}
		classId = strtok(NULL, ",");
		classGrade = strtok(NULL, ";");
		trimLeading(classId);
		trimLeading(classGrade);
	}
	return 1;
}
/***********************************************************************************
* Function name: classPointer
* Input:char* id, Curse* head
* Output:pointer to a curse or null
* Function Operation:search for a curse when id is given
* if not found return null
***********************************************************************************/
Curse* classPointer(char* id, size_t len, Curse* head) {
	if (validateClassId(id, len) == 1) {
		Curse* current = head;
		while (current->id != NULL) {
			if (strcmp(current->id, id) == 0) {
				return current;
			}
			current = current->next;
			if (current == NULL) {
				break;
			}
		}
	}
	return NULL;
}
/***********************************************************************************
* Function name: studentPointer
* Input:char* name, size_t len, Student* head
* Output:pointer to a student or null
* Function Operation:search for a student when name is given
* if not found return null
***********************************************************************************/
Student* studentPointer(char* name, size_t len, Student* head) {
	Student* current = head;
	while (current->name != NULL) {
		if (strcmp(current->name, name) == 0) {
			return current;
		}
		current = current->next;
		if (current == NULL) {
			break;
		}

	}
	return NULL;
}
/***********************************************************************************
* Function name: saveInputs
* Input:char* fullinput, Inputs* head
* Output:NONE
* Function Operation:save the full input im using in structers in a structer
* so we can free it all up later
***********************************************************************************/
void saveInputs(char* fullinput, Inputs* head) {
	if (head->input == NULL) {
		head->input = fullinput;
		head->next = NULL;
	}
	else {
		Inputs* body = (Inputs*)malloc(sizeof(Inputs));
		Inputs* tail = head;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = body;
		body->input = fullinput;
		body->next = NULL;

	}
}
/***********************************************************************************
* Function name: makeMeFree
* Input:Curse* headCurse, Student* currentStudent, Inputs* headInputs
* Output:NONE
* Function Operation:free all malloc function that are yet been freed
***********************************************************************************/
void makeMeFree(Curse* headCurse, Student* currentStudent, Inputs* headInputs) {
	if (headInputs->input != NULL) {
		while (headInputs)
		{
			Inputs* temp = headInputs;
			headInputs = headInputs->next;
			free(temp->input);
			free(temp);
		}
	}
	else {
		free(headInputs);
	}
	if (currentStudent->name != NULL) {
		while (currentStudent)
		{
			Student* temp = currentStudent;
			currentStudent = currentStudent->next;
			free(temp);
		}
	}
	else {
		free(currentStudent);
	}
	if (headCurse->id != NULL) {
		while (headCurse)
		{
			Curse* temp = headCurse;
			headCurse = headCurse->next;
			free(temp);
		}
	}
	else {
		free(headCurse);
	}
}