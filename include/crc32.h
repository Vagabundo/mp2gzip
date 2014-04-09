#ifndef _CRC32_H_
#define _CRC32_H_

#include "libvd.h"
#include <iostream>

using namespace std;

/**
*
* \struct crc32
*
* \brief esta clase gestiona una tabla de 256 unsigned long y un unsigned long que sera el codigo crc32 de un texto dado
*
* \author Roberto Jose del Rio Rodriguez 75154244-L
*
* \version $Revision: 0.1 $
*
* \date $Date: 11/06/2010 $
*
*/

struct crc32{
	unsigned long tabla[256];
	unsigned long crc;
};

/**
*	@brief Calcular una tabla de 256 entradas a partir del polinomio generador mediante un código dado.
*	
*	@param c estructura crc32 a inicializar.
*/
void CRC32_Inicializar (crc32 &c);

/**
*	@brief El CRC se va actualizando con cada nuevo byte del mensaje.
*
*	@param c estructura crc32 a actualizar.
*	@param b caracter con el cual se actualiza el codigo.
*/
void CRC32_Actualiza (crc32 &c, unsigned char b);

/**
*	@brief Finaliza el codigo crc32.
*	
*	@param c estructura crc32 a finalizar.
*/
void CRC32_FinDeMensaje (crc32 &c);

/**
*	@brief Funcion que devuelve el codigo crc32 almacenado.
*	
*	@param c estructura crc32 del cual queremos devolver el codigo almacenado.
*/
unsigned long CRC32_Get (crc32 &c);

/**
*	@brief Funcion que calcula el código crc32 de un VD_char.
*	
*	@param v VD_char del cual queremos calcular el codigo crc32.
*/
unsigned long CRC32_Cadena (const VD_char &v);

#endif