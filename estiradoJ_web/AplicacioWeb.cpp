//Tasca 1. Aplicació web

#include <iostream>
#include <string>
using namespace std;

class SessioUsuari {
private:
    string nomUsuari;
    int tempsLlimitSegons;
    bool activa;
    void tancarSessio() {
        activa = false;
    }

public:
    SessioUsuari()
        : nomUsuari("convidat"), tempsLlimitSegons(300), activa(true) {
    }

    explicit SessioUsuari(string nom)
        : nomUsuari(nom), tempsLlimitSegons(600), activa(true) {
    }

    SessioUsuari(string nom, int temps)
        : nomUsuari(nom),
        tempsLlimitSegons(temps > 0 ? temps : 60),
        activa(true) {
    }

    string getNomUsuari() const {
        return nomUsuari;
    }

    bool isActiva() const {
        return activa;
    }

    void ampliarTemps(int segons) {
        if (segons > 0) {
            tempsLlimitSegons += segons;
        }
    }

    ~SessioUsuari() {
        if (activa) {
            tancarSessio();

            cout << "[AUDITORIA] La sessio de '"
                << nomUsuari
                << "' s'ha tancat automaticament en sortir d'ambit."
                << endl;
        }
    }
};

int main() {
    {
        SessioUsuari sessio1;
        SessioUsuari sessio2("Judit");
        SessioUsuari sessio3("Marc", 900);

        cout << "Usuari 1: " << sessio1.getNomUsuari() << endl;
        cout << "Usuari 2: " << sessio2.getNomUsuari() << endl;
        cout << "Sessio activa? "
            << (sessio3.isActiva() ? "Si" : "No") << endl;

        sessio3.ampliarTemps(300);
        sessio2.ampliarTemps(-10); 
    } 

    cout << "El programa continua." << endl;

    return 0;
}