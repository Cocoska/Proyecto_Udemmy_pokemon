
#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

class pokemon
{
    char nombre[15];
    double ataque;
    int salud;
    char color[15];
    int respiracion;

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

    int getRespiracion() { return respiracion; }
    void setRespiracion(int r) { respiracion = r; }

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

    int bajoAgua(bool i)
    {
        bool inmune = i;
        if (inmune = false)
        {
            for (int i=0; i < 100; i++)
            {
                respiracion++;
               // delay(1000);
            }
            if (respiracion = 0)
            {
                salud = 0;
            }
        }
        else
        {
            respiracion = 0;
        }
    }
};


class pokeAgua : public pokemon
{
    char tipo[15];
    int resp = 0;
    bool inmune = true;
    
};

class pokeFuego : public pokemon
{
    char tipo[15];
    bool modoAtk = false;
    int temperatura;

};

class pokeTierra : public pokemon
{
    int profundidad;

public:

    void cavar(bool cvr, int dis_bajo)
    {
        int head;
        head = getSalud();
        if (cvr = true && dis_bajo > profundidad)
        {
            head = head - (dis_bajo - profundidad);
        }
        setSalud(head);
    }

};

class bolaFuego : public pokeFuego
{
    int temperatura;
    int atk;
    double danoFuego;
public:
    void ataqueFuego(int t)
    {
        t = temperatura;
        atk = getAtaque();
        danoFuego = atk + (t * 0.20);
    }
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