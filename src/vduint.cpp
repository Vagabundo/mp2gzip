#include "vduint.h"

void VD_uint::Ampliar(){

	// si el vector no tiene reservado elementos, reservamos uno
	if (r == 0)
		r = 1;
	// en caso contrario reservamos el doble de lo que tenemos
	else
		r*=2;

	unsigned int *aux = new unsigned int [r];

	for (int i = 0; i < nb; i++)
		aux[i] = v[i];

	delete []v;
	v = aux;
}

VD_uint::VD_uint(){
	v = 0;
	nb = 0;
	r = 0;
}

VD_uint::~VD_uint(){
	delete [] v;
	v = 0;
	nb = 0;
	r = 0;
}

VD_uint::VD_uint(const VD_uint &V){

	r = V.r;
	nb = V.nb;
	v = new unsigned int [r];

	for (int i = 0; i < nb; i++)
		v[i] = V.v[i];
}

VD_uint &VD_uint::operator=(const VD_uint &V){

	if (this!=&V){
		delete []v;
		r = V.r;
		nb = V.nb;
		v = new unsigned int[r];

		for (int i = 0; i < nb; i++)
			v[i] = V.v[i];
	}

	return *this;
}

unsigned int VD_uint::Get (const int &i)const{
	return v[i];
}

void VD_uint::Set (unsigned int c, int i){
	v[i] = c;
}


void VD_uint::Add (unsigned int c){
	if (nb == r)
		Ampliar();

	v[nb] = c;
	nb++;
}

ostream & operator << (ostream &os, const VD_uint & vd){
	for (int i = 0; i < vd.nb; i++)
		os << vd.v[i] << " ";

	return os;
}

istream & operator >> (istream &is, VD_uint & vd){
	char c;
	while (cin.get(c))
		vd.Add(c);

	return is;
}
