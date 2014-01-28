#include<iostream>
#include<vector>
using namespace std;
struct Node
	{
	int data;
 	Node *next;
	};
Node *Createlinklist(int num[],int N);
int Get(int i,Node *head);
void Insert(int i,int x,Node *head);
void Delete(int i,Node* head);
void printlist(Node* head);
int main()
{
 /* vector<int>array;
  for(int i=1;i<=10;i++)
  {
     array.push_back(i);
  }*/
 	 int array[10]={1,2,3,4,5,6,7,8,9,10};
 	 int N=sizeof(array)/sizeof(int);
 	 int result;
 	 for(int i=0;i<N;i++)
 		 {
   			cout<<array[i]<<" ";
		 }
 	 cout<<endl;
 	 Node *p1 = new Node;
 	 p1= Createlinklist(array,N);
	 printlist(p1);

  	 result=Get(5,p1);
  	 cout<<"result:"<<result<<endl;
 	 Insert(4,5,p1);
	 printlist(p1);
	 Delete(10,p1);
	 printlist(p1);	
 	 return 0;
}
Node *Createlinklist(int num[],int N)
{
  	 Node *head,*n;
  	 head = new Node;
  	 n=head;
  	 int length=N;
 	 // int length=num.size();
  	 cout<<"num:"<<N<<endl;
  	 for(int i=0;i<length;i++)
 		{
        		 Node *p=new Node;    
	 		 p->data=num[i];
         		 n->next=p;
         		 n=p;
       		 }
  	 head=head->next;
  	 n->next=NULL;
	 return head;
}

int Get(int i,Node *head)
{ 
 	 int j=1;
 	 Node *p=head;
 	 while(p&&j<i)
   	 {
     		 p=p->next;
    		 j++;
   	 }
 	 if(!p|j>i)
   	 {
    		 cout<<"the "<<i<<"不存在"<<endl;
    		 throw "位置";
   	 }
 	 else if(j==i&&p)
   	 return p->data;
}
void Insert(int i,int x,Node *head)
{
	Node *p=head;
	int j=1;
	while(j<i-1&&p)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i)
	{
		cout<<"第"<<i<<"个位置"<<"无法插入"<<endl;
		return;
	}
	else if(j==i-1)
	{
		Node *s= new Node;
		s->data=x;
		s->next=p->next;
		p->next=s;
	}
}

void  Delete(int i,Node *head)
{
	int x=0;
	int j=1;
	Node *s=new Node;
	Node *p=head;
	while(j<i-1&&p)
	{
		p=p->next;
		j++;
	}
	if(!p||!p->next)
	{
		cout<<"要删除的内容不存在"<<endl;
		return;
	}
	if(j==i-1&&p->next)
	{
		s=p->next;
		x=s->data;
		p->next=s->next;
		delete s;
	}
  	cout<<"第"<<i<<"个元素"<<x<<"已经被删除"<<endl;
}
void printlist(Node* head)
{
	Node *p=head;
	while(p)
	{
		cout<<p->data<<"  ";
		p=p->next;
	}
	cout<<endl;
}		
