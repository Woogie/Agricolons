/* Bon h� bien voila une premi�re version du programme
je n'ai pour l'instant que fait la structure g�n�rale du jeu,
cela semble bien fonctionner bien que je ne pense pas que ce programme
soit bien optimis� :)
-> genre la boucle do while copier coller 4 fois lol (j'aurais pu en faire une fct mais l�
Je vais me coucher :)

+ quelques ajustement encore pour �viter les bugs
(genre un joueur qui rentre un caract�re au lieu d'un nombre etc etc...),

il manque encore toute les fonctions "actions" (le plus long je pense),
toutes les variables � "recolter", les bourses des joueurs, les plateaux....

et j'entre-aper�oit un probl�me :
comment le programme saura-t-il qu'il faut augment� la bourse du joueur 1 ou du joueur 2
ou encore comment lui expliquer lorsque mes fonctions s'appliquent aux actions des deux joueurs...

mais bon on reflechira � cela plus tard !!! :)

N'h�site pas � critiquer,
Si ce code te semble inadapt� dis le moi aussi,
Si le code est mal mis en page je suis vraiment d�sol� -> j'essaye pourtant de faire au plus clair
    mais si je passe � cot� de r�gles �l�mentaires de pr�sentation dis le moi


Si tu va jusqu'au bout de la lecture de ce code Merci !!!
Bye
*/

#include <iostream>
#include <string>

using namespace std;

/*  cr�ation des diff�rentes fonctions du programme
    Ici les fonctions ne sont faite que pour tester
    l'organisation du programme (elles ne renvoient qu'un cout)
    Elles seront s�rement plus tard �crites dans un autre fichier pour clarifier */
void fillingOfTheGameBoard () // on verra plus tard !
    {
        cout << "remplissage du plateau effectue !" << endl; //si �� pouvait �tre aussi simple :)
    }

void help () // on pourra rajouter apr�s les explication de chaque commande.
    {
        cout << "les commandes possibles sont :" << endl;
        cout << "help" << endl << "quit" << endl << "end" << endl << "print" << endl << "pocket" << endl << "go" << endl;
    }

void quit ()
    {
        cout << "merci d'avoir jou� � Agricolons" << endl;
        // Il doit exister un moyen de quitter im�diatement le programme
        // mais on verra plus tard
    }

void end () // l'�criture de cette fonction montre le probl�me de mon code :
            // le programme ne sait pas quel joueur est en cour donc
            // le programme ne sait pas sur quelles variable decrement�
            // MERDE !!! :)
    {
        /* on la met de cot� pour le moment
        int sleep (0);
        cout << "Ceci mettra fin � votre TOUR" << endl << "Etes vous sur ?" << endl;
        cout << "oui : 1" << endl << "non : 2" << endl;
        cin >> sleep;
        if (sleep == 1) {familyMember} */
        // GROS PROBLEME !!!! COMMENT INDIQUER LE JOUEUR EN COUR !!!!!
        cout << "tout va bien !" << endl;
    }

void print ()
    {
        cout << "Desoler nous n'en sommes pas encore l�" << endl;
    }

void pocket ()
    {
        cout << "Vous n'avez rien dans les poches dsl"<<endl;
    }

void go (int x=0)
    {
        if (x>=0) {cout << "Votre personnage part travaille" << endl;}
        else {cout << "Votre personnage part travaille" << endl;}
        // Je voulais au d�part d�cr�menter familyMember � la fin de la fonction go(),
        // finalement je l'ai fait � la fin des boucles do while
        // je pense que cela peut aussi marcher pour le probl�me ci-dessus
        // mais l� il faut que j'aille me coucher :)
    }

