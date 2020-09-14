#ifndef ___Airplane__
#define ___Airplane__

#define _USE_MATH_DEFINES
#include "DisplayableObject.h"
#include "Animation.h"
#include <cmath>
#include <string>

using namespace std;

class Airplane : 
	public DisplayableObject,
	public Animation
{
public:
	Airplane();
	~Airplane() {} ;
	void display();
	void update(float dT);
private:
	float animationTime;
	float propRotation;
	float aT;

	void drawAirplane();
	void drawPlaneBody();
	void drawFrontwing();
	void drawPropeller();
	void drawBackWing();


};
#endif
