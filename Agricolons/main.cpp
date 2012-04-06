/*
 * Agricolons is a boardgame
 * This is stage one of developpement
 * For now, the program is for the consol and for two players.
 */

#include <iostream>
#include <string>

using namespace std;

/* The fonctions
 * In fine, the fonctions will be together in another file.
 * For now the fct are just here to run the program, they return only a cout. */

void fillingOfTheGameBoard () // Fonction de remplissage du plateau
    {
        cout << "remplissage du plateau effectue !" << endl;
    }

void actionTurn () // Fonction du tour de jeu.
    {
       do
        {
            cout << endl << endl << "entrez une commande (si vous ne savez pas quoi faire, tapez help)" << endl;
            cin >> action;
            if (action == "help") {help();}
            else if (action == "quit") {quit();}
            else if (action == "end") {end();}
            else if (action == "print") {print();}
            else if (action == "pocket") {pocket();}
            else if (action == "go")
            {
                cout<<"choix de la case :"<<endl;
                cin >> choixCase;   /*  Il manque la boucle et condition pour tous les choixCase différents de 1 à 7   */
                go(choixCase);
            }
            else {cout << "Commande invalide" <<endl;}

        } while (action != "go" || action != "end" && yon == "yes");
    }

void help ()
    {
        cout << "les commandes possibles sont :" << endl;
        cout << "help" << endl << "quit" << endl << "end" << endl << "print" << endl << "pocket" << endl << "go" << endl;
    }

void quit ()
    {
        cout << "merci d'avoir joué à Agricolons" << endl;
        break;
    }

void end ()
    {
        string yon = "no";
        while (yon != "yes")
        {
            cout << "Ceci mettra fin à votre tour, etes-vous sur ? (yes / no)" << endl;
            cin >> a;
            if (yon == "yes")
            {
                cout << endl << "Votre personnage va donc faire la sieste !";

            }
            else if (yon == "no")
            {
                cout << "Retournez donc au travail !";
                break;
            }
            else {cout << "Commande invalide";}
        }
    }

void print ()
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "PLATEAU CENTRAL :" << endl;
        cout << "=================" << endl << endl;
        cout << "Case 0 : Recolte du bois      : " << wood1 << " bois disponibles (" << freeSquare0 << ")" << endl;
        cout << "Case 1 : Recolte du ble       : " << wheat1 << " Blé disponible (" << freeSquare1 << ")" << endl;
        cout << "Case 2 : Recolte de pierre    : " << stone1 << " Pierre diponible (" << freeSquare2 << ")" << endl;
        cout << "Case 3 : Recolte de 1 legume  : " << vegetable1 << " legume disponible (" << freeSquare3 << ")" << endl;
        cout << "Case 4 : Recolte de roseaux   : " << reed1 << " roseaux disponibles (" << freeSquare4 << ")" << endl;
        cout << "Case 5 : Labourer ! (" << freeSquare5 << ")" << endl;
        cout << "Case 6 : Construction ! (" << freeSquare6 << ")" << endl;
        cout << "Case 7 : Naissance ! (" << freeSquare7 << ")" << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << player1 << "------------------------------" << player2 << endl;
        cout << "Bois    : " << numberOfWood1 << "--------------------" << "Bois    : " << numberOfWood2 << endl;
        cout << "Argile  : " << numberOfClay1 << "--------------------" << cout << "Argile  : " << numberOfClay2 << endl;
        cout << "Pierre  : " << numberOfStone1 << "--------------------" << cout << "Pierre  : " << numberOfStone2 << endl;
        cout << "Roseaux : " << numberOfReed1 << "--------------------" << cout << "Roseaux : " << numberOfReed2 << endl;
        cout << "Ble     : " << numberOfWheat1 << "--------------------" << cout << "Ble     : " << numberOfWheat2 << endl;
        cout << "Legume  : " << numberOfVegetable1 << "--------------------" << cout << "Legume  : " << numberOfVegetable2 << endl;
        cout << "PN  : " << pn1 << "--------------------" << cout << "PN  : " << pn2 << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << player1 << "------------------------------" << player2 << endl;
        cout << house1 << " : " << numberOfHouse1 << "--------------------" << house2 << " : " << numberOfHouse2 << endl;
        cout << "Champs labourés : " << plowedField1 << "--------------------" << "Champs labourés : " << plowedField2 << endl;
        cout << "Champs semés    : " << sownField1 << "--------------------" << "Champs semés    : " << sownField2 << endl;

    }

void pocket ()
    {
        cout << "Vous n'avez rien dans les poches dsl" << endl;
    }

void go (int x=0)
    {
        if (x>=0) {cout << "Votre personnage part travaille" << endl;}
        else {cout << "Votre personnage part travaille" << endl;}
    }

