#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Nama_WIFI";
const char* password = "Password_WIFI";
const char* serverUrl = "http://alamat_server.com/data_receiver";

void setup() {
  Serial.begin(115200);
  // Menghubungkan ke jaringan WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Konfigurasi pin sensor
  // Contoh: PinSensorVoltage = 34;
  //         PinSensorAmpere = 35;

  // Inisialisasi koneksi HTTPClient
  HTTPClient http;
  http.begin(serverUrl);  // Tentukan alamat server untuk mengirim data

  // Loop pengumpulan data sensor
  while (true) {
    // Baca data dari sensor
    float voltage = readVoltage(); // Fungsi untuk membaca tegangan
    float ampere = readAmpere();   // Fungsi untuk membaca ampere
    String timestamp = getTimeStamp(); // Fungsi untuk mendapatkan stempel waktu
    String deviceID = "TV"; // ID perangkat, dapat diubah sesuai kebutuhan

    // Persiapkan data untuk dikirim
    String postData = "voltage=" + String(voltage) + "&ampere=" + String(ampere) + "&timestamp=" + timestamp + "&deviceID=" + deviceID;

    // Kirim data ke server
    int httpResponseCode = http.POST(postData);
    if (httpResponseCode > 0) {
      Serial.print("Data terkirim dengan kode respons: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Gagal mengirim data. Kode respons: ");
      Serial.println(httpResponseCode);
    }

    // Tunggu sebelum pengumpulan data selanjutnya
    delay(60000); // Misalnya, pengumpulan data setiap menit
  }

  // Tutup koneksi HTTPClient
  http.end();
}

float readVoltage() {
  // Baca tegangan dari sensor
  // Implementasi sesuai dengan spesifikasi sensor
}

float readAmpere() {
  // Baca ampere dari sensor
  // Implementasi sesuai dengan spesifikasi sensor
}

String getTimeStamp() {
  // Dapatkan stempel waktu saat ini
  // Implementasi sesuai dengan spesifikasi mikrokontroler atau modul waktu yang digunakan
}
