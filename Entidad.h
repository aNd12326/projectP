#pragma once

using namespace System::Drawing;
enum Direcciones{Arriba,Abajo,Derecha,Izquierda,Ninguna};
class Entidad
{
protected:
	int x, y, dx, dy, ancho, alto, iteraX, iteraY;
	Direcciones direccion;

public:
	Entidad() {

	}
	~Entidad(){}
	Entidad(int x,int y){
		dx = dy = ancho = alto = iteraX = iteraY = 0;
	}
	void dibujarDesdeEntidad(BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.2, alto * 1.2);
		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
		x += dx;
		y += dy;
	}
};

