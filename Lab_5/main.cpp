#include <iostream>
#include <cstring>
using namespace std;

//-------------------------------Students----------------------------------------------------------------------------------
class Student{
private: 
	int  ID;
    char *firstName;
    char *lastName;
    float GPA;
	//------------------------
	unsigned int size;
	unsigned int size2;
public:
	//----------------------Constructors---------------
	Student(){//default constructor 
	}
	
	Student(int ID, const char* firstName, const char* lastName, float GPA){//Parametrized Constructor
		this->ID = ID;
		//--------------------------
		size = strlen(firstName);
		this->firstName = new char[size+1];
		for(unsigned int i = 0; i < size; i++){
			this->firstName[i] = firstName[i];
		}
		//-------------------------
		size2 = strlen(lastName);
		this->lastName = new char[size2+1];
		for(unsigned int i = 0; i < size2; i++){
			this->lastName[i] = lastName[i];
		} 
		//-------------------------
		this->GPA = GPA;
		//-------------------------
		cout<< "Parametrized Constructor was called!!" << endl;
	}
	
	Student(const Student &p){//copy constructor 
		ID = p.ID;
		//-------------------------------
		size = p.size;
		firstName = new char[size+1];
		for(unsigned int i = 0; i < size; i++){
			firstName[i] = p.firstName[i];
		}
		//-------------------------------
		size2 = p.size2;
		lastName = new char[size2+1];
		for(unsigned int i = 0; i < size2; i++){
			lastName[i] = p.lastName[i];
		}		
		//-------------------------------
		GPA = p.GPA;
		//-------------------------------
		cout << "Copy constructor was called!! " << endl;
	}
	
	~Student(){//destructor
		delete [] firstName;
		delete [] lastName;
		cout << "Destructor was called!!" << endl;
	}

	//----------------------Setting Functions----------(properties initialized with parameters)
	void setID(int a){
		ID = a;
	}
	void setfirstname(const char *firstName){
		this->firstName = (char*) malloc(strlen(firstName)+1);
		strcpy(this->firstName, firstName);
		}
	void setlastname(const char *lastName){
			this->lastName = (char*) malloc(strlen(lastName)+1);
			strcpy(this->lastName, lastName);
		}
	void setGPA(float b){
		GPA = b;
	}
	//----------------------Getting Functions------------
	void getID(){
		cout << ID << endl;
	}
	void getfirstname(){
		cout << firstName << endl;
	}
	void getlastname(){
		cout << lastName << endl;
	}
	void getGPA(){
		cout << GPA << endl;
	}
};

void testStudents(){
	//testing get and set functions 
	Student student1;
	student1.setID(1234);
	student1.setfirstname("Jonah");
	student1.setlastname("Casinas");
	student1.setGPA(4.0);
	cout << "Student 1: " << endl;
	student1.getID();
	student1.getfirstname();
	student1.getlastname();
	student1.getGPA();
	cout<< endl;

	//testing constructors
	Student student2(4321, "Barack", "Obama" , 5.0);
	cout << "Student 2: " << endl;
	student2.getID();
	student2.getfirstname();
	student2.getlastname();
	student2.getGPA();
	cout<< endl;
	Student student2twin = student2;// Copying Student 2's info to Student2's twin
	cout << "Student 2's twin: " << endl;
	student2twin.getID();
	student2twin.getfirstname();
	student2twin.getlastname();
	student2twin.setGPA(3.0);//Checking if it really copied by changing the twin's GPA
	student2twin.getGPA();
	cout << endl;
	
	cout << "Testing copy constructor by printing Student 2 information again: " << endl;
	student2.getID();
	student2.getfirstname();
	student2.getlastname();
	student2.getGPA();
	cout<< endl;
	
	// We know that that the methods are working properly because they are able to intialize all the properites within the student class 
	// by setting each property of the student class equal to the parameters of the call back function. We know that the constructors are working 
	// properly because the parameter constructor is able to form a new student when one is initialized. Additionally the copy constructor is able to 
	// copy a student's information and give it to a new student when a copy takes place. I also double-checked the copy constructor functionality by
	// changing the GPA of student2twin to make sure that it wasnt also changing the GPA of student2. Additionally each constructor contains a print 
	// statement, where it's supposed to print a "successfull call" message, that lets the user know when it has been called, which is what I saw while 
	// initalizing and copying professors. In a similar way, we know that the destructor was called because it was also fitted with a "successfull call" 
	// message which makes me confident that the destructor was able to free memory for the allocated memory of the first and last names. 
}

