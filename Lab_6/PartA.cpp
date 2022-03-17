#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//--------------------------------------------------------------------------Part A--------------------------------------------------------------------------------------------

// In this new program we are using char pointers to represent the first and last names of a student. Because of this new implemntation we are no longer working with a fixed string size.
// Because we are using character pointers, we need to be sure to that we are allocting memory for it (+1 because of the null-terminating character). Additonally we also need to make sure 
// that we are freeing the memory that was allocated once we are done with it, otherwise we would have memory leaks. 

class Student
{
private:
	int  ID;
    char* firstName;
    char* lastName;
    float GPA;
	Student* next;

public:
	Student(){//Default Constructor 
		this->ID = 0;
		this->firstName = NULL;
		this->lastName = NULL;
		this->GPA = 0.0;
		this->next = NULL;
		cout << "Default Constructor called" << endl;
	}
	
	Student(int ID, char *firstName, char *lastName, float GPA){//Paramerterized Constructor 
		this->ID = ID;
		this->firstName = (char*) malloc(strlen(firstName)+1);
		strcpy(this->firstName, firstName);
		this->lastName = (char*) malloc(strlen(lastName)+1);
		strcpy(this->lastName, lastName);
		this->GPA = GPA;
		this->next = NULL;
		cout << "Parametrized Constructor called" << endl;
	}
	
	Student(Student &p){//Copy Constructor
		ID = p.ID;
		GPA = p.GPA;
		firstName = NULL;
		lastName = NULL;
		if(p.firstName)
		{
			setFirstName(p.firstName);
		}
		if(p.lastName)
		{
			setLastName(p.lastName);
		}
		next = p.next;
		cout << "Copy Constructor called" << endl;
	}
	
	~Student(){//Deconstructor
		delete [] firstName;
		delete [] lastName;
		cout << "Destructor called!" << endl;
	}
	Student& operator=(Student const &s){
		this->ID = s.ID;
		this->firstName = NULL;
		this->lastName = NULL;
		setFirstName(s.firstName);
		setLastName(s.lastName);
		this->GPA = s.GPA;
		//printf("Student Assignment Operator called.\n");
		return *this;
	}
	
	//-------------------------------------Set/Get Methods-----------------------------------------
	void setID(int ID){
		this->ID = ID;
	}
	void setFirstName(const char *firstName){
		if(this->firstName == NULL)
		{
			this->firstName = (char*) malloc(strlen(firstName)+1);
			strcpy(this->firstName, firstName);
			return;
		}
		else
		{
			free(this->firstName);
			this->firstName = (char*) malloc(strlen(firstName)+1);
			strcpy(this->firstName, firstName);
			return;
		}
	}
	void setLastName(const char *lastName){
		if(this->lastName == NULL)
		{
			this->lastName = (char*) malloc(strlen(lastName)+1);
			strcpy(this->lastName, lastName);
			return;
		}
		else
		{
			free(this->lastName);
			this->lastName = (char*) malloc(strlen(lastName)+1);
			strcpy(this->lastName, lastName);
			return;
		}
	}
	void setGPA(float GPA){
		this->GPA = GPA;
	}
	void setNext(Student* next_in)
	{
		next = next_in;
	}
	
	int getID(){
		//cout << ID << endl;
		return ID;
	}
	char* getFirstName(){
		//cout << firstName << endl;
		return firstName;
	}
	char* getLastName(){
		//cout << lastName << endl;
		return lastName;
	}
	float getGPA(){
		//cout << GPA << endl;
		return GPA;
	}
	Student* getNext(){
		return next;
	}
};

//---------------------------------------------------------------Linked Lists-------------------------------------------------------------
//Head node of the Linked List
Student* student1 = NULL; //firstStudent = headNode from lab 4

