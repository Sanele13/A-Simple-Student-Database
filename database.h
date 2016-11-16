//Name: Sanele Mpangalala
//Date: 28 Feb 2016
// Assignment 1: A Simple Student Database

#ifndef DATABASE_H
#define DATABASE_H
#include<string>
#include<iostream>

namespace MPNSAN005{
//Function declarations

void addStudent(std::string name, std::string surname, std::string stuID, std::string classRecord);
void readDatabase();
void saveDatabase();
void display(std::string stuID);
void gradeStudent(std::string stuID);
void clear();

//declaration of the struct to bundle the strings
struct stuRec{
	std::string Name;
	std::string Surname;
	std::string StudentNumber;
	std::string classRecord;
};
}

#endif
