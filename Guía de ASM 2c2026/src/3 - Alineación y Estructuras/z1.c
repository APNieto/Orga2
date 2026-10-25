
typedef struct str1 {
    char c;
    struct {
        long l;
        short s;
    } str2;
    int i;
} str1;

int main() {
    str1 s1;
    s1.c = 'p';
    s1.str2.l = 1000;
    s1.str2.s = 10;
    s1.i = 100;
}