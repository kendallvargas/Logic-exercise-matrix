#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void menu();
vector<string> asignarEscolaridad(int escolaridad);
vector<string> asignarMeses(int cantidadMeses);
int generarNumeroInversiones();
int generarNumeroInversionistas();
void mostrarMatriz(int cantidadEscolaridad, int cantidadMeses);
void menuOpciones();
void clearScreen();
void presentarDatosInvEscola();
void presentarDatosInvMeses();
void encabezadoEscolaridad();
void encabezadoMeses();

// Global variables

bool generado=false;
int matrizInversiones[7][12];
int matrizInversionistas[7][12];
int cantidadEscolaridad = 0, cantidadMeses = 0;
int menuOption = 0;

vector<string> meses;
vector<string> esco;

int main()
{

    system("title Logic Exercise - Kendall Vargas");

    // Use current time as seed for random generator
    srand(time(0));

    menu();
    do
    {
    menuOpciones();
    
    switch (menuOption)
    {
    case 1:
        mostrarMatriz(cantidadEscolaridad, cantidadMeses);   
        system("pause");     
        break;
    case 2:
        presentarDatosInvEscola();
        system("pause");
        break;
    case 3:
        presentarDatosInvMeses();
        system("pause");
        break;
    case 4:
        cout << "Saliendo del sistema, hasta luego!";
        break;
    default:
        cout << "Opcion invalida!\n";
        system("pause");
        break;
    }
    } while (menuOption != 4);
    
    return 0;
}

void menu()
{
    cout << "Digite la cantidad de tipos de escolaridad que se van a procesar(1-7): ";
    cin >> cantidadEscolaridad;
    while (cantidadEscolaridad < 0 || cantidadEscolaridad > 7)
    {
        cout << "Incorrecto, numero debe de estar entre 1 y 7: ";
        cin >> cantidadEscolaridad; 
    }
    
    cout << "Digite la cantidad de meses que se van a procesar(1-12): ";
    cin >> cantidadMeses;
    while (cantidadMeses < 0 || cantidadMeses > 12)
    {
        cout << "Incorrecto, numero debe de estar entre 1 y 12: ";
        cin >> cantidadMeses; 
    }
    asignarEscolaridad(cantidadEscolaridad);
    asignarMeses(cantidadMeses);
}

