/*=====[Module Name]===========================================================
 * Copyright 2019 Esteban Daniel VOLENTINI <evolentini@gmail.com>
 * All rights reserved.
 * License: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.1.0
 * Creation Date: 2019/03/01
 */
 
/*=====[Inclusion of own header]=============================================*/

#include "alumnos.h"
#include <stdio.h>
#include <string.h>

/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

/**
 * @brief Se cargan los datos para la estructura de NOMBRE_APELLIDO del 
 * alumno ESTEBAN_VOLENTINI
 * 
 */
static const struct alumno_s ESTEBAN_VOLENTINI = {
    .apellidos = "VOLENTINI",
    .nombres = "Esteban Daniel",
    .documento = "23.517.968",
};
/**
 * @brief Se cargan los datos para la estructura de NOMBRE_APELLIDO del 
 * alumno CARLOS_HERRERA
 * 
 */
static const struct alumno_s CARLOS_HERRERA = {
    .apellidos = "HERRERA",
    .nombres = "Carlos Silvestre",
    .documento = "44576112",
};

/**
 * @brief Lista de alumnos de tipo de variable alumno_t
 * 
 */
const alumno_t ALUMNOS[] = {    //
    &ESTEBAN_VOLENTINI,
    &CARLOS_HERRERA,
};

const int CANTIDAD_ALUMNOS = (sizeof(ALUMNOS) / sizeof(alumno_t)); //!< Cantidad de alumnos

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

/*=====[Implementations of interrupt functions]==============================*/

bool SerializarAlumno(char * cadena, size_t espacio, const alumno_t alumno) {
    int resultado;
    const char FORMATO[] = "{"
        "\"documento\":\"%s\","
        "\"apellidos\":\"%s\","
        "\"nombres\":\"%s\""
    "}";

    resultado = snprintf(cadena, espacio, FORMATO, 
             alumno->documento, alumno->apellidos, alumno->nombres);

    return (resultado >= 0);
}

bool SerializarAlumnos(char * cadena, size_t espacio) {
    static const int  cantidad = sizeof(ALUMNOS) / sizeof(alumno_t);    //!< cantidad de lista de alumnos
    int posicion = snprintf(cadena, espacio, "[\r\n  ");
    bool resultado = (posicion > 0);    //!< verifica que la cadena tenga espcio para cargar texto

    if (resultado){
        for(int indice = 0; indice < cantidad; indice++ ) {
            resultado = SerializarAlumno(&cadena[posicion], espacio - posicion, ALUMNOS[indice]);   //!< primera contactenación
            if (resultado) {
                posicion += strlen(&cadena[posicion]);                                              //!< establece posición para el siguiente alumno
                posicion += snprintf(&cadena[posicion], espacio - posicion, ",\r\n  ");             // siguiente concatenación de datos de alumno
            } else {
                break;
            }
        }
    }

    snprintf(&cadena[posicion] - 5, espacio - posicion + 5, "\r\n]");   //!< se imprime el cierre del mensaje 
    return resultado;
}

/*=====[Implementations of private functions]================================*/
