#include <stdio.h>

// This function takes the factorial of a given number.
long Factorial(long num){
	// Declaring variables. Set num1 = num so I can still print the given input value. Set i = num to give a restriction on the while loop
	long num1 = num;
	long i = num;
	// If and else statements to catch it the given input value is over 13. Since the facotrial of 13 is larger than the greatest number allowed for a long type variable. 
	if(num >= 13){
		printf("Error! Value must be less than 13.");
	}
	
	else{
		// A while loop that will multiply the given number input by one less of its value for each iteration. 
		while(i > 1){
			i--;
			num*=i;
		}
		// Print statement that will print the given input number and it's factorial. 
		printf("%ld factorial is %ld\n", num1 ,num);
	}

return 0;
}


// This function determines whether a given value is a Palindrome(The reversed number is equal to it's original).
int IsPalindrome(long value){
	// Declaring variables. The variable "reversed" will hold the reversed value of the given input. "Value2" is equal to "value" so I have something to 
	// compare it to at the end of the while loop. 
	long reversed = 0, remainder, value2 = value;
	// Using a while loop, I can grab the last digit from the given input number and print it out. It then sets that remainder
	// to the reversed value. This process repeats with every iteration until the given input number is equal to 0. 
    while(value2 != 0){
        remainder = value2%10;
        reversed = reversed*10 + remainder;
        value2 /= 10;
    }
	// If and else statements that will reconginze if the reversed number is equal to the original given input. 
    if(value == reversed){
        printf("%ld is a Palindrome\n", value);
		return 1;
    }
    else{
        printf("%ld is not a Palindrome\n", value);
		return 0;
    }
return 0;
}


// This function determines the highest bit set of a given number.
int HighestBitSet(int value){
	// Decalring variables.
   int order = -1, i;
	// For loop that will shift the given input's binray value to the left by "i" each itteration .
    for(i=0; i<32; i++){
		// if statement that checks each bit and makes sure it's a 1.
        if((value>>i) & 1){
            order = i;
        }
    }
	// If and else statements that check to make sure the postion (bit set) is not negative. If it is, then the given number input has no bits. 
    if (order != -1){
        printf("Highest order set bit in %d is %d\n", value, order);
    }
    else{
        printf("%d has no set bits.\n", value);
    }
	//-----------------------------------------------------------------------------
	// Next I printed out the given number input as a binary number 
	int c, k;
	printf("%d in binary is:\n", value);
	
	// This for loop will start with the 32nd bit and works it way down with each itteration 
	for (c = 31; c >= 0; c--){
		k = value >> c;
		// If and else statements will check each bit and see if its a one. If the bit is a 1, then it will print a one. And if not, it will print a 0. 
		if (k & 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
return 0;
}


// This function takes 5 numbers, reverses its order, and puts the reversed order in a seperate text file
void ReverseIt(void){
	// Declaring variables that will hold the user input. 
    float num1;
	float num2;
    float num3;
	float num4;
    float num5;
	// Printing a message to prompt the user to enter five numbers seperated by spaces
    printf("Enter 5 numbers seperated by spaces:\n");
	// Setting the users inputs equal to the variables 
    scanf("%f %f %f %f %f", &num1, &num2, &num3, &num4, &num5);
	// Declaring new variables 
	float prt5;
	float prt4;
	float prt3;
	float prt2;
	float prt1;
	// Setting the users inputs variables equal to new variables
	prt5 = num1;
	prt4 = num2;
	prt3 = num3;
	prt2 = num4;
	prt1 = num5;
	// Printing the new variables in a reverse order
    printf("The reversed order is %f, %f, %f, %f, %f", prt1, prt2, prt3, prt4, prt5);
	
	// Writing the reversed order to a text file 
	FILE *pen;
	pen = fopen("Reversed.txt", "w");
	if(pen){
		fprintf(pen, "The reversed order is %f, %f, %f, %f, %f", prt1, prt2, prt3, prt4, prt5);
		fclose(pen);
	}
	printf("\n");
}



// This function reads the text file that was just created, and prints in out on the screen. 
void ReverseItAgain(){
	// Declare a variable that will be set to a "get character" function.
	int c;
	// Opening the text file with the reversed order of numbers.
	FILE * fpReadFile;
	fpReadFile = fopen("C:/Users/Jonah Casinas/OneDrive/Desktop/Coding/C++/ECEGER2020/Reversed.txt", "r");
	// Using a while loop that will iterate through each character in the file. 
	printf("The file reads: ");
	while ((c = getc(fpReadFile)) != EOF){
		putchar(c);
	}
	fclose(fpReadFile);
	printf("\n");
}


// This function prints out a pyramid whose height is equal to the given number input.  
void Pyramid(int lines){
	// Creating a file that will contain the pyramid. (Note, in each for-loop, it will print out new lines, spaces, and symbols respectively, to the screen 
	// and to the new file. 
	FILE *pyr;
	pyr = fopen("Pyramid.txt", "w");
	// Declaring variables for the rows of the pyramid, the spaces on the rows of the pyramid, and the symbols on the rows of the pyramid.
	int row, space, symbol;
	// For loop that will iterate through each row of the pyramid.
    for(row = 1; row <= lines; row++){
		// For loop that will iterate on each line to produce the correct number of spaces on each line.
        for(space = 1; space <= (lines-row); space++){
            printf(" ");
			fprintf(pyr, " ");
        }
		// For loop that will iterate on each lines to produce the correct number of symbols.
        for(symbol =1; symbol <= ((2*row)-1); symbol++){
            printf("*");
			fprintf(pyr, "*");
        }
	// Prints a new line for each row of the pyramid.
    printf("\n");
	fprintf(pyr, "\n");
	}
}


// The main function calls back other functions. It also utilizes scanf() to grab a user input which is then used as a parameter for the different callback functions.  
int main()
{
	printf("Enter a number: \n");
	int factorial;
	scanf("%d", &factorial);
	Factorial(factorial);
	printf("\n");
	//--------------------------------------------------------------------
	printf("Enter a number: \n");
	long pali;
	scanf("%ld", &pali);
	IsPalindrome(pali);
	printf("\n");
	//--------------------------------------------------------------------
	printf("Enter a number: \n");
	int bit; 
	scanf("%d", &bit);
	HighestBitSet(bit);
	printf("\n");
	//--------------------------------------------------------------------
	ReverseIt();
	printf("\n");
	//--------------------------------------------------------------------
	ReverseItAgain();
	printf("\n");
	//--------------------------------------------------------------------
	printf("Enter number of lines: \n");
	int line;
    scanf("%d", &line);
    Pyramid(line);
	return 0;
}