//-------------------------Employee-----------------------------------------------------------------------------------

class Employee{
private:
	int ID;
	char* firstName; 
	char* lastName;
	float salary;
	//----------------
	unsigned int size;
	unsigned int size2;
public:

	//----------------------Constructors/Destructors---------------
	Employee(){//default constructor
	}
	
	Employee(int ID, const char* firstName, const char* lastName, float salary){//parameterized constructor
		this->ID = ID;
		//--------------------
		size = strlen(firstName);
		this->firstName = new char[size + 1];
		for(unsigned int i = 0; i < size; i++){
			this->firstName[i] = firstName[i];
		}
		//--------------------
		size2 = strlen(lastName);
		this->lastName = new char[size2 + 1];
		for(unsigned int i = 0; i < size2; i++){
			this->lastName[i] = lastName[i];
		}
		//--------------------
		this->salary = salary;
		//--------------------
		cout<< "Parameterized constructor was called!!" << endl;
	}
	
	Employee(const Employee& p){//copy constructor 
		ID = p.ID;
		//-------------------------------
		size = p.size;
		firstName = new char[size+1];
		for(unsigned int i = 0; i < size; i++){
			firstName[i] = p.firstName[i];
		}
		//-------------------------------
		size2 = p.size2;
		lastName = new char[size2+1];
		for(unsigned int i = 0; i < size2; i++){
			lastName[i] = p.lastName[i];
		}		
		//-------------------------------
		salary = p.salary;
		//-------------------------------
		cout << "Copy constructor was called!!"<< endl;
	}
	
	~Employee(){//destructor
		delete[] firstName;
		delete[] lastName;
		cout << "Destructor was called!!" << endl;
	}
	
	//----------------------Setting Functions----------(properties initialized with parameters)
	void setID(int a){
		ID = a;
	}
	void setfirstname(const char* firstName){
		size = strlen(firstName);
		this->firstName = new char[size+1];
		for(unsigned int i = 0; i < size; i++){
			this->firstName[i] = firstName[i];
		}
	}
	void setlastname(const char* lastName){
		size2 = strlen(lastName);
		this->lastName = new char[size2+1];
		for(unsigned int i = 0; i < size2; i++){
			this->lastName[i] = lastName[i];
		}
	}
	void setsalary(float b){
		salary = b;
	}
	//----------------------Getting Functions----------
	void getID(){
		cout << ID << endl;
	}
	void getfirstname(){
		for(unsigned int i = 0; i < size; i++){
			cout << firstName[i];
		}
		cout << endl;
	}
	void getlastname(){
		for(unsigned int i = 0; i < size2; i++){
			cout << lastName[i];
		}
		cout << endl;
	}
	void getsalary(){
		cout << salary << endl;
	}
};

