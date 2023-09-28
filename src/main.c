/**
 * @file main.c
 * @author Nicholas A Karle (nakarle@cpp.edu)
 * @brief Vignere Cipher Encrypter
 * @version 0.1
 * @date 2023-09-28
 * 
 * 
 * @details 
 * The Vignere Cipher works as such:
 * Given: plaintext, key
 * Out: ciphertext = vignere(plaintext, key)
 * 
 * The letters on the key are treated as numbers by their ordinality in the alphabet
 * The plaintext is then shifted on the alphabet by that amount moving the plaintext and key one-by-one
 * 
 * This implementation will support keys of shorter lengths than the plaintext
 * 
 */

#include <stdio.h>
#include <ctype.h>

char alphabetic_shift(char ch, int sh) {
    char unchshch = tolower(ch) + sh; //unchecked shifted character
    while (unchshch > 'z') {
        unchshch -= 'z';
    }
    return unchshch;
}

int vignere(char *plaintext, char *key, char *buffer) {

    int ptlen = strlen(plaintext);
    int klen = strlen(key);

    for (int i = 0, k = 0; i < ptlen; i++) {
        //reset k on short keys
        if (k >= klen) k = 0;
        if (isalpha(plaintext[i])) {

            buffer[i] = alphabetic_shift(
                plaintext[i], 
                tolower(key[k]) - 'a'
            );
            k++;

        } else buffer[i] = plaintext[i];
    }

    return 0;
}

int main(int argc, char const *argv[]) {

    char plaintext[4096];
    char key[4096];
    char ciphertext[4096];

    printf("VIGNERE CIPHER\n\n\nPlease, input your plaintext below: \n");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("\nThank you, now input a key: \n");
    scanf("%s", &key);

    printf("\nThank you, running vignere cipher with parameters\n %sand\n %s", plaintext, key);

    vignere(plaintext, key, ciphertext);

    printf("\n\nCiphertext:\n%s", ciphertext);

    scanf("%s");


    return 0;
}
