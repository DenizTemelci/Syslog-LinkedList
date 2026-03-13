# Linux Syslog Okuyucu - Bağlı Liste Uygulaması

## Proje Amacı
Bu proje, Linux işletim sistemindeki sistem günlüklerini (syslog) okuyarak, dinamik bellek yönetimi sağlayan Tek Yönlü Bağlı Liste (Singly Linked List) veri yapısında tutan bir C programıdır.

## Neden Tek Yönlü Bağlı Liste Kullanıldı?
Log kayıtlarının sayısı önceden bilinemez ve sistem çalıştıkça sürekli artar. Sabit boyutlu diziler (array) kullanmak bellek israfına veya sınırların aşılmasına yol açar. Tek yönlü bağlı liste sayesinde her yeni gelen log, listenin sonuna anlık yer ayrılarak eklenir. Kronolojik akan log verileri için en ideal yapı budur.
