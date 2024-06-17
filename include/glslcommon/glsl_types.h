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
GLSL_COM_API u32 alignof_glsl_type(glsl_type_t type, glsl_memory_layout_t layout);
GLSL_COM_API u32 alignof_glsl_type_array(glsl_type_t type, glsl_memory_layout_t layout);
typedef glsl_type_layout_traits_t (*glsl_type_layout_traits_callback_t)(void* user_data, u32 type_index);
GLSL_COM_API u32 alignof_glsl_type_struct(glsl_type_layout_traits_callback_t callback, void* user_data, u32 type_traits_count, glsl_memory_layout_t layout);
#define alignof_glsl_type_struct_array alignof_glsl_type_struct

/* returns size (in bytes) of a glsl type 'type' */
GLSL_COM_API u32 sizeof_glsl_type(glsl_type_t type, glsl_memory_layout_t layout);
/* returns VkFormat (u32) of a glsl type 'type' */
GLSL_COM_API u32 vkformatof_glsl_type(glsl_type_t type);

/* force syntax error */
#define FORCE_ERROR(description) (yield @ error description)

#define GLSL_TYPE_BLOCK_ALIGN 			FORCE_ERROR("align is not defined for BLOCK")
#define GLSL_TYPE_FLOAT_ALIGN 			4
#define GLSL_TYPE_INT_ALIGN 			4
#define GLSL_TYPE_UINT_ALIGN			4
#define GLSL_TYPE_DOUBLE_ALIGN 			FORCE_ERROR("double is not supported yet")
#define GLSL_TYPE_VEC4_ALIGN 			16
#define GLSL_TYPE_IVEC4_ALIGN 			16
#define GLSL_TYPE_UVEC4_ALIGN 			16
#define GLSL_TYPE_IVEC3_ALIGN 			16
#define GLSL_TYPE_UVEC3_ALIGN 			16
#define GLSL_TYPE_VEC3_ALIGN 			16
#define GLSL_TYPE_MAT4_ALIGN 			16
#define GLSL_TYPE_MAT3_ALIGN 			16
#define GLSL_TYPE_IVEC2_ALIGN 			8
#define GLSL_TYPE_UVEC2_ALIGN 			8
#define GLSL_TYPE_VEC2_ALIGN 			8
#define GLSL_TYPE_MAT2_ALIGN 			8
#define GLSL_TYPE_SAMPLER_2D_ALIGN 		FORCE_ERROR("size is not defined for Opaque types")
#define GLSL_TYPE_SAMPLER_3D_ALIGN 		FORCE_ERROR("size is not defined for Opaque types")
#define GLSL_TYPE_SAMPLER_CUBE_ALIGN 	FORCE_ERROR("size is not defined for Opaque types")

#define GLSL_TYPE_BLOCK_SIZE  			FORCE_ERROR("size is not defined for BLOCK")
#define GLSL_TYPE_FLOAT_SIZE			4
#define GLSL_TYPE_INT_SIZE 				4
#define GLSL_TYPE_UINT_SIZE				4
#define GLSL_TYPE_DOUBLE_SIZE 			FORCE_ERROR("double is not supported yet")
#define GLSL_TYPE_VEC4_SIZE 			16
#define GLSL_TYPE_IVEC4_SIZE 			16
#define GLSL_TYPE_UVEC4_SIZE 			16
#define GLSL_TYPE_MAT2_SIZE  			16
#define GLSL_TYPE_IVEC3_SIZE 			12
#define GLSL_TYPE_UVEC3_SIZE 			12
#define GLSL_TYPE_VEC3_SIZE 			12
#define GLSL_TYPE_IVEC2_SIZE 			8
#define GLSL_TYPE_UVEC2_SIZE 			8
#define GLSL_TYPE_VEC2_SIZE 			8
#define GLSL_TYPE_MAT4_SIZE 			64
#define GLSL_TYPE_MAT3_SIZE 			36
#define GLSL_TYPE_SAMPLER_2D_SIZE 		FORCE_ERROR("size is not defined for Opque types")
#define GLSL_TYPE_SAMPLER_3D_SIZE		FORCE_ERROR("size is not defined for Opque types")
#define GLSL_TYPE_SAMPLER_CUBE_SIZE		FORCE_ERROR("size is not defined for Opque types")

