#include <stdio.h>
#include <string.h>

int main() {
    int numEstudiantes = 5;
    int numAsignaturas = 3;
    float calificaciones[numEstudiantes][numAsignaturas];
    char nombresEstudiantes[numEstudiantes][50]; 
    char nombresAsignaturas[numAsignaturas][50];
    float sumaEstudiante, sumaAsignatura, promedioEstudiante, promedioAsignatura;
    float notaMasAlta, notaMasBaja;
    int aprobados, reprobados;
    float notaAprobatoria = 6.0; 
   
    printf("Ingrese los nombres de las asignaturas:\n");
    for (int j = 0; j < numAsignaturas; j++) {
        printf("Nombre de la Asignatura %d: ", j + 1);
        fgets(nombresAsignaturas[j], sizeof(nombresAsignaturas[j]), stdin);
       
        nombresAsignaturas[j][strcspn(nombresAsignaturas[j], "\n")] = 0;
    }

    printf("\nIngrese los nombres y calificaciones de los estudiantes:\n");
    for (int i = 0; i < numEstudiantes; i++) {
        printf("Nombre del Estudiante %d: ", i + 1);
        fgets(nombresEstudiantes[i], sizeof(nombresEstudiantes[i]), stdin);
       
        nombresEstudiantes[i][strcspn(nombresEstudiantes[i], "\n")] = 0;

        for (int j = 0; j < numAsignaturas; j++) {
            printf("%s: ", nombresAsignaturas[j]);
            scanf("%f", &calificaciones[i][j]);
        }
       
        while (getchar() != '\n');
    }

    printf("\nPromedios por estudiante:\n");
    for (int i = 0; i < numEstudiantes; i++) {
        sumaEstudiante = 0;
        for (int j = 0; j < numAsignaturas; j++) {
            sumaEstudiante += calificaciones[i][j];
        }
        promedioEstudiante = sumaEstudiante / numAsignaturas;
        printf("%s: %.2f\n", nombresEstudiantes[i], promedioEstudiante); 
    }

    printf("\nPromedios por asignatura:\n");
    for (int j = 0; j < numAsignaturas; j++) {
        sumaAsignatura = 0;
        for (int i = 0; i < numEstudiantes; i++) {
            sumaAsignatura += calificaciones[i][j];
        }
        promedioAsignatura = sumaAsignatura / numEstudiantes;
        printf("%s: %.2f\n", nombresAsignaturas[j], promedioAsignatura); 
    }

    printf("\nCalificaciones más alta y baja por estudiante:\n");
    for (int i = 0; i < numEstudiantes; i++) {
        notaMasAlta = calificaciones[i][0];
        notaMasBaja = calificaciones[i][0];
        for (int j = 1; j < numAsignaturas; j++) {
            if (calificaciones[i][j] > notaMasAlta) {
                notaMasAlta = calificaciones[i][j];
            }
            if (calificaciones[i][j] < notaMasBaja) {
                notaMasBaja = calificaciones[i][j];
            }
        }
        printf("%s: Más alta = %.2f, Más baja = %.2f\n", nombresEstudiantes[i], notaMasAlta, notaMasBaja);
    }

    printf("\nCalificaciones más alta y baja por asignatura:\n");
    for (int j = 0; j < numAsignaturas; j++) {
        notaMasAlta = calificaciones[0][j];
        notaMasBaja = calificaciones[0][j];
        for (int i = 1; i < numEstudiantes; i++) {
            if (calificaciones[i][j] > notaMasAlta) {
                notaMasAlta = calificaciones[i][j];
            }
            if (calificaciones[i][j] < notaMasBaja) {
                notaMasBaja = calificaciones[i][j];
            }
        }
        printf("%s: Más alta = %.2f, Más baja = %.2f\n", nombresAsignaturas[j], notaMasAlta, notaMasBaja);
    }

    printf("\nAprobados y reprobados por asignatura:\n");
    for (int j = 0; j < numAsignaturas; j++) {
        aprobados = 0;
        reprobados = 0;
        for (int i = 0; i < numEstudiantes; i++) {
            if (calificaciones[i][j] >= notaAprobatoria) {
                aprobados++;
            } else {
                reprobados++;
            }
        }
        printf("%s: Aprobados = %d, Reprobados = %d\n", nombresAsignaturas[j], aprobados, reprobados);
    }

    return 0;
}
