#pragma once
/*
4. ����������� �������� �������(������, ��������, �����, ������������).
����� ������ �������� ������� ��� ������� ��������, �����, � ��� �������� �������� ��� ������ ������������.
���������� ������� ��������� :
*������ ������ ������ � �������� ������, ������ � ������������, ����������, show();
*������ ������ �������� � ������������ ���������� �������(������), ���� � ���������� ������� �� �������, ������ � ������������, ����������, show();
*������ ������ ����� � ����� ����� � ����� �� �����, ������ � ������������, ����������, show(), popolnenie_sheta() (���������� ����� � �����);
*������ ������ ������������ � ����� ��������� �������, ������ � ������������, ����������, show(), pokupka() (���������� ������� ������).
������ �� ������� show() ���������� ���������� ������ ������ � �������� show() �������� ��� ���� ������.
5. ��� �������� �������, ��������� � ���������� �������, ��������� � ����������� ����������� �������� ���������� �������� ������ Pokup,
����� �������, ����� ��������� ������� ������ ���������� �������� ������� ���������� � ���������� ������ ��� ����������� ��������.
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
	string name = "�����";
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