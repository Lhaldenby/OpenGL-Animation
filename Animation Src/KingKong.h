#ifndef ___KingKong__
#define ___KingKong__

#define _USE_MATH_DEFINES
#include "DisplayableObject.h"
#include "Animation.h"
#include <cmath>
#include <string>

using namespace std;

class KingKong : 
	public DisplayableObject,
	public Animation
{
public:
	KingKong();
	~KingKong() {} ;
	void display();
	void update(float dT);
private:
	float animationTime;
	float leftShoulder, rightShoulder, leftElbow, rightElbow;
	float leftHip, rightHip, rightKnee, leftKnee;

	void drawKong();
	void drawBody();
	void drawHead();
	void drawLeftArm();
	void drawLeftLeg();
	void drawRightArm();
	void drawRightLeg();
};

#endif



	
