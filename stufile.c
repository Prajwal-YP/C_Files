/*
	Program Name	:	stufile.c
	Author			:	Prajwal Y P
	Task			:	To store and fetch Student details from Files.
*/

#include<stdio.h>
#include<conio.h>

struct student
{
	int rollno;
	char name[20]; 
	float average;
};
typedef struct student stu;

main()
{
	int c;
	void store();
	void fetch();
		
while(1)
{
	printf("\nMENU :");
	printf("\n----");
	printf("\n1. Store");
	printf("\n2. Fetch");
	printf("\n3. Exit");
	printf("\nEnter the Choice : ");
	scanf("%d",&c);
	
	switch(c)
	{
		case 1:
				store();
				printf("\n\n\t\t\tSUCCESSFULLY STORED");
				getch();
				system("cls");
				break;
				
		case 2:
				fetch();
				printf("\n\n\t\t\tSUCCESSFULLY FETCHED");
				getch();
				system("cls");
				break;
		case 3:
				printf("\n\n\t\t\tSUCCESSFULLY TERMINATED !!\n\n");
				exit(0);
		default :
				printf("\n\n\t\t\tINVALID CHOICE !!");
				getch();
				system("cls");				
	}
}	
		
	printf("\n\n---------------------------------------------------\n\n");
}

//Storing Student details to files VIA structures
void store()
{
	int i,n;
	FILE *fp;
	
	printf("\nEnter total number of students : ");
	scanf("%d",&n);
	stu s[n];
	
	fp=fopen("student.txt","a");
	for(i=0;i<n;i++)
	{
		printf("\nEnter student-%d details : ",i+1);
		printf("\n\nRoll no       : ");
		scanf("%d",&s[i].rollno);
		printf("\nName          : ");
		fflush(stdin);
		gets(s[i].name);
		printf("\nAverage Marks : ");
		scanf("%f",&s[i].average);
		printf("\n------------------------\n");
		
		fprintf(fp,"Roll-Number   :%d\n",s[i].rollno);
		fprintf(fp,"Name          :%s\n",s[i].name);
		fprintf(fp,"Average-Marks :%f\n",s[i].average);
		fprintf(fp,"-----------------------------------------\n");
	}
	
	fclose(fp);
	fp=NULL;
}

//Fetching student details VIA files
void fetch()
{
	char buf[200];
	FILE *fp;
	
	fp=fopen("student.txt","r");
	
	if(fp==NULL)
	{
		printf("\nStudents details not Entered Yet !!");
		return;
	}
	
	printf("\n\n");
	while( fscanf(fp,"%s",buf) !=EOF )
	{
		printf("%s\n",buf);
	}
	fclose(fp);
	fp=NULL;
}
