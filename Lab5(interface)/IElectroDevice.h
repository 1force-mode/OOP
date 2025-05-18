#pragma once
#include <string>

class IElectroDevice {
public:
	virtual bool getCharge() = 0;
	virtual void setCharge(bool charge) = 0;
	virtual std::string getName() = 0;

	virtual ~IElectroDevice() = default;
};