void testEmployee(){
	//Testing set and get functions
	Employee employee1;
	cout << "Employee 1: " << endl;
	employee1.setID(12345678);
	employee1.setfirstname("Dwayne");
	employee1.setlastname("Johnson");
	employee1.setsalary(1000000);
	employee1.getID();
	employee1.getfirstname();
	employee1.getlastname();
	employee1.getsalary();
	cout << endl;

	//Testing constructors
	Employee employee2(8234, "Larry", "Wheels", 1000);
	cout << "Employee 2: " << endl;
	employee2.getID();
	employee2.getfirstname();
	employee2.getlastname();
	employee2.getsalary();
	cout << endl;
	Employee employee2twin = employee2;// Copying employee2's info to employee2's twin
	cout << "Employee 2's twin: " << endl;
	employee2twin.getID();
	employee2twin.getfirstname();
	employee2twin.getlastname();
	employee2twin.setsalary(2000); //Checking if it really copied by changing the salary
	employee2twin.getsalary();
	cout << endl;
	
	cout << "Testing copy constructor by printing Employee 2 information again: " << endl;
	employee2.getID();
	employee2.getfirstname();
	employee2.getlastname();
	employee2.getsalary();
	cout << endl;
	
	// We know that that the methods are working properly because they are able to intialize all the properites within the employee class 
	// by setting each property of the employee class equal to the parameters of the call back function. We know that the constructors are working 
	// properly because the parameter constructor is able to form a new employee when one is initialized. Additionally the copy constructor is able to 
	// copy a employee's information and give it to a new employee when a copy takes place. I also double-checked the copy constructor functionality by
	// changing the salary of the employee2twin to make sure that it wasnt also changing the salary of employee2. Additionally each constructor 
	// contains a print statement, where it's supposed to print a "succesfull call" message, that lets the user know when it has been called, which is 
	// what I saw while initalizing and copying professors. In a similar way, we know that the destructor was called because it was also fitted with a 
	// "succesfull call" message which makes me confident that the destructor was able to free memory for the allocated memory of the first and last names. 
}


//-------------------------------Professor----------------------------------------------------------------------------------
class Professor{
public:
	//----------------------Enum list------------------
	enum Department{
		Engineering = 1, Math, Chemistry, CompSci, Theology, Nursing
	};
	
private:
	int ID;
	char* firstName;
	char* lastName;
	float salary;
	bool tenured; 
	Department department;
	//----------------
	unsigned int size;
	unsigned int size2;
		
public:
	//----------------------Constructors/Destructors---
	Professor(){//default constructor
	}
	
	Professor(int ID, const char* firstName, const char* lastName, float salary, bool tenured, Department department){//paramterized constructor
		this->ID = ID;
		//--------------------
		size = strlen(firstName);
		this->firstName = new char[size + 1];
		for(unsigned int i = 0; i < size; i++){
			this->firstName[i] = firstName[i];
		}
		//--------------------
		size2 = strlen(lastName);
		this->lastName = new char[size2 + 1];
		for(unsigned int i = 0; i < size2; i++){
			this->lastName[i] = lastName[i];
		}
		//--------------------
		this->salary = salary;
		//--------------------
		this->tenured = tenured;
		//--------------------
		this->department = department;
		//--------------------
		cout<< "Parameterized constructor was called!!" << endl;
	}
	Professor(const Professor& p){//copy constructor
		ID = p.ID;
		//-------------------------------
		size = p.size;
		firstName = new char[size+1];
		for(unsigned int i = 0; i < size; i++){
			firstName[i] = p.firstName[i];
		}
		//-------------------------------
		size2 = p.size2;
		lastName = new char[size2+1];
		for(unsigned int i = 0; i < size2; i++){
			lastName[i] = p.lastName[i];
		}		
		//-------------------------------
		salary = p.salary;
		//-------------------------------
		tenured = p.tenured;
		//-------------------------------
		department = p.department;
		cout << "Copy constructor was called!!"<< endl;
	}
	~Professor(){//destructor
		delete[] firstName;
		delete[] lastName;
		cout << "Destructor was called!!" << endl;
	}
	
