/*=====[Module Name]===========================================================
 * Copyright 2019 Esteban Daniel VOLENTINI <evolentini@gmail.com>
 * All rights reserved.
 * License: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.1.0
 * Creation Date: 2019/03/01
 */

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef _ALUMNOS_H_
#define _ALUMNOS_H_

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdbool.h>
#include <stddef.h>

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/
//! Se define la estructura de datos de los alumnos
typedef struct alumno_s {   
    char apellidos[30];     //!< Apellidos de 30 caracteres
    char nombres[30];       //!< Nombres de 30 caracteres
    char documento[11];     //!< Documento de 11 caracteres
} const * alumno_t;

/*=====[Definitions of public global variables]==============================*/

/*=====[Prototypes (declarations) of public functions]=======================*/

/**
 * @brief Serializa los datos de UN alumno en una cadena JSON
 * 
 * Esta función se utiliza para convertir una estructura de datos en memoria
 * del tipo C  en una cadena de caracteres siguiendo el estandar JSON. Para ello
 * recibe un puntero
 * 
 * @param cadena :  puntero a cadena de caracteres para almacenamiento de datos impresos
 * @param espacio : tamaño de caracteres de la cadena a imprimir
 * @param alumno :  estructura que contiene el DNI , Apellido y Nombres
 * @return false :  devuelve falso si no hay nada que imprimir y
 *                  verdadero el tamaño de la cadena impresa
 */
bool SerializarAlumno(char * cadena, size_t espacio, const alumno_t alumno);

/**
 * @brief : Función que imprime en serie los datos de todos los alumnos 
 * 
 * Serializa en una cadena de caracteres los datos de todos los alumnos a traves
 * de la función SerializarAlumno al concatenar los datos de cada alumno dentro de la variable "cadena"
 * 
 * @param cadena :  variable de entrada donde se cargarán todos los caracteres que
 *                  serán los datos de los alumnos
 * @param espacio : tamaño de la cadena
 * @return true :   
 * @return false 
 */
bool SerializarAlumnos(char * cadena, size_t espacio);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* _ALUMNOS_H_ */
