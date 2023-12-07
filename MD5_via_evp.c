#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void use_md5(const unsigned char *input, size_t input_len, unsigned char *digest) {
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned int digest_len;

    md = EVP_get_digestbyname("md5");

    mdctx = EVP_MD_CTX_new();
    EVP_MD_CTX_init(mdctx);

    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, input, input_len);
    EVP_DigestFinal_ex(mdctx, digest, &digest_len);

    EVP_MD_CTX_free(mdctx);
}

int main(int argc, char* argv[]) {
    if (argc !=2){
        printf("To use: %s 'string' \n", argv[0]);
        return 1;
    }
    const char *input = argv[1];
    unsigned char digest[EVP_MAX_MD_SIZE];

    use_md5((const unsigned char *)input, strlen(input), digest);

    printf("Input: %s\n", input);
    printf("MD5 Digest: ");

    for (int i = 0; i < EVP_MD_size(EVP_md5()); i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}

