#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int hesaptarzi, i, j, k, temp, sayikontrol, carpim = 1;
    int sayilar[6], hedef, sayac = 0;

    srand(time(NULL));  //Random geelen sayýlarýn her seferinde farklý gelmesi için

    //Bu kýsýmda iþlemlerin nasýl hangi türde yapýlacagýný soruyor
    do{

    printf("****Hesap Turu Nasil Olsun****\n");
    printf("1.Sayilari Rasgele Gir\n");
    printf("2.Sayilari Elle Gir\n");
    scanf("%d", &hesaptarzi);

    }while (hesaptarzi>2 || hesaptarzi<1);

    //5 tane 1 ile 9 arasýnda sayý atýyoruz
    if(hesaptarzi == 1){
        for(i=0; i<=4; i++){
            sayilar[i] = rand() % 9 + 1;
        }

        //Ulaþmak istediðimiz sayýyý belirliyoruz
        hedef = rand() % 900 + 100;

        //Ýki basamaklý sayýmýzý belirliyor
        do{
            sayilar[5] = rand() % 98 + 10;
            sayikontrol = sayilar[5] % 10;
        }while (sayikontrol != 0);
    }
    if(hesaptarzi == 2){
        do{
            sayac = 0;
            for(i=0; i<5; i++){
                printf("%d. Sayiyi Giriniz(1-9): ", i+1);
                scanf("%d", &sayilar[i]);
                fflush(stdin);
                if(sayilar[i]>=10 || sayilar[i]<=0)
                    sayac++;
            }
            printf("6. Sayiyi Giriniz(10un Katlari 10-90): ");
            scanf("%d", &sayilar[5]);
            fflush(stdin);

            if(sayilar[5] % 10 != 0)
                sayac++;

            printf("Hedef Sayiyi Giriniz(100un Katlari 100-999): ");
            scanf("%d", &hedef);
            fflush(stdin);

                if(hedef <= 100 || hedef >= 999)
                    sayac++;

            if(sayac > 0)
                printf("Istenilen Turde Veri Alinamadi. Tekrar Deneyiniz.\n");
        }while(sayac>0);
    }

        //Rasgele gelen sayýlarý ekrana yazdýrýyoruz
        for(i=0; i<=5; i++){
            printf("%d. Sayi: %d\n", i+1, sayilar[i]);
        }
        printf("\nHedef Sayi: %d \n", hedef);

        //Sayýlarýn hepsini çarpýyor
        for(i=0; i<=5; i++){
            carpim *= sayilar[i];
        }
        //Sayýlarýn çarpýmý hedeften küçükmü deðil mi kontrol ediyor
        if(carpim < hedef){
            printf("Bu sayilarla hefedlenen sayi bulunamaz\n");
            exit(1);
        }

        //Bubble Sort - Küçükten büyüðe
        for(i=0; i<6; i++){
            for(j=0; j<5; j++){
                if(sayilar[j] > sayilar[j+1]){
                    temp = sayilar[j];
                    sayilar[j] = sayilar[j+1];
                    sayilar[j+1] = temp;
                }
            }
        }

        //Ýþlem Kýsýmlarý
        int kalan = 0, bolum = 0, bolumTut = 0, kalanTut = 0, sonuc = 0;

        //Bu kýsýmda bölüm ve kalaný buluyoruz çünkü bölen*bölüm+kalan cevabýmýz
        bolum = hedef / sayilar[5];
        printf("Bolumu bulmak icin: %d / %d = %d \n", hedef, sayilar[5], bolum);
        kalan = hedef % sayilar[5];
        printf("Kalani bulmak icin: %d %% %d = %d \n", hedef, sayilar[5], kalan);

        //Girilen sayýlar içerisinde bölüm var mý bakýyoruz
        for(i=0; i<6; i++){
            if(sayilar[i] == bolum){
                bolumTut = sayilar[i];
                sonuc = bolumTut * sayilar[5];
                printf("%d * %d = %d \n", bolumTut, sayilar[5], sonuc);
                break;
            }
        }

        //Girilen sayýlar içerisinde bölüm yoksa 1.sayýyý diðerleriyle 2. sayýyý diðerleriyle boyle boyle topluyoruz toplamlarýnda var mý diye
        if(bolumTut != bolum){
                bolumTut = 0;
            for(i=0; i<6; i++){
                if(bolumTut == bolum)
                    break;
                for(j=0; j<6; j++){
                    bolumTut = sayilar[i] + sayilar[j];
                    if(bolumTut == bolum){
                        printf("%d + %d = %d \n", sayilar[i], sayilar[j], bolumTut);
                        sonuc = bolumTut*sayilar[5];
                        printf("%d * %d = %d\n", bolumTut, sayilar[5], sonuc);
                        break;
                    }
                }
            }
        }

        //Girilen sayýlari üçlü toplayarak
        if(bolumTut != bolum){
                bolumTut = 0;
            for(i=0; i<6; i++){
                    if(bolumTut == bolum)
                        break;
                for(j=0; j<6; j++){
                    if(bolumTut == bolum)
                        break;
                    for(k=0; k<6; k++){
                        bolumTut = sayilar[i] + sayilar[j] + sayilar[k];
                        if(bolumTut == bolum){
                            printf("%d + %d + %d = %d \n", sayilar[i], sayilar[j], sayilar[k], bolumTut);
                            sonuc = bolumTut*sayilar[5];
                            printf("%d * %d = %d\n", bolumTut, sayilar[5], sonuc);
                            break;
                        }
                    }
                }
            }
        }

        //Girilen sayýyý ikili çarparak
        if(bolumTut != bolum){
                bolumTut = 0;
            for(i=0; i<6; i++){
                if(bolumTut == bolum)
                    break;
                for(j=0; j<6; j++){
                    bolumTut = sayilar[i] * sayilar[j];
                    if(bolumTut == bolum){
                        printf("%d * %d = %d \n", sayilar[i], sayilar[j], bolumTut);
                        sonuc = bolumTut*sayilar[5];
                        printf("%d * %d = %d\n", bolumTut, sayilar[5], sonuc);
                        break;
                    }
                }
            }
        }

        //Girilen sayýyý ikili çýkararak
        if(bolumTut != bolum){
            bolumTut = 0;
            for(i=0; i<6; i++){
                if(bolumTut == bolum)
                    break;
                for(j=0; j<6; j++){
                    bolumTut = sayilar[i] - sayilar[j];
                    if(bolumTut == bolum){
                        printf("%d - %d = %d \n", sayilar[i], sayilar[j], bolumTut);
                        sonuc = bolumTut*sayilar[5];
                        printf("%d * %d = %d\n", bolumTut, sayilar[5], sonuc);
                        break;
                    }
                }
            }
        }

        //Sayýyý çarpýp toplama
        if(bolumTut != bolum){
            bolumTut = 0;
            for(i=0; i<6; i++){
                    if(bolumTut == bolum)
                    break;
                for(j=0; j<6; j++){
                    if(bolumTut == bolum)
                    break;
                    for(k=0; k<6; k++){
                        bolumTut = (sayilar[i] * sayilar[j]) + sayilar[k];
                        if(bolumTut == bolum){
                        printf("%d * %d + %d = %d \n", sayilar[i], sayilar[j], sayilar[k], bolumTut);
                        sonuc = bolumTut*sayilar[5];
                        printf("%d * %d = %d\n", bolumTut, sayilar[5], sonuc);
                        break;
                        }
                    }
                }
            }
        }

        //Ýlk bölüp sonra toplayarak
        if(bolumTut != bolum){
            bolumTut = 0;
            for(i=0; i<6; i++){
                    if(bolumTut == bolum)
                    break;
                for(j=0; j<6; j++){
                    if(bolumTut == bolum)
                    break;
                    for(k=0; k<6; k++){
                        bolumTut = (sayilar[i] / sayilar[j]) + sayilar[k];
                        if(bolumTut == bolum){
                        printf("%d / %d + %d = %d \n", sayilar[i], sayilar[j], sayilar[k], bolumTut);
                        sonuc = bolumTut*sayilar[5];
                        printf("%d * %d = %d\n", bolumTut, sayilar[5], sonuc);
                        break;
                        }
                    }
                }
            }
        }

        //Sadece bölerek
        if(bolumTut != bolum){
                bolumTut = 0;
            for(i=0; i<6; i++){
                if(bolumTut == bolum)
                    break;
                for(j=0; j<6; j++){
                    bolumTut = sayilar[i] / sayilar[j];
                    if(bolumTut == bolum){
                        printf("%d / %d = %d \n", sayilar[i], sayilar[j], bolumTut);
                        sonuc = bolumTut*sayilar[5];
                        printf("%d * %d = %d\n", bolumTut, sayilar[5], sonuc);
                        break;
                    }
                }
            }
        }

        //KALAN BULMA KISMI
        //Girilen sayilarda kalan var mi bakýyoruz
        for(i=0; i<6; i++){
            if(sayilar[i] == kalan){
                kalanTut = sayilar[i];
                printf("Bulunan: %d + %d = %d\n", sonuc, kalanTut, sonuc+kalanTut);
            }
        }

        //Girilen sayýlar içerisinde bölüm yoksa 1.sayýyý diðerleriyle 2. sayýyý diðerleriyle boyle boyle topluyoruz toplamlarýnda var mý diye
        if(kalanTut != kalan){
                kalanTut = 0;
            for(i=0; i<6; i++){
                if(kalanTut == kalan)
                    break;
                for(j=0; j<6; j++){
                    kalanTut = sayilar[i] + sayilar[j];
                    if(kalanTut == kalan){
                        printf("%d + %d = %d \n", sayilar[i], sayilar[j], kalanTut);
                        printf("Bulunan: %d + %d = %d \n", sonuc, kalanTut, (sonuc+kalanTut));
                        break;
                    }
                }
            }
        }

        //Girilen sayýlari üçlü toplayarak
        if(kalanTut != kalan){
                kalanTut = 0;
            for(i=0; i<6; i++){
                    if(kalanTut == kalan)
                        break;
                for(j=0; j<6; j++){
                    if(kalanTut == kalan)
                        break;
                    for(k=0; k<6; k++){
                        kalanTut = sayilar[i] + sayilar[j] + sayilar[k];
                        if(kalanTut == kalan){
                            printf("%d + %d + %d = %d \n", sayilar[i], sayilar[j], sayilar[k], kalanTut);
                            printf("Bulunan: %d + %d = %d \n", sonuc, kalanTut, (sonuc+kalanTut));
                            break;
                        }
                    }
                }
            }
        }

        //Girilen sayýyý ikili çarparak
        if(kalanTut != kalan){
                kalanTut = 0;
            for(i=0; i<6; i++){
                if(kalanTut == kalan)
                    break;
                for(j=0; j<6; j++){
                    kalanTut = sayilar[i] * sayilar[j];
                    if(kalanTut == kalan){
                        printf("%d * %d = %d \n", sayilar[i], sayilar[j], kalanTut);
                        printf("Bulunan: %d + %d = %d \n", sonuc, kalanTut, (sonuc+kalanTut));
                        break;
                    }
                }
            }
        }

        //Girilen sayýyý ikili çýkararak
        if(kalanTut != kalan){
            kalanTut = 0;
            for(i=0; i<6; i++){
                if(kalanTut == kalan)
                    break;
                for(j=0; j<6; j++){
                    kalanTut = sayilar[i] - sayilar[j];
                    if(kalanTut == kalan){
                        printf("%d - %d = %d \n", sayilar[i], sayilar[j], kalanTut);
                        printf("Bulunan: %d + %d = %d \n", sonuc, kalanTut, (sonuc+kalanTut));
                        break;
                    }
                }
            }
        }

        //Sayýyý çarpýp toplama
        if(kalanTut != kalan){
            kalanTut = 0;
            for(i=0; i<6; i++){
                    if(kalanTut == kalan)
                    break;
                for(j=0; j<6; j++){
                    if(kalanTut == kalan)
                    break;
                    for(k=0; k<6; k++){
                        kalanTut = (sayilar[i] * sayilar[j]) + sayilar[k];
                        if(kalanTut == kalan){
                        printf("%d * %d + %d = %d \n", sayilar[i], sayilar[j], sayilar[k], kalanTut);
                        printf("Bulunan: %d + %d = %d \n", sonuc, kalanTut, (sonuc+kalanTut));
                        break;
                        }
                    }
                }
            }
        }

        //Ýlk bölüp sonra toplayarak
        if(kalanTut != kalan){
            kalanTut = 0;
            for(i=0; i<6; i++){
                    if(kalanTut == kalan)
                    break;
                for(j=0; j<6; j++){
                    if(kalanTut == kalan)
                    break;
                    for(k=0; k<6; k++){
                        kalanTut = (sayilar[i] / sayilar[j]) + sayilar[k];
                        if(kalanTut == kalan){
                        printf("%d / %d + %d = %d \n", sayilar[i], sayilar[j], sayilar[k], kalanTut);
                        printf("Bulunan: %d + %d = %d \n", sonuc, kalanTut, (sonuc+kalanTut));
                        break;
                        }
                    }
                }
            }
        }

        //Sadece bölerek
        if(kalanTut != kalan){
                kalanTut = 0;
            for(i=0; i<6; i++){
                if(kalanTut == kalan)
                    break;
                for(j=0; j<6; j++){
                    kalanTut = sayilar[i] / sayilar[j];
                    if(kalanTut == kalan){
                        printf("%d / %d = %d \n", sayilar[i], sayilar[j], kalanTut);
                        printf("Bulunan: %d + %d = %d \n", sonuc, kalanTut, (sonuc+kalanTut));
                        break;
                    }
                }
            }
        }

        //KALAN BULAMAMA DURUMU ALTERNATÝF YOL (Yarý Baþarýlý)
        if(kalanTut != kalan){
            kalanTut = sayilar[4] * sayilar[3];
            if(kalanTut < kalan){
                if(sayilar[2] < 2){
                    temp = kalanTut;
                    kalanTut *= sayilar[2];
                    printf("%d * %d = %d", temp, sayilar[2], kalanTut);
                    }
            }
            printf("Bulunan: %d + %d = %d \n", sonuc, kalanTut, (sonuc+kalanTut));
        }

    getch();
    return 0;
}
