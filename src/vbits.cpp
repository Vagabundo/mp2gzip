#include "vbits.h"

using namespace std;

Vbits::Vbits(){
	n = 0;
}

Vbits::Vbits(int num, int l){
	n = 0;
	for (int i = 0; i < l; i++){
		Insertar(num%2);
		num = num/2;
	}
}

Vbits::~Vbits(){
}

void Vbits::Insertar (unsigned char bit){

	unsigned char byte;

	if (n%8 == 0){
		byte = 0;
		if (bit)
			byte = 1;
		vd.Add(byte);
	}
	else{
		unsigned char m = 1 << (n%8);
		byte = vd.Get (vd.Size()-1);

		if (bit)
			byte = byte | m;

		vd.Set (byte,vd.Size()-1);
	}
	n++;
}

int Vbits::Size ()const{
	return n;
}

unsigned int Vbits::Get (int i)const{

	unsigned char byte = vd.Get(i/8);

	return (byte & (1<<(i%8))?1:0);
}

void Vbits::Set (int i, unsigned char bit){

	unsigned char byte;
	byte = vd.Get(i/8);

	if (byte & (1<<(i%8))){
		if (!bit)
			byte = byte ^ (1 << (i%8));
   }
   else
		if (bit)
			byte = byte | (1 << (i%8));
}

Vbits &Vbits::operator = (const Vbits &V){
	n = V.n;
	vd = V.vd;
	return *this;
}

void Vbits::operator += (unsigned char bit){
	Insertar(bit);
}

void Vbits::operator += (const Vbits &vbit){
	for (int i = 0; i < vbit.Size(); i++)
		Insertar(vbit.Get(i));
}

bool Vbits::operator == (const Vbits &vbit)const{

	if (vbit.Size() != Size())
		return false;

	else
		for (int i = 0; i < Size(); i++)
			if (vbit.Get(i) != Get(i))
				return false;

	return true;
}

bool Vbits::operator != (const Vbits &vbit)const{
	return !(*this==vbit);
}

ostream & operator << (ostream &os, const Vbits & vb){

// la parte comentada es para sacar por pantalla del bit mas significativo al menos significativo
/*	for (int i = 0; i <= ((vb.n/8)); i++){
		for (int j = 7; j >= 0; j--){
			if ((i*8)+j < vb.n)
				os << vb.Get((i*8)+j);
		}
		os << " ";
	}
*/
	for (int i=0; i<vb.n; i++){
		os << vb.Get(i);
		if (i%8 == 7)
			os << " ";
	}

	return os;
}

istream & operator >> (istream &is, Vbits & vb){
	char c;
	while (cin.get(c) && c != '\n'){
		c = (unsigned char)(c-'0');
		vb += c;
	}

	return is;
}

Vbits Invertida (const Vbits & vb){
	Vbits aux;
	for (int i = (vb.Size()-1); i >= 0; i--)
		aux.Insertar(vb.Get(i));

	return aux;
}
