#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <thread>
#include <chrono>

using namespace std;

void loadingAnimation() {
    for (int i = 0; i < 5; i++) {
        cout << ".";
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // wait 500ms
    }
    cout << "\n";
}

void registerUser() {
    string username, password;
    cout << "\x1B[32m"; // set text color to green
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    loadingAnimation();

    ifstream file("database.txt");
    bool exists = false;
    string line;
    while (getline(file, line)) {
        if (line == username) {
            exists = true;
            break;
        }
    }
    file.close();

    if (exists) {
        cout << "\x1B[31m"; // set text color to red
        cout << "Username already exists\n";
    } else {
        ofstream file("database.txt", ios::app);
        file << username << "\n" << password << "\n";
        file.close();
        cout << "\x1B[32m"; // set text color to green
        cout << "Registration successful!\n";
    }
}

void loginUser() {
    string username, password;
    cout << "\x1B[32m"; // set text color to green
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    loadingAnimation();

    ifstream file("database.txt");
    string line;
    bool found = false;
    while (getline(file, line)) {
        if (line == username) {
            getline(file, line);
            if (line == password) {
                found = true;
                break;
            }
        }
    }
    file.close();

    if (found) {
        cout << "\x1B[32m"; // set text color to green
        cout << "Login successful!\n";
    } else {
        cout << "\x1B[31m"; // set text color to red
        cout << "Invalid username or password\n";
    }
}

int main() {
    int choice;
    cout << "\x1B[34m"; // set text color to blue
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "                 __________           ________          _______          _______          \n";
    cout << "               //          \\       //        \\      //       \\      //       \\        \n";
    cout << "               |  Register  |       |  Login   |      |  Exit   |      |  Help   |        \n";
    cout << "               \\          //       \\        //      \\       //      \\       //        \n";
    cout << "                 __________           _______           _______          _______          \n";
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "1. Register\n2. Login\n3. Exit\n4. Help\n";
    cin >> choice;
    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        loginUser();
    } else if (choice == 3) {
        cout << "\x1B[31m"; // set text color to red
        cout << "Exiting...\n";
        return 0;
    } else if (choice == 4) {
        cout << "\x1B[34m"; // set text color to blue
        cout << "Help menu:\n";
        cout << "1. Register: Create a new account\n";
        cout << "2. Login: Login to an existing account\n";
        cout << "3. Exit: Exit the program\n";
        cout << "4. Help: Display this help menu\n";
    } else {
        cout << "\x1B[31m"; // set text color to red
        cout << "Invalid choice\n";
    }
    return 0;
}
