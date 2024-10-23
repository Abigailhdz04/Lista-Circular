#include <iostream>  
using namespace std;

class nodo {  // Define la clase "nodo" que representará cada nodo de la lista
public:
    int data;  // Almacena el valor (dato) del nodo
    nodo* next;  // Puntero al siguiente nodo en la lista circular

    nodo(int val) {  // Constructor del nodo, que asigna el valor recibido
        data = val;  // Inicializa el dato del nodo con el valor "val"
        next = nullptr;  // Inicializa el puntero "next" como nulo (aún no apunta a otro nodo)
    }
};

class CircularLinkedList {  // Define la clase "CircularLinkedList", que representará la lista circular
private:
    nodo* head;  // Puntero que siempre apunta al primer nodo de la lista (la cabeza)

public:
    CircularLinkedList() {  // Constructor de la lista
        head = nullptr;  // Inicializa la cabeza como nula (lista vacía)
    }

    // Método para agregar un nodo al inicio de la lista
    void agregar_inicio(int val) {
        nodo* nuevo_nodo = new nodo(val);  // Crea un nuevo nodo con el valor "val"
        if (head == nullptr) {  // Si la lista está vacía
            head = nuevo_nodo;  // El nuevo nodo se convierte en la cabeza
            head->next = head;  // El puntero "next" del nodo apunta a sí mismo, formando el ciclo
        } else {
            nodo* temp = head;  // "temp" se usa para recorrer la lista
            while (temp->next != head) {  // Recorre la lista hasta encontrar el último nodo
                temp = temp->next;
            }
            nuevo_nodo->next = head;  // El nuevo nodo apunta a la cabeza actual
            temp->next = nuevo_nodo;  // El último nodo ahora apunta al nuevo nodo
            head = nuevo_nodo;  // El nuevo nodo se convierte en la nueva cabeza de la lista
        }
    }

    // Método para agregar un nodo al final de la lista
    void agregar_final(int val) {
        nodo* nuevo_nodo = new nodo(val);  // Crea un nuevo nodo con el valor "val"
        if (head == nullptr) {  // Si la lista está vacía
            head = nuevo_nodo;  // El nuevo nodo se convierte en la cabeza
            head->next = head;  // El puntero "next" del nodo apunta a sí mismo
        } else {
            nodo* temp = head;  // "temp" se usa para recorrer la lista
            while (temp->next != head) {  // Recorre la lista hasta el último nodo
                temp = temp->next;
            }
            temp->next = nuevo_nodo;  // El último nodo apunta al nuevo nodo
            nuevo_nodo->next = head;  // El nuevo nodo apunta a la cabeza, completando el ciclo
        }
    }

    // Método para agregar un nodo en una posición intermedia
    void agregar_medio(int val, int posicion) {
        if (posicion == 0) {  // Si la posición es 0, es equivalente a agregar al inicio
            agregar_inicio(val);  // Llama al método para agregar al inicio
            return;  // Termina la ejecución del método
        }

        nodo* nuevo_nodo = new nodo(val);  // Crea un nuevo nodo con el valor "val"
        nodo* temp = head;  // "temp" se usa para recorrer la lista
        int contador = 0;

        // Recorre la lista hasta encontrar la posición adecuada
        while (contador < posicion - 1 && temp->next != head) {
            temp = temp->next;
            contador++;
        }

        nuevo_nodo->next = temp->next;  // El nuevo nodo apunta al siguiente nodo en la lista
        temp->next = nuevo_nodo;  // El nodo actual apunta al nuevo nodo
    }

    // Método para imprimir todos los nodos de la lista
    void imprimir_lista() {
        if (head == nullptr) {  // Si la lista está vacía
            cout << "La lista está vacía" << endl;
            return;  // Termina el método
        }

        nodo* temp = head;  // "temp" se usa para recorrer la lista
        do {
            cout << temp->data << " -> ";  // Imprime el dato del nodo actual
            temp = temp->next;  // Avanza al siguiente nodo
        } while (temp != head);  // Continúa hasta volver a la cabeza

        cout << "(cabeza)" << endl;  // Indica que el ciclo vuelve a la cabeza
    }
};

int main() {
    CircularLinkedList lista;  // Crea una lista circular vacía

    // Inserta los elementos en la lista
    lista.agregar_inicio(10);  // Inserta el nodo con valor 10 al inicio
    lista.agregar_final(20);  // Inserta el nodo con valor 20 al final
    lista.agregar_medio(15, 1);  // Inserta el nodo con valor 15 en la posición 1 (medio)

    // Imprime la lista completa
    lista.imprimir_lista();  // Debería mostrar: 10 -> 15 -> 20 -> (cabeza)

    return 0;
}
