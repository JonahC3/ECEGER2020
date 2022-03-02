#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define FULL 10

//-------------------------------------Student Linked-List-----------------------------------
typedef struct Student{
    int ID; 
    char first[30];
    char last[30];
    float gpa;
	struct Student* next;
    } Student;

Student* headNode = NULL;

Student* createNode(int numbID, char firstname[30], char lastname[30], float gpanumb)
{
    Student* newNode = NULL;
    //  Create new node
    newNode = (Student *) malloc(sizeof(Student));
    if( newNode != NULL ){
        newNode->ID = numbID;
		strcpy(newNode->first, firstname);
        strcpy(newNode->last, lastname);
		newNode->gpa = gpanumb;
        newNode->next = NULL;
    }
	return newNode;
}

void addNode(Student* newNode)
{
    Student* currentNode = headNode;
    //  Check for empty list
    if( headNode == NULL )
    {
        headNode = newNode;
        return;
    }
    //  Loop to end of list
    while( currentNode->next != NULL ){
		Student* next = currentNode->next;
		if((currentNode->gpa > newNode->gpa) && (newNode->gpa >= next->gpa)) 
		{									
			newNode->next = currentNode->next; 
			currentNode->next = newNode; 
			return; 
		}
		else if(currentNode->gpa <= newNode->gpa) 
		{				      
			newNode->next = currentNode; 
			headNode = newNode; 
			return;
		}		
	currentNode = currentNode->next;
		
	}
    //  Add new node to end
    currentNode->next = newNode;
	newNode->next = NULL;
	return;
// The organizing of the student's GPA acutally happens within this function since whenever we add a node, we can place in the appropriate postion of the linked list without having to sort 
// through the entire list. Organizing the student's GPA from highest to lowest is only neccesary in this addNode() function since when read the intial list off the student file, it is already
// organized from highest to lowest and deleting a student from the list will not change the order from highest to lowest for the stduents GPA. 
}

void printNodes(){
    Student* node = headNode;
    int position = 0;
    while( node != NULL )
    {
		printf("List Position: %d\n", position++);
        printf("ID = %d\n", node->ID );
		printf("First name = %s\n", node->first);
		printf("Last name = %s\n", node->last);
		printf("GPA = %f\n", node->gpa);
		printf("\n");
        node = node->next;
    }
}

void NewStudent(){
	//Grabbing new students information and adding it to list
	Student* student = (Student*)malloc(sizeof(Student));
	char first[30];
	char last[30];
	printf("Enter the ID: \n");
	scanf("%d", &(student->ID));
	printf("Enter First Name: \n");
	scanf("%s", &first);
	printf("Enter Last Name: \n");
	scanf("%s", &last); 
	printf("Enter GPA: \n");
	scanf("%f", &(student->gpa));
	Student* list = createNode(student->ID, first, last, student->gpa);
	addNode(list);
	
}

void deleteStudent(struct Student** head_ref, int ID)
{
    // Store head node
    struct Student *temp = *head_ref, *prev;
 
    // If head node itself holds the student to be deleted
    if (temp != NULL && temp->ID == ID) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
 
    // Search for the student to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->ID != ID) {
        prev = temp;
        temp = temp->next;
    }
	
    // If student was not present in linked list
    if (temp == NULL)
        return;
		
    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

void updateStudent(struct Student* head, int id){
	printf("a) ID\n");
	printf("b) First name\n");
	printf("c) Last name\n");
	printf("d) GPA\n");
	printf("Choose one of the following to change (a-d):");
	char option, garb;
	struct Student* current = head;
	struct Student* previous = current;
    while (current != NULL) {
        if (current->ID == id){
			scanf("%c", &garb);
			scanf("%c", &option);
			if(option == 'a'){
				printf("Enter new ID: ");
				scanf("%d", &(current->ID));
				printf("Update Successful\n");
			}
			else if(option == 'b'){
				printf("Enter new first name: ");
				scanf("%s", &(current->first));
				printf("Update Successful\n");
			}
			else if(option == 'c'){
				printf("Enter new last name: ");
				scanf("%s", &(current->last));
				printf("Update Successful\n");
			}
			else if(option == 'd'){
				printf("Enter new GPA: ");
				scanf("%f", &(current->gpa));
				if(previous == current){
					current->next = NULL;
					addNode(current);
				}
				else{
					previous->next = current->next;
					addNode(current);
				}
				printf("Update Successful\n");
				break;	
			}				
		}
	previous = current;
	current = current->next;
	}	
}
	
void savelist(){
	FILE* filePtr;
	filePtr = fopen("C:/Users/Jonah Casinas/OneDrive/Desktop/Coding/C++/ECEGER2020/students.txt", "w+"); 
	Student* top = headNode; 
	int studentCount = 0; 
	while(top != NULL) 
	{
		studentCount++; 
		top = top->next; 
	}
	
	fprintf(filePtr, "Number of students: %d ", studentCount); 
	
	top = headNode; 
	while(top != NULL) 
	{
		fprintf(filePtr, "\n\nStudent ID: %d", top->ID);
		fprintf(filePtr, "\nStudent First Name: %s", top->first);
		fprintf(filePtr, "\nStudent Last Name: %s", top->last);
		fprintf(filePtr, "\nStudent GPA: %f", top->gpa);
		top = top->next; 
	}
	fclose(filePtr); 
}

