#include <iostream>

using namespace std;


class Bautura {
public:
    Bautura(string denumire_bautura, float cantitate_litri, unsigned int kcal);
    Bautura(const Bautura&);
    string get_denumire_bautura();
    float get_cantitate_litri();
    unsigned int get_kcal();
    void set_denumire_bautura(string);
    void set_cantitate_litri(float);
    void set_kcal(unsigned int);
    friend istream& operator >> (istream& stream, Bautura& bautura);
    friend ostream& operator << (ostream& stream, Bautura& bautura);
    Bautura operator = (Bautura);
    virtual void denumire();  //functie care ma ajuta la downcasting si upcasting



protected:
    static double preserved; //variabila care poate fi accesata din clasele copil
private:
    string denumire_bautura;
    float cantitate_litri;
    unsigned int kcal;

};

Bautura::Bautura(string denumire_bautura = "NULL", float cantitate_litri = 0, unsigned int kcal = 0) {
    this->denumire_bautura = denumire_bautura;
    this->cantitate_litri = cantitate_litri;
    this->kcal = kcal;
}

Bautura::Bautura(const Bautura& bautura) {
    denumire_bautura = bautura.denumire_bautura;
    cantitate_litri = bautura.cantitate_litri;
    kcal = bautura.kcal;
}

string Bautura::get_denumire_bautura() {
    return this->denumire_bautura;
}

float Bautura::get_cantitate_litri() {
    return this->cantitate_litri;
}

unsigned int Bautura::get_kcal() {
    return this->kcal;
}
void Bautura::set_denumire_bautura(string denumire_bautura) {
    this->denumire_bautura = denumire_bautura;
}

void Bautura::set_cantitate_litri(float cantitate_litri) {
    this->cantitate_litri = cantitate_litri;
}

void Bautura::set_kcal(unsigned int kcal) {
    this->kcal = kcal;
}

void Bautura::denumire(){

    cout << denumire_bautura;
}

istream& operator >> (istream& stream, Bautura& bautura) {
    cout << "Introduceti denumirea bauturii (un singur cuvant): \n";
    stream >> bautura.denumire_bautura;
    cout << "Introduceti cantitatea in litri a bauturii: \n";
    stream >> bautura.cantitate_litri;
    cout << "Introduceti numarul de kcal( numar intreg ): \n";
    stream >> bautura.kcal;
    return stream;
}

ostream& operator << (ostream& stream, Bautura& bautura) {
    stream << "Bautura " << bautura.denumire_bautura << " de " << bautura.cantitate_litri << " litri are " << bautura.kcal << " kcal" << ". ";
    return stream;
}

Bautura Bautura::operator = (Bautura bautura) {
    denumire_bautura = bautura.denumire_bautura;
    cantitate_litri = bautura.cantitate_litri;
    kcal = bautura.kcal;
    return (*this);
}



double Bautura:: preserved = 5;  

class Bautura_Nonalcoolica : public Bautura {
public:
    Bautura_Nonalcoolica(string, float, unsigned int, string, string , unsigned int);
    Bautura_Nonalcoolica(const Bautura_Nonalcoolica&);
    string get_carbogazificata_sau_nu();
    string get_bio_sau_nu();
    unsigned int get_nr_aditivi();
    void set_carbogazificata_sau_nu(string);
    void set_bio_sau_nu(string);
    void set_nr_aditivi(unsigned int);
    friend istream& operator >> (istream& stream, Bautura_Nonalcoolica& bautura_nonalcoolica);
    friend ostream& operator << (ostream& stream, Bautura_Nonalcoolica& bautura_nonalcoolica);
    Bautura_Nonalcoolica operator = (Bautura_Nonalcoolica&);
    static double preserved_nr_aditivi(unsigned int);  //functie statica
    void denumire();
    
private:
    string carbogazificata_sau_nu;
    string bio_sau_nu;
    unsigned int nr_aditivi;

};

