#pragma once
#include <vector>
#include "IElectroDevice.h"

class PowerStrip {
private:
	std::vector<IElectroDevice*> devices;
public:
	void connectDevice(IElectroDevice* device);
	void disconnectDevice(int index);
	void showConnectedDevices() const;
	void chargeDevices();
};