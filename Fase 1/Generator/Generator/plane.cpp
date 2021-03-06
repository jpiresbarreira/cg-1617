/**
 * @file plane.cpp
 *
 * Defini��o de m�todos para calcular as coordenadas dos pontos de um plano.
 *
 * @author Carlos Pereira - A61887 
 * @author Jo�o Barreira  - A73831
 * @author Rafael Braga   - A61799
 */


#include "plane.h"


class Plane::PlaneImpl {
	float dimX;  // Dimens�o do plano no eixo dos xx
	float dimZ;  // Dimens�o do plano no eixo dos zz

public:
	
	/**
	 * Construtor por defeito.
	 */
	PlaneImpl(void)
	{
		dimX = dimZ = 0;
	}


	/**
	 * Construtor por par�metros.
	 *
	 * @param dimX Dimens�o do plano no eixo dos xx.
	 * @param dimZ Dimens�o do plano no eixo dos zz.
	 */
	PlaneImpl(float dimX, float dimZ)
	{
		this->dimX = dimX;
		this->dimZ = dimZ;
	}


	/**
	 * Devolve o valor da dimens�o do plano no eixo dos xx.
	 */
	float getDimX(void)
	{
		return dimX;
	}


	/**
	 * Devolve o valor da dimens�o do plano no eixo dos zz.
	 */
	float getDimZ(void)
	{
		return dimZ;
	}


	/**
	 * Altera o valor da dimens�o do plano no eixo dos xx.
	 */
	void setDimX(float dimX)
	{
		this->dimX = dimX;
	}


	/**
	 * Altera o valor da dimens�o do plano no eixo dos zz.
	 */
	void setDimZ(float dimZ)
	{
		this->dimZ = dimZ;
	}


	/**
	 * Destrutor por defeito.
	 */
	~PlaneImpl(void) = default;
};


/**
 * Construtor por defeito.
 */
Plane::Plane(void) : pimpl{ new PlaneImpl() } {}


/**
 * Construtor por par�metros. 
 *
 * @param dimX Dimens�o do plano no eixo dos xx.
 * @param dimZ Dimens�o do plano no eixo dos zz.
 */
Plane::Plane(float dimX, float dimZ)
{
	dimX = (dimX < 0) ? 0 : dimX;
	dimZ = (dimZ < 0) ? 0 : dimZ;

	pimpl = new PlaneImpl(dimX, dimZ);

	generateVertices();
}


/**
 * Construtor de c�pia.
 *
 * @param p Objeto da classe Plane a ser copiado.
 */
Plane::Plane(const Plane& p)
{
	pimpl = new PlaneImpl(p.pimpl->getDimX(), p.pimpl->getDimZ());
}


/**
 * Devolve o valor da dimens�o do plano no eixo dos xx.
 */
float Plane::getDimX(void)
{
	return pimpl->getDimX();
}


/**
 * Devolve o valor da dimens�o do plano no eixo dos zz.
 */
float Plane::getDimZ(void)
{
	return pimpl->getDimZ();
}


/**
 * Altera o valor da dimens�o do plano no eixo dos xx.
 */
void Plane::setDimX(float dimX)
{
	dimX = (dimX < 0) ? 0 : dimX;
	pimpl->setDimX(dimX);
}


/**
 * Altera o valor da dimens�o do plano no eixo dos zz.
 */
void Plane::setDimZ(float dimZ)
{
	dimZ = (dimZ < 0) ? 0 : dimZ;
	pimpl->setDimZ(dimZ);
}


/**
 * M�todo que c�lcula todos as coordenadas de todos os pontos de um plano.
 *
 * v2------v1
 *  |      |
 *  |      |
 *  |      |
 *  v3-----v4
 */
void Plane::generateVertices(void)
{
	// Centrar o plano na origem
	float x = pimpl->getDimX() / 2; 
	float z = pimpl->getDimZ() / 2;

	// Um plano apenas cont�m 2 tri�ngulos

	// V�rtices v1-v2-v3
	addVertex(Vertex(x, 0, -z));
	addVertex(Vertex(-x, 0, -z));
	addVertex(Vertex(-x, 0, z));


	// V�rtives v1-v3-v4
	addVertex(Vertex(x, 0, -z));
	addVertex(Vertex(-x, 0, z));
	addVertex(Vertex(x, 0, z));
}


/**
 * Destrutor da classe Plane.
 *
 * Liberta a mem�ria ocupada pelo apontador para a parte privada da classe
 * Plane.
 */
Plane::~Plane(void)
{
	if (pimpl != NULL) {
		delete pimpl;
		pimpl = NULL;
	}
}







