#ifndef _DEFLATE_H_
#define _DEFLATE_H_

#include "LZ77.h"
#include "tabla.h"

using namespace std;

/**
*
* \class Deflate
*
* \brief esta clase gestiona una clase LZ77 y un vector de bits, que será el archivo comprimido
*
* \author Roberto Jose del Rio Rodriguez 75154244-L
*
* \version $Revision: 0.1 $
*
* \date $Date: 11/06/2010 $
*
*/

class Deflate {
	private:
		LZ77 lz;
		Vbits ziped;
	public:
	  /**
	  *	  @brief Constructor por defecto.
	  */
		Deflate();
	  /**
	  *	  @brief Destructor por defecto.
	  */
		~Deflate();
	  /**
	  *	  @brief Funcion que lee un vector de caracteres desde el teclado y lo almacena en lz.
	  */
		void LeerTexto();
	  /**
	  *	  @brief Funcion que añade el caracter c al vector vc de LZ.
	  *	  
	  *	  @param c caracter a almacenar.
	  */
		void AddUC(const unsigned char c){lz.AddUC(c);};
	  /**
	  *	  @brief Funcion que devuelve el Vbits de Huffman asociado al unsigned int ui.
	  *	  
	  *	  @param ui numero del cual queremos saber su Vbits.
	  */
		Vbits Huffman(unsigned int ui)const;
	  /**
	  *	  @brief Funcion que comprime un archivo almacenado en lz y lo guarda en ziped.
	  */
		void Comprimir();
	  /**
	  *	  @brief Funcion que devuelve el Vbits ziped, miembro de la clase.
	  */
		Vbits GetComprimido()const;
	  /**
	  *	  @brief Funcion que devuelve el vector de unsigned char, miembro de la clase VD_char, miembro de la clase Vbits, asociado a ziped.
	  *	  
	  *	  @return vector de unsigned char asociado a ziped.
	  */
		unsigned char* GetVDComprimido()const{ return ziped.GetVD();};
	  /**
	  *	  @brief Funcion que devuelve el VD_char, miembro de la clase Vbits, asociado a ziped.
	  *	  
	  *	  @return VD_char asociado a ziped.
	  */
		VD_char GetVC()const{ return ziped.GetVC();};
	  /**
	  *	  @brief Funcion que devuelve el VD_char, miembro de LZ77, asociado a lz.
	  *	  
	  *	  @return VD_char asociado a lz.
	  */
		VD_char GetTexto() const {return lz.GetVC();};
	  /**
	  *	  @brief Funcion que devuelve el tamaño del VD_char, miembro de la clase Vbits, asociado a lz.
	  *	  
	  *	  @return tamaño del VD_char asociado a lz.
	  */
		unsigned int SizeTexto (){ return lz.SizeVC();};
	  /**
	  *	  @brief Funcion que devuelve el tamaño en bits de ziped.
	  *	  
	  *	  @return tamaño en bits de ziped.
	  */
		unsigned int SizeComprimido()const;
};

#endif