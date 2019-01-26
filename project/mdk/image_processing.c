//#include "image_processing.h"
void RGB_TO_GRAY()
{
}
/*======================================================================*/
/* OTSU global thresholding routine */
/* takes a 2D unsigned char array pointer, number of rows, and */
/* number of cols in the array. returns the value of the threshold */
/*parameter: 
*image --- buffer for image
rows, cols --- size of image
x0, y0, dx, dy --- region of vector used for computing threshold
vvv --- debug option, is 0, no debug information outputed
/*======================================================================*/
int otsu (unsigned char*image, int rows, int cols, int x0, int y0, int dx, int dy, int vvv)
{
    
    unsigned char*np; // ????
		int thresholdValue=1; // ??
		int ihist[256]; // ?????,256??
    
		int i, j, k; // various counters
		int n, n1, n2, gmin, gmax;
		double m1, m2, sum, csum, fmax, sb;
    // ??????
    memset(ihist, 0, sizeof(ihist));
    
    gmin=255; gmax=0;
		// ?????
		for (i = y0 +1; i < y0 + dy -1; i++) 
			{
        np = (unsigned char*)image[i*cols+x0+1];
		for (j = x0 +1; j < x0 + dx -1; j++)
        {
            ihist[*np]++;
						if(*np > gmax) gmax=*np;
						if(*np < gmin) gmin=*np;
            np++; /* next pixel */
        }
    }
    
// set up everything
    sum = csum =0.0;
    n =0;
    
		for (k =0; k <=255; k++) 
    {
        sum += (double) k * (double) ihist[k]; /* x*f(x) ???*/
        n += ihist[k]; /* f(x) ?? */
    }
    
		if (!n) 
    {
			// if n has no value, there is problems...
       // fprintf (stderr, "NOT NORMAL thresholdValue = 160\n");
				return (160);
    }
    
      // do the otsu global thresholding method
    fmax =-1.0;
    n1 =0;
		for (k =0; k <255; k++)
    {
        n1 += ihist[k];
				if (!n1) 
        { 
					continue; 
        }
        n2 = n - n1;
				if (n2 ==0)
        { 
					break; 
        }
        csum += (double) k *ihist[k];
        m1 = csum / n1;
        m2 = (sum - csum) / n2;
        sb = (double) n1 *(double) n2 *(m1 - m2) * (m1 - m2);
			/* bbg: note: can be optimized. */
			if (sb > fmax) 
        {
            fmax = sb;
            thresholdValue = k;
        }
    }
    
// at this point we have our thresholding value
    
// debug code to display thresholding values
			if ( vvv &1 )
       // fprintf(stderr,"# OTSU: thresholdValue = %d gmin=%d gmax=%d\n",thresholdValue, gmin, gmax);
    
			return(thresholdValue);
}