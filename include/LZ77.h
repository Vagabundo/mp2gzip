#ifndef _LZ77_H_
#define _LZ77_H_

#include "libvd.h"

using namespace std;

/**
*
* \class LZ77
*
* \brief esta clase gestiona un vector de dinamico de caracteres y lo codifica en un vector dinamico de unsigned ints
*
* \author Roberto Jose del Rio Rodriguez 75154244-L
*
* \version $Revision: 0.1 $
*
* \date $Date: 11/06/2010 $
*
*/

class LZ77{
	private:
		VD_char vc;
		VD_uint vi;
	public:
	  /**
	  *	  @brief Constructor por defecto.
	  */
		LZ77();
	  /**
	  *	  @brief Constructor por parametros.
	  *	  
	  *	  @param [in] vdchar VD_char con el que inicializamos el LZ77.
	  */
		LZ77(const VD_char & vdchar);
	  /**
	  *	  @brief Destructor por defecto.
	  */
		~LZ77();
	  /**
	  *	  @brief Funcion que lee un vector de uinsigned ints por teclado y lo almacena en vi.
	  */
		void LeerVUI();
	  /**
	  *	  @brief Funcion que saca por pantalla vi.
	  */
		void EscribirVUI()const;
	  /**
	  *	  @brief Funcion que devuelve el elemento i-esimo del vector vi.
	  *	  
	  *	  @param i numero del elemento a devolver.
	  */
		unsigned int GetLZ (int i)const;
	  /**
	  *	  @brief Funcion que devuelve el tamaño de vc.
	  *	  
	  *	  @return tamaño de vc.
	  */
		unsigned int SizeVC (){ return vc.Size();};
	  /**
	  *	  @brief Funcion que devuelve el tamaño de vi.
	  */
		unsigned int SizeUI()const;
	  /**
	  *	  @brief Funcion que lee un vector de uinsigned chars por teclado y lo almacena en vc.
	  */
		void LeerVUC();
	  /**
	  *	  @brief Funcion que saca por pantalla vc.
	  */
		void EscribirVUC()const;
	  /**
	  *	  @brief Funcion que devuelve el el vector dinamico vc.
	  *	  
	  *	  @return vector vc miembro.
	  */
		VD_char GetVC()const{return vc;};
	  /**
	  *	  @brief Funcion que añade el caracter "c" a vc.
	  *	  
	  *	  @param c caracter a añadir al vector.
	  */
		void AddUC(const unsigned char c){vc.Add(c);};
	  /**
	  *	  @brief Funcion que codifica el texto del vector vc a codigo numerico, previo a aplicar la codificacion deflate.
	  */
		void Codificar();
	  /**
	  *	  @brief Funcion que codifica el texto del vector vc a codigo numerico, previo a aplicar la codificacion deflate, pero con un algoritmo mas compresor.
	  */
		void CodificarMejor();
};

#endif