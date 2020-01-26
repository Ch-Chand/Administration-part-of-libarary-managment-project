#include <conio.h>
#include <string.h>
#include <time.h>
#include <cmath>
#include <windows.h>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
class Student
{
	public:
	string name;
	string regno;
		Student()
		{
			name="";
			regno="";
		}
		void InputStudentData()
		{
			cout<<"Enter regestration no :";
			getline(cin,regno);
			cout<<"Enter student name    :";
			getline(cin,name);
		}
		void DisplayStudentData()
		{
			cout<<"Registration No :"<<regno<<endl;
			cout<<"Student Name    :"<<name<<endl;
		}
		string GetStudentID()
		{
			return regno;
		}
		string GetStudentName()
		{
			return name;
		}
};
class Book
{
	string bookid;
	string name;
	string authorname;
	public:
		Book()
		{
			bookid="";
			name="";
			authorname="";
		}
		void InputBookData()
		{
			cout<<"Enter Book ID     :";
			getline(cin,bookid);
			cout<<"Enter Book Name   :";
			getline(cin,name);
			cout<<"Enter Author Name :";
			getline(cin,authorname);
		}
		void DisplayBookData()
		{
			cout<<"Book ID     :"<<bookid<<endl;
			cout<<"Book Name   :"<<name<<endl;
			cout<<"Author Name :"<<authorname<<endl;
		}
		string GetBookID()
		{
			return bookid;
		}
		string GetBookName()
		{
			return name;
		}
		string GetAuthorName()
		{
			return authorname;
		}
};
// FOR STUDENT RECORD MANAGEMENT
void CreateStudentRecord()
{
	Student s1;
	s1.InputStudentData();
	ofstream ofs("Student.txt",ios_base::out | ios_base::app);
	ofs.write((char*)&s1,sizeof(s1));
	ofs.close();
	cout<<"*****Student data is recorded*****"<<endl;
}
void DsiplayAllStudentsRecords()
{
	int i=1;
	Student s1;
	ifstream ifs("Student.txt", ios_base::in);
	while(ifs.read((char*)&s1,sizeof(s1)))
	{
		cout<<endl<<i++<<" Student"<<endl;
		s1.DisplayStudentData();
	}
	ifs.close();
}
void DisplaySpecificStudentRecord()
{
	int check=0;
	char ch[30];
	cout<<"Enter Student Registration No whose data you want to display :";
	gets(ch);
	Student s1;
	ifstream ifs("Student.txt", ios_base::in);
	while(ifs.read((char*)&s1,sizeof(s1)))
	{
		if(ch==s1.GetStudentID())
		{
			s1.DisplayStudentData();
			check++;
		}
	}
	if(check==0)
	cout<<"No Student having Registration No :"<<ch<<endl;
	ifs.close();
}
void ModifyStudentData()
{
	int check=0;
	char ch[30];
	cout<<"Enter Student Registration No whose data you want to modify :";
	gets(ch);
	Student s1;
	ifstream ifs("Student.txt", ios_base::in);
	ofstream ofs("Temp.txt", ios_base::out);
	while(ifs.read((char*)&s1,sizeof(s1)))
	{
		if(ch==s1.GetStudentID())
		{
			s1.InputStudentData();
			check++;
		}
		ofs.write((char*)&s1,sizeof(s1));
	}
	ifs.close();
	ofs.close();
	ifstream ifs1("Temp.txt", ios_base::in);
	ofstream ofs1("Student.txt", ios_base::out);
	while(ifs1.read((char*)&s1,sizeof(s1)))
	{
		ofs1.write((char*)&s1,sizeof(s1));
	}
	ifs1.close();
	ofs1.close();
	if(check==0)
	cout<<"No Student having Registration No :"<<ch<<endl;
	else
	cout<<"Student record Modified succussfully"<<endl;
}
void DeleteStudentRecord()
{
	int check=0;
	char ch[30];
	cout<<"Enter Student Registration No whose record you want to delete :";
	gets(ch);
	Student s1;
	ifstream ifs("Student.txt", ios_base::in);
	ofstream ofs("Temp.txt", ios_base::out);
	while(ifs.read((char*)&s1,sizeof(s1)))
	{
		if(ch!=s1.GetStudentID())
		ofs.write((char*)&s1,sizeof(s1));
		else
		check++;
	}
	ifs.close();
	ofs.close();
	ifstream ifs1("Temp.txt", ios_base::in);
	ofstream ofs1("Student.txt", ios_base::out);
	while(ifs1.read((char*)&s1,sizeof(s1)))
	{
		ofs1.write((char*)&s1,sizeof(s1));
	}
	ifs1.close();
	ofs1.close();
	if(check==0)
	cout<<"No Student having Registration No :"<<ch<<endl;
	else
	cout<<"Student record Deleted succussfully"<<endl;
}
// FOR BOOKS RECORDS MANAGEMENT
void CreateBook()
{
	Book b1;
	b1.InputBookData();
	ofstream ofs("Book.txt",ios_base::out | ios_base::app);
	ofs.write((char*)&b1,sizeof(b1));
	ofs.close();
	cout<<"*****Book data is recorded*****"<<endl;
}
void DisplayAllBooks()
{
	int i=1;
	Book b1;
	ifstream ifs("Book.txt", ios_base::in);
	while(ifs.read((char*)&b1,sizeof(b1)))
	{
		cout<<endl<<i++<<" Book"<<endl;
		b1.DisplayBookData();
	}
	ifs.close();
}
void DisplaySpecificBook()
{
	int check=0;
	char ch[30];
	cout<<"Enter Book ID whose data you want to display :";
	gets(ch);
	Book b1;
	ifstream ifs("Book.txt", ios_base::in);
	while(ifs.read((char*)&b1,sizeof(b1)))
	{
		if(ch==b1.GetBookID())
		{
			b1.DisplayBookData();
			check++;
		}
	}
	if(check==0)
	cout<<"No Book having ID :"<<ch<<endl;
	ifs.close();
}
void ModifyBookData()
{
	int check=0;
	char ch[30];
	cout<<"Enter Book ID whose data you want to modify :";
	gets(ch);
	Book b1;
	ifstream ifs("Book.txt", ios_base::in);
	ofstream ofs("Temp.txt", ios_base::out);
	while(ifs.read((char*)&b1,sizeof(b1)))
	{
		if(ch==b1.GetBookID())
		{
			b1.InputBookData();
			check++;
		}
		ofs.write((char*)&b1,sizeof(b1));
	}
	ifs.close();
	ofs.close();
	ifstream ifs1("Temp.txt", ios_base::in);
	ofstream ofs1("Book.txt", ios_base::out);
	while(ifs1.read((char*)&b1,sizeof(b1)))
	{
		ofs1.write((char*)&b1,sizeof(b1));
	}
	ifs1.close();
	ofs1.close();
	if(check==0)
	cout<<"No Book having ID :"<<ch<<endl;
	else
	cout<<"Book record Modified succussfully"<<endl;
}
void DeleteBookRecord()
{
	int check=0;
	char ch[30];
	cout<<"Enter Book ID whose record you want to delete :";
	gets(ch);
	Book b1;
	ifstream ifs("Book.txt", ios_base::in);
	ofstream ofs("Temp.txt", ios_base::out);
	while(ifs.read((char*)&b1,sizeof(b1)))
	{
		if(ch!=b1.GetBookID())
		ofs.write((char*)&b1,sizeof(b1));
		else
		check++;
	}
	ifs.close();
	ofs.close();
	ifstream ifs1("Temp.txt", ios_base::in);
	ofstream ofs1("Book.txt", ios_base::out);
	while(ifs1.read((char*)&b1,sizeof(b1)))
	{
		ofs1.write((char*)&b1,sizeof(b1));
	}
	ifs1.close();
	ofs1.close();
	if(check==0)
	cout<<"No Book having ID :"<<ch<<endl;
	else
	cout<<"Book record Deleted succussfully"<<endl;
}
// Administration Menu
void AdministrationMenu()
{
	char ch='\0';
	do
	{
		cout<<"\t1: Create Student Record"
		<<"\n\t2: Display All Students Records"
		<<"\n\t3: Display Specific Student Record"
		<<"\n\t4: Modify Student Record"
		<<"\n\t5: Delete Student Record"
		<<"\n\t6: Create Book"
		<<"\n\t7: Display All Books"
		<<"\n\t8: Display Specific Book"
		<<"\n\t9: Modify Book"
		<<"\n\t0: Delete Book"
		<<"\n\tY: Exit To Main Menu\n"<<endl;
		cout<<"Enter choice :";
	    ch=getche();
		switch(ch)
		{
			case '1':
				{
					system("cls");
					CreateStudentRecord();
					break;
				}
			case '2':
				{
					system("cls");
					DsiplayAllStudentsRecords();
					Sleep(3000);
					break;
				}
			case '3':
				{
					system("cls");
					DisplaySpecificStudentRecord();
					Sleep(3000);
					break;
				}
			case '4':
				{
					system("cls");
					ModifyStudentData();
					Sleep(1000);
					break;	
				}
			case '5':
				{
					system("cls");
					DeleteStudentRecord();
					Sleep(1000);
					break;
				}
			case '6':
				{
					system("cls");
					CreateBook();
					break;
				}
			case '7':
				{
					system("cls");
					DisplayAllBooks();
					Sleep(3000);
					break;
				}
			case '8':
				{
					system("cls");
					DisplaySpecificBook();
					Sleep(3000);
					break;
				}
			case '9':
				{
					system("cls");
					ModifyBookData();
					Sleep(1000);
					break;
				}
			case '0':
				{
					system("cls");
					DeleteBookRecord();
					Sleep(1000);
					break;
				}	
			case 'y':
				{
					system("cls");
					break;
				}
			case 'Y':
				{
					system("cls");
					break;
				}
			default:
				{
					cout<<"Invalid Choice"<<endl;
				}
		}
		if(ch=='y' || ch=='Y')
		break;
	}while(1);
}
main()
{
	cout<<"\t\t******WELCOME TO LAB******"<<endl;
	AdministrationMenu();
	cout<<endl<<"\n\n\t\t*******Game Over******\n\t\t*******THANKS********"<<endl;
}

