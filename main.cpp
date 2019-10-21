// Alex Arbuckle, Emily Foley, Justin Thomas, McKenzie Humann
// CS201R : Program 04
// 11 October 2019 

#include "functions.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

	vector<double> vectorQuantity(20, 5.0); // creating a vector, size of 20 elements, all assigned a double-value of 5.0
	fileWrite("quantityVendingMachine.txt", vectorQuantity); // writing that created vector to a new file, signifies brand new quantities
	while (true) { // while the user interacts with the vending machine

		vector<double> vectorPrices = fileRead("pricesVendingMachine.txt"); // pull prices file and put into vector for use
		vector<double> vectorQuantity = fileRead("quantityVendingMachine.txt"); // pull created quantities file and put into vector for use
		vector<string> vectorSnacks = snackRead("snacksVendingMachine.txt"); // pull created snack names and put into vector for use

		vendingMachine("asciiVendingMachine.txt", vectorQuantity); // print condition of vending machine
		int intInput = vendingMachineInput(); // get desired snackies from user
		bool boolCheck = vendingMachineCheck(intInput, vectorPrices, vectorQuantity, vectorSnacks); // interact with user for transaction

		if (boolCheck == true) { // if transaction was successful

			vectorQuantity.at(intInput) -= 1; // decrementation of quantity
			fileWrite("quantityVendingMachine.txt", vectorQuantity); // updating quantity file so we can later tell the vending machine in the next run

		}

	}

	return 0;

}
