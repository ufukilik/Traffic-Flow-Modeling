#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct yolDugum
{
    int GCKutup;  //giris cikislar icin deger tutar (x,y,z,t) (1 veya 0 tutar)
    int aracyogunlugu[4];  // arac yogunluklarini tutar
    int aracyonu[3];   // arac yonlerini tutar.
} YOL;

YOL dugum[4];
int yolNo;


void sifirla()
{
    int i,j,k;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            dugum[i].aracyogunlugu[j]=0; // tum aracyogunluklarini baslangic degerini 0 olarak atar.
        }
        for(k=0; k<4; k++)
        {
            dugum[i].aracyonu[k]=0; // tum aracyonunun baslangıc degerını 0 olarak atar.
        }
    }
}

void yolSecimi()
{
    //sekil 1 icin yazılmıs kodlardır
    initwindow(1000,500);       //1000 e 500 luk bi graphic cizim ekrani (winbgim uygulamasi) acar.
    line(50,180,143,180);       // (50,180) den baslayan (143,180) de bitin bir cizgi cizer.
    line(50,220,143,220);
    line(358,180,450,180);
    line(358,220,450,220);
    line(230,10,230,93);
    line(268,10,268,93);
    line(230,308,230,400);
    line(268,308,268,400);
    arc(250,200,100,170,110); // (250,200) de merkezi olan 100 ve 170 dereceleri aracında capı 110 olan bi yay cizer.
    arc(250,200,190,260,110);
    arc(250,200,280,350,110);
    arc(250,200,10,80,110);
    circle(250,200,75);       // merkezi (250,200) olan capı 75 olan bi cember cizer.
    outtextxy(200,450,"Sekil 1");

    //sekil 2 icin yazılmıs kodlardır
    line(677,180,823,180);       //(677,180) den baslayan (823,180) de biten bi cizgi cizer.
    line(677,220,823,220);
    line(550,180,643,180);
    line(550,220,643,220);
    line(858,180,950,180);
    line(858,220,950,220);
    line(730,10,730,93);
    line(768,10,768,93);
    line(730,308,730,400);
    line(768,308,768,400);
    arc(750,200,100,170,110);     //(750,200) de merkezi olan 100 ve 170 dereceleri aracında capı 110 olan bi yay cizer.
    arc(750,200,190,260,110);
    arc(750,200,280,350,110);
    arc(750,200,10,80,110);
    arc(750,200,17,165,75);      //(750,200) de merkezi olan 17 ve 165 dereceleri aracında capı 110 olan bi yay cizer.
    arc(750,200,197,345,75);
    outtextxy(700,450,"Sekil 2");

    outtextxy(350,450,"Lutfen bir tusa basiniz...");

    while(!kbhit());
    closegraph();
}

void girislercikislar()
{
    int kontrol=0;
    int i=0;
    char dizi[]= {'x','y','z','t'};
    printf("\nSADECE 2 ADET GIRIS YOLU VE 2 ADET CIKIS YOLU BELIRLEYEBILIRSINIZ! \n");
    do
    {
        printf("\n%c yolu giris mi olsun cikis mi?(giris icin :'1', cikis icin :'0' tusuna basiniz..!)\n",dizi[i]);
        scanf("%d",&dugum[i].GCKutup);
        kontrol= kontrol +dugum[i].GCKutup; // kontrol icin girilen degerleri toplar.(2 giris 2 cikis icin kontrol)
        if(dugum[i].GCKutup!=1 && dugum[i].GCKutup!=0)
        {
            printf("\nYALNIZCA 1 ve 0 TUSLARINI KULLANINIZ !\n");
            kontrol=kontrol-dugum[i].GCKutup; // hatali giris yapilmissa kontroldan o deger dusurulur.
            i--; // tekrar giris alabilmek icin i azaltilir.
        }
        i++;
    }
    while(i<4);
    if(kontrol!=2)
    {
        printf("\nHATALI SECIM YAPTINIZ LUTFEN SADECE 2 GIRIS VE 2 CIKIS SECINIZ !\n");
        girislercikislar();
    }
}

void hangiYol()
{
    printf("sekil 1 mi? 2 mi ?");
    scanf("%d",&yolNo);    //hangi yol secildiyse onu tutar.
}

