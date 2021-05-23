// Program for the database of oxygen supply for hospitals and from manfacturing companies.
// Uses the concept of single linked list.
#include<stdio.h>
#include<string.h>
#include<malloc.h>
// Algorithm for hospitals
struct node1{
	char loc1[100];
	char name1[1000];
	int bed1;
	int pat1;
	float amo_oxy1;
	struct node1 *next1;
}*temp1=NULL,*head1=NULL,*p1=NULL;

// Algorithm for companies. 
struct node2{
	char loc2[100];
	char name2[1000];
	float cap;
	int time;
	int no_cyl;
	float cost2;
	struct node2 *next2;
}*temp2=NULL,*head2=NULL,*p2=NULL;

//Structure is defined for storing the user datas in the form of 2-D array
//Structure is named as "Details" and has following members like name, age, choice and date of vaccination, address, etc...

struct details{
	char name[30],ast[30],ard[30],aci[30],vac[30];
	int sno[30],age[30],ch[30],d[30],m[30],y[30],nd[30],adn[30];
}abc;
 
// programs starts..

void inserthos(char*hl,int bd1,int pt1, float oxy,char*nma1){
	temp1=(struct node1*)malloc(sizeof(struct node1));
	strcpy(temp1->loc1,hl);
	temp1->bed1=bd1;
	temp1->pat1=pt1;
	temp1->amo_oxy1=oxy;
	strcpy(temp1->name1,nma1);
	temp1->next1=NULL;
	
	if(head1==NULL){
		head1=temp1;
		return ;
	}
	p1=head1;
	while(p1->next1!=NULL){
		p1=p1->next1;
	}
	p1->next1=temp1;
	printf(" \n node entered..");
	printf("\n---------------------------------------------------------------------------\n");
}

void insertcom(char*cl,float cp,int tm,int cy,float cos2,char*nma2){
	
	temp2=(struct node2*)malloc(sizeof(struct node2));

	strcpy(temp2->loc2,cl);
	strcpy(temp2->name2,nma2);
	temp2->cap=cp;
	temp2->time=tm;
	temp2->no_cyl=cy;
	temp2->cost2=cos2;
	temp2->next2=NULL;
	if(head2==NULL){
		head2=temp2;
		return ;
	}
	p2=head2;
	while(p2->next2!=NULL){
		p2=p2->next2;
	}
	p2->next2=temp2;
	printf(" \n node entered..");
	printf("\n---------------------------------------------------------------------------\n");
}

void displayhos(){
    int c=0;
	if(head1==NULL){
		printf(" \n sorry! the list of hospital is empty..");
		return ;
	}
	p1=head1;
	printf(" \n The details of the hospitals are : ");
	while(p1!=NULL){
		c++;
		printf(" \n-----------------%d.,HOSPITAL------------------",c);
		printf(" \n NAME OF THE HOSPITAL\t\t\t:%s",p1->name1);
		printf(" \n LOCATION\t\t\t\t:%s",p1->loc1);
		printf(" \n NUMBER OF BEDS\t\t\t\t:%d per patient",p1->bed1);
		printf(" \n NUMBER OF PATIENTS ADMITTED\t\t:%d",p1->pat1);
		printf(" \n AMOUNT OF OXYGEN REQUIRED\t\t:%f litres",p1->amo_oxy1);
		p1=p1->next1;
		
		
	}
	printf("\n---------------------------------------------------------------------------\n");
}

void displaycom(){
	 int c=0;
	if(head2==NULL){
		printf(" \n sorry! the list of companies is empty..");
		return ;
	}
	p2=head2;
	printf(" \n The details of the companines are : ");
	while(p2!=NULL){
		c++;
		printf(" \n-----------------%d.,COMPANIES------------------",c);
		printf(" \n NAME OF THE COMPANY\t\t:%s",p2->name2);
		printf(" \n LOCATION\t\t\t:%s",p2->loc2);
	    printf(" \n CAPACITY OF OXYGEN\t\t:%f litres",p2->cap);
	    printf(" \n TIME TAKEN FOR DELIVERY\t:%d hours",p2->time);
		printf(" \n NUMBER OF CYLINDERS\t\t:%d tanks",p2->no_cyl);
		printf(" \n TOTAL COST\t\t\t:Rs. %f /-",p2->cost2);
		p2=p2->next2;
}
printf("\n---------------------------------------------------------------------------\n");}


