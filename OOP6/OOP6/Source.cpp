#include "Header.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string temp;
	Shop shop;
	Client client;
	Pokup a(&shop, &client);
	shop.Set_items();
	client.Set_client();
	do {
		a.Deal();
		shop.show();
		client.show();
		cout << endl;
		cout << "¬ведите 1, чтобы продолжить, или любой другой символ дл€ завершени€ программы" << endl;
		cin >> temp;
	} while (!temp.compare("1"));
}