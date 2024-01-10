#include <stdio.h>
#include <string.h>

char Kullaniciadi[20];
char Sifre[20];
FILE *dosya;

void UyeOl() {
    printf("Kullanici Adinizi Giriniz: ");
    scanf("%s", Kullaniciadi);

    printf("Sifrenizi Giriniz: ");
    scanf("%s", Sifre);

    dosya = fopen("Kullanici_Bilgileri.txt", "a");

    if (dosya == NULL) {
        printf("Islem Gerceklestirilirken hata meydana geldi!");
    } else {
        fprintf(dosya, "%s %s\n", Kullaniciadi, Sifre);
        fclose(dosya);
        printf("Uye olma islemi tamamlandi.\n");
    }
}

int GirisYap() {
    char girilenKullaniciadi[20];
    char girilenSifre[20];
    dosya = fopen("Kullanici_Bilgileri.txt", "r");

    if (dosya == NULL) {
        printf("Dosya acilirken hata meydana geldi!\n");
        return -1; // Dosya açma hatası
    }

    printf("Kullanici Adinizi Giriniz: ");
    scanf("%s", girilenKullaniciadi);

    printf("Sifrenizi Giriniz: ");
    scanf("%s", girilenSifre);

    // Dosyadan veri okuma ve karşılaştırma
    while (fscanf(dosya, "%s %s", Kullaniciadi, Sifre) == 2) {
        if (strcmp(girilenKullaniciadi, Kullaniciadi) == 0 && strcmp(girilenSifre, Sifre) == 0) {
            fclose(dosya);
            printf("Giris Islemi Basarili\n");
            break;
        }
    
    }
    fclose(dosya);
    printf("Hatali Kullanici Adi Ya da Sifre\n");

}
    

int main(){
    int secim;
    while (1)
    {
        printf("Uye Ol (1)\nUye Girisi (2)\nSeciminizi yapiniz: ");
        scanf("%d",&secim);
        switch (secim)
        {
        case 1:
            UyeOl();
            break;
        case 2:
            GirisYap();
            break;
        default:
            printf("Lutfen Gecerli Bir Islem Yapiniz");
            break;
        }

    }
    return 0;
}