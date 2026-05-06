#include <stdio.h>
#include <string.h>

struct book {
    char name[20];
    char phone[15];
};

struct book b[100];
int n = 0;

int main() {
    int ch, i, pos;

    while(1) {
        printf("\n1.Create\n2.View\n3.Insert\n4.Delete\n5.Modify\n6.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch) {

            case 1:
                printf("How many records: ");
                scanf("%d", &n);

                for(i = 0; i < n; i++) {
                    printf("Enter Name and Phone: ");
                    scanf("%s %s", b[i].name, b[i].phone);
                }
                break;

            case 2:
                for(i = 0; i < n; i++) {
                    printf("\n%s\t%s", b[i].name, b[i].phone);
                }
                break;

            case 3:
                printf("Enter Name and Phone: ");
                scanf("%s %s", b[n].name, b[n].phone);
                n++;
                break;

            case 4:
                printf("Enter record number to delete: ");
                scanf("%d", &pos);

                for(i = pos-1; i < n-1; i++) {
                    b[i] = b[i+1];
                }

                n--;
                break;

            case 5:
                printf("Enter record number to modify: ");
                scanf("%d", &pos);

                printf("Enter new Name and Phone: ");
                scanf("%s %s", b[pos-1].name, b[pos-1].phone);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid Choice");
        }
    }
}