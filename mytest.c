#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "comp128v23.h"
#include <time.h>


int main () {
uint8_t ki[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
uint8_t rand[16] = {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00};
uint8_t sres[4] = {00,00,00,00};
uint8_t kc[8] = {00,00,00,00,00,00,00,00};
clock_t start, end;
double cpu_time_used;
typedef unsigned __int128 uint128_t;
uint128_t kint= 0x0000000000000000;     
/*
memcpy(&ki, &kint, 16);


printf("\n\n ki: ");
for(int x=0;x<16;x++){
        printf(" %x",ki[x]);
        }
*/
FILE *f = fopen("TEST.DAT", "wb");

start = clock();
for(kint = 0x0000000000000000;kint<=0x00000000000000FFFF;kint++){
memcpy(&ki, &kint, 16);
comp128v3(&ki[0],&rand[0],&sres[0],&kc[0]);
/*printf("\n Ki: %llx \n",(unsigned long long) kint);
printf("\n\n SRES: ");
for(int k=0;k<4;k++){
        printf(" %x",sres[k]);
        }*/

fwrite(ki,sizeof(uint8_t),sizeof(ki),f);
fwrite(sres,sizeof(uint8_t),sizeof(sres),f);
}
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("\n %f sec. \n",cpu_time_used);
fclose(f);
}
