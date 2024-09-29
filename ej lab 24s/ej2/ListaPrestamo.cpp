#include "ListaPrestamo.h"
#include <fstream>

bool ListaPrestamo::leerPrestamos(Catalogo& catalogo)
{
    // abre el archivo coches.txt
    std::fstream prestamoRead("prestamos.txt");

    int c; // codigo del ejemplar
    int u; // usuario del prestamo
    int tam = 0;

    // fecha del prestamo
    int day;
    int month;
    int year;
    char barra;

    // saca el tama�o de la lista de coches
    prestamoRead >> tamArrayPrestamo;

    // crea el array dinamico
    ArrayPrestamo = new Prestamo[tamArrayPrestamo];

    // bucle para leer los datos
    for (int i = 0; i < tamArrayPrestamo; i++)
    {
        prestamoRead >> c; // lee el codigo

        tam = catalogo.getTam();
        ArrayPrestamo[i].setEjemplar(catalogo.buscarEjemplar(c, 0, tam)); // lo mete

        // lee la fecha
    	barra = ' ';
        day = 0;
        month = 0;
        year = 0;

        prestamoRead >> day;
        prestamoRead >> barra;
        prestamoRead >> month;
        prestamoRead >> barra;
        prestamoRead >> year;

        ArrayPrestamo[i].setDate(day, month, year); // lo mete

        prestamoRead >> u; // lee el user
        ArrayPrestamo[i].setUser(u); // lo mete 
    }

    return prestamoRead.is_open(); // true -> archivo prestamos abierto / false -> error  
}

void ListaPrestamo::ordenarPrestamos()
{

}

void ListaPrestamo::mostrarPrestamos()
{
    for(int i = 0; i < tamArrayPrestamo; i++)
    {
        std::cout << ArrayPrestamo[i].getDate() + ArrayPrestamo[i].duracionPrestamo((ArrayPrestamo[i].getEjemplar())->getTipo());
        std::cout << " ";
        std::cout << "(en " << ArrayPrestamo[i].getDate() - 
    }
}