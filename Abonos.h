#ifndef ABONOS_H_INCLUDED
#define ABONOS_H_INCLUDED
#include "Fecha.h"
class Abonos{
    private:
        Fecha *fechaAbono;
        float montoAbono;
    public:
        Abonos(Fecha *fa, float ma){
        this->fechaAbono = fa;
        this->montoAbono = ma;
        }
        void setFecha(Fecha *fa){
        this->fechaAbono = fa;
        }
        Fecha *getFechaAbono(){
        return this->fechaAbono;
        }
        void setMonto(float ma){
        this->montoAbono = ma;
        }
        float getMonto(){
        return this->montoAbono;
        }
};



#endif // ABONOS_H_INCLUDED
