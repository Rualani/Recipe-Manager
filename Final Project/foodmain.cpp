// Author: Joshua Thatcher
// Professor: Barry Dysert
// Purpose: Through a series of complex while loops the user can navigate 
//          through the program via a interface based menu. 

#include "Recipe.h"
#include <iostream>
#include <vector>
using namespace std;

// List of menu functions

void addMenu(vector<Recipe>& v);
void modifyMenu(vector<Recipe>& v);
void ModifyRecipe(vector<Recipe>& v, int p);
void printList(vector<Recipe>& v);

int main() {
	// Declares a vector and assigns recipes to it. When loading a text file, recipe information will eventually be loaded into this vector
	vector<Recipe> mealplan; 

	// Initial Main menu. All menu's will eventually go back to this menu which then allows you to exit the game.
	while (true) {
		cout << "Please type a number for your choice" << endl;
		cout << "1: Modify Recipes" << endl;
		cout << "2: Add a recipe" << endl;
		cout << "3: List of recipes" << endl;
		cout << "4: Exit program" << endl;
		int i = 0;
		cin >> i;
		switch (i) {
		case 1: modifyMenu(mealplan);
			break;
		case 2: addMenu(mealplan);
			break;
		case 3: printList(mealplan);
			break;
		case 4:
			return 0;
		}
	}
}

// Let's user choose which recipe to modify or delete
	void modifyMenu(vector<Recipe>& v) {
		while (true) {
			cout << "Please enter the number of the recipe you wish to modify or delete" << endl;
			cout << "If you wish to exit, type -1" << endl;
			cout << "******************************" << endl;
			for (auto it = v.begin(); it != v.end(); ++it) {
				int i = it - v.begin(); // Pulls out the index number from the iterator. 
				cout << i + 1 << ": " << v[i].listName() << endl;
			}
			int i = 0;
			cin >> i;
			if (i != -1) {
				ModifyRecipe(v, i-1); // Now we go in one menu deeper to the program that can actually change the things.
			}
			else
				break;
		}
	}

	void ModifyRecipe(vector<Recipe>& v, int p) {
		while (true) {
			cout << "Recipe Name: " << v[p].listName();
			cout << "Please enter a number of your choice" << endl;
			cout << "1: Edit Name" << endl;
			cout << "2: Add Ingredient" << endl;
			cout << "3: Edit Cooking Instructions" << endl;
			cout << "4: Exit" << endl;

			int i = 0;  // For the switch case
			vector<string> ingredientlist;
			string tempstring;
			int tempint = 0;
			cin >> i; 
			switch (i) { 
			case 1: 
				cout << "Current name is " << v[p].listName() << endl; 
				cout << "What do you wish to change the name too? " << endl;
				cin.ignore();
				getline(cin, tempstring);
				v[p].setName(tempstring);
				break;
			case 2: 
				// Ingredientlist now points to the vector of ingredients within the class
				cout << "What is the name of the ingredient you wish to add?" << endl;
				cin.ignore();
				getline(cin, tempstring);
				v[p].addIngredient(tempstring);
				break;
			case 3:
				cout << "Please type in your new set of instructions to replace the old one" << endl;
				cin.ignore();
				getline(cin, tempstring);
				v[p].setDescription(tempstring);
				break;
			case 4:
				return; // Should break out of function.
			}
			
		}
	}

	void addMenu(vector<Recipe>& v) {
		while (true) {
			string temp;
			Recipe temprecipe; // Will be pushed back into vector
			// Setting the name with user input
			cout << "Please type in the name of your recipe" << endl;
			cin.ignore();
			getline(cin, temp);
			temprecipe.setName(temp);

			// setting the list of ingredients with user input
			cout << "Please add your ingredients." << endl;
			cout << "*****************************" << endl;
			while (true) {
				cout << "Please enter the name of your ingredient" << endl;
				cin.ignore();
				getline(cin, temp);
				// Adds ingredient to new recipe
				temprecipe.addIngredient(temp);	
				cout << "Do you wish to enter another ingredient" << endl;
				cout << "1: No" << endl;
				cout << "2: Yes" << endl;
				int tempint = 0;
				cin >> tempint;
				if (tempint == 1) {
					break;
				}
			}

			// Setting the Instructions for cooking
			cout << "Please enter the directions for cooking." << endl;
			cin.ignore();
			getline(cin, temp);
			temprecipe.setDescription(temp);

			// Now that the class attributes are assigned, push it back to class?
			v.push_back(temprecipe);

			// Allows user to exit
			cout << "Your recipe has been entered, do you wish to enter another?" << endl;
			cout << "1: Yes" << endl;
			cout << "2: No" << endl;
			int tempint = 0;
			cin >> tempint;
			if (tempint == 2)
				break;
		}
	}

	void printList(vector<Recipe>& v) {
		if (v.size() == 0) {
			cout << "You have no recipes yet!" << endl << endl;
		}
		else {
			for (std::vector<Recipe>::iterator it = v.begin(); it != v.end(); it++) {
				int i = it - v.begin(); // Index number
				cout << i + 1 << ": " << v[i].listName() << endl;
			}
		}
	}
