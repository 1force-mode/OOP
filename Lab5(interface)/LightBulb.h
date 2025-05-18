#pragma once
#include "IElectroDevice.h"
#include "ILightSource.h"

class LightBulb : public IElectroDevice, public ILightSource {
private:
	bool charged;
	bool shines;
	std::string name;
public:
	LightBulb(bool charged, bool shines, std::string name);

	bool getCharge() override;
	void setCharge(bool charge) override;
	std::string getName() override;

	bool getShine() override;
	void setShine(bool shines) override;
};
