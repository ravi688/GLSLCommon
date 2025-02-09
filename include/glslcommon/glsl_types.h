#pragma once

#include <glslcommon/defines.h>

typedef enum glsl_memory_layout_t
{
	GLSL_SCALAR,
	GLSL_MEMORY_LAYOUT_SCALAR = GLSL_SCALAR,
	GLSL_STD430,
	GLSL_MEMORY_LAYOUT_BASE = GLSL_STD430,
	GLSL_STD140,
	GLSL_MEMORY_LAYOUT_EXTENDED = GLSL_STD140
} glsl_memory_layout_t;

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
	GLSL_TYPE_DVEC2 = 23ULL,
	GLSL_TYPE_DVEC3 = 24ULL,
	GLSL_TYPE_DVEC4 = 25ULL,
	GLSL_TYPE_DMAT2 = 26ULL,
	GLSL_TYPE_DMAT3 = 27ULL,
	GLSL_TYPE_DMAT4	= 28ULL,

	GLSL_TYPE_MAX_NON_OPAQUE,

	GLSL_TYPE_BLOCK,
	GLSL_TYPE_UNIFORM_BUFFER,
	GLSL_TYPE_STORAGE_BUFFER,
	GLSL_TYPE_PUSH_CONSTANT,

	GLSL_TYPE_SAMPLER_1D,
	GLSL_TYPE_SAMPLER_2D,
	GLSL_TYPE_SAMPLER_3D,
	GLSL_TYPE_SAMPLER_CUBE,
	GLSL_TYPE_SUBPASS_INPUT,

	GLSL_TYPE_FLOAT = GLSL_TYPE_F32,
	GLSL_TYPE_INT = GLSL_TYPE_S32,
	GLSL_TYPE_UINT = GLSL_TYPE_U32,
	GLSL_TYPE_DOUBLE = GLSL_TYPE_F64
} glsl_type_t;

typedef struct glsl_type_layout_traits_t
{
	/* if this is GLSL_TYPE_UNDEFINED (meaning maybe it is a struct type), then align and size must be set correctly to specify its layout information */
	glsl_type_t type;
	/* true if this type is an array, otherwise false */
	bool is_array;
	/* alignment of GLSL_TYPE_UNDEFINED type */
	u32 align;
	/* size of GLSL_TYPE_UNDEFINED type */
	u32 size;
} glsl_type_layout_traits_t;

/* returns alignment (in bytes) of a glsl type 'type' */
GLSLCOM_API u32 alignof_glsl_type(glsl_type_t type, glsl_memory_layout_t layout);
GLSLCOM_API u32 alignof_glsl_type_array(glsl_type_t type, glsl_memory_layout_t layout);
typedef glsl_type_layout_traits_t (*glsl_type_layout_traits_callback_t)(void* user_data, u32 type_index);
GLSLCOM_API u32 alignof_glsl_type_struct(glsl_type_layout_traits_callback_t callback, void* user_data, u32 type_traits_count, glsl_memory_layout_t layout);
#define alignof_glsl_type_struct_array alignof_glsl_type_struct

/* returns size (in bytes) of a glsl type 'type' */
GLSLCOM_API u32 sizeof_glsl_type(glsl_type_t type, glsl_memory_layout_t layout);
/* returns VkFormat (u32) of a glsl type 'type' */
GLSLCOM_API u32 vkformatof_glsl_type(glsl_type_t type);

