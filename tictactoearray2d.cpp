#include <iostream>
using namespace std;

struct tictactoe {
    string nama_pemain1, nama_pemain2;
    int baris, kolom;
};

void menampilkanteks() {
    cout << "+-------------------------+\n";
    cout << "| Nama : M. Agung Pratama |\n";
    cout << "| Kelas: A                |\n";
    cout << "| NIM  : 2300018005       |\n";
    cout << "+-------------------------+\n";
}
char papan[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

tictactoe pemain; 

void namaplayer() {
	cout << "Masukkan Nama Pemain 1: ";
    getline(cin, pemain.nama_pemain1);
    cout << "Masukkan Nama Pemain 2: ";
    getline(cin, pemain.nama_pemain2);
    cout << " \n";
    cout << " Nama Pemain 1 : " << pemain.nama_pemain1 << "  \n";
    cout << " Nama Pemain 2 : " << pemain.nama_pemain2 << "  \n";
}

void papantictactoe() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << papan[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "------------" << endl;
        }
    }
    cout << endl;
}

bool check(char papan[3][3], char simbolpemain) {
    for (int i = 0; i < 3; i++) {
        if (papan[i][0] == simbolpemain && papan[i][1] == simbolpemain && papan[i][2] == simbolpemain) {
            return true;
        }
        if (papan[0][i] == simbolpemain && papan[1][i] == simbolpemain && papan[2][i] == simbolpemain) {
            return true;
        }
    }
    if (papan[0][0] == simbolpemain && papan[1][1] == simbolpemain && papan[2][2] == simbolpemain) {
        return true;
    }
    if (papan[0][2] == simbolpemain && papan[1][1] == simbolpemain && papan[2][0] == simbolpemain) {
        return true;
    }
    return false;
}

bool papanfull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (papan[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void inv(char input) {
    cout << "Pemain " << input << " (" << ((input == 'X') ? pemain.nama_pemain1 : pemain.nama_pemain2) << ") masukkan baris (1-3): ";
    cin >> pemain.baris;
    cout << "Pemain " << input << " (" << ((input == 'X') ? pemain.nama_pemain1 : pemain.nama_pemain2) << ") masukkan kolom (1-3): ";
    cin >> pemain.kolom;

    pemain.baris--;
    pemain.kolom--;

    if (pemain.baris >= 0 && pemain.baris < 3 && pemain.kolom >= 0 && pemain.kolom < 3 && papan[pemain.baris][pemain.kolom] == ' ') {
        papan[pemain.baris][pemain.kolom] = input;
    } else {
        cout << "Langkah tidak valid. Silakan coba lagi.\n";
        inv(input);
    }
}

int main() {
	menampilkanteks(); 
    namaplayer();
    char namapemain = 'X';
	
    while (true) {
        papantictactoe();
        inv(namapemain);

        if (check(papan, namapemain)) {
            cout << "Pemain " << namapemain << " menang!\n";
            break;
        }

        if (papanfull()) {
            cout << "Permainan seri!\n";
            break;
        }

        namapemain = (namapemain == 'X') ? 'O' : 'X';
    }

    return 0;
}

