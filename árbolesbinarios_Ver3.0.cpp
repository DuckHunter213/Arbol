#include <iostream>
using namespace std;

class Nodo{
	int dato;
	Nodo *izquierdo;
	Nodo *derecho;
public:
	friend class Arbol;
};
class Arbol{
	Nodo *raiz;
public:
	Arbol();
	~Arbol();
	int estaVacio();
	Nodo *apuntadorRaiz();
	int esHoja(Nodo *&p);
	int alturaArbol(Nodo *&p,int contador,int &altura);
	int contarHojas(Nodo *&p,int contador);
	void PreOrden(Nodo *&p);
	void IndOrden(Nodo *&p);
	void PosOrden(Nodo *&p);
	int contarNodos(Nodo *&p,int contador);
	void insertar(int x,Nodo *&p);
	int buscar(Nodo *&p,int numero);
	int EliminarNodo(Nodo *&p,int numero);
	int masDerecha(Nodo *&p);
};
Arbol::Arbol(){raiz=NULL;}
Arbol::~Arbol(){}
int Arbol::estaVacio(){return raiz==NULL;}
Nodo *Arbol::apuntadorRaiz(){return raiz;}
int Arbol::esHoja(Nodo *&p){return (p->derecho==NULL && p->izquierdo==NULL);}
int Arbol::EliminarNodo(Nodo *&p,int numero){
	if(estaVacio())
		return 0;
	if(p->izquierdo!=NULL){
		EliminarNodo(p->izquierdo,numero);
	}
	if(p->dato==numero){
		if(esHoja(p)){
			p=NULL;
		}
		if(p->derecho==NULL && p->izquierdo!=NULL){
			p = p->izquierdo;
			p->izquierdo=NULL;
		}
		if (p->izquierdo==NULL && p->derecho!=NULL){
			p = p->derecho;
			p->derecho=NULL;
		}
		if(p->izquierdo==NULL && p->derecho==NULL){
			Nodo *Temp;
			Nodo *aux1;
			Nodo *aux2;
			Temp = new Nodo;
			aux1 = new Nodo;
			aux2 = new Nodo;
			Temp = p;
			aux1 = p->izquierdo;
			aux2 = p->izquierdo;
			if(aux2->derecho!=NULL){
				aux2->dato = masDerecha(aux2);
			}
			Temp = aux2;
			aux1->derecho = NULL;
			Temp = NULL;
			aux2 = NULL;
		}
	}
	if(p->derecho!=NULL){
		EliminarNodo(p->derecho,numero);
	}
}
int Arbol::masDerecha(Nodo *&p){
	if(p->derecho!=NULL)
		masDerecha(p->derecho);
	return p->dato;
}
int Arbol::alturaArbol(Nodo *&p, int contador,int &altura){
	if(estaVacio()){
		cout<<"Esta Vacio: ";
		return 0;
	}
	if(p->izquierdo!=NULL){
		alturaArbol(p->izquierdo,contador+1,altura);
	}
	if(p->derecho!=NULL){
		alturaArbol(p->derecho,contador+1,altura);
	}
	if(contador<altura){
		altura = contador;
	}
	return contador-1;
}
int Arbol::contarHojas(Nodo *&p, int contador){
	if(estaVacio()){
		cout<<"Esta Vacio: ";
		return 0;
	}
	if(p->izquierdo!=NULL){
		contador = contarHojas(p->izquierdo,contador);
	}
	if(p->derecho!=NULL){
		contador = contarHojas(p->derecho,contador);
	}
	if(esHoja(p)){
		contador=contador+1;
	}
	return contador;
}
void Arbol::PreOrden(Nodo *&p){
	cout<<p->dato<<",";
	if(p->izquierdo!=NULL)
		PreOrden(p->izquierdo);
	if(p->derecho!=NULL)
		PreOrden(p->derecho);
}
void Arbol::IndOrden(Nodo *&p){
	if(p->izquierdo!=NULL)
		IndOrden(p->izquierdo);
	cout<<p->dato<<",";
	if(p->derecho!=NULL)
		IndOrden(p->derecho);
}
void Arbol::PosOrden(Nodo *&p){
	if(p->izquierdo!=NULL)
		PosOrden(p->izquierdo);
	if(p->derecho!=NULL)
		PosOrden(p->derecho);
	cout<<p->dato<<",";
}
int Arbol::contarNodos(Nodo *&p, int contador){
	if(estaVacio()){
		cout<<"Esta Vacio: ";
		return 0;
	}
	if(p->izquierdo!=NULL){
		contador = contarNodos(p->izquierdo,contador);
	}
	if(p->derecho!=NULL){
		contador = contarNodos(p->derecho,contador);
	}
	return contador+1;
}
void Arbol::insertar(int x,Nodo *&p){
	if(p == NULL){
		p = new Nodo;
		p->dato = x;
		p->izquierdo = NULL;
		p->derecho = NULL;
		if(estaVacio()){
			raiz=p;
		}
	}
	else if (x < p->dato)
		insertar(x, p->izquierdo);
	else if (x > p->dato)
		insertar(x, p->derecho);
	else
		cout<<"\n El dato ya existe.";
}
int Arbol::buscar(Nodo *&p,int numero){
	if(estaVacio())
		return 0;
	if(p->izquierdo!=NULL){
		buscar(p->izquierdo,numero);
	}
	if(p->dato==numero){
		return 1;
	}
	if(p->derecho!=NULL){
		buscar(p->derecho,numero);
	}
	return 0;
}
int main(){
	int x;
	Nodo *p;
	Arbol arbol_1;
	p=arbol_1.apuntadorRaiz();
	int contador=0,menu=0,altura=0;
	while(menu!=5){
		cout<<"1.-Agregar"<<endl;
		cout<<"2.-Mostrar"<<endl;
		cout<<"3.-Contar"<<endl;
		cout<<"4.-Buscar"<<endl;
		cout<<"5.-Contar Hojas"<<endl;
		cout<<"6.-Altura del Arbol"<<endl;
		cout<<"7.-Eliminar Numero"<<endl;
		cout<<"10.-Salir"<<endl;
		cin>>menu;
		switch(menu){
		case 1://Agregar Nodo
			cout<<"Dame el valor del Nodo: ";
			cin>>x;
			arbol_1.insertar(x,p);
			break;
		case 2://Mostrar
			cout << "Preorden: "<<endl;
			arbol_1.PreOrden(p);
			cout <<endl;
			cout << "Inorden: "<<endl;
			arbol_1.IndOrden(p);
			cout <<endl;
			cout << "Posorden: "<<endl;
			arbol_1.PosOrden(p);
			cout <<endl;
			cout<<endl;
			break;
		case 3://Contar Nodos
			cout <<arbol_1.contarNodos(p,contador)<<endl;
			break;
		case 4://Buscar
			if(arbol_1.estaVacio()){
				cout <<"Esta vacio"<<endl;
				break;
			}
			cout <<"Dame el numero a buscar"<<endl;
			cin >> x;
			x=arbol_1.buscar(p,x);
			if (x==1)
				cout << "Numero encontrado"<<endl;
			else
				cout << "No se encontro numero"<<endl;
			break;
		case 5://Contar Hojas
			cout <<arbol_1.contarHojas(p,contador)<<endl;
			break;
		case 6://Altura del arbol
			arbol_1.alturaArbol(p,contador,altura);
			cout<<"Altura del Arbol"<<altura<<endl;
			break;
		case 7:
			cout<<"Dame el numero a eliminar:";
			cin>>x;
			arbol_1.EliminarNodo(p,x);
			break;
		case 10:
			menu=5;
			break;
		default:
			cout<<"Estas mal No ingresaste un numero valido"<<endl;
		}
	}
	return 0;
}