void menuOpciones()
{
    clearScreen();

    cout << "1. Inicializar las matrices\n";
    cout << "2. Presentar datos de inversiones por escolaridad\n";
    cout << "3. Presentar datos de inversiones por meses procesados\n";
    cout << "4. Finalizar\n";

    cin >> menuOption;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

vector<string> asignarEscolaridad(int cantidadEscolaridad)
{
    const string escolaridad[] = {
        "Primaria  ",
        "Secundaria",
        "Tecnico   ",
        "Bachi Uni ",
        "Licenciado",
        "Maestria  ",
        "Doctorado "};

    // vector para guardar la escolaridad
    vector<string> escolaridadSeleccionada;

    for (int i = 0; i < cantidadEscolaridad; i++)
    {
        // guardar el array de escolaridades al vector en base a la cantidad indicada del usuario
        escolaridadSeleccionada.push_back(escolaridad[i]);
    }

    return escolaridadSeleccionada;
}

vector<string> asignarMeses(int cantidadMeses)
{
    const string meses[] = {
        "Enero     ", "Febrero   ", "Marzo     ", "Abril     ", "Mayo      ", "Junio     ",
        "Julio     ", "Agosto    ", "Septiembre", "Octubre   ", "Noviembre ", "Diciembre "};

    vector<string> mesesSeleccionados; // Create a vector to store selected months

    for (int i = 0; i < cantidadMeses; i++)
    {
        // guardar el array de meses al vector en base a la seleccion del usuario
        mesesSeleccionados.push_back(meses[i]); 
    }

    return mesesSeleccionados;
}

void mostrarMatriz(int cantidadEscolaridad, int cantidadMeses)
{
    if (generado == false)
    {
        // generar la matriz de inversiones
        for (int i = 0; i < cantidadEscolaridad; i++)
        {
            for (int j = 0; j < cantidadMeses; j++)
            {
                matrizInversiones[i][j] = generarNumeroInversiones();
                generado = true;
            }
        }

        // generar matriz de inversionistas
        for (int i = 0; i < cantidadEscolaridad; i++)
        {
            for (int j = 0; j < cantidadMeses; j++)
            {
                matrizInversionistas[i][j] = generarNumeroInversionistas();
                generado = true;
            }
        }
    }

    meses = asignarMeses(cantidadMeses);
    esco = asignarEscolaridad(cantidadEscolaridad);

    // mostrar matriz de inversiones

    cout << "              Matriz de inversiones acumuladas\n";
    // encabezado de meses
    cout << "             ";
    for (int i = 0; i < cantidadMeses; i++)
    {
        cout << meses[i] << " "; // Print the month name
    }
    cout << "\n";

    // encabezado de escolaridad
    for (int i = 0; i < cantidadEscolaridad; i++)
    {
        cout << esco[i] << "    "; // Print the month name
        for (int j = 0; j < cantidadMeses; j++)
        {
            cout << setfill(' ') << setw(3) << matrizInversiones[i][j] << "        ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "              Matriz de Inversionistas\n";
    // encabezado de meses
    cout << "             ";
    for (int i = 0; i < cantidadMeses; i++)
    {
        cout << meses[i] << " "; // Print the month name
    }
    cout << "\n";

    // encabezado de escolaridad y mostrar la matriz de inversionistas
    for (int i = 0; i < cantidadEscolaridad; i++)
    {
        cout << esco[i] << "    "; // Print the month name
        for (int j = 0; j < cantidadMeses; j++)
        {
            cout << setfill(' ') << setw(3) << matrizInversionistas[i][j] << "        ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "Matrices fueron generadas correctamente!\n";
}

void presentarDatosInvEscola()
{
    vector<int> resultadoEscolaridad; vector<int> resultadoInversionistas; vector<float> resultadoPromedio;
    int suma = 0, sumaInver = 0;
    float promedio = 0;

    if (generado == false)
    {
        cout << "No se puede acceder a esta opcion sin haber ingresado a la opcion 1!\n\n";
    }
    else
    {
        mostrarMatriz(cantidadEscolaridad, cantidadMeses);

        cout << "\n\n";

        encabezadoEscolaridad();

        // guardar la suma del total de inversiones y de inversionistas de la columna 1 fila 1 en la suma y guardarlo en el vector
        for (int i = 0; i < cantidadEscolaridad; i++)
        {
            for (int j = 0; j < cantidadMeses; j++)
            {
                suma += matrizInversiones[i][j];
                sumaInver += matrizInversionistas[i][j];
               
            }
            resultadoEscolaridad.push_back(suma);
            resultadoInversionistas.push_back(sumaInver);
            // reiniciar para guardar la linea i j nueva
            suma = 0;
            sumaInver = 0;
        }

        for (int i = 0; i < cantidadEscolaridad; i++)
        {
            promedio = static_cast<double>(resultadoEscolaridad[i]) / resultadoInversionistas[i];
            resultadoPromedio.push_back(promedio);
        }
        

        for (int i = 0; i < cantidadEscolaridad; i++)
        {
            // mostrar los resultados del reporte de inversiones acumuladas por escolaridad
            cout << right << esco[i] << setw(18)<< setfill(' ') << resultadoEscolaridad[i] << setw(23)<< setfill(' ') 
            <<resultadoInversionistas[i] << setw(27)<< setfill(' ') << resultadoPromedio[i]<< endl;
        }
    }
}

void presentarDatosInvMeses()
{
    vector<int> resultadoEscolaridadMes; vector<int> resultadoInversionistasMes; vector<float> resultadoPromedioMes;
    int suma = 0, sumaInver = 0;
    float promedio = 0;

    if (generado == false)
    {
        cout << "No se puede acceder a esta opcion sin haber ingresado a la opcion 1!\n\n";
    }
    else
    {
        mostrarMatriz(cantidadEscolaridad, cantidadMeses);

        cout << "\n\n";

        encabezadoMeses();

        // guardar la suma del total de inversiones y de inversionistas de la columna 1 fila 1 en la suma y guardarlo en el vector
        for (int j = 0; j < cantidadMeses; j++)
        {
            for (int i = 0; i < cantidadEscolaridad; i++)
            {
                suma += matrizInversiones[i][j];
                sumaInver += matrizInversionistas[i][j];
               
            }
            resultadoEscolaridadMes.push_back(suma);
            resultadoInversionistasMes.push_back(sumaInver);
            // reiniciar para guardar la linea i j nueva
            suma = 0;
            sumaInver = 0;
        }

        for (int i = 0; i < cantidadMeses; i++)
        {
            promedio = static_cast<double>(resultadoEscolaridadMes[i]) / resultadoInversionistasMes[i];
            resultadoPromedioMes.push_back(promedio);
        }
        

        for (int i = 0; i < cantidadMeses; i++)
        {
            // mostrar los resultados del reporte de inversiones acumuladas por escolaridad
            cout << right << meses[i] << setw(18)<< setfill(' ') << resultadoEscolaridadMes[i] << setw(23)<< setfill(' ') 
            <<resultadoInversionistasMes[i] << setw(30)<< setfill(' ') << resultadoPromedioMes[i]<< endl;
        }
    }
}

void encabezadoEscolaridad()
{
    cout << "********************************************************\n";
    cout << "          Inversiones totales Kendall Vargas\n";
    cout << "   Reporte de Inversiones Acumuladas por Escolaridad\n";
    cout << "********************************************************\n";
    cout << "Escolaridad        Monto Inversiones       Cant Inversionistas         Promedio\n";
}

void encabezadoMeses()
{
    cout << "********************************************************\n";
    cout << "          Inversiones totales Kendall Vargas\n";
    cout << "   Reporte de Inversiones Acumuladas por Mes Procesado\n";
    cout << "********************************************************\n";
    cout << "Mes Procesado        Monto Inversiones       Cant Inversionistas         Promedio\n";
}

int generarNumeroInversiones()
{
    int randomNum = 1 + (rand() % 800); // Generar un numero entre 1 y 800
    return randomNum;
}

int generarNumeroInversionistas()
{
    int randomNum = 1 + (rand() % 30); // Generar un numero entre 1 y 30
    return randomNum;
}


// Limpiar pantalla
void clearScreen()
{
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux or Mac
#endif
}