Bautura_Nonalcoolica::Bautura_Nonalcoolica(string denumire_bautura = "NULL", float cantitate_litri = 0, unsigned int kcal = 0, string carbogazificata_sau_nu = "NULL", string bio_sau_nu = "NULL", unsigned int nr_aditivi = 0) :Bautura(denumire_bautura, cantitate_litri, kcal) {
    this->carbogazificata_sau_nu = carbogazificata_sau_nu;
    this->bio_sau_nu = bio_sau_nu;
    this->nr_aditivi = nr_aditivi;
}

Bautura_Nonalcoolica::Bautura_Nonalcoolica(const Bautura_Nonalcoolica& bautura_nonalcoolica){
    carbogazificata_sau_nu = bautura_nonalcoolica.carbogazificata_sau_nu;
    bio_sau_nu = bautura_nonalcoolica.bio_sau_nu;
    nr_aditivi = bautura_nonalcoolica.nr_aditivi;

}

string Bautura_Nonalcoolica::get_carbogazificata_sau_nu() {
    return this->carbogazificata_sau_nu;
}

string Bautura_Nonalcoolica::get_bio_sau_nu() {
    return this->bio_sau_nu;
}

unsigned int Bautura_Nonalcoolica::get_nr_aditivi() {
    return this->nr_aditivi;
}

void Bautura_Nonalcoolica::set_carbogazificata_sau_nu(string) {
    this->carbogazificata_sau_nu = carbogazificata_sau_nu;
}

void Bautura_Nonalcoolica::set_bio_sau_nu(string) {
    this->bio_sau_nu = bio_sau_nu;
}

void Bautura_Nonalcoolica::set_nr_aditivi(unsigned int) {
    this->nr_aditivi = nr_aditivi;
}

void Bautura_Nonalcoolica::denumire() {
    cout << nr_aditivi;
}


istream& operator >> (istream& stream, Bautura_Nonalcoolica& bautura_nonalcoolica) {
    cout << "Introduceti daca bautura este carbogazificata sau necarbogazificata: \n";
    stream >> bautura_nonalcoolica.carbogazificata_sau_nu;
    cout << "Introduceti daca bautura este bio sau nu este bio: \n";
    stream >> bautura_nonalcoolica.bio_sau_nu;
    cout << "Introduceti cati aditivi are bautura: \n";
    stream >> bautura_nonalcoolica.nr_aditivi;
    return stream;

}

ostream& operator << (ostream& stream, Bautura_Nonalcoolica& bautura_nonalcoolica) {
    stream << "Bautura este nonalcoolica, " << bautura_nonalcoolica.carbogazificata_sau_nu << " ," << bautura_nonalcoolica.bio_sau_nu << " si are " << bautura_nonalcoolica.nr_aditivi << " aditivi" << endl;
    return stream;
}

Bautura_Nonalcoolica Bautura_Nonalcoolica::operator = (Bautura_Nonalcoolica& bautura_nonalcoolica) {
    (*this).Bautura::operator = (bautura_nonalcoolica);
    carbogazificata_sau_nu = bautura_nonalcoolica.carbogazificata_sau_nu;
    bio_sau_nu = bautura_nonalcoolica.bio_sau_nu;
    nr_aditivi = bautura_nonalcoolica.nr_aditivi;
    return(*this);
}


double Bautura_Nonalcoolica::preserved_nr_aditivi(unsigned int nr_aditivi) {
    return preserved * nr_aditivi;
}


class Bautura_Alcoolica : public Bautura {
public:
    Bautura_Alcoolica(string, float, unsigned int, unsigned int, unsigned int);
    Bautura_Alcoolica(const Bautura_Alcoolica&);
    unsigned int get_volum_alcool();
    unsigned int get_nr_coloranti();
    void set_volum_alcool(unsigned int);
    void set_nr_coloranti(unsigned int);
    friend istream& operator >> (istream& stream, Bautura_Alcoolica& bautura_alcoolica);
    friend ostream& operator << (ostream& stream, Bautura_Alcoolica& bautura_alcoolica);
    Bautura_Alcoolica operator = (Bautura_Alcoolica&);
    static double preserved_nr_coloranti(unsigned int);  //functie statica
    void denumire();

private:
    unsigned int volum_alcool;
    unsigned int nr_coloranti;

};

