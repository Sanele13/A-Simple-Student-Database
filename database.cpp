//Name: Sanele Mpangalala
//Date: 28 Feb 2016
// Assignment 1: A Simple Student Database

#include "database.h"
#include<cstdlib>
#include<string>
#include<vector>
#include <iostream>
#include<fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;
vector<MPNSAN005::stuRec> rec;

//add student
void MPNSAN005::addStudent(std::string name, std::string surname, std::string stuId, std::string classRecord){	 

	//check for duplication of data
	if(rec.size()==0){stuRec record={name,surname,stuId, classRecord};rec.push_back(record);}
	else{
		bool add = true;		
		for(int i=0;i<rec.size();i++){
			if(stuId.compare(rec[i].StudentNumber)==0){
				rec[i]={name,surname,stuId, classRecord};
				add = false;
				
			}
		}
		if (add){
			stuRec record={name,surname,stuId, classRecord};rec.push_back(record);
		}
	}

}

//display student data
void MPNSAN005::display(std::string stuId){

 cout<<"Displaying data...\n"; 
 for(int i=0;i<rec.size();i++){
	if(stuId.compare(rec[i].StudentNumber)==0){cout<<rec[i].classRecord;}
	cout<<endl;		
}
 cout<<endl;
 cout<<endl;	
 
}

//grade student
void MPNSAN005::gradeStudent(std::string stuId){
	cout<<"Grading student..."; 
	string str="";
	//search for student 
	for(int i=0;i<rec.size();i++){
		if(stuId==rec[i].StudentNumber){str=rec[i].classRecord;cout<<endl;}
	
	}		
	//tokenize the string and add to vector        
	istringstream iss(str);
        vector<string> grades;
        copy(istream_iterator<string>(iss),
        istream_iterator<string>(),
        back_inserter(grades));
	
	//calculate average
	int sum=0;
	for (int i=0;i< grades.size();i++){
	 sum=sum+atoi(grades[i].c_str());
	}
        float average= sum/(double)grades.size();
	        
	cout<<average;	
	cout<<endl;
	
}

//read data from a text file containing data
void MPNSAN005::readDatabase(){
	cout<<"Reading database...\n"; cout<<endl;
  	string line;
  	ifstream myfile ("Database.txt");
 	 if (myfile.is_open())
  	{
  	  while ( getline (myfile,line) )
  	{
 	//tokenize the string and add to vector        
	istringstream iss(line);
        vector<string> tokens;
        copy(istream_iterator<string>(iss),
        istream_iterator<string>(),
        back_inserter(tokens));
	
	//add data to database	
	std::string rec = "";
	for(int i =3;i<tokens.size();i++){rec=rec+" "+tokens[i];} //taking unknown number of grades
	addStudent(tokens[0],tokens[1],tokens[2],rec);
   	 }
	
    	myfile.close();
  	}


  else {cout<<"Unable to open file";}		
		
}

//saving data in the database.txt

void MPNSAN005::saveDatabase(){
  //add new data to a text file (append data)
  std::ofstream out;

  out.open("Database.txt", std::ios_base::app);
    for(int i=0; i<rec.size();i++){
		out<< rec[i].Name+" "+rec[i].Surname+" "+rec[i].StudentNumber+" "+rec[i].classRecord+"\n";
	}
  out.close();
}