void addNode(Student* newNode){
    Student* node = student1;
    if( student1 == NULL )
    {
        student1 = newNode;
        return;
    }
	else if(student1->getNext() == NULL)
	{
		if(student1->getGPA() >= newNode->getGPA())
		{
			student1->setNext(newNode);
			return;
		}
		else
		{
			Student* temp = student1;
			student1 = newNode;
			student1->setNext(temp);
			return;
		}
	}
	
	while(node->getNext() != NULL)
	{
		Student* nextNode = node->getNext();
		
		if((node->getGPA() > newNode->getGPA()) && (newNode->getGPA() >= nextNode->getGPA()))
		{
			newNode->setNext(node->getNext());
			node->setNext(newNode);
			return;
		}
		else if(node->getGPA() <= newNode->getGPA())
		{
			newNode->setNext(node);
			student1 = newNode;
			return;
		}
		node = node->getNext();
	}
	node->setNext(newNode);
	newNode->setNext(NULL);
	return;
}
	
void printNodes(){
	Student* node = student1;
    int position = 1;
	if(node == NULL){
		cout << "List is empty" << endl;
	}
	else{
		while(node != NULL){ 
			cout << endl;
			cout << "Student " << position++ << ":" << endl;
			cout << "ID: " << node->getID() << endl;
			cout << "First Name: " << node->getFirstName() << endl;
			cout << "Last Name: " << node->getLastName() << endl;
			cout << "GPA: " << node->getGPA() << endl;
			node = node->getNext();
		}
	}
}

void NewStudent(){
	string word;
	string word2;
	int newID;
	char* newfirstname;
	char* newlastname;
	float newGPA;
	//USE SET AND GET FUNCTIONS
	cout << "Enter the ID:";
	cin >> newID;
	
	cout << "Enter the First Name:";
	cin >> word;
	newfirstname = (char*) malloc(strlen((word.c_str())+1));
	strcpy(newfirstname, word.c_str());

	cout << "Enter the Last Name:";
	cin >> word2;
	newlastname = (char*) malloc(strlen((word2.c_str())+1));
	strcpy(newlastname, word2.c_str());
	
	cout << "Enter the GPA:";
	cin >> newGPA;
	
	Student* newStud = new Student(newID, newfirstname, newlastname, newGPA);
	addNode(newStud);
	free(newfirstname);
	free(newlastname);
}

void deleteStudent(Student** head_ref, int ID){
	// Store head node
    Student *temp = *head_ref, *prev;
 
    // If head node itself holds the student to be deleted
    if (temp != NULL && temp->getID() == ID) {
        *head_ref = temp->getNext(); // Changed head
        free(temp); // free old head
        return;
    }
 
    // Search for the student to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->getID() != ID) {
        prev = temp;
        temp = temp->getNext();
    }
	
    // If student was not present in linked list
    if (temp == NULL)
        return;
		
    // Unlink the node from linked list
    prev->setNext(temp->getNext());
    free(temp); // Free memory
}

void updateStudent(Student* head, int id){
	Student* current = head;
	Student* previous = current;
	char choice;
	int temp1;
	string tempf;
	string templ;
	char* firstname;
	char* lastname;
	float temp2;
	cout << "What would you like to change?" << endl;
	cout << "a) ID" << endl;
	cout << "b) First Name" << endl;
	cout << "c) Last Name" << endl;
	cout << "d) GPA" << endl;
	cout << "Choose from options a-d: ";
	cin >> choice;
	
	while(current != NULL){
		if(current->getID() == id){
			if(choice == 'a'){
				cout << "Enter new ID: ";
				cin >> temp1;
				current->setID(temp1);
			}
			else if(choice == 'b'){
				cout << "Enter new First Name: ";
				cin >> tempf;
				firstname = (char*) malloc(strlen((tempf.c_str())+1));
				strcpy(firstname, tempf.c_str());
				current->setFirstName(firstname);
				free(firstname);
			}
			else if(choice == 'c'){
				cout << "Enter new Last Name: ";
				cin >> templ;
				lastname = (char*) malloc(strlen((templ.c_str())+1));
				strcpy(lastname, templ.c_str());
				current->setLastName(lastname);	
				free(lastname);
			}
			else if(choice == 'd'){
				cout << "Enter new GPA: ";
				cin >> temp2;
				current->setGPA(temp2);		
				if(previous == current){
					current->setNext(NULL);
					addNode(current);
				}
				else{
					previous->setNext(current->getNext());
					addNode(current);
				}
						
			}
			else{
				cout << "Invalid Input!!" << endl;
			}
		}
	previous = current;
	current = current->getNext();
	}
}

