#include <stdio.h>
#include "set.h"
//imprime los conjuntos 
void print_set(char *name, const Set *s){
    printf("%s (size=%d): {", name, set_size(s));
    for (int i = 0; i < set_size(s); ++i)
        printf(i ? " %d" : "%d", s->datos[i]);
    puts(" }");
}

int main(void)
{
    Set A, B, U, I;
    set_init(&A);
    set_init(&B);

    set_add(&A, 1); set_add(&A, 2); set_add(&A, 3);
    set_add(&B, 3); set_add(&B, 4);

    set_union(&A, &B, &U);
    set_intersection(&A, &B, &I);

    print_set("A", &A);
    print_set("B", &B);
    print_set("A ∪ B", &U);
    print_set("A ∩ B", &I);

    return 0;
}
