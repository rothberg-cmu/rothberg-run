#include <stdio.h>
#include "binstlTree.h"



unsigned int GetInteterTree(const unsigned char dat[4])
{
	unsigned int b0=dat[0];
	unsigned int b1=dat[1];
	unsigned int b2=dat[2];
	unsigned int b3=dat[3];
	return b0+b1*0x100+b2*0x10000+b3*0x1000000;
}

bool CPUIsLittleEndianTree(void)
{
	int a=1;
	unsigned char *b=((unsigned char *)&a);
	if(1==b[0])
	{
		return true;
	}
	else
	{
		return false;
	}
}

float GetFloatTree(const unsigned char dat[4])
{
	if(true==CPUIsLittleEndianTree())
	{
		const float *fPtr=(const float *)dat;
		return *fPtr;
	}
	else
	{
		unsigned char flip[4]={dat[3],dat[2],dat[1],dat[0]};
		const float *fPtr=(const float *)flip;
		return *fPtr;
	}
}



bool LoadBinStlTree(std::vector <float> &vtx,std::vector <float> &nom,const char fn[], const YsVec3 &offset)
{
	FILE *fp=fopen(fn,"rb");
	if(nullptr!=fp)
	{
		
		unsigned char buf[80];

		fread(buf,1,80,fp);


		fread(buf,4,1,fp);
		auto nTri=GetInteterTree(buf);
		//printf("%d\n",nTri);

		float offset_x = offset.xf();
		float offset_y = offset.yf();
		float offset_z = offset.zf();


		int nActual=0;
		while(50==fread(buf,1,50,fp))
		{
			auto nx=GetFloatTree(buf+0);
			auto ny=GetFloatTree(buf+4);
			auto nz=GetFloatTree(buf+8);

			auto x0=GetFloatTree(buf+12);
			auto y0=GetFloatTree(buf+16);
			auto z0=GetFloatTree(buf+20);

			auto x1=GetFloatTree(buf+24);
			auto y1=GetFloatTree(buf+28);
			auto z1=GetFloatTree(buf+32);

			auto x2=GetFloatTree(buf+36);
			auto y2=GetFloatTree(buf+40);
			auto z2=GetFloatTree(buf+44);

			vtx.push_back(x0/5 + offset_x);
			vtx.push_back(y0/5 + offset_y);
			vtx.push_back(z0/5 + offset_z);
			nom.push_back(nx);
			nom.push_back(ny);
			nom.push_back(nz);

			vtx.push_back(x1/5 + offset_x);
			vtx.push_back(y1/5 + offset_y);
			vtx.push_back(z1/5 + offset_z);
			nom.push_back(nx);
			nom.push_back(ny);
			nom.push_back(nz);

			vtx.push_back(x2/5 + offset_x);
			vtx.push_back(y2/5 + offset_y);
			vtx.push_back(z2/5 + offset_z);
			nom.push_back(nx);
			nom.push_back(ny);
			nom.push_back(nz);

			++nActual;
		}


		//printf("%d\n",nActual);


		fclose(fp);
		return true;
	}
	return false;
}


