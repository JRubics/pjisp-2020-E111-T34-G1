#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 20+1
#define MAX_JEDINICA 2+1
#define MAX_NIZ 30

struct drvo_st {
    char naziv[MAX_NAZIV];
    double visina;
};

struct visina_st {
    char naziv[MAX_NAZIV];
    double visina;
    char jedinica[MAX_JEDINICA];
};


FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj_drvo(FILE *in, struct drvo_st drvece[], int *n);
char *odredi_najvecu_visinu(struct drvo_st drvece[], int n);
void transform(struct drvo_st drvece[], struct visina_st visine[], int n, double konverzija, char* jedinica);
void snimi_visinu(FILE *out, struct visina_st visine[], int n);


int main(int arg_num, char **args) {
    if (arg_num != 5) {
        printf("USAGE: %s KONVERZIJA JEDINICA IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(42);
    }

    double konverzija = atof(args[1]);
    char *jedinica = args[2];
    char *in_filename = args[3];
    char *out_filename = args[4];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    struct drvo_st drvece[MAX_NIZ];
    struct visina_st visine[MAX_NIZ];
    int n;

    ucitaj_drvo(in, drvece, &n);
    transform(drvece, visine, n, konverzija, jedinica);
    snimi_visinu(out, visine, n);
    fprintf(out, "\nDrvo sa najvecom prosecnom visinom je: %s", odredi_najvecu_visinu(drvece, n));

    fclose(in);
    fclose(out);

    return 0;
}

FILE *safe_fopen(char filename[], char mode[], int error_code) {
    FILE *fp = fopen(filename, mode);
    if(fp == NULL) {
        printf("Can't open '%s'!\n", filename);
        exit(error_code);
    }
    return fp;
}

void ucitaj_drvo(FILE *in, struct drvo_st drvece[], int *n) {
    *n = 0;
    while(fscanf(
        in, "%s %lf",
         drvece[*n].naziv,
        &drvece[*n].visina
    ) != EOF) {
        (*n)++;
    }
}

void transform(struct drvo_st drvece[], struct visina_st visine[], int n, double konverzija, char* jedinica){
    int i;
    for(i=0; i<n; i++) {
        strcpy(visine[i].naziv, drvece[i].naziv);
        visine[i].visina = drvece[i].visina * konverzija;
        strcpy(visine[i].jedinica, jedinica);
    }
}

void snimi_visinu(FILE *out, struct visina_st visine[], int n) {
    int i;
    for(i=0; i<n; i++) {
        fprintf(
            out, "%s %.1lf %s\n",
            visine[i].naziv,
            visine[i].visina,
            visine[i].jedinica
        );
    }
}

char *odredi_najvecu_visinu(struct drvo_st drvece[], int n){
    int max = drvece[0].visina;
    char* max_naziv = drvece[0].naziv;
    int i;
    for(i=1; i<n; i++) {
        if(drvece[i].visina > max){
            max = drvece[i].visina;
            strcpy(max_naziv, drvece[i].naziv);
        }
    }
    return max_naziv;
}