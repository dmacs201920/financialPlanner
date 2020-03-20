#include"header.h"
//////////////////////////////This function takes the details from the user and writes  it to binary file.(By Abhay)////////////////////////////////////////////////////////////////////////////
void EmployeeDetail(WINDOW *w,employee E,char *a)
{
    int ac,j,k,space,i=5,y=3,t=4,ch,sw,cmp;
    k=i;
    employee F;
    char ID[7];
    char choice[4][40]={"YES","NO"};
    char month_p[12][5]={"Jan.","Feb.","Mar.","Apr.","May","June","July","Aug.","Sept.","Oct.","Nov.","Dec."};
    FILE *p,*q;
    echo();
    wattron(w,A_ALTCHARSET);
    mvwprintw(w,2,10,"%s","Enter the Details of an Employee."); 
    wattroff(w,A_ALTCHARSET);
    p=fopen(a,"ab");
    if(p==NULL)          //Cheaking if File opened Properly.
    {
        mvwprintw(w,1,5,"%s","Not able to Open");
        sleep(3);
        exit(-1);
    }
    wattron(w,A_UNDERLINE);
    mvwprintw(w,i++,y,"%s","ID:");
    wattroff(w,A_UNDERLINE);
    wgetstr(w,E.ID);                //Taking the Input as ID. 
    q=fopen(a,"rb");
    if(q==NULL)                    //Cheaking if File opened Properly. 
   {
        mvwprintw(w,1,5,"%s","Not able to Open");
        sleep(3);
        exit(-1);
    }
    while(fread(&F,sizeof(employee),1,q)==1)//Cheaking if the Detail of the particular detail is avalable or not.
    {
        if(strcmp(F.ID,E.ID)==0)
        {
            E=F;
            goto existing;                 //If Avaliable print the personal Detail and Start taking input Year onwards.
        }
    }
    wattron(w,A_UNDERLINE);
    mvwprintw(w,i++,y,"%s","First Name:");
    wattroff(w,A_UNDERLINE);
    wscanw(w,"%s",E.name.init);                 //Taking the Input as First Name.
    wattron(w,A_UNDERLINE);
    mvwprintw(w,i++,y,"%s","Last Name:");
    wattroff(w,A_UNDERLINE);
    wscanw(w,"%s",E.name.surname);              //Taking the Input as Last Name.
age:    wattron(w,A_UNDERLINE);
        mvwprintw(w,i,y,"%s","Age:");          //Taking the Input as Age.
        wattroff(w,A_UNDERLINE);
        wscanw(w,"%d",&E.age);
        if(E.age<=14)                           //Cheaking Age Limits.
        {
            for(space=2;space<=55;space++)
                mvwprintw(w,i,space,"%s","  ");
            wattron(w,COLOR_PAIR(4));
            mvwprintw(w,39,10,"%s","* Inappropriate Input.");    //Printing a Message.
            wattroff(w,COLOR_PAIR(4));
            wrefresh(w);
            goto age;                          //If Input is Inapropriate then Again take the Input from the User.
        }
        i++;

        for(space=2;space<=55;space++)
            mvwprintw(w,39,space,"%s","  ");
        wrefresh(w);
gender:   wattron(w,A_UNDERLINE);
          mvwprintw(w,i,y,"%s","Gender(M/F/O):");    //Taking the Input as Gender.
          wattroff(w,A_UNDERLINE);
          wscanw(w,"%s",&E.gender);
          if(strcmp(E.gender,"M") && strcmp(E.gender,"F") && strcmp(E.gender,"O"))      //Cheaking if Input is Correct.
          {
              for( space=2;space<=55;space++)
                  mvwprintw(w,i,space,"%s","  ");
              wattron(w,COLOR_PAIR(4));
              mvwprintw(w,39,10,"%s","* Inappropriate Input.");		//Printing a Message.
              wattroff(w,COLOR_PAIR(4));
              wrefresh(w);
              goto gender;			//If Input is Inapropriate then Again take the Input from the User.
          }
          i++;
          for(space=2;space<=55;space++)
              mvwprintw(w,39,space,"%s","  ");
          wrefresh(w);
here1:	  wattron(w,A_UNDERLINE);
          mvwprintw(w,i,y,"%s","Year of INCOME:");     
          wattroff(w,A_UNDERLINE);
          wscanw(w,"%d",&E.year);                       //Taking Input
          if(E.year<=0)                                 //Cheaking if Input is Correct.
          {
              for( space=2;space<=55;space++)
                  mvwprintw(w,i,space,"%s","  ");
              wattron(w,COLOR_PAIR(4));
              mvwprintw(w,39,10,"%s","* Inappropriate Input.");		//Printing a Message.
              wattroff(w,COLOR_PAIR(4));
              wrefresh(w);
              goto here1;			//If Input is Inapropriate then Again take the Input from the User.
          }
          i++;
          for(space=2;space<=55;space++)
              mvwprintw(w,39,space,"%s","  ");
          wrefresh(w);
MOI:       wattron(w,A_UNDERLINE);
           mvwprintw(w,i,y,"%s","Month of INCOME:");          //Taking Input.
           wattroff(w,A_UNDERLINE);
           wscanw(w,"%d",&E.exp.month);
           if(E.exp.month<1 || E.exp.month>12)		//Cheaking if Input is Correct.
           {
               for(space=2;space<=55;space++)
                   mvwprintw(w,i,space,"%s","  ");
               wattron(w,COLOR_PAIR(4));
               mvwprintw(w,39,10,"%s","* Inappropriate Input.");	//Printing a Message.
               wattroff(w,COLOR_PAIR(4));
               wrefresh(w);
               goto MOI;			//If Input is Inapropriate then Again take the Input from the User.
           }
           i++;
           for(space=2;space<=55;space++)
               mvwprintw(w,39,space,"%s","  ");
           wrefresh(w);
IOY:       wattron(w,A_UNDERLINE);
           mvwprintw(w,i,y,"Income(of %s %d):",month_p[E.exp.month-1],E.year);
           wattroff(w,A_UNDERLINE);
           wscanw(w,"%f",&E.income);      //Taking Income of the Particular Month.
           if(E.income<=0)
           {
               for( space=2;space<=55;space++)
                   mvwprintw(w,i,space,"%s","  ");
               wattron(w,COLOR_PAIR(4));
               mvwprintw(w,39,10,"%s","* Inappropriate Input.");	//Printing a Message.
               wattroff(w,COLOR_PAIR(4));
               wrefresh(w);
               goto IOY;		//If Input is Inapropriate then Again take the Input from the User.
           }
           i++;
           for(space=2;space<=55;space++)
               mvwprintw(w,39,space,"%s","  ");
           wrefresh(w);
           wattron(w,A_UNDERLINE);
           mvwprintw(w,i++,y,"EXPENDITURES (of %s %d ):",month_p[E.exp.month-1],E.year); //Taking Monthly Expenditure & Further Cheaking if the Input is Correct or Not.
           mvwprintw(w,i++,y,"%s","BILL DETAILS:");
BDH:       mvwprintw(w,i,y+t,"%s","House Rent:");
           wattroff(w,A_UNDERLINE);
           wscanw(w,"%f",&E.exp.BD.houserent);
           if(E.exp.BD.houserent<=0)
           {
               for(space=2;space<=55;space++)
                   mvwprintw(w,i,space,"%s","  ");
               wattron(w,COLOR_PAIR(4));
               mvwprintw(w,39,10,"%s","* Inappropriate Input.");
               wattroff(w,COLOR_PAIR(4));
               wrefresh(w);
               goto BDH;
           }
           i++;
           for(space=2;space<=55;space++)
               mvwprintw(w,39,space,"%s","  ");
           wrefresh(w);

BDE:       wattron(w,A_UNDERLINE);
           mvwprintw(w,i,y+t,"%s","Electric Bill:");
           wattroff(w,A_UNDERLINE);
           wscanw(w,"%f",&E.exp.BD.elec_bill);
           if(E.exp.BD.elec_bill<=0)
           {
               for(space=2;space<=55;space++)
                   mvwprintw(w,i,space,"%s","  ");
               wattron(w,COLOR_PAIR(4));
               mvwprintw(w,39,10,"%s","* Inappropriate Input.");
               wattroff(w,COLOR_PAIR(4));
               wrefresh(w);
               goto BDE;
           }
           i++;
           for(space=2;space<=55;space++)
               mvwprintw(w,39,space,"%s","  ");
           wrefresh(w);

BDG:       wattron(w,A_UNDERLINE);
           mvwprintw(w,i,y+t,"%s","Groceries:");
           wattroff(w,A_UNDERLINE);
           wscanw(w,"%f",&E.exp.BD.groceries);
           if(E.exp.BD.groceries<=0)
           {
               for(space=2;space<=55;space++)
                   mvwprintw(w,i,space,"%s","  ");
               wattron(w,COLOR_PAIR(4));
               mvwprintw(w,39,10,"%s","* Inappropriate Input.");
               wattroff(w,COLOR_PAIR(4));
               wrefresh(w);
               goto BDG;
           }
           i++;
           for(space=2;space<=55;space++)
               mvwprintw(w,39,space,"%s","  ");
           wrefresh(w);

BDO:       wattron(w,A_UNDERLINE);
           mvwprintw(w,i,y+t,"%s","Others:");
           wscanw(w,"%f",&E.exp.BD.others);
           if(E.exp.BD.others<=0)
           {
               for(space=2;space<=55;space++)
                   mvwprintw(w,i,space,"%s","  ");
               wattron(w,COLOR_PAIR(4));
               mvwprintw(w,39,10,"%s","* Inappropriate Input.");
               wattroff(w,COLOR_PAIR(4));
               wrefresh(w);
               goto BDO;
           }
           i++;
           for(space=2;space<=55;space++)
               mvwprintw(w,39,space,"%s","  ");
           wrefresh(w);
           wattron(w,A_UNDERLINE);
           mvwprintw(w,i++,y,"%s","POLICY DETAILS:");	//Taking Different POLICY Details & Further Cheaking if the Input is Correct or Not.
           mvwprintw(w,i++,y+t,"%s","Life Insurance:");
           wattroff(w,A_UNDERLINE);
           wscanw(w,"%f",&E.exp.PD.lifeins);
PDMI:      wattron(w,A_UNDERLINE);
           mvwprintw(w,i,y+t,"%s","Medical Insurance:");
           wattroff(w,A_UNDERLINE);
           wscanw(w,"%f",&E.exp.PD.medicalins);
           if(E.exp.PD.medicalins<=0)
           {
               for(space=2;space<=55;space++)
                   mvwprintw(w,i,space,"%s","  ");
               wattron(w,COLOR_PAIR(4));
               mvwprintw(w,39,10,"%s","* Inappropriate Input.");
               wattroff(w,COLOR_PAIR(4));
               wrefresh(w);
               goto PDMI;
           }
           i++;
           for(space=2;space<=55;space++)
               mvwprintw(w,39,space,"%s","  ");
           wrefresh(w);

PDM:       wattron(w,A_UNDERLINE);
           mvwprintw(w,i,y+t,"%s","Motor Insurance");
           wattroff(w,A_UNDERLINE);
           wscanw(w,"%f",&E.exp.PD.motorins);
           if(E.exp.PD.motorins<=0)
           {
               for(space=2;space<=55;space++)
                   mvwprintw(w,i,space,"%s","  ");
               wattron(w,COLOR_PAIR(4));
               mvwprintw(w,39,10,"%s","* Inappropriate Input.");
               wattroff(w,COLOR_PAIR(4));
               wrefresh(w);
               goto PDM;
           }
           i++;
           for(space=2;space<=55;space++)
               mvwprintw(w,39,space,"%s","  ");
           wrefresh(w);

PDO:       wattron(w,A_UNDERLINE);
           mvwprintw(w,i,y+t,"%s","Others:");
           wattroff(w,A_UNDERLINE);
           wscanw(w,"%f",&E.exp.PD.others);
           if(E.exp.PD.others<=0)
           {
               for( space=2;space<=55;space++)
                   mvwprintw(w,i,space,"%s","  ");
               wattron(w,COLOR_PAIR(4));
               mvwprintw(w,39,10,"%s","* Inappropriate Input.");
               wattroff(w,COLOR_PAIR(4));
               wrefresh(w);
               goto PDO;
           }
           i++;
           for(space=2;space<=55;space++)
               mvwprintw(w,39,space,"%s","  ");
           wrefresh(w);

           wattron(w,A_UNDERLINE);
           mvwprintw(w,i++,y+t,"%s","Do you have any Transitions (Debit) : "); 
           wattroff(w,A_UNDERLINE);
           sw=Menu(w,i-1,y+11*t,choice,2,ch,0);  //Menu Function For Yes Or No.
           i++;
           ac=0;
           if(sw==i-2)
           {
transactions:	echo();
                wattron(w,A_UNDERLINE);
                mvwprintw(w,i++,y,"%s","ACCOUNT:");
                mvwprintw(w,i++,y+t,"%s","Debit:");
                mvwprintw(w,i++,y+2*t,"%s","Receivers's ID:");
                wattroff(w,A_UNDERLINE);
                wgetstr(w,E.exp.AC.debit[ac].receiver_id);         //Taking Input As Receivers ID.
date:		wattron(w,A_UNDERLINE);
            mvwprintw(w,i,y+2*t,"%s","Date of Transaction(dd/mm/yyyy):"); 
            wattroff(w,A_UNDERLINE);
            wscanw(w,"%s",&E.exp.AC.debit[ac].dt);               //Transaction Date as a String.
            if(DateChangeCheck(E.exp.AC.debit[ac].dt)!=1)        //Cheaking The Correctness of the Date.
            {
                for(j=2;j<=55;j++)
                    mvwprintw(w,i,j,"%s","  ");
                wattron(w,COLOR_PAIR(4));
                mvwprintw(w,39,10,"%s","* Inappropriate Input.");
                wattroff(w,COLOR_PAIR(4));
                wrefresh(w);
                goto date;             //If Input Date is Not Correct ,take the Input Again.
            }
            i++;
            for(space=2;space<=55;space++)
                mvwprintw(w,39,space,"%s","  ");
            wrefresh(w);
DA:		wattron(w,A_UNDERLINE);
        mvwprintw(w,i,y+3*t,"%s","Amount :");
        wattroff(w,A_UNDERLINE);
        wscanw(w,"%f",&E.exp.AC.debit[ac].amount);       //Taking Input as Amount Debited.
        if(E.exp.AC.debit[ac].amount<=0)          //Cheaking The Correctness of Amount.
        {
            for(space=2;space<=55;space++)
                mvwprintw(w,i,space,"%s","  ");
            wattron(w,COLOR_PAIR(4));
            mvwprintw(w,39,10,"%s","* Inappropriate Input.");
            wattroff(w,COLOR_PAIR(4));
            wrefresh(w);
            goto DA;			//If the Input is Wrong, take Input Again.
        }
        i++;
        for(space=2;space<=55;space++)
            mvwprintw(w,39,space,"%s","  ");
        wrefresh(w);
        ac++;
        if(ac<=9)                               //Cheaking if Monthly Transaction Limit of Ten is Excedded. 
        {
            wattron(w,A_UNDERLINE);
            mvwprintw(w,i++,y+2*t,"%s","Do you want to Continue : ");
            wattroff(w,A_UNDERLINE);
            sw=Menu(w,i-1,y+9*t,choice,2,ch,0);   //Asking if More Transactions are There or not.
            if(sw==i-3)
            {
                i=i-11;
                for(j=0;j<=12;j++)
                    for(k=2;k<=55;k++)
                        mvwprintw(w,i+j,k,"%s","  ");
                goto transactions;          //If YES take next Transaction Details.
            }
            else
            {
                for(j=ac;j<=9;j++)          //If NO Then Assign All Other Amount for the Transactions as 'zero'.
                {
                    E.exp.AC.debit[j].amount=0;
                }
            }
        }
        else
        {
            for(j=ac;j<=9;j++)          //Assign All Remaining Transaction Amount as 'zero'.
            {
                E.exp.AC.debit[j].amount=0;
            }
        }
           }
           else
           {
               for(j=0;j<=9;j++)	//Assign All Remaining Transaction Amount as 'zero'.
               {
                   E.exp.AC.debit[j].amount=0;
               }
           }
           fwrite(&E,sizeof(employee),1,p);  //Write The Details to the File.
           wattron(w,A_UNDERLINE);
           mvwprintw(w,i++,y+t,"%s","Do you want to Continue : ");
           wattroff(w,A_UNDERLINE);
           sw=Menu(w,i,y+7*t,choice,2,ch,0);//Menu ,Asking if the User Want to Continue or Not ,for same ID.
           if(sw==i)               // If Yes Print the Personal Details.
           {
               noecho();               //Disabling the Display of Buffer on the Screen.
               i=k;
               wclear(w);
               wrefresh(w);
               wattron(w,A_STANDOUT);
               wattron(w,COLOR_PAIR(1));
               wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
               wattroff(w,COLOR_PAIR(1));
               wattroff(w,A_STANDOUT);
               echo();                    //Enable the Buffer.
               keypad(w,TRUE);
               wattron(w,A_ALTCHARSET);
               wattron(w,A_UNDERLINE);
               mvwprintw(w,3,10,"%s","Please enter the details of employees :");
               wattroff(w,A_UNDERLINE);
               wattroff(w,A_ALTCHARSET);
               p=fopen(a,"ab");
               if(q==NULL)
               {
                   mvwprintw(w,1,5,"%s","Not able to Open");
                   sleep(3);
                   exit(-1);
               }
               wattron(w,A_UNDERLINE);
               mvwprintw(w,i++,y,"%s","ID:");
               wattroff(w,A_UNDERLINE);
               mvwprintw(w,i-1,y+2*t,"%s",E.ID);
existing:      wattron(w,A_UNDERLINE);
               mvwprintw(w,i++,y,"%s","First Name:");
               wattroff(w,A_UNDERLINE);
               mvwprintw(w,i-1,y+3*t,"%s",E.name.init);
               wattron(w,A_UNDERLINE);
               mvwprintw(w,i++,y,"%s","Last Name:");
               wattroff(w,A_UNDERLINE);
               mvwprintw(w,i-1,y+3*t,"%s",E.name.surname);
               wattron(w,A_UNDERLINE);
               mvwprintw(w,i,y,"%s","Age:");
               wattroff(w,A_UNDERLINE);
               mvwprintw(w,i,y+t+1,"%d",E.age);
               i++;
               wattron(w,A_UNDERLINE);
               mvwprintw(w,i,y,"%s","Gender(M/F/O):");
               wattroff(w,A_UNDERLINE);
               mvwprintw(w,i,y+4*t-1,"%s",E.gender);
               i++;
               goto here1;  //After Printing the Personal Details Take new Inputs Fron Year Onwards.
           }
           fclose(p);   //Close the File.

}

