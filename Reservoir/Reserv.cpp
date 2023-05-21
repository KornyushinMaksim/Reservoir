#include "Reserv.h"

float Reservoir::volume()
{
	return this->width * this->length * this->depth;
}

float Reservoir::square()
{
	return this->width * this->length;
}

bool Reservoir::operator-(Reservoir& reservoir)
{
	bool flag;
	strstr(this->type, reservoir.type) ? flag = true : flag = false;
	return flag;
}

string Reservoir::operator/(Reservoir& reservoir)
{
	if (strstr(this->type, reservoir.type)) {
		if (this->square() > reservoir.square()) {
			return this->print();
		}
		else {
			return reservoir.print();
		}
	}
	else {
		string s = "Нельзя сравнить! Разные типы!";
		return s;
	}
}

Reservoir& Reservoir::operator=(const Reservoir& reservoir)
{
	if (this->name != reservoir.name) {
		this->name = new char[strlen(reservoir.name) + 1];
		strcpy_s(this->name, strlen(reservoir.name) + 1, reservoir.name);
	}
	if (this->type != reservoir.type) {
		this->type = new char[strlen(reservoir.type) + 1];
		strcpy_s(this->type, strlen(reservoir.type) + 1, reservoir.type);
	}
	this->width = reservoir.width;
	this->length = reservoir.length;
	this->depth = reservoir.depth;
	return *this;
}

string Reservoir::print()
{
	string s = "";
	s.append(this->name);
	s.append(" (");
	s.append(this->type);
	s.append(")\nширина ");
	s.append(to_string(this->width));
	s.append("\nдлина ");
	s.append(to_string(this->length));
	s.append("\nглубина ");
	s.append(to_string(this->depth));
	s.append("\n");
	return s;
}
