#ifndef _ADC_H
#define _ADC_H


#define fs			8000					//ADC Sampling Rate Hz 8000
#define	voice_len	3000					//Length of recording time in ms
#define	VcBuf_Len	((fs/1000)*voice_len)	//Length of voice buffer area Unit points 16 bits per sampling point
#define atap_len_t	300						//Background noise adaptive time length ms
#define atap_len	((fs/1000)*atap_len_t)	//Background noise adaptive length

#ifdef __cplusplus
extern "C" {
#endif

void ADC_DMA_Init(void);

#ifdef __cplusplus
}
#endif

#endif

