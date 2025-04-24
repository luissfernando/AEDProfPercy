#ifndef SET_H
#define SET_H

typedef struct {
    int datos[100];      //conjunto de datos
    int size;         //tamaño
} Set;

//iniciaiza conjunto vacío
void set_init(Set *s);

//insertar valor si no existe devuelve 1 si lo añadió, 0 si ya estaba  
int  set_add(Set *s, int value);

//tamaño de elementos
int  set_size(const Set *s);

//union
void set_union(const Set *a, const Set *b, Set *result);

//interseccion
void set_intersection(const Set *a, const Set *b, Set *result);

#endif
