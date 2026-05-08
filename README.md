# Arduino MotoGP Racer / F1 Driver List

Proyek Arduino ini menampilkan daftar pembalap F1 pada modul LCD I2C dan memungkinkan pengguna untuk menavigasi antar entri menggunakan tiga tombol.

## Fitur

- Tampilan menu awal pada LCD 16x2
- Navigasi maju dan mundur antar nama pembalap F1
- Tombol menu awal untuk kembali ke layar awal
- Konfigurasi untuk Arduino Uno

## Komponen Utama

- Arduino Uno
- LCD I2C 16x2 (alamat I2C `0x27`)
- 3 tombol tekan (push button)

## Pin Koneksi

- `button1` (Maju) = pin digital 4
- `button2` (Mundur) = pin digital 2
- `button3` (Menu Awal) = pin digital 3

## Keterangan Kode

- `src/main.cpp` berisi logika utama.
- `LiquidCrystal_I2C` digunakan untuk mengendalikan LCD.
- Tombol terhubung ke input internal pull-up, sehingga ditekan berarti `LOW`.
- Data ditampilkan dari array `tim[]` dan `pembalap[]`.

## Instalasi dan Build

1. Buka proyek ini di PlatformIO.
2. Pastikan board `uno` sudah dipilih.
3. Kompilasi dan upload kode ke Arduino.

## Dependensi

Digunakan library berikut di `platformio.ini`:

- `marcoschwartz/LiquidCrystal_I2C@^1.1.4`
- `z3t0/IRremote@^4.7.1`

> Catatan: Saat ini kode utama tidak memanfaatkan fitur IR remote.

## Penggunaan

1. Nyalakan Arduino dan LCD akan menampilkan:
   - `Daftar Nama`
   - `Pembalap F1`
2. Tekan tombol `Maju` untuk melihat entri berikutnya.
3. Tekan tombol `Mundur` untuk kembali ke entri sebelumnya.
4. Tekan tombol `Menu Awal` untuk kembali ke layar awal.

## Perluasan

Proyek ini dapat dikembangkan dengan menambahkan:

- input IR remote untuk navigasi jarak jauh
- LED indikator status
- daftar pembalap tambahan atau informasi balapan lainnya
- dukungan layar LCD yang lebih besar atau tampilan grafis
