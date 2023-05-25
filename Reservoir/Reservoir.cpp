//      Задание.
//      Разработать класс Reservoir(водоем).Класс должен обязательно иметь поле «название».Класс должен содержать :
//      конструктор по умолчанию, конструктор с параметрами,
//      при необходимости реализовать деструктор и конструктор копирования.
//      Добавить методы для :
//      1. Определения приблизительного объема(ширина * длина * максимальная глубина);
//      2. Определения площади водной поверхности;
//      3. Метод для проверки относятся ли водоемы к одному
//      типу(море - море; бассейн - пруд);
//      4. Для сравнения площади водной поверхности водоемов
//      одного типа;
//      5. Для копирования объектов;
//      6. Остальные методы на усмотрение разработчика(методы set и get).
//      Написать интерфейс для работы с классом.Реализовать
//      динамический массив объектов класса с возможностью
//      добавления, удаления объектов из массива.Реализовать
//      возможность записи информации об объектах массива
//      в текстовый файл, бинарный файл.
//      Используйте explicit конструктор и константные функции-члены(например, для отображения данных о водоёме и т.д.)

#include <iostream>
#include <string>
#include "Reserv.h"
#include "Data.h"
using namespace std;

int func_enter_num() {
	cout << "Введите пункт для действия: ";
	int num;
	cin >> num;
	return num;
}

Reservoir enter_reservoir() {
	char name[40];
	char* type{ nullptr };
	int width;
	int length;
	int depth;
	cin.get();
	cout << "Название: ";
	cin.getline(name, 40);
	cout << "Тип водоёма (нужное выбрать: 1-пруд, 2-озеро, 3-море): ";
	int key;
	cin >> key;
	if (key == 1) {
		char str[] = { "пруд" };
		type = new char[strlen(str) + 1];
		strcpy_s(type, strlen(str) + 1, str);
	}
	if (key == 2) {
		char str[] = { "озеро" };
		type = new char[strlen(str) + 1];
		strcpy_s(type, strlen(str) + 1, str);
	}
	if (key == 3) {
		char str[] = { "море" };
		type = new char[strlen(str) + 1];
		strcpy_s(type, strlen(str) + 1, str);
	}
	cout << "Ширина водоёма (м): ";
	cin >> width;
	cout << "Длина водоёма (м): ";
	cin >> length;
	cout << "Глубина водоёма (м): ";
	cin >> depth;
	return Reservoir (name, type, width, length, depth);
}

void func_interface(Data_base& data) {
	bool flag = true;
	while (flag) {
		cout << "1. Добавить\n2. Удалить\n3. Скопировать\n4. Проверка по типу\n5. Сравнение площадей\n6. Полная информация водоёма\n7. Выйти\n";
		int key;
		cin >> key;
		switch (key) {
		case 1:
			data.add_reservoir(enter_reservoir());
			break;
		case 2:
			data.del_reservoir(func_enter_num());
				break;
		case 3:
			cout << data.short_print_data() << endl;
			data.add_reservoir(data.copy_reservoir(func_enter_num()));
			break;
		case 4:
			cout << data.short_print_data() << endl;
			if (data.compare(func_enter_num(), func_enter_num())) {
				cout << "Водоёмы одного типа" << endl;
			}
			else {
				cout << "Водоёмы разного типа" << endl;
			}
			break;
		case 5:
			cout << data.short_print_data() << endl;
			data.compare_square(func_enter_num(), func_enter_num());
			break;
		case 6:
			cout << data.print_data();
			break;
		case 7:
			flag = false;
			break;
		default:
			break;
		}
	}
}

int main()
{
	system("chcp 1251>nul");
	Data_base data;
	func_interface(data);
	cout << data.print_data() << endl;

//	Reservoir obj1("Байкал", "озеро", 2, 3, 3);
//	Reservoir obj2("Азовское", "море", 3, 3, 3);
//	Reservoir obj3;
//	obj3 = obj1;//копирование 
//	cout << obj1.print() << endl << obj2.print() << endl << obj3.print() << endl;
//
//	if (obj1 - obj2) {//сравнение типов
//		cout << "Водоёмы одного типа" << endl;
//	}
//	else {
//		cout << "Водоёмы разного типа" << endl;
//	}
//
//	cout << obj1 / obj2 << endl;//сравнение площади одного типа
}
