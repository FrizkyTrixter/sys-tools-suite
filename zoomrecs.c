#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "zoomrecs.h"
char tolowerChar(char c){ //A function which returns the lower case letter of the Lab
	if(c >= 'A' && c <= 'Z'){
		return 'a' + c - 'A';
	}
	return c;
}
char* tolowerString(char* s){ //A function which returns a string to lower case
	int i;
	for(i = 0; s[i] != '\0'; i++){
		s[i] = tolowerChar(s[i]);
	}
	return s;


}
void addZoomRecord(char* email, char* name, int duration, int lab, struct ZoomRecord **head){	
	struct ZoomRecord *currentNode; //Creates a node to store the current node
	struct ZoomRecord *prev; //Creates a node to store the prev node
	      
	if(*head == NULL){ //If the head is null
		 *head = (struct ZoomRecord*) malloc(sizeof(struct ZoomRecord)); //Allocates space in memory to store the head
		 for (int i = 0; i <= 9; i++){ //This part fixes a weird bug that the code had
			if((**head).duration[i] == 1990152512){
				(**head).duration[i] = 0;
			}
		}
		strcpy((**head).email, email);  //Makes email of head equal to email
		strcpy((**head).name, name);  //Makes name of head equal to name    
		(**head).duration[tolowerChar(lab) - 'a'] = duration; //Makes duration equal to duration
		(*head)->next = NULL; //makes head->next equal to null
		return;
		}
	        currentNode = *head; //starts the current node at the head
		while(currentNode != NULL && strcmp(tolowerString(currentNode->email), tolowerString(email)) != 0){
			prev = currentNode; //this while loop goes through each node as long as it is not null or the email is not the same as the email
			currentNode = currentNode -> next;
		 }
		    
		if(currentNode != NULL && strcmp(tolowerString(currentNode->email), tolowerString(email)) == 0){ //If the node is not null and the email is equal to the email, this will add the corresponding duration to the given duration slot
			currentNode->duration[tolowerChar(lab) - 'a']+=duration;
		 }
		 else{
			 struct ZoomRecord *nextNode = *head; //initializes nextNode to head
			 currentNode = (struct ZoomRecord*) malloc(sizeof(struct ZoomRecord)); //allocates memory for the current Node
			 strcpy((*currentNode).email, email); //makes the email of the currentNode equal to email
			 strcpy((*currentNode).name ,name); //Makes the name of the currentNode equal to name
			 (*currentNode).duration[tolowerChar(lab) - 'a'] = duration; //Makes the duration equal to the duration
		         (currentNode)->next = NULL; //makes currentNode next = to null
			 prev = NULL;  //prev equal to null
			 while (nextNode != NULL && strcmp(tolowerString(nextNode->email), tolowerString(email)) < 0){  
				 prev = nextNode; //this is to arrange everything in alphabetical order. while the letters are less than zero, cycles through until it gets to the node with greater letters
				 nextNode = nextNode->next;
			}
			if(prev == NULL){ //if prev is NULL, then that means this node belongs as the head
				currentNode->next = *head;
				*head = currentNode;
			}
			else{
				//else, the current node will be placed in its proper position in alphabetical order
				prev->next = currentNode;
				currentNode->next = nextNode;
				currentNode->duration[tolowerChar(lab) - 'a'] = duration;
			 }
								          
		 }
}

void generateAttendance(struct ZoomRecord *head, FILE* f){
	  fprintf(f, "User Email,Name (Original Name),A,B,C,D,E,F,G,H,I,Attendance (Percentage)\n"); //Prints this to the top of the file
	  int i;
	  struct ZoomRecord *temp = head; //Stores the head in temp
	  while(temp != NULL){ //while the temp is not null
		int count = 0; //This count is initialized to keep track of the labs the user attended
		float percentage; //this will store the percentage
		int j = 0;
		for (j = 0; j<9; j++){ //adds to the count every time someone attended a lab for more than 45 minutes
			if (temp->duration[j] >= 45){
				count++;
			}
		}
		percentage = ((float)count/9)*100; //Calculates the percentage
		fprintf(f, "%s,%s,", temp->email, temp->name); //prints name and email to file
		for (i = 0; i<9; i++){ //prints each duration to file
			fprintf(f, "%d,", temp->duration[i]);
																	      }
			fprintf(f, "%f\n", percentage); //prints percentage to file
			temp = temp->next; //goes to next node
	 	 }
}

