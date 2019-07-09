//
// Created by soft01 on 19-7-9.
//

#include "conpress.h"

#include "unconpress.h"

int main()
{
    conpress conpress_("test.txt", "conpressed.dat");
    conpress_.fileConpress();

    cout<<"------------------unconpress----------------"<<endl;
    unconpress unconpress_("conpressed.dat", "unconpress.txt");
    return 0;
}

