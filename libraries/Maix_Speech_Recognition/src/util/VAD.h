#ifndef _VAD_H
#define _VAD_H

#include "g_def.h"

#define	max_vc_con	3						// Maximum number of voice segments detected by VAD
#define frame_time	20						// Time length per frame unit ms
#define frame_mov_t	10						// Frame shift
#define FRAME_LEN	(frame_time*fs/1000)	// Frame length
#define frame_mov	(frame_mov_t *fs/1000)	// Frame shift, overlapping parts of adjacent frames

#ifdef __cplusplus
extern "C" {
#endif


#pragma pack(1)
typedef struct {
	u32 mid_val;	//语音段中值 相当于有符号的0值 用于短时过零率计算
	u16	n_thl;		//噪声阈值，用于短时过零率计算
	u16 z_thl;		//短时过零率阈值，超过此阈值，视为进入过渡段。
	u32 s_thl;		//短时累加和阈值，超过此阈值，视为进入过渡段。
} atap_tag;			//自适应参数
#pragma pack()

//#pragma pack(4)
typedef struct {
	u16 *start;	//起始点
	u16 *end;	//结束点
//	u8 word_num;
} valid_tag;	//有效语音段
//#pragma pack()

void noise_atap(const u16 *noise, u16 n_len, atap_tag *atap);
void VAD(const u16 *vc, u16 buf_len, valid_tag *valid_voice, atap_tag *atap_arg);
u8 VAD2(const u16 *vc, valid_tag *valid_voice, atap_tag *atap_arg);

#ifdef __cplusplus
}
#endif

#endif
