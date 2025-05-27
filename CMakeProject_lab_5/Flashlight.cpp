#include "Flashlight.h"

Flashlight::Flashlight(bool shines, std::string name) {
	this->shines = shines;
	this->name = name;
}

bool Flashlight::getShine() {
	return shines;
}

void Flashlight::setShine(bool shines) {
	this->shines = shines;
}

std::string Flashlight::getName() {
	return name;
}