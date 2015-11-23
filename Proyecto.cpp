#include <iostream>
#include <cctype>
using namespace std;

class Nodo{
	string nombre;
	int fechaEdicion;
	string artista;
	Nodo *sig;
	Nodo *ant;
public:
	friend class Lista;
};


class Lista{
private:
	Nodo *cab;
public:
	Lista();
	void nuevoNodo(string nombre,int fechaEdicion,string artista);
	int estaVacia();
	void insertar(Nodo *&nuevo);
	void mostrar();
	void ordenarFechaEdicion();
	void ordenarArtista();
	void ordenarNombre();
	int comparaString();
	
};
Lista::Lista(){cab=NULL;}
int Lista::estaVacia(){return cab==NULL;}

void Lista::ordenarFechaEdicion(){
	Nodo *actual,*siguiente,*temporal,*aux;
	actual = new Nodo;
	siguiente = new Nodo;
	siguiente = cab->sig;
	aux = cab;
	int vuelta=0;
	while(aux!=NULL){
		aux = aux->sig;
		vuelta = vuelta+1;
	}
	int vuelta2=vuelta*vuelta;
	for(int i;i<=vuelta2;++i){
		while(cab!=NULL){
		if(cab->fechaEdicion>siguiente->fechaEdicion){
		temporal->nombre = cab->nombre;
		temporal->fechaEdicion = cab->fechaEdicion;
		temporal->artista = cab->artista;	
		
		cab->nombre = siguiente->nombre;
		cab->fechaEdicion = siguiente->fechaEdicion;
		cab->artista = siguiente->artista;
		
		siguiente->nombre = temporal->nombre;
		siguiente->fechaEdicion = temporal->fechaEdicion;
		siguiente->artista = temporal->artista;
		for(int i;i<=vuelta;++i){
			cab = cab->sig;
		}
		}	
		}
	}
}

int Lista::comparaString(){
	int i=0;
	Nodo *aux1,*aux2;
	aux1=aux2=cab;
	string artista1,artista2;
	artista1=aux1->artista;
	artista2=aux2->artista;
	while(toupper(artista1[i])==toupper(artista2[i])){
		i++;
	}
	if(toupper(artista1[i])>toupper(artista2[i])){
		return 1;
	}
	if(toupper(artista1[i])<toupper(artista2[i])){
		return 2;
	}
}
void Lista::ordenarArtista(){
	Nodo *aux,*aux1,*aux2,*aux3;
	aux=aux1=aux3=cab;
	aux2=cab->sig;
	int vuelta=0;
	while(aux!=NULL){
		aux = aux->sig;
		vuelta = vuelta+1;
	}
	aux=cab;
	for (int i=1;i<vuelta;++i){
		for (int j=0;j<vuelta-1;++j){
		aux1= aux;
		aux2 = aux->sig;
		int com=comparaString();
			if(com==1){
				aux3->nombre = aux1->nombre;
				aux3->fechaEdicion = aux1->fechaEdicion;
				aux3->artista = aux1->artista;	
				aux1->nombre = aux2->nombre;
				aux1->fechaEdicion = aux2->fechaEdicion;
				aux1->artista = aux2->artista;
				aux2->nombre = aux3->nombre;
				aux2->fechaEdicion = aux3->fechaEdicion;
				aux2->artista = aux3->artista;
			}
			aux = aux->sig;
		}
	aux=cab;
	}
}

void Lista::mostrar(){
	Nodo *aux;
	aux=cab;
	int vuelta=0;
	while(aux->ant!=NULL){
		cout<<"\n******** "<<vuelta+1 <<" ********"<<"******************"<<endl;
		cout<<"Nombre\t\t\t\t| "<<aux->nombre<<endl;
		cout<<"Fecha De Edicion\t\t| "<<aux->fechaEdicion<<endl;
		cout<<"Artista\t\t\t\t| "<<aux->artista<<endl;
		aux = aux->sig;
		vuelta = vuelta+1;
	}
}
void Lista::nuevoNodo(string nombre,int fechaEdicion,string artista){
	Nodo *nuevo;
	nuevo = new Nodo;
	nuevo->nombre = nombre;
	nuevo->fechaEdicion = fechaEdicion;
	nuevo->artista = artista;
	if(estaVacia()){
		nuevo->sig=nuevo;
		nuevo->ant=NULL;
		cab=nuevo;
	}
	nuevo->ant=cab;
	cab->sig=nuevo;
	nuevo->sig=nuevo;
}

int main(){
	string nombre,artista;
	int fechaEdicion,menu=0;
	Lista Lista1;
	Lista1.nuevoNodo("Black holes and revelations",2006,"Muse");
	Lista1.nuevoNodo("2ND law",2012,"Muse");
	Lista1.nuevoNodo("Black veil brides IV",2012,"Black Veil Brides");
	Lista1.nuevoNodo("Vicius delicius",2008,"Infected Mushrooms");
	Lista1.nuevoNodo("N 1",2013,"Teen Top");
	Lista1.nuevoNodo("Hail to king",2013,"Avengend Sevenfold");
	Lista1.nuevoNodo("The black parade",2007,"My Chemical Romance");
	Lista1.nuevoNodo("All we know is falling",2005,"Paramore");
	Lista1.nuevoNodo("AM",2013,"Arctic Monkeys");
	Lista1.nuevoNodo("Battle for the sun",2003,"Placebo");
	Lista1.nuevoNodo("La ciudad de los arboles",2007,"Mago de oz");
	Lista1.nuevoNodo("Un dia en la suburbia",2008,"Nach");
	Lista1.nuevoNodo("Easy and tropical machine",2013,"Aguas Aguas");
	do{
		cout<<"1.-Ingresar nuevas entradas: "<<endl;
		cout<<"2.-Mostar Libreria: "<<endl;
		cout<<"3.-Ordenar por fecha de edicion: "<<endl;
		cout<<"4.-Ordenar por nombre: "<<endl;
		cout<<"5.-Ordenar por artista: "<<endl;
		cout<<"6.-Salir: "<<endl;
		cin>>menu;
		switch(menu){
		case 1:
			cout<<"Dame el nombre del album: "<<endl;
			cin.ignore(256,'\n');
			getline(cin,nombre);
			cout<<"Dame el artista: "<<endl;
			cin.ignore(256,'\n');
			getline(cin,artista);
			cout<<"Dame la fecha de salida: "<<endl;
			cin>>fechaEdicion;
			Lista1.nuevoNodo(nombre,fechaEdicion,artista);
			break;
		case 2:
			Lista1.mostrar();
			break;
		case 3:
			Lista1.ordenarFechaEdicion();
			break;
		case 4:
			//Lista1.ordenarNombre();
			break;
		case 5:
			Lista1.ordenarArtista();
			break;
		case 6:
			menu=6;
		default:
			cout<<"Numero equivocado: "<<endl;
		}
	}while(menu!=6);
}
