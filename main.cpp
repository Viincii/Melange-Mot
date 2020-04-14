#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

string melangerLettres(string mot)//Fonction pour mélanger les lettres
{
    int position(0);
    string mot2;

    while (mot.size()!= 0)
    {
        position = rand()% mot.size();
        mot2 += mot[position];
        mot.erase(position, 1);
    }
    return mot2;
}


int main()
{
    string repO("OUI"),repN("NON"),repU("Pas de réponse");
    int nbPartie(0),partieGagne(0);
    string const parcDico("Dico/dico.txt");//On cree une variable avec le chemin vers le fichier
    do
    {

        string motMystere, motJ2,motMelange;

        srand(time(0));

        //On choisi un mot au hasard dans une liste


        cout << "Un mot va etre choisi soit au hasard soit par l'un des deux joueurs, essayez de le trouver en remettant les lettres dans le bon ordre." << endl<< "Vous avez autant d'essais que de lettres dans le mot (avec un minimum de 5)."<<endl;
        cout << "Faites attention a bien ecrire toutes les reponses en majuscules."<< endl;
        int nbJoueur(0);
        do
        {
        cout <<"Combien de joueurs? (1 ou 2)"<<endl;
        cin >> nbJoueur;

        if(nbJoueur ==1)
        {
            int niveaux(0);
            cout << "Quel niveaux desirez-vous? (correspond au nombre de lettres du mot: min 3)"<< endl;
            cin >> niveaux;
            do
            {
            ifstream dico(parcDico.c_str());
        string ligneDico;
        int numLigne= rand()% 353277;

        int compteur(0);//le compteur permet de travailler avec des lignes pas des caractères

        while (getline(dico,ligneDico))
            {

            if (compteur == numLigne)
            {
                motMystere= ligneDico;
            }

            compteur++;
            }

            }while (niveaux != motMystere.size());
        }
        if(nbJoueur == 2)
        {
            cout<< "Joueur 1 : Choisissez un mot : "<<endl;
            cin >> motMystere;
        }
         }while(nbJoueur != 1 && nbJoueur != 2);


        int nbEssais(motMystere.size());//Permet d'avoir un nombre d'essais dynamique.
        if (nbEssais<5)
        {
            nbEssais=5;
        }
        if (nbEssais>10)
        {
            nbEssais=10;
        }
        //On mélange


        motMelange  = melangerLettres(motMystere);


        //On demande à l'utilisateur quel est le mot
        do
        {
            {
                cout<< "Attention, il vous reste "<< nbEssais<< " essais."<< endl;
                nbEssais--;
            }
            cout << endl << "Quel est ce mot? " << motMelange << endl;
            cin >> motJ2;
            if(nbEssais>0)

                if (motJ2 == motMystere)
                {
                    cout <<"Bravo !"<< endl;
                }
                else
                {
                    cout << "Ce n'est pas ca !"<< endl<< endl;
                }

        }
        while (motJ2 != motMystere && nbEssais>0);
        nbPartie++;
        if (nbEssais>0)
        {
            partieGagne++;
        }
        else
        {
            cout << "Vous avez perdu! La reponse etait " << motMystere << endl;
        }
        cout << "Voulez-vous faire une nouvelle partie? (OUI/NON)" << endl;
        cin >> repU;
    }
    while (repO == repU);
    if (repU == repN)
    {
        cout << "Le jeu se termine."<< endl;
    }
    if (repU != repO && repU != repN)
    {
        cout << "Vous avez voulu jouer au petit malin, la partie se termine quand meme."<< endl;
    }
    cout << "Votre moyenne est de "<< partieGagne<<"/"<<nbPartie<< " parties gagnees." <<endl;

    return 0;
}
