#include <stdio.h>

// This function lists out the size of different variables in bytes. 
void SizeOfVariables(void){
	// First, I decalred different types of variables and assigned each one a name. 
	char c;
	short s;
	int i;
	unsigned int ui;
	unsigned long int ul;
	float f;
	double d;
	long double ld;
	void *ptr;
	
	// Next we print out the size of each varaible using the built in sizeof() funtion.  
	printf("The byte size of c is %i bytes\n", sizeof(c));
	printf("The byte size of s is %i bytes\n", sizeof(s));
	printf("The byte size of i is %i bytes\n", sizeof(i));
	printf("The byte size of ui is %i bytes\n", sizeof(ui));
	printf("The byte size of ul is %i bytes\n", sizeof(ul));
	printf("The byte size of f is %i bytes\n", sizeof(f));
	printf("The byte size of d is %i bytes\n", sizeof(d));
	printf("The byte size of ld is %i bytes\n", sizeof(ld));
	printf("The byte size of ptr is %i bytes\n", sizeof(ptr));	
}


// This function tells us whether a given year is a leap year or not. 
int IsLeapYear(int aYear){
	// By utilizing if, else-if, and else statements, I specified different codintions that will determine whether the given year is a leap year or not. 
	// If the year is a leap year it will return 1 and if not, it will return 0.
	if(aYear < 1752){
		printf("%i is not a leap year\n", aYear);
		return 0;
	}
	else if(aYear % 400 == 0){
		printf("%i is a leap year\n", aYear);
		return 1;
	}
	else if(aYear % 100 == 0){
		printf("%i is not a leap year\n", aYear);
		return 0;
	}
	else if(aYear % 4 == 0){
		printf("%i is a leap year\n", aYear);
		return 1;
	}
	else{
		printf("%i is not a leap year\n", aYear);
		return 0;
	}
return 0;
}


// This funtion will determine if the given character input is a vowel,consonant, or non alphabetical.
int IsVowel(char aLetter){
	// I first declare all the vowels in the alphabet(and its captial's) as an array of characters or strings.
	char vowel[] = "aeiouAEIOU";
	// Next I utilized an if and else statement to determine if the given input is within the ASCII alphabet, if not an error message will be printed. 
	if((aLetter>='a' && aLetter<='z') || (aLetter>='A' && aLetter<='Z')){
		// If the given character input satisfies the if statement above, then the given character input will be itterated through the "vowel" array that was decalared in the beginning of
		// this funtion using a for loop.
		for(int n = 0; n <= sizeof(vowel); n++){
			// As the given character input is itterated through the "vowel" array, the for loop will check the given character input with each letter in the "vowel" array using if and else if
			// statements on each itteration. If the given character input is the same as one of the letters in the "vowel" array it will reconginze it as a vowel, return a 1, and break out of 
			// the loop. If it reaches the end of the "vowel" array, then it will reconginze the given character input as a consonant and return a 0. 
			if(aLetter == vowel[n]){
				printf("%c is a vowel\n" , aLetter);
				return 1;
				break;
				}
			else if(n == sizeof(vowel)){
				printf("%c is a consonant\n", aLetter);
				return 0;
				}
			}
		}
	else{
		printf("%c is not in the Alphabet!!\n", aLetter);
		return 0;
	}
return 0;
}


// This function prints the given input number in a reverse order.
void ReverseNumber(long aNumber){
	// We start by declaring a varaible that will hold the remainder of the given number when divided by 10. 
	int num = 0;
	// Using if and else statements we can specify if the given number is a negative or positive. 
	if(aNumber > 0){
		// Using a while loop, we can grab the last digit from the given input number and print it out. It then sets the given input number to having only the digits that 
		// was not set to the remainder. This process repeats with every itteration until the given input number is equal to 0. 
		while(aNumber > 0){
			num = aNumber % 10;
			printf("%i", num);
			aNumber /= 10;
		}
	}
	// This else statement catches any negative number that may be inputed as the given number. 
	else{
		// We first print a negative sign so that it will appear in front of the ending result. (Makes it a negative number)
		printf("-");
		// We make the negative given input number a postive number so that it can go through the while loop. If the given input number were to stay negative, then it would
		// not work properly. 
		long aNumber2 = aNumber*(-1);
		// Now that the given input number is a postive, it will work normally in the while loop. 
		while(aNumber2 > 0){
			num = aNumber2 % 10;
			printf("%i", num);
			aNumber2 /= 10;
		}
	}
	printf("\n");
}


//The main funtion calls back the previous functions above. It also prints new lines and dashed lines to seperate each of the funtion's result. 
int main()
{
    SizeOfVariables();
	printf("----------------------------\n");
	IsLeapYear(1991);
	IsLeapYear(1992);
	IsLeapYear(1993);
	IsLeapYear(1994);
	IsLeapYear(1995);
	IsLeapYear(1996);
	IsLeapYear(1997);
	IsLeapYear(1998);
	IsLeapYear(1999);
	IsLeapYear(2000);
	printf("----------------------------\n");
	IsVowel('a');
	printf("----------------------------\n");
	ReverseNumber(12345);
	ReverseNumber(-12345);
	printf("----------------------------\n");
    return 0;
}