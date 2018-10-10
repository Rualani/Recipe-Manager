#pragma once
// Author: Joshua Thatcher
// Computer Scientist: Barry Dysert
// Purpose: Contains class definitions for a recipe

#include <vector>
#include <string>
using namespace std;

class Recipe {
protected:
	vector<string> ingredients;
	string discription;
	string name;
public:
	Recipe() {} // Default Constructor
	void setDescription(string mystring);
	void addIngredient(string ingredient);
	string listDescription();
	string listName();
	void setName(string v);
};