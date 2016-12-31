/* ***********************************************************************
 * Description:  A simple PPM image library with some - in future - improvements.
 *               I'm writing it for one of mine little and future project.
 * -----------------------------------------------------------------------
 * License    :  BSD LICENS (refer to LICENSE)
 * -----------------------------------------------------------------------
 */


#include<stdlib.h>
#include<stdio.h>

/**
 * \brief Test and demo file for PPM image library
 *
 */

int main() 
{
  int w = 1024, h = 768, i, j;
  
  initialize(w, h);
  
  for(i=0; i<w; i++) 
  {
    set_pixel_rgb(i,h/2,0,255,0);
  }
  
  for(j=0; j<h; j++) 
  {
    set_pixel_rgb(w/2,j,255,0,0);
  }
  
  save_image("test_set_pixel.ppm");
  
  /* Test two
   *
   * Create array and passing it
   *
   */
  
  char *px = (char*) calloc(3+(w*h*3), 8);
  
  i = 0, j = h/2;
  for(; i<w; i++)
  {
    if(i < w) 
    {
      px[3 * (i + j * w)+1]  = 255;
    }
  }
  
  i = w/2;
  j = 0;
  for(; j<h; j++)
  {
    if(j+1 < h) 
    {
      px[3 * (i + j * w)] = 255;
    }
  }
  
  initialize(w,h);
  set_pixel_array(px);

  save_image("test_set_array.ppm");
  
  return 0;
}