/* Scalary Layout */
#define GLSL_SCALAR_FLOAT_ALIGN            	4 /* IEEE 745 double precision float has 32 bits */
#define GLSL_SCALAR_FLOAT_ARR_ALIGN			GLSL_SCALAR_FLOAT_ALIGN /* IEEE 745 double precision float has 32 bits */
#define GLSL_SCALAR_INT_ALIGN              	4 /* GLSL spec states 32-bits for int */
#define GLSL_SCALAR_INT_ARR_ALIGN 			GLSL_SCALAR_INT_ALIGN /* GLSL spec states 32-bits for int */
#define GLSL_SCALAR_UINT_ALIGN             	4 /* GLSL spec states 32-bits for uint */
#define GLSL_SCALAR_UINT_ARR_ALIGN 			GLSL_SCALAR_UINT_ALIGN /* GLSL spec states 32-bits for uint */
#define GLSL_SCALAR_DOUBLE_ALIGN           	8 /* IEEE 745 double precision float has 64 bits */
#define GLSL_SCALAR_DOUBLE_ARR_ALIGN 		GLSL_SCALAR_DOUBLE_ALIGN /* IEEE 745 double precision float has 64 bits */
#define GLSL_SCALAR_IVEC4_ALIGN            	GLSL_SCALAR_INT_ALIGN
#define GLSL_SCALAR_IVEC4_ARR_ALIGN 		GLSL_SCALAR_IVEC4_ALIGN
#define GLSL_SCALAR_UVEC4_ALIGN            	GLSL_SCALAR_UINT_ALIGN
#define GLSL_SCALAR_UVEC4_ARR_ALIGN 		GLSL_SCALAR_UVEC4_ALIGN
#define GLSL_SCALAR_IVEC3_ALIGN            	GLSL_SCALAR_INT_ALIGN
#define GLSL_SCALAR_IVEC3_ARR_ALIGN       	GLSL_SCALAR_IVEC3_ALIGN
#define GLSL_SCALAR_UVEC3_ALIGN            	GLSL_SCALAR_UINT_ALIGN
#define GLSL_SCALAR_UVEC3_ARR_ALIGN        	GLSL_SCALAR_UVEC3_ALIGN
#define GLSL_SCALAR_IVEC2_ALIGN            	GLSL_SCALAR_INT_ALIGN
#define GLSL_SCALAR_IVEC2_ARR_ALIGN        	GLSL_SCALAR_IVEC2_ALIGN
#define GLSL_SCALAR_UVEC2_ALIGN            	GLSL_SCALAR_UINT_ALIGN
#define GLSL_SCALAR_UVEC2_ARR_ALIGN        	GLSL_SCALAR_UVEC2_ALIGN
#define GLSL_SCALAR_VEC2_ALIGN           	GLSL_SCALAR_FLOAT_ALIGN
#define GLSL_SCALAR_VEC2_ARR_ALIGN         	GLSL_SCALAR_VEC2_ALIGN
#define GLSL_SCALAR_VEC3_ALIGN             	GLSL_SCALAR_FLOAT_ALIGN
#define GLSL_SCALAR_VEC3_ARR_ALIGN         	GLSL_SCALAR_VEC3_ALIGN
#define GLSL_SCALAR_VEC4_ALIGN             	GLSL_SCALAR_FLOAT_ALIGN /* Scalar Alignment: A vector type has a scalar alignment equal to that of its component type. */
#define GLSL_SCALAR_VEC4_ARR_ALIGN        	GLSL_SCALAR_VEC4_ALIGN /* Scalar Alignment: A vector type has a scalar alignment equal to that of its component type. */
#define GLSL_SCALAR_DVEC2_ALIGN            	GLSL_SCALAR_DOUBLE_ALIGN
#define GLSL_SCALAR_DVEC2_ARR_ALIGN      	GLSL_SCALAR_DVEC2_ALIGN
#define GLSL_SCALAR_DVEC3_ALIGN            	GLSL_SCALAR_DOUBLE_ALIGN
#define GLSL_SCALAR_DVEC3_ARR_ALIGN       	GLSL_SCALAR_DVEC3_ALIGN
#define GLSL_SCALAR_DVEC4_ALIGN            	GLSL_SCALAR_DOUBLE_ALIGN /* Scalar Alignment: A vector type has a scalar alignment equal to that of its component type. */
#define GLSL_SCALAR_DVEC4_ARR_ALIGN        	GLSL_SCALAR_DVEC4_ALIGN /* Scalar Alignment: A vector type has a scalar alignment equal to that of its component type. */
#define GLSL_SCALAR_MAT2_ALIGN             	GLSL_SCALAR_VEC2_ARR_ALIGN
#define GLSL_SCALAR_MAT2_ARR_ALIGN			GLSL_SCALAR_MAT2_ALIGN
#define GLSL_SCALAR_MAT3_ALIGN             	GLSL_SCALAR_VEC3_ARR_ALIGN
#define GLSL_SCALAR_MAT3_ARR_ALIGN			GLSL_SCALAR_MAT3_ALIGN
#define GLSL_SCALAR_MAT4_ALIGN             	GLSL_SCALAR_VEC4_ARR_ALIGN /* Recursively MAT2 --> array of VEC2, MAT3 --> array of VEC3, MAT4 --> array of VEC4 */
#define GLSL_SCALAR_MAT4_ARR_ALIGN			GLSL_SCALAR_MAT4_ALIGN
#define GLSL_SCALAR_DMAT2_ALIGN            	GLSL_SCALAR_DVEC2_ARR_ALIGN
#define GLSL_SCALAR_DMAT2_ARR_ALIGN			GLSL_SCALAR_DMAT2_ALIGN
#define GLSL_SCALAR_DMAT3_ALIGN            	GLSL_SCALAR_DVEC3_ARR_ALIGN
#define GLSL_SCALAR_DMAT3_ARR_ALIGN			GLSL_SCALAR_DMAT3_ALIGN
#define GLSL_SCALAR_DMAT4_ALIGN            	GLSL_SCALAR_DVEC4_ARR_ALIGN /* Recursively DMAT2 --> array of DVEC2, DMAT3 --> array of DVEC3, DMAT4 --> array of DVEC4 */
#define GLSL_SCALAR_DMAT4_ARR_ALIGN			GLSL_SCALAR_DMAT4_ALIGN

