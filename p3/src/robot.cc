#include "objetos_B3.h"
#include "robot.h"

Cabeza::Cabeza(){
	craneo = new _esfera(5,1,20,false);
	oreja_izq = new _cilindro(0.2,0.05,20);
	oreja_dcha = new _cilindro(0.2,0.05,20);
	ojo_izq = new _cilindro(0.15,0.2,20);
	ojo_dcha = new _cilindro(0.15,0.2,20);
	pupila_dcha = new _cilindro(0.12,0.05,20);
	pupila_izq = new _cilindro(0.12,0.05,20);
}

Cabeza::~Cabeza(){
	delete craneo;
	delete oreja_izq;
	delete oreja_dcha;
	delete ojo_dcha;
	delete ojo_izq;
	delete pupila_dcha;
	delete pupila_izq;
}


void Cabeza::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
	glPushMatrix();
	this->craneo->draw(modo,0.5,0.5,0.5,0.5,0.5,0.5,grosor);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1,0,0);
	glRotatef(90.0,0,0,1);
	this->oreja_izq->draw(modo,0,0,0,0,0,0,grosor);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.05,0,0);
	glRotatef(90.0,0,0,1);
	this->oreja_dcha->draw(modo,0,0,0,0,0,0,grosor);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.4,0.4,0.75);
	glRotatef(90.0,1,0,0);
	this->ojo_izq->draw(modo,0.8,0.8,0.8,0.8,0.8,0.8,grosor);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4,0.4,0.75);
	glRotatef(90.0,1,0,0);
	this->ojo_dcha->draw(modo,0.8,0.8,0.8,0.8,0.8,0.8,grosor);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.4,0.4,0.92);
	glRotatef(90.0,1,0,0);
	this->pupila_dcha->draw(modo,1,1,1,1,1,1,grosor);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4,0.4,0.92);
	glRotatef(90.0,1,0,0);
	this->pupila_izq->draw(modo,1,1,1,1,1,1,grosor);
	glPopMatrix();

}

void Robot::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
	glPushMatrix();
	glTranslatef(0,1.9,0);
	this->cabeza.draw(modo,r1,g1,b1,r2,g2,b2,grosor);
	glPopMatrix();
}