void updatehos(){
	int c=0;
	if(head1==NULL){
		printf(" \n sorry! the list of hospital is empty..");
		return ;
	}
	p1=head1;
	printf(" \n The details of the hospitals which in need of oxygen are : ");
	while(p1!=NULL){
		c++;
		if(p1->amo_oxy1<100000){
		
	    printf(" \n-----------------%d.,HOSPITAL------------------",c);
		printf(" \n NAME OF THE HOSPITAL\t\t\t:%s",p1->name1);
		printf(" \n LOCATION\t\t\t\t:%s",p1->loc1);
		printf(" \n NUMBER OF BEDS\t\t\t\t:%d per patient",p1->bed1);
		printf(" \n NUMBER OF PATIENTS ADMITTED\t\t:%d",p1->pat1);
		printf(" \n AMOUNT OF OXYGEN REQUIRED\t\t:%f litres",p1->amo_oxy1);
		p1=p1->next1;}
		else{
			printf(" \n No hospital is in need of oxygen at present  ");
			return;
		}	
	}
	printf("\n---------------------------------------------------------------------------\n");
}

void updatecom(){
	int c=0;
	if(head2==NULL){
		printf(" \n sorry! the list of companies is empty..");
		return ;
	}
	p2=head2;
	printf(" \n The details of the companines which are ready to supply oxygen  are : ");
	while(p2!=NULL){
		c++;
		if(p2->cap>10000){
		
		printf(" \n-----------------%d.,COMPANIES------------------",c);
			printf(" \n NAME OF THE COMPANY\t\t:%s",p2->name2);
		printf(" \n LOCATION\t\t\t:%s",p2->loc2);
	    printf(" \n CAPACITY OF OXYGEN\t\t:%f litres",p2->cap);
	    printf(" \n TIME TAKEN FOR DELIVERY\t:%d hours",p2->time);
		printf(" \n NUMBER OF CYLINDERS\t\t:%d tanks",p2->no_cyl);
		printf(" \n TOTAL COST\t\t\t:Rs. %f /-",p2->cost2);
		p2=p2->next2;
}
       else{ printf(" \n No company is not ready to supply oxygen at present ..");
       return;
	   }}
printf("\n---------------------------------------------------------------------------\n");
}

//total no. of cylinder for supply..
void cylinder(){ int nom = 0;
	if(head2==NULL){
		printf(" \n sorry! the list of companies is empty..");
		return ;
	}
	p2=head2;
	printf(" \n Total no. of cylinder manufactured : \t ");
	while(p2!=NULL){
		
	    nom= nom+p2->no_cyl;
	    p2=p2->next2;
}	printf("%d",nom);
printf("\n---------------------------------------------------------------------------\n");	
}

// mailing services..
void mail(){
	FILE *sd;
	sd = fopen("MAIL.html","w+");
	char ml[500] = "https://mail.google.com/mail/u/0/?tab=rm&ogbl#inbox?compose=CllgCJfqccLLxKsVhhhGBBkmBvNQLKptVdVlvxZscTRFlzdpklgNFpKzChzhHPlbXrRndhPJzfg";
	fprintf(sd,"Open the link :\n %s",ml);
	fclose(sd);
	printf("\n---------------------------------------------------------------------------\n");
}

//Function tail is defined to get the details of the users and store the datas in the Structure details defined below

