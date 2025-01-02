#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// PARA ENTENDER DOBLE PUNTERO 
// Función que imprime un array de strings
void imprimirStrings(char **strings, int cantidad)
{
    int i;

    i = 0;
    while (i < cantidad)
    {
        write(1, strings[i], i + 1);
        i++;
    }
}
// Función que crea un array dinámico de strings
char**  crearArrayStrings(int cantidad)
{
    char **strings;
    strings = (char**)malloc(cantidad * sizeof(char*));    // Reservamos memoria para el array de punteros
    if (strings == NULL)
        return (NULL);
    return (strings);
}
// Función para agregar un string al array
void agregarString(char **strings, int posicion, const char *nuevo_string)
{
    strings[posicion] = (char*)malloc((strlen(nuevo_string) + 1) * sizeof(char));    // Reservamos memoria para el nuevo string (incluyendo el carácter nulo)
    if (strings[posicion] == NULL)
        return ;
    ft_strlcpy(strings[posicion], nuevo_string);    // Copiamos el string a la memoria reservada
}
// Función para dividir un string al array
char	**ft_split(char const *s, char c)
{
    char    **resultado;
    char    *strCopy;
    int     *count;

    *count = contarDelimitadores(str, delim) + 1;    // Primero contamos cuántas partes tendremos
    resultado = (char**)malloc(*count * sizeof(char*));    // Reservamos memoria para el array de strings (punteros)
    if (resultado == NULL)
        return (NULL);
    strCopy = (char*)malloc(ft_strlen(str) + 1);    // Hacemos una copia del string original porque strtok lo modifica 
    ft_strlcpy(strCopy, s);
    
    char *token = strtok(strCopy, delim);    // Obtenemos el primer token 
    int i = 0;
    while (token != NULL && i < *count)
    {
        resultado[i] = (char*)malloc(strlen(token) + 1);        // Reservamos memoria para este token específico 
        if (resultado[i] == NULL)
        {
            j = 0;
            while (j < i)            // Liberamos la memoria ya reservada 
            {
                free(resultado[j]);
                j++;
            }
            free(resultado);
            free(strCopy);
            return (NULL);
        }
        ft_strlcpy(resultado[i], token);        // Copiamos el token a su posición en el array
        token = strtok(NULL, delim);        // Obtenemos el siguiente token
        i++;
    }
    free(strCopy);    // Liberamos la copia temporal
    return (resultado);
}
// Función para liberar la memoria del resultado
void liberarSplit(char **strings, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        free(strings[i]);
        i++;
    }
    free(strings);
}
// Función que cuenta cuántas veces aparece un delimitador en el string
int contarDelimitadores(const char *str, const char *delim)
{
    int count = 0;
    char *temp = strstr(str, delim);

    while (temp != NULL)
    {
        count++;
        temp = strstr(temp + strlen(delim), delim);
    }
    return (count);
}

int main(void)
{
    printf("--- Método 1: Array estático de strings ---\n");    // Método 1: Array estático de strings
    char *frutas[] = {"Manzana", "Banana", "Naranja", "Pera"};
    int num_frutas = sizeof(frutas) / sizeof(frutas[0]);
    
    printf("Frutas disponibles:\n");
    imprimirStrings(frutas, num_frutas);

    printf("\n--- Método 2: Array dinámico de strings ---\n");    // Método 2: Array dinámico de strings
    int num_colores = 3;
    char **colores = crearArrayStrings(num_colores);
    
    agregarString(colores, 0, "Rojo");    // Agregamos strings al array
    agregarString(colores, 1, "Verde");
    agregarString(colores, 2, "Azul");

    printf("Colores disponibles:\n");
    imprimirStrings(colores, num_colores);

    printf("\n--- Modificando un string ---\n");    // Modificación de un string 
    free(colores[1]); // Liberamos la memoria del string anterior 
    agregarString(colores, 1, "Amarillo"); // Agregamos el nuevo string 

    printf("Colores después de la modificación:\n");
    imprimirStrings(colores, num_colores);

    printf("\n--- Ordenando strings ---\n");    // Ordenamiento de strings (usando selección) 
    for(int i = 0; i < num_colores - 1; i++)
    {
        for(int j = i + 1; j < num_colores; j++)
        {
            if(ft_strlcmp(colores[i], colores[j]) > 0)
            {
                char *temp = colores[i];                // Intercambiamos los punteros
                colores[i] = colores[j];
                colores[j] = temp;
            }
        }
    }

    printf("Colores ordenados alfabéticamente:\n");
    imprimirStrings(colores, num_colores);

    for(int i = 0; i < num_colores; i++)    // Liberación de memoria 
        free(colores[i]);
    free(colores);

    return (0);
}
