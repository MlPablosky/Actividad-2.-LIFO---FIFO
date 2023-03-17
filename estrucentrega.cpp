#include <iostream>
#include <string>
//Pablo Murillo Lemus, Yeison Stiven Lozano, Luis Adrian Caicedo.
using namespace std;

struct Atleta {
    string nombre;
    double tiempo1;
    double tiempo2;
    Atleta* next;
};

void RegistrArtleta(Atleta** head) {
    Atleta* nuevoAtleta = new Atleta;

    cout << "Ingrese el nombre del atleta: ";
    cin >> nuevoAtleta->nombre;

    cout << "Ingrese el tiempo 1 para el atleta: ";
    cin >> nuevoAtleta->tiempo1;

    cout << "Ingrese el tiempo 2 para el atleta: ";
    cin >> nuevoAtleta->tiempo2;

    nuevoAtleta->next = *head;
    *head = nuevoAtleta;

    system("cls");
}

void MostrarAtletas(Atleta* head) {
    cout << endl << "Los datos de los atletas son:" << endl;
    while (head != NULL) {
        cout << head->nombre << ": " << head->tiempo1 << ", " << head->tiempo2 << endl;
        head = head->next;
    }
}

void CalcularPromedio(Atleta* head) {
    int count = 0;
    double tiempoTotal = 0;

    while (head != NULL) {
        tiempoTotal += head->tiempo1 + head->tiempo2;
        count++;
        head = head->next;
    }

    double promedio = tiempoTotal / (count * 2);
    cout << endl << "El promedio de los tiempos es: " << promedio << endl;
}

int main() {
    Atleta* head = NULL;
    int choice;

    do {
        cout << endl <<"---MENU DE REGISTRO DE ATLETAS---" << endl;
        cout << "1. Agregar atleta" << endl;
        cout << "2. Mostrar atletas" << endl;
        cout << "3. Salir" << endl;
        cout << "4. Calcular promedio de tiempos" << endl;
        cout << "Seleccione una opcion: ";
        cin >> choice;

        switch (choice) {
            case 1:
                RegistrArtleta(&head);
                break;
            case 2:
                MostrarAtletas(head);
                break;
            case 3:
                while (head != NULL) {
                    Atleta* current = head;
                    head = head->next;
                    delete current;
                }
                break;
            case 4:
                CalcularPromedio(head);
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}