void savelist(){
	ofstream opening;
	opening.open("students.txt");
	if(!opening.is_open()){
		cout << "Could not open file" << endl;
	}
	else{
		cout << "Saved to text file" << endl;
		Student* top = student1; 
		int studentCount = 0; 
		while(top != NULL) {
			studentCount++; 
			top = top->getNext(); 
		}
		
		opening << "Number of students: " << studentCount << endl;
		
		top = student1; 
		while(top != NULL) 
		{
			opening << endl;
			opening << "Student ID: "<< top->getID() << endl;
			opening << "Student First Name: "<< top->getFirstName() << endl;
			opening << "Student Last Name: "<< top->getLastName() << endl;
			opening << "Student GPA: "<< top->getGPA() << endl;
			top = top->getNext();
		}
		opening.close(); 
	}
}

void reads(){
	ifstream opening;
	opening.open("students.txt");
	
	if(!opening.is_open()){
		cout << "error" << endl;
	}
	else{
		cout << "Opened Successfully" << endl;
		//---------------------------------
		string word;
		int IDw = 0;
		char* firstname = NULL;
		char *lastname = NULL;
		float GPAw = 0.0;
		opening >> word;
		opening >> word;
		opening >> word;
		opening >> word;
		opening >> word;
		opening >> word;
		while(opening.good()){
			opening >> IDw;
			
			opening >> word;
			opening >> word;
			opening >> word;
			
			opening >> word;
			firstname = (char*) malloc(strlen((word.c_str())+1));
			strcpy(firstname, word.c_str());
			
			opening >> word;
			opening >> word;
			opening >> word;
			
			opening >> word;
			lastname = (char*) malloc(strlen((word.c_str())+1));
			strcpy(lastname, word.c_str());
	
			opening >> word;
			opening >> word;
			opening >> GPAw;

			Student* newstud = new Student(IDw, firstname, lastname, GPAw); //Make a pointer and allocate memory somehow
			addNode(newstud);
			free(firstname);
			free(lastname);
			
			opening >> word;
			opening >> word;
		}
		opening.close();
		cout << "File read successfully" << endl;
	}
	cout << endl;
}

void Menu1(){
	reads();
	//------------Display Menu----------------------------
	cout << "1) List all students" << endl;
	cout << "2) Add Student" << endl;
	cout << "3) Remove Student" << endl;
	cout << "4) Update Student" << endl;
	cout << "5) End Program" << endl;
	
	char input;
	int IDsearch;
	int IDsearch2;
	while(1){
		cout << "Please choose an option (1-5): ";
		cin >> input;
		
		if(input == '1'){
			printNodes();
		}
		else if(input == '2'){
			NewStudent();
			cout << "Student Added!!" << endl;
		}
		else if(input == '3'){
			cout << "Enter the ID of the student you want to delete: ";
			cin >> IDsearch2;
			deleteStudent(&student1, IDsearch2);
			cout << "Student Deleted!!" << endl;
		}
		else if(input == '4'){
			cout << "Enter the ID of the student you want to update: ";
			cin >> IDsearch;
			updateStudent(student1, IDsearch);
		}
		else if(input == '5'){
			savelist();
			cout << "Program exited" << endl;
			break;
		}
		else{
			cout << "Invalid input!" << endl;
		}
	}
}

//--------------------------------------------------------------------------Main Function-------------------------------------------------------------------------------------
int main(){
	//Part A
	Menu1();	
return 0;
}