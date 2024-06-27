#include<graphics.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

float alanhesapla(int dizi[],int uzunluk)
{
	int i;
	float toplam=0.0;
	for(i=0;i<uzunluk-2;i+=2)
	{	
		toplam=(dizi[i]*dizi[i+3]-dizi[i+2]*dizi[i+1])+toplam;
	}
	return fabs(toplam)/2.0;
}

void x1kare(int x,int y)//1x1 sol ust koordinatini giriyoruz
{
int i;
for(i=x;i<x+16;i++)
line(i,y,i,y+16);
}

void x2kare(int x,int y)//2x2 merkez koordinatlarini girioz
{
x1kare(x,y);
x1kare(x-16,y-16);
x1kare(x-16,y);
x1kare(x,y-16);
}

void x4kare(int x,int y)//4x4 (merkez koordinatlarini giriyoruz
{
x+=16;
y+=16;
x2kare(x-32,y-32);
x2kare(x-32,y);
x2kare(x,y-32);
x2kare(x,y);
}

int tavan_bulma(int dizi_boyutu,int cokgen_dizisi[])//ysi en kucuk deger
{
	int tavan,ai;
	tavan=cokgen_dizisi[1];
	for(ai=1;ai<dizi_boyutu+1;ai+=2)
	{
		if(cokgen_dizisi[ai]>tavan)
		{
			tavan=cokgen_dizisi[ai];
		}		
	}
return tavan;
}

int taban_bulma(int dizi_boyutu,int cokgen_dizisi[])//ysi en buyuk deger
{
	int taban,ai;
	taban=cokgen_dizisi[1];
	for(ai=1;ai<dizi_boyutu+1;ai+=2)
	{
		if(cokgen_dizisi[ai]<taban)
		{
			taban=cokgen_dizisi[ai];
		}		
	}
return taban;
}

int en_sag_bulma(int dizi_boyutu,int cokgen_dizisi[])
{
	int sag,ai;
	sag=cokgen_dizisi[0];
	for(ai=0;ai<dizi_boyutu;ai+=2)
	{
		if(cokgen_dizisi[ai]>sag)
		{
			sag=cokgen_dizisi[ai];
		}		
	}
return sag;
}

int en_sol_bulma(int dizi_boyutu,int cokgen_dizisi[])
{
	int sol,ai;
	sol=cokgen_dizisi[0];
	for(ai=0;ai<dizi_boyutu;ai+=2)
	{
		if(cokgen_dizisi[ai]<sol)
		{
			sol=cokgen_dizisi[ai];
		}		
	}
return sol;
}

int icindemi(int uzunluk,int noktax,int noktay,int dizi[])
 {
	int bx[(uzunluk-2)/2];
	int by[(uzunluk-2)/2];
	int ai,aj=0;
	for(ai=0;ai<((uzunluk-2));ai+=2)
	{
		bx[aj]=dizi[ai];
		aj++;
	}
	aj=0;
	for(ai=1;ai<((uzunluk-2));ai+=2)
	{
		by[aj]=dizi[ai];
		aj++;
	}	
	aj=0;

    float alan = alanhesapla(dizi,uzunluk);
    float s = 0.0;
	uzunluk = (uzunluk-2)/2;
	int i,j,a,b;
    for (i = 0; i < uzunluk; i++)
	{
        int x1 = bx[i];
        int y1 = by[i];
        int x2 = bx[(i + 1) % uzunluk];
        int y2 = by[(i + 1) % uzunluk];
        s += fabs((x1 - noktax) * (y2 - noktay) - (x2 - noktax) * (y1 - noktay)) / 2.0;   
    }
if (fabs(alan - s) < 0.000001 ) 
        return 1; 
else 
	{
        return 0;
    }
}

