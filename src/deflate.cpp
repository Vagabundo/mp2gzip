#include "deflate.h"

Deflate::Deflate(){
	Vbits aux(3,3);
	ziped = aux;
}

Deflate::~Deflate(){
}

void Deflate::LeerTexto(){
	lz.LeerVUC();
}

Vbits Deflate::Huffman(unsigned int ui)const{

	Vbits err;
	if (ui >= 0 && ui <= 143){
		Vbits aux(ui+48, 8);
		return Invertida(aux);
	}

	if (ui > 143 && ui <= 255){
		Vbits aux(ui+256, 9);
		return Invertida(aux);
	}

	if (ui > 255 && ui <= 279){
		Vbits aux(ui-256, 7);
		return Invertida(aux);
	}

	if (ui > 279 && ui <= 287){
		Vbits aux(ui-88, 8);
		return Invertida(aux);
	}
	return err;
}

void Deflate::Comprimir(){

	lz.Codificar();
//	lz.CodificarMejor();

	Tabla t_long(0);
	Tabla t_dist(1);

	for (unsigned int i = 0; i < lz.SizeUI(); i++){

		if (lz.GetLZ(i) > 256){
//			cout << Huffman(t_long.GetCodigo(lz.GetLZ(i)-257));
//			cout << "  " << t_long.GetVB(lz.GetLZ(i)-257);
			ziped += Huffman(t_long.GetCodigo(lz.GetLZ(i)-257));
			ziped += t_long.GetVB(lz.GetLZ(i)-257);
			i++;
			Vbits aux(t_dist.GetCodigo(lz.GetLZ(i)-1), 5);
//			cout << endl << Invertida(aux);
//			cout << "  " << Invertida(t_dist.GetVB(lz.GetLZ(i)-1));
			ziped += Invertida(aux);
			ziped += t_dist.GetVB(lz.GetLZ(i)-1);
		}
		else{
//			cout << Huffman(lz.GetLZ(i));
			ziped += Huffman(lz.GetLZ(i));
		}
//		cout << endl;
	}
}

Vbits Deflate::GetComprimido()const{
	return ziped;
}

unsigned int Deflate::SizeComprimido()const{
	return ziped.Size();
}
