#include <vector>
#include <string>
using namespace std;

#include "Recipe.h"

void Recipe::setDescription(string mystring) {
	this->discription = mystring;
}
void Recipe::addIngredient(string ingredient) {
	ingredients.push_back(ingredient);
}
/*vector<string>* Recipe::listIngredients() {
	return ingredients;
} */
string Recipe::listDescription() {
	return this->discription;
}
string Recipe::listName() {
	return this->name;
}
void Recipe::setName(string v) {
	this->name = v;
}