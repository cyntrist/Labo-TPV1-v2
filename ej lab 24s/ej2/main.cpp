// Nieves Alonso Gilsanz

#include "Catalogo.h"
#include "ListaPrestamo.h"
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Catalogo catalogo;
    ListaPrestamo listaPrestamo;

    // carga catalogo y lista prestamos
    catalogo.leerCatalogo();
    listaPrestamo.leerPrestamos(catalogo);

    // ordena prestamos
    listaPrestamo.ordenarPrestamos();

    // mostrar un men� con opciones para:
    //  - mostrar el cat�logo
    //  - mostrar los pr�stamos
    //  - a�adir un nuevo ejemplar (*)
    //  - prestar un ejemplar (*)
    //  - devolver un ejemplar (*)
    //  - salir

    // (*) Al a�adir un ejemplar o pr�stamo la lista correspondiente debe quedar ordenada,
    // para lo cual deber� insertarse en su lugar desplazando elementos si es necesario.
    // En caso de no haber espacio en la lista correspondiente se indicar� mediante un mensaje al usuario.


    listaPrestamo.mostrarPrestamos();

    return 0;
}