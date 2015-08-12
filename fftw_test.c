#include<fftw3.h>
#include<stdio.h>
#define N 8
#define M 9


/* -I /usr/local/include -L /usr/local/lib -lm -lfftw3 */
int main()
{
    int i;
    
    fftw_complex *in,*out;
    fftw_plan p;
    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    
    if((in==NULL)||(out==NULL))
    {
        printf("Error:insufficient available memory\n");
    }
    else
    {
        
        for(i=0; i<N; i++)
        {
            in[i][0] = i+1;
            in[i][1] = 0;
        }
    }
    
    p = fftw_plan_dft_1d(M, in, out, FFTW_FORWARD,FFTW_ESTIMATE);
    
    fftw_execute(p); /* repeat as needed */
    fftw_destroy_plan(p);
    fftw_cleanup();
    for(i=0;i<N;i++)/*OUTPUT*/
    {
        printf("%f,%fi\n",in[i][0],in[i][1]);
    }
    printf("\n");
    for(i=0;i<M;i++)/*OUTPUT*/
    {
        printf("%d is : %f,%fi\n",i,out[i][0],out[i][1]);
    }
    
    if(in!=NULL) fftw_free(in);
    if(out!=NULL) fftw_free(out);
    return 0;
}
