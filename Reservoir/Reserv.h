#pragma once
#include <iostream>
#include <string>
using namespace std;

class Reservoir
{
	char* name;
	char* type;
	float width;//ширина
	float length;// длина
	float depth;// глубина
public:
	Reservoir(const char* name, const char* type, float width, float length, float depth)
	{
		if (name) {
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
		if (type) {
			this->type = new char[strlen(type) + 1];
			strcpy_s(this->type, strlen(type) + 1, type);
		}
		this->width = width;
		this->length = length;
		this->depth = depth;
	}
	Reservoir(const Reservoir& other)
	{
		if (this->name != other.name) {
			this->name = new char[strlen(other.name) + 1];
			strcpy_s(this->name, strlen(other.name) + 1, other.name);
		}
		if (this->type != other.type) {
			this->type = new char[strlen(other.type) + 1];
			strcpy_s(this->type, strlen(other.type) + 1, other.type);
		}
		this->width = other.width;
		this->length = other.length;
		this->depth = other.depth;
	}
	Reservoir() : name{ nullptr }, type{ nullptr }, width{ 0 }, length{ 0 }, depth{ 0 } {}

	char* get_name() { return this->name; }

	float volume();
	float square();
	bool operator-(Reservoir& reservoir);
	string operator/(Reservoir& reservoir);
	Reservoir& operator=(const Reservoir& reservoir);
	string print();

	~Reservoir()
	{
		if (name) {
			delete[] name;
		}
	}
};

