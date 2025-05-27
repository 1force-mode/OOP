#pragma once
#include "ILightSource.h"

class Candle : public ILightSource {
private:
	bool shines;
	std::string name;
public:
	Candle(bool shines, std::string name);

	bool getShine() override;
	void setShine(bool shine) override;
	std::string getName() override;
};
