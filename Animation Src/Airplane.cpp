#include "Airplane.h"


Airplane::Airplane() : // Constructor
	animationTime(2.f), propRotation(360.f)
{
	
}

void Airplane::update(float dT)
{
	aT = fmod(aT + dT, animationTime);
	float aS = 8.f*aT / animationTime;

	if (aS < 1.f ) {
		propRotation = 315.f;

	}
	else if (aS < 2.f ) {
		propRotation = 270.f;
	}
	else if (aS < 3.f ) {
		propRotation = 225.f;
	}
	else if (aS < 4.f ) {
		propRotation = 180.f;
	}
	else if (aS < 5.f ) {
		propRotation = 135.f;
	}
	else if (aS < 6.f ) {
		propRotation = 90.f;
	}
	else if (aS < 7.f ) {
		propRotation = 45.f;
	}
	else {
		propRotation = 0.f;
	}
}

void Airplane::display()
{
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);                   // save style attributes (and more)
		glColor3f(1.f, 0.2f, 0.2f);                        // colour airplane red

		// Project from Object Space to World Space
		glTranslatef(pos[0], pos[1], pos[2]);   // position
		glScalef(scale[0], scale[1], scale[2]); // scale
		glRotatef(rotation[1], 0.f, 1.f, 0.f);  // set orientation (Y)
		glRotatef(rotation[2], 0.f, 0.f, 1.f);  // set orientation (Z)
		glRotatef(rotation[0], 1.f, 0.f, 0.f);  // set orientation (X)

		drawAirplane();

		glPopAttrib();
	glPopMatrix();
}
	
void Airplane::drawAirplane()
{
	glTranslatef(0.f, 2.f, 0.f);
	glPushMatrix();
		drawPlaneBody();

		//front wing
		glPushMatrix(); //centre body
			glTranslatef(0.2f, 0.f, 0.f);
			drawFrontwing();
		glPopMatrix(); //back to centre

		//back wing
		glPushMatrix(); //save centre
			glTranslatef(-1.5f, 0.f, 0.f);
			drawBackWing();
		glPopMatrix(); //back to centre

		//propeller
		glPushMatrix(); //save centre
			glTranslatef(2.f, 0.f, 0.f); //front of plane
			drawPropeller();
		glPopMatrix(); //back to centre

	glPopMatrix(); //back to start state
}

void Airplane::drawPlaneBody() 
{
	glPushMatrix();
		glScalef(4.f,1.f,1.f);
		glutSolidCube(1.f);
	glPopMatrix();
}

void Airplane::drawFrontwing()
{
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glColor3f(0.6f, 0.f, 0.f);
			glScalef(1.f, 0.2f, 4.f);
			glutSolidCube(1.f);
		glPopAttrib();
	glPopMatrix();
}

void Airplane::drawBackWing()
{
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glColor3f(0.6f, 0.f, 0.f);
			glScalef(1.f, 0.2f, 2.f);
			glutSolidCube(1.f);
		glPopAttrib();
	glPopMatrix();
}

void Airplane::drawPropeller()
{
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glColor3f(0.5f, 0.5f, 0.5f);
			glRotatef(propRotation, 1.f, 0.f, 0.f);

			glPushMatrix();
				glScalef(0.2f, 2.f, 0.2f);
				glutSolidCube(1.f);
			glPopMatrix();

			glPushMatrix();
				glRotatef(90.f, 1.f, 0.f, 0.f);
				glScalef(0.2f, 2.f, 0.2f);
				glutSolidCube(1.f);
			glPopMatrix();

		glPopAttrib();
	glPopMatrix();
}