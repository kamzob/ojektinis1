//
//  main.cpp
//  pirmasobj
//
//  Created by Kamilė Zobėlaitė on 2024-02-07.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#define x 50
using namespace std;
struct Vartotojas
{
    string vardas;
    string pavarde;
    int nd[x];
    int egz;
    double vid = 0.0;       // namu darbu pazymiu vidurkis
    double gal = 0.0;       // galutinis ivertinimas
    double med = 0.0;       // namu darbu mediana
    
};
double Vidurkis(double suma, int nariai);
double Mediana(int paz[], int nariai);
int main() {

    int n;
    int kiek;       // tarpiniu pazymiu kiekis
    cout << "Iveskite vartotoju skaiciu:" << endl;
    cin >> n;
    Vartotojas vart[n];
    for (int i = 0; i < n; i++)
    {
        double sum = 0.0;        // tarpiniu pazymiu suma
        cout << "Iveskite " << i+1 << "-ojo studento varda:" << endl;
        cin >> vart[i].vardas;
        cout << "Iveskite " << i+1 << "-ojo pavarde:" << endl;
        cin >> vart[i].pavarde;
        cout << "Kiek yra tarpiniu pazymiu?" << endl;
        cin >> kiek;
        while(kiek<1 || kiek>x)
        {
            cout << "Iveskite tarpiniu pazymiu kieki:" << endl;
            cin >> kiek;
        }
        for (int j = 0; j < kiek; j++){
            cout << "Iveskite " << j+1 << " pazymi" << endl;
            cin >> vart[i].nd[j];
            while(vart[i].nd[j]<1 || vart[i].nd[j]>10)
            {
                cout << "Klaida! Pazymys turi buti nuo 1 iki 10: \n";
                cin >> vart[i].nd[j];
            }
            sum += vart[i].nd[j];
        }
        cout << "Iveskite egzamino rezultata:" << endl;
        cin >> vart[i].egz;
        while(vart[i].egz<1 || vart[i].egz>10)
        {
            cout << "Klaida! Egzamino rezultatas turi buti nuo 1 iki 10: \n";
            cin >> vart[i].egz;
        }
        vart[i].vid = Vidurkis(sum, kiek);
        vart[i].med = Mediana(vart[i].nd, kiek);
        
        
    }
    int rnkts;      // pasirinkimas, kaip norima skaiciuoti galutini ivertinima - pagal vidurki ar mediana
    cout << "Pasirinkite kaip norite, kad skaiciuotu jusu galutini ivertinima: 0 - pagal vidurki, 1 - pagal mediana: " << endl;
    cin >> rnkts;
    while (rnkts != 0 && rnkts !=1)
    {
        cout << "Klaida! Turite pasirinkti 0 (galutinis ivert. skaiciuojamas pagal vidurki) arba 1 (pagal mediana): \n";
        cin >> rnkts;
    }
    if (rnkts == 0)
    {
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)<< "Galutinis (vid.)" << endl;
        cout << "---------------------------------------------------" << endl;
        for ( int i = 0; i < n; i++)
        {
            vart[i].gal = 0.4*vart[i].vid+0.6*vart[i].egz;
            cout << left << setw(15) << vart[i].pavarde << setw(15) << vart[i].vardas << setw(15) << fixed << setprecision(2) << vart[i].gal << endl;
        }
        
        
    }
    else if (rnkts == 1)
    {
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)<< "Galutinis (med.)" << endl;
        cout << "---------------------------------------------------" << endl;
        for ( int i = 0; i < n; i++)
        {
            vart[i].gal = 0.4*vart[i].med+0.6*vart[i].egz;
            cout << left << setw(15) << vart[i].pavarde << setw(15) << vart[i].vardas << setw(15) << fixed << setprecision(2) << vart[i].gal << endl;
        }
        
    }
    
    
    return 0;
}
double Vidurkis(double suma, int nariai){
    return suma/nariai;
    
}
double Mediana(int paz[], int nariai)
{
    sort(paz, paz+nariai);
    if(nariai % 2 != 0)
        return double(paz[nariai/2]);
    return double(paz[(nariai-1) / 2] + paz[nariai/2] / 2.0);
    
}

