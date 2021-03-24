// cuts off at 0.04 * sampling freq
// example: if sampling frequency is 10 kHz, the cutoff is 400 Hz
void BesselLowpassThirdOrder004(const double src[], double dest[], int size)
{
    double xv[3+1] = {0.0};
    double yv[3+1] = {0.0};

    for (int i=0; i<size; i++)
    {
        xv[0] = xv[1]; xv[1] = xv[2]; xv[2] = xv[3]; 
        xv[3] = src[i] / double(2.711023309e+02);
        yv[0] = yv[1]; yv[1] = yv[2]; yv[2] = yv[3]; 
        yv[3] = (xv[0] + xv[3]) + 3 * (xv[1] + xv[2])
                + (  0.4226750651 * yv[0]) + ( -1.6550518354 * yv[1])
                + (  2.2028676179 * yv[2]);
        dest[i] = yv[3];
    }
}
