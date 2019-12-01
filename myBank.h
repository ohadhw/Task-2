#ifndef MYBANK_H_
#define MYBANK_H_
#define OPEN 1
#define CLOSED 0
#define DEPOSIT 0
#define STATUS 1
#define ACCOUNTNUMBER 2

extern float accounts[50][3]; 

void open(float real);

void balance(int whole);

void deposit(int whole, float real);

void withdraw(int whole,float real);

void close(int whole);

void interestRate(float real);

void print();

void exitProgram();



#endif
