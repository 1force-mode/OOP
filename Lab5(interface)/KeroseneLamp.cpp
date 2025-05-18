#include "KeroseneLamp.h"

KeroseneLamp::KeroseneLamp(bool shines, std::string name) {
	this->shines = shines;
	this->name = name;
}

bool KeroseneLamp::getShine() {
	return shines;
}

void KeroseneLamp::setShine(bool shines) {
	this->shines = shines;
}

std::string KeroseneLamp::getName() {
	return name;
}