#ifndef _VBITS_H_
#define _VBITS_H_

#include "vdchar.h"

using namespace std;

/**
*
* \class Vbits
*
* \brief esta clase gestiona un vector de bits
*
* \author Roberto Jose del Rio Rodriguez 75154244-L
*
* \version $Revision: 0.1 $
*
* \date $Date: 11/06/2010 $
*
*/

class Vbits{
	private:
		VD_char vd;
		int n;  // nº de bits
	public:
	  /**
	  *	  @brief Constructor por defecto.
	  */
		Vbits();
	  /**
	  *	  @brief Constructor por parametros
	  *
	  *	  @param [in] num numero que queremos codificar en binario.
	  *	  @param [in] l numero de bits con el que queremos codificar el numero num.
	  */
		Vbits(int num, int l);
	  /**
	  *	  @brief Destructor por defecto.
	  */
		~Vbits();
	  /**
	  *	  @brief Funcion que agrega un bit al final del vector.
	  *
	  *	  @param [in] bit bit que queremos agregar.
	  */
		void Insertar (unsigned char bit);
	  /**
	  *	  @brief Funcion que devuelve el numero de bits almacenados.
	  */
		int Size ()const;
	  /**
	  *	  @brief Funcion que devuelve el bit i-esimo.
	  *
	  *	  @param [in] i numero del bit que queremos consultar.
	  */
		unsigned int Get (int i)const;
	  /**
	  *	  @brief Funcion que devuelve el vector dinamico miembro de la clase.
	  *
	  *	  @return vector dinamico asociado.
	  */
		VD_char GetVC ()const{ return vd;};
	  /**
	  *	  @brief Funcion que devuelve el vector de unsigned char asociado al miembro vd.
	  *
	  *	  @return vector unsigned char asociado a vd.
	  */
		unsigned char* GetVD ()const{ return vd.GetVD();};
	  /**
	  *	  @brief Funcion que devuelve el numero de bytes reservados del vector dinamico.
	  *
	  *	  @return bytes reservados en el vector dinamico.
	  */
		int SizeVC()const{ return vd.Size();};
	  /**
	  *	  @brief Funcion que asignar el bit "bit" en la posicion i-esima.
	  *	  
	  *	  @param [in] i numero del bit que queremos asignar.
	  *	  @param [in] bit bit a asignar.
	  */
		void Set (int i, unsigned char bit);
	  /**
	  *	  @brief Operador de asignacion.
	  *
	  *	  @param [in] V Vbits que le pasamos para copiarlo.
	  */
		Vbits & operator = (const Vbits &V);
	  /**
	  *	  @brief Funcion que agrega un bit al final del vector.
	  *
	  *	  @param [in] bit bit que queremos agregar.
	  */
		void operator += (unsigned char bit);   //igual que Insertar
	  /**
	  *	  @brief Funcion que agrega un Vbit al final del vector.
	  *
	  *	  @param [in] vbit Vbit que queremos agregar.
	  */
		void operator += (const Vbits &vbit);   //suma el vector vbit al vector apuntado por this
	  /**
	  *	  @brief Operador de igualdad.
	  *
	  *	  @param [in] vbit Vbits que queremos comparar con el actual.
	  */
		bool operator == (const Vbits &vbit)const;
	  /**
	  *	  @brief Operador de desigualdad.
	  *
	  *	  @param [in] vbit Vbits que queremos comparar con el actual.
	  */
		bool operator != (const Vbits &vbit)const;
	  /**
	  *	  @brief Operador de salida.
	  *
	  *	  @param [in] os flujo de salida.
	  *	  @param [in] vb Vbits a sacar por el flujo
	  */
		friend ostream & operator << (ostream &os, const Vbits & vb);
	  /**
	  *	  @brief Operador de entrada.
	  *
	  *	  @param [in] is flujo de entrada.
	  *	  @param [in] vb Vbits a meter por el flujo
	  */
		friend istream & operator >> (istream &is, Vbits & vb);
};

/**
*	@brief Funcion que invierte el orden de los bits de un Vbits.
*
*	@param [in] vb Vbit que queremos agregar.
*/
Vbits Invertida(const Vbits & vb);

#endif
