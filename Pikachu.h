#pragma once
#include "Entidad.h"
class Pikachu :
    public Entidad
{
private:
    Direcciones ultimaTecla;
public:
    Pikachu(int x, int y):Entidad(x,y) {
        this->x = x;
        this->y = y;
        iteraX = 0;
        iteraY = 0;
        dx = dy = 0;
        direccion = Direcciones::Ninguna;
        ultimaTecla = Direcciones::Abajo;
    }
    ~Pikachu(){}
    void dibujarPikachu(BufferedGraphics^ buffer, Bitmap^ bmp) {
        ancho = bmp->Width/4;
        alto = bmp->Height/4;

        dibujarDesdeEntidad(buffer, bmp);
    }

    void moverPikachu(BufferedGraphics^ buffer, Bitmap^ bmp) {
        if (iteraX >= 0 && iteraX < 3) iteraX++;
        else iteraX = 0;
        switch (direccion)
        {
        case Arriba:
            iteraY = 3;
            dy = -10;
            dx = 0;
            ultimaTecla = Arriba;
            break;
        case Abajo:
            iteraY = 0;
            dy = 10;
            dx = 0;
            ultimaTecla = Abajo;
            break;
        case Derecha:
            iteraY = 2;
            dx = 10;
            dy = 0;
            ultimaTecla = Derecha;
            break;
        case Izquierda:
            iteraY = 1;
            dx = -10;
            dy = 0;
            ultimaTecla = Izquierda;
            break;
        case Ninguna:
            dx = 0;
            dy = 0;
            switch (ultimaTecla)
            {
            case Arriba:
                iteraX = 0;
                iteraY = 3;
                break;
            case Abajo:
                iteraX = 0;
                iteraY = 0;
                break;
            case Derecha:
                iteraX = 0;
                iteraY = 2;
                break;
            case Izquierda:
                iteraX = 0;
                iteraY = 1;
                break;
            }
            break;
        }
        dibujarPikachu(buffer,bmp);
    }
    void setDireccionPikachu(Direcciones direx) { this->direccion = direx; }
};

