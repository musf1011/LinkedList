#include<iostream>
using namespace std;
struct SingleLinkList
{ 
    int data;
    struct SingleLinkList* next;
};
typedef struct SingleLinkList node;
node* getNode()
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode=newnode;
	cout<<"Enter the Data in the Node = ";
	cin>>newnode->data;
	cout<<"\n*********\n";
	newnode->next=NULL;
	return newnode;
}
node* createList(node* &start)
{
	int n;
	cout<<"Enter number of list you want = ";
	cin>>n;
  for(int i=0;i<n;i++)
  {
  	cout<<"\n\n";
	node* newNode=getNode();
	if(start==NULL)
	{
		start=newNode;
	}
	else
	{
		node* temp;
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newNode;
	}
  }
  cout<<"\n\n\n";
  return start;  
}
void display(node* ptr)
{
	int counter=0;
	cout<<"Traversal of Linked List : \n";
	if(ptr==NULL)
	{
		cout<<"\n\nThere is nothing to traverse in the List.";
	}
	else
	{
	while(ptr!=NULL)
	{
	cout<<"\n*\n"<<ptr->data<<endl;
	ptr=ptr->next;
	counter++;
    }
    }
    cout<<"\n\n\nTotal Nodes in the List = "<<counter<<"\n\n\n";
}
node* delAtBeg(node* &start)
{
	if(start==NULL)
	{
		cout<<"There is no Node in the List to Delete.\n";
	}
	else
	{
		cout<<"\nFirst Node in the List has been Deleted: "<<start->data<<endl<<endl;
		node* temp;
		temp=start;
		start=start->next;
		free(temp);
	}
	return start;
}
node* delAtEnd(node* &start)
{
	if(start==NULL)
	{
		cout<<"There is no node in the List to Delete.\n\n\n\n";
	}
	else if(start->next==NULL)
	{
		cout<<"\nLast Node in the List has been Deleted: "<<start->data<<endl<<endl;
		cout<<"Empty List now\n\n\n";
		free(start->next);
		start=NULL;
	}
	else
	{
		node* temp=start;
		node* prev=temp;
		while(temp->next!=NULL)
		{	
		    prev=temp;
		    temp=temp->next; 
	    }
		cout<<"\nLast Node in the List has been Deleted: "<<temp->data<<endl<<endl;
	    prev->next=NULL;
	    free(temp);
	}
	return start;	
}
int main()
{
	node* start=NULL;
	int opt;
	int upd=0;
	options:
	cout<<"Choose the option from below :\n\n1). ";
	if(upd==1)
	{
		cout<<"Add Nodes in the List";
	}
	else
	{
		cout<<"Create List of Nodes";
    }
	cout<<".\n2). Display the List.\n3). Delete the First Node in List.\n4). Delete the Last node in List.\n5). Exit.\n\n";
	cin>>opt;
	if(opt<1 || opt>5)
	{
		system("cls");
		cout<<"\nInvalid Option!\n\n Choose Again.....\n\n";
		goto options;
	}
	else if(opt==1)
	{
	   system("cls");
	   createList(start);
	   upd=1;
	   goto options;
    }
    else if(opt==2)
    {
    	system("cls");
	    display(start);
    	goto options;
    }
    else if(opt==3)
    {
    	system("cls");
    	delAtBeg(start);
    	if(start==NULL)
    	{
    		upd=0;
		}
	    goto options;
    }
    if(opt==4)
    {
    	system("cls");
    	delAtEnd(start);
    	if(start==NULL)
    	{
    		upd=0;
		}
    	goto options;
	}
	if(opt==5)
	{
		system("cls");
		cout<<"\n\n\n\t\t\tThank You! \n\n\n\n\nProgram Finished....\n\n";
	}
	system("pause");
}