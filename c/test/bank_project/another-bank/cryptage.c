#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

// Fonction pour afficher les données en hexadécimal
void print_data(const char *title, const void* data, int len) {
    printf("%s : ", title);
    const unsigned char *p = (const unsigned char*)data;
    for (int i = 0; i < len; i++)
        printf("%02x ", *p++);
    printf("\n");
}

int main() {
    // Clé de cryptage (doit être de 16, 24 ou 32 octets pour AES-128, AES-192 ou AES-256)
    unsigned char key[32];
    memset(key, 0, 32);
    strncpy((char*)key, "thisisaverysecurekey!", 32);

    // Données à chiffrer
    unsigned char text[] = "1234567890"; // Exemple de numéro de compte
    unsigned char enc_out[80];
    unsigned char dec_out[80];

    // Initialisation des structures AES
    AES_KEY enc_key, dec_key;
    AES_set_encrypt_key(key, 256, &enc_key);
    AES_set_decrypt_key(key, 256, &dec_key);

    // Chiffrement
    AES_encrypt(text, enc_out, &enc_key);
    print_data("Chiffré", enc_out, sizeof(text));

    // Déchiffrement
    AES_decrypt(enc_out, dec_out, &dec_key);
    print_data("Déchiffré", dec_out, sizeof(text));

    return 0;
}
