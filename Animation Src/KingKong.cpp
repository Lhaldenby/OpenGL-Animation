#include "KingKong.h"


KingKong::KingKong() :
	animationTime(6.f), leftShoulder(-30.f),leftElbow(10.f),rightShoulder(30.f),rightElbow(-10.f),
	leftHip(-20.f),leftKnee(15.f),rightHip(20.f),rightKnee(-15.f)
{
}

void KingKong::update(float dT)
{

}

void KingKong::display()
{
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);                   // save style attributes (and more)
		glColor3f(0.5f, 0.5f, 0.5f);                        // colour horse grey

		// Project from Object Space to World Space
		glTranslatef(pos[0], pos[1], pos[2]);   // position
		glScalef(scale[0], scale[1], scale[2]); // scale
		glRotatef(rotation[1], 0.f, 1.f, 0.f);  // set orientation (Y)
		glRotatef(rotation[2], 0.f, 0.f, 1.f);  // set orientation (Z)
		glRotatef(rotation[0], 1.f, 0.f, 0.f);  // set orientation (X)

		drawKong();

		glPopAttrib();
	glPopMatrix();
}

void KingKong::drawKong()
{
	glTranslatef(0.f, 5.f, 0.f);
	glPushMatrix();
		drawBody();

		glPushMatrix();
			glTranslatef(0.f,1.3f, 0.f);
			drawHead();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(2.f, -0.6f, 0.f);
			drawRightArm();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-2.f, -0.6f, 0.f);
			drawLeftArm();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.f, -3.7f, 0.f);
			drawRightLeg();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-1.f, -3.7f, 0.f);
			drawLeftLeg();
		glPopMatrix();

	glPopMatrix();
}

void KingKong::drawBody()
{
	glPushMatrix();
	glScalef(3.f,1.5f,1.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.f, -1.5f, 0.f);
	glScalef(2.f, 2.5f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();
}

void KingKong::drawHead()
{
	glPushMatrix();
	glScalef(1.f, 1.f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();
}

void KingKong::drawLeftArm()
{
	glPushMatrix();
	glRotatef(leftShoulder,0.f,0.f,1.f);
	glScalef(1.f, 2.5f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.5f,-1.4f,0.f);
		glRotatef(leftElbow, 0.f, 0.f, 1.f);
		glScalef(1.f,1.6f,1.f);
		glutSolidCube(1.f);
	glPopMatrix();
	
}

void KingKong::drawRightArm()
{
	glPushMatrix();
	glRotatef(rightShoulder, 0.f, 0.f, 1.f);
	glScalef(1.f, 2.5f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5f, -1.4f, 0.f);
	glRotatef(rightElbow, 0.f, 0.f, 1.f);
	glScalef(1.f, 1.6f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();
}

void KingKong::drawLeftLeg()
{
	glPushMatrix();
	glRotatef(leftHip, 0.f, 0.f, 1.f);
	glScalef(1.2f, 2.f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.3f,-1.6f,0.f);
	glRotatef(leftKnee, 0.f, 0.f, 1.f);
	glScalef(1.f, 1.5f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();
}

void KingKong::drawRightLeg()
{
	glPushMatrix();
	glRotatef(rightHip, 0.f, 0.f, 1.f);
	glScalef(1.2f, 2.f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3f, -1.6f, 0.f);
	glRotatef(rightKnee, 0.f, 0.f, 1.f);
	glScalef(1.f, 1.5f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();
}

