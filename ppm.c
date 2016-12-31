/*
Copyright (c) 2016, Marco 'DispatchCode' C.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
   
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
   
3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by Marco 'DispatchCode' C.

THIS SOFTWARE IS PROVIDED ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef  _PPM_IMAGE
#define  _PPM_IMAGE

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "include/ppm.h"
#endif


/**
 * \brief <p>Memory allocation and struct initialization</p>
 *
 * @param  w  width  of the image
 * @param  h  height of the image
 */
void initialize(int w, int h) 
{
  if(image.pixels == NULL)
  {    
    image.pixels = (char*) calloc(3+(w*h*3), 8);
    image.w      = w;
    image.h      = h;
  }
}


/**
 *\brief <p><b>NOTE</b> The function assumes that a previously called to the function initialize() is occurred (for performance reason)
 *\brief Set pixel color at the (x,y) location</p>
 *
 * @param  x  x axys position
 * @param  y  y axys position
 * @param  r  red color
 * @param  g  green color
 * @param  b  blue color
 *
 */
void set_pixel_rgb(int x, int y, int r, int g, int b) 
{
  if(x >=0 && y>=0 && x<=image.w && y<=image.h) 
  {
    image.pixels[INDEX(x,y,image.w)  ] = (char) r;
    image.pixels[INDEX(x,y,image.w)+1] = (char) g;
    image.pixels[INDEX(x,y,image.w)+2] = (char) b;
  }
}

/**
 * \brief The same as before (refer to set_pixel_rgb() )
 *
 * @param color   packed color in rgb format
 */
void set_pixel_int(int x, int y, int color)
{
  set_pixel_rgb(x, y, R(color), G(color), B(color));
}

/**
 * \brief <p><b>WARNING!</b> call this only after a previous initialization calling (initialize())</p>
 *
 * @param pixels   pixels array
 */
void set_pixel_array(char* pixels)
{
  assert(image.pixels != NULL);
  memcpy(&image.pixels, &pixels, sizeof(image.pixels));
}


/**
 * \brief  Save Image in ppm format (eg. with ppm extension)
 *
 * @param  imageName   the name of the image
 */
void save_image(char *imageName) 
{  
  FILE *file = fopen(imageName, "wb");
  fprintf(file, "%s%d%s%d%s", "P6\n#DispatchCode PPM CLib\n", image.w, " ", image.h, "\n255\n");  
  fwrite(image.pixels, sizeof(char), 3+(image.w*image.h*3), file);
  
  fclose(file);
  free(image.pixels);
}

/**
 * \brief  Destroy pixel array without save image
 *
 */
void destroy()
{
  assert(image.pixels != NULL);
  free(image.pixels);
}