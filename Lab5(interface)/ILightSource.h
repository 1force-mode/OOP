#pragma once
#include <string>

class ILightSource {
public:
	virtual bool getShine() = 0;
	virtual void setShine(bool shines) = 0;
	virtual std::string getName() = 0;

	virtual ~ILightSource() = default;
};
