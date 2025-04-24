#include "set.h"
//si ya esta en el conjunto
int contains(const Set *s, int value){
    for (int i = 0; i < s->size; ++i)
        if (s->datos[i] == value)
            return 1;
    return 0;
}

//inicializa 
void set_init(Set *s){
    s->size = 0;
}
//agrega al conjunto
int set_add(Set *s, int value){
    if (contains(s, value))   return 0;  //busca si ya existe
    s->datos[s->size++] = value;
    return 1;
}
// muestra el tamaño
int set_size(const Set *s){
    return s->size;
}
// union
void set_union(const Set *a, const Set *b, Set *result){
    set_init(result);
    for (int i = 0; i < a->size; ++i) set_add(result, a->datos[i]);
    for (int i = 0; i < b->size; ++i) set_add(result, b->datos[i]);
}
//interseccion
void set_intersection(const Set *a, const Set *b, Set *result){
    set_init(result);
    for (int i = 0; i < a->size; ++i)
        if (contains(b, a->datos[i]))
            set_add(result, a->datos[i]);
}
