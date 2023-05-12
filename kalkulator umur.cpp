//DETA SARI ASLINA
//2217051117
//KELAS D
#include <iostream>
#include <ctime>
using namespace std;

template<typename T> class PenghitungUsia {
public:
    // Constructor
    PenghitungUsia(T hari, T bulan, T tahun) : hari(hari), bulan(bulan), tahun(tahun) {}

    // Setter
    void setHari(T hariBaru);
    void setBulan(T bulanBaru);
    void setTahun(T tahunBaru);

    // Getter
    T getHari();
    T getBulan();
    T getTahun();

    // Member function untuk menghitung usia berdasarkan tanggal lahir
    void cetakUsia();

    // Member function untuk menghitung jumlah hari dalam suatu bulan pada suatu tahun
    int jumlahHari(int bulan, int tahun);

    // Member function untuk memeriksa tahun kabisat
    bool isTahunKabisat(int tahun);

private:
    T hari;
    T bulan;
    T tahun;
};

template<typename T>
void PenghitungUsia<T>::setHari(T hariBaru)
{
    this->hari = hariBaru;
}

template<typename T>
void PenghitungUsia<T>::setBulan(T bulanBaru)
{
    this->bulan = bulanBaru;
}

template<typename T>
void PenghitungUsia<T>::setTahun(T tahunBaru)
{
    this->tahun = tahunBaru;
}

template<typename T>
T PenghitungUsia<T>::getHari() 
{
    return this->hari;
}

template<typename T>
T PenghitungUsia<T>::getBulan()
{
    return this->bulan;
}

template<typename T>
T PenghitungUsia<T>::getTahun()
{
    return this->tahun;
}

template<typename T>
void PenghitungUsia<T>::cetakUsia()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int tahunSekarang = 1900 + ltm->tm_year;
    int bulanSekarang = 1 + ltm->tm_mon;
    int hariSekarang = ltm->tm_mday;

    int tahun = tahunSekarang - this->tahun;
    int bulan = bulanSekarang - this->bulan;
    int hari = hariSekarang - this->hari;

    if (hari < 0) {
        --bulan;
        hari += 30;
    }

    if (bulan < 0) {
        --tahun;
        bulan += 12;
    }

    cout << "Usia Anda adalah " << tahun << " tahun " << bulan << " bulan " << hari << " hari" << endl;

}

template<typename T>
int PenghitungUsia<T>::jumlahHari(int bulan, int tahun)
{
    int hari[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isTahunKabisat(tahun) && bulan == 2) return hari[bulan-1]+1;
    
    return hari[bulan-1];
}

template<typename T>
bool PenghitungUsia<T>::isTahunKabisat(int tahun)
{
    int tahunQuery = tahun ? tahun : this->tahun;

    return tahunQuery % 4 == 0 && (tahunQuery % 100 != 0 || tahun % 400 == 0);
}
int main()
{

int hari, bulan, tahun;

    cout << "Masukkan tanggal, bulan, dan tahun lahir anda: ";
    cin >> hari >> bulan >> tahun;

    PenghitungUsia<int> person(hari, bulan, tahun);
    person.cetakUsia();
}