//////////////////////////////////////////////////////Creates the Window of Tax Details[By Abhay ]//////////////////////////////////////////////////////////////////////////////////////////////
void TAX(WINDOW *w,char *a)
{
    char ID[7];
    int year;
    float tax,income;
    employee E;
    echo();              //Enable teh Buffer.
    wattron(w,A_BOLD);
    mvwprintw(w,2,34,"%s","ID :");
    wgetstr(w,ID);       //Taking the ID.
    mvwprintw(w,3,34,"%s","YEAR :"); 
    wscanw(w,"%d",&year);  //Taking the Year for Which Tax to-be Paid is to be Displayed.
    wattroff(w,A_BOLD);
    noecho();
    wrefresh(w);
    income=GrossSal(ID,year,a);         //Calculating the Gross Salary.
    tax=TaxCal(income,ID,year,a);       //Calculating the Approx Tax.
    if(tax!=0)    //Condition For if Employee is Avaliabe or Not.
    {
        mvwprintw(w,4,10,"Tax to be paid by the Employee is %.2f ",tax);  //Printing the Tax To be Paid.
         wrefresh(w);
    }
    if(tax==0)
    {
        wattron(w,COLOR_PAIR(4));
        mvwprintw(w,5,10,"Employee Details not Avaliable.");
        wattroff(w,COLOR_PAIR(4));
    }
    wrefresh(w);         //Reafreshing the Window.
}
/////////////////////////////////////////////////Calculates the tax of the given Employee (By Arun)////////////////////////////////////////////////////////////////////////////////////////////
float TaxCal(float gross_sal,char ID[],int year,char *a)
{
    float sal,policy=0,tax=0;
    employee E;
    FILE *f;
    int i=0,j=0,s=1,k=0,flag=0;
    float slab[][8]={{2001,50000,0,60000,10,150000,20,30},
        {2002,50000,0,60000,10,150000,20,30},
        {2003,50000,0,60000,10,150000,20,30},
        {2004,50000,0,60000,10,150000,20,30},
        {2005,50000,0,60000,10,150000,20,30},
        {2006,100000,0,150000,10,250000,20,30},
        {2006,135000,0,150000,10,250000,20,30},
        {2006,185000,0,250000,20,30},                                              
        {2007,100000,0,150000,10,250000,20,30},
        {2007,135000,0,150000,10,250000,20,30},
        {2007,185000,0,250000,20,30},
        {2008,110000,0,150000,10,250000,20,30},
        {2008,145000,0,150000,10,250000,20,30},
        {2008,195000,0,250000,20,30}, 
        {2009,150000,0,300000,10,500000,20,30},                                 
        {2009,80000,0,300000,10,500000,20,30},
        {2009,225000,0,300000,10,500000,20,30},                                        //Slab Rates of Tax
        {2010,160000,0,300000,10,500000,20,30},                                       //year, Amount limit, rate(%)
        {2010,190000,0,300000,10,500000,20,30},
        {2010,224000,0,300000,10,500000,20,30},
        {2011,160000,0,500000,10,800000,20,30},
        {2011,190000,0,500000,10,800000,20,30},
        {2011,224000,0,500000,10,800000,20,30},
        {2012,180000,0,500000,10,800000,20,30},
        {2012,190000,0,500000,10,800000,20,30},
        {2012,250000,0,500000,10,800000,20,30},
        {2013,200000,0,500000,10,1000000,20,30},
        {2013,200000,0,500000,10,1000000,20,30},
        {2013,250000,0,500000,10,1000000,20,30},
        {2014,200000,0,500000,10,1000000,20,30},
        {2014,200000,0,500000,10,1000000,20,30},
        {2014,250000,0,500000,10,1000000,20,30},
        {2015,250000,0,500000,10,1000000,20,30},
        {2015,250000,0,500000,10,1000000,20,30},
        {2015,300000,0,500000,10,1000000,20,30},                    
        {2016,250000,0,500000,10,1000000,20,30},
        {2016,250000,0,500000,10,1000000,20,30},
        {2016,250000,0,500000,10,1000000,20,30},
        {2017,250000,0,500000,10,1000000,20,30},
        {2017,300000,0,500000,10,1000000,20,30},                    
        {2017,300000,0,500000,10,1000000,20,30},
        {2018,250000,0,500000,5,1000000,20,30},
        {2018,250000,0,500000,5,1000000,20,30},
        {2018,300000,0,500000,5,1000000,20,30},
        {2019,250000,0,500000,5,1000000,20,30},
        {2019,250000,0,500000,5,1000000,20,30},
        {2019,300000,0,500000,5,1000000,20,30},
        {2020,250000,0,500000,5,1000000,20,30},
        {2020,250000,0,500000,5,1000000,20,30},
        {2020,300000,0,500000,5,1000000,20,30}};
    f=fopen(a,"r");
    if(f==NULL)
    {
        printf("Not able to Open");
        sleep(3);
        exit(-1);
    }
    fread(&E,sizeof(employee),1,f);
    sal=GrossSal(ID,year,a);
    while(!feof(f))
    {
        if(strcmp(ID,E.ID)==0&&year==E.year)
        { 
            while(year==E.year)
            {
                for(i=0;i<51;i++)
                {
                    if(slab[i][0]==E.year)
                    {
                        if(E.year!=2001&&E.year!=2002&&E.year!=2003&&E.year!=2004&&E.year!=2005)
                        {
                            if(E.year<2012)
                            {

                                if(E.age>65)
                                {  
                                    i=i+2;
                                    break;
                                }
                                else if(E.gender[0]=='F'||E.gender[0]=='f')
                                {  
                                    i=i+1;
                                    break;
                                }
                                else
                                    break;
                            }
                            else
                                if(E.year>=2012)
                                {
                                    if(E.age>60)
                                    {
                                        i=i+2;
                                        break;
                                    }
                                    else if(E.gender[0]=='F'||E.gender[0]=='f')
                                    {
                                        i=i+1;
                                        break;
                                    }
                                    else
                                        break;
                                }  
                        }
                        else

                            if(E.year==2001||E.year==2002||E.year==2003||E.year==2004||E.year==2005)
                                break;
                    }
                }
                if(i==7||i==10||1==13)
                {
                    for(s=1;s<=3;s+=2)
                    {
                        if(sal>slab[i][s])
                            continue;
                        else
                            break;
                    }
                    if(s<5)
                    {
                        j=s-2;
                        k=s+1;
                    }
                    if(s==5)
                    {
                        j=s-2;
                        k=s;
                    }
                }
                else
                {
                    for( s=1;s<=5;s+=2)
                    {
                        if(sal>slab[i][s])
                            continue;
                        else
                            break;
                    }
                    if(s<7)
                    {
                        j=s-2;
                        k=s+1;
                    }
                    if(s==7)
                    {
                        j=s-2;
                        k=s;
                    }
                }
                for(j;j>=1;j-=2)
                {
                    tax=tax+(sal-slab[i][j])*(slab[i][k]/100);
                    if(k==s)
                        k=k-1;
                    else
                        k=k-2;
                    sal=slab[i][j];
                }
                fread(&E,sizeof(employee),1,f);
                flag=1;
            }
        }
        if(flag==1)
            break;
        fread(&E,sizeof(employee),1,f);
    }
    return tax;
}
////////////////////////////////////////////////////Calculate the Gross Salary.( By Arun)///////////////////////////////////////////////////////////////////////////////////////////////////////
float GrossSal(char ID[],int year,char *a)
{
    FILE *f;
    employee F;
    float policy=0,gross_sal;
    int flag=0;
    f=fopen(a,"r");
    if(f==NULL)
    {
        printf("Not able to Open");
        sleep(3);
        exit(-1);
    }
    fread(&F,sizeof(employee),1,f);
    while(!feof(f))                             //traversing through the file
    {
        if(strcmp(F.ID,ID)==0&&F.year==year) //comparing ID & year
        { 
            while(F.year==year)
            {	
                policy=policy+F.exp.PD.lifeins+F.exp.PD.medicalins+F.exp.PD.motorins+F.exp.PD.others;      //Calculating Amount spent in Policy
                fread(&F,sizeof(employee),1,f);
                flag=1;
            }
        }
        if(flag==1)
            break;
        fread(&F,sizeof(employee),1,f);
    }
    gross_sal=EstimateIncome(F.ID,F.year,a);              //Gives the estimate income of the employee.
    gross_sal=gross_sal-policy;                          // Calculates the gross Salary
    return gross_sal;
}

/////////////////////////////////////////////// Gives the estimate income of the employee. (By Arun)////////////////////////////////////////////////////////////////////////////////////////////

float EstimateIncome(char ID[],int year,char *a)
{
    employee E;
    FILE *f=fopen(a,"r+");
    if(f==NULL)
    {
        printf("Not able to Open");
        sleep(3);
        exit(-1);
    }
    float eincome=0;
    int i=0,flag=0;
    fread(&E,sizeof(employee),1,f);
    while(!(feof(f)))                                                   //Reads till the end of file
    {
        if((strcmp(E.ID,ID)==0)&&E.year==year)                     // compares the ID & year
        {
            eincome=E.income+eincome;
            i++;
            flag=1;
        }
        if(strcmp(E.ID,ID)!=0 || year!=E.year)
        {
            if(flag==1)
                break;
        }
        fread(&E,sizeof(employee),1,f);
    }	
    eincome=eincome/i;                     
    eincome=eincome*12;                                        //Calcultes the average income of the employee
    fclose(f);
    return eincome;
}
///////////////////////////////////////////////////Creates a node of type Yearlist (By Arun)////////////////////////////////////////////////////////////////////////////////////////////////////
Yearlist* MakeNode(char ID[],int year)
{
    Yearlist *temp;
    temp=malloc(1*sizeof(Yearlist));
    if(temp==NULL)                                        //Checks whether space is allocated.
    {
        printf("Space not available\n");
        exit(-1);
    }
    else
    {
        strcpy(temp->ID,ID);                       //Assigns data to the temp var 
        temp->year=year;
        temp->next=NULL;
    }
    return temp;
}
////////////////////////////////////////insert the year and ID of the employee to the linked list. (By Arun)////////////////////////////////////////////////////////////////////////////////////
Yearlist* Insert(Yearlist *head,char ID[],int year)
{
    Yearlist *temp=MakeNode(ID,year);
    if(head==NULL)
        return temp;
    else
    {
        head->next=temp;
        head=temp;
    }
}
////////////////////////////////////////searches the given ID and year in the link list.(By Arun)//////////////////////////////////////////////////////////////////////////////////////////////
int Search(Yearlist  *head,char ID[], int year)
{
    Yearlist *traverse=head;
    if(head==NULL)
        return 0;
    while(traverse!=NULL)
    {
        if(traverse->year==year && strcmp(traverse->ID,ID)==0)
            return 1;
        traverse=traverse->next;
    }
    return 0;
}
//////////////////////////////////////////////Gives the total tax Collected int the given year.(By Arun)///////////////////////////////////////////////////////////////////////////////////////
void TotalTax(WINDOW *w,char *a)
{
    float tax,total=0,sal;
    FILE *f;
    int flag=0,y=2,x=2,t=4,q=0,year;
    employee E;
    Yearlist *head=NULL;
    f=fopen(a,"r");
    if(f==NULL)
    {
        mvwprintw(w,y,x+7*t,"%s","The File does not exist");
        sleep(3);
        q=1;
    }
    if(q==0)
    {
        echo();
        wattron(w,A_BOLD);
        wattron(w,A_STANDOUT);
        mvwprintw(w,y,x+15*t,"%s","YEAR : ");
        wscanw(w,"%d",&year);
        wattroff(w,A_BOLD);
        wattroff(w,A_STANDOUT);
        noecho();
        fread(&E,sizeof(employee),1,f);
        wattron(w,A_BOLD);
        wattron(w,A_UNDERLINE);
        mvwprintw(w,y,x+51,"TAX COLLECTED [%d]",year);
        y=y+3;
        mvwprintw(w,y,x+5*t,"%s","ID");
        mvwprintw(w,y,x+10*t,"%s","NAME");
        mvwprintw(w,y,x+17*t,"%s","TAX PAID");
        y+=2;
        wattroff(w,A_BOLD);
        wattroff(w,A_UNDERLINE);
        while(!feof(f))
        {
            if(E.year==year)
            {
                sal=GrossSal(E.ID,E.year,a);
                while(E.year==year)
                {
                    if(Search(head,E.ID,E.year)!=1)
                    {
                        head=Insert(head,E.ID,E.year);
                        tax=TaxCal(sal,E.ID,E.year,a);
                        mvwprintw(w,y,x+4*t,"%s",E.ID);
                        mvwprintw(w,y,x+8*t,"%s %s",E.name.init,E.name.surname);
                        mvwprintw(w,y,x+17*t,"%.2f",tax);
                        y++;
                        total=total+tax;
                        break;
                    }
                    fread(&E,sizeof(employee),1,f);
                }
            }
            fread(&E,sizeof(employee),1,f);
        }
        y=y+3;
        wattron(w,A_BOLD);
        wattron(w,A_UNDERLINE);
        mvwprintw(w,y,x+4*t,"TOTAL TAX COLLECTED : %.2f",total);
        wattroff(w,A_BOLD);
        wattroff(w,A_UNDERLINE);
    }
    fclose(f);
}



