#include"header.h"

void Employee_Detail(WINDOW *w,employee E,char *a)
{
    int i=5,y=3,t=4,ch,sw,k,cmp;
    k=i;
    employee F;
    char ID[20];
    char choice[4][40]={"YES","NO"};
    char month_p[12][5]={"Jan.","Feb.","Mar.","Apr.","May","June","July","Aug.","Sept.","Oct.","Nov.","Dec."};
    FILE *p,*q;
    //init_pair(1,COLOR_CYAN,COLOR_BLACK);
    echo();
    wattron(w,A_ALTCHARSET);
    mvwprintw(w,2,10,"%s","HELLO");
    wattroff(w,A_ALTCHARSET);
    p=fopen(a,"ab");
    wgetch(w);
    wattron(w,A_UNDERLINE);
    mvwprintw(w,i++,y,"%s","ID:");
    wattroff(w,A_UNDERLINE);
    wgetstr(w,E.ID);
    q=fopen(a,"rb");
    while(fread(&F,sizeof(employee),1,q)==1)
    {
	if(strcmp(F.ID,E.ID)==0)
	{
	    E=F;
	    goto existing;
	}
    }
    wattron(w,A_UNDERLINE);
    mvwprintw(w,i++,y,"%s","First Name:");
    wattroff(w,A_UNDERLINE);
    wscanw(w,"%s",E.name.init);
    wattron(w,A_UNDERLINE);
    mvwprintw(w,i++,y,"%s","Last Name:");
    wattroff(w,A_UNDERLINE);
    wscanw(w,"%s",E.name.surname);
age:    wattron(w,A_UNDERLINE);
	mvwprintw(w,i,y,"%s","Age:");
	wattroff(w,A_UNDERLINE);
	wscanw(w,"%d",&E.age);
	if(E.age<=14)
	{
	    for(int space=2;space<=55;space++)
		mvwprintw(w,i,space,"%s","  ");
	    wattron(w,COLOR_PAIR(4));
	    mvwprintw(w,39,10,"%s","* Inappropriate Input.");
	    wattroff(w,COLOR_PAIR(4));
	    wrefresh(w);
	    goto age;
	}
	i++;

	for(int space=2;space<=55;space++)
	    mvwprintw(w,39,space,"%s","  ");
	wrefresh(w);
gender:   wattron(w,A_UNDERLINE);
	  mvwprintw(w,i,y,"%s","Gender(M/F/O):");
	  wattroff(w,A_UNDERLINE);
	  wscanw(w,"%s",&E.gender);
	  if(strcmp(E.gender,"M") && strcmp(E.gender,"F") && strcmp(E.gender,"O"))
	  {
	      for(int space=2;space<=55;space++)
		  mvwprintw(w,i,space,"%s","  ");
	      wattron(w,COLOR_PAIR(4));
	      mvwprintw(w,39,10,"%s","* Inappropriate Input.");
	      wattroff(w,COLOR_PAIR(4));
	      wrefresh(w);
	      goto gender;
	  }
	  i++;
	  for(int space=2;space<=55;space++)
	      mvwprintw(w,39,space,"%s","  ");
	  wrefresh(w);
	  wattron(w,A_UNDERLINE);
	  mvwprintw(w,i++,y,"%s","Account No.:");
	  wattroff(w,A_UNDERLINE);
	  wgetstr(w,E.acc_no);
here1: wattron(w,A_UNDERLINE);
       mvwprintw(w,i,y,"%s","Year of INCOME:");
       wattroff(w,A_UNDERLINE);
       wscanw(w,"%d",&E.year);
       if(E.year<=0)
       {
	   for(int space=2;space<=55;space++)
	       mvwprintw(w,i,space,"%s","  ");
	   wattron(w,COLOR_PAIR(4));
	   mvwprintw(w,39,10,"%s","* Inappropriate Input.");
	   wattroff(w,COLOR_PAIR(4));
	   wrefresh(w);
	   goto here1;
       }
       i++;
       for(int space=2;space<=55;space++)
	   mvwprintw(w,39,space,"%s","  ");
       wrefresh(w);
MOI:       wattron(w,A_UNDERLINE);
	   mvwprintw(w,i,y,"%s","Month of INCOME:");
	   wattroff(w,A_UNDERLINE);
	   wscanw(w,"%d",&E.exp.month);
	   if(E.exp.month<1 || E.exp.month>12)
	   {
	       for(int space=2;space<=55;space++)
		   mvwprintw(w,i,space,"%s","  ");
	       wattron(w,COLOR_PAIR(4));
	       mvwprintw(w,39,10,"%s","* Inappropriate Input.");
	       wattroff(w,COLOR_PAIR(4));
	       wrefresh(w);
	       goto MOI;
	   }
	   i++;
	   for(int space=2;space<=55;space++)
	       mvwprintw(w,39,space,"%s","  ");
	   wrefresh(w);
IOY:       wattron(w,A_UNDERLINE);
	   mvwprintw(w,i,y,"Income(of %s %d):",month_p[E.exp.month-1],E.year);
	   wattroff(w,A_UNDERLINE);
	   wscanw(w,"%f",&E.income);
	   if(E.income<=0)
	   {
	       for(int space=2;space<=55;space++)
		   mvwprintw(w,i,space,"%s","  ");
	       wattron(w,COLOR_PAIR(4));
	       mvwprintw(w,39,10,"%s","* Inappropriate Input.");
	       wattroff(w,COLOR_PAIR(4));
	       wrefresh(w);
	       goto IOY;
	   }
	   i++;
	   for(int space=2;space<=55;space++)
	       mvwprintw(w,39,space,"%s","  ");
	   wrefresh(w);
	   wattron(w,A_UNDERLINE);
	   mvwprintw(w,i++,y,"EXPENDITURES (of %s %d ):",month_p[E.exp.month-1],E.year);
	   mvwprintw(w,i++,y,"%s","BILL DETAILS:");
BDH:       mvwprintw(w,i,y+t,"%s","House Rent:");
	   wattroff(w,A_UNDERLINE);
	   wscanw(w,"%f",&E.exp.BD.houserent);
	   if(E.exp.BD.houserent<=0)
	   {
	       for(int space=2;space<=55;space++)
		   mvwprintw(w,i,space,"%s","  ");
	       wattron(w,COLOR_PAIR(4));
	       mvwprintw(w,39,10,"%s","* Inappropriate Input.");
	       wattroff(w,COLOR_PAIR(4));
	       wrefresh(w);
	       goto BDH;
	   }
	   i++;
	   for(int space=2;space<=55;space++)
	       mvwprintw(w,39,space,"%s","  ");
	   wrefresh(w);

BDE:       wattron(w,A_UNDERLINE);
	   mvwprintw(w,i,y+t,"%s","Electric Bill:");
	   wattroff(w,A_UNDERLINE);
	   wscanw(w,"%f",&E.exp.BD.elec_bill);
	   if(E.exp.BD.elec_bill<=0)
	   {
	       for(int space=2;space<=55;space++)
		   mvwprintw(w,i,space,"%s","  ");
	       wattron(w,COLOR_PAIR(4));
	       mvwprintw(w,39,10,"%s","* Inappropriate Input.");
	       wattroff(w,COLOR_PAIR(4));
	       wrefresh(w);
	       goto BDE;
	   }
	   i++;
	   for(int space=2;space<=55;space++)
	       mvwprintw(w,39,space,"%s","  ");
	   wrefresh(w);

BDG:       wattron(w,A_UNDERLINE);
	   mvwprintw(w,i,y+t,"%s","Groceries:");
	   wattroff(w,A_UNDERLINE);
	   wscanw(w,"%f",&E.exp.BD.groceries);
	   if(E.exp.BD.groceries<=0)
	   {
	       for(int space=2;space<=55;space++)
		   mvwprintw(w,i,space,"%s","  ");
	       wattron(w,COLOR_PAIR(4));
	       mvwprintw(w,39,10,"%s","* Inappropriate Input.");
	       wattroff(w,COLOR_PAIR(4));
	       wrefresh(w);
	       goto BDG;
	   }
	   i++;
	   for(int space=2;space<=55;space++)
	       mvwprintw(w,39,space,"%s","  ");
	   wrefresh(w);

BDO:       wattron(w,A_UNDERLINE);
	   mvwprintw(w,i,y+t,"%s","Others:");
	   wscanw(w,"%f",&E.exp.BD.others);
	   if(E.exp.BD.others<=0)
	   {
	       for(int space=2;space<=55;space++)
		   mvwprintw(w,i,space,"%s","  ");
	       wattron(w,COLOR_PAIR(4));
	       mvwprintw(w,39,10,"%s","* Inappropriate Input.");
	       wattroff(w,COLOR_PAIR(4));
	       wrefresh(w);
	       goto BDO;
	   }
	   i++;
	   for(int space=2;space<=55;space++)
	       mvwprintw(w,39,space,"%s","  ");
	   wrefresh(w);

	   wattron(w,A_UNDERLINE);
	   mvwprintw(w,i++,y,"%s","POLICY DETAILS:");
	   mvwprintw(w,i++,y+t,"%s","Life Insurance:");
	   wattroff(w,A_UNDERLINE);
	   wscanw(w,"%f",&E.exp.PD.lifeins);
PDMI:      wattron(w,A_UNDERLINE);
	   mvwprintw(w,i,y+t,"%s","Medical Insurance:");
	   wattroff(w,A_UNDERLINE);
	   wscanw(w,"%f",&E.exp.PD.medicalins);
	   if(E.exp.PD.medicalins<=0)
	   {
	       for(int space=2;space<=55;space++)
		   mvwprintw(w,i,space,"%s","  ");
	       wattron(w,COLOR_PAIR(4));
	       mvwprintw(w,39,10,"%s","* Inappropriate Input.");
	       wattroff(w,COLOR_PAIR(4));
	       wrefresh(w);
	       goto PDMI;
	   }
	   i++;
	   for(int space=2;space<=55;space++)
	       mvwprintw(w,39,space,"%s","  ");
	   wrefresh(w);

PDM:       wattron(w,A_UNDERLINE);
	   mvwprintw(w,i,y+t,"%s","Motor Insurance");
	   wattroff(w,A_UNDERLINE);
	   wscanw(w,"%f",&E.exp.PD.motorins);
	   if(E.exp.PD.motorins<=0)
	   {
	       for(int space=2;space<=55;space++)
		   mvwprintw(w,i,space,"%s","  ");
	       wattron(w,COLOR_PAIR(4));
	       mvwprintw(w,39,10,"%s","* Inappropriate Input.");
	       wattroff(w,COLOR_PAIR(4));
	       wrefresh(w);
	       goto PDM;
	   }
	   i++;
	   for(int space=2;space<=55;space++)
	       mvwprintw(w,39,space,"%s","  ");
	   wrefresh(w);

PDO:       wattron(w,A_UNDERLINE);
	   mvwprintw(w,i,y+t,"%s","Others:");
	   wattroff(w,A_UNDERLINE);
	   wscanw(w,"%f",&E.exp.PD.others);
	   if(E.exp.PD.others<=0)
	   {
	       for(int space=2;space<=55;space++)
		   mvwprintw(w,i,space,"%s","  ");
	       wattron(w,COLOR_PAIR(4));
	       mvwprintw(w,39,10,"%s","* Inappropriate Input.");
	       wattroff(w,COLOR_PAIR(4));
	       wrefresh(w);
	       goto PDO;
	   }
	   i++;
	   for(int space=2;space<=55;space++)
	       mvwprintw(w,39,space,"%s","  ");
	   wrefresh(w);

	   wattron(w,A_UNDERLINE);
	   mvwprintw(w,i++,y+t,"%s","Do you have any Transitions (Debit) : ");
	   wattroff(w,A_UNDERLINE);
	   sw=menu(w,i-1,y+11*t,choice,2,ch,0);
	   i++;
	   int ac=0;
	   if(sw==i-2)
	   {
transactions:	echo();
		wattron(w,A_UNDERLINE);
		mvwprintw(w,i++,y,"%s","ACCOUNT:");
		mvwprintw(w,i++,y+t,"%s","Debit:");
		mvwprintw(w,i++,y+2*t,"%s","Receivers's ID:");
		wattroff(w,A_UNDERLINE);
		wgetstr(w,E.exp.AC.debit[ac].receiver_id);
date:		wattron(w,A_UNDERLINE);
		mvwprintw(w,i,y+2*t,"%s","Date of Transaction(dd/mm/yyyy):"); 
		wattroff(w,A_UNDERLINE);
		wscanw(w,"%s",&E.exp.AC.debit[ac].dt);
		if(datechange_cheak(E.exp.AC.debit[ac].dt)!=1)
		{
		    for(int j=2;j<=55;j++)
			mvwprintw(w,i,j,"%s","  ");
		    wattron(w,COLOR_PAIR(4));
		    mvwprintw(w,39,10,"%s","* Inappropriate Input.");
		    wattroff(w,COLOR_PAIR(4));
		    wrefresh(w);
		    goto date;
		}
		i++;
		for(int space=2;space<=55;space++)
		    mvwprintw(w,39,space,"%s","  ");
		wrefresh(w);
DA:		wattron(w,A_UNDERLINE);
		mvwprintw(w,i,y+3*t,"%s","Amount :");
		wattroff(w,A_UNDERLINE);
		wscanw(w,"%f",&E.exp.AC.debit[ac].amount);
		if(E.exp.AC.debit[ac].amount<=0)
		{
		    for(int space=2;space<=55;space++)
			mvwprintw(w,i,space,"%s","  ");
		    wattron(w,COLOR_PAIR(4));
		    mvwprintw(w,39,10,"%s","* Inappropriate Input.");
		    wattroff(w,COLOR_PAIR(4));
		    wrefresh(w);
		    goto DA;
		}
		i++;
		for(int space=2;space<=55;space++)
		    mvwprintw(w,39,space,"%s","  ");
		wrefresh(w);
		ac++;
		if(ac<=9)
		{
		    wattron(w,A_UNDERLINE);
		    mvwprintw(w,i++,y+2*t,"%s","Do you want to Continue : ");
		    wattroff(w,A_UNDERLINE);
		    sw=menu(w,i-1,y+9*t,choice,2,ch,0);
		    if(sw==i-3)
		    {
			i=i-11;
			for(int j=0;j<=12;j++)
			    for(int k=2;k<=55;k++)
				mvwprintw(w,i+j,k,"%s","  ");
			goto transactions;
		    }
		    else
		    {
			for(int j=ac;j<=9;j++)
			{
			    E.exp.AC.debit[j].amount=0;
			}
		    }
		}
		else
		{
		    for(int j=ac;j<=9;j++)
		    {
			E.exp.AC.debit[j].amount=0;
		    }
		}
	   }
	   else
	   {
	       for(int j=0;j<=9;j++)
	       {
		   E.exp.AC.debit[j].amount=0;
	       }
	   }




	   E.tax=taxcal(E);
	   wattron(w,A_UNDERLINE);
	   mvwprintw(w,i++,y,"%s","TAX:");
	   wattroff(w,A_UNDERLINE);
	   mvwprintw(w,i++,y,"%f",E.tax);
	   fwrite(&E,sizeof(E),1,p);
	   wattron(w,A_UNDERLINE);
	   mvwprintw(w,i++,y+t,"%s","Do you want to Continue : ");
	   wattroff(w,A_UNDERLINE);
	   sw=menu(w,i,y+7*t,choice,2,ch,0);
	   if(sw==i)
	   {
	       noecho();
	       i=k;
	       wclear(w);
	       wrefresh(w);
	       wattron(w,A_STANDOUT);
	       wattron(w,COLOR_PAIR(1));
	       wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
	       wattroff(w,COLOR_PAIR(1));
	       wattroff(w,A_STANDOUT);
	       echo();
	       keypad(w,TRUE);
	       wattron(w,A_ALTCHARSET);
	       wattron(w,A_UNDERLINE);
	       mvwprintw(w,3,10,"%s","Please enter the details of employees :");
	       wattroff(w,A_UNDERLINE);
	       wattroff(w,A_ALTCHARSET);
	       p=fopen(a,"ab");
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
	       goto here1;
	   }
	   fclose(p);

}


