#include <iostream>
#include <stdio.h>
#include <cstring>
#include "crc32.h"

using namespace std;
//   Calcular una tabla de 256 entradas a partir del polinomio generador mediante el siguiente código:

void CRC32_Inicializar (crc32 &c){
	int n, k;
	for (n = 0; n < 256; n++) {

	    c.crc = (unsigned long) n;

	    for (k = 0; k < 8; k++)
	        if (c.crc & 1)
	            c.crc = 0xedb88320L ^ (c.crc >> 1);
	        else
	            c.crc = c.crc >> 1;

	    c.tabla[n] = c.crc;
	}
	c.crc = 0xFFFFFFFF;
}

void CRC32_Actualiza (crc32 &c, unsigned char b){
	c.crc = (c.crc >> 8) ^ c.tabla[(c.crc^b) & 0xFF];
}
void CRC32_FinDeMensaje (crc32 &c){
	c.crc = c.crc ^ 0xFFFFFFFF;
}

unsigned long CRC32_Get (crc32 &c){
	return c.crc;
}

unsigned long CRC32_Cadena (const VD_char &v){

	crc32 c;
	CRC32_Inicializar(c);

	int i = 0;
	while (i < v.Size()){

		CRC32_Actualiza(c, v.Get(i));
		i++;
	}

	CRC32_FinDeMensaje (c);
	return c.crc;
}
