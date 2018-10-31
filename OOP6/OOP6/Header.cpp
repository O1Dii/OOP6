#include "Header.h"
using namespace std;

bool Town::show()
{
	cout << "�����: " << this->name << endl;
	return true;
}

bool Shop::show()
{
	this->Town::show();
	cout << "�������: " << this->name << endl;
	if (this->item == nullptr) 
		return false;
	else {
		cout << "� �������� ��������� " << amount << " �����(��):" << endl;
		for (int i = 0; i < amount; i++) {
			cout << "����� �" << i + 1 << " - " << this->item[i].name << ", ���������� - " << this->item[i].amount << ", ���� �� 1 ����� - " << this->item[i].price << endl;
		}
	}
	return true;
}

int Client::Deal(int price)
{
	if (this->money < price)
		return -1;
	else
		this->money -= price;
	return 0;
}

void Client::Set_client()
{
	string a;
	cout << "������� ��� �������" << endl;
	cin >> this->name;
	cout << "������� ���������� ����� �������" << endl;
	do {
		cin >> a;
		this->money = atoi(a.c_str());
	} while (this->money == 0);
}

bool Client::show()
{
	if (name == "0")
		return false;
	else
		cout << "� ������� " << this->name << " " << this->money << " �����" << endl;
	return true;
}

int Shop::Deal(string item, int amount)
{
	int temp;
	for (int i = 0; i < amount; i++) {
		if (this->item[i].name.compare(item) == 0) {
			temp = this->item[i].amount - amount;
			if (temp < 0)
				return -1;									// "������ ������ ����� ���������� ����� ������";
			else {
				this->item[i].amount = temp;
				return this->item[i].price;
			}
		}
	}
	return -2;												// "������� ������ ��� � ������ ��������";
}

void Shop::Set_items()
{
	int n;
	string a;
	if (this->amount == 0) {
		cout << "������� ���������� ���������" << endl;
		do {
			cin >> a;
			this->amount = atoi(a.c_str());
		} while (this->amount == 0);
	}
	bool flag;
	this->item = new Item[amount];
	for (int i = 0; i < amount; i++) {
		cout << "������� �������� ������ �" << i + 1 << endl;
		do {
			flag = false;
			cin >> this->item[i].name;
			for (int j = 0; j < i && flag == false; j++) {
				if (this->item[i].name.compare(this->item[j].name) == 0) {
					cout << "����� ����� ��� ����, ������� �����" << endl;
					flag = true;
				}
			}
		} while (flag == true);
		cout << "������� ���� ������ " << this->item[i].name << endl;
		do {
			cin >> a;
			n = atoi(a.c_str());
		} while (n == 0);
		this->item[i].price = n;
		cout << "������� ���������� ������ " << this->item[i].name << endl;
		do {
			cin >> a;
			n = atoi(a.c_str());
		} while (n == 0);
		this->item[i].amount = n;
	}
	cout << "������� �������� ������� ��������" << endl;
	cin >> this->name;
}

Shop::~Shop()
{
	delete[] this->item;
}

Pokup::Pokup(Shop *shop, Client *client)
{
	this->client = client;
	this->shop = shop;
}

void Pokup::Deal()
{
	int n, amount;
	string a, b;
	if (this->client->show() == 0) {
		cout << "������ �� �����" << endl;
		return;
	}
	cout << endl;
	if (this->shop->show() == 0) {
		cout << "� ������ �������� ��� ��� �������" << endl;
		return;
	}
	cout << endl;
	cout << "������� �������� ������, ������� ���������� ����� ������" << endl;
	cin >> a;
	cout << "������� ���������� ������, ������� ���������� ������ ����������" << endl;
	do {
		cin >> b;
		amount = atoi(b.c_str());
	} while (amount == 0);
	n = this->shop->Deal(a, amount);
	if (n == -1)
		cout << "������ ������ ����� ���������� ����� ������" << endl;
	else if (n == -2)
		cout << "������� ������ ��� � ������ ��������" << endl;
	else {
		n = this->client->Deal(n * amount);
		if (n == -1)
			cout << "� ������� �� ������� �����" << endl;
		else
			cout << "������ ��������� �������" << endl;
	}
}
