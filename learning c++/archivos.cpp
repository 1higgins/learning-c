//ARCHIVOS C++

#include <iostream>
#include <fstream> //usada para trabajar con archivos o ficheros
#include <cstring>
#include <string>
#include <vector>

/*
struct PlayerData {
    int id;
    char name[32];
    float health;
    int level;
    double positionX;
    double positionY;
};

int main() {
    std::string filename = "savegame.dat";

    // ESCRITURA BINARIA CON .write()
    
    // Creamos los datos del jugador en la RAM
    PlayerData playerToWrite;
    playerToWrite.id = 777;
    std::strcpy(playerToWrite.name, "Aragorn_C++");
    playerToWrite.health = 94.5f;
    playerToWrite.level = 42;
    playerToWrite.positionX = 1540.25;
    playerToWrite.positionY = -850.12;

    // Abrimos el archivo en modo salida (out) y binario (binary)
    std::ofstream outFile(filename, std::ios::binary);

    if (outFile.is_open()) {
 
        // Explicación del write:
        // &playerToWrite -> Dirección en RAM de nuestra estructura.
        // reinterpret_cast<const char*> -> Convierte esa dirección a un puntero de bytes crudos.
        // sizeof(PlayerData) -> Le dice a C++ cuántos bytes medir y copiar en total.
 
        outFile.write(reinterpret_cast<const char*>(&playerToWrite), sizeof(PlayerData));
        
        outFile.close();
        std::cout << "¡Partida guardada exitosamente en " << filename << "!\n\n";
    } else {
        std::cerr << "Error al abrir el archivo para guardar.\n";
        return 1;
    }

    // 2. LECTURA BINARIA CON .read()
    
    // Creamos una estructura vacía en la RAM lista para recibir los datos
    PlayerData playerToRead;

    // Abrimos el archivo en modo entrada (in) y binario (binary)
    std::ifstream inFile(filename, std::ios::binary);

    if (inFile.is_open()) {
        // Explicación del read:
        // Toma los bytes del disco y los vuelca directamente en la dirección de memoria de 'playerToRead'
        inFile.read(reinterpret_cast<char*>(&playerToRead), sizeof(PlayerData));
        
        inFile.close();
        
        // Ahora los datos binarios vuelven a ser variables utilizables en C++
        std::cout << "--- PARTIDA CARGADA DESDE DISCO ---\n";
        std::cout << "ID del Jugador: " << playerToRead.id << "\n";
        std::cout << "Nombre        : " << playerToRead.name << "\n";
        std::cout << "Vida (Health) : " << playerToRead.health << "%\n";
        std::cout << "Nivel         : " << playerToRead.level << "\n";
        std::cout << "Coordenadas   : (" << playerToRead.positionX << ", " << playerToRead.positionY << ")\n";
    } else {
        std::cerr << "Error al abrir el archivo para cargar.\n";
        return 1;
    }

    return 0;
}



int main() {
    std::string nombre;
    const std::string ADIVINA = "Isabel";
    
    do {
        std::cout<<"Adivina el nombre de la persona que trae loco a Matias! (FIN para cerrar el programa)"<<std::endl;
        std::cin>>nombre;
    } while (nombre != ADIVINA && nombre != "FIN");
    
    if (nombre == ADIVINA) {
        std::cout<<"Correcto, Matias esta loco por: " <<ADIVINA<<std::endl;
        std::cout<<"uwu :,3"<<std::endl;

    }
    else {
        std::cout<<"Casi pero Matias solo se derrite por Isabel :D"<<std::endl;
    }
    return 0;
}


struct gameUser {
    int hearts;
    char name[30];
    int level;
};

 
int main() {
    
    gameUser playerToWrite;
    std::strcpy(playerToWrite.name, "Higginson");
    playerToWrite.hearts = 10;
    playerToWrite.level = 15;
    
    std::ofstream outFile("datagame.txt");
    
    if (!outFile) {
        std::cerr<<"Hubo un problema al abrir el archivo.\n";
        return 1;
    }
    
    outFile << playerToWrite.hearts << "\n";
    outFile << playerToWrite.name << "\n";
    outFile << playerToWrite.level << "\n";

    outFile.close();
    std::cout <<"[Exito]: Partida guardada correctamente!"<<std::endl;
    
    
    
    //cargar datos input
    
    gameUser playerToRead;
    
    std::ifstream inFile("datagame.txt");
    
    if (inFile.fail()) {
        std::cerr<<"Error al intentar cargar los archivos, o no existe."<<std::endl;
    }
    
    inFile >> playerToRead.hearts;
    inFile >> playerToRead.name;
    inFile >> playerToRead.level;
    
    inFile.close();
    std::cout<<"\n";
    std::cout <<"---- DATOS CARGADOS DE LOS ARCHIVOS ----"<<std::endl;
    std::cout <<"Nombre del jugador: " <<playerToRead.name<< "\n";
    std::cout <<"La vida del jugador es: " <<playerToRead.hearts<< "\n";
    std::cout <<"El nivel de " <<playerToRead.name << " es: " <<playerToRead.level<< "\n";
    
    return 0;
}
 
*/


int main() {
    
    std::string students[] {"Higginson", "Ruel", "Fabrizio", "Cole Palmer", "Bellingham"};
    int age[] {19, 23, 14, 21, 26};
    int studentCount = 5;
    
    std::fstream writeFile;
    writeFile.open("users.txt", std::ios::out);
    
    if (writeFile.is_open()) {
        for (int i = 0; i < studentCount; i++) {
            writeFile << students[i] << "," << age[i] <<std::endl;
        }
        std::cout <<"Users saves succesfully!\n" <<std::endl;
    }
    writeFile.close();
    
    //lectura de archivos, eliminando lo de arriba para que funcione
    //En C++ no se puede tener dos variables llamadas exactamente igual en el mismo bloque aunque sean fstream o ifstream
    std::ifstream readFile("users.txt", std::ios::in);
    
    if (readFile.is_open()) {
        std::string line;
        
        while (getline(readFile, line)) {
            std::cout << line <<std::endl;
        }
    }
}



