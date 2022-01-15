#pragma once
#include"UI.h"

class UICalator :public UI {
private:
	void meniuCalator();
	void meniuFunctionalitatiCalator();
public:
	//UICalator();
	UICalator(ServicePunctDeVizitare& srv, ServiceLocalitati& srv_loc, ServiceRuta& srv_ruta, ServiceObiectivTuristic& srv_obv, Calatorie& calatorie);
	~UICalator() {};

	void runAllMeniuCalator();
};