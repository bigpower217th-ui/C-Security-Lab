#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

const char* THREATS[] = {"/JS", "/JavaScript", "/OpenAction", "/EmbeddedFile", "/XFA", "/AA", "/Launch", "/Arcoject", "/Richarchive"};
const size_t THREAT_COUNT = sizeof(THREATS) / sizeof(THREATS[0]);

void analyze_data(const char* data, size_t len) {
    for (size_t i = 0; i < THREAT_COUNT; i++) {
        if (memmem(data, len, THREATS[i], strlen(THREATS[i])) != NULL) {
            printf("\a[!!!] KRİTİK TEHDİT TESPİT EDİLDİ: %s\n", THREATS[i]);
        }
    }
}

void decompress_and_scan(const char* compressed_buf, size_t len) {
    if (len == 0) return;
    size_t out_size = len * 10 + 1024;
    unsigned char* out_buf = malloc(out_size);
    if (!out_buf) return;

    z_stream infstream = {0};
    infstream.zalloc = Z_NULL;
    infstream.zfree = Z_NULL;
    infstream.opaque = Z_NULL;
    infstream.avail_in = (uInt)len;
    infstream.next_in = (Bytef*)compressed_buf;
    infstream.avail_out = (uInt)out_size;
    infstream.next_out = out_buf;

    if (inflateInit(&infstream) == Z_OK) {
        int ret = inflate(&infstream, Z_NO_FLUSH);
        if (ret == Z_OK || ret == Z_STREAM_END) {
            analyze_data((const char*)out_buf, infstream.total_out);
        }
        inflateEnd(&infstream);
    }

    free(out_buf);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Kullanim: %s dosya.pdf\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (!file) {
        perror("fopen");
        return 1;
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        perror("fseek");
        fclose(file);
        return 1;
    }

    long size = ftell(file);
    if (size < 0) {
        perror("ftell");
        fclose(file);
        return 1;
    }

    rewind(file);

    char* buf = malloc(size);
    if (!buf) {
        fprintf(stderr, "Bellek atanamadi\n");
        fclose(file);
        return 1;
    }

    if (fread(buf, 1, size, file) != (size_t)size) {
        perror("fread");
        free(buf);
        fclose(file);
        return 1;
    }

    printf("Analiz basliyor: %s\n", argv[1]);

    analyze_data(buf, size);

    char* stream_start = strstr(buf, "stream");
    while (stream_start) {
        char* stream_end = strstr(stream_start, "endstream");
        if (!stream_end) {
            break;
        }

        char* data_start = stream_start + strlen("stream");
        size_t data_len = (size_t)(stream_end - data_start);
        decompress_and_scan(data_start, data_len);

        stream_start = strstr(stream_end + strlen("endstream"), "stream");
    }

    printf("Analiz tamamlandi.\n");
    free(buf);
    fclose(file);
    return 0;
}