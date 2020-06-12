#include <iostream>
#include <cmath>
#include <fstream>
#include <list>

using namespace std;

struct triangleType
{
    double vertex1X;
    double vertex1Y;
    double vertex2X;
    double vertex2Y;
    double vertex3X;
    double vertex3Y;
};

class circleType
{
    double radius;
    int numOfTriangles;
    triangleType triangle1[30];
    triangleType triangle2[30];
    list<triangleType> meshGrid2;
    list<triangleType>::iterator itr2;
    list<list<triangleType>> meshGrid1;
    list<list<triangleType>>::iterator itr1;
    triangleType *grid;
    list<double> xList;
    list<double>::iterator xItr;
    list<double>::iterator yItr;
    double *xVar;
    list<double> yList;
    double *yVar;
public:
    ~circleType()
    {
        xList.erase(xList.begin(), xList.end());
        yList.erase(yList.begin(), yList.end());
    }
    circleType()
    {
        radius = 6;
        numOfTriangles = 30;
        for(int index = 0; index < numOfTriangles; index++)
        {
            triangle1[index].vertex1X = 0;
            triangle1[index].vertex1Y = 0;
            triangle1[index].vertex2X = 0;
            triangle1[index].vertex2Y = 0;
            triangle1[index].vertex3X = 0;
            triangle1[index].vertex3Y = 0;
            triangle2[index].vertex1X = 0;
            triangle2[index].vertex1Y = 0;
            triangle2[index].vertex2X = 0;
            triangle2[index].vertex2Y = 0;
            triangle2[index].vertex3X = 0;
            triangle2[index].vertex3Y = 0;
        }
    }
    void makeCircle()
    {
        double infinitesimal = 0;
        for(int index = 0; index < 250; index++)
        {
            if(infinitesimal <= 6)
            {
                xVar = new double;
                yVar = new double;
                *xVar = infinitesimal;
                *yVar = sqrt(pow(radius, 2) - pow(*xVar, 2));
                xList.push_back(*xVar);
                yList.push_back(*yVar);
            }
            infinitesimal = infinitesimal + 0.1;
        }
        infinitesimal = 0;
        for(int index = 250; index < 500; index++)
        {
            if(infinitesimal >= -6)
            {
                xVar = new double;
                yVar = new double;
                *xVar = infinitesimal;
                *yVar = sqrt(pow(radius, 2) - pow(*xVar, 2));
                xList.push_back(*xVar);
                yList.push_back(*yVar);
            }
            infinitesimal = infinitesimal - 0.1;
        }
        infinitesimal = 0;
        for(int index = 500; index < 750; index++)
        {
            if(infinitesimal <= 6)
            {
                xVar = new double;
                yVar = new double;
                *xVar = infinitesimal;
                *yVar = -sqrt(pow(radius, 2) - pow(*xVar, 2));
                xList.push_back(*xVar);
                yList.push_back(*yVar);
            }
            infinitesimal = infinitesimal + 0.1;
        }
        infinitesimal = 0;
        for(int index = 750; index < 1000; index++)
        {
            if(infinitesimal >= -6)
            {
                xVar = new double;
                yVar = new double;
                *xVar = infinitesimal;
                *yVar = -sqrt(pow(radius, 2) - pow(*xVar, 2));
                xList.push_back(*xVar);
                yList.push_back(*yVar);
            }
            infinitesimal = infinitesimal - 0.1;
        }
    }
    void makeMesh()
    {
        triangle1[0].vertex1X = -8;
        triangle1[0].vertex1Y = 8;
        triangle1[0].vertex2X = -8;
        triangle1[0].vertex2Y = 7;
        triangle1[0].vertex3X = -7;
        triangle1[0].vertex3Y = 7;

        triangle2[0].vertex1X = -8;
        triangle2[0].vertex1Y = 6;
        triangle2[0].vertex2X = -8;
        triangle2[0].vertex2Y = 7;
        triangle2[0].vertex3X = -7;
        triangle2[0].vertex3Y = 7;

        int temp = 1;
        for(int index = 1; index < numOfTriangles; index++)
        {
            if(temp == 1)
            {
                triangle1[index].vertex1X = triangle1[index - 1].vertex1X;
                triangle1[index].vertex1Y = triangle1[index - 1].vertex1Y;
                triangle1[index].vertex2X = triangle1[index - 1].vertex2X + 1;
                triangle1[index].vertex2Y = triangle1[index - 1].vertex2Y + 1;
                triangle1[index].vertex3X = triangle1[index - 1].vertex3X;
                triangle1[index].vertex3Y = triangle1[index - 1].vertex3Y;

                triangle2[index].vertex1X = triangle2[index - 1].vertex1X;
                triangle2[index].vertex1Y = triangle2[index - 1].vertex1Y;
                triangle2[index].vertex2X = triangle2[index - 1].vertex2X + 1;
                triangle2[index].vertex2Y = triangle2[index - 1].vertex2Y - 1;
                triangle2[index].vertex3X = triangle2[index - 1].vertex3X;
                triangle2[index].vertex3Y = triangle2[index - 1].vertex3Y;
            }
            else if(temp == 2)
            {
                triangle1[index].vertex1X = triangle1[index - 1].vertex1X + 2;
                triangle1[index].vertex1Y = triangle1[index - 1].vertex1Y;
                triangle1[index].vertex2X = triangle1[index - 1].vertex2X;
                triangle1[index].vertex2Y = triangle1[index - 1].vertex2Y;
                triangle1[index].vertex3X = triangle1[index - 1].vertex3X;
                triangle1[index].vertex3Y = triangle1[index - 1].vertex3Y;

                triangle2[index].vertex1X = triangle2[index - 1].vertex1X + 2;
                triangle2[index].vertex1Y = triangle2[index - 1].vertex1Y;
                triangle2[index].vertex2X = triangle2[index - 1].vertex2X;
                triangle2[index].vertex2Y = triangle2[index - 1].vertex2Y;
                triangle2[index].vertex3X = triangle2[index - 1].vertex3X;
                triangle2[index].vertex3Y = triangle2[index - 1].vertex3Y;
            }
            else if(temp == 3)
            {
                triangle1[index].vertex1X = triangle1[index - 1].vertex1X;
                triangle1[index].vertex1Y = triangle1[index - 1].vertex1Y;
                triangle1[index].vertex2X = triangle1[index - 1].vertex2X + 1;
                triangle1[index].vertex2Y = triangle1[index - 1].vertex2Y - 1;
                triangle1[index].vertex3X = triangle1[index - 1].vertex3X;
                triangle1[index].vertex3Y = triangle1[index - 1].vertex3Y;

                triangle2[index].vertex1X = triangle2[index - 1].vertex1X;
                triangle2[index].vertex1Y = triangle2[index - 1].vertex1Y;
                triangle2[index].vertex2X = triangle2[index - 1].vertex2X + 1;
                triangle2[index].vertex2Y = triangle2[index - 1].vertex2Y + 1;
                triangle2[index].vertex3X = triangle2[index - 1].vertex3X;
                triangle2[index].vertex3Y = triangle2[index - 1].vertex3Y;
            }
            else if(temp == 4)
            {
                triangle1[index].vertex1X = triangle1[index - 1].vertex1X;
                triangle1[index].vertex1Y = triangle1[index - 1].vertex1Y;
                triangle1[index].vertex2X = triangle1[index - 1].vertex2X;
                triangle1[index].vertex2Y = triangle1[index - 1].vertex2Y;
                triangle1[index].vertex3X = triangle1[index - 1].vertex3X + 2;
                triangle1[index].vertex3Y = triangle1[index - 1].vertex3Y;

                triangle2[index].vertex1X = triangle2[index - 1].vertex1X;
                triangle2[index].vertex1Y = triangle2[index - 1].vertex1Y;
                triangle2[index].vertex2X = triangle2[index - 1].vertex2X;
                triangle2[index].vertex2Y = triangle2[index - 1].vertex2Y;
                triangle2[index].vertex3X = triangle2[index - 1].vertex3X + 2;
                triangle2[index].vertex3Y = triangle2[index - 1].vertex3Y;
                temp = 0;
            }
            temp++;
        }


        temp = 1;
        for(int index = 0; index <  numOfTriangles; index++)
        {
            if(temp == 1)
            {
                for(int index1 = 0; index1 < numOfTriangles; index1++)
                {
                    grid = new triangleType;
                    grid->vertex1X = triangle1[index1].vertex1X;
                    grid->vertex1Y = triangle1[index1].vertex1Y - index;
                    grid->vertex2X = triangle1[index1].vertex2X;
                    grid->vertex2Y = triangle1[index1].vertex2Y - index;
                    grid->vertex3X = triangle1[index1].vertex3X;
                    grid->vertex3Y = triangle1[index1].vertex3Y - index;
                    meshGrid2.push_back(*grid);
                }
            }
            else if(temp == 2)
            {
                for(int index1 = 0; index1 < numOfTriangles; index1++)
                {
                    grid = new triangleType;
                    grid->vertex1X = triangle2[index1].vertex1X;
                    grid->vertex1Y = triangle2[index1].vertex1Y - index + 1;
                    grid->vertex2X = triangle2[index1].vertex2X;
                    grid->vertex2Y = triangle2[index1].vertex2Y - index + 1;
                    grid->vertex3X = triangle2[index1].vertex3X;
                    grid->vertex3Y = triangle2[index1].vertex3Y - index + 1;
                    meshGrid2.push_back(*grid);
                    temp = 0;
                }
            }
            meshGrid1.push_back(meshGrid2);
            meshGrid2.erase(meshGrid2.begin(), meshGrid2.end());
            temp++;
        }
        return;
    }
    void surgery()
    {
        for(itr1 = meshGrid1.begin(); itr1 !=  meshGrid1.end(); itr1++)
        {
            list<triangleType>& itr2Ptr = *itr1;
            for(itr2 = itr2Ptr.begin(); itr2 !=  itr2Ptr.end(); itr2++)
            {
                xItr = xList.begin();
                yItr = yList.begin();
               while(xItr != xList.end() || yItr != yList.end())
               {
                   if(*xItr >= 0 && *yItr >= 0)
                   {
                       if((itr2->vertex1X > *xItr && itr2->vertex1Y > *yItr)
                       || (itr2->vertex2X > *xItr && itr2->vertex2Y > *yItr)
                       || (itr2->vertex3X > *xItr && itr2->vertex3Y > *yItr))
                       {
                           meshGrid2.erase(itr2);
                       }
                   }
                   else if(*xItr >= 0 && *yItr <= 0)
                   {
                       if((itr2->vertex1X > *xItr && itr2->vertex1Y < *yItr)
                       || (itr2->vertex2X > *xItr && itr2->vertex2Y < *yItr)
                       || (itr2->vertex3X > *xItr && itr2->vertex3Y < *yItr))
                       {
                           meshGrid2.erase(itr2);
                       }
                   }
                   else if(*xItr <= 0 && *yItr <= 0)
                   {
                       if((itr2->vertex1X < *xItr && itr2->vertex1Y < *yItr)
                       || (itr2->vertex2X < *xItr && itr2->vertex2Y < *yItr)
                       || (itr2->vertex3X < *xItr && itr2->vertex3Y < *yItr))
                       {
                           meshGrid2.erase(itr2);
                       }
                   }
                   else if(*xItr <= 0 && *yItr >= 0)
                   {
                       if((itr2->vertex1X < *xItr && itr2->vertex1Y > *yItr)
                       || (itr2->vertex2X < *xItr && itr2->vertex2Y > *yItr)
                       || (itr2->vertex3X < *xItr && itr2->vertex3Y > *yItr))
                       {
                           meshGrid2.erase(itr2);
                       }
                   }
                    xItr++;
                    yItr++;
                   }
               }
            }
            return;
    }

