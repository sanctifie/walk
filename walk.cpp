#include <bits/stdc++.h>
using namespace std;

// chemin à l'entré
char S[10000];

// matrice
bool mat[10][10];

// le résultat
char result[10000];

//  nous appliquer une première recherche
bool shortest(char* S, int valeur)
{
	result[0] = valeur + '0';
	for (int i = 1; S[i]; i++) {

		// parcourir le graphe extérieur
		if (mat[valeur][S[i] - 'A'] || mat[S[i] -
							'A'][valeur]) {
			valeur = S[i] - 'A';
		}

		// parcourir le graphe intérieur
		else if (mat[valeur][S[i] - 'A' + 5] ||
				mat[S[i] - 'A' + 5][valeur]) {
			valeur = S[i] - 'A' + 5;
		}

		// retouner faux si la condition n'est pas reunie
		else
			return false;

		result[i] = valeur + '0';
	}

	return true;
}

// driver code
int main()
{
	// utilisation d'une matrice pour faire la connexion entre les noeuds

	mat[0][1] = mat[1][2] = mat[2][3] = mat[3][4] =
	mat[4][0] = mat[0][5] = mat[1][6] = mat[2][7] =
	mat[3][8] = mat[4][9] = mat[5][7] = mat[7][9] =
	mat[9][6] = mat[6][8] = mat[8][5] = true;

	// vérification du chemin
	char S[] = "ABB";

	if (shortest(S, S[0] - 'A') ||
		shortest(S, S[0] - 'A' + 5)) {
		cout << result;
	} else {
		cout << "-1";
	}
	return 0;
}
