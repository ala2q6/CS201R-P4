#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

// function declarations
vector<double> fileRead(string strParameter);
vector<string> snackRead(string strParameter);
void fileWrite(string strParameter, vector<double> vectorParameter);
void vendingMachine(string strParameter, vector<double> vectorQuantity);
int vendingMachineInput();
bool vendingMachineCheck(int intParameter, vector<double> vectorPrice, vector<double> vectorQuantity, vector<string> vectorSnack);