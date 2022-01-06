#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
 int compara_int (const void * a, const void * b)
{
   //return ( *(int*)a - *(int*)b );
   if(*(int*)a< *(int*)b ) return -1;
   else if(*(int*)a== *(int*)b ) return 0;
   else return 1;
}
int compara_float (const void * a, const void * b)
{
	float dif=( *(float*)a - *(float*)b );
	if(dif>0) return 1;
	else if(dif==0) return 0;
		else return -1;
   
}
typedef int (*TIP_PF)(const void*, const void*);

void* cautareBinaraGenerala(const void* key,const void* vector,size_t fn,size_t elSize, TIP_PF compF){
	char* low=(char*)vector;
	char* high=(char*)vector+elSize*fn;
	char* Mid;
	while(low<=high)
	{
		int dif=(high-low)/elSize;
		Mid=low+dif/2*elSize;

		if(compF(key,Mid)==0) {
			return Mid;
		}
		else if (compF(key, Mid) < 0) {
			high = Mid - (1 * elSize);
		}
		else {
			low = Mid + (1 * elSize);
		}
	}
	return NULL;	
}
int main()
{
   int n;
  cout<<"Fie un tablou de numere intregi ordonat crescator: \n";
   cout<<"Introduceti numarul de elemente ale tabloului: ";
   cin>> n;
   int* vector=new int[n];
   int cheie;
   for( int i= 0 ; i < n; ++i ) {
     cout<<"vector["<<i<<"]=";
	 cin>>vector[i];
   }
   cout<<"Introduceti valoarea cautata: ";
   cin>>cheie;

   int* adrElementGasit=(int*)cautareBinaraGenerala(&cheie,vector,n,sizeof(int),compara_int);
   if(adrElementGasit==NULL) cout<<"Elementul nu e in vector\n";
   else cout<<"Pozitia elementului cautat : "<<adrElementGasit-vector<<endl;
   
   cout<<endl;
   delete[] vector;
  /* 
  cout<<"Fie un tablou de numere reale ordonat crescator: \n";
  cout<<"Introduceti numarul de elemente ale tabloului: ";
   cin>> n;
   float* vectorFloat=new float[n];
   float cheieFloat;
   for( int i= 0 ; i < n; ++i ) {
     cout<<"vector["<<i<<"]=";
	 cin>>vectorFloat[i];
   }

  cout<<"Introduceti valoarea cautata: ";
   cin>>cheieFloat;

   float* adrElementGasitFloat=(float*)cautareBinaraGenerala(&cheieFloat,vectorFloat,n,sizeof(int),compara_float);
   if(adrElementGasitFloat==NULL) cout<<"Elementul nu e in vector\n";
   else cout<<"Pozitia elementului cautat : "<<adrElementGasitFloat-vectorFloat<<endl;
   cout<<endl;
   delete[] vectorFloat;
  */
  _getch();
  return 0;
}