#include <iostream>
#include<stdlib.h>
using  namespace std;
int pos1=0,pos2=0,m,n,p1,p2;
struct node
{
  int rw,cl;
  node *next;
};
struct node1
{
  int rw,cl;
  node1 *next;
};
struct back
{
	int rw,cl;
	back *next;
};
//queue
void push1(struct node1 **front,struct node1 **rear,int a,int b)
{
node1 *createnode=new node1;
createnode->rw=a;
createnode->cl=b;
createnode->next=NULL;
if(*front==NULL)
{
(*front)=(*rear)=createnode;
(*rear)->next=NULL;
}
else{
  (*rear)->next=createnode;
 (*rear)=createnode;
 (*rear)->next=NULL;
}
}
//stack
void push(struct node **head,int a,int b)
{
node *createnode=new node;
createnode->rw=a;
createnode->cl=b;
createnode->next=NULL;
if(*head==NULL)
{
(*head)=createnode;
}
else{
	struct node *list=(*head);
	while(list->next!=NULL)
	{
		list=list->next;
	}
  list->next=createnode;
}
}
//remove in queue
void removeready1(struct node1 **front)
{
  if((*front)==NULL)
  {
    cout<<"Empty list";
  }
  else 
	{
 struct node1 *head;
 head=(*front);
 (*front)=(*front)->next;
 delete(head);
  }
}
//remove in stack
void removeready(struct node **head)
{
  if((*head)==NULL)
  {
    cout<<"Empty list";
  }
  else 
	{
 delete(*head);
  }
}
//print matrix
void printmat(char arr[100][100])
{
		system("CLS");
for(int i=0;i<=m+1;i++)
{
	cout<<". ";
}
cout<<"\n";
for(int i=0;i<m;i++)
{
	cout<<".";
	for(int j=0;j<n;j++)
	{
		cout<<arr[i][j]<<" ";
	}
	cout<<".";
	cout<<endl;
}
for(int i=0;i<=m+1;i++)
{
	cout<<". ";
}
cout<<"\n";

}
//track path
void track(struct back **head,int i,int j)
{
	back *createnode=new back;
createnode->rw=i;
createnode->cl=j;
createnode->next=NULL;
if(*head==NULL)
{
(*head)=createnode;
}
else{
	struct back *list=(*head);
	while(list->next!=NULL)
	{
		list=list->next;
	}
  list->next=createnode;
}
}
void delt(struct back **head,char car[100][100],int *i,int *j)
{
	int k=0;
	while(head!=NULL)
	{
	if(k<4){
		struct back *list=(*head),*temp=(*head);
		while(list->next!=NULL)
		{
			temp=list;
			list=list->next;
		}
		car[list->rw][list->cl]='-';
*i=list->rw;
*j=list->cl;
		if(list==(*head))
		{
			car[list->rw][list->cl]='#';
			list=NULL;
		}
		else
		{
temp->next=NULL;
delete(list);
		}
k++;
	}
else
break;
}
}
//stage 1
int copymat1(char car[100][100],char ar[100][100])
{
	int i=pos1,j=pos2,points=0;
struct back *headb=NULL;
car[i][j]='#';
track(&headb,i,j);
int chance=3;
while(1){
	printmat(car);
	char ch;
	if(i==p1 && j==p2)
	{
		cout<<"CONGRATULATIONS\n";
		cout<<"Welcome to Stage2\n";
return 1;
	
	}
	 if(i<0||j<0||i>=m||j>=n||chance==0)
	{
		cout<<"YOU LOSS \n";
		return 0;
	}
	
	cout<<"Points"<<points<<"\n";
	cout<<"Chance"<<chance<<"\n";
	cout<<"Enter the operation--------a(left) ---d(right)---w(top)--s(down)\n ";
cin>>ch;
switch(ch)
{
	case 'w':
	if(car[i-1][j]=='-' && i-1>=0) 
	{
		i=i-1;
		car[i][j]='#';
		if(ar[i][j]=='*')
		{
			points++;
			track(&headb,i,j);
  }  
	else
	{
		cout<<"invalid step\n";
		delt(&headb,car,&i,&j);
	chance--;
	}
	break;
	case 's':
	if(car[i+1][j]=='-' && i+1<m)
	{
		i=i+1;
		car[i][j]='#';
			if(ar[i][j]=='*')
		{
			points++;
			track(&headb,i,j);
		}
	}  
	else
	{
		cout<<"Invalid step\n";
	delt(&headb,car,&i,&j);
	chance--;
	}
	break;
	case 'a':
	if(car[i][j-1]=='-' && j-1>=0)
	{
		j=j-1;
		car[i][j]='#';
			if(ar[i][j]=='*')
		{
			points++;
		track(&headb,i,j);
		}
	}  
	else
	{
		cout<<"Invalid step\n";
	delt(&headb,car,&i,&j);
	chance--;
	}

	break;
	case 'd':
	if(car[i][j+1]=='-' && j+1<n)
	{
		j=j+1;
		car[i][j]='#';
			if(ar[i][j]=='*')
		{
			points++;
      track(&headb,i,j);
		}
	}  
	else
	{
		cout<<"Invalid step\n";
		delt(&headb,car,&i,&j);
chance--;
	}
	break;
	default:cout<<"wrong input\n";
}
}
}}
//stage 2
void copymat(char car[100][100],char ar[100][100])
{
	struct back *headb=NULL;
	int i=pos1,j=pos2,points=0,chance=3;
car[i][j]='#';
track(&headb,i,j);
while(1){
	char ch;
	if(i==p1 && j==p2)
	{
		cout<<"CONGRATULATIONS\n";
		break;
	}
	printmat(car);
	cout<<"Points--"<<points<<"\n";
	cout<<"Chance--"<<chance<<"\n";
	cout<<"Enter the operation--------a(left) ---d(right)---w(top)--s(down)\n ";
cin>>ch;
switch(ch)
{
	case 'w':
	if(car[i-1][j]=='-' && i-1>=0) 
	{
		i=i-1;
		car[i][j]='#';
		if(ar[i][j]=='*')
		{
			points=points+2;
			track(&headb,i,j);
		}
		else {
			points++;
		}
	}  
	else
	{
		cout<<"invalid step\n";
	delt(&headb,car,&i,&j);
chance--;
	}
	break;
	case 's':
	if(car[i+1][j]=='-' && i+1<m)
	{
		i=i+1;
		car[i][j]='#';
			if(ar[i][j]=='*')
		{
			points=points+2;
			track(&headb,i,j);
		}
		else {
			points++;
		}
	}  
	else
	{
		cout<<"Invalid step\n";
	delt(&headb,car,&i,&j);
chance--;
	}
	break;
	case 'a':
	if(car[i][j-1]=='-' && j-1>=0)
	{
		j=j-1;
		car[i][j]='#';
			if(ar[i][j]=='*')
		{
			points=points+2;
			track(&headb,i,j);
		}
		else {
			points++;
		}
	}  
	else
	{
		cout<<"Invalid step\n";
	delt(&headb,car,&i,&j);
chance--;
	}
	break;
	case 'd':
	if(car[i][j+1]=='-' && j+1<n)
	{
		j=j+1;
		car[i][j]='#';
			if(ar[i][j]=='*')
		{
			points=points+2;
			track(&headb,i,j);
		}
		else {
			points++;
		}
	}  
	else
	{
		cout<<"Invalid step\n";
		delt(&headb,car,&i,&j);
chance--;
	}
	break;
	default:cout<<"wrong input\n";
}
}
}

