#ifndef ___Stage__
#define ___Stage__

#include <GL/glut.h>

#include "DisplayableObject.h"

class Stage : public DisplayableObject
{
public:
	Stage();
	~Stage() {};
	void display();
private:
	void drawStage();
};
#endif