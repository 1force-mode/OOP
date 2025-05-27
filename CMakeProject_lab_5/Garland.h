#pragma once
#include <vector>

#include "ILightSource.h"

class Garland {
private:
	std::vector<ILightSource*> l_devices;
public:
	void connectDevice(ILightSource* device);
	void disconnectDevice(int index);
	void showConnectedDevices() const;
	void turnOnGarland();
	void turnOffGarland();
};
