/***********
* neria doron
* 315351445	
* 01
* ex5.h
***********/
typedef struct Student{
	char *name;
	struct Curse* classes[5];
	char* Grade[5];
	struct Student* next;
}Student;

typedef struct Curse{
	char *id;
	char *name;
	struct Curse* next;
}Curse;

typedef struct Inputs{
	char* input;
	struct Inputs* next;
}Inputs;


