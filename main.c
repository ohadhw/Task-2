#include <stdio.h>
#include "myBank.h"
#include "myBank.c"
/*
 *        ------------C O D E----E X P L A I N A T I O N ---------
 * The code below is a "main menu" with a switch case of big letters and many do-while loops:
 *
 * Each inputed big letter calls the functions from myBank.c. the main menu (switch case) is inside a do while
 * loop as well because it is a proper way of fixing a wrong input being inserted other than the letters: 'O' 'B' 'D' 'W' 'I' 'C' 'P' 'E' 
 * which will lead to the call of the loop once again.
 *
 * The inner do-while loops are in charge of the boolean option of the scanner and also a negative numbers which aren't supposed to be inserted
 *
 */
int main(){
	char ch;
	int num;
	float amount;

	int whole;
	float real;
	int bullyA = 1;
	int bullyB = 1;
	do{
	 printf("Transaction type?: \n");
	 ch = getchar();
	 switch(ch) {
      case 'O' :
	 do{
        printf("Initial deposit?: \n");
                if(scanf("%f",&amount)!=1){
                        printf("Error: It's not a number! \n");
                        scanf("%*s");
                }
                else{
                        if(amount<0){
                                printf("Error: Cannot deposit a negative amount!! \n");
			}
			else{
				open(amount);
			}
                }
        }
        while (amount < 0);
         break;

      case 'B' :
	 do{
        printf("Account number? \n");
                if(scanf("%d",&num)!=1){
                        printf("Error: Please enter a number \n");
                        scanf("%*s");
                }
                else{
                        if(num<0){
                                printf("Error: Cannot read a negative value \n");
			}
			else{
				balance(num);
			}
                }
	}
        while(num<0);
	 break;

      case 'D' :
	 do{
	        printf("Account number? \n");
                if(scanf("%d",&num)!=1){
                        printf("Error: Please enter a number and not a char \n");
                        scanf("%*s");
                }
                else{
                        if(num<0){
                                printf("Error: Cannot read a negative value \n");
                        }
			else{
				whole = num;
				bullyA = 0;
			}
                }
        	printf("Amount?: \n");
                	if(scanf("%f",&amount)!=1){
                        	printf("Error: Please enter a number and not a char \n");
                        	scanf("%*s");
                	}
                	else{
                        	if(amount<0){
                                	printf("Error: Cannot deposit a negative amount of cash! \n");
                        	}
				else{
					real = amount;
					bullyB = 0;
				}
                	}	
        }
        while (amount < 0 || num < 0);
	if(bullyA == 0 && bullyB == 0){
		deposit(whole,real);
	}
	else{
		printf("Error: Returning to main menu \n");
	}
	break;

      case 'W' :
	do{
                printf("Account number? \n");
                if(scanf("%d",&num)!=1){
                        printf("Error: Please enter a number and not a char \n");
                        scanf("%*s");
                }
                else{
                        if(num<0){
                                printf("Error: Cannot read a negative value \n");
			}
			else{
				whole = num;
				bullyA = 0;
                	}	
		}
                printf("Amount?: \n");
                        if(scanf("%f",&amount)!=1){
                                printf("Error: Please enter a number and not a char \n");
                                scanf("%*s");
                        }
                        else{
                                if(amount<0){
                                        printf("Error: Cannot withdraw a negative amount of cash!! \n");
                                }
				else{
				real = amount;
				bullyB = 0;
				}
                        }       
        }
        while (amount < 0 || num < 0);
	if(bullyA == 0 && bullyB == 0){
         	withdraw(whole, real);
	}
	else{
		printf("Error: Returning back to main menu \n");
	}
         break;

      case 'C' :
      do{
	      printf("Account number? \n");
              	if(scanf("%d",&num)!=1){
              		printf("Error: Please enter a number!  \n");
              		scanf("%*s");
              }
              else{
                        if(num<0){
                                printf("Error: Cannot read a negative number \n");
			}
			else{
				close(num);
			}
              }
	}
        while(num<0);
         break;

      case 'I' :
         do{
        printf("Interest rate?: \n");
                if(scanf("%f",&amount)!=1){
                        printf("Error: It's not a number! \n");
                        scanf("%*s");
                }
                else{
                        if(amount<0){
                                printf("Error: Cannot increase interest rate with a negative value! \n");
                        }
			else{
				interestRate(amount);
			}
                }
        }
        while (amount < 0);
         break;

      case 'P' :
	 print();
	 break;

      case 'E':
	 exitProgram();
	 printf("All bank accounts are closed and the program will exit. Goodbye \n");
	 return 0;

      default:
	 printf("Invalid input, Please try again: \n");
	}
	ch = getchar();
	}
	while(ch!='O' || ch!='B' || ch!='D' || ch!='W' || ch!='C' || ch!='I' || ch!='P' || ch!='E');
	printf("Your selection is: %c",ch);
	return 0;
	}

