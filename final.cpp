#include<iostream>
#include<fstream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////
struct student
{
	int code;
	char name[100];
	int number;
	char lesson[10][20];
	int grade[20];
	int part[20];
	float avg;
}s[100];

/////////////////////////////////////////////////////////////////////////////////////
student read();
void write();
void search();
int main()
{                                                   //main
	int x=0,i=-1,j=0,n=0;
	
	cout<<"Welcome how can i help you?"
	<<endl<<"1-Add student"<<endl<<"2-Display student information"<<endl<<"3-Search student"<<endl;
	
	do
	{
		cin>>x;
		cin.ignore();
		i++;
	}while(x<1 || x>3);
	
	switch(x)
	{
		case 1: 
				cout<<"How many students do you want to add?"<<endl;
				cin>>n;
				cin.ignore();
				for(j=0;j<n;j++)
				{
					cout<<"student "<<j+1<<" = "<<endl;
					s[i]=read();
					
					cout<<"--------"<<endl;
					cout<<"avg is: "<<s[i].avg<<endl;
				}
				
				break;
		
		case 2:
					write();
					break;
					
		case 3:
					
					search();
	}
	
	
	return 0;
}                                                 //main
/////////////////////////////////////////////////////////////////////////////////////
int count(int a)
{
	int i=0;
	
	while(a>0)
	{
		a/=10;
		i++;
	}

	return i;
}
//////////////////////////////////////////////////////////////////////////////////////
student read()
{
	student s;
	
	float z[20],f=0,sum=0;
	
	cout<<"pls enter name: ";
	cin.getline(s.name,100);
		
	cout<<"pls enter code: ";
	
	do{
		cin>>s.code;
		cin.ignore();
	}while(count(s.code)!=9);
	

	cout<<"pls enter tedad lesson: ";
	cin>>s.number;
	cin.ignore();
		
	cout<<"--------"<<endl;
		
	for(int i=0;i<s.number;i++)
	{
		cout<<"pls enter name your lesson"<<i+1<<" : ";
		cin.getline(s.lesson[i],20);
		
		
		cout<<"pls enter grade your lesson"<<i+1<<" : ";
		do{
			cin>>s.grade[i];
			cin.ignore();
		}while(s.grade[i]<0 || s.grade[i]>20);
		
		
		cout<<"pls enter part your lesson"<<i+1<<" : ";
		cin>>s.part[i];
		cin.ignore();
		
			
		cout<<endl;
		
		f+=s.part[i];
		
		z[i]=s.grade[i]*s.part[i];
		
		sum+=z[i];
	}
	
	s.avg=sum/f;
	
	ofstream f1("student.txt" , ios::app);
	
	f1<<s.name<<endl;
	f1<<s.code<<endl;
	f1<<s.number<<endl;
	
	for(int j=0;j<s.number;j++)
	{
		f1<<s.lesson[j]<<endl;
		f1<<s.grade[j]<<endl;
		f1<<s.part[j]<<endl;
	}
	
	f1<<s.avg<<endl;
	
	f1.close();
	
	
	return s;
}
/////////////////////////////////////////////////////////////////////////////////////
void write()
{
	
	student s;
	
	ifstream f2("student.txt");
	
	while(f2.getline(s.name,100))
	{
		f2>>s.code;
		f2.ignore();
		f2>>s.number;
		f2.ignore();
		
		cout<<endl<<endl<<"your name: "<<s.name<<endl;
		cout<<"your code "<<s.code<<endl;
		cout<<"tedad of your lesson: "<<s.number<<endl;
		cout<<"--------"<<endl;
		
		for(int i=0;i<s.number;i++)
		{
			f2.getline(s.lesson[i],20);
			f2>>s.grade[i];
			f2.ignore();
			f2>>s.part[i];
			f2.ignore();
			
			cout<<"name of your lesson "<<i+1<<" : "<<s.lesson[i]<<endl;
			cout<<"grade your lesson "<<i+1<<" : "<<s.grade[i]<<endl;
			cout<<"part your lesson "<<i+1<<" : "<<s.part[i]<<endl;
		
			cout<<endl;
		}
			
		f2>>s.avg;
		f2.ignore();
		
		cout<<"--------"<<endl;
		cout<<"your avg: "<<s.avg<<endl;
		
	}
	
	f2.close();

	
}

////////////////////////////////////////////////////////////////////////////
void search()
{
	bool found=false;
	int x,y;
	student s;
	char ch[100];
	
	cout<<"Do you want to enter a name or code for the search?"<<endl<<"1-Name"<<endl<<"2-Code"<<endl;
	
	do
	{
		cin>>x;
		cin.ignore();
	}while(x<1 || x>2);
	
	
	if(x==1)
	{
		cout<<"please enter name : "<<endl;
		cin.getline(ch,100);
		
		ifstream f3("student.txt");

		while(f3.getline(s.name,100))
		{
			if(strcmp(ch , s.name)==0)
			{
				found=true;
						
				cout<<"fond!"<<endl;
						
				f3>>s.code;
				f3.ignore();
				f3>>s.number;
				f3.ignore();
		
				cout<<endl<<endl<<"your name: "<<s.name<<endl;
				cout<<"your code "<<s.code<<endl;
				cout<<"tedad of your lesson: "<<s.number<<endl;
				cout<<"--------"<<endl;
		
				for(int i=0;i<s.number;i++)
				{
					f3.getline(s.lesson[i],20);
					f3>>s.grade[i];
					f3.ignore();
					f3>>s.part[i];
					f3.ignore();
			
					cout<<"name of your lesson "<<i+1<<" : "<<s.lesson[i]<<endl;
					cout<<"grade your lesson "<<i+1<<" : "<<s.grade[i]<<endl;
					cout<<"part your lesson "<<i+1<<" : "<<s.part[i]<<endl;
		
					cout<<endl;
				}
			
					f3>>s.avg;
					f3.ignore();
		
					cout<<"--------"<<endl;
					cout<<"your avg: "<<s.avg<<endl;
							
			}                        ///if
			
				if(found==false)
					cout<<"Not found!";
					
		}              ///while
		
			f3.close();
		
		
	}     /// if x==1
	
	
	else if(x==2)
	{
		ifstream f4("student.txt");
				
			found=false;
			cout<<"Please enter code : "<<endl;
				
			do{
			cin>>y;
			cin.ignore();
			}while(count(y)!=9);
				
				
				
			while(f4.getline(s.name,100))
			{	
				f4>>s.code;
				f4>>s.number;
				f4.ignore();
				
				for(int i=0;i<s.number;i++)
				{
					f4.getline(s.lesson[i],20);
					f4>>s.grade[i];
					f4.ignore();
					f4>>s.part[i];
					f4.ignore();
				}
					
				f4>>s.avg;
				f4.ignore();
		
		
				if(y==s.code)
				{	
					found=true;
					cout<<endl<<endl<<"your name: "<<s.name<<endl;
					cout<<"your code "<<s.code<<endl;
					cout<<"tedad of your lesson: "<<s.number<<endl;
					cout<<"--------"<<endl;
		
					for(int i=0;i<s.number;i++)
					{

						cout<<"name of your lesson "<<i+1<<" : "<<s.lesson[i]<<endl;
						cout<<"grade your lesson "<<i+1<<" : "<<s.grade[i]<<endl;
						cout<<"part your lesson "<<i+1<<" : "<<s.part[i]<<endl;
						cout<<endl;
					}
			
					cout<<"--------"<<endl;
					cout<<"your avg: "<<s.avg<<endl;
						
					break;
			
			
				}   ///if
		}  //while
	
			if(found==false)
				cout<<"Not found!";
		
	}


}