int path1(struct node1 *front,struct node1 *rear,char arr[100][100])
{
  cout<<"enter the destination cord\n";
  cin>>p1>>p2;
while(front!=NULL)
{
int r=front->rw;
int c=front->cl;
if(r==p1 && c==p2)
{
	arr[r][c]='*';
  ///cout<<"FOUND\n";
	return 1;
}
else
{
  if(arr[r][c+1]=='-' && (c+1)<n)
{
  push1(&front,&rear,r,c+1);
}
if(arr[r+1][c]=='-' && (r+1)<m)
{
push1(&front,&rear,r+1,c);
}
if(arr[r-1][c]=='-' && r>0)
{
   push1(&front,&rear,r-1,c);
}
if(arr[r][c-1]=='-' && c>0)
{
  push1(&front,&rear,r,c-1);
}
arr[r][c]='*';
removeready1(&front);
}
}
return 0;
}
void path(struct node *head,char arr[100][100],char car[100][100])
{
  int flag=0;
  cout<<"enter the destination cord\n";
  cin>>p1>>p2;
	struct node *list2=NULL,*list=NULL;
while(head!=NULL)
{
list2=head;
	while(list2->next!=NULL)
	{
		list=list2;
   list2=list2->next;
	}
int r=list2->rw;
int c=list2->cl;
if(r==p1 && c==p2)
{ flag=1;
  arr[r][c]='*';
	break;
}
else
{
  if((arr[r][c+1]=='-')&& (c+1)<n)
{
	arr[r][c+1]='&';
  push(&head,r,c+1);
}
if((arr[r+1][c]=='-')&& (r+1)<m)
{
	arr[r+1][c]='&';
push(&head,r+1,c);
}
if((arr[r-1][c]=='-') && (r-1)>0)
{
	arr[r-1][c]='&';
   push(&head,r-1,c);
   
}
if((arr[r][c-1]=='-') && (c-1)>=0)
{
	arr[r][c-1]='&';
  push(&head,r,c-1);
}
arr[r][c]='*';
if(list2==head)
{
	head=head->next;
}
else{
list->next=list->next->next;
}
removeready(&list2);
}
}
if(flag==0)
{
	cout<<"destination not reached\n";
}
else 
copymat(car,arr);
//printmat(arr);
}
int main()
{
  char ar[100][100],car[100][100],car1[100][100];
  struct node *head=NULL;
	struct node1 *front=NULL,*rear=NULL;
  cout<<"enter the pos\n";
  cin>>pos1>>pos2;
  cout<<"matrix cordinates\n";
  cin>>m>>n;
  cout<<"enter the value\n";
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>ar[i][j];
		car[i][j]=car1[i][j]=ar[i][j];
    }
  }
	push1(&front,&rear,pos1,pos2);
  if(path1(front,rear,ar)){
	if(copymat1(car1,ar)){
  push(&head,pos1,pos2);
  path(head,ar,car);
	copymat(car,ar);
}
}}