void caddeYonu()
{
    int kontrol[4]= {0,0,0,0},sayac=0,i,j=0,syc=0;
    char dizi[]= {'x','y','z','t'};
    char bN;
    char y;
    if(yolNo==1)
    {
        syc=4; // ilk yok icin kontrol saglamak amacli deger atamasi.
    }
    else if(yolNo==2)
    {
        syc=5; //ikinci yol icin ontrol saglamak amacli deger atamasi
    }
    do
    {
        printf("Baslangic noktasi:");
        scanf(" %c",&bN);
        printf("yonu:");
        scanf(" %c",&y);
        if(bN=='t' && y=='x')
        {
            if(kontrol[0]==0) // kullanici a yolu icin giris yapmadiysa giris saglanir.
            {
                kontrol[0]=1;// kontrol 1 olunca a yolu icin deger alimi duracak.
                sayac+=1;
                dugum[0].aracyonu[0]=1;// x icin a 1 olacak.
                dugum[3].aracyonu[1]=-1;// t icin a -1 olacak.
            }
        }
        if(bN=='x' && y=='t')
        {
            if(kontrol[0]==0)  // kullanici a yolu icin giris yapmadiysa giris saglanir.
            {
                kontrol[0]=1;// kontrol 1 olunca a yolu icin deger alimi duracak.
                sayac+=1;
                dugum[0].aracyonu[0]=-1;// x icin a -1 olacak.
                dugum[3].aracyonu[1]=1; //t icin a 1 olacak.
            }
        }
        if(bN=='x' && y=='y')
        {
            if(kontrol[2]==0)// kullanici b yolu icin giris yapmadiysa giris saglanir.
            {
                kontrol[2]=1;// kontrol 1 olunca b yolu icin deger alimi duracak.
                sayac+=1;
                dugum[1].aracyonu[0]=1;//y icin b 1 olacak.
                dugum[0].aracyonu[1]=-1;//x icin b -1 olacak.
            }

        }
        if(bN=='y' && y=='x')
        {
            if(kontrol[2]==0)// kullanici b yolu icin giris yapmadiysa giris saglanir.
            {
                kontrol[2]=1;// kontrol 1 olunca b yolu icin deger alimi duracak.
                sayac+=1;
                dugum[1].aracyonu[0]=-1;//y icin b degeri -1 olacak.
                dugum[0].aracyonu[1]=1;//x icin b degeri 1 olacak.
            }
        }
        if(bN=='t' && y=='z')
        {
            if(kontrol[1]==0)// kullanici c yolu icin giris yapmadiysa giris saglanir.
            {
                kontrol[1]=1;// kontrol 1 olunca c yolu icin deger alimi duracak.
                sayac+=1;
                dugum[2].aracyonu[1]=1;//z icin c degeri 1 olacak.
                dugum[3].aracyonu[0]=-1;//t icin c degeri -1 olacak.
            }
        }
        if(bN=='z' && y=='t')
        {
            if(kontrol[1]==0)// kullanici c yolu icin giris yapmadiysa giris saglanir.
            {
                kontrol[1]=1;// kontrol 1 olunca c yolu icin deger alimi duracak.
                sayac+=1;
                dugum[2].aracyonu[1]=-1;//z icin c degeri -1 olacak.
                dugum[3].aracyonu[0]=1;//t icin c degeri 1 olacak.
            }
        }
        if(bN=='y' && y=='z')
        {
            if(kontrol[3]==0)// kullanici d yolu icin giris yapmadiysa giris saglanir.
            {
                kontrol[3]=1;// kontrol 1 olunca d yolu icin deger alimi duracak.
                sayac+=1;
                dugum[2].aracyonu[0]=1;//z icin d degeri 1 olacak.
                dugum[1].aracyonu[1]=-1;//y icin d degeri -1 olacak.
            }

        }
        if(bN=='z' && y=='y')
        {
            if(kontrol[3]==0)// kullanici d yolu icin giris yapmadiysa giris saglanir.
            {
                kontrol[3]=1;// kontrol 1 olunca d yolu icin deger alimi duracak.
                sayac+=1;
                dugum[2].aracyonu[0]=-1;//z icin d degeri -1 olacak.
                dugum[1].aracyonu[1]=1;//y icin d degeri 1 olacak.
            }
        }
        if(yolNo==2)// eger ikinci yo lsecildiyse asagidaki islemleri yapacak.
        {
            if(bN=='t' && y=='y')
            {
                if(kontrol[4]==0)// kullanici e yolu icin giris yapmadiysa giris saglanir.
                {
                    kontrol[4]=1;// kontrol 1 olunca e yolu icin deger alimi duracak.
                    sayac+=1;
                    dugum[1].aracyonu[2]=1;//y icin e degeri 1 olacak.
                    dugum[3].aracyonu[2]=-1;//t icin e degeri -1 olacak.
                }
            }
            if(bN=='y' && y=='t')
            {
                if(kontrol[4]==0)// kullanici e yolu icin giris yapmadiysa giris saglanir.
                {
                    kontrol[4]=1;// kontrol 1 olunca e yolu icin deger alimi duracak.
                    sayac+=1;
                    dugum[3].aracyonu[2]=1;//t icin e degeri 1 olacak.
                    dugum[1].aracyonu[2]=-1;//y icin e degeri -1 olacak.
                }
            }
        }
    }
    while(sayac!=syc); // sayac syc degerine esit olana kadar donguyu yap.
    if(yolNo==1)       //ilk yol seciliyse
    {
        for(i=0; i<4; i++)
        {
            if(dugum[i].GCKutup==1 && dugum[i].aracyonu[j]==1 && dugum[i].aracyonu[j+1]==1)//tum araclar bi noktaya giris olamasin diye kontrol yapildi.
            {
                printf("\n%c VE BAGLI CADDELERININ HEPSI GIRIS OLAMAZ !!!!\n",dizi[i]);
                caddeYonu();
            }
            else if(dugum[i].GCKutup==0 && dugum[i].aracyonu[j]==-1 && dugum[i].aracyonu[j+1]==-1)//tum araclar bi noktaya cikis olamasin diye kontrol yapildi.
            {
                printf("\n%c VE BAGLI CADDELERININ HEPSI CIKIS OLAMAZ !!!!\n",dizi[i]);
                caddeYonu();
            }
        }
    }
    else if(yolNo==2)//ikinci yol seciliyse
    {
        for(i=0; i<2; i++) // x, y icin ayri kontrol edildi.
        {
            if(dugum[i].GCKutup==1 && dugum[i].aracyonu[j]==1 && dugum[i].aracyonu[j+1]==1)//tum araclar bi noktaya giris olamasin diye kontrol yapildi.
            {
                printf("\n%c VE BAGLI CADDELERININ HEPSI GIRIS OLAMAZ !!!!\n",dizi[i]);
                caddeYonu();
            }
            else if(dugum[i].GCKutup==0 && dugum[i].aracyonu[j]==-1 && dugum[i].aracyonu[j+1]==-1)//tum araclar bi noktaya giris olamasin diye kontrol yapildi.
            {
                printf("\n%c VE BAGLI CADDELERININ HEPSI CIKIS OLAMAZ !!!!\n",dizi[i]);
                caddeYonu();
            }
        }
        for(i=2; i<4; i++)// z, t icin ayri kontrol edildi.
        {
            if(dugum[i].GCKutup==1 && dugum[i].aracyonu[j]==1 && dugum[i].aracyonu[j+1]==1 && dugum[i].aracyonu[j+2]==1)//tum araclar bi noktaya giris olamasin diye kontrol yapildi.
            {
                printf("\n%c VE BAGLI CADDELERININ HEPSI GIRIS OLAMAZ !!!!\n",dizi[i]);
                caddeYonu();
            }
            else if(dugum[i].GCKutup==0 && dugum[i].aracyonu[j]==-1 && dugum[i].aracyonu[j+1]==-1 && dugum[i].aracyonu[j+2]==-1)//tum araclar bi noktaya giris olamasin diye kontrol yapildi.
            {
                printf("\n%c VE BAGLI CADDELERININ HEPSI CIKIS OLAMAZ !!!!\n",dizi[i]);
                caddeYonu();
            }
        }
    }
}

