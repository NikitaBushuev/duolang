#ifndef DUO_COMMON_H_
#define DUO_COMMON_H_

#ifdef __cplusplus
#define _DUO_EXTERNC_BEGIN extern "C" {
#define _DUO_EXTERNC_END   }
#else /* __cplusplus */
#define _DUO_EXTERNC_BEGIN
#define _DUO_EXTERNC_END
#endif /* __cplusplus */

#define _DUO_SIZEOF(_TYPE) ((duo_size_t) { sizeof(_TYPE), })

#endif /* DUO_COMMON_H_ */