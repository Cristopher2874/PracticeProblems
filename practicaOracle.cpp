/*
Problema 1
Tenemos un sistema que permite crear una nueva contraseña. 
Necesitamos una función que verifique que la nueva contraseña no es un anagrama de la contraseña anterior.
Dada nueva_contraseña y vieja_contraseña, regresa TRUE si nueva_contraseña es un anagrama de vieja_contraseña, y FALSE de otra forma.

Ejemplo 1:
Input: s = "anagram", t = "nagaram"
Output: true

Ejemplo 2:
Input: s = "rat", t = "car"
Output: false

Limites:
1 <= nueva_contraseña.length, vieja_contraseña.length <= 5 * 104
nueva_contraseña y  vieja_contraseña contienen solamente caracteres en minúscula del español. (poco seguro para una contraseña 0.o????) 
*/

#include <bits/stdc++.h>

using namespace std;

bool revisarContraseña(string vieja, string nueva){
    if(vieja.size() < 1 || nueva.size() < 1) return false;
    if(vieja.size() != nueva.size()) return false;
    map<char, int> existe;
    for(int i = 0; i<vieja.size(); ++i){
        if(existe[vieja[i]]){
            existe[vieja[i]]++;
        }else{
            existe[vieja[i]] = 1;
        }
    }
    for(int i = 0; i<nueva.size(); ++i){
        if(!existe[nueva[i]] || existe[nueva[i]] < 0){
            return false;
        }else{
            existe[nueva[i]]--;
        }
    }
    return true;
}

int main(){
    string vieja = "anagram";
    string nueva = "nagaram";
    revisarContraseña(vieja, nueva);
    return 0;
}

/*
Cosas que salieron bien
terminé el 90% del código c++ en 20 minutos
No me bloqueé en la parte de SQL
Agradecí a la reclutadora por la oportunidad
Me presenté en general y mi historia
Puse mi conocimiento de manejo de equipos, liderazgo y trabajo en equipo
Se usar metodologías tipo Kanban o Srum
Participación en los hacks y proyectos relevantes
Logré dos queries de SQL con investigación rápida en internet
Respondí un poco acerca de mi historia
Respondí normal a la pregunta de qué dificultades he enrfentado
Respondí bien la pregunta de qué proyecto me gustó más

Cosas que salieron mal
No pude lograr el SQL
Horrible: me puse muy nervioso al momento de explicar el problema
Horrible: no sabía cómo poner los corchetes en mi propio teclado
No sabía que responder en qué conocía de Oracle y sus productos
No sabía que responder en qué conocía de la empresa
No sabía que responder en qué conocía de la vacante
No tuve una buena despedida
No sabía que preguntar en dudas para ellos
Me puse muy nervioso y desesperado cuando pasó lo de los corchetes y de ahí en adelante
estuve muy desesperado por esconderme o salir de la entrevista.
No hubo buen trato al final de la entrevista, no hice preguntas concretas y tampoco 
escuché lo que la entrevistadora me explicó al final
No escuché bien la pregunta de qué dificultades he enfrentado

Cosas que puedo mejorar
Conocer mi computadora antes de ponerme a programar
Saber cómo poner los símbolos antes de empezar a programar
Saber un poco más de estructuras de datos y cómo acceder a los elementos
leer todos los problemas antes de empezar a programar
Saber cómo hacer un query en SQL
saber qué programas tengo que generar para todas las actividades

Cosas que aprendí
Qué necesito controlarme cuando me pongo nervioso
Decir la verdad sobre el equipo que estoy usando
Ampliar más mi respuesta de qué dificultades he enfrentado
Escuchar bien las preguntas
Escuchar las instrucciones y sugerencias de la entrevistadora
Pensar en preguntas de cierre y dudas que tengo
Dejar que ellos cierren la entrevista

Mencioné bien el time complexity y space complexity
Mencioné bien el uso de mapas y vectores
Mencioné el espacio y lo que prefería hacer
Me faltó explicar la razón de usar un map
Me faltó explicar la importancia de la complejidad
Me faltó decir más de mi curriculum tecnico

*/

/*
Segunda ronda

Cosas que salieron bien:


Cosas que salieron mal:

Cosas que puedo mejorar:
Tener a la mano mi curriculum
Tener a la mano mi portafolio
Tener el deploy de los proyectos que he hecho
Saber los términos técnicos de mi carrera y de los proyectos que he hecho
Saber el road map de proyectos o apps que he hecho

Cosas que aprendí:

 */