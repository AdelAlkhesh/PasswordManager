#include "main.hpp"

void SaveToFile(string path, string email, string password, string accountName) {
  ofstream my_file;
  my_file.open(path, std::ios_base::app);

  if (my_file) {
    my_file << setw(25) << std::left << accountName << setw(40) << std::left
            << email << setw(15) << password;
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
      my_file << setw(25) << std::left << "ACCOUNT" << setw(40) << std::left
              << "EMAIL" << setw(15) << "PASSWORD";
      my_file << endl;
      signUp();
    }
    my_file.close();
  }
}

string PassGenerate(int length) {
  const char alphanum[] =
      "0123456789!@#$%^_-*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int string_length = sizeof(alphanum) - 1;
  string password;
  srand(time(NULL));
  cout << "Generated Password:" << endl;
  for (int i = 0; i < length; i++) {
    password += alphanum[rand() % string_length];
  }
  cout << password << endl;
  return password;
}

void storePassword() {}