void kontrol2x2(int dizi[],int uzunluk)
{
int i,j,sayac=0,sayac1=0,sayac2=0;	

	for(i=en_sol_bulma(uzunluk,dizi);i<en_sag_bulma(uzunluk,dizi);i+=16)
	{
		for(j=taban_bulma(uzunluk,dizi);j<tavan_bulma(uzunluk,dizi);j+=16)
		{
			if(icindemi(uzunluk,i,j,dizi))
			{
				sayac=0;
				if(icindemi(uzunluk,i-16,j-16,dizi))
				{
				sayac++;
				}
				if(icindemi(uzunluk,i-16,j+16,dizi)) 
				{
				sayac++;
				}
				if(icindemi(uzunluk,i+16,j+16,dizi)) 
				{
				sayac++;
				}
				if(icindemi(uzunluk,i+16,j-16,dizi)) 
				{
				sayac++;
				}
				if(sayac>2)
				{	
				x2kare(i,j);
				sayac1++;
				sayac2++;
				i+=16;
				}
			}	
		if(sayac1>0)
		j+=16;
		}
	}
}

void kontrol4x4(int dizi[],int uzunluk)
{
int i,j,sayac=0,sayac1=0,sayac2=0;
	

	for(i=en_sol_bulma(uzunluk,dizi);i<en_sag_bulma(uzunluk,dizi);i+=16)
	{
		for(j=taban_bulma(uzunluk,dizi);j<tavan_bulma(uzunluk,dizi);j+=16)
		{
			if(icindemi(uzunluk,i,j,dizi))
			{
				sayac=0;
				if(icindemi(uzunluk,i-16,j-16,dizi))
				{
				sayac++;
				}
				if(icindemi(uzunluk,i-16,j+16,dizi)) 
				{
				sayac++;
				}
				if(icindemi(uzunluk,i+16,j+16,dizi)) 
				{
				sayac++;
				}
				if(icindemi(uzunluk,i+16,j-16,dizi)) 
				{
				sayac++;
				}
				if(sayac>2)
				{	
				sayac1++;
				sayac2++;
				x4kare(i,j);
				i+=32;
				}
			}						
		if(sayac1>0)
		j+=32;
		if(sayac1>1)
		i=i-16-16*sayac1;
		sayac1=0;	
		}
	}
}


int kontrol2x2v(int dizi[],int uzunluk)
{
int i,j,sayac=0,sayac1=0,sayac2=0;	

	for(i=en_sol_bulma(uzunluk,dizi);i<en_sag_bulma(uzunluk,dizi);i+=16)
	{
		for(j=taban_bulma(uzunluk,dizi);j<tavan_bulma(uzunluk,dizi);j+=16)
		{
			if(icindemi(uzunluk,i,j,dizi))
			{
				sayac=0;
				if(icindemi(uzunluk,i-16,j-16,dizi))
				{
				sayac++;
				}
				if(icindemi(uzunluk,i-16,j+16,dizi)) 
				{
				sayac++;
				}
				if(icindemi(uzunluk,i+16,j+16,dizi)) 
				{
				sayac++;
				}
				if(icindemi(uzunluk,i+16,j-16,dizi)) 
				{
				sayac++;
				}
				if(sayac>2)
				{	
				sayac1++;
				sayac2++;
				i+=16;
				}
			}	
		if(sayac1>0)
		j+=16;
		}
	}
	return sayac2;
}

int kontrol4x4v(int dizi[],int uzunluk)
{
	
	int i,j,sayac=0,sayac1=0,sayac2=0;
	

	for(i=en_sol_bulma(uzunluk,dizi);i<en_sag_bulma(uzunluk,dizi);i+=16)
	{
		for(j=taban_bulma(uzunluk,dizi);j<tavan_bulma(uzunluk,dizi);j+=16)
		{
			if(icindemi(uzunluk,i,j,dizi))
			{
				sayac=0;
				if(icindemi(uzunluk,i-16,j-16,dizi))
				{
				sayac++;
				}
				if(icindemi(uzunluk,i-16,j+16,dizi)) 
				{
				sayac++;
				}
				if(icindemi(uzunluk,i+16,j+16,dizi)) 
				{
				sayac++;
				}
				if(icindemi(uzunluk,i+16,j-16,dizi)) 
				{
				sayac++;
				}
				if(sayac>2)
				{	
				sayac1++;
				sayac2++;
				i+=32;
				}
			}						
		if(sayac1>0)
		j+=32;
		if(sayac1>1)
		i=i-16-16*sayac1;
		sayac1=0;	
		}
	}
	return sayac2;
}

