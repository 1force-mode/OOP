#include "ElectroFlashlight.h"

ElectroFlashlight::ElectroFlashlight(bool charged, bool shines, std::string name) {
	this->charged = charged;
	this->shines = shines;
	this->name = name;
}

bool ElectroFlashlight::getCharge() {
	return charged;
}

void ElectroFlashlight::setCharge(bool charge) {
	this->charged = charge;
}

std::string ElectroFlashlight::getName() {
	return name;
}


bool ElectroFlashlight::getShine() {
	return shines;
}

void ElectroFlashlight::setShine(bool shines) {
	if (shines == true) {
		if (this->charged == true) {
			this->shines = shines;
		}
	}
	else {
		this->shines = shines;
	}
}