Bautura_Alcoolica::Bautura_Alcoolica(string denumire_bautura = "NULL",  float cantitate_litri = 0, unsigned int kcal = 0, unsigned int volum_alcool = 0, unsigned int nr_coloranti = 0) :Bautura(denumire_bautura, cantitate_litri, kcal) {
    this->volum_alcool = volum_alcool;
    this->nr_coloranti = nr_coloranti;
}

Bautura_Alcoolica::Bautura_Alcoolica(const Bautura_Alcoolica& bautura_alcoolica) {
    volum_alcool = bautura_alcoolica.volum_alcool;
    nr_coloranti = bautura_alcoolica.nr_coloranti;
}

unsigned int Bautura_Alcoolica::get_volum_alcool() {
    return this->volum_alcool;
}

unsigned int Bautura_Alcoolica::get_nr_coloranti() {
    return this->nr_coloranti;
}

void Bautura_Alcoolica::set_volum_alcool(unsigned int) {
    this->volum_alcool = volum_alcool;
}

void Bautura_Alcoolica::set_nr_coloranti(unsigned int) {
    this->nr_coloranti = nr_coloranti;
}

void Bautura_Alcoolica::denumire() {
    cout << volum_alcool;
}

istream& operator >> (istream& stream, Bautura_Alcoolica& bautura_alcoolica) {
    cout << "Introduceti volumul de alcool(numar intreg): \n";
    stream >> bautura_alcoolica.volum_alcool;
    cout << "Introduceti numarul de coloranti al bauturii: \n";
    stream >> bautura_alcoolica.nr_coloranti;
    return stream;
}

ostream& operator << (ostream& stream, Bautura_Alcoolica& bautura_alcoolica) {
    stream <<"Bautura alcoolica are "<< bautura_alcoolica.volum_alcool<<"% volum de alcool si "<<bautura_alcoolica.nr_coloranti<<" coloranti";
    return stream;
}

Bautura_Alcoolica Bautura_Alcoolica:: operator = (Bautura_Alcoolica& bautura_alcoolica) {
    (*this).Bautura::operator = (bautura_alcoolica);
    volum_alcool = bautura_alcoolica.volum_alcool;
    nr_coloranti = bautura_alcoolica.nr_coloranti;
    return(*this);
}



double Bautura_Alcoolica::preserved_nr_coloranti(unsigned int nr_coloranti) {
    return preserved * nr_coloranti;

}