////////////////////////////////////////////Creates the Menu By Abhay Dhiman///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Menu(WINDOW *w,int y,int x, char list[13][40],int n,int ch,int c)
{
    wattron(w,COLOR_PAIR(c));
    wattron(w,A_BOLD);
    int i=0;
    char *item=malloc(40*n);
    for( i=0; i<n; i++ )
    {
        if( i == 0 )
            wattron( w, A_STANDOUT ); // highlights the first item.
        else
            wattroff( w, A_STANDOUT ); // highlights the first item.
        sprintf(item, "%s",  list[i]);
        mvwprintw( w, y+i,x, "%s", item );
    }
    wrefresh( w ); // update the terminal screen
    i = 0;
    noecho(); // disable echoing of characters on the screen
    keypad( w, TRUE ); // enable keyboard input for the window.
    curs_set( 0 ); // hide the default screen cursor.
    // get the input
    while(( ch = wgetch(w)) != 'q')
    {
        // right pad with spaces to make the items appear with even width.
        sprintf(item, "%s",  list[i]);
        mvwprintw( w, i+y, x, "%s", item );
        // use a variable to increment or decrement the value based on the input.
        switch( ch ) 
        {
            case KEY_UP:
                i--;
                i = ( i<0 ) ? n-1 : i;
                break;
            case KEY_DOWN:
                i++;
                i = ( i>n-1 ) ? 0 : i;
                break;
            case 10:
                getyx(w,y,x);
                wattroff(w,COLOR_PAIR(c));
                wattroff(w,A_BOLD);
                return y;           //Return the y-coordinate.
                break;
        }
        // now highlight the next item in the list.
        wattron( w, A_STANDOUT);
        sprintf(item, "%s",  list[i]);
        mvwprintw( w, i+y, x, "%s", item);
        wattroff( w, A_STANDOUT);

    }
}
//////////////////////////////////////// Creates the MEnu for month for showing the details of usser( By Abhay )///////////////////////////////////////////////////////////////////////////////
int MenuMonth(WINDOW *w,int y,int x, char list[13][40],int n,int ch,int c,int a)
{
    wattron(w,COLOR_PAIR(c));
    wattron(w,A_BOLD);
    int i=a;
    char *item=malloc(40*n);
    for( i=0; i<n; i++ )
    {
        if( i == a )
            wattron( w, A_STANDOUT ); // highlights the first item.
        else
            wattroff( w, A_STANDOUT ); // highlights the first item.
        sprintf(item, "%s",  list[i]);
        mvwprintw( w, y+i,x, "%s", item );
    }
    wrefresh( w ); // update the terminal screen
    i = a;
    noecho(); // disable echoing of characters on the screen
    keypad( w, TRUE ); // enable keyboard input for the window.
    curs_set( 0 ); // hide the default screen cursor.
    // get the input
    while(( ch = wgetch(w)) != 'q')
    {
        // right pad with spaces to make the items appear with even width.
        sprintf(item, "%s",  list[i]);
        mvwprintw( w, i+y, x, "%s", item );
        // use a variable to increment or decrement the value based on the input.
        switch( ch )
        {
            case KEY_UP:
                i--;
                i = ( i<0 ) ? n-1 : i;
                wattroff(w,COLOR_PAIR(c));
                wattroff(w,A_BOLD);
                return i;		 //Returning the Index of the Array.
                break;
            case KEY_DOWN:
                i++;
                i = ( i>n-1 ) ? 0 : i;
                wattroff(w,COLOR_PAIR(c));
                wattroff(w,A_BOLD);
                return i;                  //Returning the Index of the Array.
                break;
            case 10:
                if(i==12)
                {
                    getyx(w,y,x);
                    wattroff(w,COLOR_PAIR(c));
                    wattroff(w,A_BOLD);
                    return y;                  //Returning y-Coordinate
                }
                break;
        }
        // now highlight the next item in the list.
        wattron( w, A_STANDOUT);
        sprintf(item, "%s",  list[i]);
        mvwprintw( w, i+y, x, "%s", item);
        wattroff( w, A_STANDOUT);

    }
}
///////////////////////////////////////This function takes date as a string converts into Date, Month and Year as integer.(By Arun)////////////////////////////////////////////////////////////
int  DateChangeCheck(char *str)
{
    int power=1,no,sum=0;
    int d,m,y;
    for(int i=0;i<2;i++)
    {
        no=str[i]-'0';
        sum=sum+no*pow(10,power);
        power--;
    }
    d=sum;
    power=1;
    sum=0;
    for(int i=3;i<5;i++)
    {
        no=str[i]-'0';
        sum=sum+no*pow(10,power);
        power--;
    }
    m=sum;
    power=3;
    sum=0;
    for(int i=6;i<=9;i++)
    {
        no=str[i]-'0';
        sum=sum+no*pow(10,power);
        power--;
    }
    y=sum;
    if(ValidityDate(d,m,y)==1)
        return(1);
    else
        return(-1);
}
////////////////////////////////////////////////////////This function checks whether the given year is leap year or not.(By Arun) /////////////////////////////////////////////////////////////
int CheckLeapYear(int year)
{
    if(year%4==0)
    {
        if(year%100==0)
        {
            if(year%400==0)
                return 1;
            else
                return 0;
        }
        else 
            return 1;
    }
    else
        return 0;

}

/////////////////////////////////////////////This function checks whether the given date exist or not.(By Arun)////////////////////////////////////////////////////////////////////////////////
int ValidityDate(int date,int month,int year)
{
    if(date<1||month>12||month<1||year<1)
        return -1;
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        if(date>31)
            return -1;
    }
    if(month==4||month==6||month==9||month==11)
    {
        if(date>30)
            return -1;
    }
    if(month==2&&CheckLeapYear(year)==1)
    {
        if(date>29)
            return -1;
    }
    if(month==2&&CheckLeapYear(year)==0)
    {
        if(date>28)
            return -1;
    }
    return 1;
}

//////////////////////// This function display the personal details of the given Employee and various expenses in different fields. (By Abhay)/////////////////////////////////////////////////
void DislayId(WINDOW *w,employee E,char *a)
{
    FILE *p;
    WINDOW *w1;
    char ID[7];
    int y=2,x=2,t=4,s=2,cmp,cmp1,year,l,m,b;
    float income,tax;
    p=fopen(a,"rb");
    if(p==NULL)
    {
        mvwprintw(w,1,5,"%s","Not able to Open");
        sleep(3);
        exit(-1);
    }
    echo();
    wattron(w,A_BOLD);
    wattron(w,A_UNDERLINE);
    mvwprintw(w,y,60,"%s","ID :");
    wgetstr(w,ID);
    wattroff(w,A_BOLD);
    wattroff(w,A_UNDERLINE);
    wrefresh(w);
    fseek(p,0,0);
    fread(&E,sizeof(employee),1,p);
    while(!feof(p))
    {
        cmp=strcmp(E.ID,ID);
        if(cmp==0)
        {
            wattron(w,A_STANDOUT);
            mvwprintw(w,y+s,x,"%s","PERSONAL DETAILS :");
            wattroff(w,A_STANDOUT);
            mvwprintw(w,y+2*s,x,"ID : ");
            mvwprintw(w,y+2*s,x+t+2,"%s",E.ID);
            mvwprintw(w,y+2*s,x+8*t,"%s","Name:");
            mvwprintw(w,y+2*s,x+9*t+3,"%s",E.name.init);
            getyx(w,m,b);
            mvwprintw(w,y+2*s,b+1,"%s",E.name.surname);
            mvwprintw(w,y+3*s,x,"%s","Age:");
            mvwprintw(w,y+3*s,x+t+1,"%d",E.age);
            mvwprintw(w,y+3*s,x+5*t,"%s","Gender(M/F/O):");
            mvwprintw(w,y+3*s,x+8*t+2,"%s",E.gender);
            wattron(w,A_STANDOUT);
            mvwprintw(w,y+4*s,x,"%s","INCOME & EXPENDITURE DETAILS :");
            wattroff(w,A_STANDOUT);
            wattron(w,A_BOLD);
            wattron(w,A_UNDERLINE);
            mvwprintw(w,y+5*s,60,"%s","YEAR :");
            wscanw(w,"%d",&year);
            wattroff(w,A_UNDERLINE);
            wattroff(w,A_BOLD);
            if(E.year==year)
            {

income:		for(int b=1;b<=125;b++)
                mvwprintw(w,y+5*s,b,"%s"," ");
            wattron(w,A_UNDERLINE);
            mvwprintw(w,y+5*s,x,"%s","INCOME :");
            wattroff(w,A_UNDERLINE);
            mvwprintw(w,y+6*s,x,"%s","Year of Income :");
            mvwprintw(w,y+6*s,x+4*t,"%d",E.year);
            income=GrossSal(ID,year,a);
            tax=TaxCal(income,ID,year,a);
            mvwprintw(w,y+6*s,x+10*t,"TAX to be paid(approx.) : %.2f",tax);
            wrefresh(w);
            m=1;
nextmonth:		w1=newwin(40,15,0,130);
                wattron(w1,COLOR_PAIR(2));
                wattron(w1,A_REVERSE);
                wborder(w1,' ',' ',' ',' ',' ',' ',' ',' ');
                wattroff(w1,A_REVERSE);
                wattroff(w1,COLOR_PAIR(2));
                wattron(w1,A_STANDOUT);
                wattron(w1,COLOR_PAIR(2));
                wattron(w1,A_BOLD);
                mvwprintw(w1,1,3,"%s"," MONTH ");
                wattroff(w1,A_STANDOUT);
                wattroff(w1,COLOR_PAIR(2));
                wattroff(w1,A_BOLD);
                char list[13][40]={"JANUARY","FEBURARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER","EXIT"};
                m=MenuMonth(w1,4,3,list,13,b,1,m-1);
                m=m+1;
                mvwprintw(w1,20,1,"%s","          ");
                mvwprintw(w1,20,3,"%d",m);
                if(m==17)
                    goto Exit;
                if(m==13)
                {
                    for(int k=y+8*s-3;k<=y+18*s;k++)
                        for(int h=1;h<=120;h++)
                            mvwprintw(w,k,h,"%s"," ");
                    wattron(w,A_BOLD);
                    wattron(w,COLOR_PAIR(4));
                    mvwprintw(w,y+9*s,x+10*t,"%s","PRESS ENTER TO EXIT");
                    wattroff(w,COLOR_PAIR(4));
                    wattroff(w,A_BOLD);
                    wrefresh(w);
                    goto nextmonth;
                }
                if(m==E.exp.month)
                {
income1:        s=2;
                x=2;
                for(int k=y+8*s-3;k<=y+18*s;k++)
                    for(int h=1;h<=120;h++)
                        mvwprintw(w,k,h,"%s"," ");
                mvwprintw(w,y+7*s,x,"%s","Income :");
                mvwprintw(w,y+7*s,x+2*t,"%.2f",E.income);
                wattron(w,A_UNDERLINE);
                mvwprintw(w,y+8*s,x,"%s","BILL DETAILS :");
                wattroff(w,A_UNDERLINE);
                mvwprintw(w,y+9*s,x,"%s","House Rent :");
                mvwprintw(w,y+9*s,x+3*t,"%.2f",E.exp.BD.houserent);
                mvwprintw(w,y+9*s,x+8*t,"%s","Electricity Bill :");
                mvwprintw(w,y+9*s,x+13*t,"%.2f",E.exp.BD.elec_bill);
                mvwprintw(w,y+10*s,x,"%s","GROCERIES :");
                mvwprintw(w,y+10*s,x+3*t,"%.2f",E.exp.BD.groceries);
                mvwprintw(w,y+10*s,x+8*t,"%s","Others :");
                mvwprintw(w,y+10*s,x+10*t,"%.2f",E.exp.BD.others);
                wattron(w,A_UNDERLINE);
                mvwprintw(w,y+11*s,x,"%s","POLICY DETAILS :");
                wattroff(w,A_UNDERLINE);
                mvwprintw(w,y+12*s,x,"%s","Life Insurance :");
                mvwprintw(w,y+12*s,x+4*t,"%.2f",E.exp.PD.lifeins);
                mvwprintw(w,y+12*s,x+8*t,"%s","Medical Insurance :");
                mvwprintw(w,y+12*s,x+13*t,"%.2f",E.exp.PD.medicalins);
                mvwprintw(w,y+13*s,x,"%s","Motor Insurance :");
                mvwprintw(w,y+13*s,x+5*t,"%.2f",E.exp.PD.motorins);
                mvwprintw(w,y+13*s,x+8*t,"%s","Others :");
                mvwprintw(w,y+13*s,x+10*t,"%.2f",E.exp.PD.others);
                }
                else
                {
                    fseek(p,0,0);
                    fread(&E,sizeof(employee),1,p);
                    while(!feof(p))
                    {
                        cmp1=strcmp(E.ID,ID);
                        if(cmp1==0)
                        {
                            if(E.year==year)
                            {
                                if(m==E.exp.month)
                                {
                                    b=1;
                                    goto income1;
                                }
                            }

                        }
                        fread(&E,sizeof(employee),1,p);
                    }
                    getyx(w,s,x);
                    mvwprintw(w,1,1,"%d",s);
                    s=2;
                    x=2;
                    for(int k=y+8*s-3;k<=y+18*s;k++)
                        for(int h=1;h<=120;h++)
                            mvwprintw(w,k,h,"%s"," ");
                    wattron(w,COLOR_PAIR(4));
                    mvwprintw(w,y+10*s,x+10*t,"%s","Details of Particular MONTH Not Found.");
                    wattroff(w,COLOR_PAIR(4));


                }
            }
            else
            {
                fseek(p,0,0);
                fread(&E,sizeof(employee),1,p);
                while(!feof(p))
                {
                    cmp1=strcmp(E.ID,ID);
                    if(cmp1==0)
                    {
                        if(E.year==year)
                            goto income;
                    }
                    fread(&E,sizeof(employee),1,p);
                }
                wattron(w,COLOR_PAIR(4));
                mvwprintw(w,y+8*s,x+10*t,"%s","Details of Particular year Not Found.");
                wattroff(w,COLOR_PAIR(4));
                goto EXIT1;
            }
            wattron(w,A_STANDOUT);
            mvwprintw(w,y+14*s,x,"%s","TRANSACTION DETAILS :");
            wattroff(w,A_STANDOUT);
            l=0;
            wattron(w,A_BOLD);
            mvwprintw(w,y+15*s+l,x+t,"%s","TO");
            mvwprintw(w,y+15*s+l,x+4*t,"%s","Date of Transition(DD/MM/YYYY)");
            mvwprintw(w,y+15*s+l,x+13*t,"%s","Debit");
            wattroff(w,A_BOLD);
            fseek(p,0,0);
            l++;
            fread(&E,sizeof(employee),1,p);
            while(!feof(p))
            {
                cmp1=strcmp(E.ID,ID);
                if(cmp1==0)
                {
                    for(int j=0;j<=4;j++)
                    {
                        if(E.exp.AC.debit[j].amount!=0)
                        {
                            mvwprintw(w,y+15*s+l,x+t,"%s",E.exp.AC.debit[j].receiver_id);
                            mvwprintw(w,y+15*s+l,x+7*t,"%s",E.exp.AC.debit[j].dt);
                            mvwprintw(w,y+15*s+l,x+13*t,"%.2f",E.exp.AC.debit[j].amount);
                            l++;
                        }
                    }
                }

                fread(&E,sizeof(employee),1,p);
            }
            wrefresh(w);
            wclear(w1);
            wrefresh(w);
            delwin(w1);
            goto nextmonth;


            break;
        }
        fread(&E,sizeof(employee),1,p);

    }
    if(cmp!=0)
    {
        wattron(w,COLOR_PAIR(4));
        mvwprintw(w,4,4,"%s","Employee Details not Avaliable.");
        wattroff(w,COLOR_PAIR(4));
        goto EXIT1;
    }

Exit:    wclear(w1);
         wrefresh(w1);
         delwin(w1);
EXIT1:   fclose(p);
}
//////////////////////////////This function reads the details of user from text file and writes it into a binary file. (By Arun)///////////////////////////////////////////////////////////////
void FileEmployeeDetail(char *T,char *B)
{
    WINDOW *w=newwin(100,100,0,0);
    employee E,F;
    FILE *f,*fp;
    char str[30],line[1000];
    int month[12],top=0,pos;
    for(int i=0;i<12;i++)
        month[i]=0;
    for(int i=0;i<10;i++)
        E.exp.AC.debit[i].amount=0;

    f=fopen(T,"r");
    if(f==NULL)
    {
        mvwprintw(w,20,20,"%s""The file does not exist.Please Create a file for Employees Details");
        sleep(3);
        exit(0);
    }
    if(f!=0)
        perror("\n");

    fp=fopen(B,"w+");
    if(fp==NULL)
    {
        mvwprintw(w,20,22,"%s""ERROR IN OPENING");
        sleep(3);
        exit(0);
    }

    for(int i=0;i<=5;i++)
        fgets(line,1000,f);
ID_onward:

    fscanf(f,"%s",E.ID);
    fscanf(f,"%s%s",E.name.init,E.name.surname);
    fscanf(f,"%d",&E.age);
    fscanf(f,"%s",E.gender);
year_onward:
    fscanf(f,"%d",&E.year);
month_onward:
    fscanf(f,"%d",&E.exp.month);
    if(top>=1)
    {
        if(E.exp.month!=F.exp.month || E.year!=F.year || strcmp(E.ID,F.ID)!=0)
        {
            fwrite(&F,sizeof(employee),1,fp);
            for(int i=0;i<10;i++)
                E.exp.AC.debit[i].amount=0;
            top=0;
        }
        if((E.year!=F.year)||strcmp(E.ID,F.ID)!=0)
        {
            for(int i=0;i<12;i++)
                month[i]=0;
            top=0;
        }
        if(month[E.exp.month-1]==1)
        {
            fscanf(f,"%s",E.exp.AC.debit[top].receiver_id);
            fscanf(f,"%f",&E.exp.AC.debit[top].amount);
            fscanf(f,"%s",E.exp.AC.debit[top].dt);
            pos=ftell(f);
            goto string;
        }
    }
    month[E.exp.month-1]=1;
    fscanf(f,"%f",&E.income);
    fscanf(f,"%f",&E.exp.BD.houserent);
    fscanf(f,"%f",&E.exp.BD.elec_bill);
    fscanf(f,"%f",&E.exp.BD.groceries);
    fscanf(f,"%f",&E.exp.BD.others);
    fscanf(f,"%s",E.exp.AC.debit[top].receiver_id);
    fscanf(f,"%f",&E.exp.AC.debit[top].amount);
    fscanf(f,"%s",E.exp.AC.debit[top].dt);
    fscanf(f,"%f",&E.exp.PD.lifeins);
    fscanf(f,"%f",&E.exp.PD.medicalins);
    fscanf(f,"%f",&E.exp.PD.motorins);
    fscanf(f,"%f",&E.exp.PD.others);
    pos=ftell(f); 
string:
    fscanf(f,"%s",str);
    F=E;
    top++;
    if (feof(f))
    {
        fwrite(&F,sizeof(employee),1,fp);
        goto end;
    }


    if(strlen(str)==1||strlen(str)==2)
    {
        fseek(f,pos,0);
        goto month_onward;
    }
    else if(strlen(str)==4)
    {

        fseek(f,pos,0);
        goto year_onward;
    }
    else 
    {
        fseek(f,pos,0);
        goto ID_onward;
    }
end:
    printf(" ");

    fclose(f);
    fclose(fp);
    wclear(w);
    wrefresh(w);
    delwin(w);
    refresh;
}

