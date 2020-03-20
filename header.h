/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||///////////////////////////////////////////////////////////////////////////
						       | Project :  Financial Planner                               |
						       |        By                                                  |
						       |            Arun Ranjan Sahu (173215)                       |
						       |            Abhay Dhiman     (173213)                       |
						       |            Pintu Roy        (173207)                       |
						       | Class   :  B.Sc.{ (III)rd  Maths }                         |
						       | Date    :  21/03/2020                                      |
///////////////////////////////////////////////////////||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
////////////////////////////////////////////////////////////////////HEADER FILES////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ncurses.h>
#include<limits.h>
///////////////////////////////////////////////////////////////Structure Declarations///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct Password    
{
    char password[15];
    int  rand_value[15];
    int   len;
    int  user_status;
    int  operation[15];
}Password;
typedef struct Yearlist
{
    char ID[7];
    int  year;
    struct Yearlist *next;
}Yearlist;
typedef struct Debit
{
    char receiver_id[7];
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
    char   ID[7];
    Name  name;
    char  gender[1];
    int   age;
    float income;
    int year;
    expense exp;              
}employee;
typedef struct Transaction
   {
    char  ID[7];
    Name  name;
    char  dt[10];
    float amount;
    struct Transaction *left;
    struct Transaction *right;
   }Transaction;
///////////////////////////////////////////////////////////////////////////FUNCTION PROTOTYPE///////////////////////////////////////////////////////////////////////////////////////////////////
int 	     MainWin(char *c);
void 	     Encryption(WINDOW * ,char*,char*);
Password     Decryption(char*);
int 	     EPassword(WINDOW *w,char *c);
void 	     ChangePassword(WINDOW *w,char *c);
void 	     NewUser(WINDOW *w,char *c);
int 	     MainFun(char *a,char *b);
int          Menu(WINDOW *w,int y,int x,char list[13][40],int n,int c,int ch);
int          MenuMonth(WINDOW *w,int y,int x, char list[13][40],int n,int ch,int c,int a);
void         FileEmployeeDetail(char *T,char *B);
void         EmployeeDetail(WINDOW *,employee ,char *);
void         DisplayId(WINDOW *w,employee E,char *a);
int          DateChangeCheck(char *str);
int          CheckLeapYear(int year);
int          ValidityDate(int date,int month,int year);
void         BillDetail(WINDOW *w,char *a );
void         PolicyDetail(WINDOW *w,char *a);
void         CreateNode(employee,int,Transaction**,Transaction**);
Transaction* FillName(WINDOW *w,char *a,Transaction *root,int option,char *ID,int sw,int y);
Transaction* TransferDetailTree(Transaction*,Transaction*,Transaction*);
int          DisplayTransferDetail_DEBIT(WINDOW*,Transaction*,char*,int);
int          DisplayTransferDetail_CREDIT(WINDOW*,Transaction*,char*,int);
void         TransferDetail(WINDOW *w,char *a);
int          DisplayAllTransfer_DEBIT(WINDOW *w,Transaction *S_root,int y);
int          DisplayAllTransfer_CREDIT(WINDOW *w,Transaction *R_root,int y);
void         TransferDetail_all(WINDOW *w,char *a);
int 	     DisplayTransferDetail_DEBIT(WINDOW*,Transaction*,char*,int);
int 	     DisplayTransferDetail_CREDIT(WINDOW*,Transaction*,char*,int);
float 	     EstimateIncome(char ID[],int year,char *a);
void 	     TransferDetails_clear(WINDOW *w,char *a);
void 	     TransferAllDetails_clear(WINDOW *w,char *a);
Transaction* ClearDebt(Transaction *root,char *ID1,char *ID2,float amount);
Yearlist*    MakeNode(char*,int);
float        TaxCal(float gross_sal,char ID[],int year,char *a);
void         TAX(WINDOW *w,char *a);
Yearlist*    Insert(Yearlist*,char*,int);
int 	     Search(Yearlist*,char*,int);
void 	     TotalTax(WINDOW*,char*);
void 	     TrackIncome(employee);
float 	     GrossSal(char*,int,char*);