void yonGoster()
{
    initwindow(500,500);       //sekil 1 icin yazildi.
    moveto(0,0);
    line(50,180,143,180);
    line(50,220,143,220);
    line(358,180,450,180);
    line(358,220,450,220);
    line(230,10,230,93);
    line(268,10,268,93);
    line(230,308,230,400);
    line(268,308,268,400);
    arc(250,200,100,170,110);
    arc(250,200,190,260,110);
    arc(250,200,280,350,110);
    arc(250,200,10,80,110);
    if(yolNo==1)                      // ilk yol seciliyse
    {
        circle(250,200,75);
    }
    else if(yolNo==2)                 // ikinci yol seciliyse
    {
        line(177,180,323,180);          //sekil 2 icin yazildi.
        line(177,220,323,220);
        arc(250,200,17,165,75);
        arc(250,200,197,345,75);
    }
    int i;
    if(dugum[0].GCKutup==1) // x girisse asagiyi yap.
    {
        for(i=0; i<10; i++)
        {
            setcolor(BLACK); // cizim rengini siyaha ayarlar.
            line(252,10+(i*5),252,25+(i*5));   // belirtilen araliklarda cizgi cizer.
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            line(252,10+((i+1)*5),252,25+((i+1)*5));// belirtilen araliklarda cizgi cizer.
            delay(50); //bekleme suresi koyar.
        }
    }
    if(dugum[0].GCKutup==0) // x cikissa asagiyi yap.
    {
        for(i=10; i>0; i--)
        {
            setcolor(BLACK);// cizim rengini siyaha ayarlar.
            line(252,10+((i+1)*5),252,25+((i+1)*5));
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            line(252,10+(i*5),252,25+(i*5));
            delay(50);//bekleme suresi koyar.
        }
    }
    if(dugum[1].GCKutup==0)
    {
        for(i=0; i<15; i++)
        {
            setcolor(BLACK);// cizim rengini siyaha ayarlar.
            line(360+(i*5),200,370+(i*5),200);   // belirtilen araliklarda cizgi cizer.
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            line(360+((i+1)*5),200,370+((i+1)*5),200);// belirtilen araliklarda cizgi cizer.
            delay(50);//bekleme suresi koyar.
        }
    }
    if(dugum[1].GCKutup==1)
    {
        for(i=15; i>0; i--)
        {
            setcolor(BLACK);// cizim rengini siyaha ayarlar.
            line(360+((i+1)*5),200,370+((i+1)*5),200);   // belirtilen araliklarda cizgi cizer.
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            line(360+(i*5),200,370+(i*5),200);// belirtilen araliklarda cizgi cizer.
            delay(50);//bekleme suresi koyar.
        }
    }
    if(dugum[2].GCKutup==1)
    {
        for(i=10; i>0; i--)
        {
            setcolor(BLACK);// cizim rengini siyaha ayarlar.
            line(252,318+((i+1)*5),252,325+((i+1)*5));   // belirtilen araliklarda cizgi cizer.
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            line(252,318+(i*5),252,325+(i*5));// belirtilen araliklarda cizgi cizer.
            delay(50);//bekleme suresi koyar.
        }
    }
    if(dugum[2].GCKutup==0)
    {
        for(i=0; i<10; i++)
        {
            setcolor(BLACK);// cizim rengini siyaha ayarlar.
            line(252,318+(i*5),252,325+(i*5));   // belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            line(252,318+((i+1)*5),252,325+((i+1)*5));// belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            delay(50);//bekleme suresi koyar.
        }
    }

    if(dugum[3].GCKutup==1)
    {
        for(i=0; i<15; i++)
        {
            setcolor(BLACK);// cizim rengini siyaha ayarlar.
            line(50+(i*5),200,65+(i*5),200);   // belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            line(50+((i+1)*5),200,65+((i+1)*5),200);// belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            delay(50);//bekleme suresi koyar.
        }
    }
    if(dugum[3].GCKutup==0)
    {
        for(i=15; i>0; i--)
        {
            setcolor(BLACK);// cizim rengini siyaha ayarlar.
            line(50+((i+1)*5),200,65+((i+1)*5),200);   // belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            line(50+(i*5),200,65+(i*5),200);// belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            delay(50);//bekleme suresi koyar.
        }
    }
    if(dugum[0].aracyonu[0]==-1 || dugum[3].aracyonu[1]==1)
    {
        for(i=0; i<10; i++)
        {
            setcolor(BLACK);// cizim rengini siyaha ayarlar.
            arc(250,200,107+(i*5),110+(i*5),92.5);   // belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            arc(250,200,107+((i+1)*5),110+((i+1)*5),92.5);// belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            delay(100);//bekleme suresi koyar.
        }
    }
    if(dugum[0].aracyonu[0]==1 || dugum[3].aracyonu[1]==-1)
    {
        for(i=0; i<10; i++)
        {
            setcolor(BLACK);// cizim rengini siyaha ayarlar.
            arc(250,200,160-(i*5),167-(i*5),92.5);   // belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            arc(250,200,160-((i+1)*5),167-((i+1)*5),92.5);// belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            delay(100);//bekleme suresi koyar.
        }
    }
    if(dugum[1].aracyonu[0]==-1 || dugum[0].aracyonu[1]==1)
    {
        for(i=0; i<10; i++)
        {
            setcolor(BLACK);// cizim rengini siyaha ayarlar.
            arc(250,200,20+(i*5),23+(i*5),92.5);   // belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            arc(250,200,20+((i+1)*5),23+((i+1)*5),92.5);// belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            delay(100);//bekleme suresi koyar.
        }
    }
    if(dugum[1].aracyonu[0]==1 || dugum[0].aracyonu[1]==-1)
    {
        for(i=0; i<10; i++)
        {
            setcolor(BLACK);// cizim rengini siyaha ayarlar.
            arc(250,200,70-(i*5),73-(i*5),92.5);   // belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            arc(250,200,70-((i+1)*5),73-((i+1)*5),92.5);// belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            delay(100);//bekleme suresi koyar.
        }
    }
    if(dugum[2].aracyonu[1]==1 || dugum[3].aracyonu[0]==-1)
    {
        for(i=0; i<10; i++)
        {
            setcolor(BLACK);// cizim rengini siyaha ayarlar.
            arc(250,200,200+(i*5),203+(i*5),92.5);   // belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            arc(250,200,200+((i+1)*5),203+((i+1)*5),92.5);// belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            delay(100);//bekleme suresi koyar.
        }
    }
    if(dugum[2].aracyonu[1]==-1 || dugum[3].aracyonu[0]==1)
    {
        for(i=0; i<10; i++)
        {
            setcolor(BLACK);// cizim rengini siyaha ayarlar.
            arc(250,200,260-(i*5),263-(i*5),92.5);   // belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            arc(250,200,260-((i+1)*5),263-((i+1)*5),92.5);// belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            delay(100);//bekleme suresi koyar.
        }
    }
    if(dugum[2].aracyonu[0]==-1 || dugum[1].aracyonu[1]==1)
    {
        for(i=0; i<10; i++)
        {
            setcolor(BLACK);// cizim rengini siyaha ayarlar.
            arc(250,200,280+(i*5),283+(i*5),92.5);   // belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            arc(250,200,280+((i+1)*5),283+((i+1)*5),92.5);// belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            delay(100);//bekleme suresi koyar.
        }
    }
    if(dugum[2].aracyonu[0]==1 || dugum[1].aracyonu[1]==-1)
    {
        for(i=0; i<10; i++)
        {
            setcolor(BLACK);// cizim rengini siyaha ayarlar.
            arc(250,200,340-(i*5),343-(i*5),92.5);   // belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            setcolor(WHITE);//cizim rengini beyaza ayarlar.
            arc(250,200,340-((i+1)*5),343-((i+1)*5),92.5);// belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
            delay(100);//bekleme suresi koyar.
        }
    }
    if(yolNo==2)
    {
        if(dugum[3].aracyonu[2]==-1 && dugum[1].aracyonu[2]==1)
        {
            for(i=0; i<25; i++)
            {
                setcolor(BLACK);// cizim rengini siyaha ayarlar.
                line(180+(i*5),200,190+(i*5),200);   // belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
                setcolor(WHITE);//cizim rengini beyaza ayarlar.
                line(180+((i+1)*5),200,190+((i+1)*5),200);// belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
                delay(50);//bekleme suresi koyar.
            }
        }
        if(dugum[3].aracyonu[2]==1 && dugum[1].aracyonu[2]==-1)
        {
            for(i=25; i>0; i--)
            {
                setcolor(BLACK);// cizim rengini siyaha ayarlar.
                line(180+((i+1)*5),200,190+((i+1)*5),200);   // belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
                setcolor(WHITE);//cizim rengini beyaza ayarlar.
                line(180+(i*5),200,190+(i*5),200);// belirtilen araliklarda i ye baglı olarak degisen cizgi cizer.
                delay(50);//bekleme suresi koyar.
            }
        }
    }

    while(!kbhit());
    closegraph();
}

