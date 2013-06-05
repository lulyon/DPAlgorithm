#include <iostream>
#include <vector>
#include "DouglasPeucker.h"
using namespace std;

void readin(vector<MyPointStruct> &Points,const char * filename)
{
  MyPointStruct SinglePoint;
	FILE *fp = fopen(filename,"r");
	while(fscanf(fp,"%lf%lf",&SinglePoint.X,&SinglePoint.Y)!=EOF)
	{
		Points.push_back(SinglePoint);
	}
}

void DouglasPeuckerAlgorithm(vector<MyPointStruct> &Points,int tolerance,const char*filename)
{
	DouglasPeucker Instance(Points,tolerance);
	Instance.WriteData(filename);
}

void DumpOut1()
{
	printf("done!\n");
}

void DumpOut2()
{
	printf("need 3 command line parameter:\n[0]executable file name;\n[1]file name of the input data;\n[2]file name of the output data;\n[3]threshold.\n");
}

int main(int argc, const char *argv[])
{
	if(argc==4)
	{
		vector<MyPointStruct> Points;
		readin(Points,argv[1]);

		int threshold = atoi(argv[3]);		
		DouglasPeuckerAlgorithm(Points,threshold,argv[2]);
		DumpOut1();
	}
	else
	{
		DumpOut2();
	}
	return 0;
}
