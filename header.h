#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ncurses.h>

char *gets(char *s);
typedef struct Debit
{
    char receiver_id[20];
    char receiver_acc[20];
    char dt[10];
    float amount;
}Debit;
typedef struct billdetail
{
    float houserent;
    float elec_bill;
    float groceries;
    float others;
}billdetail;
typedef struct account
{
    Debit debit[10];
    float tax;
}account;
typedef struct policydetail
{
    float lifeins;
    float medicalins;
    float motorins;
    float others;
}policydetail;
typedef struct expense
{
    int month;
    billdetail BD;
    account AC;
    policydetail PD;
}expense;

typedef struct Name
{
    char init[20];
    char surname[20];
}Name;

typedef struct employee
{
    char   ID[20];
    Name  name;
    char  gender[1];
    int   age;
    char acc_no[20];
    float income;
    int year;
    expense exp;                    //The income & expenses are taken yearly
    float tax;
}employee;

typedef struct Transaction
   {
    char  ID[10];
    Name  name;
    char  dt[10];
    float amount;
    struct Transaction *left;
    struct Transaction *right;
   }Transaction;
////////////////////////////////////////FUNCTION PROTOTYPE/////////////////////////////////////////////
void   Employee_Detail(WINDOW *,employee ,char *);
void   Expense_Detail();//takes all expenses from the user and write to employee's ID.txt file
void   Display_Summary();//Displaying all expenses in tabular column
void   Expense_Graph();//Displaying the graph of expense over a period of time
float taxcal(employee E);//Tax Calculator
int menu(WINDOW *w,int y,int x,char list[13][40],int n,int c,int ch);
void TAX(WINDOW *w,char *a);
void display_id(WINDOW *w,employee E,char *a);
void transation(WINDOW *w,employee E,char *a);
int menu_month(WINDOW *w,int y,int x, char list[13][40],int n,int ch,int c,int a);
int  datechange_cheak(char *str);
int CheckLeapYear(int year);
int ValidityDate(int date,int month,int year);
void FileEmployeeDetail(char *T,char *B);
void BillDetail(WINDOW *w,char *a );
void PolicyDetail(WINDOW *w,char *a);
void   CreateNode(employee,int,Transaction**,Transaction**);
Transaction* FillName(WINDOW *w,char *a,Transaction *root,int option,char *ID,int sw,int y);
Transaction* TransferDetailTree(Transaction*,Transaction*,Transaction*);
int DisplayTransferDetail_DEBIT(WINDOW*,Transaction*,char*,int);
int DisplayTransferDetail_CREDIT(WINDOW*,Transaction*,char*,int);
void TransferDetail(WINDOW *w,char *a);
int DisplayAllTransfer_DEBIT(WINDOW *w,Transaction *S_root,int y);
int DisplayAllTransfer_CREDIT(WINDOW *w,Transaction *R_root,int y);
void TransferDetail_all(WINDOW *w,char *a);
void main_fun(char *a,char *b);
float EstimateIncome(char ID[],int year);