void tails(){
	char name[500],file[1000];
	int i,x,nd,j,snum;
	FILE *df;
	
// Number of patients is obtained and their  details are collected follwingly

	printf("Enter the number of patients... ");
	scanf("%d",&x);
	printf("Enter the details...\n");
	
//using the number of patients, a for loop is initiated to obtain the details of given number of patients
//for entered patients details like Serial number, name, age,choice of vaccine, address, date for first dose of vaccine is collected

	for(i=0;i<x;i++){
		printf(" \n Enter the file name : ");
		scanf("%s",file);
		strcat(file,".txt");
		df = fopen(file,"w+");
		
		printf("Enter serial number... ");
		scanf("%d",&abc.sno[i]);
		fprintf(df,"%d",abc.sno[i]);
		printf("Enter name... ");
		scanf("%s", abc.name);
		fprintf(df,"%s",abc.name);
		printf("Enter age... ");
		scanf("%d",&abc.age[i]);
		fprintf(df,"%d",abc.age[i]);
		printf("Enter your Address :\n ");
		printf("Door No. ...");
		scanf("%d",&abc.adn[i]);
		fprintf(df,"%d",abc.adn[i]);
		printf("Street ... ");
		scanf("%s", abc.ast);
		fprintf(df,"%s",abc.ast);
		printf("Road/Locality ...");
		scanf("%s", abc.ard);
		fprintf(df,"%s",abc.ard);
		printf("City ...");
		scanf("%s", abc.aci);
		fprintf(df,"%s",abc.aci);
		printf("State ...");
		scanf("%s", abc.ast);
		fprintf(df,"%s",abc.ast);
		printf("Enter choice of vaccine... \n1.Covisheild\n2.Cowaxine\n3AstraZeneca\n4.Sputnik V");
		scanf("%d",&abc.ch[i]);
		fprintf(df,"%d",abc.ch[i]);
		printf("Enter date of vaccination... ");
		scanf("%d%d%d",&abc.d[i],&abc.m[i],&abc.y[i]);
		fprintf(df,"%d%d%d",abc.d[i],abc.m[i],abc.y[i]);
		
//Depending upon the choice entered, if-else case is used to store the name of the vaccine name in the database
//Choice 1 for Covishield, Choice 2 for Cowaxin, choice 3 for Astrazeneca, choice 4 for Sputnik V
		
		if(abc.ch[i]==1)
		    {abc.vac=="Covisheild";
		    fprintf(df,"%s",abc.vac);}
		else if(abc.ch[i]==2)
			{abc.vac=="Cowaxin";
			fprintf(df,"%s",abc.vac);}
		else if(abc.ch[i]==3)
		{	abc.vac=="Astrazenaca";
			fprintf(df,"%s",abc.vac);}
		else if(abc.ch[i]==4)
		{	abc.vac=="Sputnik V";
			fprintf(df,"%s",abc.vac);}
		
//As per GOI rules, there is a dose gap of 16 weeks for Covishield and Cowaxine , 12 weeks for Astrazenca and Sputnik V
//Thus, the date for second dose of Vaccine is assigned and stored in the database corresponding to each of the patients

//Second dose date is assigned for the Covishield and Cowzine followingly
		if((abc.ch[i]==1) || (abc.ch[i]==2))
		{
			if(abc.m[i]<9)
			{
				abc.nd[i] = abc.m[i] + 4;
			}
			else if(abc.m[i]==9)
			{
				abc.nd[i] = 01;
				abc.y[i]++;
			}
			else if (abc.m[i]==10)
			{
				abc.nd[i] = 02;
				abc.y[i]++;
			}
			else if (abc.m[i]==11)
			{
				abc.nd[i] = 03;
				abc.y[i]++;
			}
			else if (abc.m[i]==12)
			{
				abc.nd[i] = 04;
			
				abc.y[i]++;
			} 			
		}
		
//Second dose date for Astrazeneca and Sputnik V is assigned followingly
		if(abc.ch[i]==3 || abc.ch[i]==4)
		{ printf(" \n ------------------");
			if(abc.m[i]<10)
			{
				abc.nd[i] = abc.m[i] + 3;
			}
			else if(abc.m[i]==10)
			{
				abc.nd[i] = 01;
				abc.y[i]++;
			}
			else if (abc.m[i]==11)
			{
				abc.nd[i] = 02;
				abc.y[i]++;
			}
			else if (abc.m[i]==12)
			{
				abc.nd[i] = 03;
				abc.y[i]++;
			}
			
		}
		
	}
	
//After the databse is created, its enough for the patient's name or serial number to be collected

	printf("\n\nEnter your name...");
	scanf("%s", name);
	printf("\nEnter serial number ...");
	scanf("%d",&snum);
	for(i=0;i<x-1;i++){

//With the name and serial , its is compared with all the names and serial numbers from the database
//If either name or serial number matches then the corresponding patient's details is displayed including the date for the secind dose of the vaccine

	if ((abc.sno[i]==snum )|| (strcmp(abc.name,name)==0))
	{
	//	printf("\n%s%d%d\n\n",abc.name,abc.age[i],abc.ch[i]);
		printf("Name ... %s\n",abc.name);
		printf("Age ...%d\n",abc.age[i]);
		printf("Your are supposed to take second dose of %s on %d / %d / %d ",abc.vac,abc.d[i],abc.nd[i],abc.y[i]);
	}
	}
	return;
}


