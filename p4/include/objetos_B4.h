#ifndef _OBJETOS_B3
#define _OBJETOS_B3


//**************************************************************************
// Práctica IG usando objetos
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>
#include "file_ply_stl.hpp"

using namespace std;

const float AXIS_SIZE=5000;
typedef enum{POINTS,EDGES,SOLID_CHESS,SOLID,SOLID_ILLUMINATED_FLAT,
             SOLID_ILLUMINATED_GOURAUD} _modo;
typedef enum{EJE_X,EJE_Y,EJE_Z} _eje;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:

  
	_puntos3D();
void 	draw_puntos(float r, float g, float b, int grosor);

vector<_vertex3f> vertices;
};

//*************************************************************************
// clase tri�ngulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
void 	draw_aristas(float r, float g, float b, int grosor);
void    draw_solido(float r, float g, float b);
void 	draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
void 	draw_iluminacion_plana( );
void 	draw_iluminacion_suave( );

void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

void	calcular_normales_caras();
void 	calcular_normales_vertices();

vector<_vertex3i> caras;

vector<_vertex3f> normales_caras;
vector<_vertex3f> normales_vertices;

bool b_normales_caras;
bool b_normales_vertices;

_vertex4f ambiente_difusa;     //coeficientes ambiente y difuso
_vertex4f especular;           //coeficiente especular
float brillo;                  //exponente del brillo 

};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=0.5);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=0.75);
};

//*************************************************************************
// clase objeto ply
//*************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
   _objeto_ply();

int   parametros(char *archivo);
};

//************************************************************************
// objeto por revoluci�n
//************************************************************************

class _rotacion: public _triangulos3D
{
public:
       _rotacion();
void  parametros(vector<_vertex3f> perfil1, int num1, bool tapa_sup, bool tapa_inf, _eje eje);

vector<_vertex3f> perfil; 
int num;
};

//*************************************************************************
// clase cono
//*************************************************************************

class _cono: public _triangulos3D
{
public:

_cono(float radio, float altura, int num);


};

//*************************************************************************
// clase cilindro
//*************************************************************************
class _cilindro: public _triangulos3D
{
public:

	_cilindro(float radio=0.00005, float altura=1, int num=20);
};

//*************************************************************************
// clase esfera
//*************************************************************************
class _esfera: public _rotacion{
	private:
		float latitud;
		float longitud;
		float radio;
	public:
		_esfera(float latitud=5, float radio=1, float longitud=20, bool semi=false);
		std::vector<_vertex3f> generar_perfil(bool semi);
		float getRadio(){return radio;}
};

#endif