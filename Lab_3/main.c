#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// This function takes the contents of the array given, and reverses the order.
void ReverseArray(){
	int theArray[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("The reversed order of the array is: ");
	for(int x = (sizeof(theArray)/4) -1; x >= 0; x--){
		if(x == 0){
			printf("%i", theArray[x]);
		}
		else{
		printf("%i, ", theArray[x]);
		}
	}
	printf("\n");
}

//-----------------------------------------------------------------------------------------
//This function allows the user to enter in any number of students, and give each student an ID number, first name, last name, and GPA.  
void Students(int num){
    //Define Student Struct
    typedef struct {
    int ID; 
    char first[30];
    char last[30];
    float gpa;
    } Student;

    //Grab input from user
    Student** studArray = (Student**)malloc(num * sizeof (Student*));
    for (int i = 0; i < num; ++i)
    {
         Student* student = (Student*)malloc(sizeof(Student));
        char first[30];
        char last[30];

        printf("Enter the ID: ");
        scanf("%d", &(student-> ID));
        printf("Enter First Name: ");
        scanf("%s", &first);
        printf("Enter Last Name: ");
        scanf("%s", &last); 
        printf("Enter GPA: ");
        scanf("%f", &(student-> gpa));

        strcpy(student->first, first);
        strcpy(student->last, last);
        
        studArray[i] = student;
    }

    //Organize students by gpa
    for(int i =0; i < num; i++){
        for(int j=0; j < num; j++){
            if(studArray[i] -> gpa > studArray[j] -> gpa){
                Student* temp = studArray[i];
                studArray[i] = studArray[j];
                studArray[j] = temp;
            }
        }

    }

    //Write to a file
    FILE *myfile = fopen("students.txt", "w");
    fprintf(myfile, "Number of students in class: %d\n", num);
	fprintf(myfile, "\n");
    for (int i = 0; i < num; i++)
    {
        fprintf(myfile, "ID number: %d\n", studArray[i]->ID);
        fprintf(myfile, "First name: %s\n", studArray[i]->first);
        fprintf(myfile, "Last name: %s\n", studArray[i]->last);
        fprintf(myfile, "GPA: %f\n", studArray[i]->gpa);
		fprintf(myfile, "\n");
    }
	fclose(myfile);
}

//-----------------------------------------------------------------------------------------
//This function reads the file that was printed in the previous function
void reads(){
	int c;
	FILE * fpReadFile;
	fpReadFile = fopen("C:/Users/Jonah Casinas/OneDrive/Desktop/Coding/C++/ECEGER2020/students.txt", "r");
	printf("The file reads: \n");
	printf("\n");
	while ((c = getc(fpReadFile)) != EOF){
		putchar(c);
	}
	fclose(fpReadFile);
	printf("\n");
}

//-----------------------------------------------------------------------------------------
//These functions are used for part D and E
int countVowels(char x[100]){
  int vowels = 0;
	for(int i = 0; i < strlen(x); i++){
    if(x[i] == 'a' || x[i] == 'A' || x[i] == 'e' || x[i] == 'E' || x[i] == 'i' || 
        x[i] == 'I' || x[i] =='o' || x[i]=='O' || x[i] == 'u' || x[i] == 'U'){
            vowels++;
    }
  }
  printf("Number of vowels %d\n", vowels);
  printf("\n");
return 0;
}

int countcon(char x[100]){
  int constonant = 0;
	for(int i = 0; i < strlen(x); i++){
	if(x[i] == 'a' || x[i] == 'A' || x[i] == 'e' || x[i] == 'E' || x[i] == 'i' || 
        x[i] == 'I' || x[i] =='o' || x[i]=='O' || x[i] == 'u' || x[i] == 'U' || x[i] == ' '){
		}
	else{
		constonant++;
	}
  }
  printf("Number of consonats %d\n", constonant);
  printf("\n");
return 0;
}

void UpperCase(char x[100]){
	for(int i = 0; i < strlen(x); ++i){
		if(x[i]> 96 && x[i] < 123){
			x[i] = x[i]-32;
		}  
	}	
}

int lowerCase(char x[100]){
	for(int i = 0; i < strlen(x); ++i){
		if(x[i]> 64 && x[i] < 91){
			x[i] = x[i]+32;
		}  
	}
return 0;	
}

int printing(char x[100]){
	printf("The current string is: %s\n", x);
return 0;
}

void reverse_string(char str[], int start, int end){
    char temp;
    while(start<end)
    {
        temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        end--;
    }
}

//------------------------------------------------------------------------------------------
int main(){

//Part A:
  ReverseArray();


//Part B:
  int n;
  printf("Enter amount of students: ");
  scanf("%d", &n);
  Students(n);


//Part C:
  reads();


//Part D and E:
  char x[100];
  char y, j; //this variables hold the new line character inputs
  char a;
	printf("Enter a string: \n");
	scanf("%c", &y);
	scanf("%[^\n]",x);
	printf("\n");
	
	  printf("A) Count the number of vowels in the string\n");
	  printf("B) Count the number of consonants in the string\n");
	  printf("C) Convert the string to uppercase\n");
	  printf("D) Convert the string to lowercase\n");
	  printf("E) Display the current string\n");
	  printf("F) Enter another string\n");
	  printf("M) Display the menu\n");
	  printf("R) Reverse the string\n");
	  printf("X) Exit the program\n");

	while(1){
	  printf("Choose an option(A-X): ");
	  scanf("%c", &y);
	  scanf("%c", &a);

    if(a == 'A'){
      countVowels(x);
    }
    else if(a == 'B'){
      countcon(x);
    }
    else if(a == 'C'){
      UpperCase(x);
	  printf("\n");
    }
    else if(a == 'D'){
      lowerCase(x);
	  printf("\n");
    }
    else if(a == 'E'){
      printing(x);
	  printf("\n");
    }
    else if(a == 'F'){
      printf("Enter a string: ");
	  scanf("%c", &y);
	  scanf("%[^\n]",x);
	  printf("\n");
    }
    else if(a == 'M'){
	  printf("A) Count the number of vowels in the string\n");
	  printf("B) Count the number of consonants in the string\n");
	  printf("C) Convert the string to uppercase\n");
	  printf("D) Convert the string to lowercase\n");
	  printf("E) Display the current string\n");
	  printf("F) Enter another string\n");
	  printf("M) Display the menu\n");
	  printf("R) Reverse the string\n");
	  printf("X) Exit the program\n");
    }
    else if(a == 'X'){
      printf("Exited Program!");
      break;
	}
	else if(a == 'R'){
		int start, end;
		end=0;
		start=0;
		while(x[end])
		{
			for(end=start;x[end]&&x[end]!=' ';end++);
			reverse_string(x, start, end-1);
			start=end+1;
		}
			printf("%s\n",x);
	}
    else{
	   scanf("%c", &y);
	   scanf("%c", &j);
	   printf("Invalid input!\n");
    }
  }
return 0;
}