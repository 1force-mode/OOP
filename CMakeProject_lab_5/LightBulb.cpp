#include "LightBulb.h"

LightBulb::LightBulb(bool charged, bool shines, std::string name) {
	this->charged = charged;
	this->shines = shines;
	this->name = name;
}

bool LightBulb::getCharge(){
	return charged;
}

void LightBulb::setCharge(bool charge) {
	this->charged = charge;
}

std::string LightBulb::getName() {
	return name;
}


bool LightBulb::getShine() {
	return shines;
}

void LightBulb::setShine(bool shines) {
	if (shines == true) {
		if (this->charged == true) {
			this->shines = shines;
		}
	}
	else {
		this->shines = shines;
	}
}