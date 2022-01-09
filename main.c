#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
struct node
{
    int adet;
    char data [20];

    struct node* sonraki;

};

struct node* start=NULL;
struct node* q=NULL;
struct node* tmp=NULL;

void basaekle(char veri[20]); /* linked listin basina eleman ekleme */

void arayaekle(char veri[20],int adet,char konum[20]); /* linked listin belirtinlen eleman onune eleman ekleme */

void sonaekle(char veri[20]); /* linked listin sonuna eleman ekleme */

void yazdir(); /*linked list yazdirma*/

void dosya_oku();

int ara(char aranacak[20]); /* kelime daha once kullanilip kullanilmadgini kontrol eder*/

void guncelle(char gonderilen[20]); /*adet bilgisini gunceller*/

void SelectionSort(); /*siralama*/


void swap(struct node* p1,struct node* p2); /* iki degiskenin degimesi icin kullanýliyor */
int main()
{
    setlocale(LC_ALL,"Turkish");
    char veri[20];
    int adet;
    char konum[20];
    int secim;
    dosya_oku();
    printf("Sýralý hali:\n\n");
    yazdir();

    return 0;
}
void basaekle(char veri[20])
{
    struct node* eklenecek=(struct node*)(malloc(sizeof(struct node)));


    strcpy(eklenecek->data,veri);
    eklenecek->adet=1;
    eklenecek->sonraki=start;
    start=eklenecek;
}
void arayaekle(char veri[20],int adet,char konum[20])
{
    struct node* eklenecek=(struct node*)malloc(sizeof(struct node));

    strcpy(eklenecek->data,veri);
    eklenecek->adet=1;
    q=start;
    while(!(strstr(q->sonraki->data,konum)))
    {
        q=q->sonraki;
    }
    struct node* onune=(struct node*)malloc(sizeof(struct node));
    onune=q->sonraki;
    q->sonraki=eklenecek;
    eklenecek->sonraki=onune;
}
void sonaekle(char veri[20])
{
    struct node*eklenecek=(struct node*)(malloc(sizeof(struct node)));

    strcpy(eklenecek->data,veri);
    eklenecek->adet=1;
    eklenecek->sonraki=NULL;

    if(start==NULL)
    {
        start=eklenecek;
    }
    else
    {
        q=start;

        while(q->sonraki!=NULL)
        {

            q= q->sonraki;
        }
        q->sonraki=eklenecek;
    }
}
void yazdir()
{
    q=start;
    while(q->sonraki!=NULL)
    {

        printf("%s->",q->data);
        printf("adet %d\n",q->adet);
        q= q->sonraki;
    }
    printf("%s->",q->data);

    printf("adet %d\n",q->adet);
}
void dosya_oku()
{
    FILE *dosya;
    q=start;
    struct node* eklenecek=(struct node*)malloc(sizeof(struct node));
    int durum;
    int indis=0;
    dosya=fopen("oku.txt","r");
    if(dosya!=NULL)
    {
        printf("dosya bulundu\n");
        printf("TXT ICERISINDEKI METIN:\n\n");
        while(!feof(dosya))
        {
            fscanf(dosya,"%s",eklenecek->data);
            durum=ara(eklenecek->data);
            if(indis==0)
            {
                basaekle(eklenecek->data);
            }
            else
            {
                if(durum==-1)
                {
                    guncelle(eklenecek->data);
                }
                else
                {

                    sonaekle(eklenecek->data);
                }
            }
            SelectionSort();

            printf("%s ",eklenecek->data);
            indis+=1;
            // yazdir();
            //printf("\n\n");
        }

        fclose(dosya);
        printf("\n\n");

    }
    else
    {
        printf("dosya bulunamadi");
    }
}
// dizi içerisinde arama yapiyor:
int ara(char aranacak[20])
{
    q=start;
    int durum;
    while(q!=NULL && strcmp(q->data,aranacak)!=0)
    {

        q=q->sonraki;
    }
    if(q==NULL)
    {
        return 0;
    }
    else
    {
        return -1;
    }

}
// ayni eleman varsa adet bilgisini guncelliyo:
void guncelle(char gonderilen[20])
{
    q=start;
    while(strcmp(q->data,gonderilen)!=0)
    {
        q=q->sonraki;
    }

    q->adet=q->adet+1;
}
void SelectionSort()
{
    q = start;
    struct node* j;
    struct node* min;


    while(q->sonraki)
    {
        min = q;
        j = q->sonraki;

        while(j)
        {
            /* Find minimum element from array */
            if( min->adet < j->adet )
            {
                min = j;
            }

            j = j->sonraki;
        }
        swap(q,min);
        q = q->sonraki;
    }
}
void swap(struct node* p1,struct node* p2)
{
    char temps[20];
    strcpy(temps,p1->data);
    int temp = p1->adet;
    p1->adet = p2->adet;
    strcpy(p1->data,p2->data);
    p2->adet = temp;
    strcpy(p2->data,temps);
}

