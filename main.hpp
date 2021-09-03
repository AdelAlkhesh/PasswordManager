#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::exit;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::string;
using std::toupper;

void SaveToFile(string path, string username, string password,
                string accountName);

void ReadFile();

void SignUp();

void ProgramStart();

void PassGenerate();

void StorePassword(string password);

void MainMenu();

void Choices();

void SearchFile(string query);

void Search();
