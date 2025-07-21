#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "zoomrecs.c"

int main(int argc, char *argv[]){
	struct ZoomRecord *head = NULL; //Initializes Zoom Record struct head
	struct ZoomRecord *next; //Initializes next zoom record struct
	char str[1000]; //initializes all the variables
	char ret[1000];
	char email[1000];
	char name[1000];
	char lab[1000];
	int duration;
	if (argc != 3){ //If program is given incorrect number of arguments, will throw an error
		printf("Error! Incorrect number of arguments\n");
		return 1;
	}
	FILE* f1 = fopen(argv[1], "rt"); //Opens input file
	FILE* f2 = fopen(argv[2], "w"); //Opens the output file
												
	fgets(str, 1000, f1); //Gets the first line from the file
	while(fgets(str, 1000, f1) != NULL){ //While there are lines in the file, will parse the file and get the correct variables using strtok
	     strcpy(ret, strtok(str, ","));
	     strcpy(email, ret);
	     strcpy(ret, strtok(NULL, ","));
	     strcpy(name, ret);
	     strcpy(ret, strtok(NULL, ","));
	     strcpy(lab, ret);
	     strcpy(ret, strtok(NULL, ","));				
	     duration = atoi(ret); //Converts duration to an int
	     addZoomRecord(email, name, duration, lab[0], &head); //calls add zoom record with corresponding variables			
	}
	generateAttendance(head, f2); //generates the attendance with the corresponding variables
	fclose(f1); //closes two files
	fclose(f2);
	while(head != NULL){ //frees memory from the linked list
		next = head -> next;
		free(head);
		head = next;
	}
	return 0;
																			
}

