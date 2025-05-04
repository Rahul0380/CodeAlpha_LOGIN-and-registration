#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    ofstream file("users/" + username + ".txt");
    file << username << endl << password;
    file.close();

    cout << "Registration successful!\n";
}

bool loginUser() {
    string username, password, u, p;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream file("users/" + username + ".txt");
    if (!file) {
        cout << "User not found.\n";
        return false;
    }

    getline(file, u);
    getline(file, p);

    if (u == username && p == password) {
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Incorrect credentials.\n";
        return false;
    }
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoose an option: ";
    cin >> choice;

    if (choice == 1)
        registerUser();
    else if (choice == 2)
        loginUser();
    else
        cout << "Invalid option.\n";

    return 0;
}
