#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <string.h>
class Cliente{
    private:
        int idCliente;
        string Nombre;
        string Apellido;
    public:
        Cliente(int id, string n, string a){
            this->idCliente = id;
            this->Nombre = n;
            this->Apellido = a;
        }
        void setIdCliente(int id){
            this->idCliente = id;
        }
        int getIdCliente(){
            return this->idCliente;
        }
        void setNombre(string n){
            this->Nombre = n;
        }
        string getNombre(){
            return this->Nombre;
        }
        void setApellido(string a){
            this->Apellido = a;
        }
        string getApellido(){
            return this->Apellido;
        }
};
#endif // CLIENTE_H_INCLUDED
