#include "LZ77.h"
#include "libvd.h"
#include "tabla.h"

using namespace std;

LZ77::LZ77(){
}

LZ77::LZ77(const VD_char & vdchar){
	vc = vdchar;
}

LZ77::~LZ77(){
}

void LZ77::LeerVUI(){
	cin >> vi;
}

void LZ77::EscribirVUI()const{

	Tabla t_long(0);
	Tabla t_dist(1);

	for (int i = 0; i < vi.Size(); i++){
		if (vi.Get(i) < 256)
			cout << " " << vi.Get(i) <<" ";
		if (vi.Get(i) > 256){
			cout << t_long.GetCodigo(vi.Get(i)-257);
			if(vi.Get(i)>264)
				cout << " " << t_long.GetVB(vi.Get(i)-257);
			i++;
			cout << "," << t_dist.GetCodigo(vi.Get(i));
			if (vi.Get(i)>3)
				cout << " " << t_dist.GetVB(vi.Get(i));
		}
	}
}

unsigned int LZ77::GetLZ (int i)const{
	return vi.Get(i);
}

unsigned int LZ77::SizeUI()const{
	return vi.Size();
}

void LZ77::LeerVUC(){
	cin >> vc;
}

void LZ77::EscribirVUC()const{
	cout << vc;
}

void LZ77::Codificar(){

	Tabla t_long(0);
	Tabla t_dist(1);
	int cont;

// cortar lo pondremos a true cuando se pase del limite de distancia
// fin lo pondremos a true cuando hayamos llegado al final del archivo o hayamos llegado al limite de longitud
// referenciado lo pondremos a true cuando exista una coincidencia de 3 o mas caracteres
	bool cortar, fin, referenciado;

	for (long i = 0; i < vc.Size(); i++){

		referenciado = false;
		cortar = false;

		for (long j = i-1; j >= 0 && !referenciado && !cortar; j--){

			cont = 0;

			fin = false;
			while ((vc.Get (j+cont) == vc.Get(i+cont)) && !fin){
				cont ++;
				if ((i+cont) == vc.Size() || cont == 258)
					fin = true;
			}

			if (cont >= 3){
				referenciado = true;
				vi.Add(cont+254);
				vi.Add(i-j);
				i+=cont;
			}

			if ((i-j) >= 32768)
				cortar = true;
		}	
		if (!referenciado){
			vi.Add(vc.Get(i));
		}
		else
			i--;
	}
	vi.Add(256);
}

void LZ77::CodificarMejor(){

	Tabla t_long(0);
	Tabla t_dist(1);
	int cont, contmax, pos_max = 0;
	bool cortar, fin, referenciado;

	for (long i = 0; i < vc.Size(); i++){

		referenciado = false;
		cortar = false;
		fin = false;
		contmax = 0;

		for (long j = i-1; j >= 0 && !fin && !cortar; j--){

			cont = 0;

			fin = false;
			while ((vc.Get (j+cont) == vc.Get(i+cont)) && !fin){
				cont ++;
				if ((i+cont) >= vc.Size() || cont == 258)
					fin = true;
			}

			if (cont >= 3){
				referenciado = true;
				if (cont > contmax){
					contmax = cont;
					pos_max = j;
				}
			}

			if ((i-j) >= 32768)
				cortar = true;
		}
		if (referenciado){
//			cout << "#REF(" << t_long.GetCodigo(contmax-3);
			cout << "#REF(" << contmax;
			vi.Add(contmax+254);
//			if(contmax>10)
//				cout << " " << t_long.GetVB(contmax-3);
//				vi.Add(cont+254);  esto se hace en el deflate
//			cout << "," << t_dist.GetCodigo(i-pos_max-1);
			cout << "," << i-pos_max;
			vi.Add(i-pos_max);
//			if (i-pos_max>4)
//				cout << " " << t_dist.GetVB(i-pos_max-1);
//				vi.Add(t_dist.GetVB(i-j-1));  esto se hace en el deflate
			cout << ")#";
			i+=contmax-1;
		}
		else{
			vi.Add(vc.Get(i));
			cout << vc.Get(i);
		}
	}
	vi.Add(256);
	cout << endl << "#REF Final fichero: 256" << endl;
}
