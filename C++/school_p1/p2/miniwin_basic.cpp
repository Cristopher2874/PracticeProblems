#include "miniwin.h"
using namespace miniwin;

int main() {
    vredimensiona(400, 300);
    color(AZUL);
    rectangulo_lleno(50, 50, 200, 200);
    refresca();
    return 0;
}