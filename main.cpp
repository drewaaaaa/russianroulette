#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_set>
#include <random>

int  main()
{
    std::string msg="/roulette 4"; //этот кусок кода из другого проекта, поэтому тут строка, надо было проверить правильность обрезки и вообще поэкспериментировать
    unsigned int ammo;
    ammo=std::atoi(msg.substr(10).c_str());//atoi мне наиболее подходил, т.к. не выкидывает исключений
    printf("%d bullet(s)\n", ammo);//сколько патронов зарядили в каморы, в данном случае - 4
    std::random_device rd;
    std::mt19937 mersenne(rd());
    unsigned int num; //куда бьёт боёк, типа как крутанули барабан и выбрали камору, по которой происходит удар
    num=mersenne()%6;//револьвер шестизарядный
    printf("hit hole %d\n", num);//удар пришёлся в камору №
    std::unordered_set<unsigned int> armed;//заряженные дырки. неупорядоченный набор, т.к. одну камору зарядить дважды нельзя, а в каком порядке заряжать - без разницы
    do {
        armed.insert(mersenne()%6);//собственно, наполнение "барабана", он же - неупорядоченный набор
    }
    while (armed.size()<ammo);//заполнение пока не закончатся патроны
    printf ("armed holes: ");//чтобы было явно видно, что программа не врёт
    for (auto &element : armed)
        std::cout << element << ' ';//вывод номеров, в которые попали патроны
    printf("\n");
    if (armed.find(num)!=armed.end()) {//если боёк попал в непустую камору - происходит выстрел
        printf("rip \n");
    }
    else {
        printf("alive \n");//если боёк бьёт по пустой каморе, то выстрел не происходит
    }
    return 0;
}
