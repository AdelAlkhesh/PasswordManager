#include "main.hpp"

void SaveToFile(string path, string email, string password, string accountName) {
  ofstream my_file;
  my_file.open(path, std::ios_base::app);

  if (my_file) {
    my_file << setw(25) << std::left << accountName << setw(30) << std::left
            << email << setw(25) << password;
    my_file << endl;
  }
  my_file.close();
}

string ReadFile(string path) {
  ifstream my_file(path);
  string line;
  if (my_file) {
    while (getline(my_file, line)) {
      cout << line << endl;
    }
  }
  my_file.close();
  return line;
}

void signUp() {
  string email, password, accountName;
  cout << "Enter an email:" << endl;
  cin >> email;
  cout << "Enter a password:" << endl;
  cin >> password;
  cout << "Enter an account name:" << endl;
  cin >> accountName;

  SaveToFile("accounts.txt", email, password, accountName);
}

void Welcome() {
  ifstream file_exist("accounts.txt");
  if (file_exist) {
    signUp();
  } else {
    ofstream my_file("accounts.txt");

    if (my_file) {
      my_file << setw(25) << std::left << "ACCOUNT" << setw(30) << std::left
              << "EMAIL" << setw(25) << "PASSWORD";
      my_file << endl;
      my_file << endl;
      signUp();
    }
    my_file.close();
  }
}

void storePassword(string password) {
  string email, accountName;
  cout << "Enter an email:" << endl;
  cin >> email;
  cout << "Enter an account name:" << endl;
  cin >> accountName;
  SaveToFile("accounts.txt", email, password, accountName);
}

void PassGenerate() {
  const char alphanum[] =
      "0123456789!@#$%^_-*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int string_length = sizeof(alphanum) - 1;
  string password;
  int length;
  cout << "Enter the desired password length ";
  cin >> length;
  srand(time(NULL));
  cout << "Generated Password:" << endl;
  for (int i = 0; i < length; i++) {
    password += alphanum[rand() % string_length];
  }
  string answer;
  cout << password << endl;
  cout << endl;
  cout << "Would you like to store this password?(Y/N)" << endl;
  cin >> answer;
  if (answer == "Y")
  {
    storePassword(password);
  }
 
}

