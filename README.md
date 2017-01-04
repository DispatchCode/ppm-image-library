# PPM Image Library (v1.0)
This is the first version of the PPM Imgage library that I'm writing. This project is born only like a base for a future and small - but interesting - project.

The library is fully documented, and in a future version I will be use Doxygen for generating the documentation. 

The following are few example (image converted because of their size):

*Plus sign with background white color*

```
void third_test()
{
  int i, j;
  
  initialize(w, h);                         // Initialize the array pixels array to 0's
  set_background_rgb(255, 255, 255);        // Set white color on all the background image
  
  // Horizontal Green line
  for(i=0; i<w; i++) 
  {
    set_pixel_rgb(i,h/2,0,255,0);
  }
  
  // Vertical red line
  for(j=0; j<h; j++) 
  {
    set_pixel_rgb(w/2,j,255,0,0);
  }
  
  // Save the image
  save_image("test_set_bg_pixel.ppm");
}
```

![Set background and pixels](http://i64.tinypic.com/o0a1rr.png)


##CHANGELOG##

 - 4 gennaio 2017 18:17: added background function(s) and rect function