#include <iostream>

using namespace std;
#include <stdlib.h>
#include "Cliente.h"
#include "Cuenta.h"
#include "Abonos.h"
#define TA 5
int menu(){
    int op;
    cout << "MENU DE OPCIONES\n";
    cout << "1.Agregar Cliente a la Lista\n";
    cout << "2.Agregar cuenta a la Lista\n";
    cout << "3.Hacer abonos\n";
    cout << "4.Mostrar Lista de clientes\n";
    cout << "5.Mostrar Lista de cuentas\n";
    cout << "6.Mostrar detalles de la cuenta\n";
    cout << "7.Salir\n";
    cout << "Digite la opcion : ";
    cin >> op;
    return op;
}
Cliente *agregarCliente(){
    int id;
    string n, a;
    Cliente *cli;
    cout << "Digite el id del cliente: ";
    cin >> id;
    cout << "Digite el nombre del cliente: ";
    cin >> n;
    cout << "Digite el apellido del cliente: ";
    cin >> a;
    cli = new Cliente(id, n, a);
    return cli;
}
void mostrarClientes(Cliente *lst[], int cont){
    if(cont==0)
        cout << "La lista de clientes esta vacia\n";
    else{
        cout << "Id\tNombre\tApellido\n";
        for(int i=0;i<cont;i++){
            cout << lst[i]->getIdCliente() << "\t";
            cout << lst[i]->getNombre() << "\t";
            cout << lst[i]->getApellido() << "\n";
        }
    }
}
Cliente *buscarCliente(Cliente *lst[], int cCli, int id){
    bool encontrado = false;
    Cliente *cli = NULL;
    int c = 0;
    while(c < cCli && !encontrado){
        if(lst[c]->getIdCliente()==id){
            encontrado = true;
            cli = lst[c];
        }
        else{
            c++;
        }
    }
    return cli;
}
Cuenta *agregarCuenta(Cliente *lst[], int contCli){
    int idCli, nc;
    Cuenta *cta = NULL;
    cout << "Digite el id del cliente a quien se asignara la cuenta: ";
    cin >> idCli;
    Cliente *cli = buscarCliente(lst, contCli, idCli);
    if(cli){
        ///Se encontro el cliente en la lista
        cout << "Digite el numero de cuenta: ";
        cin >> nc;
        cta = new Cuenta(nc);
        cta->setCliente(cli);
    }
    return cta;
}
void mostrarCuentas(Cuenta *lst[], int cont){
    if(cont==0)
        cout << "La lista de cuentas esta vacia\n";
    else{
        cout << "Numero\tCliente\tSaldo\n";
        for(int i=0;i<cont;i++){
            Cuenta *cta = lst[i];
            cout << cta->getNumeroCuenta() << "\t";
            cout << cta->getCliente()->getNombre() << " " << cta->getCliente()->getApellido() << "\t";
            cout << cta->getSaldo() << "\n";
        }
    }
}
void mostrarDetallesCuentas(Cuenta *lst[], Abonos *lsta[], int cont){
    if(cont==0)
        cout << "La lista de cuentas esta vacia\n";
    else{
        cout << "Numero\tCliente\tAbonos\tSaldo\n";
        for(int i=0;i<cont;i++){
            Cuenta *cta = lst[i];
            cout << cta->getNumeroCuenta() << "\t";
            cout << cta->getCliente()->getNombre() << " " << cta->getCliente()->getApellido() << "\t";
            cout << cta->getSaldo() << "\n";
        }
    }
}
Cuenta *buscarCuenta(Cuenta *lst[], int cCue, int nc){
    bool encontrado = false;
    Cuenta *cta = NULL;
    int c = 0;
    while(c < cCue && !encontrado){
        if(lst[c]->getNumeroCuenta()==nc){
            encontrado = true;
            cta = lst[c];
        }
        else{
            c++;
        }
    }
    return cta;
}
int main(){
    int opc;
    Cliente *lstCliente[TA];
    Cuenta *lstCuenta[TA];
    Abonos *lstAbonos[TA];
    int contCli = 0;
    int contCue = 0;
    do{
        system("cls");
        opc = menu();
        switch (opc){
            case 1:
                ///AGREGAR CLIENTES
                if (contCli < TA){
                    lstCliente[contCli] = agregarCliente();
                    contCli++;
                }
                else {
                    cout << "La lista de clientes esta llena.\n";
                }
                break;
            case 2:
                ///AGREGAR CUENTAS
                if (contCue < TA){
                    Cuenta *cta = agregarCuenta(lstCliente, contCli);
                    if(cta){
                        lstCuenta[contCue] = cta;
                        contCue++;
                    }
                }
                else {
                    cout << "La cuenta no se agrego porque el cliente no existe.\n";
                }
                break;
            case 3:
                ///HACER ABONOS
                {
                    int nc, ma, d, m, a;
                    Fecha *f;
                    Abonos *ab;
                    cout << "Digite el numero de cuenta a la que desea hacer el abono: ";
                    cin >> nc;
                    Cuenta *cta = buscarCuenta(lstCuenta, contCue, nc);
                    if(cta){
                        cout << "Digite el monto: ";
                        cin >> ma;
                        cout << "Digite la fecha dd/mm/aa (Enter): ";
                        cin >> d;
                        cin >> m;
                        cin >> a;
                        f = new Fecha(d,m,a);
                        ab = new Abonos(f, ma);
                        cta->addAbonos(ab);
                    }
                    else{
                        cout << "No se puede hacer un abono a una cuenta inexistente.";
                    }
                }
                break;
            case 4:
                ///MOSTRAR LISTA DE CLIENTES
                mostrarClientes(lstCliente, contCli);
                break;
            case 5:
                ///MOSTRAR LISTA DE CUENTAS
                mostrarCuentas(lstCuenta, contCue);
                break;
            case 6:
                ///MOSTRAR DETALLES DE LA CUENTA
                mostrarDetallesCuentas(lstCuenta, lstAbonos, contCue);
                break;
            case 7:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Error, opcion no definida.\n";
                break;
        }
        system("pause");
    }while(opc!=7);
    return 0;
}