int bilinmeyen=0;
int dizi1[9];
void aracYogunluklari()
{
    bilinmeyen=0;
    int i;
    char dizi[]= {'x','y','z','t','a','b','d','c','e'};
    printf("\nLUTFEN ARAC YOGUNLUGUNU GIRINIZ GIRMEK BILINMEYENLER ICIN -1 GIRIN\n");
    for(i=0; i<8; i++)
    {
        printf("\n%c yolu arac yogunlugu nedir? (bilinmiyorsa -1 giriniz!)\n",dizi[i]);
        scanf("%d",&dizi1[i]);
        if(dizi1[i]<-1){
            printf("lutfen tekrar giriniz !!");
            i--;
        }
        if(dizi1[i]==-1) //dizi1 -1 degeri iceriyorsa.
        {
            bilinmeyen++; // bilinmeyeni arttır.
        }
    }
    dugum[0].aracyogunlugu[0]=dizi1[4];// a nin degerini x in arac yogunluguna at.
    dugum[0].aracyogunlugu[1]=dizi1[5];// b nin degerini x in arac yogunluguna at.
    dugum[0].aracyogunlugu[3]=dizi1[0];// x nin degerini x in arac yogunluguna at.
    dugum[1].aracyogunlugu[0]=dizi1[5];// b nin degerini y in arac yogunluguna at.
    dugum[1].aracyogunlugu[1]=dizi1[6];// d nin degerini y in arac yogunluguna at.
    dugum[1].aracyogunlugu[3]=dizi1[1];// y nin degerini y in arac yogunluguna at.
    dugum[2].aracyogunlugu[0]=dizi1[6];// d nin degerini z in arac yogunluguna at.
    dugum[2].aracyogunlugu[1]=dizi1[7];// c nin degerini z in arac yogunluguna at.
    dugum[2].aracyogunlugu[3]=dizi1[2];// z nin degerini z in arac yogunluguna at.
    dugum[3].aracyogunlugu[0]=dizi1[7];// c nin degerini t in arac yogunluguna at.
    dugum[3].aracyogunlugu[1]=dizi1[4];// a nin degerini t in arac yogunluguna at.
    dugum[3].aracyogunlugu[3]=dizi1[3];// t nin degerini t in arac yogunluguna at.
    if(yolNo==2)
    {
        printf("\n%c yolu arac yogunlugu nedir? (bilinmiyorsa -1 giriniz!)\n",dizi[8]);
        scanf("%d",&dizi1[8]);
        dugum[1].aracyogunlugu[2]=dizi1[8];// e nin degerini y in arac yogunluguna at.
        dugum[3].aracyogunlugu[2]=dizi1[8];// e nin degerini t in arac yogunluguna at.
        if(dizi1[8]==-1) // e icin -1 degeri iceriyorsa
        {
            bilinmeyen++; // bilinmeyeni bir arttır.
        }
    }
    if(bilinmeyen>5)//bilinmeyen sayişi 5 den buyuk olursa assagiyi yap
    {
        printf("\nGIRDIGINIZ DEGERLER COZUM ICIN YETERLI DEGIL!!!\n"); // 5 den buyuk bilinmeyen sayisiyla cozum bulunmaz.
        aracYogunluklari();
    }
}