    void wrap()
    {
            for(itr1 = meshGrid1.begin(); itr1 !=  meshGrid1.end(); itr1++)
            {
                list<triangleType>& itr2Ptr = *itr1;
                for(itr2 = itr2Ptr.begin(); itr2 !=  itr2Ptr.end(); itr2++)
                {
                    xItr = xList.begin();
                    yItr = yList.begin();
                    while(xItr != xList.end() || yItr != yList.end())
                    {
                        double dist1 = sqrt(pow((itr2->vertex1X - *xItr), 2) + (pow((itr2->vertex1Y - *yItr), 2)));

                        if(dist1 <= 0.35)
                        {
                            itr2->vertex1X = *xItr;
                            itr2->vertex1Y = *yItr;
                            break;
                        }
                        xItr++;
                        yItr++;
                    }
               }
            }
            for(itr1 = meshGrid1.begin(); itr1 !=  meshGrid1.end(); itr1++)
            {
                list<triangleType>& itr2Ptr = *itr1;
                for(itr2 = itr2Ptr.begin(); itr2 !=  itr2Ptr.end(); itr2++)
                {
                    xItr = xList.begin();
                    yItr = yList.begin();
                    while(xItr != xList.end() || yItr != yList.end())
                    {
                        double dist2 = sqrt(pow((itr2->vertex2X - *xItr), 2) + (pow((itr2->vertex2Y - *yItr), 2)));
                        if(dist2 <= 0.35)
                        {
                            itr2->vertex2X = *xItr;
                            itr2->vertex2Y = *yItr;

                            break;
                        }
                        xItr++;
                        yItr++;
                   }
               }
            }

            for(itr1 = meshGrid1.begin(); itr1 !=  meshGrid1.end(); itr1++)
            {
                list<triangleType>& itr2Ptr = *itr1;
                for(itr2 = itr2Ptr.begin(); itr2 !=  itr2Ptr.end(); itr2++)
                {
                    xItr = xList.begin();
                    yItr = yList.begin();
                    while(xItr != xList.end() || yItr != yList.end())
                    {
                        double dist3 = sqrt(pow((itr2->vertex3X - *xItr), 2) + (pow((itr2->vertex3Y - *yItr), 2)));
                        if(dist3 <= 0.35)
                        {
                            itr2->vertex3X = *xItr;
                            itr2->vertex3Y = *yItr;

                            break;
                        }

                        xItr++;
                        yItr++;
                    }
               }
            }

            return;
        }


