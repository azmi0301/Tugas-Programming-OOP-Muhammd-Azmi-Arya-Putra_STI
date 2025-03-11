#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Mahasiswa;

class Kursus {
private:
    std::string nama;
    int kapasitas_maks;
    std::vector<Mahasiswa*> daftar_mahasiswa;
    std::vector<Mahasiswa*> daftar_gagal;
public:
    Kursus(std::string nama, int kapasitas) : nama(nama), kapasitas_maks(kapasitas) {}

    bool daftarMahasiswa(Mahasiswa* mahasiswa);
    void tampilkanMahasiswa();
    void tampilkanMahasiswaGagal();
    std::string getNama() { return nama; }
};

class Mahasiswa {
private:
    std::string nama;
public:
    Mahasiswa(std::string nama) : nama(nama) {}
    std::string getNama() { return nama; }
};

bool Kursus::daftarMahasiswa(Mahasiswa* mahasiswa) {
    if (daftar_mahasiswa.size() < kapasitas_maks) {
        daftar_mahasiswa.push_back(mahasiswa);
        std::cout << "[SUKSES] " << mahasiswa->getNama() << " berhasil terdaftar di " << nama << "\n";
        return true;
    }
    else {
        std::cout << "[GAGAL] " << mahasiswa->getNama() << " tidak dapat mendaftar ke " << nama << " karena sudah penuh.\n";
        daftar_gagal.push_back(mahasiswa);
        return false;
    }
}

void Kursus::tampilkanMahasiswa() {
    std::cout << "\n=== Mahasiswa Terdaftar di " << nama << " ===\n";
    if (daftar_mahasiswa.empty()) {
        std::cout << "Tidak ada mahasiswa yang terdaftar.\n";
    }
    else {
        for (size_t i = 0; i < daftar_mahasiswa.size(); i++) {
            std::cout << i + 1 << ". " << daftar_mahasiswa[i]->getNama() << "\n";
        }
    }
    std::cout << "===============================\n";
}

void Kursus::tampilkanMahasiswaGagal() {
    std::cout << "\n=== Mahasiswa Gagal Mendaftar di " << nama << " ===\n";
    if (daftar_gagal.empty()) {
        std::cout << "Tidak ada mahasiswa yang gagal mendaftar.\n";
    }
    else {
        for (size_t i = 0; i < daftar_gagal.size(); i++) {
            std::cout << i + 1 << ". " << daftar_gagal[i]->getNama() << "\n";
        }
    }
    std::cout << "===============================\n";
}

int main() {
    Kursus kursus("Pemrograman C++", 3);

    Mahasiswa mhs1("azmi");
    Mahasiswa mhs2("gathan");
    Mahasiswa mhs3("umar");
    Mahasiswa mhs4("ariesta"); 

    std::cout << "\n=== Proses Pendaftaran ===\n";
    kursus.daftarMahasiswa(&mhs1);
    kursus.daftarMahasiswa(&mhs2);
    kursus.daftarMahasiswa(&mhs3);
    kursus.daftarMahasiswa(&mhs4); 

    kursus.tampilkanMahasiswa();
    kursus.tampilkanMahasiswaGagal();

    return 0;
}
