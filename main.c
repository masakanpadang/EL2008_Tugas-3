#include <stdio.h>
#define maxchar_fn 50
#define sig_byte 5

int main () {
    char file [maxchar_fn];
    unsigned char val[sig_byte];
    FILE *filep;

    printf("Masukkan nama file: ");
    scanf("%s", file);

    filep = fopen(file,"r");
    if (filep != NULL){
        fread(val, sig_byte, 1, filep);
        if ((val[0] == 0x25) && (val[1] == 0x50) && (val[2] == 0x44)
            && (val[3] == 0x46) && (val[4] == 0x2d)){
            printf("File %s merupakan PDF\n", file);
        }
        else if ((val[0] == 0xFF) && (val[1] == 0xd8) && (val[2] == 0xFF)) {
            printf("File %s merupakan JPG\n", file);
        }
        else {
            printf("File %s bukan JPG atau PDF\n", file);
        }
    }
    else {
        printf("File tersebut tidak ada atau bukan sebuah file");
    }
    fclose(filep);
}
