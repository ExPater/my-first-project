#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool join() {
	dontsucces:
	cout << "write your username." << endl;
	string login;
	cin >> login;
	login += ".txt";
	ifstream check;
	check.open(login);
	if (check.is_open() == true) {
		cout << "write your password" << endl;
	}
	else {
		cout << "there is no account with this username!" << endl;
		cout << "Do you want to go out or try to come in again?" << endl;
		cout << "to leave you must to write 1                   to try it again you must to write 2" << endl;
		int exit; cin >> exit;
		if (exit == 1) {
			return 0;
		}
		else {
			goto dontsucces;
		}
	}
	string password; cin >> password;
	string passworda;
	getline(check, passworda);
	if (password == passworda) {
		cout << "you are logged into your account." << endl;
		check.close();
		return 1;
	}
	else {
		cout << "Your password isnt right" << endl;
		check.close();
		return 0;
	}
}
bool registr() {
	fuck:
	cout << "come up with a username." << endl;
	string login; cin >> login;
	login += ".txt";
	ifstream check;
	check.open(login);
	if (check.is_open() == true) {
		cout << "this account already exists" << endl;
		check.close();
		cout << "to leave you must to write 1                   to try it again you must to write 2" << endl;
		int a; cin >> a;
		if (a == 1) {
			return 0;
		}
		else {
			goto fuck;
		}
	}
	check.close();
	ofstream add;
	add.open(login);
	if (add.is_open() == false) {
		cout << "Something went wrong" << endl;
		return 0;
	}
	cout << "enter your password" << endl;
	string password;
	cin >> password;
	add << password;
	add.close();
	cout << "Succes" << endl;
	return 1;
}
int main() {
	cout << "Do you have account?" << endl << "1 if you have              2 if you dont have" << endl;
	int a;
	cin >> a;
	if (a == 1) {
		bool succes;
		succes = join();
		if (succes == 0) {
			return 0;
		}
		else {
			return 0;
		}
	}
	else {
		registr();
	}
}