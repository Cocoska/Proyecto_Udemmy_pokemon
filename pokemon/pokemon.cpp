
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

    pokemon()
    {
        strcpy_s(nombre, "Anonimo");
        ataque = 1;
        salud = 100;
        strcpy_s(color, "SIn color");
    }

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
    char nombreAtaque[20];
    
public: 

    pokeAgua(int ba, int da): pokemon()
    {
        bonoAgua = ba;
        debugAgua = da;
        strcpy_s(nombreAtaque, "Chorro de agua");
    }

    pokeAgua(int bf, int df, char n[15], double a, int s, char c[15])
    {
        bonoAgua = bf;
        debugAgua = df;
        strcpy_s(nombre, n);
        ataque = a;
        salud = s;
        strcpy_s(color, c);
        strcpy_s(nombreAtaque, "Chorro de agua");
    }

    int getBonoAgua() { return bonoAgua; }
    void setBonoAgua(int bono) { bonoAgua = bono; }

    void aumentoAtaque() { ataque = ataque + (bonoAgua * 0.1); }
    void disminuirAtaque() { ataque = ataque - (debugAgua * 0.1); }

    char* getNombreAtaque() { return nombreAtaque; }
    void setName(char n[20]) { strcpy_s(nombreAtaque, n); }
};

class pokeFuego : public pokemon
{
    int bonoFuego;
    int debugFuego;
    //float espFuego;
    char nombreAtaque[20];

public: 

    pokeFuego(int bf, int df): pokemon()
    {
        bonoFuego = bf;
        debugFuego = df;
        strcpy_s(nombreAtaque, "bola de fuego");
    }

    pokeFuego(int bf, int df, char n[15], double a, int s, char c[15])
    {
        bonoFuego = bf;
        debugFuego = df;
        strcpy_s(nombre, n);
        ataque = a;
        salud = s;
        strcpy_s(color, c);
        strcpy_s(nombreAtaque, "bola de fuego");
    }

    int getBonoFuego() { return bonoFuego; }
    void setBonoFuego(int bono) { bonoFuego = bono; }

    void aumentoAtaque() { ataque = ataque + (bonoFuego * 0.1); }
    void disminuirAtaque() { ataque = ataque - (debugFuego * 0.1); }

    char* getNombreAtaque() { return nombreAtaque; }
    void setName(char n[20]) { strcpy_s(nombreAtaque, n); }
};

class pokeTierra : public pokemon
{
    int bonoTierra;
    int debugTierra;
    char nombreAtaque[20];

public:

    pokeTierra(int bt, int dt): pokemon() 
    {
        bonoTierra = bt;
        debugTierra = dt;
        strcpy_s(nombreAtaque, "Lanza roca");
    }

    pokeTierra(int bt, int dt, char n[15], double a, int s, char c[15])
    {
        bonoTierra = bt;
        debugTierra = dt;
        strcpy_s(nombre, n);
        ataque = a;
        salud = s;
        strcpy_s(color, c);
        strcpy_s(nombreAtaque, "Lanza roca");
    }

    int getBonoTierra() { return bonoTierra; }
    void setBonoTierra(int bono) { bonoTierra = bono; }

    void aumentoAtaque() { ataque = ataque + (bonoTierra * 0.1); }
    void disminuirAtaque() { ataque = ataque - (debugTierra * 0.1); }

    char* getNombreAtaque() { return nombreAtaque; }
    void setName(char n[20]) { strcpy_s(nombreAtaque, n); }
};

void funcionAtaque(pokemon& p, pokemon& p2)
{
    double ataque;
    int salud;
    ataque = p2.getAtaque();
    salud = p.getSalud()-ataque;
    p.setSalud(salud);
}

int main()
{
    char nom_poke[15], col_poke[15], nnom_poke[15], ncol_poke[15], nom_poke2[15], col_poke2[15];
    int pelea, pociones, turno = 0, ataqueBonus, estado = 0;


    strcpy_s(nom_poke, "Charmander");
    strcpy_s(col_poke, "Naranja");
    pokeFuego Poke1( 1, 1, nom_poke, 10, 180, col_poke);

    strcpy_s(nom_poke2, "mew");
    strcpy_s(col_poke2, "Rosa");

    pokeTierra Poke2(1, 1, nom_poke2, 10, 170, col_poke2);

    Poke1.datos_pokemon();

    pokeAgua* poke3 = new pokeAgua(1, 1, nom_poke2, 3, 170, col_poke2);

    Poke2.datos_pokemon();

    cout << "Desea pelear: 1. si, 2. no" << endl;
    cin >> pelea;

    if (pelea == 1)
    {
        while (estado != 1)
        {
            if (turno == 1 && Poke1.getSalud() != 0)
            {
                cout << "El pokemon " << Poke1.getNombre() << " ataca al pokemon " << Poke2.getNombre() << " con ataque: " << Poke1.getNombreAtaque() << "." << endl;
                funcionAtaque(Poke2, Poke1);
                turno = 0;
                cout << "Salud de " << Poke2.getNombre() << " es: " << Poke2.getSalud() << endl;
                if (Poke2.getSalud() <= 0) { estado = 1; }
            }
            if (turno == 0 && Poke2.getSalud() != 0)
            {
                cout << "El pokemon " << Poke2.getNombre() << " ataca al pokemon " << Poke1.getNombre()<<"con ataque: " << Poke2.getNombreAtaque() << "." << endl;
                    funcionAtaque(Poke1, Poke2);
                    turno = 1;
                    cout << "Salud de " << Poke1.getNombre() << " es: " << Poke1.getSalud() << endl;
                    if (Poke1.getSalud() <= 0) { estado = 1; }
            }
        if (Poke1.getSalud() <= 0) { cout << "El ganador del combate es: " << Poke2.getNombre() << endl; }
        else 
        if (Poke2.getSalud() <= 0) { cout << "El ganador del combate es: " << Poke1.getNombre() << endl; }
        }
    }
    else if (pelea == 2) { return 0; }
    else 
    {
            cout << "opcion no reconocida"<<endl;
            return 0;
    }


}