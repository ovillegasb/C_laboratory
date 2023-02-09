
// A test program.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// // Includinf header file
// #include "mathOp.h"

// #define NATOMS 6

float positionRand(float L_init, float L_final);

int main(void)
{
    printf("Welcome to DrunkParticle!\n");

    // // Given two numbers
    // int a = 13, b = 22;
    // printf("Sum is: %d\n", sum(a, b));


    // System information:
    int Natoms;
    puts("Enter number of atoms:");
    scanf("%d", &Natoms);

    int atid[Natoms];
    float x[Natoms], y[Natoms], z[Natoms];
    char *atsb[Natoms];

    // Trajectory information:

    // time in ps
    float time = 0.0;

    FILE *groPtr;

    // Box limits in X (nm)
    float L_xi = 0.0, L_xf = 4.0;

    // <print informationset elements of array n to 0
    for (size_t i = 0; i < Natoms; ++i){
        atid[i] = 0; // set ele;ent at location i to 0
        atsb[i] = "He";
        x[i] = positionRand(L_xi, L_xf);
        y[i] = positionRand(L_xi, L_xf);
        z[i] = positionRand(L_xi, L_xf);
    }

    float Lx, Ly, Lz;
    Lx = abs(L_xi - L_xf);
    Ly = abs(L_xi - L_xf);
    Lz = abs(L_xi - L_xf);


    printf("%s%13s%13s%13s\n", "Element", "index", "Symbol", "x");

    // output contents of array n in tabular format
    for (size_t i = 0; i < Natoms; ++i){
        printf("%7lu%13d%13s%13.3f\n", i, atid[i], atsb[i], x[i]);
    }

    printf("Box dimension:\n");
    printf("\tx: %.3f, %.3f\n", L_xi, L_xf);

    // printf("%s\n", "Positions");

    // float posx = positionRand(L_xi, L_xf);
    // printf("%f\n", posx);


    // Save trajectory in Gro file.
    groPtr = fopen("confout.gro", "w");

    // title and time.
    fprintf(groPtr, "GRO file, t=%.3f\n", time);
    fprintf(groPtr, "%5d\n", Natoms);

    for (int i = 0; i < Natoms; ++i){
        fprintf(groPtr, "%5d%-5s%5s%5d%8.3f%8.3f%8.3f\n", i + 1, "GAS", atsb[i], atid[i], x[i], y[i], z[i]);
    }

    fprintf(groPtr, "%10.5f%10.5f%10.5f\n", Lx, Ly, Lz);
    fclose(groPtr);

    puts("File gro saved");
}


float positionRand(float L_init, float L_final){
    // randomize random number generator using current time
    // srand(time(NULL));
    // float rn = (float)rand()/RAND_MAX;
    float L = abs(L_final - L_init);

    return (float)rand()/RAND_MAX * L - L_init;
}