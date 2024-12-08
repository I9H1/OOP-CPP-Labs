#pragma once
#include <stdint.h>

#define SUPPORTED_FORMAT 1163280727 // PCM
#define SUPPORTED_CHANNELS 1
#define SUPPORTED_SAMPLE_SIZE 16
#define SUPPORTED_SAMPLE_RATE 44100

struct WAVHeader {
    uint32_t chunk_ID;
    uint32_t chunk_size;
    uint32_t format;
    uint32_t subchunk1_ID;
    uint32_t subchunk1_size;
    uint16_t audio_format;
    uint16_t num_channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
    uint32_t subchunk2_ID;
    uint32_t subchunk2_size;
};