void TAX(WINDOW *w,char *a)
{
    char ID[20];
    FILE *p;
    int cmp;
    float tax;
    employee E;
    echo();
    wattron(w,A_BOLD);
    mvwprintw(w,2,34,"%s","ID :");
    wgetstr(w,ID);
    wattroff(w,A_BOLD);
    noecho();
    wrefresh(w);
    p=fopen(a,"rb");
   // rewind(p);
    fseek(p,0,0);
    while(fread(&E,sizeof(E),1,p)==1)
    {
	cmp=strcmp(E.ID,ID);
	if(cmp==0)
	{
	    tax=taxcal(E);
	    mvwprintw(w,4,10,"Tax to be paid by the Employee is %.2f ",tax);
	    wrefresh(w);
	    break;
	}
    }
    if(cmp!=0)
    {
	wattron(w,COLOR_PAIR(4));
	mvwprintw(w,5,10,"Employee Details not Avaliable.");
	wattroff(w,COLOR_PAIR(4));
    }
    wrefresh(w);
    fclose(p);
}

float taxcal(employee E)
{
    float gross_sal,policy,tax=0;
    policy=E.exp.PD.lifeins+E.exp.PD.medicalins+E.exp.PD.motorins+E.exp.PD.others;
    gross_sal=EstimateIncome(E.ID,E.year);
    gross_sal=gross_sal-policy;
    int i=0,j=0,s=1,k=0;
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
                       {2009,225000,0,300000,10,500000,20,30},
                       {2010,160000,0,300000,10,500000,20,30},
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
			     if(gross_sal>slab[i][s])
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
		     if(gross_sal>slab[i][s])
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
		     tax=tax+(gross_sal-slab[i][j])*(slab[i][k]/100);
		     if(k==s)
			     k=k-1;
		     else
			     k=k-2;
		     gross_sal=slab[i][j];
	     }
	     return tax;
}