int main()
{
    //cr�ation des diff�rentes variables du programme
    string player1("joueur1"), player2("Joueur2"), action;
    int numberOfTurn(-1), choixCase(0), familyMember1(1), familyMember2(3);

    // Pr�sentation, choix des pseudos et nombre de tours
    cout << "AGRICOLONS" << endl << endl;
    cout << "Choix des pseudos :" << endl;
    cout << "Joueur 1 :" << endl;
    cin >> player1;
    cout << "joueur 2 :" << endl;
    cin >> player2;
    cout << endl;
    cout << player1 << " vous avez " << familyMember1 << " memebres dans votre famille" << endl;
    cout << player2 << " vous avez " << familyMember2 << " memebres dans votre famille" << endl;
    while ((numberOfTurn<0) || (numberOfTurn>15))
        {
        cout << "Combien de tours souhaitez-vous jouer ?" << endl;
        cin >> numberOfTurn;
            if (numberOfTurn<=0) {cout << "c'est impossible !" << endl;}
            else if (numberOfTurn>=15) {cout <<"ca va etre un peu long !" << endl;}
            /*
            je voudrais maintenant parer au probl�me suivant :
            si l'utilisateur entre un charact�re au lieu d'un entier dans
            le cin de la ligne 21 le programme plante
            Je voulais �crire la condition suivante genre :
            else if (numberOfTurn != int) {cout<<"entrez un nombre !"};
            mais je ne sait pas comment + pas trouv� sur le net !
            */
            else if (!(numberOfTurn<=0 || numberOfTurn>0)) {cout << "je n'ai pas compris"<<endl;}
        }
    cout << endl << endl << "Agricolons donc pendant " << numberOfTurn << "tours !" << endl << endl << endl;

    // BOUCLES DE TOURS

    for (int i=0; i<numberOfTurn; ++i)
    {
        // remplissage du plateau.
        fillingOfTheGameBoard ();

        /*  bloucle d'actions
            jusqu'� ce qu'un des deux joueurs n'ai plus
            d'action dispo : familyMember=0 */
        while (familyMember1>0 && familyMember2>0)
        {
            cout << player1 << " c'est votre tour :" << endl;
            do {
                cout << endl << endl << "entrez une commande (si vous ne savez pas quoi faire, tapez help)" << endl;
                cin >> action;
                if (action == "help") {help();} // ce double == m'en aura fait baver : 2heures de recherche pour trouver l'erreur !!!
                else if (action == "quit") {quit();}
                else if (action == "end") {end();}
                else if (action == "print") {print();}
                else if (action == "pocket") {pocket();}
                else if (action == "go") {
                    cout<<"choix de la case :"<<endl;
                    cin >> choixCase;   /*  Il manque la boucle et condition pour
                                            tous les choixCase diff�rents de 1 � 7   */
                    go(choixCase);}
                else {cout << "Commande invalide" <<endl;}
                } while (action != "go");
            --familyMember1; // on "supprime un membre de la famille du joueur 1
            // v�rification de la bonne d�cr�mentation de familyMember1
            cout << endl << player1 << " il vous reste " << familyMember1 << " actions !" << endl << endl;
            cout << player2 << " c'est votre tour :" << endl;
            do {
                cout << endl << endl << "entrez une commande (si vous ne savez pas quoi faire, tapez help)" << endl;
                cin >> action;
                if (action == "help") {help();}
                else if (action == "quit") {quit();}
                else if (action == "end") {end();}
                else if (action == "print") {print();}
                else if (action == "pocket") {pocket();}
                else if (action == "go") {
                    cout<<"choix de la case :"<<endl;
                    cin >> choixCase;   /*  Il manque la boucle et condition pour
                                            tous les choixCase diff�rents de 1 � 7   */
                    go(choixCase);}
                else {cout << "Commande invalide" <<endl;}
                } while (action != "go");
            --familyMember2; // on "supprime un membre de la famille du joueur 2
            // v�rification de la bonne d�cr�mentation de familyMember2
            cout << endl << player2 << " il vous reste " << familyMember2 << " actions !" << endl << endl;
        }
        /*  Lorsque l'un des joueurs n'a plus d'action
            l'autre joueur poss�de sa propre boucle*/
        while (familyMember1==0 && familyMember2>0)
                        {
                            cout << player1 <<" vous n'avez plus d'action" << endl;
                            cout << player2 << " c'est votre tour :" << endl;
                            do {
                                cout << endl << endl << "entrez une commande (si vous ne savez pas quoi faire, tapez help)" << endl;
                                cin >> action;
                                if (action == "help") {help();}
                                else if (action == "quit") {quit();}
                                else if (action == "end") {end();}
                                else if (action == "print") {print();}
                                else if (action == "pocket") {pocket();}
                                else if (action == "go") {
                                    cout<<"choix de la case :"<<endl;
                                    cin >> choixCase;   /*  Il manque la boucle et condition pour
                                                            tous les choixCase diff�rents de 1 � 7   */
                                    go(choixCase);}
                                else {cout << "Commande invalide" <<endl;}
                                } while (action != "go");
                            --familyMember2; // on "supprime un membre de la famille du joueur 2
                            // v�rification de la bonne d�cr�mentation de familyMember2
                            cout << endl << player2 << " il vous reste " << familyMember2 << " actions !" << endl << endl;
                        }
        while (familyMember2==0 && familyMember1>0)
                        {
                            cout << player2 <<" vous n'avez plus d'action" << endl;
                            cout << player1 << " c'est votre tour :" << endl;
                            do {
                                cout << endl << endl << "entrez une commande (si vous ne savez pas quoi faire, tapez help)" << endl;
                                cin >> action;
                                if (action == "help") {help();}
                                else if (action == "quit") {quit();}
                                else if (action == "end") {end();}
                                else if (action == "print") {print();}
                                else if (action == "pocket") {pocket();}
                                else if (action == "go") {
                                    cout<<"choix de la case :"<<endl;
                                    cin >> choixCase;   /*  Il manque la boucle et condition pour
                                                            tous les choixCase diff�rents de 1 � 7   */
                                    go(choixCase);}
                                else {cout << "Commande invalide" <<endl;}
                                } while (action != "go");
                            --familyMember1; // on "supprime un membre de la famille du joueur 1
                            // v�rification de la bonne d�cr�mentation de familyMember1
                            cout << endl << player1 << " il vous reste " << familyMember1 << " actions !" << endl << endl;
                        }
        if (familyMember1==0 && familyMember2==0)
                        {
                            cout << player1 << ", " << player2 << " les membres de vos familles respectives sont epuises" << endl;
                            cout << "Allons dormir !" << endl << "fin du tour " << i+1 << endl;
                        }
        // restauration des membres de la famille, j'inverse ici les valeurs pour tester le programme sur 2 tours de jeu.
        familyMember1 += 3;
        familyMember2 += 1;
        /*  lors du rajout de l'action naissance il faudra
            un truc genre
            familyMember == RealfamilyMember
            ou RealFamilyMember est une variable que seul la
            fonction naissance () peut modifier     */
    }


// une fonction score ici


    cout <<"fin du programme";
    return 0;
}
