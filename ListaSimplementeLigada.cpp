#include <iostream>
using namespace std;
class Socio{
    private:
        int NumeroSocio;
        string NombreSocio;
        string Domicilio;
        int AnioIngreso;
    public:
        Socio(){}
        friend ostream& operator<<(ostream& O, Socio& x){
            O << "\nNumero de socio: " << x.NumeroSocio;
            O << "\nNombre: " << x.NombreSocio;
            O << "\nDomicilio: " << x.Domicilio;
            O << "\nAnio de Ingreso: " << x.AnioIngreso;
        return O;
        }
        friend istream& operator>>(istream& I, Socio& x){
            cout << "\nNumero de socio: ";
            I >> x.NumeroSocio;
            cout << "Nombre: ";
            I >> x.NombreSocio;
            cout << "Domicilio: ";
            I >> x.Domicilio;
            cout << "Anio de Ingreso: ";
            I >> x.AnioIngreso;
            return I;
    }

    int getIng(){
        return AnioIngreso;
    }
    int getNumS(){
        return NumeroSocio;
    }

    const string& getNomS() const {
        return NombreSocio;
    }

    const string& getDomi() const {
        return Domicilio;
    }
};


template<class T>
class LSLSE;

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr){};
    friend class LSLSE<T>;
};

template<class T>
class LSLSE{
private:
    node<T>* lista;
public:
    LSLSE():lista(nullptr){};
    bool vacia()const;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
    void imprimir()const;
    void Buscar(string, string);
    void insercion(node<T>* aux);

};

template<class T>
void LSLSE<T>::Buscar(string Nom, string Dom){
    node<T>* aux=lista;
    int i=0, num;
    while(aux!=nullptr){
        if(aux->data.getNomS() == Nom && aux->data.getDomi() == Dom){
            cout<<"\nSocio encontrado con exito: \n"<<aux->data;
            i=1;
        }
        aux=aux->sig;
    }
    if(i == 0){
        cout<<"\nEl socio que intenta buscar no esta dado de alta\n";
    }
}

template<class T>
void LSLSE<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=nullptr){
        cout<<aux->data<<"\n";
        aux=aux->sig;
    }
}

template<class T>
bool LSLSE<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void LSLSE<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        insercion(aux);
    }
}

template<class T>
void LSLSE<T>::insercion(node<T>* aux){
    node<T>* Xa= lista;
    int i=0,c=0;
    while(Xa!=nullptr){
        if(Xa->data.getNumS() == aux->data.getNumS()){
            i=2;
            //cout<<"\n\nEste numero de socio ya esta en uso\n";
        }
        if(i==0){
            if(Xa->data.getNumS()<aux->data.getNumS()){
                if(Xa->sig==nullptr){
                    Xa->sig=aux;
                }
            }
            if(Xa->data.getNumS()>aux->data.getNumS()&&c!=2){
                aux->sig=lista;
                lista=aux;
                c=2;
            }
        }
        Xa=Xa->sig;
    }
}




template<class T>
node<T>* LSLSE<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* LSLSE<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* LSLSE<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool LSLSE<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

int menu();

int main()
{
    LSLSE<Socio> milista;
    Socio x;
    int opc, total=0;
    string Nombre, Domicilio;
    do{
        opc = menu();
        cout<<"\n";
        switch(opc){
            case 1:{
                cout<<"Ingresa datos\n";
                cin>>x;
                milista.insertar(milista.ultimo(),x);
                total++;
                cout<<"\n\n";
                break;}
            case 2:
                milista.eliminar(milista.ultimo());
                cout<<"Socio dado de baja con exito\n\n";
                total--;
                break;
            case 3:
                milista.imprimir();
                cout<<"\n\n";
                break;
            case 4:
                cout<<"A continuacion escribe el nombre de socio que desea buscar\n";
                cin>>Nombre;
                cout<<"\nA continuacion escribe el domicilio tambien del socio que desea buscar\n";
                cin>>Domicilio;
                milista.Buscar(Nombre,Domicilio);
                cout<<"\n";
                break;
            case 5:
                cout<<"\nTotal de socios registrados en el club:\t"<<total;
                cout<<"\n\n\n";
                break;
            case 6:
                break;
        }
    }while(opc!=6);
    return 0;
}

int menu(){
    int opc;
    cout<<"MENU\n"
    <<"1. Registrar un nuevo socio\n"
    <<"2. Dar de baja un socio\n"
    <<"3. Generar reporte de los socios del club\n"
    <<"4. Buscar un socio\n"
    <<"5. Calcular e imprimir total de socios registrados\n"
    <<"6. Salir\n"
    <<"Elige tu opcion: \t";
    cin>>opc;
    return opc;
}
