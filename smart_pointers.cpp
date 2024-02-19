/*
    Ejemplo de Smart Pointer

    Registro: 23310166.
    Nombre: Galio Marcelo Gutiérrez Hernández.

    Mi definición:

    Pues un smart pointer a lo que vi es un versión más actualizada de los punteros. Su propósito es evitar el "memory leak" al
    destruir de forma automática nuestros punteros después de que su ciclo de vida de uso se haya completado. Esta automatización es últil
    para cuando el programa tiene distintas salidas, por que nos garantiza que la memoria utilizada será liberada. Además de que nos ahorra
    llamar a delete.

    Video que vi para entender mejor: https://www.youtube.com/watch?v=4f87Rtquj6M&ab_channel=Jos%C3%A9Tom%C3%A1sTocino

    También me gustaría agregar que existe tanto el unique_ptr como el shared_ptr, el unique_ptr es para cuando solo el puntero apunta 
    a un objeto, mientras que el shared_ptr es para cuando varios punteros apuntan a un miismo objeto. También en el video hablan del 
    make_shared que es una forma de crear un shared_ptr de forma más eficiente sin utilizar new ni delete.

*/


#include <iostream>
#include <memory> // Incluimos la librería <memory> para utilizar smart pointers

// Definimos una clase MyClass
class MyClass {
public:
    // Constructor que recibe un entero value
    MyClass(int value) : m_value(value) {
        // Imprimimos un mensaje indicando que se está llamando al constructor
        std::cout << "Constructor called with value: " << m_value << std::endl;
    }

    // Destructor
    ~MyClass() {
        // Imprimimos un mensaje indicando que se está llamando al destructor
        std::cout << "Destructor called for value: " << m_value << std::endl;
    }

    // Método para mostrar el valor almacenado
    void display() {
        std::cout << "Value: " << m_value << std::endl;
    }

private:
    int m_value; // Miembro privado que almacena el valor
};

int main() {
    // Usando unique_ptr
    // Creamos un unique_ptr apuntando a un objeto MyClass creado con new
    std::unique_ptr<MyClass> uniquePtr(new MyClass(42));
    // Llamamos al método display() del objeto apuntado por uniquePtr
    uniquePtr->display();

    // Usando shared_ptr
    // Creamos un shared_ptr usando make_shared, que crea el objeto y devuelve un shared_ptr a él
    std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>(10);
    // Creamos otro shared_ptr que apunta al mismo objeto que sharedPtr1
    std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1; // Incrementa el contador de referencia
    // Llamamos al método display() del objeto apuntado por sharedPtr1 y sharedPtr2
    sharedPtr1->display();
    sharedPtr2->display();

    // shared_ptr garantiza que la memoria sea liberada después de que ambos sharedPtr1 y sharedPtr2 se hayan quedado sin uso
    // Por lo que no hay necesidad de llamar a delete explícitamente

    return 0;
}
