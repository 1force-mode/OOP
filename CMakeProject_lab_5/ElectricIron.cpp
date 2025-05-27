#include "ElectricIron.h"

ElectricIron::ElectricIron(bool charged, bool works, std::string name) {
	this->charged = charged;
	this->works = works;
	this->name = name;
}

bool ElectricIron::getCharge() {
	return charged;
}

void ElectricIron::setCharge(bool charge) {
	this->charged = charge;
}

std::string ElectricIron::getName() {
	return name;
}


bool ElectricIron::getWorks() {
	return works;
}

void ElectricIron::setWorks(bool works) {
	if (works == true) {
		if (this->charged = true) {
			this->works = works;
		}
	}
	else {
		this->works = works;
	}
}