float EstimateIncome(char ID[],int year)
{
	employee E;
	FILE *f=fopen("EmployeesB.txt","r+");
	float eincome=0;
	int i=0,flag=0;
	fread(&E,sizeof(employee),1,f);
	while(!(feof(f)))
	{
		if((strcmp(E.ID,ID)==0)&&E.year==year)
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
	eincome=eincome*12;
	fclose(f);
	return eincome;
}


//////////////////////////////////////////////
//////////////////////////////////////////////

int menu(WINDOW *w,int y,int x, char list[13][40],int n,int ch,int c)
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
		return y;
		break;
	}
	// now highlight the next item in the list.
	wattron( w, A_STANDOUT);
	sprintf(item, "%s",  list[i]);
	mvwprintw( w, i+y, x, "%s", item);
	wattroff( w, A_STANDOUT);

    }
}

int menu_month(WINDOW *w,int y,int x, char list[13][40],int n,int ch,int c,int a)
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
		return i;
		break;
	    case KEY_DOWN:
		i++;
		i = ( i>n-1 ) ? 0 : i;
		wattroff(w,COLOR_PAIR(c));
		wattroff(w,A_BOLD);
		return i;
		break;
	    case 10:
		if(i==12)
		{
		    getyx(w,y,x);
		    wattroff(w,COLOR_PAIR(c));
		    wattroff(w,A_BOLD);
		    return y;
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

int  datechange_cheak(char *str)
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


void display_id(WINDOW *w,employee E,char *a)
{
    FILE *p;
    WINDOW *w1;
    char ID[20];
    int y=2,x=2,t=4,s=2,cmp,cmp1,year,l,m,b;
    p=fopen(a,"rb");
    echo();
    wattron(w,A_BOLD);
    wattron(w,A_UNDERLINE);
    mvwprintw(w,y,60,"%s","ID :");
    wgetstr(w,ID);
    wattroff(w,A_BOLD);
    wattroff(w,A_UNDERLINE);
    wrefresh(w);
    rewind(p);
    fread(&E,sizeof(E),1,p);
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
    mvwprintw(w,y+3*s,x+10*t,"%s","Acc. No. :");
	    mvwprintw(w,y+3*s,x+12*t+1,"%s",E.acc_no);
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
			m=menu_month(w1,4,3,list,13,b,1,m-1);
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
			    rewind(p);
			    fread(&E,sizeof(E),1,p);
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
				fread(&E,sizeof(E),1,p);
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
		fread(&E,sizeof(E),1,p);
		while(!feof(p))
		{
		    cmp1=strcmp(E.ID,ID);
		    if(cmp1==0)
		    {
			if(E.year==year)
			    goto income;
		    }
		    fread(&E,sizeof(E),1,p);
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
	    rewind(p);
	    l++;
	    fread(&E,sizeof(E),1,p);
	    while(!feof(p))
	    {
		cmp1=strcmp(E.ID,ID);
		if(cmp1==0)
		{
		    for(int j=0;j<=9;j++)
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

		fread(&E,sizeof(E),1,p);
	    }
	    wrefresh(w);
	    wclear(w1);
	    wrefresh(w);
	    delwin(w1);
	    goto nextmonth;


	    break;
	}
	fread(&E,sizeof(E),1,p);

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

void FileEmployeeDetail(char *T,char *B)
{
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
	printf("The file does not exist\nPlease Create a file for Employees Details\n");
	exit(0);
    }
    if(f!=0)
	perror("\n");

    fp=fopen(B,"w+");
    if(fp==NULL)
    {
	printf("ERROR IN OPENING\n\n");

	exit(0);
    }

    for(int i=0;i<=5;i++)
	fgets(line,1000,f);
ID_onward:

    fscanf(f,"%s",E.ID);
    fscanf(f,"%s%s",E.name.init,E.name.surname);
    fscanf(f,"%d",&E.age);
    fscanf(f,"%s",E.gender);
    fscanf(f,"%s",E.acc_no);
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
    //E.tax=TaxCal(E);

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
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ANALYSIS FUNCTIONS/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void BillDetail(WINDOW *w,char *a )
{
    int i,j,current_year,diff_year=0;
    employee E;
    char ID[20];
    int y=2,x=2,t=4,l=0,efound=0;
    char Month[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    float month[12][6],year[20][5],section[5]={0,0,0,0,0};
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
		mvwprintw(w,y,x+7*t,"NAME : %s %s      AGE: %d     GENDER : %s     Acc. No. : %s",E.name.init,E.name.surname,E.age,E.gender,E.acc_no);
		wattroff(w,A_BOLD);
		y=y+2;
	    }
	    efound=1;
	    while(strcmp(E.ID,ID)==0 && !feof(f))
	    {
		for(j=0;j<diff_year;j++)
		    if(year[j][0]==E.year)
		    {
			//year[i][0]=E.year;
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
    if(efound!=0)
    {
    for(i=0;i<12;i++)
    {
	for(j=0;j<4;j++)
	    month[i][4]+=month[i][j];
	month[i][4]/=month[i][5];
    }
    wattron(w,A_UNDERLINE);
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
	}
    }
    y=y+3;
    wattron(w,A_UNDERLINE);
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
	    }
    y=y+3;
    wattron(w,A_UNDERLINE);
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
}
if(efound==0)
{
    mvwprintw(w,6,40,"%s","Employee Details Not Avaliable.");
}
}



void PolicyDetail(WINDOW *w,char *a)
{
    float year[20][6],sum;
    int i,j,diff_year=0,current_year;
    int x=2,y=2,t=4,efound=0;
    employee E;
    char ID[20];
    FILE *f=fopen(a,"rb");
    if(f==NULL)
    {
	mvwprintw(w,y,9*t,"%s","Sorry,couldnot find file.");
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
		mvwprintw(w,y,x+7*t,"NAME : %s %s      AGE: %d      GENDER : %s     Acc. No. : %s",E.name.init,E.name.surname,E.age,E.gender,E.acc_no);
		wattroff(w,A_BOLD);
		y=y+2;
	    }
	    efound=1;

	    while(strcmp(E.ID,ID)==0 && !feof(f))
	    {
		for(j=0;j<diff_year;j++)
		    if(year[j][0]==E.year)
		    {
			//year[i][0]=E.year;
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
    wattroff(w,A_UNDERLINE);
    wattroff(w,A_BOLD);
    for(i=0;year[i][0]!=0;i++)
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
    }
}



////////////////////////////////////////////////////////TRANSFER DAETAILS//////////////////////////////////////////////////////////////////////////////////

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

void DisplayTransferDetail_DEBIT(WINDOW *w,Transaction *S_root,char ID[10],int y)
{
    Transaction *traverse=S_root;
    int flag=0;
    float sum=0;
    int x=2,t=4,a,ch;
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
		mvwprintw(w,69,x+5*t,"%s","Press Enter to Go to Next Page");
		wscanw(w,"%d",ch);
		if(ch==10)
		{
		    for(int line=a;line<=69;line++)
			for(int space=1;space<=129;space++)
			    mvwprintw(w,line,space,"%s"," ");
		}
		y=10;
		
	    }
	    mvwprintw(w,y,x+4*t,"%s",traverse->ID);
	    mvwprintw(w,y,x+9*t,"%s %s",traverse->name.init,traverse->name.surname);
	    mvwprintw(w,y,x+16*t+2,"%s",traverse->dt);
	    mvwprintw(w,y,x+22*t,"%.2f",traverse->amount);
	    y=y+1;
	    traverse=traverse->right;
	}
	y=y+2;
	wattron(w,A_BOLD);
	mvwprintw(w,y,x+7*t,"You have sent Rs. %.2f amount.",sum);
	wattroff(w,A_BOLD);
    }
}
void DisplayTransferDetail_CREDIT(WINDOW *w,Transaction *R_root,char ID[10],int y)
{
    Transaction *traverse=R_root;
    int flag=0;
    float sum=0;
    int ch;
    int x=2,t=4,a;
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
	   /* if(y==37)
	    {
statement:      mvwprintw(w,69,x+5*t,"%s","Press Enter to Go to Next Page");
		wscanw(w,"%d",ch);
		if(ch==10)
		{
		    for(int line=a;line<=69;line++)
			for(int space=1;space<=129;space++)
			    mvwprintw(w,line,space,"%s"," ");
		}
	    }
	    else
		goto statement;*/
	    mvwprintw(w,y,x+4*t,"%s",traverse->ID);
	    mvwprintw(w,y,x+9*t,"%s %s",traverse->name.init,traverse->name.surname);
	    mvwprintw(w,y,x+16*t+2,"%s",traverse->dt);
	    mvwprintw(w,y,x+22*t,"%.2f",traverse->amount);
	    y++;
	    traverse=traverse->right;
	}
	y+=3;

	if(flag==1)
	{

	    wattron(w,A_BOLD);
	    mvwprintw(w,y,x+6*t,"You have received Rs. %.2f.",sum);
	    wattroff(w,A_BOLD);
	}
    }

}
void TransferDetail(WINDOW *w,char *a,int sw)
{
    Transaction *sender_root=NULL,*receiver_root=NULL,*sender,*receiver;
    employee E;
    int x=2,y=2,t=4,i;
    FILE *f=fopen(a,"rb");
    char ID[20];
    echo();
    wattron(w,A_BOLD);
    wattron(w,A_STANDOUT);
    mvwprintw(w,y++,15*t,"%s","ID:");
    wattroff(w,A_BOLD);
    wattroff(w,A_STANDOUT);
    wgetstr(w,ID);
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
	    DisplayTransferDetail_DEBIT(w,sender_root,ID,y);
	    break;
	case 2:
	    DisplayTransferDetail_CREDIT(w,receiver_root,ID,y);
	    break;
    }
    free(sender_root);
    free(receiver_root);
    fclose(f);
}