// driver code..
int main(){
	//file operations..
	FILE *fp[10];
    FILE *pf[10];

	
	
	int n,i,bed1,pati,m,tim,cyl;
	char ch1[100],ch2[100],nm1[1000],nm2[1000],path1[1000],path2[1000],YS[10];
	float ox,capi,cot2;
	printf("\n Enter the number of hospitals to insert : ");
	scanf("%d",&n);
	printf(" \n Enter the details now..");
	for(i=0;i<n;i++){
		printf(" \n Enter the directory path to save  the file : ");
		scanf("%s",path1);
		strcat(path1,".txt");
		fp[i]=fopen(path1,"w+");
		printf(" \n Enter the name of the hospital (char) : ");
		scanf("%s",nm1);
		printf(" \n Enter the location (char) : ");
		scanf("%s",ch1);
		printf(" \n Enter the number of beds (int) : ");
		scanf("%d",&bed1);
		printf(" \n Enter the number of patients (int) : ");
		scanf("%d",&pati);
		printf(" \n Enter the amount of oxygen (float) : ");
		scanf("%f",&ox);
		fprintf(fp[i],"Name of the hospital\t\t\t\t\t\t:%s\nName of the locationt\t\t\t\t\t\t:\%s\nNumber of beds\t\t\t\t\t\t\t:%d per person \nNumber of patients\t\t\t\t\t\t:%d\nAmount of Oxygen\t\t\t\t\t\t:%f litres",nm1,ch1,bed1,pati,ox);
		fclose(fp[i]);
		inserthos(ch1,bed1,pati,ox,nm1);	
		//continue;
	}
	printf(" \n Enter the number of companies to insert : ");
	scanf("%d",&m);
	printf(" \n Enter the details now..");
	for(i=0;i<m;i++){
		printf(" \n Enter the directory path to save  the file : ");
		scanf("%s",path2);
		strcat(path2,".txt");
		pf[i]=fopen(path2,"w+");
		printf(" \n Enter the name of the company (char) : ");
		scanf("%s",nm2);
	    printf(" \n Enter the location (char) : ");
		scanf("%s",ch2);
		printf(" \n Enter the capacity of oxygen (float) : ");
		scanf("%f",&capi);
		printf(" \n Enter the time taken for travelling (int) : ");
		scanf("%d",&tim);
		printf(" \n Enter the number of cylinder (int) : ");
		scanf("%d",&cyl);
		printf(" \n Enter the cost (float) : ");
		scanf("%f",&cot2);
		fprintf(pf[i],"Name of the Company\t\t\t\t\t\t:%s\nName of the location\t\t\t\t\t\t:%s\nCapacity of oxygen\t\t\t\t\t\t:%f litres\nTime taken for travelling\t\t\t\t\t:%d hours\nNumber of cylinder\t\t\t\t\t\t:%d tanks\nCost\t\t\t\t\t\t\t\t:Rs. %f /-",nm2,ch2,capi,tim,cyl,cot2);
	    fclose(pf[i]);
		insertcom(ch2,capi,tim,cyl,cot2,nm2);
	    //continue;	
	}
	displayhos();
	displaycom();
	cylinder();
	updatehos();
	updatecom();
	printf("\n Do yo want to continue to mail : y|n ");
	scanf("%s",YS);
	if ( strcmp(YS,"y") == 0){
		printf(" \n Link to mail will be alloted in the file name : MAIL \n");
	    mail();	
	}
	else
	   printf("\n You have responded not to mail \n");
	printf("\n  _________________________________________________________________________________  \n");
	printf("\n\t\tVACCINATION DATABASE\n\n");
	tails();
	return 0;
}