/* (std430) Base Layout */
#define GLSL_STD430_FLOAT_ALIGN            	GLSL_SCALAR_FLOAT_ALIGN /* IEEE 745 double precision float has 32 bits */
#define GLSL_STD430_FLOAT_ARR_ALIGN			GLSL_STD430_FLOAT_ALIGN /* IEEE 745 double precision float has 32 bits */
#define GLSL_STD430_INT_ALIGN              	GLSL_SCALAR_INT_ALIGN /* GLSL spec states 32-bits for int */
#define GLSL_STD430_INT_ARR_ALIGN 			GLSL_STD430_INT_ALIGN /* GLSL spec states 32-bits for int */
#define GLSL_STD430_UINT_ALIGN             	GLSL_SCALAR_UINT_ALIGN /* GLSL spec states 32-bits for uint */
#define GLSL_STD430_UINT_ARR_ALIGN 			GLSL_STD430_UINT_ALIGN /* GLSL spec states 32-bits for uint */
#define GLSL_STD430_DOUBLE_ALIGN           	GLSL_SCALAR_DOUBLE_ALIGN /* IEEE 745 double precision float has 64 bits */
#define GLSL_STD430_DOUBLE_ARR_ALIGN 		GLSL_STD430_DOUBLE_ALIGN /* IEEE 745 double precision float has 64 bits */
#define GLSL_STD430_IVEC4_ALIGN            	(4 * GLSL_STD430_INT_ALIGN)
#define GLSL_STD430_IVEC4_ARR_ALIGN 		GLSL_STD430_IVEC4_ALIGN
#define GLSL_STD430_UVEC4_ALIGN            	(4 * GLSL_STD430_UINT_ALIGN)
#define GLSL_STD430_UVEC4_ARR_ALIGN 		GLSL_STD430_UVEC4_ALIGN
#define GLSL_STD430_IVEC3_ALIGN            	(4 * GLSL_STD430_INT_ALIGN)
#define GLSL_STD430_IVEC3_ARR_ALIGN       	GLSL_STD430_IVEC3_ALIGN
#define GLSL_STD430_UVEC3_ALIGN            	(4 * GLSL_STD430_UINT_ALIGN)
#define GLSL_STD430_UVEC3_ARR_ALIGN        	GLSL_STD430_UVEC3_ALIGN
#define GLSL_STD430_IVEC2_ALIGN            	(2 * GLSL_STD430_INT_ALIGN)
#define GLSL_STD430_IVEC2_ARR_ALIGN        	GLSL_STD430_IVEC2_ALIGN
#define GLSL_STD430_UVEC2_ALIGN            	(2 * GLSL_STD430_UINT_ALIGN)
#define GLSL_STD430_UVEC2_ARR_ALIGN        	GLSL_STD430_UVEC2_ALIGN
#define GLSL_STD430_VEC2_ALIGN           	(2 * GLSL_STD430_FLOAT_ALIGN)
#define GLSL_STD430_VEC2_ARR_ALIGN         	GLSL_STD430_VEC2_ALIGN
#define GLSL_STD430_VEC3_ALIGN             	(4 * GLSL_STD430_FLOAT_ALIGN)
#define GLSL_STD430_VEC3_ARR_ALIGN         	GLSL_STD430_VEC3_ALIGN
#define GLSL_STD430_VEC4_ALIGN             	(4 * GLSL_STD430_FLOAT_ALIGN) /* Scalar Alignment: A vector type has a scalar alignment equal to that of its component type. */
#define GLSL_STD430_VEC4_ARR_ALIGN        	GLSL_STD430_VEC4_ALIGN /* Scalar Alignment: A vector type has a scalar alignment equal to that of its component type. */
#define GLSL_STD430_DVEC2_ALIGN            	(2 * GLSL_STD430_DOUBLE_ALIGN)
#define GLSL_STD430_DVEC2_ARR_ALIGN      	GLSL_STD430_DVEC2_ALIGN
#define GLSL_STD430_DVEC3_ALIGN            	(4 * GLSL_STD430_DOUBLE_ALIGN)
#define GLSL_STD430_DVEC3_ARR_ALIGN       	GLSL_STD430_DVEC3_ALIGN
#define GLSL_STD430_DVEC4_ALIGN            	(4 * GLSL_STD430_DOUBLE_ALIGN) /* Scalar Alignment: A vector type has a scalar alignment equal to that of its component type. */
#define GLSL_STD430_DVEC4_ARR_ALIGN        	GLSL_STD430_DVEC4_ALIGN /* Scalar Alignment: A vector type has a scalar alignment equal to that of its component type. */
#define GLSL_STD430_MAT2_ALIGN             	GLSL_STD430_VEC2_ARR_ALIGN
#define GLSL_STD430_MAT2_ARR_ALIGN			GLSL_STD430_MAT2_ALIGN
#define GLSL_STD430_MAT3_ALIGN             	GLSL_STD430_VEC3_ARR_ALIGN
#define GLSL_STD430_MAT3_ARR_ALIGN			GLSL_STD430_MAT3_ALIGN
#define GLSL_STD430_MAT4_ALIGN             	GLSL_STD430_VEC4_ARR_ALIGN /* Recursively MAT2 --> array of VEC2, MAT3 --> array of VEC3, MAT4 --> array of VEC4 */
#define GLSL_STD430_MAT4_ARR_ALIGN			GLSL_STD430_MAT4_ALIGN
#define GLSL_STD430_DMAT2_ALIGN            	GLSL_STD430_DVEC2_ARR_ALIGN
#define GLSL_STD430_DMAT2_ARR_ALIGN			GLSL_STD430_DMAT2_ALIGN
#define GLSL_STD430_DMAT3_ALIGN            	GLSL_STD430_DVEC3_ARR_ALIGN
#define GLSL_STD430_DMAT3_ARR_ALIGN			GLSL_STD430_DMAT3_ALIGN
#define GLSL_STD430_DMAT4_ALIGN            	GLSL_STD430_DVEC4_ARR_ALIGN /* Recursively DMAT2 --> array of DVEC2, DMAT3 --> array of DVEC3, DMAT4 --> array of DVEC4 */
#define GLSL_STD430_DMAT4_ARR_ALIGN			GLSL_STD430_DMAT4_ALIGN