////////////////////////////////////////////////////////////////////ANALYSIS FUNCTION//////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////This function calculates total expenses of any user in the Bill Section.(By Pintu)//////////////////////////////////////////////////////////////////////////////
void BillDetail(WINDOW *w,char *a )
{
    int i,j,current_year,diff_year=0,max_month,min_month,ch;
    employee E;
    char ID[7];
    int y=2,x=2,t=4,l=0,efound=0,a1,a2;
    char Month[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    float month[12][6],year[20][5],section[5]={0,0,0,0,0},min,max;
    for(i=0;i<20;i++)
        for(j=0;j<5;j++)
            year[i][j]=0;
    for(i=0;i<12;i++)
        for(j=0;j<6;j++)
            month[i][j]=0;
    echo();
    wattron(w,A_BOLD);
    wattron(w,A_UNDERLINE);
    wattron(w,A_STANDOUT);
    mvwprintw(w,y,60,"%s","ID :");
    wgetstr(w,ID);
    wattroff(w,A_BOLD);
    wattroff(w,A_UNDERLINE);
    wattroff(w,A_STANDOUT);
    wrefresh(w);
    noecho();
    y=y+2;
    FILE *f=fopen(a,"rb");
    if(f==NULL)
    {
        mvwprintw(w,y,9*t,"%s","Sorry,couldnot find file.");
        sleep(3);
        exit(-1);
    }
    fread(&E,sizeof(employee),1,f);
    while(!feof(f))
    {
        if(strcmp(E.ID,ID)==0)
        {
            if(efound==0)
            {
                wattron(w,A_BOLD);
                mvwprintw(w,y,x+7*t,"NAME : %s %s      AGE: %d     GENDER : %s",E.name.init,E.name.surname,E.age,E.gender);
                wattroff(w,A_BOLD);
                y=y+2;
                a1=y;
            }
            efound=1;
            while(strcmp(E.ID,ID)==0 && !feof(f))
            {
                for(j=0;j<diff_year;j++)
                    if(year[j][0]==E.year)
                    {
                        current_year=j;
                        break;
                    }
                if(j==diff_year)
                {
                    diff_year++;
                    year[j][0]=E.year;
                    current_year=j;
                }
                month[E.exp.month-1][0]=month[E.exp.month-1][0]+E.exp.BD.houserent;
                month[E.exp.month-1][1]=month[E.exp.month-1][1]+E.exp.BD.elec_bill;
                month[E.exp.month-1][2]=month[E.exp.month-1][2]+E.exp.BD.groceries;
                month[E.exp.month-1][3]=month[E.exp.month-1][3]+E.exp.BD.others;
                month[E.exp.month-1][5]+=1;
                year[current_year][1]=year[current_year][1]+E.exp.BD.houserent;
                year[current_year][2]=year[current_year][2]+E.exp.BD.elec_bill;
                year[current_year][3]=year[current_year][3]+E.exp.BD.groceries;
                year[current_year][4]=year[current_year][4]+E.exp.BD.others;
                section[0]=section[0]+E.exp.BD.houserent;
                section[1]=section[1]+E.exp.BD.elec_bill;
                section[2]=section[2]+E.exp.BD.groceries;
                section[3]=section[3]+E.exp.BD.others;
                section[4]+=1;
                fread(&E,sizeof(employee),1,f);
            }
            if(strcmp(E.ID,ID)!=0)
                break;
        }
        fread(&E,sizeof(employee),1,f);
    }
    min=(float)(INT_MAX),max=-1;
    for(i=0;i<12;i++)
    {
        for(j=0;j<4;j++)
            month[i][4]+=month[i][j];
        month[i][4]/=month[i][5];
        if(month[i][4]>max)
        {
            max=month[i][4];
            max_month=i;
        }
        if(month[i][4]<min)
        {
            min=month[i][4];
            min_month=i;
        }
    }
    a1=y;
    if(efound!=0)
    {
MCE:	wattron(w,A_UNDERLINE);
        wattron(w,A_BOLD);
        mvwprintw(w,y,x+12*t,"%s","MONTHLY CALCULATED EXPENSES");
        y++;
        mvwprintw(w,y,x+4*t,"%s","MONTH");
        mvwprintw(w,y,x+7*t,"%s","HOUSE RENT");
        mvwprintw(w,y,x+11*t,"%s","ELECTRIC BILL");
        mvwprintw(w,y,x+16*t,"%s","GROCERIES");
        mvwprintw(w,y,x+20*t,"%s","OTHERS");
        mvwprintw(w,y,x+23*t,"%s","AVERAGE");
        y++;
        wattroff(w,A_UNDERLINE);
        wattroff(w,A_BOLD);
        for(i=0;i<12;i++)
        {
            j=0;
            l=0;
            if(month[i][0]!=0||month[i][1]!=0||month[i][2]!=0||month[i][3]!=0)
            { 
                mvwprintw(w,y,x+3*t+2,"%s",Month[i]);
                mvwprintw(w,y,x+7*t+1,"%.2f",month[i][0]);
                mvwprintw(w,y,x+12*t,"%.2f",month[i][1]);
                mvwprintw(w,y,x+16*t+1,"%.2f",month[i][2]);
                mvwprintw(w,y,x+20*t,"%.2f",month[i][3]);
                mvwprintw(w,y,x+23*t,"%.2f",month[i][4]);
                y++;
                a2=y;
                if(y>=36&&y<=39)
                {
again1:		mvwprintw(w,38,x+5*t,"%s","Press Enter to Go to Next Page,or 'q' to EXIT.");
            ch=wgetch(w);
            y=a1;
            if(ch=='\n')
            {
                for(int line=a1;line<=a2;line++)
                    for(int space=1;space<=120;space++)
                        mvwprintw(w,line,space,"%s"," ");
                goto MCE;
            }
            else if(ch=='q')
                goto END;
            else
                goto again1;
                } 
            }
        }
        y=y+3;
YCE:	wattron(w,A_UNDERLINE);
        wattron(w,A_BOLD);
        mvwprintw(w,y,x+11*t,"%s","YEARLY CALCULATED EXPENSES");
        y++;
        mvwprintw(w,y,x+4*t,"%s","YEAR");
        mvwprintw(w,y,x+7*t,"%s","HOUSE RENT");
        mvwprintw(w,y,x+11*t,"%s","ELECTRIC BILL");
        mvwprintw(w,y,x+16*t,"%s","GROCERIES");
        mvwprintw(w,y,x+20*t,"%s","OTHERS");
        y++;
        wattroff(w,A_UNDERLINE);
        wattroff(w,A_BOLD);
        for(i=0;year[i][0]!=0;i++)
        {
            mvwprintw(w,y,x+4*t,"%.f",year[i][0]);
            mvwprintw(w,y,x+7*t+1,"%.2f",year[i][1]);
            mvwprintw(w,y,x+12*t,"%.2f",year[i][2]);
            mvwprintw(w,y,x+16*t+1,"%.2f",year[i][3]);
            mvwprintw(w,y,x+20*t,"%.2f",year[i][4]);
            y++;
            a2=y;
            if(y>=36&&y<=39)
            {
again2:         mvwprintw(w,38,x+5*t,"%s","Press Enter to Go to Next Page,or 'q' to EXIT.");
                ch=wgetch(w);
                y=a1;
                if(ch=='\n')
                {
                    for(int line=a1;line<=a2;line++)
                        for(int space=1;space<=120;space++)
                            mvwprintw(w,line,space,"%s"," ");
                    goto YCE;
                }
                else if(ch=='q')
                    goto END;
                else
                    goto again2;
            }
        }
        y=y+3;
SCE:	wattron(w,A_UNDERLINE);
        wattron(w,A_BOLD);
        mvwprintw(w,y,x+10*t,"%s","SECTIONWISE CALCULATED EXPENSES");
        y++;
        mvwprintw(w,y,x+7*t,"%s","HOUSE RENT");
        mvwprintw(w,y,x+11*t,"%s","ELECTRIC BILL");
        mvwprintw(w,y,x+16*t,"%s","GROCERIES");
        mvwprintw(w,y,x+20*t,"%s","OTHERS");
        y++;
        wattroff(w,A_UNDERLINE);
        wattroff(w,A_BOLD);
        mvwprintw(w,y,x+7*t+1,"%.2f",section[0]);
        mvwprintw(w,y,x+11*t+1,"%.2f",section[1]);
        mvwprintw(w,y,x+16*t,"%.2f",section[2]);
        mvwprintw(w,y,x+20*t,"%.2f",section[3]);
        y++;
        wattron(w,A_UNDERLINE);
        mvwprintw(w,y,x+4*t,"%s","AVERAGE");
        mvwprintw(w,y,x+7*t+1,"%.2f",section[0]/section[4]);
        mvwprintw(w,y,x+11*t+1,"%.2f",section[1]/section[4]);
        mvwprintw(w,y,x+16*t,"%.2f",section[2]/section[4]);
        mvwprintw(w,y,x+20*t,"%.2f",section[3]/section[4]);
        wattroff(w,A_UNDERLINE);
        a2=y;
        if(y>=36&&y<=39)
        {
again3:         mvwprintw(w,38,x+5*t,"%s","Press Enter to Go to Next Page,or 'q' to EXIT.");
                ch=wgetch(w);
                y=a1;
                if(ch=='\n')
                {
                    for(int line=a1;line<=a2;line++)
                        for(int space=1;space<=120;space++)
                            mvwprintw(w,line,space,"%s"," ");
                    goto SCE;
                }
                else if(ch=='q')
                    goto END;
                else
                    goto again3;
        }
    }
    wattron(w,A_BOLD);
    y+=3;
    a2=y;
    if(y>=32&&y<=39)
    {
again4:         mvwprintw(w,38,x+5*t,"%s","Press Enter to Go to Next Page,or 'q' to EXIT.");
                ch=wgetch(w);
                y=a1;
                if(ch=='\n')
                {
                    for(int line=a1;line<=a2;line++)
                        for(int space=1;space<=120;space++)
                            mvwprintw(w,line,space,"%s"," ");
                }
                else if(ch=='q')
                    goto END;
                else
                    goto again4;
    }
    wattron(w,A_UNDERLINE);
    y++;
    mvwprintw(w,y,x+12*t,"%s","MAXIMUM EXPENSE");
    y++;
    mvwprintw(w,y,x+10*t,"%s",Month[max_month]);
    mvwprintw(w,y,x+14*t,"%.2f",max);
    y+=2;
    mvwprintw(w,y,x+12*t,"%s","MINIMUM EXPENSE");
    y++;
    mvwprintw(w,y,x+10*t,"%s",Month[min_month]);
    mvwprintw(w,y,x+14*t,"%.2f",min);
    wattroff(w,A_UNDERLINE);
    wattroff(w,A_BOLD);
END: if(efound==0)
     {
         wattron(w,COLOR_PAIR(4));
         mvwprintw(w,6,40,"%s","Emloyee Details Not Avaliable.");
         wattroff(w,COLOR_PAIR(4));
     }
}


/////////////////////////////////////////This function calculates total expenses of any user in the Policy Section.(By Pintu)///////////////////////////////////////////////////////////////////
void PolicyDetail(WINDOW *w,char *a)
{
    float year[20][6],sum;
    int i,j,diff_year=0,current_year;
    int x=2,y=2,t=4,efound=0,a1,a2,ch;
    employee E;
    char ID[7];
    FILE *f=fopen(a,"rb");
    if(f==NULL)
    {
        mvwprintw(w,y,9*t,"%s","Sorry,couldnot find file.");
        sleep(3);
        exit(-1);
    }
    for(i=0;i<20;i++)
        for(j=0;j<6;j++)
            year[i][j]=0;
    echo();
    wattron(w,A_BOLD);
    wattron(w,A_UNDERLINE);
    wattron(w,A_STANDOUT);
    mvwprintw(w,y,60,"%s","ID :");
    wgetstr(w,ID);
    wattroff(w,A_BOLD);
    wattroff(w,A_UNDERLINE);
    wattroff(w,A_STANDOUT);
    wrefresh(w);
    noecho();
    y=y+2;
    fread(&E,sizeof(employee),1,f);
    while(!feof(f))
    {
        if(strcmp(E.ID,ID)==0)
        {
            if(efound==0)
            {
                wattron(w,A_BOLD);
                mvwprintw(w,y,x+7*t,"NAME : %s %s      AGE: %d      GENDER : %s",E.name.init,E.name.surname,E.age,E.gender);
                wattroff(w,A_BOLD);
                y=y+2;
            }
            efound=1;

            while(strcmp(E.ID,ID)==0 && !feof(f))
            {
                for(j=0;j<diff_year;j++)
                    if(year[j][0]==E.year)
                    {
                        current_year=j;
                        break;
                    }
                if(j==diff_year)
                {
                    diff_year++;
                    year[j][0]=E.year;
                    current_year=j;
                }
                year[current_year][1]+=E.exp.PD.lifeins;
                year[current_year][2]+=E.exp.PD.medicalins;
                year[current_year][3]+=E.exp.PD.motorins;
                year[current_year][4]+=E.exp.PD.others;
                year[current_year][5]+=1;
                fread(&E,sizeof(employee),1,f);
            }
        }
        fread(&E,sizeof(employee),1,f);
    }
    wattron(w,A_UNDERLINE);
    wattron(w,A_BOLD);
    mvwprintw(w,y,x+12*t,"%s","POLICIES");
    y++;
    mvwprintw(w,y,x+4*t,"%s","YEAR");
    mvwprintw(w,y,x+7*t,"%s","LIFE INS.");
    mvwprintw(w,y,x+11*t,"%s","MEDICAL INS.");
    mvwprintw(w,y,x+16*t,"%s","MOTOR INS.");
    mvwprintw(w,y,x+20*t,"%s","OTHERS");
    mvwprintw(w,y,x+23*t,"%s","AVERAGE");
    y++;
    a1=y;
    wattroff(w,A_UNDERLINE);
    wattroff(w,A_BOLD);
PD:    for(i=0;year[i][0]!=0;i++)
       {
           sum=0;
           for(j=1;j<5;j++)
               sum+=year[i][j];
           mvwprintw(w,y,x+4*t,"%.0f",year[i][0]);
           mvwprintw(w,y,x+7*t+1,"%.2f",year[i][1]);
           mvwprintw(w,y,x+12*t,"%.2f",year[i][2]);
           mvwprintw(w,y,x+16*t+1,"%.2f",year[i][3]);
           mvwprintw(w,y,x+20*t,"%.2f",year[i][4]);
           mvwprintw(w,y,x+23*t,"%.2f",sum/year[i][5]);
           y++;
           a2=y;
           if(y>=36&&y<=39)
           {
again1:         mvwprintw(w,38,x+5*t,"%s","Press Enter to Go to Next Page,or 'q' to EXIT.");
                ch=wgetch(w);
                y=a1;
                if(ch=='\n')
                {
                    for(int line=a1;line<=a2;line++)
                        for(int space=1;space<=120;space++)
                            mvwprintw(w,line,space,"%s"," ");
                    goto PD; 
                }
                else if(ch=='q')
                    break;
                else
                    goto again1;
           }
       }
}



//////////////////////////////////////////////////////////////////////////TRANSFER DAETAILS////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////Creates the node of transaction type and assigns the corresponding values.(By Pintu)/////////////////////////////////////////////////////////////////////////

void CreateNode(employee E,int i,Transaction **sender,Transaction **receiver)
{
    *sender=malloc(sizeof(Transaction));
    *receiver=malloc(sizeof(Transaction));
    strcpy((*sender)->ID,E.ID);
    strcpy((*sender)->name.init,E.name.init);
    strcpy((*sender)->name.surname,E.name.surname);
    (*sender)->amount=E.exp.AC.debit[i].amount;
    strcpy((*sender)->dt,E.exp.AC.debit[i].dt);
    strcpy((*receiver)->ID,E.exp.AC.debit[i].receiver_id);
    strcpy((*receiver)->dt,E.exp.AC.debit[i].dt);
    (*receiver)->amount=E.exp.AC.debit[i].amount;
    (*sender)->left=NULL;
    (*sender)->right=NULL;
    (*receiver)->left=NULL;
    (*receiver)->right=NULL;
}
//////////////////////////////////////////////////// Creates the tree of all transactions.(By Pintu)///////////////////////////////////////////////////////////////////////////////////////////

Transaction* TransferDetailTree(Transaction *root,Transaction *E1,Transaction *E2)
{
    Transaction *traverse=root;
    int flag=0;
    if(root==NULL)
    {
        root=E1;
        traverse=root;
    }
    else
    {
        while(traverse!=NULL)
        {
            if(strcmp(traverse->ID,E1->ID)==0)
            {
                traverse->amount=traverse->amount+E2->amount;
                if(traverse->left!=NULL)
                {
                    traverse=traverse->left;
                }
                break;
            }
            else
                if((traverse->right==NULL)&&(strcmp(traverse->ID,E1->ID)!=0))
                {
                    flag=1;
                    break;
                }
                else
                    traverse=traverse->right;
        }
        if(flag==1)
        {
            traverse->right=E1;
            traverse=traverse->right;
        }
    }
    if(traverse->left==NULL)
    {
        traverse->left=E2;
        E2->left=traverse;
    }
    else
    {
        while(traverse->right!=NULL)
            traverse=traverse->right;
        traverse->right=E2;
        E2->left=traverse;
    }
    return root;
}
//////////////////////////////////////////////Displays the Details of the nodes having detail of debit.(By Pintu)///////////////////////////////////////////////////////////////////////////////
int DisplayTransferDetail_DEBIT(WINDOW *w,Transaction *S_root,char ID[10],int y)
{
    Transaction *traverse=S_root;
    int flag=0;
    float sum=0;
    int x=2,t=4,a,b,ch;
    y+=2;
    if(S_root==NULL)
    {
        wattron(w,COLOR_PAIR(4));
        mvwprintw(w,y,x+10*t,"%s","You have not sent money to anyone....");
        wattroff(w,COLOR_PAIR(4));
        flag=2;
    }
    else
    {
        while(traverse!=NULL)
        {
            if(strcmp(traverse->ID,ID)==0 && traverse->left!=NULL)
            {
                sum=traverse->amount;
                wattron(w,A_BOLD);
                wattron(w,A_UNDERLINE);
                mvwprintw(w,y++,x+13*t,"%s","SENDERS DETAILS");
                mvwprintw(w,y,x+10*t,"ID : %s",traverse->ID);
                mvwprintw(w,y,x+17*t,"NAME : %s %s",traverse->name.init,traverse->name.surname);
                y=y+2;
                mvwprintw(w,y,x+13*t,"%s","RECEIVERS DETAILS");
                y++;
                mvwprintw(w,y,x+5*t,"%s","ID");
                mvwprintw(w,y,x+11*t,"%s","NAME");
                mvwprintw(w,y,x+17*t,"%s","DATE");
                mvwprintw(w,y,x+22*t,"%s","AMOUNT");
                wattroff(w,A_BOLD);
                wattroff(w,A_UNDERLINE);
                y++;
                a=y;
                traverse=traverse->left;
                flag=1;
                break;
            }
            traverse=traverse->right;
        }
        if(flag==0)
        {
            wattron(w,COLOR_PAIR(4));
            mvwprintw(w,y,x+10*t,"%s","sorry,u hvnot sent money to any one");
            wattroff(w,COLOR_PAIR(4));
        }
        while(traverse!=NULL)
        {
            if(y==37)
            {
                mvwprintw(w,38,x+5*t,"%s","Press Enter to Go to Next Page");
                wscanw(w,"%d",ch);
                if(ch==10)
                {
                    for(int line=a;line<=69;line++)
                        for(int space=1;space<=129;space++)
                            mvwprintw(w,line,space,"%s"," ");
                }
                y=a;

            }
            mvwprintw(w,y,x+4*t,"%s",traverse->ID);
            mvwprintw(w,y,x+9*t,"%s %s",traverse->name.init,traverse->name.surname);
            mvwprintw(w,y,x+16*t+2,"%s",traverse->dt);
            mvwprintw(w,y,x+22*t,"%.2f",traverse->amount);
            y=y+1;
            traverse=traverse->right;
            b=y;
            if(y>=36&&y<=39)
            {
again:                mvwprintw(w,38,x+5*t,"%s","Press Enter to Go to Next Page ,or 'q'");
                      ch=wgetch(w);
                      y=a;
                      if(ch=='\n')
                      {
                          for(int line=a;line<=b;line++)
                              for(int space=1;space<=120;space++)
                                  mvwprintw(w,line,space,"%s"," ");
                      }
                      else if(ch=='q')
                          return(-1);
                      goto again;
            }

        }
        y=y+2;
        wattron(w,A_BOLD);
        mvwprintw(w,y,x+7*t,"You have sent Rs. %.2f amount.",sum);
again1:       wattron(w,COLOR_PAIR(4));
              mvwprintw(w,38,x+5*t,"%s","Press 'q' to go back");
              wattroff(w,COLOR_PAIR(4));
              ch=wgetch(w);
              if(ch=='q')
                  return(-1);
              {
                  wattron(w,COLOR_PAIR(4));
                  mvwprintw(w,38,4,"%s","Inappropriate Input");
                  wattroff(w,COLOR_PAIR(4));
                  goto again1;
              }
              wattroff(w,A_BOLD);
              return(0);
    }
}

//////////////////////////////////////////////////Displays the Details of the nodes having detail of credit.(By Pintu)/////////////////////////////////////////////////////////////////////////
int DisplayTransferDetail_CREDIT(WINDOW *w,Transaction *R_root,char ID[10],int y)
{
    Transaction *traverse=R_root;
    int flag=0;
    float sum=0;
    int ch;
    int x=2,t=4,a,b;
    y+=2;
    if(R_root==NULL)
    {
        wattron(w,COLOR_PAIR(4));
        mvwprintw(w,y,x+10*t,"%s","You have not received any money");
        wattroff(w,COLOR_PAIR(4));
    }
    else
    { 
        while(traverse!=NULL)
        {     
            if(strcmp(traverse->ID,ID)==0 && traverse->left!=NULL)
            {
                sum=traverse->amount;
                wattron(w,A_BOLD);
                wattron(w,A_UNDERLINE);
                mvwprintw(w,y++,x+13*t,"%s","RECEIVERS DETAILS");
                mvwprintw(w,y,x+10*t,"ID : %s",traverse->ID);
                mvwprintw(w,y,x+17*t,"NAME : %s %s",traverse->name.init,traverse->name.surname);
                y=y+2;
                mvwprintw(w,y,x+13*t,"%s","SENDERS DETAILS");
                y++;
                mvwprintw(w,y,x+5*t,"%s","ID");
                mvwprintw(w,y,x+11*t,"%s","NAME");
                mvwprintw(w,y,x+17*t,"%s","DATE");
                mvwprintw(w,y,x+22*t,"%s","AMOUNT");
                wattroff(w,A_BOLD);
                wattroff(w,A_UNDERLINE);
                y++;
                a=y;
                traverse=traverse->left;
                flag=1;
                break;
            }

            traverse=traverse->right;
        }
        if(flag==0)
        {
            wattron(w,COLOR_PAIR(4));
            mvwprintw(w,y,x+10*t,"%s","You have not received any money");
            wattroff(w,COLOR_PAIR(4));
        }
        while(traverse!=NULL)
        {
            mvwprintw(w,y,x+4*t,"%s",traverse->ID);
            mvwprintw(w,y,x+9*t,"%s %s",traverse->name.init,traverse->name.surname);
            mvwprintw(w,y,x+16*t+2,"%s",traverse->dt);
            mvwprintw(w,y,x+22*t,"%.2f",traverse->amount);
            y++;
            traverse=traverse->right;
            b=y;
            if(y>=36&&y<=39)
            {
again:                mvwprintw(w,38,x+5*t,"%s","Press Enter to Go to Next Page");
                      wscanw(w,"%c",&ch);
                      y=10;
                      if(ch=='\n')
                      {
                          for(int line=a;line<=b;line++)
                              for(int space=1;space<=120;space++)
                                  mvwprintw(w,line,space,"%s"," ");
                      }
                      else if(ch=='q')
                          return(-1);
                      else
                      {
                          mvwprintw(w,38,4,"%s","NOT TAKING");
                          goto again;
                      }
            }

        }
        y+=3;

        if(flag==1)
        {

            wattron(w,A_BOLD);
            mvwprintw(w,y,x+6*t,"You have received Rs. %.2f.",sum);
            wattroff(w,A_BOLD);
            for(int space=2;space<=127;space++)
                mvwprintw(w,38,space,"%s"," ");
again1:	    mvwprintw(w,38,x+5*t,"%s","Press 'q' to Go BACK");
            ch=wgetch(w);
            y=10;
            if(ch=='\n')
            {
                for(int line=a;line<=b;line++)
                    for(int space=1;space<=120;space++)
                        mvwprintw(w,line,space,"%s"," ");
            }
            if(ch=='q')
                return(-1);
            else
            {
                mvwprintw(w,37,4,"%s","NOT TAKING");
                goto again1;
            }
            return(0);
        }
    }

}
///////////////////////////////////////////Create the Window for Transfer Details(By Abhay )//////////////////////////////////////////////////////////////////////////////////////////////////
void TransferDetail(WINDOW *w,char *a)
{
    Transaction *sender_root=NULL,*receiver_root=NULL,*sender,*receiver;
    employee E;
    int x=2,y=2,t=4,i,ch,m,sw;
    char list[13][40]={"DEBIT","CREDIT","EXIT"};
    FILE *f=fopen(a,"rb");
    if(f==NULL)
    {
        mvwprintw(w,1,5,"%s","Not able to Open");
        sleep(3);
        exit(-1);
    }
    char ID[7];
    WINDOW *w1;
starting:   y=2;
            w1=newwin(5,13,0,0);
            wattron(w1,COLOR_PAIR(2));
            wattron(w1,A_REVERSE);
            wborder(w1,' ',' ',' ',' ',' ',' ',' ',' ');
            wattroff(w1,A_REVERSE);
            wattroff(w1,COLOR_PAIR(2));
            sw=Menu(w1,1,1,list,3,ch,2);
            if(sw==3)
                goto Exit;
            echo();
            wattron(w,A_BOLD);
            wattron(w,A_STANDOUT);
            mvwprintw(w,y++,15*t,"%s","ID:");
            wattroff(w,A_BOLD);
            wattroff(w,A_STANDOUT);
            wgetstr(w,ID);
            mvwprintw(w,y++,2,"%d",sw);
            fread(&E,sizeof(employee),1,f);
            while(!feof(f))
            {
                for(i=0;E.exp.AC.debit[i].amount!=0;i++)      
                {
                    CreateNode(E,i,&sender,&receiver);
                    sender_root=TransferDetailTree(sender_root,sender,receiver);
                }
                fread(&E,sizeof(employee),1,f);
            }
            fseek(f,0,0);
            fread(&E,sizeof(employee),1,f);
            while(!feof(f))
            { 
                for(i=0;E.exp.AC.debit[i].amount!=0;i++)
                {     
                    CreateNode(E,i,&sender,&receiver);
                    receiver_root=TransferDetailTree(receiver_root,receiver,sender);
                }
                fread(&E,sizeof(employee),1,f);
            }
            sender_root=FillName(w,a,sender_root,0,ID,1,y);
            receiver_root=FillName(w,a,receiver_root,1,ID,1,y);
            switch(sw)
            {
                case 1:
                    m=DisplayTransferDetail_DEBIT(w,sender_root,ID,y);
                    if(m==-1)
                    {
                        wclear(w1);
                        wrefresh(w1);
                        delwin(w1);
                        for(int line=2;line<=38;line++)
                            for(int space=2;space<=127;space++)
                                mvwprintw(w,line,space,"%s"," ");
                        wrefresh(w);
                        m=0;
                        goto starting;
                    }
                    break;
                case 2:
                    m=DisplayTransferDetail_CREDIT(w,receiver_root,ID,y);
                    if(m==-1) 
                    {
                        wclear(w1);
                        wrefresh(w1);
                        delwin(w1);
                        for(int line=2;line<=38;line++)
                            for(int space=2;space<=127;space++)
                                mvwprintw(w,line,space,"%s"," ");
                        wrefresh(w);
                        m=0;
                        goto starting;
                    }
                    break;
                case 3:
                    goto Exit;
            }
Exit:    wclear(w1);
         wrefresh(w1);
         delwin(w1);
         free(sender_root);
         free(receiver_root);
         fclose(f);
}


////////////////////////////////////////////////////////////////////Creates the Window for all Transefer details (By Abhay Dhiman)/////////////////////////////////////////////////////////////
void TransferDetail_all(WINDOW *w,char *a)
{
    Transaction *sender_root=NULL,*receiver_root=NULL,*sender,*receiver;
    employee E;
    int x=2,y=2,t=4,i,m,ch,sw;
    FILE *f=fopen(a,"rb");			//Opens the Binary File.
    if(f==NULL)                                 //Cheaks if Opened properly.
    {
        mvwprintw(w,1,5,"%s","Not able to Open");
        sleep(3);
        exit(-1);
    }
    char list[13][40]={"DEBIT","CREDIT","EXIT"};
    WINDOW *w1;
    wattron(w,A_BOLD);                                 
    wattron(w,A_STANDOUT);                     //Highlites the String Printed
    mvwprintw(w,y,x+12*t,"%s","*** TRANSACTION DETAILS ***");
    wattroff(w,A_BOLD);
    wattroff(w,A_STANDOUT);
    y+=2;
    fread(&E,sizeof(employee),1,f);  	//Reades form the File into a structure E.
    while(!feof(f))                     //Loop to Create a tree with its Nodes as the Transaction Details.
    {
        for(i=0;E.exp.AC.debit[i].amount!=0;i++)     //Loop to add nodes for the particular detail read before.
        {   
            CreateNode(E,i,&sender,&receiver);         //Creates a Node.
            sender_root=TransferDetailTree(sender_root,sender,receiver);   //Build's up the tree for Senders.
        }
        fread(&E,sizeof(employee),1,f);         //Reading the Next data
    }
    fseek(f,0,0);                               //Going back to the Starting of the File.
    fread(&E,sizeof(employee),1,f);             //Reades form the File into a structure E.
    while(!feof(f))                //Loop to Create a tree with its Nodes as the Transaction Details.
    {
        for(i=0;E.exp.AC.debit[i].amount!=0;i++)	//Loop to add nodes for the particular detail read before.
        {
            CreateNode(E,i,&sender,&receiver);		//Creates a Node.
            receiver_root=TransferDetailTree(receiver_root,receiver,sender);	 //Build's up the tree for Senders.
        }
        fread(&E,sizeof(employee),1,f);                 //Reading the Next data
    }
    sender_root=FillName(w,a,sender_root,0," ",2,y);        //Filling Up tehe details of the Particular ID whose Details are Not found in the Tree.
    receiver_root=FillName(w,a,receiver_root,1," ",2,y);	//Filling Up tehe details of the Particular ID whose Details are Not found in the Tree.
starting:   y=2;
            w1=newwin(5,13,0,0);	//Creating a New Window.
            wattron(w1,COLOR_PAIR(2));  //Setting a Color Attribute.
            wattron(w1,A_REVERSE);
            wborder(w1,' ',' ',' ',' ',' ',' ',' ',' ');  //Defining a Border for the Window.
            wattroff(w1,A_REVERSE);
            wattroff(w1,COLOR_PAIR(2));
            sw=Menu(w1,1,1,list,3,ch,2);    //Printing the Menu.
            if(sw==3)                       //Coordinate for Exit Statement in the Menu.
                goto Exit;
            switch(sw)                      //Switch Statement for Debit or Credit.
            {
                case 1:
                    m=DisplayAllTransfer_DEBIT(w,sender_root,y);   //Display All the Debit Details.
                    if(m==-1)    //Return value for the Function & then go back to the Menu Again.
                    {
                        wclear(w1);
                        wrefresh(w1);
                        delwin(w1);
                        for(int line=2;line<=38;line++)
                            for(int space=2;space<=127;space++)
                                mvwprintw(w,line,space,"%s"," ");
                        wrefresh(w);
                        m=0;
                        goto starting;
                    }

                    break;
                case 2:
                    m=DisplayAllTransfer_CREDIT(w,receiver_root,y);   //Display All the Debit Details.
                    if(m==-1)		//Return value for the Function & then go back to the Menu Again.
                    {
                        wclear(w1);
                        wrefresh(w1);
                        delwin(w1);
                        for(int line=2;line<=38;line++)
                            for(int space=2;space<=127;space++)
                                mvwprintw(w,line,space,"%s"," ");
                        wrefresh(w);
                        m=0;
                        goto starting;
                    }
                    break;
                case 3:
                    goto Exit;
            }
Exit:    wclear(w1);
         wrefresh(w1);               //Deleting the Window.
         delwin(w1);
         free(sender_root);          //Freeing the Allocated Space for trh Pointer.
         free(receiver_root);		//Freeing the Allocated Space for trh Pointer.
         fclose(f); 		    //Closing the file.
}




///////////////////////////////////////////Keeps the nodes with resultant debit and credit of given ID.(By Pintu)//////////////////////////////////////////////////////////////////////////////
void TransferDetails_clear(WINDOW *w,char *a)
{
    Transaction *sender_root=NULL,*receiver_root=NULL,*sender,*receiver;
    employee E;
    char list[13][40]={"DEBIT","CREDIT","EXIT"};
    int x=2,y=2,t=4,i,ch,m,sw;
    FILE *f=fopen(a,"rb");
    if(f==NULL)
    {
        mvwprintw(w,1,5,"%s","Not able to Open");
        sleep(3);
        exit(-1);
    }
    char ID[7];
    WINDOW *w1;
starting:    w1=newwin(5,13,0,0);
             wattron(w1,COLOR_PAIR(2));
             wattron(w1,A_REVERSE);
             wborder(w1,' ',' ',' ',' ',' ',' ',' ',' ');
             wattroff(w1,A_REVERSE);
             wattroff(w1,COLOR_PAIR(2));
             sw=Menu(w1,1,1,list,3,ch,2);
             if(sw==3)
                 goto Exit;
             echo();
             wattron(w,A_BOLD);
             wattron(w,A_STANDOUT);
             mvwprintw(w,y++,15*t,"%s","ID:");
             wattroff(w,A_BOLD);
             wattroff(w,A_STANDOUT);
             wgetstr(w,ID);
             noecho();
             fread(&E,sizeof(employee),1,f);
             while(!feof(f))
             {
                 for(i=0;E.exp.AC.debit[i].amount!=0;i++)      
                 {
                     CreateNode(E,i,&sender,&receiver);
                     sender_root=TransferDetailTree(sender_root,sender,receiver);
                 }
                 fread(&E,sizeof(employee),1,f);
             }
             fseek(f,0,0);
             fread(&E,sizeof(employee),1,f);
             while(!feof(f))
             { 
                 for(i=0;E.exp.AC.debit[i].amount!=0;i++)
                 {     
                     CreateNode(E,i,&sender,&receiver);
                     receiver_root=TransferDetailTree(receiver_root,receiver,sender);
                 }
                 fread(&E,sizeof(employee),1,f);
             }
             sender_root=FillName(w,a,sender_root,0," ",2,y);
             receiver_root=FillName(w,a,receiver_root,1," ",2,y);
             fseek(f,0,0);
             fread(&E,sizeof(employee),1,f);
             while(!feof(f))
             {
                 for(i=0;E.exp.AC.debit[i].amount!=0;i++)
                 {
                     sender_root=ClearDebt(sender_root,E.exp.AC.debit[i].receiver_id,E.ID,E.exp.AC.debit[i].amount);
                     receiver_root=ClearDebt(receiver_root,E.ID,E.exp.AC.debit[i].receiver_id,E.exp.AC.debit[i].amount);
                 }
                 fread(&E,sizeof(employee),1,f);
             }
             switch(sw)
             {
                 case 1:
                     m=DisplayTransferDetail_DEBIT(w,sender_root,ID,y);
                     if(m==-1)
                     {
                         wclear(w1);
                         wrefresh(w1);
                         delwin(w1);
                         for(int line=2;line<=39;line++)
                             for(int space=2;space<=127;space++)
                                 mvwprintw(w,line,space,"%s"," ");
                         wrefresh(w);
                         m=0;
                         goto starting;
                     }
                     break;
                 case 2:
                     DisplayTransferDetail_CREDIT(w,receiver_root,ID,y);
                     if(m==-1) 
                     {
                         wclear(w1);
                         wrefresh(w1);
                         delwin(w1);
                         for(int line=2;line<=39;line++)
                             for(int space=2;space<=127;space++)
                                 mvwprintw(w,line,space,"%s"," ");
                         wrefresh(w);
                         m=0;
                         goto starting;
                     }
                     break;
                 case 3:
                     goto Exit;
             }
Exit:    wclear(w1);
         wrefresh(w1);
         delwin(w1);
         free(sender_root);
         free(receiver_root);
         fclose(f);
}

///////////////////////////////////////////////////// keeps the nodes with resultant debit and credit(By Pintu)////////////////////////////////////////////////////////////////////////////////
void TransferAllDetails_clear(WINDOW *w,char *a)
{
    Transaction *sender_root=NULL,*receiver_root=NULL,*sender,*receiver;
    employee E;
    char list[13][40]={"DEBIT","CREDIT","EXIT"};
    int x=2,y=2,t=4,i,ch,m,sw;
    FILE *f=fopen(a,"rb");
    if(f==NULL)
    {
        mvwprintw(w,1,5,"%s","Not able to Open");
        sleep(3);
        exit(-1);
    }
    WINDOW *w1;
    wattron(w,A_BOLD);
    wattron(w,A_STANDOUT);
    mvwprintw(w,y,x+12*t,"%s","XXX TRANSACTION DETAILS XXX");
    wattroff(w,A_BOLD);
    wattroff(w,A_STANDOUT);
    y+=2;
    fread(&E,sizeof(employee),1,f);
    while(!feof(f))
    {
        for(i=0;E.exp.AC.debit[i].amount!=0;i++)      
        {
            CreateNode(E,i,&sender,&receiver);
            sender_root=TransferDetailTree(sender_root,sender,receiver);
        }
        fread(&E,sizeof(employee),1,f);
    }
    fseek(f,0,0);
    fread(&E,sizeof(employee),1,f);
    while(!feof(f))
    { 
        for(i=0;E.exp.AC.debit[i].amount!=0;i++)
        {     
            CreateNode(E,i,&sender,&receiver);
            receiver_root=TransferDetailTree(receiver_root,receiver,sender);
        }
        fread(&E,sizeof(employee),1,f);
    }
    sender_root=FillName(w,a,sender_root,0," ",2,y);
    receiver_root=FillName(w,a,receiver_root,1," ",2,y);
    fseek(f,0,0);
    fread(&E,sizeof(employee),1,f);
    while(!feof(f))
    {
        for(i=0;E.exp.AC.debit[i].amount!=0;i++)
        {
            sender_root=ClearDebt(sender_root,E.exp.AC.debit[i].receiver_id,E.ID,E.exp.AC.debit[i].amount);
            receiver_root=ClearDebt(receiver_root,E.ID,E.exp.AC.debit[i].receiver_id,E.exp.AC.debit[i].amount);
        }
        fread(&E,sizeof(employee),1,f);
    }
starting:    w1=newwin(5,13,0,0);
             wattron(w1,COLOR_PAIR(2));
             wattron(w1,A_REVERSE);
             wborder(w1,' ',' ',' ',' ',' ',' ',' ',' ');
             wattroff(w1,A_REVERSE);
             wattroff(w1,COLOR_PAIR(2));
             sw=Menu(w1,1,1,list,3,ch,2);
             switch(sw)
             {
                 case 1:
                     m=DisplayAllTransfer_DEBIT(w,sender_root,y);
                     if(m==-1)
                     {
                         wclear(w1);
                         wrefresh(w1);
                         delwin(w1);
                         for(int line=2;line<=39;line++)
                             for(int space=2;space<=127;space++)
                                 mvwprintw(w,line,space,"%s"," ");
                         wrefresh(w);
                         m=0;
                         goto starting;
                     }
                     break;
                 case 2:
                     DisplayAllTransfer_CREDIT(w,receiver_root,y);
                     if(m==-1) 
                     {
                         wclear(w1);
                         wrefresh(w1);
                         delwin(w1);
                         for(int line=2;line<=39;line++)
                             for(int space=2;space<=127;space++)
                                 mvwprintw(w,line,space,"%s"," ");
                         wrefresh(w);
                         m=0;
                         goto starting;
                     }
                     break;
                 case 3:
                     goto Exit;
             }
Exit:    wclear(w1);
         wrefresh(w1);
         delwin(w1);
         free(sender_root);
         free(receiver_root);
         fclose(f);
}



///////////////////////////////////////////////////Finds the resultant transaction.(By Pintu)//////////////////////////////////////////////////////////////////////////////////////////////////
Transaction* ClearDebt(Transaction *root,char *ID1,char *ID2,float amount)
{
    static int flag=1;
    int i;
    float reduced=0;
    Transaction *traverse=root,*temp=NULL,*top_node=NULL;
    while(traverse!=NULL)
    {
        if(strcmp(traverse->ID,ID1)==0)
        {
            top_node=traverse;
            if((traverse->left!=NULL)&&(strcmp(traverse->left->ID,ID2)==0))
            {
                if(traverse->left->amount==amount)
                {
                    reduced+=amount;
                    temp=traverse->left;
                    traverse->left=traverse->left->right;
                    if(traverse->left!=NULL)
                        traverse->left->left=traverse;
                    free(temp);
                    amount=0;
                    goto END;
                }
                else
                {
                    if(traverse->left->amount<amount)
                    {
                        while((traverse->left!=NULL)&&(strcmp(traverse->left->ID,ID2)==0)&&(amount!=0))
                        {
                            if(traverse->left->amount<amount)
                            {
                                reduced+=traverse->left->amount;
                                amount=amount-traverse->left->amount;
                            }
                            else
                            {
                                reduced+=amount;
                                traverse->left->amount-=amount;
                                amount=0;
                                break;
                            }
                            temp=traverse->left;
                            traverse->left=traverse->left->right;
                            if(traverse->left!=NULL)
                                traverse->left->left=traverse;
                            free(temp);
                        }
                        if(amount==0)
                        {
                            goto END;
                        }
                        else
                        {
                            traverse=traverse->left;
                            break;
                        }
                    }
                    else
                        if(traverse->left->amount>amount)
                        {
                            reduced+=amount;
                            traverse->left->amount-=amount;
                            amount=0;
                            goto END;
                        }

                }
            }
            else
            {
                traverse=traverse->left;
                break;
            }
        }
        traverse=traverse->right;
    }
    if(amount!=0)
    {
        if(traverse!=NULL)
        {
            while(traverse->right!=NULL)
            {
                if(strcmp(traverse->right->ID,ID2)==0)
                {

                    if(traverse->right->amount==amount)
                    {
                        reduced+=amount;
                        temp=traverse->right;
                        traverse->right=traverse->right->right;
                        if(traverse->right!=NULL)
                            traverse->right->left=traverse;
                        free(temp);
                        amount=0;
                        goto END;
                    }
                    else
                    {
                        if(traverse->right->amount<amount)
                        {
                            reduced+=traverse->right->amount;
                            amount=amount-traverse->right->amount;
                            temp=traverse->right;
                            traverse->right=traverse->right->right;
                            if(traverse->right!=NULL)
                                traverse->right->left=traverse;
                            free(temp);
                        }
                        else
                            if(traverse->right->amount>amount)
                            {
                                reduced+=amount;
                                traverse->right->amount-=amount;
                                amount=0;
                                goto END;
                            }
                    }
                }
                if(traverse->right!=NULL)
                    traverse=traverse->right;
                else
                {
                    if(amount==0)
                        goto END;
                    else
                        break;
                }
            }
        }
    }
END:
    if(top_node!=NULL)
        top_node->amount-=reduced;
    if(flag%2!=0&&reduced!=0)
        flag++;
    return root;
}

/////////////////////////////////Writes name of the user in all nodes of the tree from the binary file.(By Pintu)//////////////////////////////////////////////////////////////////////////////
Transaction* FillName(WINDOW *w,char *a,Transaction *root,int option,char *ID,int sw,int y)
{
    int x=2,t=4,a1=y,b,a2;
    Transaction *traverse1=root,*traverse2;
    employee E;
    int flag=0,power,year,digit,i;
    FILE *f=fopen(a,"r+");
    if(f==NULL)
    {
        mvwprintw(w,y++,x+10*t,"%s","Sorry,Coulnot open file.");
        sleep(3);
        return root;
    }
    if(option==0)
    {
        while(traverse1!=NULL)
        {
            if(sw==1)
            {
                if(strcmp(traverse1->ID,ID)==0)
                    traverse2=traverse1->left;
                else
                {
                    traverse1=traverse1->right;
                    continue;
                }
            }
            else
                traverse2=traverse1->left;
            while(traverse2!=NULL)
            {
                fseek(f,0,0);
                flag=0;
                fread(&E,sizeof(employee),1,f);
                while(!feof(f))
                {
                    if(strcmp(traverse2->ID,E.ID)==0)
                    {
                        strcpy(traverse2->name.init,E.name.init);
                        strcpy(traverse2->name.surname,E.name.surname);
                        flag=1;
                        break;
                    }
                    fread(&E,sizeof(employee),1,f);
                }
                if(flag==0)
                {
                    echo();
                    wattron(w,A_BOLD);
                    mvwprintw(w,y++,x+10*t,"Info of ID %s is not there in the file.",traverse2->ID);
                    mvwprintw(w,y++,x+10*t,"%s","Please enter the data of the person having");
                    mvwprintw(w,y++,x+10*t,"ID %s :",traverse2->ID);
                    strcpy(E.ID,traverse2->ID);
                    a1=y;
                    mvwprintw(w,y++,x+12*t,"%s","Name(First & Last) : ");
                    wattroff(w,A_BOLD);
                    wscanw(w,"%s %s",E.name.init,E.name.surname);
                    strcpy(traverse2->name.init,E.name.init);
                    strcpy(traverse2->name.surname,E.name.surname);
age: 					wattron(w,A_BOLD);
                        mvwprintw(w,y,x+12*t,"%s","Age :");
                        wattroff(w,A_BOLD);
                        wscanw(w,"%d",&E.age);
                        if(E.age<=15)
                        {
                            for(int space=2;space<=120;space++)
                                mvwprintw(w,y,space,"%s"," ");
                            wattron(w,COLOR_PAIR(4));
                            mvwprintw(w,38,x+7*t,"%s","*Inappropriate Input");
                            wattroff(w,COLOR_PAIR(4));
                            goto age;
                        }
                        for(int space=2;space<=120;space++)
                            mvwprintw(w,38,space,"%s"," ");
                        y++;
gender:		    wattron(w,A_BOLD);
                mvwprintw(w,y,x+12*t,"%s","Gender : ");
                wattroff(w,A_BOLD);
                wscanw(w,"%s",E.gender);
                if(E.gender[0]!='M'&&E.gender[0]!='F'&&E.gender[0]!='O')
                {
                    for(int space=2;space<=120;space++)
                        mvwprintw(w,y,space,"%s"," ");
                    wattron(w,COLOR_PAIR(4));
                    mvwprintw(w,38,x+7*t,"%s","*Inappropriate Input");
                    wattroff(w,COLOR_PAIR(4));
                    goto gender;
                }
                for(int space=2;space<=120;space++)
                    mvwprintw(w,38,space,"%s"," ");
                y++;
                wattron(w,A_BOLD);
                noecho();
                power=3;
                year=0;
                for(i=6;i<=9;i++)
                {
                    digit=traverse2->dt[i]-'0';
                    year=year+digit*pow(10,power);
                    power--;
                }
                E.year=year;
                E.exp.BD.houserent=E.exp.BD.elec_bill=E.exp.BD.groceries=E.exp.BD.others=0;
                strcpy(E.exp.AC.debit[0].receiver_id,"");
                strcpy(E.exp.AC.debit[0].dt,"");
                E.exp.AC.debit[0].amount=0;
                E.exp.PD.lifeins=E.exp.PD.motorins=E.exp.PD.medicalins=E.exp.PD.others=0;
                fseek(f,0,2);
                fwrite(&E,sizeof(employee),1,f);
                }
                traverse2=traverse2->right;
                a2=y;
                if(y>=36&&y<=39)
                {
                    y=a1;
                    for(int line=a1;line<=a2;line++)
                        for(int space=1;space<=120;space++)
                            mvwprintw(w,line,space,"%s"," ");
                }
            }
            if(sw==1)
                break;
            traverse1=traverse1->right;
        }
        b=y;
        fclose(f);
        for(int line=a1;line<=b;line++)
            for(int space=1;space<=120;space++)
                mvwprintw(w,line,space,"%s"," ");
        wrefresh(w);
        return root;
    }
    if(option==1)
    {
        traverse1=root;
        while(traverse1!=NULL)
        {
            if(sw==1 && strcmp(traverse1->ID,ID)!=0)
            {
                traverse1=traverse1->right;
                continue;
            }
            fseek(f,0,0);
            flag=0;
            fread(&E,sizeof(employee),1,f);
            while(!feof(f))
            {
                if(strcmp(traverse1->ID,E.ID)==0)
                {
                    strcpy(traverse1->name.init,E.name.init);
                    strcpy(traverse1->name.surname,E.name.surname);
                    flag=1;
                    break;
                }
                fread(&E,sizeof(employee),1,f);
            }
            if(flag==0)
            {
                echo();
                wattron(w,A_BOLD);
                mvwprintw(w,y++,x+10*t,"Info of ID %s is not there in the file.",traverse2->ID);
                mvwprintw(w,y++,x+10*t,"%s","Please enter the data of the person having");
                mvwprintw(w,y++,x+10*t,"ID %s :",traverse2->ID);
                mvwprintw(w,y++,x+12*t,"%s","Name (First & Last) : ");
                wattroff(w,A_BOLD);
                wscanw(w,"%s %s",E.name.init,E.name.surname);
                strcpy(traverse1->name.init,E.name.init);
                strcpy(traverse1->name.surname,E.name.surname);
                wattron(w,A_BOLD);
                mvwprintw(w,y,x+12*t,"%s","Age :");
                wattroff(w,A_BOLD);
                wscanw(w,"%d",&E.age);
age1:		    if(E.age<15)
                {
                    for(int space=2;space<=120;space++)
                        mvwprintw(w,y,space,"%s"," ");
                    wattron(w,COLOR_PAIR(4));
                    mvwprintw(w,38,x+7*t,"%s","*Inappropriate Input");
                    wattroff(w,COLOR_PAIR(4));
                    goto age1;
                }
                for(int space=2;space<=120;space++)
                    mvwprintw(w,38,space,"%s"," ");
                y++;
gender1:     	    wattron(w,A_BOLD);
                    mvwprintw(w,y,x+12*t,"%s","Gender : ");
                    wattroff(w,A_BOLD);
                    wscanw(w,"%s",E.gender);
                    if(E.gender[0]!='M'&&E.gender[0]!='F'&&E.gender[0]!='O')
                    {
                        for(int space=2;space<=120;space++)
                            mvwprintw(w,y,space,"%s"," ");
                        wattron(w,COLOR_PAIR(4));
                        mvwprintw(w,38,x+7*t,"%s","*Inappropriate Input");
                        wattroff(w,COLOR_PAIR(4));
                        goto gender1;
                    }
                    for(int space=2;space<=120;space++)
                        mvwprintw(w,38,space,"%s"," ");
                    y++;
                    wattron(w,A_BOLD);
                    noecho();
                    power=3;
                    year=0;
                    for(i=6;i<=9;i++)
                    {
                        digit=traverse2->dt[i]-'0';
                        year=year+digit*pow(10,power);
                        power--;
                    }
                    E.year=year;
                    E.exp.BD.houserent=E.exp.BD.elec_bill=E.exp.BD.groceries=E.exp.BD.others=0;
                    strcpy(E.exp.AC.debit[0].receiver_id,"");  
                    strcpy(E.exp.AC.debit[0].dt,"");
                    E.exp.AC.debit[0].amount=0;
                    E.exp.PD.lifeins=E.exp.PD.motorins=E.exp.PD.medicalins=E.exp.PD.others=0;
                    fseek(f,0,2);
                    fwrite(&E,sizeof(employee),1,f);
            }
            if(sw==1)
                break;
            traverse1=traverse1->right;
        }
        b=y;
        for(int line=a1;line<=b;line++)
            for(int space=1;space<=120;space++)
                mvwprintw(w,line,space,"%s"," ");
        wrefresh(w);
        fclose(f);
        return root;
    }
}


////////////////////////////////////////////////////////////////Display the details of all nodes of debited .( By Pintu)///////////////////////////////////////////////////////////////////////
int DisplayAllTransfer_DEBIT(WINDOW *w,Transaction *S_root,int y)
{
    int x=2,t=4,a,b,ch;
    Transaction *traverse1=S_root,*traverse2;
    wattron(w,A_BOLD);
    wattron(w,A_UNDERLINE);
    wattron(w,A_STANDOUT);
    mvwprintw(w,y,x+2*t,"%s","Sender's Detail");
    mvwprintw(w,y,x+15*t,"%s","Receivers's Detail");
    wattroff(w,A_STANDOUT);
    y+=2;
    mvwprintw(w,y,2*x+t,"%s","ID");
    mvwprintw(w,y,x+5*t,"%s","Name");
    mvwprintw(w,y,2*x+11*t,"%s","ID");
    mvwprintw(w,y,x+15*t,"%s","Name");
    mvwprintw(w,y,x+20*t-1,"%s","Date");
    mvwprintw(w,y,x+23*t,"%s","Amount");
    wattroff(w,A_BOLD);
    wattroff(w,A_UNDERLINE);
    y++;
    a=y;
    while(traverse1!=NULL)
    {
        if(traverse1->left!=NULL)
        {
            mvwprintw(w,y,x+t,"%s",traverse1->ID);
            mvwprintw(w,y,x+4*t,"%s %s",traverse1->name.init,traverse1->name.surname);
        }
        traverse2=traverse1->left;
        while(traverse2!=NULL)
        {
            mvwprintw(w,y,x+11*t,"%s",traverse2->ID);
            mvwprintw(w,y,x+14*t,"%s %s",traverse2->name.init,traverse2->name.surname);
            mvwprintw(w,y,x+19*t,"%s",traverse2->dt);
            mvwprintw(w,y,x+23*t,"%.2f",traverse2->amount);
            traverse2=traverse2->right;
            y++;
            b=y;
            if(y>=36&&y<=39)
            {
again2:		mvwprintw(w,38,x+5*t,"%s","Press Enter to Go to Next Page");
            ch=wgetch(w);
            y=10;
            if(ch=='\n')
            {
                for(int line=a;line<=b;line++)
                    for(int space=1;space<=120;space++)
                        mvwprintw(w,line,space,"%s"," ");
            }
            else if(ch=='q')
                return(-1);
            else
                goto again2;
            } 
        }
        traverse1=traverse1->right;
        y+=2;
        b=y;
        if(y>=36&&y<=39)
        {
again:               mvwprintw(w,38,x+5*t,"%s","Press Enter to Go to Next Page");
                     ch=wgetch(w);
                     y=10;
                     if(ch=='\n')
                     {
                         for(int line=a;line<=b;line++)
                             for(int space=1;space<=120;space++)
                                 mvwprintw(w,line,space,"%s"," ");
                     }
                     else if(ch=='q')
                         return(-1);
                     else
                         goto again;
        }
    }
again1:        mvwprintw(w,y+2,x+5*t,"%s","Press 'q' to go back");
               wrefresh(w);
               ch=wgetch(w);
               if(ch=='q')
                   return(-1);
               goto again1;


}
//////////////////////////////////////////////Display the details of all nodes of credited .(By Pintu)////////////////////////////////////////////////////////////////////////////////////////
int DisplayAllTransfer_CREDIT(WINDOW *w,Transaction *R_root,int y)
{
    int x=2,t=4,a,b,ch;
    Transaction *traverse1,*traverse2;
    wattron(w,A_BOLD);
    wattron(w,A_UNDERLINE);
    wattron(w,A_STANDOUT);
    mvwprintw(w,y,x+2*t,"%s","Receiver's Detail");
    mvwprintw(w,y,x+15*t,"%s","Sender's Detail");
    wattroff(w,A_STANDOUT);
    y+=2;
    mvwprintw(w,y,2*x+t,"%s","ID");
    mvwprintw(w,y,x+5*t,"%s","Name");
    mvwprintw(w,y,2*x+11*t,"%s","ID");
    mvwprintw(w,y,x+15*t,"%s","Name");
    mvwprintw(w,y,x+20*t-1,"%s","Date");
    mvwprintw(w,y,x+23*t,"%s","Amount");
    wattroff(w,A_BOLD);
    wattroff(w,A_UNDERLINE);
    y++;
    traverse1=R_root;
    a=y;
    while(traverse1!=NULL)
    {
        if(traverse1->left!=NULL)
        {
            mvwprintw(w,y,x+t,"%s",traverse1->ID);
            mvwprintw(w,y,x+4*t,"%s %s",traverse1->name.init,traverse1->name.surname);
        }
        traverse2=traverse1->left;
        while(traverse2!=NULL)
        {
            mvwprintw(w,y,x+11*t,"%s",traverse2->ID);
            mvwprintw(w,y,x+14*t,"%s %s",traverse2->name.init,traverse2->name.surname);
            mvwprintw(w,y,x+19*t,"%s",traverse2->dt);
            mvwprintw(w,y,x+23*t,"%.2f",traverse2->amount);
            traverse2=traverse2->right;
            y++;
            b=y;
            if(y>=36&&y<=39)
            {
again2:     mvwprintw(w,38,x+5*t,"%s","Press Enter to Go to Next Page");
            ch=wgetch(w);
            y=a;
            if(ch=='\n')
            {
                for(int line=a;line<=b;line++)
                    for(int space=1;space<=120;space++)
                        mvwprintw(w,line,space,"%s"," ");
            }
            else if(ch=='q')
                return(-1);
            else
                goto again2;
            }
        }
        traverse1=traverse1->right;
        y+=2;
        b=y;
        if(y>=36&&y<=39)
        {
again:               mvwprintw(w,38,x+5*t,"%s","Press Enter to Go to Next Page");
                     ch=wgetch(w);
                     y=a;
                     if(ch=='\n')
                     {
                         for(int line=a;line<=b;line++)
                             for(int space=1;space<=120;space++)
                                 mvwprintw(w,line,space,"%s"," ");
                     }
                     else if(ch=='q')
                         return(-1);
                     else
                         goto again;
        }
    }

again1:        mvwprintw(w,38,x+5*t,"%s","Press 'q' to go back");
               wrefresh(w);
               ch=wgetch(w);
               if(ch=='q')
                   return(-1);
               goto again1;
}



//////////////////////////////////////////////////////////////////////////////////////PASSWORD////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////// This function takes a string(Password typed by user) and returns the truth value of Password.(By Abhay)//////////////////////////////////////////////////////

int EPassword(WINDOW *w,char *c)
{
    Password P;              
    FILE *f=fopen(c,"rb");       //opening the Password File in Binary Mode.
    if(f==NULL)  		//Cheaking if the File opened Properly.
    {
        mvwprintw(w,1,5,"%s","Not able to Open");
        sleep(3);
        exit(-1);
    }
    int y=2,x=2,t=4,i=0,z;
    char str[15],option;
    fread(&P,sizeof(Password),1,f);                 //Reading fro the File.
passw: y=2; 
       mvwprintw(w,y++,x,"%s","USERNAME : STUDENT");
       mvwprintw(w,y++,x,"%s","PASSWORD :");
       do
       {
           str[i]=wgetch(w);                         //Taking input as Each Character and Printing 'Star'(*),and removing it alsowhen Deleted a character.
           if(str[i]=='d')
           {
               if(i>0)
               {
                   i--;
                   mvwprintw(w,y-1,x+2*t+i+3,"%s"," ");   //removing 'star'(*) When Deleting a Character.
               }
           }
           else
           {
               mvwprintw(w,y-1,x+3+i+2*t,"%s","*");       //printing 'star'(*),when taking a Character.
               i++;
           }
       }while(str[i-1]!='\n');          //Loop goes on till the Input is 'Enter'.
       str[i-1]='\0';
       i=0;
       P=Decryption(c);                //Decriptes the Data Stored in the File.
       if(strcmp(str,P.password)==0)      //Compares the Password.
       {
           for(int space=2;space<=30;space++)
               mvwprintw(w,5,space,"%s"," ");
           return(1);
       }
       else 				//If Password is Different then Print the Approprite Message and takes the Input again.
       {
           wattron(w,COLOR_PAIR(4));
           mvwprintw(w,5,x+3,"%s","INVALID PASSWORD");
           wattroff(w,COLOR_PAIR(4));
           for(int line=2;line<=3;line++)
               for(int space=2;space<=30;space++)
                   mvwprintw(w,line,space,"%s"," ");
           goto passw;
       }
}

/////////////////////////////////////////////////// This function allows the user to change the Password.(By Pintu)////////////////////////////////////////////////////////////////////////////
void ChangePassword(WINDOW *w,char *c)
{
    Password P;
    char str1[15],str2[15];
    int y=4,x=2,t=4,i=0,change;
    FILE *f;
    f=fopen(c,"rb");
    if(f==NULL)
    {
        mvwprintw(w,1,5,"%s","Not able to Open");
        sleep(3);
        exit(-1);
    }
    fread(&P,sizeof(Password),1,f);
    P=Decryption(c);
    mvwprintw(w,y++,x+t,"%s","Password Word Should be between 4-15 characters.");
Start:
    mvwprintw(w,y++,x+t,"%s","Current Password : ");
    do
    {
        str1[i]=wgetch(w);
        if(str1[i]=='d')
        {
            if(i>0)
            {
                i--;
                mvwprintw(w,y-1,x+6*t+i,"%s"," ");
            }
        }
        else 
        {
            mvwprintw(w,y-1,x+i+6*t,"%s","*");
            i++;
        }
    }while(str1[i-1]!='\n');
    str1[i-1]='\0';
    i=0;
    strcpy(str2,"");
    if(strcmp(P.password,str1)==0)
    {
        while(strcmp(str1,str2)!=0)
        {
Input:
            mvwprintw(w,y,x+t,"%s","Enter New password : ");
            do
            {
                str1[i]=wgetch(w);
                if(str1[i]=='d')
                {
                    if(i>0)
                    {
                        i--;
                        mvwprintw(w,y,x+6*t+i+1,"%s"," ");
                    }
                }
                else 
                {
                    mvwprintw(w,y,x+1+i+6*t,"%s","*");
                    i++;
                }
            }while(str1[i-1]!='\n');
            str1[i-1]='\0';
            i=0;
            if(strlen(str1)>15 && strlen(str1)<4)
            {
                wattron(w,COLOR_PAIR(4));
                mvwprintw(w,10,10,"%s","Invalid Length Limit");
                wattroff(w,COLOR_PAIR(4));
                for(int space=2;space<=40;space++)
                    mvwprintw(w,y,space,"%s"," ");

                goto Input;
            }
            for(int space=2;space<=40;space++)
                mvwprintw(w,10,space,"%s"," ");
            mvwprintw(w,y+1,x+t,"%s","Confirm New password : ");
            do
            {
                str2[i]=wgetch(w);
                if(str2[i]=='d')
                {
                    if(i>0)
                    {
                        i--;
                        mvwprintw(w,y+1,x+7*t+i+1,"%s"," ");
                    }
                }
                else 
                {
                    mvwprintw(w,y+1,x+1+i+7*t,"%s","*");
                    i++;
                }
            }while(str2[i-1]!='\n');
            str2[i-1]='\0';
            i=0;

            if(strcmp(str1,str2)==0)
            {
                Encryption(w,str1,c);
                break;
            }
            else
            {
                wattron(w,COLOR_PAIR(4));
                mvwprintw(w,10,10,"%s","Password Does not Match");
                wattroff(w,COLOR_PAIR(4));
                for(int line=y;line<=y+1;line++)
                    for(int space=2;space<=40;space++)
                        mvwprintw(w,line,space,"%s"," ");

            }
        }
        for(int space=2;space<=40;space++)
            mvwprintw(w,10,space,"%s"," ");
        change=1;
    }
    else
    {
        wattron(w,COLOR_PAIR(4));
        mvwprintw(w,10,10,"%s","Invalid Password");
        wattroff(w,COLOR_PAIR(4));
    }
    if(change==1)
    {
        wattron(w,COLOR_PAIR(1));
        mvwprintw(w,10,10,"%s","Your Password is changed...Thank you..");
        wattroff(w,COLOR_PAIR(1));
    }
}

/////////////////////////////////////////////Creates the Window for New user By Abhay Dhiman////////////////////////////////////////////////////////////////////////////////////////////////
void NewUser(WINDOW *w,char *c)
{
    FILE *f;
    int y=2,x=2,t=4;
    Password P;
    f=fopen(c,"rb");         //Opens the Password File in Binary Mode.
    if(f==NULL)		     //Cheaks if the File Opened Properly.
    { 
        mvwprintw(w,1,5,"%s","Not able to Open");
        sleep(3);
        exit(-1);
    }
    fread(&P,sizeof(Password),1,f);            //Reades from the File.
    if(P.user_status!=0)                       //Cheaks if the User is a New User or Not.
        mvwprintw(w,y++,x+t,"%s","Sorry,u are not new user.");
    else           //Prints appropriate Messeges and asks to Change his password.
    {
        mvwprintw(w,y++,x+t,"%s","It is better to change your current password to keep your data secure....");
        mvwprintw(w,y++,x+t,"%s","Your current password is '0000'.");
        ChangePassword(w,c);		//Function to Change the Password.
    }
    fclose(f);  		Closses the File.
}


//////////////////////////////This function takes a string, Encrypts it by adding and subtracting some random numbers and stores it into a binary file.(By Pintu)//////////////////////////////

void Encryption(WINDOW *w,char str[15],char *c)
{ 
    Password P;
    char copy[15];
    int seed=10,i,x;
    FILE *f;
    P.len=strlen(str);
    f=fopen(c,"wb");
    if(f==NULL)
    {
        mvwprintw(w,1,5,"%s","Not able to Open");
        sleep(3);
        exit(-1);
    }
    if(f==NULL)
    {
        mvwprintw(w,6,3,"%s","File not Found");
        exit(-1);
    } 
    strcpy(copy,str);
    i=0;
    void srand(seed);
    while(str[i]!='\0')
    {
        x=1+rand()%20;
        P.rand_value[i]=x;
        P.operation[i]=x%2;
        if(P.operation[i]==0)
        {
            str[i]=(char)((int)str[i]+x);
            i++;
        }
        else
        {
            str[i]=(char)((int)str[i]-x);
            i++;
        }        
    }
    strcpy(P.password,str);
    if(strcmp(copy,"0000")==0)
        P.user_status=0;
    else
        P.user_status=1;
    fwrite(&P,sizeof(Password),1,f);
    fclose(f);
}

/////////////////////////////////////////////// This function Decrypts the Encrypted Password and returns a record of type Password.(By Pintu)/////////////////////////////////////////////////
Password  Decryption(char *c)
{
    Password P;
    FILE *f;
    int i,operation,operand;
    f=fopen(c,"rb");
    if(f==NULL)
    {
        printf("Not able to Open");
        sleep(3);
        exit(-1);
    }
    fread(&P,sizeof(Password),1,f);
    i=0;
    while(i<P.len)
    {
        if(P.operation[i]==0)
            P.password[i]=(char)((int)P.password[i]-P.rand_value[i]);
        else
            P.password[i]=(char)((int)P.password[i]+P.rand_value[i]);
        i++;
    } 
    fclose(f);
    return P;
}	

/////////////////////////////////////////////////////////////////////////////MAIN FUNCTION////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////// The main Function( By Abhay )//////////////////////////////////////////////////////////////////////////////////////////////////
int MainFun(char *a,char *b)
{
    FileEmployeeDetail(b,a);		//Convets the text File Into The Binary File.
    WINDOW *w;
    int sw,ch,x=2,y=1,i,m;
    employee E;
    FILE *p;
    char item[4];
    char list[13][40]={"Enter the Details of an Employee","Income Tax Department","Display the Details of the Employees","Analysis","LOG OUT"};
    char list1[13][40]={"Expensies","Policy","Transaction","BACK"};
    char list2[13][40]={"Individual","Group","Individual(OFFSET)","Group(OFFSET)" ,"BACK"};
    char list3[13][40]={"Indivisiual","Total","BACK"};
starting:
    w=newwin(10,80,18,33);//Creates the Main Window.
    wattron(w,COLOR_PAIR(2));
    wattron(w,A_REVERSE);
    wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');   		//Defines a Border to the Window.
    wattroff(w,A_REVERSE);
    wattroff(w,COLOR_PAIR(2));
    wattron(w,A_BOLD);
    wattron(w,A_UNDERLINE);
    wattron(w,COLOR_PAIR(1));
    mvwprintw(w,1,18,"%s","*** FINANCIAL PLANNER OF AN INDIVIDIUAL ***");
    wattroff(w,COLOR_PAIR(1));
    wattroff(w,A_UNDERLINE);
    wattron(w,A_BOLD);
    m=Menu(w,y+2,x,list,5,ch,2);               //Menu Function to Print Menu initialized above in the list.
    wclear(w);
    wrefresh(w);
    delwin(w);
    sw=m-2;
    switch(sw)                                //switches to the Function According to the User Input.
    {
        case 1:
            w=newwin(40,75,0,45);            //Creates a new Window.
            wattron(w,COLOR_PAIR(2));
            wattron(w,A_REVERSE);
            wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
            wattroff(w,A_REVERSE);
            wattroff(w,COLOR_PAIR(2));
            EmployeeDetail(w,E,a);		//Function to take the Details of an Employee. 
            wclear(w);
            wrefresh(w);                       //Deleting the Window.
            delwin(w);
prev2:	case 2:
            w=newwin(10,80,18,33);		//Creates a new Window.
            wattron(w,COLOR_PAIR(2));
            wattron(w,A_REVERSE);
            wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
            wattroff(w,A_REVERSE);
            wattroff(w,COLOR_PAIR(2));
            m=Menu(w,y+2,x,list3,3,ch,2);		//Menu Function to Print Menu initialized above in the list3.
            wclear(w);
            wrefresh(w);
            delwin(w);                                 //Deleting the Window.
            sw=m-2;
            switch(sw)                           //Switches to the Input Acording to the User Input.
            {
                case 1:
                    w=newwin(10,80,10,10);		//Creates a new Window.
                    wattron(w,COLOR_PAIR(2));
                    wattron(w,A_STANDOUT);
                    wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
                    wattroff(w,COLOR_PAIR(2));
                    wattroff(w,A_STANDOUT);
                    TAX(w,a);                               //Function to Print the Payable Tax for the Particular ID and Year.
                    wgetch(w);
                    wclear(w);
                    wrefresh(w);                             //Deletes the Window.
                    delwin(w);
                    goto prev2;
                case 2:
                    w=newwin(40,130,0,0);		//Creates a new Window.
                    wattron(w,COLOR_PAIR(2));
                    wattron(w,A_REVERSE);
                    wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
                    wattroff(w,A_REVERSE);
                    wattroff(w,COLOR_PAIR(2));
                    TotalTax(w,a);                     //Displays the Total Tax Collected in a Particular year.
                    wrefresh(w);
                    wgetch(w);
                    wclear(w);
                    wrefresh(w);                         //Deletes the Window.
                    delwin(w);
                    goto prev2;
                case 3:
                    goto starting;
            }
        case 3:
            w=newwin(40,130,0,0);		//Creates a new Window.
            wattron(w,COLOR_PAIR(2));
            wattron(w,A_REVERSE);
            wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
            wattroff(w,A_REVERSE);
            wattroff(w,COLOR_PAIR(2));
            DislayId(w,E,a);                          //Display all the Details of the Particular Employee.
            wrefresh(w);
            wgetch(w);
            wclear(w);
            wrefresh(w);                         //Deletes the Window.
            delwin(w);
            goto starting;
        case 4:
prev4:	w=newwin(6,70,20,35);		//Creates a new Window.
        wattron(w,COLOR_PAIR(2));
        wattron(w,A_REVERSE);
        wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
        wattroff(w,A_REVERSE);
        wattroff(w,COLOR_PAIR(2));
        m=Menu(w,y,x,list1,4,ch,2);		//Menu Function to Print Menu initialized above in the list1.
        wclear(w);
        wrefresh(w);
        delwin(w);                             //Deletes the Window.
        sw=m;
        switch(sw)                               //Switches to the Function according to the User Input.
        {
            case 1:
                w=newwin(40,130,0,0);		//Creates a new Window.
                wattron(w,COLOR_PAIR(2));		wattron(w,A_REVERSE);
                wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
                wattroff(w,A_REVERSE);
                wattroff(w,COLOR_PAIR(2));
                BillDetail(w,a);                     //Analysis the Bill Details of the Particular ID.
                wrefresh(w);
                wgetch(w);
                wclear(w);                           //Delets the Window.
                wrefresh(w);
                delwin(w);
                goto prev4;
            case 2:
                w=newwin(40,130,0,0);		//Creates a new Window.
                wattron(w,COLOR_PAIR(2));
                wattron(w,A_REVERSE);
                wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
                wattroff(w,A_REVERSE);
                wattroff(w,COLOR_PAIR(2));
                PolicyDetail(w,a);                    //Analysis the Policy Details of the Particular ID.
                wrefresh(w);
                wgetch(w);
                wclear(w);
                wrefresh(w);
                delwin(w);                            //Deletes the Window.
                goto prev4;
            case 3:

prev43:		w=newwin(8,70,20,35);		//Creates a new Window.
            wattron(w,COLOR_PAIR(2));
            wattron(w,A_REVERSE);
            wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
            wattroff(w,A_REVERSE);
            wattroff(w,COLOR_PAIR(2));
            m=Menu(w,y,x,list2,5,ch,2);
            wclear(w);
            wrefresh(w);
            delwin(w);
            sw=m;
            switch(sw)
            {
                case 1:
                    w=newwin(40,130,0,12);		//Creates a new Window.
                    wattron(w,COLOR_PAIR(2));
                    wattron(w,A_REVERSE);
                    wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
                    wattroff(w,A_REVERSE);
                    wattroff(w,COLOR_PAIR(2));
                    wrefresh(w);
                    TransferDetail(w,a);
                    wrefresh(w);
                    wgetch(w);
                    wclear(w);
                    wrefresh(w);
                    delwin(w);
                    goto prev43;
                case 2:
                    w=newwin(40,130,0,12);		//Creates a new Window.
                    wattron(w,COLOR_PAIR(2));
                    wattron(w,A_REVERSE);
                    wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
                    wattroff(w,A_REVERSE);
                    wattroff(w,COLOR_PAIR(2));
                    wrefresh(w);
                    TransferDetail_all(w,a);
                    wrefresh(w);
                    wgetch(w);
                    wclear(w);
                    wrefresh(w);
                    delwin(w);
                    goto prev43;
                case 3:
                    w=newwin(40,130,0,12);		//Creates a new Window.
                    wattron(w,COLOR_PAIR(2));
                    wattron(w,A_REVERSE);
                    wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
                    wattroff(w,A_REVERSE);
                    wattroff(w,COLOR_PAIR(2));
                    wrefresh(w);
                    TransferDetails_clear(w,a);
                    wrefresh(w);
                    wgetch(w);
                    wclear(w);
                    wrefresh(w);
                    delwin(w);
                    goto prev43;
                case 4:
                    w=newwin(40,130,0,12);		//Creates a new Window.
                    wattron(w,COLOR_PAIR(2));
                    wattron(w,A_REVERSE);
                    wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
                    wattroff(w,A_REVERSE);
                    wattroff(w,COLOR_PAIR(2));
                    wrefresh(w);
                    TransferAllDetails_clear(w,a);
                    wrefresh(w);
                    wgetch(w);
                    wclear(w);
                    wrefresh(w);
                    delwin(w);
                    goto prev43;

                case 5:
                    goto prev4;
            }
            case 4:
            goto starting;
        }
        case 5:
        goto EXIT;
    }
EXIT:
    refresh();
    return(0);
}



///////////////////////////////////////////////////////////////Creates the main Window of the program( By Abhay )//////////////////////////////////////////////////////////////////////////////
int MainWin(char *c)
{
    char list[13][40]={"LOG IN","SIGN UP","EXIT"};
    char list1[13][40]={"ENTER PASSWORD","CHANGE PASSWORD","BACK"};
    int sw,ch,y=2,x=2,sw1,p; 
    WINDOW *w,*w1;
    FILE *f;
    char pass[15];
starting:    w=newwin(6,20,20,80);		//Creates a new Window.
             wattron(w,COLOR_PAIR(2));
             wattron(w,A_REVERSE);
             wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');	//Defines a border for the Window.
             wattroff(w,A_REVERSE);
             wattroff(w,COLOR_PAIR(2));
             wrefresh(w);
             sw=Menu(w,y,x,list,3,ch,2);
             wclear(w);
             wrefresh(w);
             delwin(w);
             sw=sw-1;
             switch(sw)
             {
                 case 1:
                     y=2;
                     x=2;
                     w=newwin(6,20,0,0);		//Creates a new Window.
                     wattron(w,COLOR_PAIR(2));
                     wattron(w,A_REVERSE);
                     wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
                     wattroff(w,A_REVERSE);
                     wattroff(w,COLOR_PAIR(2));
                     wrefresh(w);
prev1:	    sw1=Menu(w,y,x,list1,3,ch,2);
            sw1=sw1-1;
            switch(sw1)
            {
                case 1:
                    w1=newwin(12,40,0,20);		//Creates a new Window.
                    wattron(w1,COLOR_PAIR(2));
                    wattron(w1,A_REVERSE);
                    wborder(w1,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
                    wattroff(w1,A_REVERSE);
                    wattroff(w1,COLOR_PAIR(2));
                    p=EPassword(w1,c);
                    if(p==1)
                        return(1);		
                    wclear(w1);
                    wrefresh(w1);
                    delwin(w1);
                    goto prev1;
                case 2:
                    w1=newwin(12,80,0,20);		//Creates a new Window.
                    wattron(w1,COLOR_PAIR(2));
                    wattron(w1,A_REVERSE);
                    wborder(w1,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
                    wattroff(w1,A_REVERSE);
                    wattroff(w1,COLOR_PAIR(2));
                    ChangePassword(w1,c);
                    wgetch(w1);
                    wclear(w1);
                    wrefresh(w1);
                    delwin(w1);
                    goto prev1;
                case 3:
                    wclear(w);
                    wrefresh(w);
                    delwin(w);
                    goto starting;
            }
                 case 2:
            w=newwin(12,60,20,30);		//Creates a new Window.
            wattron(w,COLOR_PAIR(2));
            wattron(w,A_REVERSE);
            wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');		//Defines a border for the Window.
            wattroff(w,A_REVERSE);
            wattroff(w,COLOR_PAIR(2));
            wrefresh(w);
            NewUser(w,c);
            wgetch(w);
            wclear(w);
            wrefresh(w);
            delwin(w);
            goto starting;
                 case 3:
            goto EXIT;
             }
EXIT: refresh();
      return(0);
}

