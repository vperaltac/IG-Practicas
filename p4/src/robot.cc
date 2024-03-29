#include "objetos_B4.h"
#include "robot.h"

// ---------------------------------------------------------------------------------------------------------
Cabeza::Cabeza(){
	craneo = new _esfera(5,1,20,false);
	oreja_izq = new _cilindro(0.2,0.05,20);
	oreja_dcha = new _cilindro(0.2,0.05,20);
	ojo_izq = new _cilindro(0.25,0.2,20);
	ojo_dcha = new _cilindro(0.25,0.2,20);
	pupila_dcha = new _cilindro(0.22,0.05,20);
	pupila_izq = new _cilindro(0.22,0.05,20);
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


void Cabeza::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor, _material mat){
	glPushMatrix();
	this->craneo->draw(modo,0.5,0.5,0.5,0.6,0.6,0.6,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1,0,0);
	glRotatef(90.0,0,0,1);
	this->oreja_izq->draw(modo,0,0,0,0.2,0.2,0.2,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.05,0,0);
	glRotatef(90.0,0,0,1);
	this->oreja_dcha->draw(modo,0,0,0,0.2,0.2,0.2,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.4,0.4,0.75);
	glRotatef(90.0,1,0,0);
	this->ojo_izq->draw(modo,0.8,0.8,0.8,0.7,0.7,0.7,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4,0.4,0.75);
	glRotatef(90.0,1,0,0);
	this->ojo_dcha->draw(modo,0.8,0.8,0.8,0.7,0.7,0.7,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.4,0.4,0.92);
	glRotatef(90.0,1,0,0);
	this->pupila_dcha->draw(modo,1,1,1,0.9,0.9,0.9,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4,0.4,0.92);
	glRotatef(90.0,1,0,0);
	this->pupila_izq->draw(modo,1,1,1,0.9,0.9,0.9,grosor,mat);
	glPopMatrix();

}
// ---------------------------------------------------------------------------------------------------------
Torso::Torso(){
	cuerpo = new _cilindro(1,2,20);
	cuello = new _cilindro(0.2,0.5,20);
	torso_inferior = new _esfera(5,1,20,true);
}

Torso::~Torso(){
	delete cuerpo;
	delete cuello;
	delete torso_inferior;
}

void Torso::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor, _material mat){
	glPushMatrix();
	this->cuerpo->draw(modo,0.5,0.5,0.5,0.6,0.6,0.6,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,2,0);
	this->cuello->draw(modo,0,0,0,0.2,0.2,0.2,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0.1,0);
	glRotatef(180,0,0,1);
	this->torso_inferior->draw(modo,0,0,0,0.2,0.2,0.2,grosor,mat);
	glPopMatrix();

}

Brazo::Brazo(){
	hombro = new _esfera(5,0.2,20,false);
	brazo_superior = new _cilindro(0.15,1.25,20);
	brazo_inferior = new _cilindro(0.15,1.25,20);
	codo = new _esfera(5,0.2,20,false);
}

Brazo::~Brazo(){
	delete hombro;
	delete brazo_superior;
	delete brazo_inferior;
	delete codo;
}

void Brazo::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor, _material mat){
	glPushMatrix();
	this->hombro->draw(modo,0,0,0,0.2,0.2,0.2,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-1.3,0);
	this->brazo_superior->draw(modo,0.5,0.5,0.5,0.6,0.6,0.6,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-1.3,0);
	this->codo->draw(modo,0,0,0,0.2,0.2,0.2,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-2.6,0);
	this->brazo_inferior->draw(modo,0.5,0.5,0.5,0.6,0.6,0.6,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-3,0);
	this->mano.draw(modo,0.5,0.5,0.5,0.6,0.6,0.6,grosor,mat);
	glPopMatrix();

}

Mano::Mano(){
	palma   = new _cubo(.2);
	pulgar  = new _cilindro(0.05,0.3,20);
	indice  = new _cilindro(0.03,0.3,20);
	medio   = new _cilindro(0.03,0.3,20);
	anular  = new _cilindro(0.03,0.3,20);
}

Mano::~Mano(){
	delete palma;
	delete pulgar;
	delete indice;
	delete medio;
	delete anular;
}

void Mano::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor, _material mat){
	glPushMatrix();
	glScalef(1,1,0.4);
	this->palma->draw(modo,0.5,0.5,0.5,0.6,0.6,0.6,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.35,0,0);
	glRotatef(30,0,0,1);
	this->pulgar->draw(modo,0.5,0.5,0.5,0.6,0.6,0.6,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.15,-0.3,0);
	this->indice->draw(modo,0.5,0.5,0.5,0.6,0.6,0.6,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-0.3,0);
	this->medio->draw(modo,0.5,0.5,0.5,0.6,0.6,0.6,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.15,-0.3,0);
	this->anular->draw(modo,0.5,0.5,0.5,0.6,0.6,0.6,grosor,mat);
	glPopMatrix();
}

Pierna::Pierna(){
	pierna_superior = new _cilindro(0.15,1.25,20);
	rodilla         = new _esfera(5,0.2,20,false);
	pierna_inferior = new _cilindro(0.15,1.25,20);
	pie             = new _cilindro(0.4,0.2,20);
}

Pierna::~Pierna(){
	delete pierna_inferior;
	delete pierna_superior;
	delete rodilla;
	delete pie;
}

void Pierna::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor, _material mat){

	glPushMatrix();
	glTranslatef(0,-1.3,0);
	this->pierna_superior->draw(modo,0.5,0.5,0.5,0.6,0.6,0.6,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-1.3,0);
	this->rodilla->draw(modo,0,0,0,0.2,0.2,0.2,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-2.6,0);
	this->pierna_inferior->draw(modo,0.5,0.5,0.5,0.6,0.6,0.6,grosor,mat);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-2.6,0);
	this->pie->draw(modo,0,0,0,0.2,0.2,0.2,grosor,mat);
	glPopMatrix();

}

void Robot::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor, _material mat){
	glPushMatrix();
		glRotatef(-rotacion_robot,0,1,0);
		glTranslatef(5,0,0);

		glPushMatrix();
		glTranslatef(0,3.2,0);
		glRotatef(giro_cabeza,0,1,0);
		this->cabeza.draw(modo,r1,g1,b1,r2,g2,b2,grosor,mat);
		glPopMatrix();

		glPushMatrix();
		this->torso.draw(modo,r1,g1,b1,r2,g2,b2,grosor,mat);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1,1.9,0);
		glRotatef(-15.0,0,0,1);
		glRotatef(giro_brazo,1,0,0);
		this->brazo_izq.draw(modo,r1,g1,b1,r2,g2,b2,grosor,mat);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1,1.9,0);
		glRotatef(15.0,0,0,1);
		glRotatef(giro_brazo,1,0,0);
		this->brazo_dcho.draw(modo,r1,g1,b1,r2,g2,b2,grosor,mat);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.45,-0.6,0);
		glRotatef(giro_pierna*(-1),1,0,0);
		this->pierna_izq.draw(modo,r1,g1,b1,r2,g2,b2,grosor,mat);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.45,-0.6,0);
		glRotatef(giro_pierna,1,0,0);
		this->pierna_dcha.draw(modo,r1,g1,b1,r2,g2,b2,grosor,mat);
		glPopMatrix();
	glPopMatrix();
}