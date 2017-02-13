/*
 ============================================================================
 Name        : Lab2redo.c
 Author      : Theo Choma
 Version     : 3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main(int argc, char** argv) {

	//Main Menu

	//variable definitions
	char svar = '0', c = '0';
	unsigned short factin = 0;
	unsigned long factout = 1;
	unsigned int year = 0, yearmath = 0;
	float in1, in2, divout;
	int maxresult = 0;
	int div1, div2;
	int err = 0;

	//menu repeater
	while (svar != '5') {

		//get choice
		printf(
				"\nPlease select a menu option:\n1. Factorial\n2. Leap Year\n3. Maximum\n4. Division\n5. Exit\n");
		fflush(stdout);
		err = scanf(" %c", &svar);
		while (err != 1
				|| (svar != '1' && svar != '2' && svar != '3' && svar != '4'
						&& svar != '5')) {
			printf("\nInvalid input. Please try again: ");
			fflush(stdout);
			err = scanf(" %c", &svar);
		}
		err = 0;

		//switch clause
		switch (svar) {
		case '1':
			//factorial case
			while (factin <= 0 || factin > 12) {
				printf("\nPlease input a number to factorial: ");
				fflush(stdout);
				err = scanf("%hu", &factin);
				while (err != 1) {
					printf("\nInvalid input, please try again: ");
					fflush(stdout);
					err = scanf("%hu", &factin);
					do {
						c = getchar();
					} while (!isdigit(c));
					ungetc(c, stdin);
				}
			}
			while (factin != 0) {
				factout = (unsigned long) factin * factout;
				factin = factin - 1;
			}
			printf("\nThe factorial is %lu", factout);
			fflush(stdout);
			break;
		case '2':
			//Leap year case
			printf("\nPlease input a year: ");
			fflush(stdout);
			err = scanf("%u", &year);
			while (err != 1) {
				printf("\nInvalid input, please try again: ");
				fflush(stdout);
				err = scanf(" %u", &year);
				do {
					c = getchar();
				} while (!isdigit(c));
				ungetc(c, stdin);
			}

			yearmath = year % 4;
			if (yearmath == 0) {
				printf("\n%u is a leap year!", year);
				fflush(stdout);
			} else {
				printf("\n%u is not a leap year.", year);
			}
			break;
		case '3':
			//Maximum case
			printf("\nPlease input the first number: ");
			fflush(stdout);
			scanf("%f", &in1);
			printf("\nPlease input the second number: ");
			fflush(stdout);
			scanf("%f", &in2);
			maxresult = (in1 > in2) ? 1 : 2;
			if (maxresult == 1) {
				printf("\nThe first number is greater than the second number");
				fflush(stdout);
			} else {
				printf("\nThe second number is greater than the first number");
				fflush(stdout);
			}
			break;
		case '4':
			//Division case
			printf("\nPlease enter the first number to divide: ");
			fflush(stdout);
			scanf("%d", &div1);
			printf("\nPlease enter the second number to divide by: ");
			fflush(stdout);
			scanf("%d", &div2);

			divout = (float) div1 / (float) div2;
			printf("\nThe result of the division is %f", divout);
			break;
		}

	}

	//Binary
	int bichoice;
	printf("\nEnter 1 for arithmetic and 2 for bitwise: ");
	fflush(stdout);
	scanf("%d", &bichoice);

	int decin;
	printf("Enter the decimal number you want to convert to binary: \n");
	fflush(stdout);
	scanf("%d", &decin);

	//arithmetic
	if (bichoice == 1) {
		int d[20], j, i = 0;
		while (decin > 0) {
			d[i] = decin % 2;
			i++;
			decin = decin / 2;
		}
		for (j = i - 1; j >= 0; j--) {
			printf("%d", d[j]);
		}
	}

	//bitwise
	else if (bichoice == 2) {
		int mask = 0x4000;
		if ((decin & 0x8000) == 0) {
			printf("0");
		} else {
			printf("1");
		}
		while (mask != 0) {
			if ((decin & mask) == 0) {
				printf("0");
			} else {
				printf("1");
			}
			mask = mask >> 1;
		}
	}

	return (EXIT_SUCCESS);
}

