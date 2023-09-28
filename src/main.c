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
 * This implementation will support keys of different lengths than the plaintext by wrapping around on either
 * 
 */

#include <stdio.h>
#include <ctype.h>

int alphabetic_ordinality(char ch) {
    return (tolower(ch) - 'a');
}

char alphabetic_shift(char ch, int sh) {
    char unchshch = tolower(ch) + sh; //unchecked shifted character
    while (unchshch > 'z') {
        unchshch -= 'z';
    }
    return unchshch;
}

int main(int argc, char const *argv[]) {

    char plaintext[4096];
    char key[4096];
    char ciphertext[4096];

    printf("Please, input your plaintext below: \n");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Thank you, now input a key: \n");
    scanf("%s", &key);

    printf("Thank you, running vignere cipher with parameters\n %s \nand\n %s", plaintext, key);

    return 0;
}
