#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>


void use_md5(const char *input, unsigned char *digest) {
    MD5_CTX context;
    MD5_Init(&context);
    MD5_Update(&context, input, strlen(input));
    MD5_Final(digest, &context);
}

int main(int argc, char* argv[]) {
    if (argc !=2){
        printf("To use: %s 'string' \n", argv[0]);
        return 1;
    }
    const char *input = argv[1];
    unsigned char digest[MD5_DIGEST_LENGTH];

    use_md5(input, digest);

    printf("Input: %s\n", input);
    printf("MD5 Digest: ");

    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}