typedef f32 glsl_float_t ALIGN_AS(GLSL_TYPE_FLOAT_ALIGN);
typedef s32 glsl_int_t ALIGN_AS(GLSL_TYPE_INT_ALIGN);
typedef u32 glsl_uint_t ALIGN_AS(GLSL_TYPE_UINT_ALIGN);
typedef struct glsl_vec4_t { glsl_float_t x, y, z, w; } glsl_vec4_t ALIGN_AS(GLSL_TYPE_VEC4_ALIGN);
typedef struct glsl_vec3_t { glsl_float_t x, y, z; } glsl_vec3_t ALIGN_AS(GLSL_TYPE_VEC3_ALIGN);
typedef struct glsl_vec2_t { glsl_float_t x, y; } glsl_vec2_t ALIGN_AS(GLSL_TYPE_VEC2_ALIGN);
typedef struct glsl_ivec4_t { glsl_int_t x, y, z, w; } glsl_ivec4_t ALIGN_AS(GLSL_TYPE_IVEC4_ALIGN);
typedef struct glsl_ivec3_t { glsl_int_t x, y, z; } glsl_ivec3_t ALIGN_AS(GLSL_TYPE_IVEC3_ALIGN);
typedef struct glsl_ivec2_t { glsl_int_t x, y; } glsl_ivec2_t ALIGN_AS(GLSL_TYPE_IVEC2_ALIGN);
typedef struct glsl_uvec4_t { glsl_uint_t x, y, z, w; } glsl_uvec4_t ALIGN_AS(GLSL_TYPE_UVEC4_ALIGN);
typedef struct glsl_uvec3_t { glsl_uint_t x, y, z; } glsl_uvec3_t ALIGN_AS(GLSL_TYPE_UVEC3_ALIGN);
typedef struct glsl_uvec2_t { glsl_uint_t x, y; } glsl_uvec2_t ALIGN_AS(GLSL_TYPE_UVEC2_ALIGN);
typedef union glsl_mat4_t
{
	struct { glsl_vec4_t r0, r1, r2, r3; };
	struct
	{
		glsl_float_t m00, m01, m02, m03,
					 m10, m11, m12, m13,
					 m20, m21, m22, m23,
					 m30, m31, m32, m33;
	};
} glsl_mat4_t ALIGN_AS(GLSL_TYPE_MAT4_ALIGN);
typedef union glsl_mat3_t
{
	struct { glsl_vec3_t r0, r1, r2; };
	struct
	{
		glsl_float_t m00, m01, m02,
					 m10, m11, m12,
					 m20, m21, m22;
	};
} glsl_mat3_t ALIGN_AS(GLSL_TYPE_MAT3_ALIGN);
typedef union glsl_mat2_t
{
	struct { glsl_float_t r0, r1; };
	struct { glsl_float_t m00, m01, m10, m11; };
} glsl_mat2_t ALIGN_AS(GLSL_TYPE_MAT2_ALIGN);