void ekranayaz(int matris1[][6])
{
    int i,j;
    printf("\n");
    for(i=0; i<5; i++)
    {
        for(j=0; j<6; j++)
        {
            printf("%d\t",matris1[i][j]);
        }
        printf("\n");
    }
}

void denklemkurcozumle()
{
    int i,j,k,l;
    int matris[9][10];
    for(i=0; i<9; i++)
    {
        for(j=0; j<10; j++)
        {
            matris[i][j]=0;
        }
    }
    for(i=0; i<4; i++)
    {
        if(dugum[i].aracyogunlugu[3]==-1)
        {
            matris[i][i]=-1;
        }
        else
        {
            matris[i][9]=dugum[i].aracyogunlugu[3];
        }
    }

    for(k=0; k<4; k++)
    {
        for(l=0; l<2; l++)
        {
            if(dugum[k].aracyogunlugu[l]==-1)
            {
                if(dugum[k].GCKutup==1)
                {
                    matris[k][l+4+k]=(dugum[k].aracyonu[l])*(-1);
                }
                else if(dugum[k].GCKutup==0)
                {
                    matris[k][l+4+k]=dugum[k].aracyonu[l];
                }
            }
            else
            {
                if(dugum[k].GCKutup==1)
                {

                    matris[k][9]+=((dugum[k].aracyogunlugu[l])*(dugum[k].aracyonu[l])); //iki kere -1 ile çarpmış olduk o yüzden -1 ile çarpılmaya ihtiyacı yok :)

                }
                else if(dugum[k].GCKutup==0)
                {

                    matris[k][9]+=((dugum[k].aracyogunlugu[l]*dugum[k].aracyonu[l])*(-1));
                }

            }
            if(k==3&&l==1) 			//a yolunu matriste dogru yere atmak icin
            {
                if(dugum[3].aracyogunlugu[1]==-1)
                {
                    matris[3][8]=0;
                    if(dugum[3].GCKutup==1)
                    {
                        matris[3][4]=(dugum[3].aracyonu[1])*(-1);
                    }
                    else if(dugum[3].GCKutup==0)
                    {
                        matris[3][4]=dugum[3].aracyonu[1];
                    }
                }
            }
        }
    }
    for(i=0; i<4; i++) 					//bu for 5.denklem için
    {
        if(dugum[i].GCKutup==1)
        {
            if(dugum[i].aracyogunlugu[3]==-1)
            {
                matris[4][i]=1;
            }
            else
            {
                matris[4][9]+=((-1)*(dugum[i].aracyogunlugu[3]));
            }

        }
        else if(dugum[i].GCKutup==0)
        {
            if(dugum[i].aracyogunlugu[3]==-1)
            {
                matris[4][i]=-1;
            }
            else
            {
                matris[4][9]+=(dugum[i].aracyogunlugu[3]);
            }
        }
    }

    if(dugum[1].aracyogunlugu[2]==-1) 			//e yolunu matrise atmak icin
    {
        if(dugum[1].GCKutup==1)
        {
            matris[1][8]=(dugum[1].aracyonu[2])*(-1);
        }
        else if(dugum[1].GCKutup==0)
        {
            matris[1][8]=(dugum[1].aracyonu[2]);
        }
    }
    else
    {
        if(dugum[1].GCKutup==1)
        {
            matris[1][9]+=((dugum[1].aracyogunlugu[2])*(dugum[1].aracyonu[2]));
        }
        else if(dugum[1].GCKutup==0)
        {
            matris[1][9]+=((dugum[1].aracyogunlugu[2])*(dugum[1].aracyonu[2])*(-1));
        }

    }
    if(dugum[3].aracyogunlugu[2]==-1)
    {
        if(dugum[3].GCKutup==1)
        {
            matris[3][8]=(dugum[3].aracyonu[2])*(-1);
        }
        else if(dugum[3].GCKutup==0)
        {
            matris[3][8]=(dugum[3].aracyonu[2]);
        }
    }
    else
    {
        if(dugum[3].GCKutup==1)
        {
            matris[3][9]+=((dugum[3].aracyogunlugu[2])*(dugum[3].aracyonu[2]));
        }
        else if(dugum[3].GCKutup==0)
        {
            matris[3][9]+=((dugum[3].aracyogunlugu[2])*(dugum[3].aracyonu[2])*(-1));
        }

    }

    int matris1[5][6];


    k=0;
    for(i=0; i<9; i++) 			//bilinmeyenleri yenni matrise atmak için
    {
        if(dizi1[i]==-1)
        {
            for(j=0; j<5; j++)
            {
                matris1[j][k]=matris[j][i];
            }
            k++;
        }
    }
    for(i=0; i<5; i++) 			//degerleri atmak için
    {
        matris1[i][5]=matris[i][9];
    }
    for(i=bilinmeyen; i<9-bilinmeyen; i++)  //5x6 lık matris 5 bilinmeyen icindi 5 den daha az bilimiyen varsa matrisi daha sade göstermek icin.
    {
        for(j=0; j<5; j++)
        {
            matris1[j][i]=0;
        }
    }

    ekranayaz(matris1);

    int q1,temp;
    for(i=0; i<5; i++)
    {
        if(matris1[i][i]==0)
        {
            for(j=4; j>i; j--)
            {
                if(matris1[j][i]!=0)
                {
                    for(q1=0; q1<6; q1++)     //matrisinin ilk sütunundan başlayarak satir satir tarama yapar
                    {
                        //ve 0 dan farklı ilk buldugu degerle yer degistir.
                        temp=matris1[i][q1];
                        matris1[i][q1]=matris1[j][q1];
                        matris1[j][q1]=temp;
                    }
                }
            }
        }
    }

    ekranayaz(matris1);

    for(i=0; i<5; i++)
    {
        if(matris1[i][i]==1)       //matris de 0x0 dan başlayarak kosegenlerde 1 var mı diye bak.
        {
            for(j=4; j>i; j--)
            {
                if(matris1[j][i]==1)    // bir varsa aynı sutundan sondan baslayarak yukariya dogru 1 varmı diye kontrol et.
                {
                    for(q1=0; q1<6; q1++)
                    {
                        matris1[j][q1]=matris1[i][q1]*(-1)+matris1[j][q1]; // varsa ilk satirin degerlerini -1 ile carp ve 1 buldugun matrise ekle.

                    }
                }
                if(matris1[j][i]==-1)   //bir varsa aynı sutundan sondan baslayarak yukariya dogru -1 varmı diye kontrol et
                {
                    for(q1=0; q1<6; q1++)
                    {
                        matris1[j][q1]=matris1[i][q1]+matris1[j][q1];// varsa ilk satirin degerlerini  1 buldugun matrise ekle

                    }
                }
            }
        }
        if(matris1[i][i]==-1)//matris de 0x0 dan başlayarak kosegenlerde -1 var mi diye bak
        {
            for(j=4; j>i; j--)
            {
                if(matris1[j][i]==1)// -1 varsa aynı sutundan sondan baslayarak yukariya dogru 1 varmı diye kontrol et
                {
                    for(q1=0; q1<6; q1++)
                    {
                        matris1[j][q1]=matris1[i][q1]+matris1[j][q1];// varsa ilk satirin degerlerini  1 buldugun matrise ekle

                    }
                }
                if(matris1[j][i]==-1)// -1 varsa aynı sutundan sondan baslayarak yukariya dogru -1 varmı diye kontrol et
                {
                    for(q1=0; q1<6; q1++)
                    {
                        matris1[j][q1]=matris1[i][q1]*(-1)+matris1[j][q1]; // varsa ilk satirin degerlerini -1 ile carp ve 1 buldugun matrise ekle.

                    }
                }
            }
        }
    }
    ekranayaz(matris1);

    for(i=0; i<5; i++)
    {
        if(matris1[i][i]==1)//matris de 0x0 dan başlayarak kosegenlerde 1 var mı diye bak.
        {
            for(j=0; j<i; j++)
            {
                if(matris1[j][i]==1)// bir varsa aynı sutundan bastan baslayarak asagıya dogru 1 varmı diye kontrol et.
                {
                    for(q1=0; q1<6; q1++)
                    {
                        matris1[j][q1]=matris1[i][q1]*(-1)+matris1[j][q1];// varsa ilk satirin degerlerini -1 ile carp ve 1 buldugun matrise ekle.

                    }
                }
                if(matris1[j][i]==-1)//bir varsa aynı sutundan bastan baslayarak asagiya dogru -1 varmı diye kontrol et
                {
                    for(q1=0; q1<6; q1++)
                    {
                        matris1[j][q1]=matris1[i][q1]+matris1[j][q1];// varsa ilk satirin degerlerini  1 buldugun matrise ekle

                    }
                }
            }
        }
        if(matris1[i][i]==-1)//matris de 0x0 dan başlayarak kosegenlerde -1 var mi diye bak
        {
            for(j=0; j<i; j++)
            {
                if(matris1[j][i]==1)// -1 varsa aynı sutundan bastan baslayarak asagiya dogru 1 varmı diye kontrol et
                {
                    for(q1=0; q1<6; q1++)
                    {
                        matris1[j][q1]=matris1[i][q1]+matris1[j][q1];// varsa ilk satirin degerlerini  1 buldugun matrise ekle

                    }
                }
                if(matris1[j][i]==-1)// -1 varsa aynı sutundan bastan baslayarak asagiya dogru -1 varmı diye kontrol et
                {
                    for(q1=0; q1<6; q1++)
                    {
                        matris1[j][q1]=matris1[i][q1]*(-1)+matris1[j][q1];// varsa ilk satirin degerlerini -1 ile carp ve 1 buldugun matrise ekle.

                    }
                }
            }
        }
    }
    ekranayaz(matris1);
    for(i=0;i<5;i++){
        if(matris1[i][i]<=-1){
            for(j=0;j<6;j++){
                matris1[i][j]=matris1[i][j]*(-1);
        }
    }
}
    ekranayaz(matris1);
    int x[bilinmeyen];
    for(i=0; i<bilinmeyen; i++)   //bilinmeyenlerin degerlerini tut.
    {
        for(j=0; j<6; j++)
        {
            x[i]=matris1[i][j];
        }
    }

    printf("\n");
    for(i=0; i<bilinmeyen; i++)
    {
        if(matris1[i][i]==0)  // deger kösegen 0 sa ekrana yazma ve devam et.
        {
            continue;
        }
        if(x[i]>0){
        printf("x%d: %d\t",i+1,x[i]);
        }else if(x[i]<0)
        printf("x%d: %d\t",i+1,x[i]*(-1));
    }
}

int main()
{
    sifirla();
    yolSecimi();
    hangiYol();
    girislercikislar();
    caddeYonu();
    yonGoster();
    aracYogunluklari();
    denklemkurcozumle();
    return 0;
}
