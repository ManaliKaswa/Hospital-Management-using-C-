/*Write program to implement a priority queue in C++ using an inorder List to store the items
in the queue.
Create a class that includes the data items and the
priority (which should be int)
The inorder list should contain objects . the items with highest priority appear at the beginning of the list (which will make it relatively easy to retrieve the highest item.)*/
#include<iostream>
#define max 5
using namespace std;


class q
{
 char qary[max][10];
 int prio[max];
 int size;
 int f,r;
 public:
	 q()
	 {
	 f=r=-1;
	 size=0;
	 }
 bool is_full();
 bool is_empty();
 void sort();
 void add();
 void deleteq();
 void display();
 
};
bool q :: is_empty()
{
	if(size==0)
		return 1;
	else
		return 0;
}

bool q :: is_full()
{
	if(size==max)
		return 1;
	else
		return 0;
}
void q :: sort()
{
	for(int j=0;j<size-1;j++)
    {
		for(int i=0;i<size-j-1;i++)
		{
		    if(prio[i]<prio[i+1])
		    {
		    swap(qary[i],qary[i+1]);
		    swap(prio[i],prio[i+1]);
		   
		    }
		 }
     }
     /*cout<<" sorted array :) ";
     if(!is_empty())
	{
		for(int j=f+1;j<size;j++)
		{
			cout<<qary[j]<<"\t";
		}
	}*/
}

void q :: display()
{
	if(!is_empty())
	{
		for(int j=f+1;j<size;j++)
		{
			cout<<qary[j]<<"\t";
		}

	}
	else
	{
	cout<<"\n There are no patients in the hospital wards \n";
	}
}

void q :: add()
{
char an;
cout<<" \n **** THE STATE OF THE PATIENT **** \n\n 1. GOOD : Vital signs are stable and within normal limits. Patient is conscious and comfortable.\n \n 2. FAIR : Vital signs are stable and within normal limits. Patient is conscious, but may be uncomfortable.\n \n 3. SERIOUS: Vital signs may be unstable and not within normal limits. Patient is acutely ill.\n \n4. CRITICAL : Vital signs are unstable and not within normal limits. Patient is unconscious. \n \n ";
	do
	{
		if(is_full()==1)
		{
		
			cout<<" THE HOSPITAL WARDS ARE FULL \n";
			break;
		}
		else
		{
			cout<<"enter the name of patient \n";
			r=r +1;
			cin>>qary[r];
			cout<<"ENTER 1,2,3 or 4 \n1.GOOD\n2.FAIR\n3.SERIOUS\n4.CRITICAL\n";
			cin>>prio[r];
			
			size++;
			cout<<"do you want to add more patients : \n if yes then enter y ?"<<endl;
			cin>>an;
		}
	}while(an=='y'||an=='Y');	
	sort();
}
void q :: deleteq()
{
	if(!is_empty())
	{
	f++;
	cout<<"\n the patient sent to O.T. is : "<<qary[f]<<endl;
	} 
	else
	{
	cout<<"\n  there are no patients in the hospital wards \n";
	}
}	
int main()
{
char ans;
int ch;

q ob;
do
	{
	cout<<"\n*********** ADITYA BIRLA  HOSPITAL ***************\n";
	 cout<<"\n 1. ADD THE PATIENTS TO HOSPITAL";
	 cout<<"\n 2.DISPLAY PATIENTS ";
	 cout<<"\n 3.DISPLAY THE PATIENT IN THE  OPERATION THEATRE";
	 cout<<"\n 4. Exit";
	 cout<<"\n Enter your choice :";
	 cin>>ch;
		switch (ch)
		{
		case 1:
		ob.add();
		break;
		case 2:
		ob.display();
		break;
		case 3:
		ob.deleteq();
		break;
		case 4:
		break;
		default:
		cout<<"Wrong choice"<<endl;
		break;
		}
	cout<<"Do you want to continue ?"<<endl;
	cin>>ans;
	}while(ans=='y'||ans=='Y');
return 0;
}
