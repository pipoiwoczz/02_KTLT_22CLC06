#include "changePassword.h"

void changePassword(string& currPass)
{
	string confirmPass;
	cout << endl;
	cin.ignore();
	cout << "Enter the current password: ";
	getline(cin, confirmPass);

	while (confirmPass != currPass) {
		cout << "Password wrong!\nPlease enter the password again.\n";
		cin.ignore();
		cout << "Enter the current password: ";
		getline(cin, confirmPass);
	}
}