#define __glsl_sizeof_glsl_block_t 			GLSL_TYPE_BLOCK_SIZE
#define __glsl_sizeof_glsl_float_t 			GLSL_TYPE_FLOAT_SIZE
#define __glsl_sizeof_glsl_int_t 			GLSL_TYPE_INT_SIZE
#define __glsl_sizeof_glsl_uint_t 			GLSL_TYPE_UINT_SIZE
#define __glsl_sizeof_glsl_double_t 		GLSL_TYPE_DOUBLE_SIZE
#define __glsl_sizeof_glsl_vec4_t 			GLSL_TYPE_VEC4_SIZE
#define __glsl_sizeof_glsl_ivec4_t 			GLSL_TYPE_IVEC4_SIZE
#define __glsl_sizeof_glsl_uvec4_t 			GLSL_TYPE_UVEC4_SIZE
#define __glsl_sizeof_glsl_mat2_t 			GLSL_TYPE_MAT2_SIZE
#define __glsl_sizeof_glsl_ivec3_t 			GLSL_TYPE_IVEC3_SIZE
#define __glsl_sizeof_glsl_uvec3_t 			GLSL_TYPE_UVEC3_SIZE
#define __glsl_sizeof_glsl_vec3_t 			GLSL_TYPE_VEC3_SIZE
#define __glsl_sizeof_glsl_ivec2_t 			GLSL_TYPE_IVEC2_SIZE
#define __glsl_sizeof_glsl_uvec2_t 			GLSL_TYPE_UVEC2_SIZE
#define __glsl_sizeof_glsl_vec2_t 			GLSL_TYPE_VEC2_SIZE
#define __glsl_sizeof_glsl_mat4_t 			GLSL_TYPE_MAT4_SIZE
#define __glsl_sizeof_glsl_mat3_t 			GLSL_TYPE_MAT3_SIZE
#define __glsl_sizeof_glsl_sampler_2d_t 	GLSL_TYPE_SAMPLER_2D_SIZE
#define __glsl_sizeof_glsl_sampler_3d_t 	GLSL_TYPE_SAMPLER_3D_SIZE
#define __glsl_sizeof_glsl_sampler_cube_t 	GLSL_TYPE_SAMPLER_CUBE_SIZE

#define glsl_sizeof(glsl_type) __glsl_sizeof_##glsl_type

#define __glsl_alignof_glsl_block_t 		GLSL_TYPE_BLOCK_ALIGN
#define __glsl_alignof_glsl_float_t 		GLSL_TYPE_FLOAT_ALIGN
#define __glsl_alignof_glsl_int_t 			GLSL_TYPE_INT_ALIGN
#define __glsl_alignof_glsl_uint_t 			GLSL_TYPE_UINT_ALIGN
#define __glsl_alignof_glsl_double_t 		GLSL_TYPE_DOUBLE_ALIGN
#define __glsl_alignof_glsl_vec4_t 			GLSL_TYPE_VEC4_ALIGN
#define __glsl_alignof_glsl_ivec4_t 		GLSL_TYPE_IVEC4_ALIGN
#define __glsl_alignof_glsl_uvec4_t 		GLSL_TYPE_UVEC4_ALIGN
#define __glsl_alignof_glsl_mat2_t 			GLSL_TYPE_MAT2_ALIGN
#define __glsl_alignof_glsl_ivec3_t 		GLSL_TYPE_IVEC3_ALIGN
#define __glsl_alignof_glsl_uvec3_t 		GLSL_TYPE_UVEC3_ALIGN
#define __glsl_alignof_glsl_vec3_t 			GLSL_TYPE_VEC3_ALIGN
#define __glsl_alignof_glsl_ivec2_t 		GLSL_TYPE_IVEC2_ALIGN
#define __glsl_alignof_glsl_uvec2_t 		GLSL_TYPE_UVEC2_ALIGN
#define __glsl_alignof_glsl_vec2_t 			GLSL_TYPE_VEC2_ALIGN
#define __glsl_alignof_glsl_mat4_t 			GLSL_TYPE_MAT4_ALIGN
#define __glsl_alignof_glsl_mat3_t 			GLSL_TYPE_MAT3_ALIGN
#define __glsl_alignof_glsl_sampler_2d_t 	GLSL_TYPE_SAMPLER_2D_ALIGN
#define __glsl_alignof_glsl_sampler_3d_t 	GLSL_TYPE_SAMPLER_3D_ALIGN
#define __glsl_alignof_glsl_sampler_cube_t 	GLSL_TYPE_SAMPLER_CUBE_ALIGN

#define glsl_alignof(glsl_type) __glsl_alignof_##glsl_type
