#include <iostream>
using namespace std;

class bidangDatar {
private:
    int x; // variabel untuk menyimpan input dari lingkaran maupun bujursangkar

public:
    bidangDatar() { // constructor
        x = 0;
    }

    virtual void input() = 0; // fungsi yang menerima input dan mengirim input melalui fungsi setX untuk disimpan di x
    virtual float Luas() = 0; // fungsi untuk menghitung luas
    virtual float Keliling() = 0; // fungsi untuk menghitung keliling
    void setX(int a) { // fungsi untuk memberi/mengirim nilai pada x
        this->x = a;
    }

    int getX() { // fungsi untuk membaca/mengambil nilai dalam x
        return x;
    }
};

class Lingkaran : public bidangDatar {
public:
    void input() {
        cout << "Lingkaran dibuat" << endl;
        cout << "Masukkan jejari: ";
        int jejari;
        cin >> jejari;
        setX(jejari);
    }

    float Luas() {
        return 3.14 * getX() * getX();
    }

    float Keliling() {
        return 2 * 3.14 * getX();
    }
};


class Bujursangkar : public bidangDatar {
public:
    void input() {
        cout << "\nBujursangkar dibuat" << endl;
        cout << "Masukkan sisi: ";
        int sisi;
        cin >> sisi;
        setX(sisi);
    }

    float Luas() {
        return getX() * getX();
    }

    float Keliling() {
        return 4 * getX();
    }
};


int main() {
    bidangDatar* obj;

    obj = new Lingkaran();
    obj->input();
    cout << "Luas Lingkaran = " << obj->Luas() << endl;
    cout << "Keliling Lingkaran = " << obj->Keliling() << endl;

    obj = new Bujursangkar();
    obj->input();
    cout << "Luas Bujursangkar = " << obj->Luas() << endl;
    cout << "Keliling Bujursangkar = " << obj->Keliling() << endl;

    delete obj;

    return 0;
}