
#include <glslcommon/defines.h>

typedef enum glsl_type_t
{
	GLSL_TYPE_UNDEFINED = 0ULL,
	GLSL_TYPE_U8 	= 1ULL,
	GLSL_TYPE_U16 	= 2ULL,
	GLSL_TYPE_U32	= 3ULL,
	GLSL_TYPE_U64 	= 4ULL,
	GLSL_TYPE_S8 	= 5ULL,
	GLSL_TYPE_S16 	= 6ULL,
	GLSL_TYPE_S32 	= 7ULL,
	GLSL_TYPE_S64 	= 8ULL,
	GLSL_TYPE_F32 	= 9ULL,
	GLSL_TYPE_F64 	= 10ULL,
	GLSL_TYPE_VEC2 	= 11ULL,
	GLSL_TYPE_VEC3 	= 12ULL,
	GLSL_TYPE_VEC4 	= 13ULL,
	GLSL_TYPE_MAT2 	= 14ULL,
	GLSL_TYPE_MAT3 	= 15ULL,
	GLSL_TYPE_MAT4	= 16ULL,

	GLSL_TYPE_IVEC2 = 17ULL,
	GLSL_TYPE_IVEC3 = 18ULL,
	GLSL_TYPE_IVEC4 = 19ULL,
	GLSL_TYPE_UVEC2 = 20ULL,
	GLSL_TYPE_UVEC3 = 21ULL,
	GLSL_TYPE_UVEC4 = 22ULL,

	GLSL_TYPE_MAX_NON_OPAQUE,

	GLSL_TYPE_BLOCK,
	GLSL_TYPE_UNIFORM_BUFFER,
	GLSL_TYPE_STORAGE_BUFFER,
	GLSL_TYPE_PUSH_CONSTANT,

	GLSL_TYPE_SAMPLER_2D,
	GLSL_TYPE_SAMPLER_3D,
	GLSL_TYPE_SAMPLER_CUBE,
	GLSL_TYPE_SUBPASS_INPUT,

	GLSL_TYPE_FLOAT = GLSL_TYPE_F32,
	GLSL_TYPE_INT = GLSL_TYPE_S32,
	GLSL_TYPE_UINT = GLSL_TYPE_U32,
	GLSL_TYPE_DOUBLE = GLSL_TYPE_F64
} glsl_type_t;

/* returns alignment (in bytes) of a glsl type 'type' */
GLSL_COM_API u32 alignof_glsl_type(glsl_type_t type);
/* returns size (in bytes) of a glsl type 'type' */
GLSL_COM_API u32 sizeof_glsl_type(glsl_type_t type);
/* returns VkFormat (u32) of a glsl type 'type' */
GLSL_COM_API u32 vkformatof_glsl_type(glsl_type_t type);

#define GLSL_TYPE_U8_SIZE 		sizeof_glsl_type(GLSL_TYPE_U8)
#define GLSL_TYPE_U16_SIZE 		sizeof_glsl_type(GLSL_TYPE_U16)
#define GLSL_TYPE_U32_SIZE 		sizeof_glsl_type(GLSL_TYPE_U32)
#define GLSL_TYPE_U64_SIZE 		sizeof_glsl_type(GLSL_TYPE_U64)
#define GLSL_TYPE_S8_SIZE 		sizeof_glsl_type(GLSL_TYPE_S8)
#define GLSL_TYPE_S16_SIZE 		sizeof_glsl_type(GLSL_TYPE_S16)
#define GLSL_TYPE_S32_SIZE 		sizeof_glsl_type(GLSL_TYPE_S32)
#define GLSL_TYPE_S64_SIZE 		sizeof_glsl_type(GLSL_TYPE_S64)
#define GLSL_TYPE_F32_SIZE 		sizeof_glsl_type(GLSL_TYPE_F32)
#define GLSL_TYPE_F64_SIZE		sizeof_glsl_type(GLSL_TYPE_F64)
#define GLSL_TYPE_VEC2_SIZE		sizeof_glsl_type(GLSL_TYPE_VEC2)
#define GLSL_TYPE_VEC3_SIZE		sizeof_glsl_type(GLSL_TYPE_VEC3)
#define GLSL_TYPE_VEC4_SIZE		sizeof_glsl_type(GLSL_TYPE_VEC4)
#define GLSL_TYPE_MAT2_SIZE		sizeof_glsl_type(GLSL_TYPE_MAT2)
#define GLSL_TYPE_MAT3_SIZE		sizeof_glsl_type(GLSL_TYPE_MAT3)
#define GLSL_TYPE_MAT4_SIZE		sizeof_glsl_type(GLSL_TYPE_MAT4)
#define GLSL_TYPE_IVEC2_SIZE	sizeof_glsl_type(GLSL_TYPE_IVEC2)
#define GLSL_TYPE_IVEC3_SIZE	sizeof_glsl_type(GLSL_TYPE_IVEC3)
#define GLSL_TYPE_IVEC4_SIZE	sizeof_glsl_type(GLSL_TYPE_IVEC4)
#define GLSL_TYPE_UVEC2_SIZE	sizeof_glsl_type(GLSL_TYPE_UVEC2)
#define GLSL_TYPE_UVEC3_SIZE	sizeof_glsl_type(GLSL_TYPE_UVEC3)
#define GLSL_TYPE_UVEC4_SIZE	sizeof_glsl_type(GLSL_TYPE_UVEC4)
#define GLSL_TYPE_BLOCK_SIZE	sizeof_glsl_type(GLSL_TYPE_BLOCK)

#define GLSL_TYPE_FLOAT_SIZE GLSL_TYPE_F32_SIZE
#define GLSL_TYPE_INT_SIZE GLSL_TYPE_S32_SIZE
#define GLSL_TYPE_UINT_SIZE GLSL_TYPE_U32_SIZE
#define GLSL_TYPE_DOUBLE_SIZE GLSL_TYPE_F64_SIZE
