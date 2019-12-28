#include <iostream>
#include <fstream>

using namespace std;

void swap(int *el1,int *el2){
    int temp=*el1;
    *el1=*el2;
    *el2=temp;
}

 int permute(int farray[], int array[], int pos,int length){
    if (pos==length){
        int min=0;
        int min1=0;
        for(int k=0;k<=length;k++){
            cout<<array[k]<<" ";
            } //k
            cout<<endl;
        for(int j=0; j<=length;j++){
            int d = length+1;
            if(j<length){
                int q = array[j];
                int c= array[j+1];
                int min2 = farray[q*d+c];
                min1 = min1 + min2; //weight added for subsequent edges
                }
            if(j == length){  //weight between last and first node
                int q = array[j];
                int c= array[0];
                min1 = min1 + farray[q*d+c];  //Total weight
                cout<<"weight of this cycle is:"<<min1<<endl;
                } //j=length
            } //j
        return min1;
    }else{
        int min=9999999;
        for (int i=pos;i<=length;i++){
            swap(array[pos],array[i]);
            int minv =  permute(farray,array,pos+1,length);
        //    cout<<"minv is"<<minv<<endl;
            if(minv<min || min==0){
                min = minv;
            }
            swap(array[pos], array[i]);
        }
        return min;
    }
 }


int main(int argc, char *argv[] )
{
    int v;
    int e;
    int a=0,b=0,c=0,d=0;
  //  cout<<"In main"<<endl;
    ifstream inData;
    ofstream outData;
   // inData.open("/Users/harshkour/Downloads/datafile.txt");
    inData.open(argv[1]);
    if (!inData) {
    cerr << "Error opening input file";
    exit(1);
    }
  //  outData.open("/Users/harshkour/Downloads/dataout.txt");
    outData.open(argv[2]);
    if (!outData) {
    cerr << "Error opening output file";
    exit(1);
    }
    inData>>d;
    cout<<"No of datasets"<<d<<endl;
    for(int k=0;k<d;k++){
            cout<<"k="<<k<<endl;
            inData>>v>>e;
            int test[v][v];
            cout<<"v="<<v<<"e="<<e<<endl;
            cout<<"printing entire array"<<endl;
                for (int x=0;x<v;++x){
                for(int y=0;y<v;++y){
                        test [x][y] = 0;
                    cout<<test [x][y]<<" ";
                } //y
                cout<<"\n";
            } //x
           for (int m =0; m<e;m++){
                cout<<"m="<<m<<endl;
                inData>>a>>b>>c;
                cout<<"a="<<a<<"b="<<b<<"c="<<c<<endl;
                test [a][b] = c;
                test[b][a] = c;
                cout<<"printing entire array"<<endl;
                for (int x=0;x<v;++x){
                for(int y=0;y<v;++y){
                    cout<<test [x][y]<<" ";
                } //s
                cout<<"\n";
            } //x
            }   //m
            int length = v;
            int array[length];
            cout<<"permute array initial";
            for (int i=0; i<length; i++){

                array[i] =i;
                cout<<array[i]<<" ";
            }
            cout<<endl;
            cout<<"length  is"<<length<<endl;
            int d=v*v;
            int farray[d];
            // convert 2d array to 1 d
            for(int p=0; p<v; p++){
                for(int q=0; q<v; q++){
                    farray[p*v+q] = test[p][q];
                    cout<< farray[p*v+q]<<" ";
                }
            }
            cout<<endl;
            int min = permute(farray,array, 0, length-1);
            cout<<"Final Minimum weight of this graph is "<<min<<endl;
            outData<<min<<endl;

    } //k
    inData.close();
    outData.close();
    return 0;
}