/* (std140) Extended Layout */
#define GLSL_STD140_FLOAT_ALIGN 			GLSL_STD430_FLOAT_ALIGN
#define GLSL_STD140_FLOAT_ARR_ALIGN 		U32_NEXT_MULTIPLE(GLSL_STD430_FLOAT_ARR_ALIGN, 16)
#define GLSL_STD140_INT_ALIGN 				GLSL_STD430_INT_ALIGN
#define GLSL_STD140_INT_ARR_ALIGN 			U32_NEXT_MULTIPLE(GLSL_STD430_INT_ARR_ALIGN, 16)
#define GLSL_STD140_UINT_ALIGN 				GLSL_STD430_UINT_ALIGN
#define GLSL_STD140_UINT_ARR_ALIGN 			U32_NEXT_MULTIPLE(GLSL_STD430_UINT_ARR_ALIGN, 16)
#define GLSL_STD140_DOUBLE_ALIGN 			GLSL_STD430_DOUBLE_ALIGN
#define GLSL_STD140_DOUBLE_ARR_ALIGN 		U32_NEXT_MULTIPLE(GLSL_STD430_DOUBLE_ARR_ALIGN, 16)
#define GLSL_STD140_IVEC4_ALIGN 			GLSL_STD430_IVEC4_ALIGN
#define GLSL_STD140_IVEC4_ARR_ALIGN 		U32_NEXT_MULTIPLE(GLSL_STD430_IVEC4_ARR_ALIGN, 16)
#define GLSL_STD140_UVEC4_ALIGN 			GLSL_STD430_UVEC4_ALIGN
#define GLSL_STD140_UVEC4_ARR_ALIGN 		U32_NEXT_MULTIPLE(GLSL_STD430_UVEC4_ARR_ALIGN, 16)
#define GLSL_STD140_IVEC3_ALIGN 			GLSL_STD430_IVEC3_ALIGN
#define GLSL_STD140_IVEC3_ARR_ALIGN 		U32_NEXT_MULTIPLE(GLSL_STD430_IVEC3_ARR_ALIGN, 16)
#define GLSL_STD140_UVEC3_ALIGN 			GLSL_STD430_UVEC3_ALIGN
#define GLSL_STD140_UVEC3_ARR_ALIGN 		U32_NEXT_MULTIPLE(GLSL_STD430_UVEC3_ARR_ALIGN, 16)
#define GLSL_STD140_IVEC2_ALIGN 			GLSL_STD430_IVEC2_ALIGN
#define GLSL_STD140_IVEC2_ARR_ALIGN 		U32_NEXT_MULTIPLE(GLSL_STD430_IVEC2_ARR_ALIGN, 16)
#define GLSL_STD140_UVEC2_ALIGN 			GLSL_STD430_UVEC2_ALIGN
#define GLSL_STD140_UVEC2_ARR_ALIGN 		U32_NEXT_MULTIPLE(GLSL_STD430_UVEC2_ARR_ALIGN, 16)
#define GLSL_STD140_VEC2_ALIGN 				GLSL_STD430_VEC2_ALIGN
#define GLSL_STD140_VEC2_ARR_ALIGN 			U32_NEXT_MULTIPLE(GLSL_STD430_VEC2_ARR_ALIGN, 16)
#define GLSL_STD140_VEC3_ALIGN 				GLSL_STD430_VEC3_ALIGN
#define GLSL_STD140_VEC3_ARR_ALIGN 			U32_NEXT_MULTIPLE(GLSL_STD430_VEC3_ARR_ALIGN, 16)
#define GLSL_STD140_VEC4_ALIGN 				GLSL_STD430_VEC4_ALIGN
#define GLSL_STD140_VEC4_ARR_ALIGN 			U32_NEXT_MULTIPLE(GLSL_STD430_VEC4_ARR_ALIGN, 16)
#define GLSL_STD140_DVEC2_ALIGN 			GLSL_STD430_DVEC2_ALIGN
#define GLSL_STD140_DVEC2_ARR_ALIGN 		U32_NEXT_MULTIPLE(GLSL_STD430_DVEC2_ARR_ALIGN, 16)
#define GLSL_STD140_DVEC3_ALIGN 			GLSL_STD430_DVEC3_ALIGN
#define GLSL_STD140_DVEC3_ARR_ALIGN 		U32_NEXT_MULTIPLE(GLSL_STD430_DVEC3_ARR_ALIGN, 16)
#define GLSL_STD140_DVEC4_ALIGN 			GLSL_STD430_DVEC4_ALIGN
#define GLSL_STD140_DVEC4_ARR_ALIGN 		U32_NEXT_MULTIPLE(GLSL_STD430_DVEC4_ARR_ALIGN, 16)
#define GLSL_STD140_MAT2_ALIGN 				GLSL_STD430_MAT2_ALIGN
#define GLSL_STD140_MAT2_ARR_ALIGN			U32_NEXT_MULTIPLE(GLSL_STD430_MAT2_ALIGN, 16)
#define GLSL_STD140_MAT3_ALIGN 				GLSL_STD430_MAT3_ALIGN
#define GLSL_STD140_MAT3_ARR_ALIGN			U32_NEXT_MULTIPLE(GLSL_STD430_MAT3_ALIGN, 16)
#define GLSL_STD140_MAT4_ALIGN 				GLSL_STD430_MAT4_ALIGN
#define GLSL_STD140_MAT4_ARR_ALIGN			U32_NEXT_MULTIPLE(GLSL_STD430_MAT4_ALIGN, 16)
#define GLSL_STD140_DMAT2_ALIGN 			GLSL_STD430_DMAT2_ALIGN
#define GLSL_STD140_DMAT2_ARR_ALIGN			U32_NEXT_MULTIPLE(GLSL_STD430_DMAT2_ALIGN, 16)
#define GLSL_STD140_DMAT3_ALIGN 			GLSL_STD430_DMAT3_ALIGN
#define GLSL_STD140_DMAT3_ARR_ALIGN			U32_NEXT_MULTIPLE(GLSL_STD430_DMAT3_ALIGN, 16)
#define GLSL_STD140_DMAT4_ALIGN 			GLSL_STD430_DMAT4_ALIGN
#define GLSL_STD140_DMAT4_ARR_ALIGN			U32_NEXT_MULTIPLE(GLSL_STD430_DMAT4_ALIGN, 16)

