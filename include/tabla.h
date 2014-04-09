#ifndef _TABLA_H_
#define _TABLA_H_

#include <iostream>
#include "libvd.h"

using namespace std;

/**
*
* \struct info
*
* \brief esta estructura contiene un entero y un Vbits asociado.
*
* \author Roberto Jose del Rio Rodriguez 75154244-L
*
* \version $Revision: 0.1 $
*
* \date $Date: 11/06/2010 $
*
*/

struct info {
	unsigned int codigo;
	Vbits vb;
};

/**
*
* \class Tabla
*
* \brief esta clase gestiona un vector de infos
*
* \author Roberto Jose del Rio Rodriguez 75154244-L
*
* \version $Revision: 0.1 $
*
* \date $Date: 11/06/2010 $
*
*/

class Tabla {
	private:
		info *tab;
		int n; //numero de elementos de la tabla
	public:
	  
	  /**
	  *	  @brief Constructor por parametros
	  *
	  *	  @param [in] tipo tipo de tabla que queremos crear.
	  */
		Tabla (unsigned int tipo);
	  /**
	  *	  @brief Destructor por defecto.
	  */
		~Tabla ();
	  /**
	  *	  @brief Esta funcion devuelve el codigo asociado a un entero dado.
	  *
	  *	  @param [in] car entero del que queremos saber el codigo asociado.
	  */
		unsigned int GetCodigo (unsigned int car)const;
	  /**
	  *	  @brief Esta funcion devuelve el Vbits asociado a un entero dado.
	  *
	  *	  @param [in] car entero del que queremos saber el Vbits asociado.
	  */
		Vbits GetVB (unsigned int car)const;
	  /**
	  *	  @brief Esta funcion saca por pantalla la tabla actual.
	  */
		void EscribirTabla()const;
};

#endif
