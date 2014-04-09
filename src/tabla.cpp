#include "tabla.h"

Tabla::Tabla (unsigned int tipo){

	if (tipo == 0){

		tab = new info [256];
		n = 256;

		for (int i = 0; i < 8; i++)
			tab[i].codigo = 257+i;

		unsigned int nb = 1;
		unsigned int codigo = 265;
		unsigned int i = 8;

		while (i < 255){

			for (int b = 0; b < (1<<nb) && i < 255; b++){
				tab[i].codigo = codigo;
				tab[i].vb = Vbits (b, nb);
				i++;
			}
			codigo++;
			if ((codigo - 265) % 4 == 0)
				nb++;
		}
		tab[255].codigo = 285;
	}

	else{

		tab = new info [32768];
		n = 32768;

		for (int i = 0; i < 4; i++)
			tab[i].codigo = i;

		unsigned int nb = 1;
		unsigned int codigo = 4;
		unsigned int i = 4;

		while (i< 32768){

			for (int b = 0; b < (1<<nb) && i<32768; b++){
				tab[i].codigo = codigo;
				tab[i].vb = Vbits (b,nb);
				i++;
			}
			codigo ++;
			if (codigo % 2 == 0)
				nb++;
		}
	}
}

Tabla::~Tabla (){
	delete [] tab;
	n = 0;
}

unsigned int Tabla::GetCodigo (unsigned int car)const{
	return tab[car].codigo;
}

Vbits Tabla::GetVB (unsigned int car)const{
	return tab[car].vb;
}

void Tabla::EscribirTabla()const{
	for (int i = 0; i < n; i++)
		cout << tab[i].codigo << " " << tab[i].vb << endl;
}
