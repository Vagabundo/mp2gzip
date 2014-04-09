#include "vdchar.h"

void VD_char::Ampliar(){

	// si el vector no tiene reservado elementos, reservamos uno
	if (r == 0)
		r = 1;
	// en caso contrario reservamos el doble de lo que tenemos
	else
		r*=2;

	unsigned char *aux = new unsigned char [r];

	for (int i = 0; i < nb; i++)
		aux[i] = v[i];

	delete []v;
	v=aux;
}

VD_char::VD_char(){
	v = 0;
	nb = 0;
	r = 0;
}

VD_char::~VD_char(){
	delete [] v;
	v = 0;
	nb = 0;
	r = 0;
}

VD_char::VD_char(const VD_char &V){

	r = V.r;
	nb = V.nb;
	v = new unsigned char [r];

	for (int i = 0; i < nb; i++)
		v[i] = V.v[i];
}

VD_char::VD_char(int n){
	r = n;
	nb = 0;
	v = new unsigned char [r];
}

VD_char &VD_char::operator=(const VD_char &V){

	if (this!=&V){
		delete []v;
		r = V.r;
		nb = V.nb;
		v = new unsigned char[r];

		for (int i = 0; i < nb; i++)
			v[i] = V.v[i];
	}

	return *this;
}

unsigned char VD_char::Get (const int &i)const{
	return v[i];
}

void VD_char::Set (unsigned char c, int i){
	v[i] = c;
}

void VD_char::Add (unsigned char c){
	if (nb == r)
		Ampliar();

	v[nb] = c;
	nb++;
}

ostream & operator << (ostream &os, const VD_char & vd){
	for (int i = 0; i < vd.nb; i++)
		os << vd.v[i];

	return os;
}

istream & operator >> (istream &is, VD_char & vd){
	char c;
	while (cin.get(c))
		vd.Add(c);

	return is;
}
