#include <stdio.h>
#include <conio.h>


int print_menu(int index) {
    if (index > 5 || index < 0) return 0;
    (index == 1) ? printf("Addition          <--\n") : printf("Addition\n");
    (index == 2) ? printf("Substraction      <--\n") : printf("Substraction\n");
    (index == 3) ? printf("Multiplication    <--\n") : printf("Multiplication\n");
    (index == 4) ? printf("Division          <--\n") : printf("Division\n");
    (index == 5) ? printf("Enter new values  <--\n") : printf("Enter new values\n");
    (index == 6) ? printf("Exit              <--\n") : printf("Exit\n");
}

int selected(int button, long long a, long long b) {
    system("cls");
    switch (button) {
    case 1:
        printf("The sum of %lld and %lld is %lld\nPress Enter to continue\n ", a, b, a + b);
        _getch();
        return button;
    case 2:
        printf("The Subtraction of %lld and %lld is %lld\nPress Enter to continue\n", a, b, a - b);
        _getch();
        return button;
    case 3:
        printf("The multiplication of %lld and %lld is %lld\nPress Enter to continue\n", a, b, a * b);
        _getch();
        return button;
    case 4:
        if (b == 0) {
            printf("Impossible\n");
            _getch();
            return button;
        }
        else {
            printf("The division of %lld and %lld is %lld\nPress Enter to continue\n", a, b, a / b);
            _getch();
            return button;
        }
    case 5:
        return button;
    case 6:
        exit(1);

    }
}

int main()
{
    long long a, b;
    while (1) {
        system("cls");
        printf("Enter A\n");
        scanf_s("%lld", &a);
        if (!(a<65535 && a>-65536)) {
            do {
                printf("enter -65536 < A <65535 \n");
                scanf_s("%lld", &a);
            } while (!(a<65535 && a>-65536));
        }

        printf("enter B\n");
        scanf_s("%lld", &b);
        if (!(b<65535 && b>-65536)) {
            do {
                printf("enter -65536 < B <65535 \n");
                scanf_s("%lld", &b);
            } while (!(b<65535 && b>-65536));
        }
        if (b == 0) {
            printf("IMPORTANT: DIVISION BY 0 IS NOT POSSIBLE\n");
            system("PAUSE");
        }
        int button = 1;
        while (1) {
            system("cls");
            print_menu(button);
            char ch = '0';
            ch = _getch();
            if (ch == 72) {
                button -= 1;
                if (button == 0) button = 6;
            }
            else if (ch == 80) {
                button += 1;
                if (button == 7) button = 1;
            }
            else if (ch == 13) {
                button = selected(button, a, b);
                if (button == 5) {
                    break;
                }
            }
        }
    }
}