int main(int argc, const char* argv[]) {

    //constructori parametrizati

    Bautura b, b1("fanta"), b2("cola", 2.5);
    cout << b << endl << b1 << endl << b2 << "\n\n";

    //atribuirea

    Bautura a("fanta", 2, 100), a1("cola", 1.5, 300);
    a = a1;
    cout << a <<"\n";

    Bautura_Nonalcoolica c( "fanta", 2, 145, "carbogazificata", "nu este bio", 5);
    Bautura_Nonalcoolica c1("suc de mere", 1, 100, "necarbogazificata", "bio", 2);
    c = c1;
    cout << c1 ;

    Bautura_Alcoolica d("vin", 2, 300, 20, 1);
    Bautura_Alcoolica d1("gin", 1.5, 293, 45, 3);
    d1 = d;
    cout << d1 << "\n\n";

    //functie statica ( se inmulteste cu 5 )

    Bautura_Nonalcoolica e("suc de mere", 1, 100, "necarbogazificata", "bio", 2);
    Bautura_Alcoolica f("gin", 1.5, 293, 45, 3);

    cout << e.preserved_nr_aditivi(e.get_nr_aditivi()) << "\n";
    cout << f.preserved_nr_coloranti(f.get_nr_coloranti()) << "\n\n";

    //upcasting

    Bautura* g = new Bautura_Alcoolica("gin", 1.5, 293, 45, 3);
    g->denumire();
    cout << " "<< g->get_denumire_bautura()<< "\n";

    Bautura* h = new Bautura_Nonalcoolica("suc de mere", 1, 100, "necarbogazificata", "bio", 2);
    h->denumire();
    cout << " " << h->get_denumire_bautura() << "\n\n";

    //downcasting si try-catch
    
    try {
        Bautura_Alcoolica* k = dynamic_cast<Bautura_Alcoolica*>(g);
        k->denumire();
    }
    catch (runtime_error) {
        cout << "Conversie invalida!\n";
    }

    cout << "\n";

    try {
        Bautura_Nonalcoolica* l = dynamic_cast<Bautura_Nonalcoolica*>(h);
        l->denumire();
    }
    catch (runtime_error) {
        cout << "Conversie invalida!\n";
    }

    //meniu interactiv
        //memorarea, citirea si afisarea se afla in meniu

    int optiune , i;
    int numar_bauturi, nr_bauturi_nonalcoolice;
    cout << "\n\nLa prima rulare a meniului se recomanda citirea datelor!\n\n";
    Bautura* bautura = NULL;
    Bautura_Nonalcoolica* bautura_nonalcoolica = NULL;
    Bautura_Alcoolica* bautura_alcoolica = NULL;
    while (true) {
        cout << "1. Citirea bauturilor \n";
        cout << "2. Afisarea tuturor bauturilor \n";
        cout << "3. Afisarea bauturilor nonalcoolice \n";
        cout << "4. Afisarea bauturilor alcoolice \n";
        cout << "5. Iesire din meniu \n";
        cin >> optiune;
        if (optiune == 5)
            break;
        else if (optiune == 1) {
            cout << "Introduceti numarul de bauturi: \n";
            cin >> numar_bauturi;
            cout << "Introduceti numarul de bauturi nonalcoolice ( restul sunt cu alcool ':)' ): \n";
            cin >> nr_bauturi_nonalcoolice;
            bautura = new Bautura[numar_bauturi + 1];
            bautura_nonalcoolica = new Bautura_Nonalcoolica[nr_bauturi_nonalcoolice + 1];
            bautura_alcoolica = new Bautura_Alcoolica[numar_bauturi + 1];
            cout << "Se citesc bauturile nonalcoolice daca exista \n";
            for (i = 1; i <= nr_bauturi_nonalcoolice; i++)
            {
                cin >> bautura[i];
                cin >> bautura_nonalcoolica[i];
            }
            cout << "Se citesc bauturile alcoolice daca exista \n";
            for (i = nr_bauturi_nonalcoolice + 1; i <= numar_bauturi; i++)
            {
                cin >> bautura[i];
                cin >> bautura_alcoolica[i];
                
            }
            cout << "\n---------------------------\n";

        }
        else if (optiune == 2 && bautura != NULL) {
            for (i = 1; i <= nr_bauturi_nonalcoolice; i++)
            {
                cout << bautura[i];
                cout << bautura_nonalcoolica[i];
            }
            for (i = nr_bauturi_nonalcoolice + 1; i <= numar_bauturi; i++)
            {
                cout << bautura[i];
                cout << bautura_alcoolica[i];

            }
            cout << "\n---------------------------\n";
        }
        else if (optiune == 3 && bautura != NULL) {
            for (i = 1; i <= nr_bauturi_nonalcoolice; i++)
            {
                cout << bautura[i];
                cout << bautura_nonalcoolica[i];
            }
            cout << "\n---------------------------\n";
        }
        else if (optiune == 4 && bautura != NULL) {
            for (i = nr_bauturi_nonalcoolice + 1; i <= numar_bauturi; i++)
            {
                cout << bautura[i];
                cout << bautura_alcoolica[i];

            }
            cout << "\n---------------------------\n";

        }

    }

    



 
    


       
}

