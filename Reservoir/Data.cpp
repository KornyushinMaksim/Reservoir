#include "Data.h"

void Data_base::add_reservoir(Reservoir reservoir)
{
	if (data == nullptr) {
		size = 1;
		data = new Reservoir[size];
		*data = reservoir;
	}
	else {
		Reservoir* new_data = new Reservoir[size + 1];
		for (int i = 0; i < size; i++) {
			new_data[i] = data[i];
		}
		new_data[size] = reservoir;
		delete[] data;
		data = new_data;
		size++;
	}
}

void Data_base::del_reservoir(int num)
{
	Reservoir* new_data = new Reservoir[size - 1];
	for (int i = 0, j = 0; i < size - 1; i++, j++) {
		if (i != num - 1) {
			new_data[i] = this->data[j];
		}
		else {
			new_data[i] = this->data[++j];
		}
	}
	delete[] data;
	data = new_data;
	size--;
}

Reservoir Data_base::copy_reservoir(int num)
{
	Reservoir new_obj;
	for (int i = 0; i < size; i++) {
		if (i == num - 1) {
			new_obj = data[i];
		}
	}
	return new_obj;
}

bool Data_base::compare(int num1, int num2)
{
	Reservoir obj1;
	Reservoir obj2;
	for (int i = 0; i < size; i++) {
		if (i == num1 - 1) {
			obj1 = data[i];
		}
		else if (i == num2 - 1) {
			obj2 = data[i];
		}
	}
	return obj1 - obj2;
}

string Data_base::compare_square(int num1, int num2)
{
	Reservoir obj1, obj2;
	for (int i = 0; i < size; i++) {
		if (i == num1) {
			obj1 = data[i];
		}
		if (i == num2) {
			obj2 = data[i];
		}
	}

	return obj1/obj2;
}

string Data_base::print_data()
{
	string s = "";
	for (int i = 0; i < size; i++) {
		s.append(data[i].print());
		s.append("-----\n");
	}
	return s;
}

string Data_base::short_print_data()
{
	string s = "";
	for (int i = 0; i < size; i++) {
		s.append(data[i].short_print());
	}
	return s;
}
