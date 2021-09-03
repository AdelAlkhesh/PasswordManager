#include "main.hpp"

void SaveToFile(string path, string email, string password,
                string accountName) {
  ofstream my_file;
  my_file.open(path, std::ios_base::app);

  if (my_file) {
    my_file << setw(25) << std::left << accountName << setw(30) << std::left
            << email << setw(25) << password;
    my_file << endl;
  }
  my_file.close();
  cout << "Data saved successfully!" << endl;
  cout << "Returning to main menu" << endl;
  cout << endl;
  cout << endl;
  MainMenu();
}

void ReadFile() {
  ifstream my_file("accounts.txt");
  string line;
  if (my_file) {
    while (getline(my_file, line)) {
      cout << line << endl;
    }
  }
  my_file.close();
  cout << endl;
  cout << endl;
  MainMenu();
}

void SignUp() {
  string email, password, accountName;
  string choice;
  cout << "Enter an email:" << endl;
  cin >> email;
  cout << "Enter a password:" << endl;
  cin >> password;
  cout << "Enter an account name:" << endl;
  cin >> accountName;

  SaveToFile("accounts.txt", email, password, accountName);
}

void StorePassword(string password) {
  string email, accountName;
  cout << "Enter an email:" << endl;
  cin >> email;
  cout << "Enter an account name:" << endl;
  cin >> accountName;
  SaveToFile("accounts.txt", email, password, accountName);
  cout << "Data saved successfully!" << endl;
  cout << "Returning to main menu" << endl;
  cout << endl;
  cout << endl;
  MainMenu();
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
  cout << endl;
  cout << "Would you like to store this password?(Y/N)" << endl;
  cin >> answer;
  if (answer == "Y") {
    cout << endl;
    cout << endl;
    StorePassword(password);
  } else {
    cout << endl;
    cout << endl;
    MainMenu();
  }
}

void Choices() {
  string choice;
  cout << "What would you like me to do?" << endl;
  cout << "1. Store New Account Info" << endl;
  cout << "2. Search" << endl;
  cout << "3. Generate Password" << endl;
  cout << "4. View Data File" << endl;
  cin >> choice;
  if (choice == "1") {
    cout << endl;
    cout << endl;
    SignUp();
  } else if (choice == "2") {
    cout << endl;
    cout << endl;
    Search();
  } else if (choice == "3") {
    cout << endl;
    cout << endl;
    PassGenerate();
  } else if (choice == "4") {
    cout << endl;
    cout << endl;
    ReadFile();
  } else {
    cout << "Invalid input, try again" << endl;
    cout << endl;
    cout << endl;
    Choices();
  }
}

void MainMenu() {

  cout << "-------------------------------" << endl;
  cout << "          MAIN MENU" << endl;
  cout << "-------------------------------" << endl;
  Choices();
}

void ProgramStart() {
  ifstream file_exist("accounts.txt");
  if (file_exist) {
    MainMenu();
  } else {
    ofstream my_file("accounts.txt");

    if (my_file) {
      my_file << setw(25) << std::left << "ACCOUNT" << setw(30) << std::left
              << "EMAIL" << setw(25) << "PASSWORD";
      my_file << endl;
      my_file << endl;
      MainMenu();
    }
    my_file.close();
  }
}

void SearchFile(string query) {
  ifstream my_file("accounts.txt");
  string line;
  bool found = false;
  if (my_file) {
    while (getline(my_file, line)) {
      if (line.find(query) != string::npos) {
        found = true;
        cout << line << endl;
      }
    }
    if (!found) {
      cout << "Item Not found" << endl;
    }
    cout << endl;
    cout << endl;
    string choice;
    cout << "What would you like to do?" << endl;
    cout << "1. Search for another item" << endl;
    cout << "2. Return to main menu" << endl;
    cout << "3. Exit Password Manager" << endl;
    cin >> choice;
    if (choice == "1") {
      Search();
    } else if (choice == "2") {
      cout << endl;
      cout << endl;
      MainMenu();
    } else if (choice == "3") {
      exit;
    } else {
      cout << "Invalid input... returning to main menu" << endl;
      cout << endl;
      cout << endl;
      MainMenu();
    }
  }
  my_file.close();
}

void Search() {
  string query;
  cout << "What would you like to search for?" << endl;
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  getline(cin, query);
  cout << endl;
  cout << endl;
  cout << "Search results:" << endl;
  SearchFile(query);
}