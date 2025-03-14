#include <stdio.h>

int main() {
    FILE* file = fopen("OS09_05.txt", "r");
    if (file == NULL) {
        printf("������: �� ������� ������� ����.\n");
        return 1;
    }

    int line_count = 0;
    char buffer[256]; // ����� ��� ������ �����

    while (fgets(buffer, sizeof(buffer), file)) {
        line_count++;
    }

    fclose(file);

    printf("���������� ����� � �����: %d\n", line_count);
    return 0;
}