//Reads files from text and callback function in the menu
void reads(){
	int c;
	int numStudents, numID;
	float temp;
	char firstName[30];
	char lastName[30];
	float gpanum;
	FILE * fpReadFile;
	fpReadFile = fopen("C:/Users/Jonah Casinas/OneDrive/Desktop/Coding/C++/ECEGER2020/students.txt", "r");
	
	//Grabbing number of students
	fscanf(fpReadFile, "\nNumber of students in class: %d", &numStudents);
	
	//Grabbing all Student info and sending to linked list
	while ((c = getc(fpReadFile)) != EOF){
		fscanf(fpReadFile, "\nID number: %d", &numID);
		fscanf(fpReadFile, "\nFirst name: %s", &firstName); 
		fscanf(fpReadFile, "\nLast name: %s", &lastName);
		fscanf(fpReadFile, "\nGPA: %f", &gpanum);
		if(gpanum != temp){
			Student* list = createNode(numID, firstName, lastName, gpanum);
			addNode(list);
		}
		temp = gpanum;
	}
	fclose(fpReadFile);
	//-------------------------------------------------------------------------------
	char newline; //this variables hold the new line character inputs
	char selected;
	int ID, ID1;

	  printf("1) List all students\n");
	  printf("2) Add Student\n");
	  printf("3) Remove Student\n");
	  printf("4) Update Student\n");
	  printf("5) Exit\n");
	  
	while(1){
	  printf("Choose an option(1-5): ");
	  scanf("%c", &newline);
	  scanf("%c", &selected);

		if(selected == '1' || newline == '1'){
		  printf("\n");
		  printNodes();
		  printf("\n");
		}
		else if(selected == '2' || newline == '2'){
		  NewStudent();
		  printf("Student added to list\n");
		}
		else if(selected == '3' || newline == '3'){
			printf("Inserts student's ID: ");
			scanf("%d" , &ID);
			deleteStudent(&headNode, ID);
			printf("Student removed from list\n");
		}
		else if(selected == '4' || newline == '4'){
			printf("Insert the student's ID: ");
			scanf("%d", &ID1);
			updateStudent(headNode, ID1);
		}
		else if(selected == '5' || newline == '5'){
		  savelist();
		  printf("Program Exited\n");
		  printf("\n");
		  break;
		}
		else{
		   	printf("Invalid input!!!\n");
		}
	}
}

//------------------------------------Stack_Array------------------------------------------------------
// Data structure to represent a stack
typedef struct Stack
{
    int data;
    struct Stack* next;
} Stack;
 
Stack* headnode;

// Utility function to initialize the stack
void newStack(){
    headnode = NULL;
}

// Utility function to return the size of the stack
int size(Stack* top){
    int count = 0;  // Initialize count
    struct Stack* current = top;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
 
// Utility function to check if the stack is empty or not
int isEmpty(){
    if(headnode == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
// Utility function to add an element `x` to the stack
void push(int value){
    Stack *tmp;
    tmp = malloc(sizeof(Stack));
    tmp -> data = value;
    tmp -> next = headnode;
    headnode = tmp;
}
 
// Utility function to pop a top element from the stack
int pop(){
    Stack *tmp;
    int n;
    tmp = headnode;
    n = tmp->data;
    headnode = headnode->next;
    free(tmp);
    return n;
}
 
// Utility function to peek at top element from the stack
int peek(){
    return headnode->data;
}

//------------------------------------Queue_Array------------------------------------------------------
struct node{
    int data;
    struct node *next;
};
typedef struct node node;

struct queue{
    int count;
    node *front;
    node *rear;
};
typedef struct queue queue;

void newQueue(queue *q){
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int isempty(queue *q){   
    if(q->rear == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void insert(queue *q, int value){
    if (q->count < FULL)
    {
        node *tmp;
        tmp = malloc(sizeof(node));
        tmp->data = value;
        tmp->next = NULL;
        if(!isempty(q))
        {
            q->rear->next = tmp;
            q->rear = tmp;
        }
        else
        {
            q->front = q->rear = tmp;
        }
        q->count++;
    }
    else
    {
        printf("List is full\n");
    }
}

int removes(queue *q){
    node *tmp;
    int n = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return(n);
}

void peeks(node *head){
    if(head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\n", head -> data);
    }
}

int sizes(queue* q){    
    printf("%d\n", q->count);
    return 0;
}


//-----------------------------------Main Function-------------------------------------------------------------------

int main(){
	//Part A and B
	reads();


	//Part C
	newStack();
 
    push(3);
    push(2);
    push(1);
 
    printf("The stack size is %d\n", size(headnode));
	
	printf("Top val on stack is %d\n", peek());

    pop();
    pop();
    pop();

    if(isEmpty() == 1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is not empty\n");
    }
	printf("\n");
	
	
	//Part D
	queue *q;
    q = malloc(sizeof(queue));
    newQueue(q);

	insert(q,10);
	insert(q,20);
	insert(q,30);

    printf("The queue size is:");
	sizes(q);

    printf("Top value on queue is:");
	peeks(q->front);
	
	removes(q);
	removes(q);
	removes(q);
    
    if(isempty(q)){
        printf("The queue is empty!\n");
    }

    else{
        printf("The queue is not empty");
    }
return 0;
}
