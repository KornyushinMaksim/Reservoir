#pragma once
#include "Reserv.h"
class Data_base
{
	int size;
	Reservoir* data;
	friend bool operator-(Reservoir&, Reservoir&);
public:
	Data_base(const Reservoir* data)
	{
		this->size = size;
		if (data != nullptr) {
			data = new Reservoir[size];
			for (int i = 0; i < size; i++) {
				this->data[i] = data[i];
			}
		}
	}
	Data_base() : size{ 0 }, data{ nullptr } {}

	int get_size_data() { return this->size; }
	Reservoir get_data_data() { return *this->data; }

	void add_reservoir(Reservoir reservoir);
	void del_reservoir(int index);
	Reservoir copy_reservoir(int num);
	bool compare(int num1, int num2);
	string compare_square(int num1, int num2);

	string print_data();
	string short_print_data();

	~Data_base()
	{
		if (data) {
			delete[] data;
		}
	}
};

