#include <iostream>
using namespace std;

int N = 10;
int mas[10];

void BubbleSort() {
    _asm
    {
        dec N;
    Lnd:
        xor ebx, ebx;
        mov ecx, N;
        mov esi, 0;
    L:
        mov edi, mas[esi];
        cmp edi, mas[esi + 4];
        jg S;
        add esi, 4;
        loop L;
        jmp Comp;
    S:
        mov ebx, mas[esi + 4];
        mov mas[esi + 4], edi;
        mov mas[esi], ebx;
        add esi, 4;
        loop L;
    Comp:
        cmp ebx, 0;
        je End;
        jmp Lnd;
    End:
    }
}

int main()
{
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        mas[i] = rand() % 101;
        cout << mas[i] << endl;
    }
    cout << endl << endl;

    BubbleSort();

    for (int i = 0; i < N; i++) cout << mas[i] << endl;
}