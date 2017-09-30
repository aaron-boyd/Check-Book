#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void RetrieveFile(string doc);
void Transaction();
void End();
float Deposit[10];
float Service[10];
float Check[10];
float IN[10];
float Withdrawal[10];
int CA, DA, SA, IA,WD;
float total, BB;
int main() {
	string D;
	cout << "Welcome to KeyBank, please enter this months transactions." << endl;
	cout << " " << endl;
	cout << "~~Key~~" << endl;
	cout << "Check == C              Deposit == D" << endl << "Service Charge == S     Withdrawal == W" << endl << "End == E" << endl;
	cout << " " << endl;
	cout << "Which account would you like to use: ";
	cin >> D;
	if (D == "CK") {
		RetrieveFile("Checking");
	}
	else if (D == "SV") {
		RetrieveFile("Savings");
	}
	else if (D == "DB") {
		RetrieveFile("Debit");
	}
	Transaction();
}
void RetrieveFile(string doc) {
	string line,fulldoc;
	fulldoc = doc + ".txt";
	ifstream file(fulldoc);
	if (file.is_open()) {
		while (getline(file, line)) {
			std::cout << "Current Balance: " << line << endl;
			total = stof(line);
			BB = stof(line);
		}
		file.close();
	}
}
void Transaction() {
	string type;
	float amount;
	cout << "Transaction: ";
	cin >> type;
	if (type == "C") {
		cout << "Amount: ";
		cin >> amount;
		total -= amount;
		CA++;
		Check[CA] = amount;
		if (total <= 0) {
			IA++;
			IN[IA] = 10;
		}
		Transaction();
	}
	else if (type == "D") {
		cout << "Amount: ";
		cin >> amount;
		total += amount;
		DA++;
		Deposit[DA] = amount;
		if (total <= 0) {
			IA++;
			IN[IA] = 10;
		}
		Transaction();
	}
	else if (type == "S") {
		cout << "Amount: ";
		cin >> amount;
		total -= amount;
		SA++;
		Service[SA] = amount;
		if (total <= 0) {
			IA++;
			IN[IA] = 10;
		}
		Transaction();
	}
	else if (type == "W") {
		cout << "Amount: ";
		cin >> amount;
		total -= amount;
		WD++;
		Withdrawal[WD] = amount;
		if (total <= 0) {
			IA++;
			IN[IA] = 10;
		}
		Transaction();
	}
	else if (type == "E") {
		End();
	}
	else {
		cout << "Illegal Transaction code..." << endl;
		Transaction();
	}
}
void End() {
	float Checks, Balance, Insufficient, Services, Deposits,Withdrawals;
	Checks = 0;
	Deposits = 0;
	Insufficient = 0;
	Services = 0;
	Withdrawals = 0;
	Balance = BB;
	cout << "=============================================================" << endl;
	cout << "Transaction                 Amount         Balance" << endl;
	cout << "Beginning Balance             " << BB << "            " << BB << endl;
	for (int a = 1; a <= CA; a++) {
		Checks += Check[a];
	}
	Balance -= Checks;
	cout << "Checks                        " << Checks << "             " << Balance << endl;
	for (int a = 1; a <= DA; a++) {
		Deposits += Deposit[a];
	}
	Balance += Deposits;
	cout << "Deposits                      " << Deposits << "             " << Balance << endl;
	for (int a = 1; a <= IA; a++) {
		Insufficient += IN[a];
	}
	for (int a = 1; a <= WD; a++) {
		Withdrawals += Withdrawal[a];
	}
	Balance -= Withdrawals;
	cout << "Withdrawals                   " << Withdrawals << "             " << Balance << endl;
	Balance -= Insufficient;
	cout << "Insufficient Funds            " << Insufficient << "             " << Balance << endl;
	for (int a = 1; a <= SA; a++) {
		Services += Service[a];
	}
	Balance -= Services;
	cout << "Service Charges               " << Services << "             " << Balance << endl;
	cout << "=============================================================" << endl;
	cout << "Account Summary"<< endl;
	cout << "                          Number        Amount" << endl;
	cout << "Beginning balance                       " << BB << endl;
	cout << "Plus Deposits               " << DA << "           " << Deposits << endl;
	cout << "Less Withdrawals            " << WD << "           " << Withdrawals << endl;
	cout << "Ending balance                          " << Balance << endl;
	cout << "=============================================================" << endl;
		system("pause");
}