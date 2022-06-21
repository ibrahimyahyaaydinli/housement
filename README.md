# Housement

BTÜ BLM0324 Yazılım Mühendisliği dönem projesi.

## Proje Amacı

Bu proje basit bir akıllı ev sisteminin uygulanmasıdır. Projede evde bulunan bir cihaz (mikrodenetleyici) ile internete veriler yüklenecek ve mobil uygulama üzerinden bu veriler görüntülenebilecektir. Ayrıca mobil uygulama üzerinden verilen komutlarla da evdeki cihaz kontrol edilebilecektir.

## Takım Üyelerinin Yetkinlikleri ve Görevleri

* [Ali Cüneyt Çağlar](https://github.com/CuneytCaglar)

React ve Firebase kullanarak müşterileri web üzerinden kayıt etme.

* [Ali Furkan Demir](https://github.com/AliFurkanDemir)

Frontend tarafında React Native, Backend tarafında Node.js kullanılarak app geliştirme ve uygulama yapımından sorumludur.

* [Ayşenur Erkin](https://github.com/Aysenur-Erkin)

Mobil uygulama tasarımı. Devre kurulumu ve ESP32 yazılımı.

* [Bilal Çalık](https://github.com/Bilalcalik)

* [Ceyhun Şen](https://github.com/ceyhunsen)

Gömülü ve IOT sistemler üzerine çalışmaktadır. Projede akıllı cihazın firmware'ini yazmaktan ve dokümante etmekten sorumludur.

* [Enes Şahin](https://github.com/enessahin450)

Hikaye kartı ve kullanım kılavuzu yazımı. Mobil uygulama destek sağlanacak.

* [İbrahim Yahya Aydınlı](https://github.com/ibrahimyahyaaydinli) (iletişim sorumlusu)

Frontend ve backend geliştiricisidir.React native ile frontend tarafı geliştirilecek olan projenin backend tarafı da node.js ile geliştirildikten sonra firebase ile uygulamanın arasında veri alışverişinin sağlanmasını gerçekleştirecektir.

## Kullanılacak Yazılımlar/Donanımlar

### Yazılım

Mobil uygulama için React Native UI framework kullanılacaktır. Sunucu tarafı Node.js ile yazılacak olup, veritabanı olarak Google'ın geliştirmiş olduğu ve  real-time veri alışverişi gerçekleştirebileceğimiz Firebase kullanılacaktır.

ESP32, Arduino Core for ESP32 ile kodlanacaktır.

### Donanım

Akıllı cihaz için ESP32 WROOM-32U mikrodenetleyicisi kullanılacaktır. Ayrıca verilerin ölçülebilmesi için ise BME680 sensörü, ışık kontrolünün gösterilebilmesi için led ve alarm için buzzer kullanılacaktır.

Akıllı cihazdan gelen verilerin görüntülenebilmesi için mobil telefon gereklidir.

## Yazılım Geliştirme Süreci

Yazılım geliştirme süreci olarak artırımlı (incremental) ekstrem programlama (XP) belirlenmiştir.

## Broşür ve Kullanım Kılavuzu

Broşür ve kullanım kılavuzuna [buradan](documents/) ulaşabilirsiniz.
