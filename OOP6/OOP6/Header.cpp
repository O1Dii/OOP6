#include "Header.h"
using namespace std;

bool Town::show()
{
	cout << "Город: " << this->name << endl;
	return true;
}

bool Shop::show()
{
	this->Town::show();
	cout << "Магазин: " << this->name << endl;
	if (this->item == nullptr) 
		return false;
	else {
		cout << "В магазине находится " << amount << " товар(ов):" << endl;
		for (int i = 0; i < amount; i++) {
			cout << "Товар №" << i + 1 << " - " << this->item[i].name << ", количество - " << this->item[i].amount << ", цена за 1 штуку - " << this->item[i].price << endl;
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
	cout << "Введите имя клиента" << endl;
	cin >> this->name;
	cout << "Введите количество денег клиента" << endl;
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
		cout << "У клиента " << this->name << " " << this->money << " денег" << endl;
	return true;
}

int Shop::Deal(string item, int amount)
{
	int temp;
	for (int i = 0; i < amount; i++) {
		if (this->item[i].name.compare(item) == 0) {
			temp = this->item[i].amount - amount;
			if (temp < 0)
				return -1;									// "Нельзя купить такое количество этого товара";
			else {
				this->item[i].amount = temp;
				return this->item[i].price;
			}
		}
	}
	return -2;												// "Данного товара нет в данном магазине";
}

void Shop::Set_items()
{
	int n;
	string a;
	if (this->amount == 0) {
		cout << "Введите количество предметов" << endl;
		do {
			cin >> a;
			this->amount = atoi(a.c_str());
		} while (this->amount == 0);
	}
	bool flag;
	this->item = new Item[amount];
	for (int i = 0; i < amount; i++) {
		cout << "Введите название товара №" << i + 1 << endl;
		do {
			flag = false;
			cin >> this->item[i].name;
			for (int j = 0; j < i && flag == false; j++) {
				if (this->item[i].name.compare(this->item[j].name) == 0) {
					cout << "Такой товар уже есть, введите новый" << endl;
					flag = true;
				}
			}
		} while (flag == true);
		cout << "Введите цену товара " << this->item[i].name << endl;
		do {
			cin >> a;
			n = atoi(a.c_str());
		} while (n == 0);
		this->item[i].price = n;
		cout << "Введите количество товара " << this->item[i].name << endl;
		do {
			cin >> a;
			n = atoi(a.c_str());
		} while (n == 0);
		this->item[i].amount = n;
	}
	cout << "Введите название данного магазина" << endl;
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
		cout << "Клиент не задан" << endl;
		return;
	}
	cout << endl;
	if (this->shop->show() == 0) {
		cout << "В данном магазине ещё нет товаров" << endl;
		return;
	}
	cout << endl;
	cout << "Введите название товара, который покупатель хочет купить" << endl;
	cin >> a;
	cout << "Введите количество товара, которое собирается купить покупатель" << endl;
	do {
		cin >> b;
		amount = atoi(b.c_str());
	} while (amount == 0);
	n = this->shop->Deal(a, amount);
	if (n == -1)
		cout << "Нельзя купить такое количество этого товара" << endl;
	else if (n == -2)
		cout << "Данного товара нет в данном магазине" << endl;
	else {
		n = this->client->Deal(n * amount);
		if (n == -1)
			cout << "У клиента не хватает денег" << endl;
		else
			cout << "Сделка совершена успешно" << endl;
	}
}
