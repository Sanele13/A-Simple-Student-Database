//Name: Sanele Mpangalala
//Date: 28 Feb 2016
// Assignment 1: A Simple Student Database

#include "database.h"
#include<iostream>
#include<string>
using namespace std;

int main(void){
	std::string option;
	for(;;){
	 std::string Name="";
	 std::string Surname="";
	 std::string StuId="";
	 std::string classRecord="";
	 cout<<endl;	 
	 //display menu
       	 cout<<"Welcome!\n";
	 cout<<"0: Add student\n";
	 cout<<"1: Read database\n";
	 cout<<"2: Save database\n";
	 cout<<"3: Display given student data\n";
	 cout<<"4: Grade student\n";
	 cout<<"Enter a number (or q to quit) and press return..."; cout<<endl;
	 cin>>option;
//choose option
	 if(option=="0"){
		//read data from input
		cout<<"Enter the student's name"; cout<<endl;	
		cin>>Name;
		cout<<"Enter the student's surname"; cout<<endl;	
		cin>>Surname;
		cout<<"Enter the student's student number"; cout<<endl;	
		cin>>StuId;
		getline(cin, classRecord);
		cout<<"Enter the student's marks (e.g. 10 25 31)"; cout<<endl;	
		getline(cin, classRecord); //reads entire line
		MPNSAN005::addStudent(Name,Surname,StuId,classRecord);
	}
	else if(option=="1"){
		MPNSAN005::readDatabase();
		}
	else if(option=="2"){
		MPNSAN005::saveDatabase();
		}
	else if(option=="3"){
		cout<<"Enter student number"; cout<<endl;
		cin>>StuId;	
		MPNSAN005::display(StuId);
		}
	else if(option=="4"){
		cout<<"Enter student number"; cout<<endl;
		cin>>StuId;
		MPNSAN005::gradeStudent(StuId);
		}
	else if (option=="q"){
		std::terminate(); //to terminate program
		}
	
	}
	 return 0;
}
