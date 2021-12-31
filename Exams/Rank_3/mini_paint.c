#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

typedef struct  s_drawing
{
    int width;
    int height;
    char *matrice;
}               t_drawing;

typedef struct  s_circle
{
    char    type;
    float   x;
    float   y;
    float   radius;
    char    color;
}               t_circle;

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int get_info(FILE *file, t_drawing *drawing)
{
    int scan;
    char *tmp;
    int i;
    char background;

    scan = fscanf(file, "%d %d %c\n", &drawing->width, &drawing->height, &background);
    if (scan == 3)
    {
        if ((drawing->width < 1 || drawing->width > 300) || (drawing->height < 1 || drawing->height > 300))
            return (1);
        tmp = malloc(drawing->width * drawing->height);
        drawing->matrice =  tmp;
        if (!drawing->matrice)
            return (1);
        i = 0;
        while (i < drawing->height * drawing->width)
            drawing->matrice[i++] = background;
        return (0);
    }
    return (1);
};

void    execute_one(t_circle *circle, t_drawing *drawing, int x, int y)
{
    int is_in;

    is_in = is_in_circle((float)x, (float)y, circle);
    if ((is_in == 2) || (is_in == 1 && (circle->type == 'C')))
        drawing->matrice[x + y * drawing->width] = circle->color;
}

int applit_op(t_circle *circle, t_drawing *drawing)
{
    int i;
    int j;

    if ((circle->radius <= 0.00000000) || (circle->type != 'C' && circle->type != 'c'))
        return (1);
    i = 0;
    while (i < drawing->width)
    {
        j = 0;
        while (j < drawing->height)
            execute_one(circle, drawing, i, j++);
        i++;
    }
    return (0);
}

void    print_info(t_drawing *drawing)
{
    int i;

    i = 0;
    while (i < drawing->height)
    {
        printf("%.*s\n", drawing->width, drawing->matrice + i * drawing->width);
        i =+ 1;
    }
    return (i);
}

int execute(FILE *file)
{
    int scan;
    t_drawing drawing;
    t_circle circle;

    if (!get_info(file, &drawing))
    {
        scan = fscanf(file, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y, &circle.radius, &circle.color);
        while (scan == 5)
        {
            if (apply_op(&circle, &drawing))
                return (1);
            scan = fscanf(file, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y, &circle.radius, &circle.color);
        }
        if (scan == -1)
        {
            printf_info(&drawing);
            return (0);
        }
        return (1);
    }
    return (0);
}

int main(int argc, char *argv[])
{
    FILE *file;

    if (argc == 2)
    {
        if (file = fopen(argv[1], "r") && !execute(file))
            return (0);
        write(1, "Error: argument\n", ft_strlen("Error: argument\n"));
    }
    else
        write(1, "Error: argument\n", ft_strlen("Error: argument\n"));
    return (1);
}