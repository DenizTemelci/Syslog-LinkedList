#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Syslog verilerini tutacak Tek Yönlü Baðlý Liste (Singly Linked List) yapýsý
typedef struct Node {
    char log_mesaji[256]; // Log metnini tutan deðiþken
    struct Node* next;    // Bir sonraki loga iþaret eden gösterici (pointer)
} Node;

Node* head = NULL; // Listenin baþý baþlangýçta boþ

// 2. Okunan logu listeye ekleme fonksiyonu
void log_ekle(char* mesaj) {
    // Yeni bir düðüm (node) için hafýzada yer ayýrýyoruz
    Node* yeni_dugum = (Node*)malloc(sizeof(Node));
    strcpy(yeni_dugum->log_mesaji, mesaj);
    yeni_dugum->next = NULL;

    // Eðer liste boþsa, ilk eleman yapýyoruz
    if (head == NULL) {
        head = yeni_dugum;
        return;
    }

    // Liste boþ deðilse, en sona gidip ekliyoruz
    Node* gecici = head;
    while (gecici->next != NULL) {
        gecici = gecici->next;
    }
    gecici->next = yeni_dugum;
}

// 3. Listedeki loglarý ekrana yazdýrma fonksiyonu
void loglari_goster() {
    Node* gecici = head;
    printf("\n--- SISTEM GUNLUKLERI (SYSLOG) ---\n");
    while (gecici != NULL) {
        printf("%s", gecici->log_mesaji);
        gecici = gecici->next; // Bir sonraki loga geç
    }
    printf("----------------------------------\n");
}

int main() {
    // syslog.txt dosyasýný okuma modunda (r) açýyoruz
    FILE* dosya = fopen("syslog.txt", "r");
    if (dosya == NULL) {
        printf("Hata: syslog.txt dosyasi bulunamadi!\n");
        return 1;
    }

    char satir[256];
    // Dosyadaki her bir satýrý okuyup baðlý listeye ekliyoruz
    while (fgets(satir, sizeof(satir), dosya)) {
        log_ekle(satir);
    }
    fclose(dosya); // Dosyayý kapatýyoruz

    // Baðlý listeye kaydedilen loglarý ekrana yazdýrýyoruz
    loglari_goster();

    return 0;
}
