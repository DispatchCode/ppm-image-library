/*
 * PPM header lib definitions
 * The Image state is maintained internally
 *
 */

#define INDEX(x,y,w) (3 * (x + y * w))

#define R(color) (color >> 0x10 & 0xFF)
#define G(color) (color >> 0x08 & 0xFF)
#define B(color) (color & 0xFF)


typedef struct _ppm_image
{
  char *pixels;
  int  w;
  int  h;
} ppm_image;
ppm_image image;



//
// Function definitions
//

void set_pixel_rgb(int, int, int, int, int);
void set_pixel_array(char*);
void set_pixel_int(int, int, int);
void save_image(char*);
void initialize(int, int);

