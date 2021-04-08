#include <stdio.h> 
#include <string.h>

void *f_memset(void* destination, int c, size_t n){
    size_t i;
    char* mas;
    mas = destination;
    for (i = 0; i < n; i++){
        mas[i] = c;
    }
    return destination;
}
void *f_bzero(void* s, size_t n){
    size_t i;
    char* mas;
    mas = s;
    for (i = 0; i < n; i++){
       mas[i] = '0';
    }
    return s;
}
void *f_memcpy (void *destination, const void *source, size_t n){
    size_t i;
    char* mas1;
    const char* mas2;
    mas1 = destination;
    mas2 = source;
    for (i = 0; i < n; i++){
        mas1[i] = mas2[i];
    }
    return destination;
}
void *f_memccpy (void *destination, const void *source, int c, size_t n){
    size_t i;
    char* mas1;
    const char* mas2;
    mas1 = destination;
    mas2 = source;
    for (i = 0; (i < n) && (mas2[i] != c) ; i++){
        mas1[i] = mas2[i];
    }
    return destination;
}
void *f_memmove (void *destination, const void *source, size_t n){
    char *dest = destination;
    const char *src = source;
    size_t i;
    
    if (dest <= src){
        for (i = 0; i < n; i++){
            dest[i]=src[i];
        }
    }
    else{
        for(i = n; i > 0; i--){
            dest[i - 1] = src[i - 1];
        }
    }
    return(destination);
}
void *f_memchr (const void *arr, int c, size_t n){   
    size_t i;
    const char *array = arr;
    for (i = 0; i < n ; i++)
       if (array[i]== c) {
            printf("f_memchr: Есть пробитие %c\n",array[i]);
            printf("f_memchr: Адрес %p",array + i);
            break;
       }
    return NULL;
}
int f_memcmp (const void *arr1, const void *arr2, size_t n){
    size_t i = 0;
    int status;
    const char *m1 = arr1;
    const char *m2 = arr2;
    while ( m1[i] == m2[i] && i < n)
        i++;
    if (m1[i] == m2[i])
        status = 0;
    else if (m1[i] > m2[i])
        status = 1;
    else 
        status = -1;
    return status;
}
//size_t *strlen (const char *str); 
//char *strdup(const char *str); 
//char *strcpy (char *destination, const char *source); 
//char *strncpy (char *destination, const char *source, size_t n); 
//char *strcat (char *destination, const char *append); 
int main(){
    int v;
    
    char a[15] = "123456789012345";
    char b[15] = "";
    
    char c[15] = "6667654321";
    char d[15] = "";
    
    char mas[15] = "1234567890";
    
    char m[15] = "1234444444";
    
    unsigned char a1[15]="1235";
    unsigned char a2[15]="1235";
    memset (a, '0',10);
    printf("memset: %s\n", a);
    //заполняет n выбраным числом
    f_memset(a , '0', 10);
    printf("f_memset: %s\n", a);
    //заполнят n элементов нулями
    f_bzero(a, 10);
    printf("f_bzero: %s\n", a);
    //копирует содержимое из одной области в другую (массивы не перекрываются)
    f_memcpy(b, a, 15);
    printf("f_memcpy: %s\n", b);
    //копирует n элементов пока не встретит символ (массивы не перекрываются)
    f_memccpy(d, c, '7', 15);
    printf("f_memccpy: %s\n", d);
    //копирует содержимое из одной области в другую (массивы перекрываются)
    f_memmove(&mas[4],&mas[3],3);
    printf("f_memmove: %s\n", mas);
    //ищет символ и возвращет его адрес, если не найден то NULL
    f_memchr(m,'4', 15);
    
    //побайтно сравнивает массивы пока не n либо пока не различные символы
    v = f_memcmp(a1,a2,10);
    printf("\nf_memcmp: %d",v);
    //
}