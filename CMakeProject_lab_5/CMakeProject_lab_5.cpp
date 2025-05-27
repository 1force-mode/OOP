#include <iostream>
#include "PowerStrip.h"
#include "Garland.h"
#include "IElectroDevice.h"
#include "ILightSource.h"
#include "Candle.h"
#include "ElectricIron.h"
#include "ElectroFlashlight.h"
#include "Flashlight.h"
#include "KeroseneLamp.h"
#include "LightBulb.h"

/*
Определение необходимых классов
Интерфейсы:
+IElectroDevice (содержит методы по зарядке и имя)
+ILightSource (содержит методы по свечению и имя)

Электроприборы:
+ElectroFlashlight - электрический фонарик (свечение, зарядка, имя)
+LightBulb - лапмочка (свечение, зарядка, имя)
+ElectricIron - электроутюг (работа, зарядка, имя)
У каждого электроприбора будут переопределённые методы интерфейса


Светящиеся приборы:
+KeroseneLamp - керосиновая лампа
+Candle - свеча
+Flashlight - фонарик

Контейнеры:
+PowerStrip - сетевой фильтр
+Garland - гирлянда
*/


//точка вызова проекта, где будет моделироваться наш проект
int main()
{
	PowerStrip powerStrip;
	Garland garland;

	ElectroFlashlight* electroFlashlight = new ElectroFlashlight(false, false, "electro Fonarik");
	LightBulb* lightBulb = new LightBulb(false, false, "Lampochka");
	ElectricIron* electricIron = new ElectricIron(false, false, "Ytug");

	KeroseneLamp* keroseneLamp = new KeroseneLamp(false, "Kerosinovay lampa");
	Candle* candle = new Candle(false, "Svechka");
	Flashlight* flashLight = new Flashlight(false, "Fonarik");


	powerStrip.connectDevice(electroFlashlight);
	powerStrip.connectDevice(electricIron);
	powerStrip.connectDevice(lightBulb);

	powerStrip.showConnectedDevices();

	std::cout << electroFlashlight->getCharge() << "\n";
	std::cout << lightBulb->getCharge() << "\n";
	std::cout << electricIron->getCharge() << "\n";

	powerStrip.chargeDevices();

	std::cout << electroFlashlight->getCharge() << "\n";
	std::cout << lightBulb->getCharge() << "\n";
	std::cout << electricIron->getCharge() << "\n";

	powerStrip.disconnectDevice(0);
	powerStrip.disconnectDevice(0);
	powerStrip.disconnectDevice(0);

	powerStrip.showConnectedDevices();

	std::cout << electroFlashlight->getCharge() << "\n";
	std::cout << lightBulb->getCharge() << "\n";
	std::cout << electricIron->getCharge() << "\n";

	garland.connectDevice(electroFlashlight);
	garland.connectDevice(lightBulb);
	garland.connectDevice(keroseneLamp);
	garland.connectDevice(candle);
	garland.connectDevice(flashLight);

	garland.showConnectedDevices();

	std::cout << electroFlashlight->getShine() << "\n";
	std::cout << lightBulb->getShine() << "\n";
	std::cout << keroseneLamp->getShine() << "\n";
	std::cout << candle->getShine() << "\n";
	std::cout << flashLight->getShine() << "\n";

	garland.turnOnGarland();

	std::cout << electroFlashlight->getShine() << "\n";
	std::cout << lightBulb->getShine() << "\n";
	std::cout << keroseneLamp->getShine() << "\n";
	std::cout << candle->getShine() << "\n";
	std::cout << flashLight->getShine() << "\n";

	garland.turnOffGarland();

	std::cout << electroFlashlight->getShine() << "\n";
	std::cout << lightBulb->getShine() << "\n";
	std::cout << keroseneLamp->getShine() << "\n";
	std::cout << candle->getShine() << "\n";
	std::cout << flashLight->getShine() << "\n";

	garland.disconnectDevice(0);
	garland.disconnectDevice(0);
	garland.disconnectDevice(0);
	garland.disconnectDevice(0);
	garland.disconnectDevice(0);

	garland.showConnectedDevices();

	std::cout << electroFlashlight->getShine() << "\n";
	std::cout << lightBulb->getShine() << "\n";
	std::cout << keroseneLamp->getShine() << "\n";
	std::cout << candle->getShine() << "\n";
	std::cout << flashLight->getShine() << "\n";
}