    void draw()
    {
        ofstream outFile;
        outFile.open("data.txt");
        xItr = xList.begin();
        yItr = yList.begin();
        while(xItr != xList.end() || yItr != yList.end())
        {
            outFile << *xItr << "  " << *yItr << endl;
            xItr++;
            yItr++;
        }
        outFile.close();


        itr1 = meshGrid1.begin();
        ofstream outFile3;
        outFile3.open("meshData.txt");
        for(itr1 = meshGrid1.begin(); itr1 != meshGrid1.end(); itr1++)
        {
            list<triangleType>& itr2Ptr = *itr1;
            for(itr2 = itr2Ptr.begin(); itr2 != itr2Ptr.end(); itr2++)
            {
                outFile3 << itr2->vertex1X << "  " << itr2->vertex1Y << endl;
                outFile3 << itr2->vertex2X << "  " << itr2->vertex2Y << endl;
                outFile3 << itr2->vertex3X << "  " << itr2->vertex3Y << endl;
                outFile3 << itr2->vertex1X << "  " << itr2->vertex1Y << endl;
                outFile3 << itr2->vertex2X << "  " << itr2->vertex2Y << endl;
                outFile3 << itr2->vertex3X << "  " << itr2->vertex3Y << endl;
            }
            outFile3 << endl;
        }

        ofstream outFile2;
        outFile2.open("command.txt");
        outFile2 << "set xlabel \'x location\'" << endl;
        outFile2 << "set ylabel \'y location\'" << endl;
        outFile2 << "set xrange[-8:8]" << endl;
        outFile2 << "set yrange[-8:8]" << endl;
        outFile2 << "set terminal png" << endl;
        outFile2 << "set output \'figure.png\'" << endl;
        //outFile2 << "plot \"meshData.txt\"  u 1:2 w l notitle, \"data.txt\" u 1:2 with lines lc rgb \'black\' notitle" << endl;
        outFile2 << "plot \"meshData.txt\"  u 1:2 w l notitle" << endl;
        outFile2 << "pause -1" << endl;
        system("gnuplot command.txt");

        return;
    }
};

int main()
{
    circleType circle;

    circle.makeCircle();
    circle.makeMesh();
    circle.wrap();
    circle.surgery();
    circle.draw();

    return 0;
}
