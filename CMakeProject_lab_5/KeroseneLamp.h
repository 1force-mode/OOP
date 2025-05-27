#pragma once
#include "ILightSource.h"

class KeroseneLamp : public ILightSource {
private:
	bool shines;
	std::string name;
public:
	KeroseneLamp(bool shines, std::string name);

	bool getShine() override;
	void setShine(bool shine) override;
	std::string getName() override;
};
