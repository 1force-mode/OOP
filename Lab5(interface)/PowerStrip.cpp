#include "PowerStrip.h"
#include <iostream>

void PowerStrip::connectDevice(IElectroDevice* device) {
	devices.push_back(device);
}

void PowerStrip::disconnectDevice(int index) {
	if (index < 0 || index >= devices.size()) {
		std::cout << "Invalid index";
		return;
	}
	else {
		devices.erase(devices.begin() + index);
	}
}

void PowerStrip::showConnectedDevices() const{
	if (devices.empty()) {
		std::cout << "No devices connected. \n";
		return;
	}

	std::cout << "Connected devices:\n";
	for (size_t i = 0; i < devices.size(); i++) {
		std::cout << i << ". " << devices[i]->getName() << "\n";
	}
}

void PowerStrip::chargeDevices() {
	for (auto device : devices) {
		device->setCharge(true);
	}
}

