#include "CityScene.h"
using namespace std;

void setup()
{
	width = 1000;                                       // initialise global window variables
	height = 700;
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);      // enable 3D rendering and double buffering
	glutInitWindowSize(width, height);                  // set window size
	glutCreateWindow("City Scene");                       // create and show window (named MyScene)
	glEnable(GL_DEPTH_TEST);

	cameraRadius();
	Stage* stage = new Stage();
	stage->position(0.f, 0.f, 0.f);
	stage->size(camrad);
	objects["_stage"] = stage;

	Airplane* plane = new Airplane();
	plane->position(-50.f, 600.f, 0.f);
	plane->size(15.f);
	objects["Airplane"] = plane;

	Airplane* plane2 = new Airplane();
	plane2->position(50.f, 600.f, 0.f);
	plane2->size(15.f);
	objects["Airplane2"] = plane2;

	KingKong* kong = new KingKong();
	kong->position(0.f, 400.f, 0.f);
	kong->size(30.f);
	objects["KingKong"] = kong;

	reshape(width, height);

	prevTime = glutGet(GLUT_ELAPSED_TIME); //animation time

	cen[0] = 0.f;              // sets model centre (pointing at the origin)
	cen[1] = 0.f;
	cen[2] = 0.f;


}

void draw()
{
	glClearColor(1.f, 1.f, 1.f, 1.f);                   // set white background colour
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear buffers
	glMatrixMode(GL_MODELVIEW);                         // set for model and viewing operations
	glLoadIdentity();   
	// reset drawing
	positionCamera();

	glTranslatef(0.f, -height / 2.f, 0.f);
	//glTranslatef(0.f, -4.f, -10.f);                     // translate back and to the bottom of the screen
	glColor3f(0.f, 0.f, 0.f);                           // set draw colour to black

	float dT = runtime();
	Animation* ani_obj;

	for (map <string, DisplayableObject*>::iterator itr = objects.begin(); itr != objects.end(); ++itr) {
		ani_obj = dynamic_cast<Animation*>(itr->second);
		if (ani_obj != NULL) ani_obj->update(dT);
		itr->second->display();
	}

	checkGLError();
	glutSwapBuffers();
}

void reshape(int _width, int _height)
{
	width = _width;                // update global dimension variables
	height = _height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();               // reset matrix
	gluPerspective(60.0, (GLdouble)width / (GLdouble)height, 1.0, 4000.0);
	glMatrixMode(GL_MODELVIEW);     // return matrix mode to modelling and viewing
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);          // Initialise GL environment
	setup();                        // Call additional initialisation commands
	glutDisplayFunc(draw);          // Register scene to render contents of draw() function
	glutIdleFunc(draw);
	glutReshapeFunc(reshape);
	checkGLError();                 // Check any OpenGL errors in initialisation

	glutKeyboardFunc(keyPressed);       // ASCII key handling
	glutSpecialFunc(keyPressed);		// Coded key handling

	glutMainLoop();                 // Begin rendering sequence

	destroyObjects();

	return 0;
}

float runtime()
{
	int currTime = glutGet(GLUT_ELAPSED_TIME);
	float dT = static_cast<float>(currTime - prevTime) / 1000.f;
	prevTime = currTime;
	return dT;
}

void positionCamera()
{
	cameraRadius();                                 // calculate current camera position
	eye[0] = camrad*sin(camangle);                  // set eye x (at camrad*sin(0)[ = 0])
	eye[1] = cen[1];                                // set eye y (at 0)
	eye[2] = camrad*cos(camangle);                  // set eye z (at camrad*cos(0)[ = 1])
	gluLookAt(eye[0], eye[1], eye[2],               // eye position
		cen[0], cen[1], cen[2],               // point that you are looking at (origin)
		0.f, 1.f, 0.f);                       // up vector (0, 1 0)
}

void cameraRadius()
{
	camrad = (height / 2.f) / tan(M_PI / 8.f);      // calcualte camera radius based on height
}

void keyPressed(int keyCode, int xm, int ym)
{           // Special (coded) key pressed
	float incr = (float)M_PI / 36.f;   // increment angle by 5 degrees
	if (keyCode == GLUT_KEY_LEFT)
	{                      // left arrow (move camera left around scene)
		camangle -= incr;     // decrement camera angle
	}
	else if (keyCode == GLUT_KEY_RIGHT)
	{              // right arrow (move camera right around scene)
		camangle += incr;     // increment camera angle
	}
}

void keyPressed(unsigned char key, int xm, int ym)
{     // ASCII key pressed
	float incr = (float)M_PI / 18.f;
	if (key == ' ')
	{                                     // if space bar pressed
		camangle = 0.f;                   //reset angle to 0.0
	}
	else if (key == 'a')
	{
		camangle -= incr;
	}
	else if (key == 'd')
	{
		camangle += incr;
	}
}

void destroyObjects()
{
	for (map <string, DisplayableObject*>::iterator itr = objects.begin(); itr != objects.end(); ++itr) {
		delete itr->second;
	}
	objects.clear();
}

void checkGLError()
{
	int e = 0;                      // Error count
	GLenum error = glGetError();    // Get first glError
	while (GL_NO_ERROR != error)    // Loop until no errors found
	{
		e++;
		printf("GL Error %i: %s\n", e, gluErrorString(error)); // Display error string
		error = glGetError();                                  // Get next glError
	}
}
