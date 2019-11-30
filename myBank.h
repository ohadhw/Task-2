#ifndef MYBANK_H_
#define MYBANK_H_
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
