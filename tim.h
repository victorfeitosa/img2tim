#ifndef _TIM_H
#define _TIM_H

#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define TIM_OUTPUT_CLUT4 0
#define TIM_OUTPUT_CLUT8 1
#define TIM_OUTPUT_RGB5 2
#define TIM_OUTPUT_RGB24 3

namespace tim
{

// TIM header struct
typedef struct
{

    // ID sub-struct
    struct HEADER_ID
    {
        uint32_t id : 8;   // Always 0x10
        uint32_t ver : 8;  // Always 0
        uint32_t pad : 16; // Useless padding
    } id;

    // Flags sub-struct
    struct HEADER_FLAGS
    {
        uint32_t pmode : 3; // Pixel mode (0: 4-bit, 1: 8-bit, 2:16-bit, 3:24-bit)
        uint32_t clut : 1;
        uint32_t pad : 24;
    } flags;

} HEADER;

// CLUT header struct
typedef struct
{
    uint32_t len;
    uint16_t cx, cy;
    uint16_t cw, ch;
} CLUT_HEAD;

// Image data block header
typedef struct
{
    uint32_t len;
    uint16_t x, y;
    uint16_t w, h;
} IMG_HEAD;

typedef struct
{
    // 0: 4-bit CLUT, 1: 8-bit CLUT, 2:16-bit, 3:24-bit
    int format;
    // Image data params
    void *imgData;
    uint16_t imgWidth, imgHeight;
    uint16_t imgXoffs, imgYoffs;
    // CLUT data params
    void *clutData;
    uint16_t clutWidth, clutHeight;
    uint16_t clutXoffs, clutYoffs;
} PARAM;

// RGB5A1 pixel format struct
typedef struct
{
    uint16_t r : 5;
    uint16_t g : 5;
    uint16_t b : 5;
    uint16_t i : 1;
} PIX_RGB5;

typedef struct
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} PIX_RGB24;

/*! tim::ExportFile()
 *
 *  /param[in]  fileName - Name of TIM file.
 *  /param[in]  *param   - tim::PARAM object of TIM export parameters.
 *
 *  /returns Zero if the TIM file was written successfully, otherwise an error occured.
 *
 */
int ExportFile(const char *fileName, tim::PARAM *param);

void FreeParam(tim::PARAM *param);

}; // namespace tim

#endif // _TIM_H
