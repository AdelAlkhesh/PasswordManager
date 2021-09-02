#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::string;
using std::vector;

void SaveToFile(string path, string username, string password,
                string accountName);

string ReadFile(string path);

void signUp();

void Welcome();
