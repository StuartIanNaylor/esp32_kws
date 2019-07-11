#pragma once

#include "kws.h"
#include <stdlib.h>
#include "esp_err.h"

void            kws_detect_init();
void            kws_fs_init(const char* name);
esp_err_t       kws_ring_init(size_t chunks_cnt, size_t samples_cnt_in_chunk);
audio_sample_t* kws_ring_get_next_chunk();
int             kws_guess_one_sec_16b_16k_mono(audio_sample_t* samples);

#define KWS_CHUNK_LENGTH_MS  (20)
#define KWS_CHUNKS_IN_WORD   (1000 / KWS_CHUNK_LENGTH_MS)
#define KWS_SAMPLE_RATE_HZ   (16000)
#define KWS_SAMPLES_IN_CHUNK (KWS_CHUNK_LENGTH_MS * KWS_SAMPLE_RATE_HZ / 1000)