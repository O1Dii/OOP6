#pragma once
/*
4. Разработать иерархию классов(«Город», «Магазин», «Банк», «Покупатель»).
Класс «Город» является базовым для классов «Магазин», «Банк», а они являются базовыми для класса «Покупатель».
Содержимое классов следующее :
*данные класса «Город» – название города, методы – конструкторы, деструктор, show();
*данные класса «Магазин» – наименование нескольких товаров(массив), цена и количество каждого из товаров, методы – конструкторы, деструктор, show();
*данные класса «Банк» – номер счета и сумма на счете, методы – конструкторы, деструктор, show(), popolnenie_sheta() (пополнение счета в банке);
*данные класса «Покупатель» – сумма сделанной покупки, методы – конструкторы, деструктор, show(), pokupka() (совершение покупки товара).
Каждый из методов show() отображает содержимое своего класса и вызывает show() базового для него класса.
5. При иерархии классов, описанной в предыдущем задании, продумать и реализовать возможность создания нескольких объектов класса Pokup,
таким образом, чтобы результат покупки каждым предыдущим объектом изменял информацию о количестве товара для последующих объектов.
*/

#include <string>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

struct Item {
	string name;
	int price;
	int amount;
};

class Town {
private:
	string name = "Минск";
public:
	Town() {};
	virtual ~Town() {};
	virtual bool show();
};

class Shop : public Town {
private:
	string name;
	int amount = 0;
	Item *item;
public:
	int Deal(string, int);
	Shop() : item(nullptr) {};
	Shop(int amount) : item(nullptr) { this->amount = amount; };
	void Set_items();
	~Shop();
	bool show();
};

class Client {
private:
	string name = "0";
	int money;
public:
	int Deal(int);
	Client() {};
	~Client() {};
	void Set_client();
	bool show();
};

class Pokup{
private:
	Shop *shop;
	Client *client;
public:
	Pokup(Shop*, Client*);
	//Pokup(int i) : Shop(i) {};
	//Pokup() : Shop() {};
	void Deal();
};