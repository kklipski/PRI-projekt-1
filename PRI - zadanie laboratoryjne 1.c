//Program obliczajacy wartosc podanej calki za pomoca przedstawionego rozwiniecia
#include<stdio.h> //standardowa funkcja
#include<math.h> //funkcje matematyczne
double x, epsilon, S1, S2, S3, W, cc, cu; //deklaracje zmiennych: S1, S2, S3 - wyniki dzialan czesciowych, cc - czesc calkowita podzielonego przez epsilon S3, cu - czesc ulamkowa podzielonego przez epsilon S3
unsigned k1=3, k2, potega1, potega2, s=1, wynik1=1, wynik2, warunki=1, n=1; //deklaracje zmiennych: warunki - sluzy do wykonywania petli while, k1, k2 - liczby w mianownikach (bez silni), s, n, wynik1, wynik2 - zmienne sluzace do licznenia silni
int main()
{
    puts("Podaj x i dokladnosc epsilon, z jaka chcesz liczyc");
    if(scanf("%lf %lf", &x, &epsilon)!=2)
    {
        while(getchar()!='\n');
        puts("Niepoprawne dane\n");
        puts("Nacisnij dowolny przycisk, aby wyjsc");
        getchar();
        return 0;
    }
    else
    {
        if(x<0 || x>1)
        {
            while(getchar()!='\n');
            puts("x spoza zbioru\n");
            puts("Nacisnij dowolny przycisk, aby wyjsc");
            getchar();
            return 0;
        }
        else
        {
            if(epsilon>x)
            {
                while(getchar()!='\n');
                puts("za duzy epsilon\n");
                puts("Nacisnij dowolny przycisk, aby wyjsc");
                getchar();
                return 0;
            }
            else
            {
                if(epsilon>0.1)
                {
                    while(getchar()!='\n');
                    puts("za duzy epsilon\n");
                    puts("Nacisnij dowolny przycisk, aby wyjsc");
                    getchar();
                    return 0;
                }
                else
                {
                    if(epsilon<=0)
                    {
                        while(getchar()!='\n');
                        puts("Niewlasciwy epsilon!\n");
                        puts("Nacisnij dowolny przycisk, aby wyjsc");
                        getchar();
                        return 0;
                    }
                    else
                    {
                        S1=0.0;
                        S2=0.0;
                        S3=0.0;
                        S1=x;
                        while(warunki=1)
                        {
                            potega1=k1;
                            for(n=1; n<=s; n++) //liczenie silni
                            {
                                wynik1*=n;
                            }
                            S2=S1-((pow(x,potega1))/(k1*wynik1));
                            k2=k1+2;
                            potega2=k2;
                            wynik2=wynik1*(s+1);
                            S3=S2+((pow(x,potega2))/(k2*wynik2));
                            W=S3-S1;
                            W=fabs(W); //wartosc bezwzgledna z W
                            if(W<epsilon)
                            {
                                S3=S3/epsilon;
                                cu=modf(S3, &cc); //przypisanie do danych zmiennych czesci: ulamkowej i calkowitej wartosci zmiennej S3
                                if(cu>=0.5)
                                {
                                    cc=cc+1;
                                    cc=cc*epsilon;
                                    printf("Wynik=%lf\n", cc);
                                    while(getchar()!='\n');
                                    puts("Nacisnij dowolny przycisk, aby wyjsc");
                                    getchar();
                                    return 0;
                                }
                                else
                                {
                                    cc=cc*epsilon;
                                    printf("Wynik=%lf\n", cc);
                                    while(getchar()!='\n');
                                    puts("Nacisnij dowolny przycisk, aby wyjsc");
                                    getchar();
                                    return 0;
                                }
                            }
                            else
                            {
                                S1=S3;
                                k1=k2+2;
                                s++; s++;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