int main()
{
    //création des différentes variables du programme

    int numberOfTurn(-1), choixCase(0), familyMember1(1), familyMember2(3);
    int wood (0), wheat (0), stone(0), clay(0), vegetable(0), reed(0);
    int numberOfWood1 (0), numberOfClay1 (0), numberOfStone1 (0), numberOfReed1 (0), numberOfWheat1 (0), numberOfVegetable1 (0), pn1 (2);
    int numberOfWood2 (0), numberOfClay2 (0), numberOfStone2 (0), numberOfReed2 (0), numberOfWheat2 (0), numberOfVegetable2 (0), pn2 (2);
    int numberOfHouse1 (2), numberOfHouse2 (2), plowedField1 (0), plowedField2 (0), sownField1 (0), sownField2 (0);

    string house1 ("Cabane en bois"), house2 ("Cabane en bois");
    string freeSquare1 ("Libre"), freeSquare2 ("Libre"), freeSquare3 ("Libre"), freeSquare4 ("Libre");
    string freeSquare5 ("Libre"), freeSquare6 ("Libre"), freeSquare7 ("Libre"), freeSquare8 ("Libre");
    string player1("joueur1"), player2("Joueur2"), action;

    // Présentation, choix des pseudos et nombre de tours
    cout << "AGRICOLONS" << endl << endl;
    cout << "Choix des pseudos :" << endl;
    cout << "Joueur 1 :" << endl;
    cin >> player1;
    cout << "joueur 2 :" << endl;
    cin >> player2;
    cout << endl;
    cout << player1 << " vous avez " << familyMember1 << " membres dans votre famille" << endl;
    cout << player2 << " vous avez " << familyMember2 << " membres dans votre famille" << endl;

    while ((numberOfTurn<0) || (numberOfTurn>15))
    {
        cout << "Combien de tours souhaitez-vous jouer ?" << endl;
        cin >> numberOfTurn;
        if (numberOfTurn<=0) {cout << "c'est impossible !" << endl;}
        else if (numberOfTurn>=15) {cout <<"ca va etre un peu long !" << endl;}
        else if (!(numberOfTurn<=0 || numberOfTurn>0)) {cout << "je n'ai pas compris" << endl;}
    }
    cout << endl << endl << "Agricolons donc pendant " << numberOfTurn << " tours !" << endl << endl << endl;


    for (int i=0; i<numberOfTurn; ++i) // BOUCLES DE TOURS
    {
        // remplissage du plateau.
        fillingOfTheGameBoard ();

        /*  bloucle d'actions
            jusqu'à ce qu'un des deux joueurs n'ai plus
            d'action dispo : familyMember=0 */
        while (familyMember1>0 && familyMember2>0)
        {
            cout << player1 << " c'est votre tour :" << endl;

            actionTurn ();

            --familyMember1; // on "supprime un membre de la famille du joueur 1

            cout << endl << player1 << " il vous reste " << familyMember1 << " actions !" << endl << endl;

            cout << player2 << " c'est votre tour :" << endl;

            actionTurn ();

            --familyMember2; // on "supprime un membre de la famille du joueur 2
            cout << endl << player2 << " il vous reste " << familyMember2 << " actions !" << endl << endl;
        }

        //  Lorsque l'un des joueurs n'a plus d'action l'autre joueur possède sa propre boucle
        while (familyMember1==0 && familyMember2>0)
        {
            cout << player1 <<" vous n'avez plus d'action" << endl;
            cout << player2 << " c'est votre tour :" << endl;

            actionTurn ();

            --familyMember2; // on "supprime un membre de la famille du joueur 2
            cout << endl << player2 << " il vous reste " << familyMember2 << " actions !" << endl << endl;
        }

        while (familyMember2==0 && familyMember1>0)
        {
            cout << player2 <<" vous n'avez plus d'action" << endl;
            cout << player1 << " c'est votre tour :" << endl;

            actionTurn ();

            --familyMember1; // on "supprime un membre de la famille du joueur 1
            cout << endl << player1 << " il vous reste " << familyMember1 << " actions !" << endl << endl;
                        }
        //if (familyMember1==0 && familyMember2==0)
        //{
            cout << player1 << ", " << player2 << " les membres de vos familles respectives sont epuises" << endl;
            cout << "Allons dormir !" << endl << "fin du tour " << i+1 << endl;
        //}

        // restauration des membres de la famille, j'inverse ici les valeurs pour tester le programme sur 2 tours de jeu.
        familyMember1 += 3;
        familyMember2 += 1;
        /*  lors du rajout de l'action naissance il faudra
            un truc genre
            familyMember = RealfamilyMember
            ou RealFamilyMember est une variable que seule la
            fonction naissance () peut modifier     */
    }


// une fonction score ici


    cout <<"fin du programme";
    return 0;
}
