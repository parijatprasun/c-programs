/**************************************************
 * Program: age.c
 * Author: Parijat Prasun Pal
 * Purpose: This program is meant to give the age 
 * 	of the user on a date given.
 *************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char date[12];	/* date on which age is needed */
	char dob[12];	/* users date of birth */

	int dob_day;	/* day part of date of birth */
	int dob_month;	/* month part of date of birth */
	int dob_year;	/* year part of date of birth */
	
	int day;	/* day part of given date */
	int month;	/* month part of given date */
	int year;	/* year part of given date */

	int age_day;	/* day part of age */
	int age_month;	/* month part of age */
	int age_year;	/* year part of age */

	int add=0;	/* a term to manage days for different months */

	/* accept user's date of birth */
	printf("\nPlease enter your Date of Birth\n");
	printf("(in \'DD MM YYYY\' format): ");
	fgets(dob,sizeof(dob),stdin);
	dob[strlen(dob)-1]='\0';
	sscanf(dob,"%d %d %d",&dob_day,&dob_month,&dob_year);
	
	/* accept the date */
	printf("\nPlease enter the date on which you want your age\n");
	printf("(in \'DD MM YYYY\' format): ");
	fgets(date,sizeof(date),stdin);
	date[strlen(date)-1]='\0';
	sscanf(date,"%d %d %d",&day,&month,&year);
	
	printf("\n%d %d %d\n",day,month,year);
	printf("%d %d %d\n",dob_day,dob_month,dob_year);
	/* calculate age by subtraction */
	if(day<dob_day){
		if(month==4||6||9||11) add=30; /* April,June,Sept,Nov */ 
		/* Jan,Mar,May,July,Aug,Oct,Dec */
		if(month==1||3||7||8||10||12) add=31;
		if(month==2){			/* February */
			if(year%4 == 0) add=29; /* Leap year */
			else add=28;
		}
		age_day=(day+add)-dob_day;
		month -= 1;
	}else
		age_day=day-dob_day;
	
	if(month<dob_month){
		age_month=(month+12)-dob_month;
		year -= 1;
	}else
		age_month=month-dob_month;
	
	if(year<dob_year){
		printf("\nPlease be serious!\n");
	}else
		age_year=year-dob_year;

	/* print the result */
	printf("\nYour age: ");
	printf("%d Years %d Months %d Days",age_year,age_month,age_day);

	puts(" ");
	return 0;
}
