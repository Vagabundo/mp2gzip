#ifndef _VD_CHAR_H_
#define _VD_CHAR_H_

#include <iostream>

using namespace std;


/**
*
* \class VD_char
*
* \brief esta clase gestiona un vector dinamico de unsigned chars
*
* \author Roberto Jose del Rio Rodriguez 75154244-L
*
* \version $Revision: 0.1 $
*
* \date $Date: 11/06/2010 $
*
*/

class VD_char{
	private:
		unsigned char *v;
		int nb;			//numero de bytes usados
		int r;			//numero de bytes reservados

	  /**
	  *	  @brief Amplia la capacidad del vector. Reserva un espacio si es nuevo, o dobla su capacidad si ya tenía elementos
	  */
		void Ampliar(); //amplia la capacidad de v a 1 si es nueva, y al doble si ya tiene elementos

	public:
	  /**
	  *	  @brief Constructor por defecto. Crea un nuevo vector de unsigned char sin memoria reservada, e inicializa los elementos miembros de la clase a 0.
	  */
		VD_char();
	  /**
	  *	  @brief Destructor por defecto.
	  */
		~VD_char();
	  /**
	  *	  @brief Constructor de copia.
	  *
	  *	  @param [in] V VD_char que le pasamos para copiarlo.
	  */
		VD_char(const VD_char &V);
	  /**
	  *	  @brief Constructor por parametros
	  *
	  *	  @param [in] n numero de elementos con que inicializamos el vector.
	  */
		VD_char(int n);
	  /**
	  *	  @brief Operador de asignacion.
	  *
	  *	  @param [in] V VD_char que le pasamos para copiarlo.
	  */
		VD_char &operator=(const VD_char &V);
	  /**
	  *	  @brief Funcion que devuelve el numero de unsigned ints usados.
	  *
	  *	  @return el numero de unsigned chars usados en el vector.
	  */
		int Size()const{ return nb;};
	  /**
	  *	  @brief Funcion que delvuelve el elemento i-esimo del vector.
	  *
	  *	  @param [in] i numero del elemento que queremos obtener.
	  */
		unsigned char Get (const int &i)const;
	  /**
	  *	  @brief Funcion que devuelve el vector de unsigned char miembro de la clase.
	  *
	  *	  @return el vector de unsigned chars miembro de la clase.
	  */
		unsigned char* GetVD ()const{ return v;};
	  /**
	  *	  @brief Funcion que asigna el elemento c al lugar i-esimo del vector.
	  *
	  *	  @param [in] c elemento que queremos asignar.
	  *	  @param [in] i lugar del vector que queremos asignar.
	  */
		void Set (unsigned char c,  int i);
	  /**
	  *	  @brief Funcion que añade al final del vector el elemento c.
	  *
	  *	  @param [in] c elemento que queremos añadir.
	  */
		void Add (unsigned char c);
	  /**
	  *	  @brief Operador de salida.
	  *
	  *	  @param [in] os flujo de salida.
	  *	  @param [in] vd VD_char a sacar por el flujo
	  */
		friend ostream & operator << (ostream &os, const VD_char & vd);
	  /**
	  *	  @brief Operador de entrada.
	  *
	  *	  @param [in] is flujo de entrada.
	  *	  @param [in] vd VD_char a meter por el flujo
	  */
		friend istream & operator >> (istream &is, VD_char & vd);
};

#endif
