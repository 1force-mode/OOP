#pragma once
#include "IElectroDevice.h"

class ElectricIron : public IElectroDevice {
private:
	bool charged;
	bool works;
	std::string name;
public:
	ElectricIron(bool charged, bool works, std::string name);

	bool getCharge() override;
	void setCharge(bool charge) override;
	std::string getName() override;

	bool getWorks();
	void setWorks(bool works);
};
