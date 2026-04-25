#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

struct estudianteS{
    char nombre;
    char apellidoPa;
    char apellidoMa;
    int codigoEstudiante;
};

void ingresoExamen(int);
void validarDatos();
void menuPrincipal(int);
void preguntas();
void verPreguntas();
void verUsuarios();

// MENU DE SALIDA
void menuSalida(int opcion)
{
    int opcionMenu;
    //system("cls");
    cout<< "\n --- ¿Que desea hacer? ---\n\n"
        << "1. Volver al menu principal \n"
        << "2. Salir \n";
    cin>> opcionMenu;
    if(opcionMenu==1)
    {
        menuPrincipal(opcion);
    }
    else if(opcionMenu==2)
    {
        cout<< "ESTA OPCION DEBERIA CERRAR LA CONSOLA";
    }
}

// MENU PRINCIPAL
void menuPrincipal(int opcion)
{
    int opcionMenu;
    system("cls");
    cout
        << "\n\n************************** \n"
        << "-------------------------- \n"
        << " Ingrese una opción. \n"
        << "-------------------------- \n"
        << "**************************. \n\n"
        << "1. Empezar examen\n"
        << "2. Ver notas\n"
        << "3. Ver preguntas\n"
        << "4. Ver lista de estudiantes\n"
        << "5. SALIR DEL EXAMEN\n";
    cin>>opcion;

    switch(opcion)
    {
    case 1:
        ingresoExamen(0);  // se pasa un valor dummy (el parámetro no se usa)
        break;
    case 2:
        system("cls");
        cout<< " \nNotas de los estudiantes\n\n ";
        menuSalida(opcion);
        break;
    case 3:
        cout<< "\nPreguntas del examen";
        verPreguntas();
        menuSalida(opcion);
        break;
    case 4:
        cout<< "\nUsuarios registrados:"<<endl;
        verUsuarios();
        menuSalida(opcion);
        break;
    case 5:
        cout<< "\n Gracias Por Visitar";
        break;
    }
}

// MENU DEL ESTUDIANTE ANTES DE DAR EL EXAMEN
void ingresoExamen(int opcion)
{
    int opcionMenu;
    system("cls");
    cout
        << "__________________________ \n"
        << "************************** \n\n"
        << "Ingrese una opcion \n\n"
        << "************************** \n"
        << "¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨ \n\n"
        << "1. Ingresar al sistema para empezar examen \n"
        << "2. Ver nota \n"
        << "3. Volver al menu anterior \n";
    cin>>opcion;

    switch(opcion)
    {
    case 1:
        validarDatos();
        break;
    case 2:
        cout<< "\n Notas del examen \n";
        break;
    case 3:
        menuPrincipal(0);  // valor dummy
    }
}

// INGRESO AL SISTEMA DE EXAMENES
void validarDatos()
{
    string valUsuario="admin", valContrasena="1234";
    string usuario, contrasena;
    int opcionMenu;
    bool ingreso=false;

    do
    {
        system("cls");
        cout<< "\n\n----- Ingrese sus datos -----"<<endl;
        cout<< "Usuario: ";
        cin>> usuario;
        cout<< "Contrasenia: ";
        cin>> contrasena;
        if(usuario==valUsuario && contrasena==valContrasena)
        {
            ingreso=true;
        }
        else
        {
            cout<< "\n------Los datos ingresados no son correctos ---------";
        }
    } while(ingreso==false);

    if(ingreso==false)   // corregido: antes era ingreso=false
    {
        cout<< "\nNo se pudede ingresar al examen";
    }
    else
    {
        cout<< "\n||| Ahora puede empezar su examen |||\n"
            << "\n||| La nota total es de 100 puntos |||\n"
            << "\n||| Cada pregunta tiene un valor de 10 puntos |||\n\n";
        preguntas();
    }
}

void verPreguntas()
{
    ifstream archivoPreguntas("preguntas.txt");
    string pregunta;
    while(getline(archivoPreguntas, pregunta))
    {
        cout<< pregunta<<endl;
    }
}

void preguntas()
{
    int opcionMenu;
    int respuesta[10];
    verPreguntas();

    for(int i=0; i<10; i++)
    {
        cout<< "Respuesta a la pregunta "<< i+1<<" ---> ";
        cin>> respuesta[i];
    }

    // VERIFICAR RESPUESTAS
    int respuestaCorrecta[10];
    fstream archivoRespuestas;
    archivoRespuestas.open("respuestas.txt", ios::in);

    // Leer exactamente 10 respuestas correctas
    for(int i=0; i<10; i++)
    {
        archivoRespuestas>> respuestaCorrecta[i];
    }

    for(int i=0; i<10; i++)
    {
        cout<< "Respuesta correcta a la pregunta "<< i+1 <<" ---> "<< respuestaCorrecta[i]<<endl;
    }

    // NOTA FINAL
    int notaFinal=0;
    int nota[10];
    for(int i=0; i<10; i++)
    {
        if(respuesta[i]==respuestaCorrecta[i])
        {
            nota[i]=1;
        }
        else
        {
            nota[i]=0;
        }
    }

    for(int i=0; i<10; i++)
    {
        cout<< nota[i]<<endl;
        notaFinal= notaFinal+nota[i];
    }
    cout<< "SU NOTA FINAL ES: "<< notaFinal*10 << " PUNTOS";
    menuSalida(0);   // valor dummy
}

void verUsuarios()
{
    ifstream archivoUsuarios("usuarios.txt");
    string usuario;
    while(getline(archivoUsuarios, usuario))
    {
        cout<< usuario<<endl;
    }
}

int main()
{
    int opcionMenu = 0;   // inicializado
    menuPrincipal(opcionMenu);
    return 0;
}