
typedef struct str1 {
    char c1;
    struct {
        int i1;
        short s;
    } str2;
    char c2;
} str1;

int main() {
    str1 s1;
    s1.c1 = 'a';
    s1.str2.i1 = 1000;
    s1.str2.s = 100;
    s1.c2 = 'A';
}