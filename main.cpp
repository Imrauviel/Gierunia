#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
HANDLE hOut;
void wyswietl();
void pierwsza();
void druga();
void trzecia();
// STRUKRURY
struct bron{
int amunicja;
int dmg;
}pistolet={6, 10};
struct postac{
char imie[20];
int ww;
int us;
int odp;
int zr;
int iq;
int zyw;
}bohater, zbir={"Blazej",20,20,20,20,20,5}, test={"Kajetan",40,40,40,40,40,10};
void wrecz(postac op);
void wreczop(postac op);
//-------------------------------
// GRA
void poczatek()
{
    cout<<"Witaj w naszej grze. Przeprowadzam test: "<<endl;
    cout<<"1."<<endl<<"2."<<endl<<"3."<<endl;
    int k;
    cin>>k;
    if(k==1) pierwsza();
    if(k==2) druga();
    if(k==3) trzecia();
}
void pierwsza()
{
    wyswietl();
    cout<< "Gratuluje przejdz do 2"<<endl;
    int k; cin>>k;
    if(k==2)druga();
}
void druga()
{
    wyswietl();
    cout<<"WoW, udalo ci sie";
}
void trzecia()
{
    wyswietl();
}
// ------------------
//Walak
void walka(postac op, int odl)
{
    system("CLS");
    Sleep(700);
        cout<<"In the right corrnner "<<test.imie<<" the great"<<endl;
        Sleep(1000);
        cout<<"His opponnent is "<<op.imie<<" the weak"<<endl;
        Sleep(1000);
        cout<<"Get redddddyyyy for rumble"<<endl;
        Sleep(1000);

        do{
            cout<<"Dzeili was "<<odl<<" metrow. Co chcesz zrobic:"<<endl;
            cout<<"1. Zatakuj go z bliska (tylko jesli jestes na mniej niz 5 metrow) "<<endl;
            cout<<"2. Postrzel go (tylko jak masz bron) "<<endl;
            cout<<"3. Przyceluj "<<endl;
            cout<<"4. Przygotuj sie do parowania "<<endl;
            cout<<"5. Podejdz"<<endl;
            cout<<"6. Uciekaj"<<endl;
            char k; cin>>k;
            switch (k)
            {
            case '1':
                wrecz(op);
                break;
            case '2':
                //strzal()
                break;
            case '3':
                //cel()
                break;
            case '4':
                //par()
                break;
            case '5':
                //podejdz
                break;
            case '6':
                //uciekaj()
                break;
            default:
                cout<<"Zly guzik. Omija cie kolejka za probe oszustwa "<<endl;
                break;
            }
            cout<<"Teraz on"<<endl;
            Sleep(800);
                wreczop(op);
            Sleep(1000);
            system("CLS");
        }while(op.zyw>0&&test.zyw>0);


}
void wrecz( postac op)
{
    cout<<"Probujesz zatakowac go z bliska"<<endl;
    Sleep(100);
    int rzut=(rand()%100)+1;
    if(rzut>test.ww)
    {
        cout<<"nie trafiles :("<<endl;
        Sleep(600);
    }
    else {
            Sleep(100);
             int dmg=(rand()%10+1);
        cout<<"WOW, udalo ci sie. Co to jest za dmg"<<endl;

        if(dmg==10)
        {
            Sleep(100);

            dmg=dmg+(rand()%10)+1;
              cout<<"WOW wszedl kryt jak w maslo"<<endl;
            Sleep(1000);
        }else{
            //nie wszedl kryt
        }
        if(op.odp/10>dmg) dmg=0;
        else dmg=dmg-op.odp/10;
        cout<<"Zadales mu "<<dmg<<endl;
        op.zyw=op.zyw-dmg;
    }

    cout<<"zostalo mu "<<op.zyw<<" HP"<<endl;

}
void wreczop(postac op)
{
        cout<<"Probuje zatakowac cie z bliska"<<endl;
    Sleep(400);
    int rzut=(rand()%100)+1;
    if(rzut>op.ww)
    {
        cout<<"Na szczecie nie trafil :)"<<endl;
        Sleep(700);
    }
    else {
            Sleep(100);
             int dmg=(rand()%10+1);
        cout<<"UUU, to na pewno zaboli "<<endl;

        if(dmg==10)
        {
            Sleep(100);

            dmg=dmg+(rand()%10)+1;
            cout<<"Zobacz czy masz wszystkie konczyny na miescu. KRYTYK!!!!"<<endl;
            Sleep(1200);
        }else{
        }
        if(test.odp/10>dmg) dmg=0;
        else dmg=dmg-test.odp/10;
        cout<<"Zadal ci "<<dmg;
        test.zyw=test.zyw-dmg;
    }
    cout<<"Zostalo ci "<<test.zyw<<" HP"<<endl;
    Sleep(1000);
}
void strzal(postac op)
{
    cout<<"Probujesz postrzelic go na smierc"<<endl;
    Sleep(100);
    int rzut=(rand()%100)+1;
    if(rzut>test.us)
    {
        cout<<"Niestety, nie trafiles :("<<endl;
        Sleep(600);
    }
    else {
            Sleep(100);
             int dmg=(rand()%10+1)+pistolet.dmg;
        cout<<"WOW, udalo ci sie. Krwawi skurczy syn. Co to jest za dmg: "<<dmg<<endl;

        if(dmg==10)
        {
            Sleep(100);
            cout<<"WOW wszedl kryt jak w sicane piachu. Zadales mu: "<<dmg<<endl;
            dmg=dmg+(rand()%10)+1;
            op.zyw=op.zyw-dmg;
            Sleep(1500);
        }else{
        op.zyw=op.zyw-dmg;

        Sleep(1500);
        }
    }

}
//--------------------
//WYSWIETLANIE
void wyswietl()
{
    Sleep(200);
    system("CLS");
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
    cout<<"Twoja postac ma na imie: "<<bohater.imie<<endl;
    cout<<"Walki Wrecz: "<<bohater.ww<<endl;
    cout<<"Umietnosci Strzelckich: "<<bohater.us<<endl;
    cout<<"Odpornosci: "<<bohater.odp<<endl;
    cout<<"Zrecznosci: "<<bohater.zr<<endl;
    cout<<"Inteligenci: "<<bohater.iq<<endl;
    cout<<"Zywotnosci: "<<bohater.zyw<<endl;

    SetConsoleTextAttribute( hOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
    Sleep(200);
}
void nowapostac()
{
    cout<<"Zacznijmy od stworzenia nowej postaci"<<endl;
    cout<<"Jej imie to: ";
    cin>>bohater.imie;
    cout<<"Teraz przejdzmy do losowania cech"<<endl;
    Sleep(1600);
    system("CLS");
    cout<<"Na Ekranie zostana pokazane ci wylosowane wyniki"<<endl;
    Sleep(500);
    int w1=(rand() % 10 ) + 1;
    int w2=(rand() % 10 ) + 1;
    int u1=(rand() % 10 ) + 1;
    int u2=(rand() % 10 ) + 1;
    int od1=(rand() % 10 ) + 1;
    int od2=(rand() % 10 ) + 1;
    int zr1=(rand() % 10 ) + 1;
    int zr2=(rand() % 10 ) + 1;
    int iq1=(rand() % 10 ) + 1;
    int iq2=(rand() % 10 ) + 1;
    int zyw1=(rand() % 10 ) + 1;
    int zyw2=(rand() % 10 ) + 1;
    cout<<"Walki Wrecz: "<<w1+w2<<endl;
    cout<<"Umietnosci Strzelckich: "<<u1+u2<<endl;
    cout<<"Odpornosci: "<<od1+od2<<endl;
    cout<<"Zrecznosci: "<<zr1+zr2<<endl;
    cout<<"Inteligenci: "<<iq1+iq2<<endl;
    cout<<"Zywotnosci: "<<zyw1+zyw2<<endl;
    Sleep(600);
    cout<<endl;
    cout<<"Oczywicie wyniki moge ci nie pasowac, wybierz co chcesz zrobic: "<<endl;
    cout<<"1.Zostawic"<<endl;
    cout<<"2.Usatwic wyszytkie na 11"<<endl;
    cout<<"3.Samodzielnie rozdac 60 punktow"<<endl;
    int w;cin>>w;
    Sleep(300);
    switch (w)
    {
    case 1:
        bohater.ww=w1+w2+20;
        bohater.us=u1+u2+20;
        bohater.odp=od1+od2+20;
        bohater.zr=zr1+zr2+20;
        bohater.iq=iq1+iq2+20;
        bohater.zyw=(zyw1+zyw2+20)/4;
        break;
    case 2:
        bohater.ww=31;
        bohater.us=31;
        bohater.odp=31;
        bohater.zr=31;
        bohater.iq=31;
        bohater.zyw=8;
        break;
    case 3:
        {
        int pojemnik=36;
        int w=4, u=4, o=4, z=4, i=4, y=4;

        do
        {
            system("CLS");
            cout<<"Karzda cecha na star ma 4 punkty, a maskmyalnie moze miec 18"<<endl<<"Pozostalo ci "<<pojemnik<<" punktow"<<endl;
            cout<<endl;
            cout<<"Wybierz ceche, ktora chcesz ulepszyc"<<endl;
            cout<<"1.Walki Wrecz            "<<" Aktulanie masz "<<w<<endl;
            cout<<"2.Umietnosci Strzelckich "<<" Aktulanie masz "<<u<<endl;
            cout<<"3.Odpornosci             "<<" Aktulanie masz "<<o<<endl;
            cout<<"4.Zrecznosci             "<<" Aktulanie masz "<<z<<endl;
            cout<<"5.Inteligenci            "<<" Aktulanie masz "<<i<<endl;
            cout<<"6.Zywotnosci             "<<" Aktulanie masz "<<y<<endl;
            int c; cin>>c;
            cout<<"Ile chcesz dodac"<<endl;
            int ilosc; cin>>ilosc;
            if(ilosc>pojemnik)
            {
                    cout<<"za duzo"<<endl;
system("CLS");
            }else
            switch (c)
            {
            case 1:
                {
                    w=w+ilosc;
                    if(w>18) w=18;
                    pojemnik = pojemnik-ilosc;
                    break;
                }
            case 2:
                {
                    u=u+ilosc;
                    if(u>18) u=18;
                    pojemnik = pojemnik-ilosc;
           system("CLS");         break;
                }
            case 3:
                {
                    o=o+ilosc;
                    if(o>18) o=18;
                    pojemnik = pojemnik-ilosc;

                    break;
                }
            case 4:
                {
                    z=z+ilosc;
                    if(z>18) z=18;
                    pojemnik = pojemnik-ilosc;
                    break;
                }
            case 5:
                {
                    i=i+ilosc;
                    if(i>18) i=18;
                    pojemnik = pojemnik-ilosc;
                    break;
                }
            case 6:
                {
                    y=y+ilosc;
                    if(y>18) y=18;
                    pojemnik = pojemnik-ilosc;
                    break;
                }
            default:
                {cout<<"nie masz takiej cechy"<<endl;
                }
         system("CLS");
            }
        }while(pojemnik!=0);

        bohater.ww=20+w;
        bohater.us=20+u;
        bohater.odp=20+o;
        bohater.zr=20+z;
        bohater.iq=20+i;
        bohater.zyw=(20+y)/4;
        break;
         system("CLS");
        }
            default:
                {


    }
    cout<< "Zly przycisk baranie"<<endl;
                    break;
                    }
        cout<<"Gratulacje!!!!"<<endl<<"Rozdales wszystkie punkty. Mozesz zaczac gre"<<endl;
        Sleep(2000);
        system("CLS");


}
void menu()
{
     cout<<"MENU:"<<endl;
    cout<<"1.Instrukcja"<<endl;
    cout<<"2.Rozpocznij gre "<<endl;
    cout<<"3.Zakoncz gre "<<endl;
    cout<<"4.Walka"<<endl;
    int l; cin>>l;
    switch (l)
    {
   case 1:
    cout<<"tu marcel wklei instrukcje"<<endl;
    cout<<"aby wrocic do menu, kliknij 1."<<endl;
    int z; cin>>z;
    if(z==1)
    {
        menu();
        system("CLS");
    }
    else
    {
        cout<<"Zly numer baranie"<<endl;
        menu();
    }
    break;
    case 2:
        cout<<"Zaraz zaraz nie masz postac"<<endl;
        Sleep(800);
        system("CLS");
        nowapostac();
        poczatek();
    break;
    case 3:
/////////////
    break;
    case 4:
        walka(zbir,50);
        break;
    default:
        cout<<"Zly numer"<<endl;
        Sleep(400);
        menu();
        break;

    }
}
//----------------------
int main()
{
    srand( time( NULL ) );
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    //MENU
    menu();

    return 0;
}



