#pragma once
#include "ILightSource.h"

class Flashlight : public ILightSource {
private:
	bool shines;
	std::string name;
public:
	Flashlight(bool shines, std::string name);

	bool getShine() override;
	void setShine(bool shine) override;
	std::string getName() override;
};
