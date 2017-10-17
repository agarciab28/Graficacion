#include<iostream>
#include<iomanip>

using namespace std;

template<class T>
class Nodo
{
      public: T info;
              Nodo<T>*sig;
              Nodo(const T);
};

template<class T>
class Lista 
{
      private: Nodo <T> *le;
      public:  Lista(); 
      ~Lista();
      int length();
      void Insertar(const T);
      T Eliminar(const T);
      int Vacia();
      int arrayList(int posicion);
      
};


template<class T>
Nodo<T>::Nodo(const T v) 
{
     info = v;
     sig = NULL;
}


template<class T>
Lista<T>::Lista() 
{
    le = NULL;
}


template<class T>
Lista<T>::~Lista() 
{
    Nodo <T>*sale;
    T val;
    while(le) 
    {
       sale=le;
       le=le->sig;
       val=sale->info;
       delete(sale);
    }
    delete le;
}


template<class T>
void Lista<T>::Insertar(const T v) 
{
     Nodo <T>*tmp;
     if (Vacia() || le->info > v) 
     {
        Nodo <T>*nvo = new Nodo<T>(v);
        nvo->sig = le;
        le = nvo;
     }
     else 
     {
         tmp = le;
         
         while(tmp->sig && tmp->sig->info <= v)  
         {
             tmp = tmp->sig;
         }
         
         Nodo <T>*nvo = new Nodo<T>(v);
         nvo->sig = tmp->sig;
         tmp->sig = nvo; 
     }
}


template<class T>
T Lista<T>::Eliminar(const T v) 
{
     Nodo <T>*tmp, *nodo;
     nodo = le;
     tmp = NULL;
     while(nodo && nodo->info < v) 
     {
        tmp = nodo;
        nodo = nodo->sig;
     }
     if(!nodo || nodo->info != v) return 0;
     else 
     {
        if(nodo==le)
        le = nodo->sig;
        else
        tmp->sig = nodo->sig;
        delete nodo;
     }
     return v;
}


template<class T>
int Lista<T>::Vacia() 
{
    return le==NULL ? 1 : 0;
}

template<class T>
int Lista<T>::length() 
{
     Nodo<T> *tmp=le;
     
     if(!Vacia()) 
     {
     	int contador = 0;
         while(tmp) 
         {
		 	contador++;
            tmp = tmp->sig;
         }
	 	 return contador;
     }
     else
     {
     	return 0;
	 }    
}

template<class T>
int Lista<T>::arrayList(int posicion) 
{
     Nodo<T> *tmp=le;
     
     if(!Vacia()) 
     {
     	for(int i=0; i <= posicion; i++)
     	{
     		if(i==posicion)
     		{
     			return tmp->info;
     		}
     		tmp = tmp->sig;//avanza al siguiente nodo hasta encontrar la posicion del dato que deseamos retornar
     	}
	 	 return 0;
     }
     return 0;
}


