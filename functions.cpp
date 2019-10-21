#include "functions.h"

// function that reads a given file and puts lines into a double-vector
vector<double> fileRead(string strParameter) {

	double doubleRead;
	ifstream filein(strParameter);
	vector<double> doubleVector;
	while (filein.good()) {

		filein >> doubleRead;
		doubleVector.push_back(doubleRead);

	}

	return doubleVector;

}

vector<string> snackRead(string strParameter) {

	string strRead;
	ifstream filein(strParameter);
	vector<string> stringVector;
	while (filein.good()) {

		filein >> strRead;
		stringVector.push_back(strRead);

	}

	return stringVector;

}

// function that reads a double-vector and updates a file with new conditions
void fileWrite(string strParameter, vector<double> vectorParameter) {

	int intVariable = 1;
	ofstream fileout(strParameter);
	for (int i = 0; i < vectorParameter.size(); i++) {

		if (intVariable == 4) {

			fileout << vectorParameter.at(i) << '\n';
			intVariable = 1;

		}

		else {

			fileout << vectorParameter.at(i) << '\t';
			intVariable += 1;

		}

	}

}

// outputs vending machine visual with current quentities
void vendingMachine(string strParameter, vector<double> vectorQuantity) {

	int intIndex = 0;
	int vendingOuter = 1, vendingInner = 1, vendingIndex = 0;
	string strVariable;
	ifstream filein(strParameter);
	while (filein.good()) {

		filein >> strVariable;
		cout << fixed << setprecision(0);

		if (intIndex == 0) { cout << "  "; }

		if (strVariable.size() == 3) {

			cout << vectorQuantity.at(vendingIndex) << strVariable;
			vendingIndex += 1;

		}

		else if (strVariable.size() == 4) {

			if (vendingOuter == 1) {

				cout << endl << strVariable;
				vendingOuter += 1;

			}

			else {

				cout << vectorQuantity.at(vendingIndex) << strVariable;
				vendingIndex += 1;
				vendingOuter = 1;

			}

		}

		else if (strVariable.size() >= 21) { cout << endl << strVariable; }

		else {

			if (intIndex == 43) { cout << "\n ||\t\t  ||\n"; }

			if (intIndex < 42) { cout << strVariable; }

		}

		intIndex += 1;

	}

}

// function that returns index from user input
int vendingMachineInput() {

	string strVariable;
	char charArray[5] = { 'A', 'B', 'C', 'D', 'E' };
	while (true) {

		cout << "\nChoose your snack : ";
		cin >> strVariable;

		if (strVariable.size() != 2) { cout << "\nInput is invalid.\n"; continue; }

		int intVariable = strVariable.at(1) - 48;

		if ((intVariable > 0) && (intVariable < 5)) {

			for (int i = 0; i < 5; i++) {

				char charVariable = toupper(strVariable.at(0));

				if (charVariable == charArray[i]) { return intVariable - 1; }

				else { intVariable += 4; }

			}

			cout << "\nInput is invalid.\n";
			continue;

		}

		else { cout << "\nInput is invalid.\n"; }

	}

}

// returns true or false if successful transaction or not
bool vendingMachineCheck(int intParameter, vector<double> vectorPrice, vector<double> vectorQuantity, vector<string> vectorSnack) {

	double doubleVariable, doubleBalance = 0.0;
	while (true) {

		cout << fixed << setprecision(2);
		cout << "\nBalance : $" << doubleBalance << endl;
		cout << "Price : $" << vectorPrice.at(intParameter) << endl;
		cout << "Snack : " << vectorSnack.at(intParameter) << endl << endl;

		if (vectorQuantity.at(intParameter) == 0) { cout << "We don\'t have " << vectorSnack.at(intParameter) << " anymore.\n\n"; return false; }

		cout << "<Input 0 to Exit>\nInput : $";
		while (!(cin >> doubleVariable)) { // while we don't get a valid data type

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInput is invalid.\n\n<Input 0 to Exit>\nInput : $";

		}
		
		if (doubleVariable > 5) { cout << "\nMaximum of $5, sorry.\n"; continue; }

		if (doubleVariable == 0) { cout << "\nHave a nice day!\n";  return false; }

		doubleBalance += doubleVariable;

		if (doubleBalance >= vectorPrice.at(intParameter)) {

			if (doubleBalance - vectorPrice.at(intParameter) > 0) {

				cout << "\nChange due : $" << doubleBalance - vectorPrice.at(intParameter);

			}

			cout << "\nEnjoy your " << vectorSnack.at(intParameter) << "!\n\n";
			return true;

		}

		else {

			cout << "\nInsufficient funds. You need $" << vectorPrice.at(intParameter) - doubleBalance << " more.\n\n";

		}

	}
	
}
