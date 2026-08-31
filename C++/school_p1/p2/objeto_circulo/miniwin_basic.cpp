#include "miniwin.h"
using namespace miniwin;

int main() {
    vredimensiona(640, 480);

    color(AZUL);
    rectangulo_lleno(50, 50, 200, 200);

    refresca();

    while(tecla()==NINGUNA);
    vcierra();
    
    return EXIT_SUCCESS;
}