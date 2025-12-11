#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
int id;
char name[20];
float marks;
struct student *next;
}SLL;
///////////////////////////////////////////////
void add_node(SLL **hptr)
{
SLL *new;
new=malloc(sizeof(SLL));
printf("Enter the student id ,name and marks:\n");
scanf("%d %s %f",&new->id,new->name,&new->marks);
new->next=*hptr;
*hptr=new;
}
//////////////////////////////////////////////
void print_node(SLL *hptr)
{
	if(hptr==0)
	{
	printf("no nodes are available:\n");
	return;
	}
while(hptr)
{
printf("%d %s %f:\n",hptr->id,hptr->name,hptr->marks);
hptr=hptr->next;
}
}
////////////////////////////////////////////////////////
int count_node(SLL *hptr)
{
	if(hptr==0)
	{
	printf("no nodes are available:\n");
	return 0;
	}
int c=0;
	while(hptr)
	{
	c++;
	hptr=hptr->next;
	}
return c;
}
///////////////////////////////////////
void add_end(SLL **hptr)
{
SLL *new;
new=malloc(sizeof(SLL));
printf("Enter the student id ,name and marks:\n");
scanf("%d %s %f",&new->id,new->name,&new->marks);
new->next=0;
if(*hptr==0)
*hptr=new;
else
{
SLL *last;
last=*hptr;
while(last->next!=0)
	last=last->next;
last->next=new;
}

}
///////////////////////////////////////////
void add_middle(SLL **hptr)
{

SLL *new;
new=malloc(sizeof(SLL));
printf("Enter the student id ,name and marks:\n");
scanf("%d %s %f",&new->id,new->name,&new->marks);
if(*hptr==0||(new->id<(*hptr)->id))
{
new->next=*hptr;
*hptr=new;
}
else
{
SLL *dup=*hptr;
while((dup->next!=0)&&(new->id>dup->next->id))
	dup=dup->next;
new->next=dup->next;
dup->next=new;
}
}
/////////////////////////////////////////////////
void save_file(SLL *hptr)
{
	
if(hptr==0)
{
	printf("no nodes are available:\n");
return;
}
FILE *fp;
fp=fopen("data","a");
while(hptr)
{
fprintf(fp,"%d %s %f\n",hptr->id,hptr->name,hptr->marks);
hptr=hptr->next;
}

fclose(fp);


}
///////////////////////////////////////////////////
void read_file(SLL **hptr)
{
SLL *new,*dup;
FILE* fp;
fp=fopen("data","r");
while(1)
{
new=malloc(sizeof(SLL));
if(fscanf(fp,"%d %s %f",&new->id,new->name,&new->marks)==-1)
	break;
new->next=0;
if(*hptr==0)
	*hptr=new;
else
{
dup=*hptr;
while(dup->next!=0)
	dup=dup->next;
dup->next=new;
}
}
}
/////////////////////////////////////////////
void delete_node(SLL **hptr)
{
	int num;
SLL *prev,*del;
del=*hptr;
printf("enter the delete roll no:\n");
scanf("%d",&num);
del=*hptr;
while(del)
{
if(del->id==num)
{
	if(del==*hptr)
*hptr=del->next;

else
prev->next=del->next;
free(del);
}
prev=del;
del=del->next;
}
}
//////////////////////////////////////////////
void delete_all(SLL **hptr)
{
SLL *dup;
if(*hptr==0)
{
printf("no records found\n");
return;
}
dup=*hptr;
while(dup)
{
*hptr=dup->next;
free(dup);
dup=*hptr;
}
}
///////////////////////////////////////////
void reverse_link(SLL **hptr)
{
	if(*hptr==0)
	{
	printf("no records found:\n");
	return;
	}
SLL *dup;
int c=count_node(*hptr);
if(c>1)
{
SLL **a=malloc(sizeof(SLL)*c);
dup=*hptr;
int i=0;
while(dup)
{
a[i]=dup;
dup=dup->next;
i++;
}
for(i=c-1;i>0;i--)
{
a[i]->next=a[i-1];
}
a[0]->next=0;
*hptr=a[c-1];
}
}
/////////////////////////////////////////////
void reverse_print(SLL *hptr)
{

	int i,j,c;
	c=count_node(hptr);
SLL *dup=hptr;
for(i=0;i<c;i++)
{
	dup=hptr;

for(j=0;j<c-1-i;j++)
{
	dup=dup->next;
}
printf("%d %s %f\n",dup->id,dup->name,dup->marks);
}
}
/////////////////////////////////////
void reverse_rec(SLL *hptr)
{

if(hptr==0)
{
printf("no nodes are available\n");
return;
}

if(hptr->next!=0)
	reverse_rec(hptr->next);
	

printf("%d %s %f\n",hptr->id,hptr->name,hptr->marks);

}
/////////////////////////////////////////////////

void reverse_print(SLL *hptr)
{
if(hptr==0)
{
printf("no nodes are available\n");
return;
}
SLL *dup;
int i,j,c;
c=count_node(hptr);

for(i=0;i<c;i++)
{
        dup=hptr;
for(j=0;j<c-1-i;j++)
{
dup=dup->next;
}
printf("%d %s %f\n",dup->roll,dup->name,dup->marks);
}
}
/////////////////////////////////////////////////
void sort_data(SLL *hptr)
{
if(hptr==0)
{
printf("no nodes are available\n");
return;
}
SLL *dup;
int c,i,j,t;
char s[20];
c=count_node(hptr);
for(i=0;i<c-1;i++)
{
        dup=hptr;

for(j=0;j<c-1-i;j++)
{
if(dup->roll>(dup->next->roll))
{
t=dup->roll;
dup->roll=dup->next->roll;
dup->next->roll=t;

strcpy(s,dup->name);
strcpy(dup->name,dup->next->name);
strcpy(dup->next->name,s);

t=dup->marks;
dup->marks=dup->next->marks;
dup->next->marks=t;
}
dup=dup->next;
}
}
}
//////////////////////////////////////////////////
void search_node(SLL *hptr)
{
if(hptr==0)
{
printf("no  nodes are available \n");
return;
}
char name[20];
printf("enter name to search:\n");
scanf("%s",name);
int f=0;
while(hptr)
{
if(strcmp(hptr->name,name)==0)
{
printf("%d %s %f\n",hptr->roll,hptr->name,hptr->marks);
f=1;
}
hptr=hptr->next;
}
if(f==0)
printf("name not found\n");
}
///////////////////////////////////////
void main()
{
	SLL *headptr=0;
	int op,c;
while(1)
{
printf("Enter the number:1)add_node 2)print_node 3)count_node 4)add_end 5)add_middle 6)save_file 7)read_file 8)delete_node 9)delete_all 10)reverse_link 11)reverse_print 12)rev_rec 13)print_rec 14)sorting_node 15)search_node 16)Exit:\n");
	scanf("%d",&op);
	
	switch(op)
	{
	
		case 1: add_node(&headptr);break;
		case 2: print_node(headptr);break;	
		case 3: c=count_node(headptr);
			    printf("%d\n",c);break;	     
		case 4: add_end(&headptr);break;
		case 5: add_middle(&headptr);break;
		case 6: save_file(headptr);break;
		case 7: read_file(&headptr);break;
		case 8: delete_node(&headptr);break;
		case 9: delete_all(&headptr);break;
        case 10: reverse_link(&headptr);break;	
		case 11: reverse_print(headptr);break;
		case 12: reverse_rec(headptr);break;
		case 13 : reverse_print(headptr);break;
		case 14: sorting_node(headptr);break;
		case 15:search_node(headptr);break;
		case 16:exit(0);break;
	}
}
}
