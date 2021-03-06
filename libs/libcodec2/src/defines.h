/*---------------------------------------------------------------------------*\

  FILE........: defines.h                                                     
  AUTHOR......: David Rowe                                                          
  DATE CREATED: 23/4/93                                                       
                                                                             
  Defines and structures used throughout the codec.			     
                                                                             
\*---------------------------------------------------------------------------*/

/*
  Copyright (C) 2009 David Rowe

  All rights reserved.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License version 2.1, as
  published by the Free Software Foundation.  This program is
  distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
  License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef __DEFINES__
#define __DEFINES__

/*---------------------------------------------------------------------------*\
                                                                             
				DEFINES                                       
                                                                             
\*---------------------------------------------------------------------------*/

/* General defines */

#define N          80		/* number of samples per frame          */
#define MAX_AMP    80		/* maximum number of harmonics          */
#define PI         3.141592654	/* mathematical constant                */
#define TWO_PI     6.283185307	/* mathematical constant                */
#define FS         8000		/* sample rate in Hz                    */
#define MAX_STR    256          /* maximum string size                  */

#define NW         279          /* analysis window size                 */
#define FFT_ENC    512		/* size of FFT used for encoder         */
#define FFT_DEC    512	    	/* size of FFT used in decoder          */
#define TW         40		/* Trapezoidal synthesis window overlap */
#define V_THRESH   4.0          /* voicing threshold in dB              */
#define LPC_MAX    20		/* maximum LPC order                    */
#define LPC_ORD    10		/* phase modelling LPC order            */

/* Pitch estimation defines */

#define M        320		/* pitch analysis frame size            */
#define P_MIN    20		/* minimum pitch                        */
#define P_MAX    160		/* maximum pitch                        */

/*---------------------------------------------------------------------------*\
                                                                             
				TYPEDEFS                                      
                                                                             
\*---------------------------------------------------------------------------*/

/* Complex number */

typedef struct {
  float real;
  float imag;
} COMP;

/* Structure to hold model parameters for one frame */

typedef struct {
  float Wo;		/* fundamental frequency estimate in radians  */
  int   L;		/* number of harmonics                        */
  float A[MAX_AMP];	/* amplitiude of each harmonic                */
  float phi[MAX_AMP];	/* phase of each harmonic                     */
  int   voiced;	        /* non-zero if this frame is voiced           */
} MODEL;

#endif
