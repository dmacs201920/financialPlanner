# financialPlanner.3bsc
Novice project on Financial Planning stuff. Implements basic functionality
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||///////////////////////////////////////////////////////////////////////////
                                                       | Project :  Financial Planner                               |
                                                       |        By                                                  |
                                                       |            Arun Ranjan Sahu (173215)                       |
                                                       |            Abhay Dhiman     (173213)                       |
                                                       |            Pintu Roy        (173207)                       |
                                                       | Class   :  B.Sc.{ (III)rd  Maths }                         |
                                                       | Date    :  21/03/2020                                      |
///////////////////////////////////////////////////////||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||///////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                               Financial Planner Project's Manual
NAME :
            Financial Planner

DIRECTION TO RUN :
             User should give command as ./FinancialPlanner EmployeesB.txt Employees.txt PasswordNew.txt
DESCRIPTION: 
	     This Project has three components 
	                      1. Tracking the income & expenditure.
					- Collects the income & expenses (manual/files) on a regular basis.
					- Tracks them continuosly.
					- Keeps track of Bill detail, Accounts & Policy. 
			      2. Analysis.
					- Shows basic income and expense summary.
					- Classification
						a. Transaction Analysis.
						b. Policy Detail Analysis.
			      3. Tax calculation. 
					a. Calculates the tax of given Employee.
					b. Calculate  the total tax of given year.
             This program helps the individual or the user to plan his expenditure based on his requirements. This program helps him to know where he has spend more amount of money in the
	     given month or year. It also helps him to keep track of his account transactions in the year.This program gives him the month where his expenditure is maximum and minimum
             which helps him to plan accordingly for the coming months. It also gives the Tax to be paid by the employee and keeps track of the tax in the year for the income tax department.

NOTES:
             This Program takes input in two ways i.e. through a file or By User.The data, contains personal information of an user, monthly income, transactions of the  month, expenditure(
             Bill Detail and Policies), are stored in a binary file. The income & expenses(Bill Detail,Transactions,Policies) are tracked on a regular basis.
        
             In the analysis part, the summary of the income & expenses are shown.The summary of the Bill Detail, Transactions and Policy Details are shown analytically.The analysis of
             Transaction displays the statement (debit and credit) of an individual or all Employees or the resultant debited or credited amount(Here resultant means if A->B(Rs. 1000) and
             B->A(Rs. 500), then the resultant tranferred amount is Rs. 500(A->B).
          
             The tax of an user is calculated and shown in the details summary.Also the Income Tax Department keeps the tax detail of an individual and total tax of a particular year.

             The password of the program is '0000' by default.The primary step to run the program is to change the password by signing up and keep a strong password.The password is encrypted
             and kept in a binary file from where it is furthur decrypted and compared to the typed string by the user.You cannot run the program unless you change the default password.
             This is done for a better security.
            
             The details of the users is taken from the text file through function EmployeeDetail(WINDOW*,employee,char*) to a binary file.The summary of the expenses is displayed by function 
             DisplayId().This summary consists of personal data of the user, expenses in household, electric bill, groceries and others.It also contains expenses in  various policies.
             The BillDetail() also displays the detail of the months having maximum and minimum expenses.The tansactions details are kept in the form of tree using double linked list.The tree
             is formed in the function TransferDetailTree(Transaction*,Transaction*,Transaction*).Every node contains details of the transaction like amount,ID,date.Then the offset
             Credit/Debit is created as a tree after finding the resultant amount transferred.The transfer details of a individual or all employees of a file is displayed through various 
             functions.If there is an ID whose personal detail is not available in the file,then program asks user to give his personal details and keeps this record in the binary file.
             
             The income of an user of a particular year is calculated by function EstimateIncome(char *,int ).It takes ID & year and calculates the salary of that year.From this salary,the
             gross salary of the user is calculated.Henceforth the tax is calculated on the basis of the gross salary.The year limit is 2000<=year<=2020.The tax is calculated on the basis
             gender and age of the user.The Income Tax Department calculates the tax of a person and displays it.The department also displays the total tax paid in a particular year by
             different users.The ID and year of a perticular user is kept in a linear linked list to avoid another calculation if the record with same ID & year is found.
ASSUMPTION:       
             The program gives unexpexted output if strlen(ID)!=6 and if year<2001 and year>2020. If the number of the words in the user name is not equal 2 the the outcome is unexpected. The              salary of the user is calculated based on the monthly inmcome of the particular year.  

