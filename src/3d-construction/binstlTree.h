#ifndef BINTREESTL_H_IS_INCLUDED
#define BINTREESTL_H_IS_INCLUDED


#include <vector>
#include <ysclass.h>

bool LoadBinStlTree(std::vector <float> &vtx,std::vector <float> &nom,const char fn[], const YsVec3 &offset, double scale);
bool LoadBinStlCoin(std::vector <float> &vtx,std::vector <float> &nom,const char fn[], const YsVec3 &offset, double scale);

#endif
