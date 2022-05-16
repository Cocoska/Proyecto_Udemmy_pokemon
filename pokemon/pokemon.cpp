
#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

class pokemon
{
protected: 

    char nombre[15];
    double ataque;
    int salud;
    char color[15];

public:

    pokemon(char n[15], double a, int s, char c[15])
    {
        strcpy_s(nombre, n);
        ataque = a;
        salud = s;
        strcpy_s(color, c);
    }

    ~pokemon() { cout << "pokemon liberado" << endl; }

    char* getNombre() { return nombre; }
    void setNombre(char name[15]) { strcpy_s(nombre, name); }

    int getAtaque() { return ataque; }
    void setAtaque(double a) { ataque = a; }

    int getSalud() { return salud; }
    void setSalud(int s) { salud = s; }

    char* getColor() { return color; }
    void setColor(char col[15]) { strcpy_s(color, col); }

    void saludo() { cout << "Soy " << nombre << ", y estoy listo para luchar" << endl; }

    void dano()
    {
        salud = salud - ataque;
    }

    void sanar()
    {
        if (salud < 100)
        {
            salud = 100;
            cout << "Pokemon curado" << endl;
        }
        else 
        {
            cout << "Pokemon con salud llena" << endl;
        }
    }

    void evolucion(char newName[15], char newColor[15])
    {
        strcpy_s(nombre, newName);
        strcpy_s(color, newColor);
        ataque = ataque + (ataque * 0.20);
    }

    void datos_pokemon()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Ataque: " << ataque << endl;
        cout << "Salud: " << salud << endl;
        cout << "Color: " << color << endl;
    }
};


class pokeAgua : public pokemon
{
    int bonoAgua;
    int debugAgua;
    
public: 

    int getBonoAgua() { return bonoAgua; }
    void setBonoAgua(int bono) { bonoAgua = bono; }

    void aumentoAtaque() { ataque = ataque + (bonoAgua * 0.1); }
    void disminuirAtaque() { ataque = ataque - (debugAgua * 0.1); }
};

class pokeFuego : public pokemon
{
    int bonoFuego;
    int debugFuego;
    float espFuego;

public: 

    int getBonoFuego() { return bonoFuego; }
    void setBonoFuego(int bono) { bonoFuego = bono; }

    void aumentoAtaque() { ataque = ataque + (bonoFuego * 0.1); }
    void disminuirAtaque() { ataque = ataque - (debugFuego * 0.1); }
};

class pokeTierra : public pokemon
{
    int bonoTierra;
    int debugTierra;

public:

    int getBonoTierra() { return bonoTierra; }
    void setBonoTierra(int bono) { bonoTierra = bono; }

    void aumentoAtaque() { ataque = ataque + (bonoTierra * 0.1); }
    void disminuirAtaque() { ataque = ataque - (debugTierra * 0.1); }
};



int main()
{
    char nom_poke[15], col_poke[15], nnom_poke[15], ncol_poke[15], nom_poke2[15], col_poke2[15];
    strcpy_s(nom_poke, "pikachu");
    strcpy_s(col_poke, "amarillo");
    pokemon Pokemon1(nom_poke, 40, 100, col_poke); 

    strcpy_s(nom_poke2, "mew");
    strcpy_s(col_poke2, "mewtwo");

    pokemon* Pokemon2 = new pokemon(nom_poke2, 60, 100, col_poke2);

    Pokemon1.datos_pokemon();

    Pokemon1.dano();

    Pokemon1.datos_pokemon();

    Pokemon1.sanar();

    delete Pokemon2;

    Pokemon1.datos_pokemon();

    strcpy_s(nnom_poke, "raichu");
    strcpy_s(ncol_poke, "naranja");
    Pokemon1.evolucion(nnom_poke, ncol_poke);

    Pokemon1.datos_pokemon();
}