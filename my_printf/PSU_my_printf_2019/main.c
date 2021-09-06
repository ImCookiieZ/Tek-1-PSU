#include "include/my.h"
#include "include/struct.h"
int main()
{
    char *lol = strdup("hallo");
    char *astek = strdup("moulineette");
    int a = 42;
    char *bombe = "huhu";
    char **hehe = &bombe;
    my_printf("%%%s%%\n", "HALO");
    printf("%%%s%%", "HALO");
    free(lol);
    free(astek);
}