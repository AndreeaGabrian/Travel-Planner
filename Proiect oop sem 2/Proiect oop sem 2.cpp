#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<Windows.h>
#include"UI.h"
#include"RepoTemplate.h"
#include"ServicePunctDeVizitare.h"
#include"CoordonateGeo.h"
#include"RepoTemplateFile.h"
#include"ServiceRuta.h"
#include"ServiceObiectivTuristic.h"
#include"Login.h"
#include"Admin.h"
#include"UICalator.h"
#include"FunctiiUtile.h"
#include"TesteDomain.h"
#include"TesteRepo.h"
#include"TesteRepoFile.h"
#include"TesteServiceLocalitate.h"
#include"TesteServicePunctDeVizitare.h"
#include"TesteServiceRuta.h"
#include"TesteServiceObiectiv.h"
#include"TesteCalatorie.h"
#include"TesteValidatori.h"


using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;
using namespace std;

int main()
{
    TesteDomain td;
    TesteRepo tr;
    TesteRepoFile trf;
    td.runAll();
    tr.runAll();
    trf.runAll();
    TesteServiceLocalitate tsl;
    tsl.runAll();
    TesteServicePunctDeVizitare tsp;
    tsp.runAll();
    TesteServiceRuta tsr;
    tsr.runAll();
    TesteServiceObiectiv tso;
    tso.runAll();
    TesteCalatorie tc;
    tc.runAll();
    TesteValidatori tv;
    tv.runAll();

    changeColor(14);
   
    bool ok2 = true;
    bool ok3 = true;
    string optiune;
    Calatorie calatorie;
    string calatorie_filename;
    bool esteLogatUnUser = false;
    while (ok3) 
    {
        ok3 = false;
        while (ok2)
        {
            string username, password;
            cout << " ___________________________\n";
            cout << "|                           |\n";
            cout << "| PLANIFICATOR DE CALATORII |\n";
            cout << "|___________________________|\n";
            cout << " ---------------------------\n";
            cout << "|1.Login                    |\n";
            cout << "|2.Sign in                  |\n";
            cout << "|x.Iesire                   |\n";
            cout << " ---------------------------\n";
            Login l("Login.txt");
            cin >> optiune;
            if (optiune == "1")
            {
                ok2 = false;
                cout << "->Username: ";
                cin >> username;
                cout << "->Password: ";
                cin >> password;

                Admin ad;
                if (ad.getUsername() == username && ad.getPassword() == password)
                {
                    calatorie_filename = "admin.txt";
                }
                else {

                    User u(username, password);
                    bool logged = l.login(u);
                    if (logged)
                    {
                        calatorie_filename = username + ".txt";
                        esteLogatUnUser = true;

                    }
                }
            }
            else if (optiune == "2")
            {
                ok2 = false;
                bool sig = l.signin();
                if (sig)
                {
                    changeColor(10);
                    cout << "Autentificare reusita! Va rugam sa va logati\n";
                    changeColor(14);
                }

            }
            else if (optiune == "x")
            {
                ok2 = false;
                continue;
            }
            else {
                changeColor(12);
                cout << "Optiune invalida, reincercati!\n";
                changeColor(14);
            }


        }

            ifstream f(calatorie_filename);
            if (!f.is_open())
            {
                ofstream f(calatorie_filename);
            }

            calatorie.setFilename("C:\\Users\\gabri\\Documents\\AN 1 SEM 2\\POO\\Proiect\\Proiect oop sem 2\\Proiect oop sem 2//" + calatorie_filename);
            string stocare;




            if (calatorie_filename == "admin.txt") {
                cout << "Unde doriti sa aiba loc stocarea, fisier sau memorie?\n";
                cin >> stocare;
                bool ok = true;
                while (ok)
                {

                    if (stocare == "fisier")
                    {
                        ok = false;
                        RepoTemplateFile<PunctDeVizitare> repo_pct_file("pct.txt");
                        RepoTemplateFile<Localitate> repo_loc_file("Locatii.txt");
                        RepoTemplateFile<Ruta> repo_ruta_file("rute.txt");
                        RepoTemplateFile<ObiectivTuristic> repo_obv_file("obiective.txt");
                        ServicePunctDeVizitare srv_pct(repo_pct_file);
                        ServiceLocalitati srv_loc(repo_loc_file, repo_obv_file, repo_ruta_file);
                        ServiceRuta srv_ruta(repo_ruta_file, repo_loc_file);
                        ServiceObiectivTuristic srv_obv(repo_obv_file, repo_loc_file);
                        UI ui(srv_pct, srv_loc, srv_ruta, srv_obv, calatorie);
                        ui.runMenu();

                    }
                    else if (stocare == "memorie")
                    {
                        ok = false;
                        RepoTemplate<PunctDeVizitare> repo_pct;
                        RepoTemplate<Localitate> repo_loc;
                        RepoTemplate<Ruta> repo_ruta;
                        RepoTemplate<ObiectivTuristic> repo_obv;
                        ServicePunctDeVizitare srv_pct(repo_pct);
                        ServiceLocalitati srv_loc(repo_loc, repo_obv, repo_ruta);
                        ServiceRuta srv_ruta(repo_ruta, repo_loc);
                        ServiceObiectivTuristic srv_obv(repo_obv, repo_loc);
                        UI ui(srv_pct, srv_loc, srv_ruta, srv_obv, calatorie);
                        ui.runMenu();

                    }
                    else
                    {
                        changeColor(12);
                        cout << "Optiune invalida, reincercati!\n";
                        changeColor(14);
                    }
                }

            }
            else if (esteLogatUnUser)
            {
                RepoTemplateFile<PunctDeVizitare> repo_pct_file("pct.txt");
                RepoTemplateFile<Localitate> repo_loc_file("Locatii.txt");
                RepoTemplateFile<Ruta> repo_ruta_file("rute.txt");
                RepoTemplateFile<ObiectivTuristic> repo_obv_file("obiective.txt");
                ServicePunctDeVizitare srv_pct(repo_pct_file);
                ServiceLocalitati srv_loc(repo_loc_file, repo_obv_file, repo_ruta_file);
                ServiceRuta srv_ruta(repo_ruta_file, repo_loc_file);
                ServiceObiectivTuristic srv_obv(repo_obv_file, repo_loc_file);
                UICalator uiCalator(srv_pct, srv_loc, srv_ruta, srv_obv, calatorie);
                uiCalator.runAllMeniuCalator();
            }
            else
            {
                ok3 = true;
                ok2 = true;
            }
                

        
    }
    return 0;
}

