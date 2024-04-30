/*
* Daniel Buck
* CS-210
* April 17, 2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

//Define the GroceryItem class
class GroceryItem {
public:
	void SetName(string itemName);
	void SetQuantity(int itemQuantity);
	string GetName();
	int GetQuantity();

private:
	string name;
	int quantity = 0;
};

void GroceryItem::SetName(string itemName) {
	name = itemName;
}

void GroceryItem::SetQuantity(int itemQuantity) {
	quantity = itemQuantity;
}

string GroceryItem::GetName() {
	return name;
}

int GroceryItem::GetQuantity() {
	return quantity;
}

ifstream inputStream;
ofstream outputStream;

vector<GroceryItem*> loadData() {
	map<string, int> itemQuantities;    //Create an empty map to store items and their quantities
	vector<GroceryItem*> groceryList(0);//Create an empty vector to store objects of the GroceryItem class
	string item;
	
	//Open the data file
	inputStream.open("CS210_Project_Three_Input_File.txt");
	if (!inputStream.is_open()) {
		throw ios_base::failure("Failed to open file.");
	}
	while (!inputStream.eof()) {
		inputStream >> item;
		//If the item is not in the map, add it
		if (itemQuantities.count(item) == 0) {
			itemQuantities.emplace(item, 1);
		}
		//If the item is already in the map, add 1 to the value
		else {
			itemQuantities[item]++;
		}
	}
	//Open or create the backup file
	outputStream.open("frequency.dat");

	//Go through the map, add each key/value pair to a GroceryItem object, then read all objects into a vector
	for (map<string, int>::iterator it = itemQuantities.begin(); it != itemQuantities.end(); it++) {
		GroceryItem* newItem = new GroceryItem();
		const string key = it->first;
		const int value = it->second;
		newItem->SetName(key);
		newItem->SetQuantity(value);
		groceryList.push_back(newItem);
		//Write data to the backup file
		outputStream << key << ' ';
		outputStream << value << endl;
	}
	return groceryList;

	inputStream.close();
	outputStream.close();
}

//Function to convert a string to lowercase, taken from https://www.geeksforgeeks.org/how-to-convert-std-string-to-lower-case-in-cpp/
string convertToLowercase(const string& str) {
	string result = "";

	for (char ch : str) {
		result += tolower(ch);
	}
	return result;
}

//Item search function
void menuOptionOne(vector<GroceryItem*> groceryList) {
	string item;
	cout << "Enter item: ";
	cin >> item;
	cout << endl;

	for (int i = 0; i < groceryList.size(); i++) { //Searches for a match to the users search in the groceryList vector
		GroceryItem* currentItem = groceryList[i];
		if (convertToLowercase(currentItem->GetName()) == convertToLowercase(item)) {
			cout << item << ": " << currentItem->GetQuantity() << endl;
			return;
		}
	}
	cout << "Item not found." << endl;
}

//Displays all items sold and their quantities
void menuOptionTwo(vector<GroceryItem*> groceryList) {
	for (int i = 0; i < groceryList.size(); i++) {
		GroceryItem* currentItem = groceryList[i];
		cout << currentItem->GetName() << ' ' << currentItem->GetQuantity() << endl;
	}
	cout << endl;
}

//Displays all items sold and their quantities in histogram format
void menuOptionThree(vector<GroceryItem*> groceryList) {
	for (int i = 0; i < groceryList.size(); i++) {
		GroceryItem* currentItem = groceryList[i];
		cout << currentItem->GetName() << ' ';
		for (int i = 0; i < currentItem->GetQuantity(); i++) {
			cout << '*';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	vector<GroceryItem*> groceryList = loadData(); //Backs up the data and create a vector of class objects

	int menuSelection = 0;

	//Displays the menu options
	while ((menuSelection < 1) || (menuSelection > 4)) {
		cout << "Please Select a Menu Option Number Below:" << endl;
		cout << "1) Search for an item by name" << endl;
		cout << "2) Display a list of all items and quantities purchased today" << endl;
		cout << "3) Display histogram representation of all items purchased today" << endl;
		cout << "4) Exit the program" << endl;
		cout << endl;
		cout << "Selection: ";
		cin >> menuSelection;
		cout << endl;


		//Takes the branch corresponding to users menu selection
		switch (menuSelection) {

		case 1: //Search for an item by name and print quantity
			menuOptionOne(groceryList);
			break;

		case 2: //Display all items and their quantities numerically
			menuOptionTwo(groceryList);
			break;

		case 3: //Display all items and their quantities in a histogram format
			menuOptionThree(groceryList);
			break;

		case 4: //Exit the program
			cout << "Thank you. Have a nice day!" << endl;
			return 0;

		default:
			cout << "Invalid Input. Please enter a number 1-4." << endl;
			cout << endl;
			//If user enters something non-numeric, this will fix cin's failstate
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			break;
		}
	}

}