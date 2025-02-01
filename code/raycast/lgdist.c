#ifndef LGDIST_C
#define LGDIST_C

extern signed char OriginX;
extern signed char OriginY;
extern signed char PointX;
extern signed char PointY;
extern unsigned char log_distance;

unsigned char logdist (signed char Ox, signed char Oy, signed char Px, signed char Py){
OriginX = Ox;
OriginY = Oy;
PointX = Px;
PointY = Py;
lgdistance();

return log_distance;
}
#endif //LGDIST_C