#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define CANT 5

struct compu
{
    int velocidad; //entre 1 y 3
    int anio;      //entre 2015 y 2022
    int cantidad;  //entre 1 y 8
    char *tipo_cpu;//de tipos
};
typedef struct compu pc;
char tipos[6][10]= {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

void cargar_pc(pc *compu);
void mostrar_pc(pc *compu);
pc compu_vieja(pc vect[]);
pc compu_veloz(pc vect[]);
int main()
{
    srand(time(NULL)); //inicializa el generador de numeros aleatorios
    pc vectComp[CANT];
    pc pc_vieja;
    pc pc_veloz;


    
    for (int i = 0; i < CANT; i++)
    {
        printf("--Maquina numero %d--\n", i + 1);
        cargar_pc(&vectComp[i]);
        mostrar_pc(&vectComp[i]);
    }
    pc_vieja= compu_vieja(vectComp);
    printf("-----PC mas antigua-----\n");
    mostrar_pc(&pc_vieja);
    printf("-----PC con mayor velocidad-----\n");
    pc_veloz= compu_veloz(vectComp);
    mostrar_pc(&pc_veloz);
    getchar();

    return 0;
}

void cargar_pc(pc *compu)
{
    compu->anio= 2015 + rand()% 8;
    compu->cantidad= 1 + rand()% 3;
    compu->velocidad= 1 + rand()% 8;
    compu->tipo_cpu= tipos[rand()% 6];
}
void mostrar_pc(pc *compu)
{
    printf("Anio: %d\n", compu->anio);
    printf("Velocidad: %d\n", compu->velocidad);
    printf("Cantidad de nucleos: %d\n", compu->cantidad);
    printf("Tipo de procesador: ");puts(compu->tipo_cpu);printf("\n");
}
pc compu_vieja(pc vect[])
{
    pc pcVieja;
    int anio= 2999;
    for (int i = 0; i < CANT; i++)
    {
        if (vect[i].anio < anio)
        {
            pcVieja= vect[i];
            anio= vect[i].anio;
        }
    }
    return pcVieja;
}
pc compu_veloz(pc vect[])
{
        pc pcVeloz;
    int velocidad= 0;
    for (int i = 0; i < CANT; i++)
    {
        if (vect[i].velocidad > velocidad)
        {
            pcVeloz= vect[i];
            velocidad= vect[i].velocidad;
        }
    }
    return pcVeloz;
}