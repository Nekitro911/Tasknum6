// Tasknum6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <conio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <time.h>
using std::cout;
using std::cin;
using std::endl;
struct Elem
{
	int num;
	Elem* next;
};
const int m = 11;
Elem* table[m];
const int n = 30;
int a[n];

int HashF(int num)
{
	return num % m;
}

Elem* NewElem(int num)
{
	Elem* p = new Elem;
	p->num = num;
	p->next = NULL;
	return p;
}
void CreateTable()
{
	int i;
	for (i = 0; i < m; i++)
		table[i] = NULL;
	for (i = 0; i < n; i++) {
		int hashF = HashF(a[i]);
		if (table[hashF] == NULL)
			table[hashF] = NewElem(a[i]);
		else {
			Elem* p = table[hashF];
			int found = 0;
			if (p->num == a[i])
				found = 1;
			while (!found && p->next != NULL)
				if (p->next->num == a[i])
					found = 1;
				else
					p = p->next;
			if (!found)
				p->next = NewElem(a[i]);
		}
	}
}

void ShowTable()
{
	cout << "Hesh-tablica - metod priamogo sviazivania:\n\n";
	int i;
	for (i = 0; i < m; i++) {
		cout << i << ":";
		Elem* p = table[i];
		while (p != NULL) {
			cout << "  ----> " << p->num;
			p = p->next;
		}
		cout << "\n";
	}
}
bool Search(int num)
{
	int hashF = HashF(num);
	Elem* p = table[hashF];
	while (p != NULL) {
		if (p->num == num)
			return true;
		p = p->next;
	}
	return false;
}
int main()
{
	system("mode con cols=80 lines=30");
	system("color 0");
	int i;
	srand(time(0));
	for (i = 0; i < n; i++)
		a[i] = rand() % 30;
	CreateTable();
	ShowTable();
	int num;
	cout << "\nVvedite chislo dlia poiska: ";
	cin >> num;
	if (Search(num))
		cout << "\nChislo naideno!";
	else
		cout << "\nЧChislo ne naideno!";

	_getch();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
