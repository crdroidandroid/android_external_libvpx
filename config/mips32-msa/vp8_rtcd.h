#ifndef VP8_RTCD_H_
#define VP8_RTCD_H_

#ifdef RTCD_C
#define RTCD_EXTERN
#else
#define RTCD_EXTERN extern
#endif

/*
 * VP8
 */

struct blockd;
struct macroblockd;
struct loop_filter_info;

/* Encoder forward decls */
struct block;
struct macroblock;
struct variance_vtable;
union int_mv;
struct yv12_buffer_config;

#ifdef __cplusplus
extern "C" {
#endif

void vp8_bilinear_predict16x16_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_bilinear_predict16x16_msa(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
#define vp8_bilinear_predict16x16 vp8_bilinear_predict16x16_msa

void vp8_bilinear_predict4x4_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_bilinear_predict4x4_msa(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
#define vp8_bilinear_predict4x4 vp8_bilinear_predict4x4_msa

void vp8_bilinear_predict8x4_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_bilinear_predict8x4_msa(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
#define vp8_bilinear_predict8x4 vp8_bilinear_predict8x4_msa

void vp8_bilinear_predict8x8_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_bilinear_predict8x8_msa(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
#define vp8_bilinear_predict8x8 vp8_bilinear_predict8x8_msa

int vp8_block_error_c(short *coeff, short *dqcoeff);
int vp8_block_error_msa(short *coeff, short *dqcoeff);
#define vp8_block_error vp8_block_error_msa

void vp8_copy_mem16x16_c(unsigned char *src, int src_pitch, unsigned char *dst, int dst_pitch);
void vp8_copy_mem16x16_msa(unsigned char *src, int src_pitch, unsigned char *dst, int dst_pitch);
#define vp8_copy_mem16x16 vp8_copy_mem16x16_msa

void vp8_copy_mem8x4_c(unsigned char *src, int src_pitch, unsigned char *dst, int dst_pitch);
void vp8_copy_mem8x4_msa(unsigned char *src, int src_pitch, unsigned char *dst, int dst_pitch);
#define vp8_copy_mem8x4 vp8_copy_mem8x4_msa

void vp8_copy_mem8x8_c(unsigned char *src, int src_pitch, unsigned char *dst, int dst_pitch);
void vp8_copy_mem8x8_msa(unsigned char *src, int src_pitch, unsigned char *dst, int dst_pitch);
#define vp8_copy_mem8x8 vp8_copy_mem8x8_msa

void vp8_dc_only_idct_add_c(short input, unsigned char *pred, int pred_stride, unsigned char *dst, int dst_stride);
void vp8_dc_only_idct_add_msa(short input, unsigned char *pred, int pred_stride, unsigned char *dst, int dst_stride);
#define vp8_dc_only_idct_add vp8_dc_only_idct_add_msa

int vp8_denoiser_filter_c(unsigned char *mc_running_avg_y, int mc_avg_y_stride, unsigned char *running_avg_y, int avg_y_stride, unsigned char *sig, int sig_stride, unsigned int motion_magnitude, int increase_denoising);
int vp8_denoiser_filter_msa(unsigned char *mc_running_avg_y, int mc_avg_y_stride, unsigned char *running_avg_y, int avg_y_stride, unsigned char *sig, int sig_stride, unsigned int motion_magnitude, int increase_denoising);
#define vp8_denoiser_filter vp8_denoiser_filter_msa

int vp8_denoiser_filter_uv_c(unsigned char *mc_running_avg, int mc_avg_stride, unsigned char *running_avg, int avg_stride, unsigned char *sig, int sig_stride, unsigned int motion_magnitude, int increase_denoising);
int vp8_denoiser_filter_uv_msa(unsigned char *mc_running_avg, int mc_avg_stride, unsigned char *running_avg, int avg_stride, unsigned char *sig, int sig_stride, unsigned int motion_magnitude, int increase_denoising);
#define vp8_denoiser_filter_uv vp8_denoiser_filter_uv_msa

void vp8_dequant_idct_add_c(short *input, short *dq, unsigned char *output, int stride);
void vp8_dequant_idct_add_msa(short *input, short *dq, unsigned char *output, int stride);
#define vp8_dequant_idct_add vp8_dequant_idct_add_msa

void vp8_dequant_idct_add_uv_block_c(short *q, short *dq, unsigned char *dst_u, unsigned char *dst_v, int stride, char *eobs);
void vp8_dequant_idct_add_uv_block_msa(short *q, short *dq, unsigned char *dst_u, unsigned char *dst_v, int stride, char *eobs);
#define vp8_dequant_idct_add_uv_block vp8_dequant_idct_add_uv_block_msa

void vp8_dequant_idct_add_y_block_c(short *q, short *dq, unsigned char *dst, int stride, char *eobs);
void vp8_dequant_idct_add_y_block_msa(short *q, short *dq, unsigned char *dst, int stride, char *eobs);
#define vp8_dequant_idct_add_y_block vp8_dequant_idct_add_y_block_msa

void vp8_dequantize_b_c(struct blockd*, short *dqc);
void vp8_dequantize_b_msa(struct blockd*, short *dqc);
#define vp8_dequantize_b vp8_dequantize_b_msa

int vp8_diamond_search_sad_c(struct macroblock *x, struct block *b, struct blockd *d, union int_mv *ref_mv, union int_mv *best_mv, int search_param, int sad_per_bit, int *num00, struct variance_vtable *fn_ptr, int *mvcost[2], union int_mv *center_mv);
int vp8_diamond_search_sadx4(struct macroblock *x, struct block *b, struct blockd *d, union int_mv *ref_mv, union int_mv *best_mv, int search_param, int sad_per_bit, int *num00, struct variance_vtable *fn_ptr, int *mvcost[2], union int_mv *center_mv);
#define vp8_diamond_search_sad vp8_diamond_search_sadx4

void vp8_fast_quantize_b_c(struct block *, struct blockd *);
void vp8_fast_quantize_b_msa(struct block *, struct blockd *);
#define vp8_fast_quantize_b vp8_fast_quantize_b_msa

int vp8_full_search_sad_c(struct macroblock *x, struct block *b, struct blockd *d, union int_mv *ref_mv, int sad_per_bit, int distance, struct variance_vtable *fn_ptr, int *mvcost[2], union int_mv *center_mv);
#define vp8_full_search_sad vp8_full_search_sad_c

void vp8_loop_filter_bh_c(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
void vp8_loop_filter_bh_msa(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
#define vp8_loop_filter_bh vp8_loop_filter_bh_msa

void vp8_loop_filter_bv_c(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
void vp8_loop_filter_bv_msa(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
#define vp8_loop_filter_bv vp8_loop_filter_bv_msa

void vp8_loop_filter_mbh_c(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
void vp8_loop_filter_mbh_msa(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
#define vp8_loop_filter_mbh vp8_loop_filter_mbh_msa

void vp8_loop_filter_mbv_c(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
void vp8_loop_filter_mbv_msa(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
#define vp8_loop_filter_mbv vp8_loop_filter_mbv_msa

void vp8_loop_filter_bhs_c(unsigned char *y, int ystride, const unsigned char *blimit);
void vp8_loop_filter_bhs_msa(unsigned char *y, int ystride, const unsigned char *blimit);
#define vp8_loop_filter_simple_bh vp8_loop_filter_bhs_msa

void vp8_loop_filter_bvs_c(unsigned char *y, int ystride, const unsigned char *blimit);
void vp8_loop_filter_bvs_msa(unsigned char *y, int ystride, const unsigned char *blimit);
#define vp8_loop_filter_simple_bv vp8_loop_filter_bvs_msa

void vp8_loop_filter_simple_horizontal_edge_c(unsigned char *y, int ystride, const unsigned char *blimit);
void vp8_loop_filter_simple_horizontal_edge_msa(unsigned char *y, int ystride, const unsigned char *blimit);
#define vp8_loop_filter_simple_mbh vp8_loop_filter_simple_horizontal_edge_msa

void vp8_loop_filter_simple_vertical_edge_c(unsigned char *y, int ystride, const unsigned char *blimit);
void vp8_loop_filter_simple_vertical_edge_msa(unsigned char *y, int ystride, const unsigned char *blimit);
#define vp8_loop_filter_simple_mbv vp8_loop_filter_simple_vertical_edge_msa

int vp8_mbblock_error_c(struct macroblock *mb, int dc);
int vp8_mbblock_error_msa(struct macroblock *mb, int dc);
#define vp8_mbblock_error vp8_mbblock_error_msa

int vp8_mbuverror_c(struct macroblock *mb);
int vp8_mbuverror_msa(struct macroblock *mb);
#define vp8_mbuverror vp8_mbuverror_msa

int vp8_refining_search_sad_c(struct macroblock *x, struct block *b, struct blockd *d, union int_mv *ref_mv, int sad_per_bit, int distance, struct variance_vtable *fn_ptr, int *mvcost[2], union int_mv *center_mv);
int vp8_refining_search_sadx4(struct macroblock *x, struct block *b, struct blockd *d, union int_mv *ref_mv, int sad_per_bit, int distance, struct variance_vtable *fn_ptr, int *mvcost[2], union int_mv *center_mv);
#define vp8_refining_search_sad vp8_refining_search_sadx4

void vp8_regular_quantize_b_c(struct block *, struct blockd *);
void vp8_regular_quantize_b_msa(struct block *, struct blockd *);
#define vp8_regular_quantize_b vp8_regular_quantize_b_msa

void vp8_short_fdct4x4_c(short *input, short *output, int pitch);
void vp8_short_fdct4x4_msa(short *input, short *output, int pitch);
#define vp8_short_fdct4x4 vp8_short_fdct4x4_msa

void vp8_short_fdct8x4_c(short *input, short *output, int pitch);
void vp8_short_fdct8x4_msa(short *input, short *output, int pitch);
#define vp8_short_fdct8x4 vp8_short_fdct8x4_msa

void vp8_short_idct4x4llm_c(short *input, unsigned char *pred, int pitch, unsigned char *dst, int dst_stride);
void vp8_short_idct4x4llm_msa(short *input, unsigned char *pred, int pitch, unsigned char *dst, int dst_stride);
#define vp8_short_idct4x4llm vp8_short_idct4x4llm_msa

void vp8_short_inv_walsh4x4_c(short *input, short *output);
void vp8_short_inv_walsh4x4_msa(short *input, short *output);
#define vp8_short_inv_walsh4x4 vp8_short_inv_walsh4x4_msa

void vp8_short_inv_walsh4x4_1_c(short *input, short *output);
#define vp8_short_inv_walsh4x4_1 vp8_short_inv_walsh4x4_1_c

void vp8_short_walsh4x4_c(short *input, short *output, int pitch);
void vp8_short_walsh4x4_msa(short *input, short *output, int pitch);
#define vp8_short_walsh4x4 vp8_short_walsh4x4_msa

void vp8_sixtap_predict16x16_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_sixtap_predict16x16_msa(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
#define vp8_sixtap_predict16x16 vp8_sixtap_predict16x16_msa

void vp8_sixtap_predict4x4_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_sixtap_predict4x4_msa(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
#define vp8_sixtap_predict4x4 vp8_sixtap_predict4x4_msa

void vp8_sixtap_predict8x4_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_sixtap_predict8x4_msa(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
#define vp8_sixtap_predict8x4 vp8_sixtap_predict8x4_msa

void vp8_sixtap_predict8x8_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_sixtap_predict8x8_msa(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
#define vp8_sixtap_predict8x8 vp8_sixtap_predict8x8_msa

void vp8_rtcd(void);

#include "vpx_config.h"

#ifdef RTCD_C
static void setup_rtcd_internal(void)
{
#if HAVE_DSPR2
void vpx_dsputil_static_init();
#if CONFIG_VP8
void dsputil_static_init();
#endif

vpx_dsputil_static_init();
#if CONFIG_VP8
dsputil_static_init();
#endif
#endif
}
#endif

#ifdef __cplusplus
}  // extern "C"
#endif

#endif
