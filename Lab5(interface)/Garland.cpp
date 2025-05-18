#include "Garland.h"
#include <iostream>

void Garland::connectDevice(ILightSource* device) {
	l_devices.push_back(device);
}

void Garland::disconnectDevice(int index) {
	if (index < 0 || index >= l_devices.size()) {
		std::cout << "Invalid index";
		return;
	}
	else {
		l_devices[index]->setShine(false);
		l_devices.erase(l_devices.begin() + index);
	}
}

void Garland::showConnectedDevices() const {
	if (l_devices.empty()) {
		std::cout << "No devices connected. \n";
		return;
	}

	std::cout << "Connected devices:\n";
	for (size_t i = 0; i < l_devices.size(); i++) {
		std::cout << i << ". " << l_devices[i]->getName() << "\n";
	}
}

void Garland::turnOnGarland() {
	for (auto device : l_devices) {
		device->setShine(true);
	}
}
void Garland::turnOffGarland() {
	for (auto device : l_devices) {
		device->setShine(false);
	}
}


