#ifndef _VD_UINT_H_
#define _VD_UINT_H_

#include <iostream>

using namespace std;

/**
*
* \class VD_uint
*
* \brief esta clase gestiona un vector dinamico de unsigned ints
*
* \author Roberto Jose del Rio Rodriguez 75154244-L
*
* \version $Revision: 0.1 $
*
* \date $Date: 11/06/2010 $
*
*/

class VD_uint{
	private:
		unsigned int *v;
		int nb;			//numero de unsigned ints usados
		int r;			//numero de unsigned ints reservados

	  /**
	  *	   @brief Amplia la capacidad del vector. Reserva un espacio si es nuevo, o dobla su capacidad si ya tenía elementos
	  */
		void Ampliar();

	public:
	  /**
	  *	   @brief Constructor por defecto. Crea un nuevo vector de unsigned int sin memoria reservada, e inicializa los elementos miembros de la clase a 0.
	  */
		VD_uint();
	  /**
	  *	  @brief Destructor por defecto.
	  */
		~VD_uint();
	  /**
	  *	  @brief Constructor de copia.
	  *
	  *	  @param [in] V VD_uint que le pasamos para copiarlo.
	  */
		VD_uint(const VD_uint &V);
	  /**
	  *	  @brief Operador de asignacion.
	  *
	  *	  @param [in] V VD_uint que le pasamos para copiarlo.
	  */
		VD_uint &operator=(const VD_uint &V);
	  /**
	  *	  @brief Funcion que devuelve el numero de unsigned ints usados.
	  *
	  *	  @return el numero de unsigned ints usados en el vector.
	  */
		int Size()const{ return nb;};
	  /**
	  *	  @brief Funcion que delvuelve el elemento i-esimo del vector.
	  *
	  *	  @param [in] i numero del elemento que queremos obtener.
	  */
		unsigned int Get (const int &i)const;
	  /**
	  *	  @brief Funcion que asigna el elemento c al lugar i-esimo del vector.
	  *
	  *	  @param [in] c elemento que queremos asignar.
	  *	  @param [in] i lugar del vector que queremos asignar.
	  */
		void Set (unsigned int c,  int i);
	  /**
	  *	  @brief Funcion que añade al final del vector el elemento c.
	  *
	  *	  @param [in] c elemento que queremos añadir.
	  */
		void Add (unsigned int c);
	  /**
	  *	  @brief Operador de salida.
	  *
	  *	  @param [in] os flujo de salida.
	  *	  @param [in] vd VD_uint a sacar por el flujo
	  */
		friend ostream & operator << (ostream &os, const VD_uint & vd);
	  /**
	  *	  @brief Operador de entrada.
	  *
	  *	  @param [in] is flujo de entrada.
	  *	  @param [in] vd VD_uint a meter por el flujo
	  */
		friend istream & operator >> (istream &is, VD_uint & vd);
};

#endif