void TransferDetail_all(WINDOW *w,char *a,int sw)
{
    Transaction *sender_root=NULL,*receiver_root=NULL,*sender,*receiver;
    employee E;
    int x=2,y=2,t=4,i;
    FILE *f=fopen(a,"rb");
    fread(&E,sizeof(employee),1,f);
    wattron(w,A_BOLD);
    wattron(w,A_STANDOUT);
    mvwprintw(w,y,x+12*t,"%s","XXX TRANSACTION DETAILS XXX");
    wattroff(w,A_BOLD);
    wattroff(w,A_STANDOUT);
    y+=2;
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

    switch(sw)
    {
	case 1:
	    DisplayAllTransfer_DEBIT(w,sender_root,y);
	    break;
	case 2:
	   DisplayAllTransfer_CREDIT(w,receiver_root,y);
	    break;
    }
    free(sender_root);
    free(receiver_root);
    fclose(f);
}







Transaction* FillName(WINDOW *w,char *a,Transaction *root,int option,char *ID,int sw,int y)
{
    int x=2,t=4,a1=y,b;
    Transaction *traverse1=root,*traverse2;
    employee E;
    int flag=0,power,year,digit,i;
    FILE *f=fopen(a,"r+");
    if(f==NULL)
    {
	mvwprintw(w,y++,x+10*t,"%s","Sorry,Coulnot open file.");
	return root;
    }
/*    if(option==0 && sw==1)
    {
	echo();
	wattron(w,A_BOLD);
	wattron(w,A_STANDOUT);
	mvwprintw(w,y++,15*t,"%s","ID:");
	wattroff(w,A_BOLD);
	wattroff(w,A_STANDOUT);
	wgetstr(w,ID);
    }*/
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
		    mvwprintw(w,y++,x+12*t,"%s","Name(First & Last) : ");
		wattroff(w,A_BOLD);
		    wscanw(w,"%s %s",E.name.init,E.name.surname);
		    strcpy(traverse2->name.init,E.name.init);
		    strcpy(traverse2->name.surname,E.name.surname);
age:		wattron(w,A_BOLD);
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
		    mvwprintw(w,y++,x+12*t,"%s","Account no :");
		wattroff(w,A_BOLD);
		    wscanw(w,"%s",E.acc_no);
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
		    mvwprintw(w,y++,x+12*t,"%s","Account No :");
		    wattroff(w,A_BOLD);
		    wscanw(w,"%s",E.acc_no);
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



void DisplayAllTransfer_DEBIT(WINDOW *w,Transaction *S_root,int y)
{
    int x=2,t=4;
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
		}
		traverse1=traverse1->right;
		y+=2;
	}
}
void DisplayAllTransfer_CREDIT(WINDOW *w,Transaction *R_root,int y)
{
    int x=2,t=4;
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

	}
	traverse1=traverse1->right;
        y+=2;
    }

}
/////////////////////////////////////////////////////////////////////////////MAIN FUNCTION//////////////////////////////////////////////////////////////////////////////////
void main_fun(char *a,char *b)
{
    FileEmployeeDetail(b,a);
    WINDOW *w;
    int sw,ch,x=2,y=1,i,m;
    employee E;
    FILE *p;
    char item[4];
    char list[13][40]={"Enter the Details of an Employee.","Income Tax Department.","Display the Details of the Employees.","Analysis","EXIT"};
    char list1[13][40]={"New Employee.","Update an Existing One.","Back"};
    char list2[13][40]={"Transactions.","Policy Details.","Back"};
    char list3[13][40]={"Expensies.","Policy.","Transaction","BACK"};
    char list4[13][40]={"Indivisiual","Group","BACK"};
    char list5[13][40]={"Debit.","Credit.","BACK"};
    initscr();
    start_color();
    init_pair(0,COLOR_WHITE,COLOR_BLACK);
    init_pair(1,COLOR_GREEN,COLOR_BLACK);
    init_pair(2,COLOR_CYAN,COLOR_BLACK);
    init_pair(3,COLOR_MAGENTA,COLOR_BLACK);
    init_pair(4,COLOR_RED,COLOR_BLACK);
starting:
    w=newwin(10,80,18,33);
    wattron(w,COLOR_PAIR(2));
    wattron(w,A_REVERSE);
    wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
    wattroff(w,A_REVERSE);
    wattroff(w,COLOR_PAIR(2));
    wattron(w,A_BOLD);
    wattron(w,A_UNDERLINE);
    wattron(w,COLOR_PAIR(1));
    mvwprintw(w,1,18,"%s","*** FINANCIAL PLANNER OF AN INDIVIDIUAL ***");
    wattroff(w,COLOR_PAIR(1));
    wattroff(w,A_UNDERLINE);
    wattron(w,A_BOLD);
    m=menu(w,y+2,x,list,5,ch,2);
    wclear(w);
    wrefresh(w);
    delwin(w);
    sw=m-2;
    switch(sw)
    {
prev1:	case 1:
	w=newwin(5,70,20,35);
	wattron(w,COLOR_PAIR(2));
	wattron(w,A_REVERSE);
	wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
	wattroff(w,A_REVERSE);
	wattroff(w,COLOR_PAIR(2));
	m=menu(w,y,x,list1,3,ch,2);
	wclear(w);
	wrefresh(w);
	delwin(w);
	sw=m;
	switch(sw)
	{
	    case 1:
		w=newwin(40,75,0,45);
		wattron(w,COLOR_PAIR(2));
		wattron(w,A_REVERSE);
		wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
		wattroff(w,A_REVERSE);
		wattroff(w,COLOR_PAIR(2));
		Employee_Detail(w,E,a);
		wclear(w);
		wrefresh(w);
		delwin(w);
		goto prev1;
prev12:		    case 2:
		w=newwin(6,70,20,35);
		wattron(w,COLOR_PAIR(2));
		wattron(w,A_REVERSE);
		wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
		wattroff(w,A_REVERSE);
		wattroff(w,COLOR_PAIR(2));
		m=menu(w,y,x,list2,3,ch,2);
		wclear(w);
		wrefresh(w);
		delwin(w);
		sw=m;
		switch(sw)
		{
		    case 1:
			//		transation(w,E,argv[1]);
			wgetch(w);
			goto prev12;
		    case 2:
			goto prev12;
		    case 3:
			goto prev1;
		}
	    case 3:
		goto starting;
		break;
	}

	case 2:
	w=newwin(10,80,10,10);
	wattron(w,COLOR_PAIR(2));
	wattron(w,A_STANDOUT);
	wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
	wattroff(w,COLOR_PAIR(2));
	wattroff(w,A_STANDOUT);
	TAX(w,a);
	wgetch(w);
	wclear(w);
	wrefresh(w);
	delwin(w);
	goto starting;
	break;
	case 3:
	w=newwin(40,130,0,0);
	wattron(w,COLOR_PAIR(2));
	wattron(w,A_REVERSE);
	wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
	wattroff(w,A_REVERSE);
	wattroff(w,COLOR_PAIR(2));
	display_id(w,E,a);
	wrefresh(w);
	wgetch(w);
	wclear(w);
	wrefresh(w);
	delwin(w);
	goto starting;
	case 4:
prev4:	w=newwin(6,70,20,35);
	wattron(w,COLOR_PAIR(2));
	wattron(w,A_REVERSE);
	wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
	wattroff(w,A_REVERSE);
	wattroff(w,COLOR_PAIR(2));
	m=menu(w,y,x,list3,4,ch,2);
	wclear(w);
	wrefresh(w);
	delwin(w);
	sw=m;
	switch(sw)
	{
	    case 1:
		w=newwin(40,130,0,0);
		wattron(w,COLOR_PAIR(2));
		wattron(w,A_REVERSE);
		wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
		wattroff(w,A_REVERSE);
		wattroff(w,COLOR_PAIR(2));
		BillDetail(w,a);
		wrefresh(w);
		wgetch(w);
		wclear(w);
		wrefresh(w);
		delwin(w);
		goto prev4;
	    case 2:
		w=newwin(40,130,0,0);
		wattron(w,COLOR_PAIR(2));
		wattron(w,A_REVERSE);
		wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
		wattroff(w,A_REVERSE);
		wattroff(w,COLOR_PAIR(2));
		PolicyDetail(w,a);
		wrefresh(w);
		wgetch(w);
		wclear(w);
		wrefresh(w);
		delwin(w);
		goto prev4;
	    case 3:

prev43:		w=newwin(6,70,20,35);
		wattron(w,COLOR_PAIR(2));
		wattron(w,A_REVERSE);
		wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
		wattroff(w,A_REVERSE);
		wattroff(w,COLOR_PAIR(2));
		m=menu(w,y,x,list4,3,ch,2);
		wclear(w);
		wrefresh(w);
		delwin(w);
		sw=m;
		switch(sw)
		{
		    case 1:
prev431:			w=newwin(6,70,20,35);
			wattron(w,COLOR_PAIR(2));
			wattron(w,A_REVERSE);
			wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
			wattroff(w,A_REVERSE);
			wattroff(w,COLOR_PAIR(2));
			m=menu(w,y,x,list5,3,ch,2);
			wclear(w);
			wrefresh(w);
			delwin(w);
			sw=m;
			switch(sw)
			{
			    case 1:
				w=newwin(40,130,0,0);
				wattron(w,COLOR_PAIR(2));
				wattron(w,A_REVERSE);
				wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
				wattroff(w,A_REVERSE);
				wattroff(w,COLOR_PAIR(2));
				TransferDetail(w,a,sw);
				wrefresh(w);
				wgetch(w);
				wclear(w);
				wrefresh(w);
				delwin(w);
				goto prev431;
			    case 2:
				w=newwin(40,130,0,0);
				wattron(w,COLOR_PAIR(2));
				wattron(w,A_REVERSE);
				wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
				wattroff(w,A_REVERSE);
				wattroff(w,COLOR_PAIR(2));
				TransferDetail(w,a,sw);
				wrefresh(w);
				wgetch(w);
				wclear(w);
				wrefresh(w);
				delwin(w);
				goto prev431;
			    case 3:
				goto prev43;
			}
		    case 2:
prev432:		w=newwin(6,70,20,35);
			wattron(w,COLOR_PAIR(2));
			wattron(w,A_REVERSE);
			wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
			wattroff(w,A_REVERSE);
			wattroff(w,COLOR_PAIR(2));
			m=menu(w,y,x,list5,3,ch,2);
			wclear(w);
			wrefresh(w);
			delwin(w);
			sw=m;
			switch(sw)
			{
			    case 1:
				w=newwin(40,130,0,0);
				wattron(w,COLOR_PAIR(2));
				wattron(w,A_REVERSE);
				wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
				wattroff(w,A_REVERSE);
				wattroff(w,COLOR_PAIR(2));
				TransferDetail_all(w,a,sw);
				wrefresh(w);
				wgetch(w);
				wclear(w);
				wrefresh(w);
				delwin(w);
				goto prev432;
			    case 2:
				w=newwin(40,130,0,0);
				wattron(w,COLOR_PAIR(2));
				wattron(w,A_REVERSE);
				wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
				wattroff(w,A_REVERSE);
				wattroff(w,COLOR_PAIR(2));
				TransferDetail_all(w,a,sw);
				wrefresh(w);
				wgetch(w);
				wclear(w);
				wrefresh(w);
				delwin(w);
				goto prev432;
 			    case 3:
				goto prev43;
			}
		    case 3:
			goto prev4;
		}
	    case 4:
		goto starting;
	}
	case 5:
	goto EXIT;
    }
EXIT:
    // mvwprintw(w,
    refresh();
    endwin();
}



/*
int password(char *pass)
{
    char *str="Sai Ram";
    if(strcmp(pass,str)==0)
	return(1);
    else
	return(0);
}


char *change_password()
{
    int x=2,t=4,y=2,confirm,l1,l2;
    char pass[15],npass1[15],npass2[15];
oldpass:rintw(w,y,x+t,"%s","Old Password :");
    wgetstr(w,pass);
    confirm=password(pass);
    y++;
    if(confirn==1)
    {
newpass:l1=y;
	mvwprintw(w,y++,x+t,"%s","New Password :");
	wgetstr(npass1);
	mvwprintw(w,y++,x+t,"%s","Confirm Password :");
	wgetstr(wpass2);
	l2=y;
	if(strcmp(npass1,npass2)!=0)
	{
	    for(int line=l1;line<=l2;line++)
		for(int space=1;space<=30,space++)
		    mvwprintw(w,linw,space,"%s"," ");
	    goto new_pass;
	}
	else
	{
	//store the pass word
	}
    }
    else
	goto oldpass;
}

*/