	//----------------------Setting Functions----------(properties initialized with parameters)
	void setID(int a){
		ID = a;
	}
	void setfirstname(const char* firstName){
		size = strlen(firstName);
		this->firstName = new char[size+1];
		for(unsigned int i = 0; i < size; i++){
			this->firstName[i] = firstName[i];
		}
	}
	void setlastname(const char* lastName){
		size2 = strlen(lastName);
		this->lastName = new char[size2+1];
		for(unsigned int i = 0; i < size2; i++){
			this->lastName[i] = lastName[i];
		}
	}
	void setsalary(float b){
		salary = b;
	}
	void settenured(bool c){
		tenured = c;
	}
	void setdepartment(Department x){
		department = x;
	}
	//----------------------Getting Functions----------
	void getID(){
		cout << ID << endl;
	}
	void getfirstname(){
		for(unsigned int i = 0; i < size; i++){
			cout << firstName[i];
		}
		cout << endl;
	}
	void getlastname(){
		for(unsigned int i = 0; i < size2; i++){
			cout << lastName[i];
		}
		cout << endl;
	}
	void getsalary(){
		cout << salary << endl;
	}
	void gettenured(){
		if(tenured == 1){
			cout << "A tenured professor at Seattle University" << endl;
		}
		else if(tenured == 0){
			cout << "Not a tenured professor" << endl;
		}
	}
	void getdepartment(){
		if(department == 1){
			cout << "Professor works in the Engineering Department" << endl;
		}
		if(department == 2){
			cout << "Professor works in the Math Department" << endl;
		}
		if(department == 3){
			cout << "Professor works in the Chemistry Department" << endl;
		}
		if(department == 4){
			cout << "Professor works in the Computer Science Department" << endl;
		}
		if(department == 5){
			cout << "Professor works in the Theology Department" << endl;
		}
		if(department == 6){
			cout << "Professor works in the Nursing Department" << endl;
		}
	}
};

void testProfessors(){
	//Testing setting and getting functions
	Professor professor1;
	cout << "Professor 1: " << endl;
	professor1.setID(333);
	professor1.setfirstname("Lola");
	professor1.setlastname("Duropan");
	professor1.setsalary(13500);
	professor1.settenured(true);
	professor1.setdepartment(Professor::Nursing);
	professor1.getID();
	professor1.getfirstname();
	professor1.getlastname();
	professor1.getsalary();
	professor1.gettenured();
	professor1.getdepartment();
	cout<< endl;
	//Testing constructors and destructors
	Professor professor2(21358, "Abdu", "Rozik", 1500.0, false, Professor::Chemistry);
	cout << "Professor 2: " << endl;
	professor2.getID();
	professor2.getfirstname();
	professor2.getlastname();
	professor2.getsalary();
	professor2.gettenured();
	professor2.getdepartment();
	cout << endl;
	Professor professor3 = professor2; //Copy info from professor2 to professor3
	cout << "Professor 3: " << endl;
	professor3.getID();
	professor3.getfirstname();
	professor3.getlastname();
	professor3.getsalary();
	professor3.gettenured();
	professor3.setdepartment(Professor::Theology); //Checking if it acutally copied by changing this professors department
	professor3.getdepartment();
	cout << endl;
	
	cout << "Testing copy constructor by printing Professor 2 information again: " << endl;
	professor2.getID();
	professor2.getfirstname();
	professor2.getlastname();
	professor2.getsalary();
	professor2.gettenured();
	professor2.getdepartment();
	cout << endl;
	
	// We know that that the methods are working properly because they are able to intialize all the properites within the professor class 
	// by setting each property of the professor class equal to the parameters of the call back function. We know that the constructors are working 
	// properly because the parameter constructor is able to form a new professor when one is initialized. Additionally the copy constructor is able to 
	// copy a professor's information and give it to a new professor when a copy takes place. I also double-checked the copy constructor functionality by
	// changing the department of the professor3 to make sure that it wasnt also changing the department of professor2. Additionally each constructor 
	// contains a print statement, where it's supposed to print a "succesfull call" message, that lets the user know when it has been called, which is what
	// I saw while initalizing and copying professors. In a similar way, we know that the destructor was called because it was also fitted with a 
	// "succesfull call" message which makes me confident that the destructor was able to free memory for the allocated memory of the first and last names. 
}


//------------------------Main Function---------------------------------------------------
int main()
{
 cout << "-----------------------------Student Section------------------------------------" << endl;
 testStudents();
 cout << "-----------------------------Employee Section------------------------------------" << endl;
 testEmployee();
 cout << "-----------------------------Professor Section------------------------------------" << endl;
 testProfessors(); 
return 0;
}