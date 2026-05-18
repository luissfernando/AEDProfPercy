//1. Una lista ordenada (no repetitiva) de números enteros es una lista cuyo valor asociado a cada nodo aparece en orden.

//ejercicio a :: Una lista ordenada (no repetitiva) de números enteros es una lista 
//cuyo valor asociado a cada nodo aparece en orden.
void insert_ordered(int data){
    Node *nuevo = new Node(data);
    Node *current = head;
    while(current && data < current->data){
        current = current->next;
    nuevo->next = current;
    current = nuevo;
    }
}
// ejercicio c ::Escriba un algoritmo que, dadas dos listas ordenadas, devuelva una
//lista que contenga la unión de todos los elementos. ¿Cuál es la complejidad?
LinkedList* unionList(Node **head1, Node **head2){ // complejidad O(n+m)
    LinkedList *nuevo = new LinkedList();
    while(*(head1) && *(head2)){
        if(*(head1)->date > *(head2)->date){
            nuevo->push(*(head2)->date);
            *head2 = (*head2)->next;
        }
        else{
            nuevo->push(*(head1)->date);
            *head1 = (*head1)->next;
        }
    }
    while(*(head1)){
        nuevo->push(*(head1)->date);
        *head1 = (*head1)->next;
    }
    while(*(head2)){
        nuevo->push(*(head2)->date);
        *head2 = (*head2)->next;
    }
    return nuevo;
}

// ejercicio 3
//3. En un banco, solo hay un cajero y se atiende a todos por orden de llegada. 
// Sin embargo, las personas mayores tienen prioridad y pueden saltarse la fila. 
// Considerando que muchos días hay mucha gente mayor, se ha establecido la siguiente regla:

// a : Se atiende a una persona por orden de llegada.
// b : Pueden pasar un máximo de 2 personas mayores antes de una persona que no sea mayor.