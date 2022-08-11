
//QUIZ 1 Estructuras de Datos
//Sarah Priscilla Quesada Chaves
//2021046027

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


struct vagon {       //estructura de vagon
    int asientos[15];    //array de asientos, van a haber 15 en cada vagon
    //El valor 1 en el array de asientos signfica OCUPADO y el valor 0 DESOCUPADO
}   vagon1, vagon2, vagon3;   //creo los vagones que tendra


struct tren {        //estructura de tren
    int n_vagones;      //numero de vagones en tren
    vagon vagones[3];   //array de vagones, conformado por estructuras de tipo vagon
}   tren1;              //creo el tren


void marcar_asiento_ocupado(int numvag, int numasi) {    //funcion para marcar un asiento como ocupado
    //esta funcion recibe como parametro el numero de vagon (numvag) donde se ocupa el asiento
    //y tambien el numero de asiento (numasi) que se ocupara en ese orden respectivo
    if (tren1.vagones[numvag].asientos[numasi] != 1) {   //revisamos si no esta ocupado aun
        tren1.vagones[numvag].asientos[numasi] = 1;  //porque 1 representa ocupado, lo marcamos asi
    } else {
        //en caso de que si este ocupado desplegamos mensaje
        cout << "El asiento seleccionado se encuentra ocupado, por favor seleccione otro." << endl;
    }
};

void marcar_asiento_disponible(int numvag, int numasi) {    //funcion para marcar un asiento como disponible
    //esta funcion recibe como parametro el numero de vagon (numvag) donde se desocupa el asiento
    //y tambien el numero de asiento (numasi) que se desocupara en ese orden respectivo
    if (tren1.vagones[numvag].asientos[numasi] != 0) {   //revisamos si no esta disponible
        tren1.vagones[numvag].asientos[numasi] = 0;  //porque 0 representa disponible, lo marcamos asi
    } else {
        //en caso de que ya estuviera desocupado desplegamos mensaje
        cout << "El asiento seleccionado ya se encuentra desocupado, por favor seleccione otro." << endl;
    }
};


void listar_10asientos(tren train) {
    //funcion que recibe el tren por parametro y lista los primeros 10 asientos disponibles y
    //los ultimos 10 disponibles
    int contardispo = 0;               //contador para saber cuando ya encontramos 10 disponibles
    //Empezamos con los diez primeros
    cout << "Listado de los primeros 10 asientos disponibles: " << endl;
    for (int j = 0; j < 3; ++j) {      //el 3 es porque son tres vagones, si se cambia, esto importa
        //iterando por los vagones j
        for (int i = 0; i < 15; ++i) {   //15 porque son 15 asientos por vagon
            if (train.vagones[j].asientos[i] == 0 && contardispo < 10) {
                //Si el asiento esta desocupado y el contador de disponible es menor que 10
                contardispo ++;    //subimos contador de disponibles
                cout << "Asiento: " << i << " de vagon: " << j << " disponible." << endl;
            }
        }
    }
    //Procedemos con los diez últimos
    int contardispo2 = 0;               //contador para saber cuando ya encontramos 10 disponibles
    cout << "Listado de los últimos 10 asientos disponibles: " << endl;
    //aca vamos a hacer las cosas al reves porque hay que ir de los utimos
    for (int p = 2; p >= 0; --p) {      //el 2 es porque son tres vagones, si se cambia, esto importa
        //iterando por los vagones p
        for (int r = 14; r >= 0; --r) {   //14 porque son 15 asientos por vagon
            if (train.vagones[p].asientos[r] == 0 && contardispo2 < 10) {
                //Si el asiento esta desocupado y el contador de disponible es menor que 10
                contardispo2 ++;    //subimos contador de disponibles
                cout << "Asiento: " << r << " de vagon: " << p << " disponible." << endl;
            }
        }
    }
};


int main()
{    
    /*
    En el siguiente ejemplo se puede ver que los asientos que marcamos como ocupados
    no aparecen en el listado de los 10 primeros disponibles cuando llamamos la funcion
    que se encarga de ello.
    Se pueden hacer cambios para probar y ver como trabajan mis dos funciones de ocupar y
    desocupar asientos, siempre que los parametros dados no se salgan de rango.
    Si se desea ampliar el sistema, se puede hacer la modificación dentro de las estructuras.
    */
    marcar_asiento_ocupado(0,0);  //primer parametro es vagon, segundo es asiento
    marcar_asiento_ocupado(0,2);
    marcar_asiento_ocupado(0,4);  
    marcar_asiento_ocupado(0,6);  
   
    /*
    En el siguiente ejemplo, pongo ocupados algunos de los ultimos asientos para que
    sea observable que no aparecen en el listado de los ultimos 10 disponibles.
    Se pueden hacer cambios y pruebas. Aclaro que este tren tiene 3 vagones, que son
    0, 1 y 2, se puede expandir si se desea. Pero en este caso el vagon cero es el
    primero y el dos, evidentemente, el ultimo.
    */
    marcar_asiento_ocupado(2,13);  //primer parametro es vagon, segundo es asiento
    marcar_asiento_ocupado(2,9);
    marcar_asiento_ocupado(2,11);  
    marcar_asiento_ocupado(2,7);  
   
    listar_10asientos(tren1);    //llamamos funcion que lista los primeros y los ultimos
                                 //diez asientos diesponibles.
    return 0;
}
