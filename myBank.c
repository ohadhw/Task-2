#include "myBank.h"
#include <stdio.h>
        int num;
        float amount;
        float current;
	int bool;
	int account;

void open(float real){
	/* --------------First function explaination---------------
	 * The "if real<0" case is for double make sure wrong inputs won't be recieved
	 * At first there is a counter that its porpuse is an "edge" case, therefore if 
	 * the counter gets to 49 it will throw an error that "all accounts are open" and won't procced
	 * 
	 * if the counter isn't 49 then there will be a for loop that will run from 0 to 49 (50 bank accounts) and if [i][1] is 0 (empty)
	 * than it will turn it into one.
	 *
	 * [i][1] = stores in the two dimensional array 1 or 0 which 1 stands for open and 0 for closed
	 * [i][0] = stores the value of account i 
	 * [i][2] = stores the account number
	 *
	 */
	int counter = 0;
	if(real<0){
		printf("Error: cannot open an account with a negative amount of cash \n");
	}else{
        for(int i=0; i<50;i++){
            if(accounts[i][1]==1){
                counter++;
             }
       	}
        if(counter == 50 || accounts[49][1]==1){
                printf("Error: All accounts are open \n");
        }
        else{
		for(int i=0;i<50;i++){
			if(accounts[i][1]==0){
				accounts[i][1] = 1;
                           	accounts[i][0] = real;
			   	accounts[i][2] = i+901;
			   	num = accounts[i][2];
				break;
			}
		}
	}
	printf("An account has been opened successfully! \n");
	printf("Your bank accounts is %d \n",num);
	}
}
void balance(int whole){
	/* ----Second function explaination------
	 * There isn't much to explain here but, there is a boolean operator called "bool"
	 * there is a a for loop that runs until the last spot in the array, if whole (whole = whole number = account number) equals to
	 * the account of the array in the spot i and the account in spot i is open (1) than make current point on the value of the accout i
	 * AND change "bool" to 0
	 * if the condition won't happen than bool will be kept equal to 1 which will lead him to cause an error
	 *
	 */
	bool = 1;
	for(int i = 0; i<50;i++){
		if(whole == accounts[i][2] && accounts[i][1]==1){
			current = accounts[i][0];
			bool = 0;
		}
	}
	if(bool==1){
		printf("Error: Account number %d does not exist or closed \n",whole);
	}else{
		printf("The balance of account %d is %0.2f \n",whole,current);
	}

}
void deposit(int whole,float real){
	/*-----------Third function explaination---------------
	 *Like previous function there is a "bool" as well, and a double check of the "real" number (real= real number= amount you want to deposit)
	 *being insereted at first. if the account exist (whole == accounts[i][2]) and open as well (accounts[i][1]==1) then turn bool to 0 and make 
	 *the array in the spot [i][0] store the value of "real" + the value of [i][0]
	 *
	 * if the condition above does not come true it will change bool to 1 and print an error.
	 * else it will call the function of balance (as being asked)
	 *
	 */
	bool = 1;
	if(real<0){
		printf("Error: Cannot deposit a negative amount \n");
	}else
	{
		for(int i=0;i<50;i++){
			if(whole==accounts[i][2] && accounts[i][1]==1){
				bool = 0;
				accounts[i][0] = accounts[i][0]+real;
				}
		}	
	}
	if(bool == 1){
		printf("Error: Account number %d does not exist or closed \n",whole);
	}
	else{
		balance(whole);
	}
}

void withdraw(int whole,float real){
	/* ----------Fourth function explaination---------------------
	 * like previous functions - again a double check for the "real" being inserted 
	 * and a bool value. 
	 * there is also a bool = 3 which means if there isn't enough cash in the account (for example 3-4=-1 which 3 is the amount in the bank and 4 is what you want to withdraw
	 * else it will change bool to 0 and do the whole procedure of substract the amount from the total amount of the bank account
	 *
	 */
	        bool = 1;
		if(real<0){
			printf("Error: Cannot withdraw a negative amount of cash! \n");
		}
		else{
               		for(int i=0;i<50;i++){
                        	if(whole==accounts[i][2] && accounts[i][1]==1){
					if((accounts[i][0]-real)<0){
						bool = 3;
					}
					else{
                                		bool = 0;
                                		account = whole;
						accounts[i][0] -= real;
                        		}
				}
               		}	
                	if(bool == 1){
                        	printf("Error: Account number %d does not exist or closed \n",whole);
                	}
			else if(bool == 3){
				printf("Error: Insufficient funds! \n");
			}
                	else{
                        	printf("%0.2f has been withdrawn successfully! \n",real);
                        	balance(account);
			}

                }

}

void close(int whole){
	/* ---------Fifth function explaination-----------
	 * As previous functions there is a bool value that if it changes it will print that the bank account have been closed
	 * successfully else it will print an error.
	 * if the bank account is exist within the array and the bank account is open it will make both account state (open/closed)
	 * to point at 0 which means closed account and 0 value
	 */
	bool = 1;
	for(int i=0;i<50;i++){
		if(whole==accounts[i][2] && accounts[i][1]==1){
			account = whole;
			accounts[i][1] = 0;
			accounts[i][0] = 0;
			bool = 0;
		}
	}
	if(bool==1){
		printf("Error: account number %d does not exist or closed \n",whole);
	}
	else{
		printf("Account number %d has been close successfully! \n",account);
	}
}

void interestRate(float real){
	/*--------Sixth function explaination----------
	 *like previous a bool value and a double check (real<0)
	 *This function increase all the interest rate if there are accounts open.
	 *if there aren't it will print an error that no account is open
	 *else if bool value points at 0 it will print that the interest rate have been changed
	 */
	bool = 1;
	if(real<0){
		printf("Error: Cannot increase the rate with a negative value \n");
	}
	else{
        	for(int i=0;i<50;i++){
                	if(accounts[i][1]==1){
                        	accounts[i][0] = accounts[i][0] + (accounts[i][0]*(real/100));
                        	bool = 0;
			}
                }
	
        	if(bool==1){
			printf("Error: No account is open \n");
        	}
        	else{
			printf("All accounts interest rates have changed successfully \n");
		}
	}
}

void print(){
	/*-------------Seventh function explaination---------------
	 *if there are no accounts open it will print that and won't do anything
	 *but if there are, it will scan which account is and change bool to 0 and print each amount held by which account
	 */
	bool = 1;
	for(int i=0;i<50;i++){
		if(accounts[i][1]==1){
			bool = 0;
			account = accounts[i][2];
			printf("Account number: %d, cash:  %0.2f \n",account, accounts[i][0]);
		}
	}
	if(bool == 1){
		printf("Error: No account is open \n");
	}
}

void exitProgram(){
	/*-------------Eight function explaination-------------
	 * just go over all the array and puts the balance to zero ([i][0]=0) and turn the account to closed ([i][1]=0)
	 */
	for(int i=0;i<50;i++){
		accounts[i][0] = 0;
		accounts[i][1] = 0;
	}
}