void boya(int dizi[],int uzunluk)
{
int kont,i,j;
for(i=en_sol_bulma(uzunluk,dizi)+16;i<en_sag_bulma(uzunluk,dizi);i+=16)
	{
	for(j=taban_bulma(uzunluk,dizi)+16;j<tavan_bulma(uzunluk,dizi);j+=16)
		{
			kont = icindemi(uzunluk,i,j,dizi);
			if(kont)
			{
			setcolor(8);
			x2kare(i,j);
			}
		}
	}
}


int main(){
	system("curl http://bilgisayar.kocaeli.edu.tr/prolab1/prolab1.txt >koordinatlar.txt");
	FILE *dosya;
	
	char dizi[100];
	char *karakter;
	dosya = fopen("koordinatlar.txt","r");
	int tercih;
	printf("\nHangi satiri cizdirmek istersiniz:");
	scanf("%d",&tercih);
 
	int i=1;	
	do
	{
	karakter=fgets(dizi,100,dosya);
		
	if (tercih==i)
		{
			break;
		}
	else 
		{
			i++;
			continue;
		}		
	}while(karakter!=NULL);	
	fclose(dosya);

	char eleme2=',';
	char eleme3='F';	
	char *ilkay;
	
	for(ilkay=dizi;*ilkay;ilkay++)
	{
		if(*ilkay==40)
		{
			strcpy(ilkay,ilkay+1);						
		}
		else if(*ilkay==41)
		{
			*ilkay=' ';		
		}	else if(*ilkay==eleme2)
		{
			*ilkay=' ';		
		}	else if(*ilkay==eleme3)
		{
			strcpy(ilkay,ilkay+1);				
		}
	}

	char yenidizi111[500];
	int j;
	if(tercih>99)
	{
		j=4;	
	}
	else if(tercih>9 && tercih<100)
	{
		j=3;
	}
	else
	{
		j=2;
	}
	
	for(i=0;i<300;i++)
	{
		yenidizi111[i]=dizi[j];
		j++;
	}
			
	char array[200];	
	int a=0;
	for(i=0;i<100;i++)
	{
		if(yenidizi111[i]==' ')
		{
			array[a]=i;			// array dizisi bosluklarýn oldugu indeksi tutmakta
			a++;//bosluk sayisi		
		}	
	}

int b=a-1; //dizinin sonda 1 tane fazla boslugu var
if(a%2==0)
{
	b++;
}

	int sayi[b];
	sscanf(yenidizi111,"%d",&sayi[0]);
	for(i=0;i<b;i++) // a+1 toplam eleman sayisi
	{
		sscanf(yenidizi111+array[i],"%d",&sayi[i+1]);
	}

	int uzunluk;
	uzunluk=sizeof(sayi)/sizeof(sayi[0]);
   
	int dizi1[20]={0};
	int dizi2[20]={0};     
	int dizi3[20]={0};
	int sayac=0;	
	int dizisayac[5]={0};
	int artan=0;
	for(i=0;i<uzunluk;i+=2)
	{
		for(j=6;j<uzunluk;j+=2)
		{
			if(sayi[i]==sayi[j] && sayi[i+1]==sayi[j+1]&& i!=j&&j>i)
			{	
				dizisayac[artan]=j+2; 			//dizisayac her bir cokgenin uzunlugunu tutuyor
				artan++;
				sayac++;
			}	
		}
	}
int uz1=0,uz2=0,uz3=0;
	
	if(sayac==1)
	{
		for(i=0;i<uzunluk;i++)
		{
			dizi1[i]=sayi[i];
		}
		uz1=uzunluk;
	}
	else if(sayac==2)
	{
		j=0;
		for(i=0;i<dizisayac[0];i++)
		{
			dizi1[i]=sayi[i];
		}
		for(i=dizisayac[0];i<uzunluk;i++)
		{
			dizi2[j]=sayi[i];
			j++;
		}	
		uz1=dizisayac[0];
		uz2=uzunluk-dizisayac[0];	
	}
	else if(sayac==3)
	{
		j=0;
		for(i=0;i<dizisayac[0];i++)
		{
			dizi1[i]=sayi[i];
		}
		for(i=dizisayac[0];i<dizisayac[1];i++)
		{
			dizi2[j]=sayi[i];
			j++;
		}
		j=0;
		for(i=dizisayac[1];i<uzunluk;i++)
		{
			dizi3[j]=sayi[i];
			j++;
		}	
		uz1=dizisayac[0];
		uz2=dizisayac[1]-dizisayac[0];
		uz3=uzunluk-dizisayac[1];
	}
	float alan1=alanhesapla(dizi1,uz1),alan2=alanhesapla(dizi2,uz2),alan3=alanhesapla(dizi3,uz3);

int	bsm,pm;	//fonksiyon islemleri optimizasyon icin
float trd=0,krd1 = alan1 * 10,krd2 = alan2 * 10,krd3 = alan3 * 10;
	printf("\nBirim sondaj maaliyetini 1 ile 10 arasinda olucak sekilde giriniz:");
	scanf("%d",&bsm);
	printf("\nPlatform maaliyetini giriniz:");
	scanf("%d",&pm);
int tsm;
trd = krd1+krd2+krd3;
printf("\nToplam rezerv degerimiz:%f\n",trd);

	// CIZIM	
initwindow(1920,1080);
for(i=0;i<uz1;i++)	
{ 
	dizi1[i]=dizi1[i]*16;		
}
for(i=0;i<uz2;i++)
{
	dizi2[i]=dizi2[i]*16;
}
for(i=0;i<uz3;i++)
{
	dizi3[i]=dizi3[i]*16;
}	
	
	setbkcolor(15);
	cleardevice();
	
	setcolor(8);
	boya(dizi1,uz1);
	boya(dizi2,uz2);	
	boya(dizi3,uz3);
	
	setcolor(3); 
	for (i=0;i<2500;i+=16)
	{
	line(0,i,2500,i);		
	}
	for (i=0;i<2500;i+=16)
	{
	line(i,0,i,2500);		
	}
	
	setcolor(0); 
	drawpoly((uz1/2),dizi1);
	drawpoly(uz2/2,dizi2);
	drawpoly(uz3/2,dizi3);	

    while (!kbhit()) {//tusa basana kadar dongu sonsuza kadar donuyo
	}
 
	cleardevice();
	
	setbkcolor(15); //2. asama
	cleardevice();
	 
	setcolor(8); 
	kontrol2x2(dizi1,uz1);
	kontrol2x2(dizi2,uz2);
	kontrol2x2(dizi3,uz3);

	setcolor(14);
	kontrol4x4(dizi1,uz1);
	kontrol4x4(dizi2,uz2);
	kontrol4x4(dizi3,uz3);

	setcolor(3);
	for (i=0;i<2500;i+=16)
	{
	line(0,i,2500,i);		
	}
	for (i=0;i<2500;i+=16)
	{
	line(i,0,i,2500);		
	}
	setcolor(0);
	for (i=0;i<2500;i+=64)
	{
	line(0,i,2500,i);		
	}
	for (i=0;i<2500;i+=64)
	{
	line(i,0,i,2500);		
	}	
	
	setcolor(4); 
	drawpoly(uz1/2,dizi1); 
	drawpoly(uz2/2,dizi2);
	drawpoly(uz3/2,dizi3);
	
float kar;
int selam1 = kontrol4x4v(dizi1,uz1)+kontrol4x4v(dizi2,uz2)+kontrol4x4v(dizi3,uz3);
int selam2 = kontrol2x2v(dizi1,uz1)+kontrol2x2v(dizi2,uz2)+kontrol2x2v(dizi3,uz3);
tsm = bsm * (16*selam1 + 4*selam2);
kar = trd - (  (bsm*16*selam1 + 4*selam2) + (selam2+selam1)*pm );
printf("\nToplam platform sayisi:%d\n",selam1+selam2);
printf("\nToplam sondaj sayisi:%d\n",(16*selam1 + 4*selam2));
printf("\nToplam platform maaliyeti:%d\n",(selam2+selam1)*pm);
printf("\nToplam sondaj maaliyeti:%d\n",tsm);
printf("\nToplam maaliyet:%d\n",tsm+(selam2+selam1)*pm);
printf("\nKar zarar durumunuz:%f\n",kar);  

delay(21032005);
closegraph();
    return 0;
}
