#pragma once
#ifndef VID_COMMON
#define VID_COMMON

#define FCONTEXT_CORE_PROFILE		BIT( 0 )
#define FCONTEXT_DEBUG_ARB		BIT( 1 )

typedef struct vidmode_s
{
	const char	*desc;
	int			width;
	int			height;
} vidmode_t;

// minimal recommended resolution
#define VID_MIN_WIDTH	640
#define VID_MIN_HEIGHT	480

//
// vid_common.c
//
qboolean VID_SetMode( void );
#define GL_CheckForErrors() GL_CheckForErrors_( __FILE__, __LINE__ )
void GL_CheckForErrors_( const char *filename, const int fileline );
const char *GL_ErrorString( int err );
void GL_UpdateSwapInterval( void );
qboolean GL_Support( int r_ext );
void VID_CheckChanges( void );
int GL_MaxTextureUnits( void );
qboolean R_Init( void );
void R_Shutdown( void );
const char *VID_GetModeString( int vid_mode );
void R_SaveVideoMode( int w, int h );
void VID_StartupGamma( void );
void GL_CheckExtension( const char *name, const dllfunc_t *funcs, const char *cvarname, int r_ext );
void GL_SetExtension( int r_ext, int enable );

#endif // VID_COMMON
