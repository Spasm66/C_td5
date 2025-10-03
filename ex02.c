#include <stdio.h>
#include <stdlib.h>

typedef struct{
float x;
float y;
}Point;

Point   *alloc(int lenght) {
    Point   *tab;

    tab = malloc(sizeof(Point) * lenght);
    
    if (tab == NULL) {
        fprintf(stderr, "Memory allocation failed \n");
        exit(EXIT_FAILURE);
    }
    return (tab);
}

void    fill(Point *t, int index, int x, int y) {
    t[index].x = x;
    t[index].y = y;
}

void    show(Point *t, int lenght) {
    for (int i = 0; i < lenght; i++) {
        printf("Point %d : (%f,%f)\n", i+1, t[i].x, t[i].y);
    }
}

Point   *fill_param(Point *t, int argc, char **argv) {
    int l;
    int i, j;

    if (!(argc-1)%2 && argc > 0)
        exit(EXIT_FAILURE);
    l = (argc-1)/2;
    t = alloc(l);
    for (i = 1, j = 0; i < argc; i += 2, j++) {
        t[j].x = atof(argv[i]);
        t[j].y = atof(argv[i+1]);
    }
    return (t);
}

void    free_pt(Point *t) {
    free(t);
}

int     main(int argc, char **argv) {
    Point   *t;

    t = fill_param(t, argc, argv);
    show(t, (argc-1)/2);
    free_pt(t);
}