#include "Face.hh"
#include <cmath>

Face::Face() {
    normal.x = 0.0;
    normal.y = 0.0;
    normal.z = 0.0;
}

/* 3 o 4 vertexs segons si és un triangle o un quadrat */
Face::Face(int i1, int i2, int i3, int i4)
{
    idxVertices.push_back(i1);
    idxVertices.push_back(i2);
    idxVertices.push_back(i3);
    if (i4!=-1) idxVertices.push_back(i4);

    normal.x = 0.0;
    normal.y = 0.0;
    normal.z = 0.0;
}

/* Calcula la normal de la cara */
void Face::calculateNormal(vector<Vertices> &v) {
    int j;
    normal.x=0.0;
    normal.y=0.0;
    normal.z=0.0;
    int n = idxVertices.size();
    for (int i=0; i<n; i++)
    {
        j = (i+1)%n;

        normal.x += ((v[idxVertices[i]].z+v[idxVertices[j]].z)*
                (v[idxVertices[i]].y-v[idxVertices[j]].y));
        normal.y += ((v[idxVertices[i]].x+v[idxVertices[j]].x)*
                (v[idxVertices[i]].z-v[idxVertices[j]].z));
        normal.z += ((v[idxVertices[i]].y+v[idxVertices[j]].y)*
                (v[idxVertices[i]].x-v[idxVertices[j]].x));
    }

    normal.x *= 0.5;
    normal.y *= 0.5;
    normal.z *= 0.5;
}



