//DETA SARI ASLINA
//2217051117
//D

#include <iostream>
#include <ctime>
using namespace std;

template<typename T> 
class PenghitungUsia {
public:
    PenghitungUsia(T hari, T bulan, T tahun) : hari(hari), bulan(bulan), tahun(tahun) {}

    void setHari(T hariBaru);
    void setBulan(T bulanBaru);
    void setTahun(T tahunBaru);

    T getHari();
    T getBulan();
    T getTahun();

    void cetakUsia();
    int jumlahHari(int bulan, int tahun);
    bool isTahunKabisat(int tahun);

private:
    T hari;
    T bulan;
    T tahun;
};

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
        hari += jumlahHari(bulanSekarang, tahunSekarang);
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
