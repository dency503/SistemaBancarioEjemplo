#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED
#include "Cliente.h"
#include "Abonos.h"
#define TAM 5
class Cuenta{
    private:
        int numeroCuenta;
        Cliente *cliente;
        Abonos *abonos[TAM];
        Abonos *monto;
        float saldo;
        int contadorAbonos;
    public:
        Cuenta(int nc){
            this->numeroCuenta = nc;
            this->saldo = 0;
            this->contadorAbonos = 0;
        }
        int getNumeroCuenta(){
            return this->numeroCuenta;
        }
        Cliente *getCliente(){
            return this->cliente;
        }
        //Abonos *getMonto(){
        //    return this->abonos;
        //}
        void setCliente(Cliente *cli){
            this->cliente = cli;
        }
        void addAbonos(Abonos *ab){
            if(this->contadorAbonos < TAM){
                this->abonos[this->contadorAbonos] = ab;
                this->contadorAbonos++;
                this->saldo = this->saldo + ab->getMonto();
            }
            else{
                cout << "La lista de abonos esta llena\n";
            }
        }
        Abonos **getAbonos(){
            return this->abonos;
        }
        Abonos *getMonto(){
            return this->monto;
        }
        float getSaldo(){
            return this->saldo;
        }
        int getContadorAbonos(){
            return this->contadorAbonos;
        }
};


#endif // CUENTA_H_INCLUDED
