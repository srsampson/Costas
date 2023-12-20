#### Costas - A Costas Loop Algorithm
This code was translated from C++ to C and was originally in GNU Radio.

First you create the control loop:
```
/*
 * All terms are radians per sample.
 *
 * The loop bandwidth determins the lock range
 * and should be set around TAU/100 to TAU/200
 */
create_control_loop((TAU / 180.0f), -1.0f, 1.0f);
```
Then you update the loop after every baseband symbol received:
```
/*
 * This method is much faster than using cexp()
 */
#define cmplx(float_value) (cosf(float_value) + sinf(float_value) * I)
#define cmplxconj(float_value) (cosf(float_value) + sinf(float_value) * -I)
```
You could also do something like this if your compiler doesn't like "I" syntax.
```
#define cmplxconj(float value) CMPLXF(cosf(float_value), -sinf(float_value))
```
So multiply the conjugate of the current phase value against the baseband receive symbol
```
    complex float costasSymbol = decimatedSymbol * cmplxconj(get_phase());

    qpskDemodulate(costasSymbol, diBits);
```
Then update the loop error based on the phase detector error
```
    /*
     * The constellation gets rotated +45 degrees (rectangular)
     * from what was transmitted (diamond) with costas enabled
     */
    float d_error = phase_detector(costasSymbol);

    advance_loop(d_error);
    phase_wrap();
    frequency_limit();
```
etc, etc...
