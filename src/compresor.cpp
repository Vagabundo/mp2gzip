#include "crc32.h"
#include "deflate.h"
#include <fstream>

/****** Funciones auxiliares ******/

void ImprimeBitsUC (unsigned char c){

	unsigned char mask = 1 << 7;
	for (int i = 0; i < 8; i++){
		if (c & mask)
			cout << 1;
		else
			cout << 0;
		mask = mask >> 1;
	}
}

void ImprimeBitsUL (unsigned long l){

	unsigned long mask = 1 << 31;
	for (int i = 0; i < 32; i++){
		if (l & mask)
			cout << 1;
		else
			cout << 0;
		mask = mask >> 1;
	}
}

unsigned int Longitud (char * cad){
	int l = 0;
	while (cad[l] != '\0')
		l++;

	return l;
}

/******* PROGRAMA MAIN *******/

int main (int argc, char * argv[]){

/****** comprobacion de parametros ******/

	if (argc < 2 || argc > 3){
		cerr << "Numero de parametros incorrecto" << endl;
		return 1;
	}

	ifstream fi(argv[1], ios::in | ios::binary);
	if (!fi){
		cerr << "No se ha podido abrir el fichero " << argv[1] << endl;
		return 1;
	}

	ofstream fo;
	char *salida;
	if (argc == 2){
		char * archivo = argv[1];
		int l = Longitud(argv[1]);
		salida = new char[l+4];
		for (int i = 0; i < l; i++)
			salida[i] = archivo[i];
		salida[l] = '.';
		salida[l+1] = 'g';
		salida[l+2] = 'z';
		salida[l+3] = '\0';
	}
	else
		salida = argv[2];

	fo.open (salida, ios::out | ios::binary);

	if (!fo){
		cerr << "No se ha podido crear el fichero " << salida << endl;
		return 1;
	}

	Deflate df;

/**** lectura de datos desde el fichero dado *****/

	char c;
	while (fi.get(c))
		df.AddUC((unsigned char)c);

/**** comprimimos los datos ****/

	df.Comprimir();

/**** declaracion e inserccion de las variables del princincipio del nuevo fichero ****/

	unsigned char ID1 = 0x1f; //31
	unsigned char ID2 = 0x8b; //139
	unsigned char CM = 8;
	unsigned char FLG = 24; // 00011000
	unsigned int MTIME = 0;
	unsigned char XFL = 4; //codificacion rapida
//	unsigned char XFL = 2; //codificacion mejorada
	unsigned char OS = 255; // SO desconocido
	unsigned long CRC = CRC32_Cadena(df.GetTexto());

	fo.write (reinterpret_cast<char *>(&ID1), sizeof(unsigned char));
	fo.write (reinterpret_cast<char *>(&ID2), sizeof(unsigned char));
	fo.write (reinterpret_cast<char *>(&CM), sizeof(unsigned char));
	fo.write (reinterpret_cast<char *>(&FLG), sizeof(unsigned char));
	fo.write (reinterpret_cast<char *>(&MTIME), sizeof(unsigned int));
	fo.write (reinterpret_cast<char *>(&XFL), sizeof(unsigned char));
	fo.write (reinterpret_cast<char *>(&OS), sizeof(unsigned char));

/** nombre del fichero original **/
	fo.write (reinterpret_cast<char *>(argv[1]), Longitud(argv[1])+1);

/** comentario, en este casi mi nombre y DNI **/
	char *comentario = (char*)"Roberto Jose del Rio Rodriguez, 75154244-l";
	fo.write (reinterpret_cast<char *>(comentario), Longitud(comentario)+1);

/** insertamos el archivo comprimido y su correspondiente CRC32 declarado anteriormente **/
	fo.write (reinterpret_cast<char *>(df.GetVDComprimido()), (df.SizeComprimido()/8)+1);
   fo.write (reinterpret_cast<char *>(&CRC), sizeof(unsigned long));

/** insertamos el tamaño del fichero original **/
	unsigned long size = df.SizeTexto();
	fo.write (reinterpret_cast<char *>(&size), sizeof(unsigned long));

/** y cierro el fichero (aunque no sea extrictamente necesario) **/
	fo.close();
}
