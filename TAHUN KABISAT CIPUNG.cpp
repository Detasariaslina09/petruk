#include <iostream>
using namespace std;

template <typename T>
class PerhitunganKabisat {
  private:
    T tahun;
  
  public:
    PerhitunganKabisat(T t) {
      tahun = t;
    }
    
    void setTahun(T t) {
      tahun = t;
    }
    
    T getTahun() {
      return tahun;
    }
    
    bool hitungKabisat() {
      if (tahun % 4 == 0) {
        if (tahun % 100 == 0) {
          if (tahun % 400 == 0) {
            return true;
          } else {
            return false;
          }
        } else {
          return true;
        }
      } else {
        return false;
      }
    }
};

int main() {
  int tahun;
  cout << "Masukkan tahun: ";
  cin >> tahun;
  
  PerhitunganKabisat<int> kabisat(tahun);
  
  if (kabisat.hitungKabisat()) {
    cout << tahun << " adalah tahun kabisat" << endl;
  } 
  else {
    cout << tahun << " bukan tahun kabisat" << endl;
  }
  
  return 0;
}

