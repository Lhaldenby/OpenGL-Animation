#ifndef ___CityScene__
#define ___CityScene__

#include <GL/glut.h> // include freeglut libraries

#define _USE_MATH_DEFINES
#include <cmath>
#include <map>
#include <string>

#include "KingKong.h"
#include "Airplane.h"
#include "Stage.h"
#include "TextureManager.h"

int width,  height;
int prevTime;

map<string, DisplayableObject*> objects;

void setup();
void draw();
void reshape(int width, int height);

int main(int argc, char **argv);
float runtime();

void checkGLError();                        // Prints any OpenGL errors to console
void destroyObjects();

float camrad, camangle = 0.f;
float eye[3];
float cen[3];

void positionCamera();
void cameraRadius();
void keyPressed(int keyCode, int xm, int ym);
void keyPressed(unsigned char key, int xm, int ym);
#endif

