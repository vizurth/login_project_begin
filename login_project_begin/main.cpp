#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool checkData(string un, string pw){
    string usernameIN, passwordIN;
    ifstream file(un + ".txt");
    if (file.is_open()){
        getline(file, usernameIN);
        getline(file, passwordIN);
        file.close();
        if (un == usernameIN && pw == passwordIN){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void includeData(string un, string pw){
    ofstream file(un + ".txt", ios_base::out);
    file << un << endl;
    file << pw << endl;
}

int main(){
    int choose;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Choose what you wanna do: ";
    cin >> choose;
    string username, password;
    cout << "Write the Username: ";
    cin >> username;
    cout << "Write the Password: ";
    cin >> password;
    if (choose == 1){
        includeData(username, password);
    } else if (choose == 2){
        if (checkData(username, password)){
            cout << "YOU IN" << endl;
        } else {
            cout << "YOUR PASSWORD WRONG" << endl;
        }
    }
    
    return 0;
}
