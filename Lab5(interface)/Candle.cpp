#include "Candle.h"

Candle::Candle(bool shines, std::string name) {
	this->shines = shines;
	this->name = name;
}

bool Candle::getShine() {
	return shines;
}

void Candle::setShine(bool shines) {
	this->shines = shines;
}

std::string Candle::getName() {
	return name;
}