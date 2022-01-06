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
void* cautareSecventiala(const void* adrCheie,const void* adrBaza, size_t nrel, size_t dimElement, TIP_PF functieComparare){
	for(unsigned i=0;i<nrel;++i){
		char* adrElement=(char*)adrBaza+dimElement*i; 
		//adresa celui de al i-lea element
		if(functieComparare(adrCheie,adrElement)==0) 
			return adrElement;//exista si revin in main
	}
	return NULL;//nu exista
}
int main()
{
   int n;
  cout<<"Fie un tablou de numere intregi: \n";
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

   int* adrElementGasit=(int*)cautareSecventiala(&cheie,vector,n,sizeof(int),compara_int);
   if(adrElementGasit==NULL) cout<<"Elementul nu e in vector\n";
   else cout<<"Pozitia elementului cautat : "<<adrElementGasit-vector<<endl;
   
   cout<<endl;
   delete[] vector;
  /* 
  cout<<"Fie un tablou de numere reale: \n";
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

   float* adrElementGasitFloat=(float*)cautareSecventiala(&cheieFloat,vectorFloat,n,sizeof(float),compara_float);
   if(adrElementGasitFloat==NULL) cout<<"Elementul nu e in vector\n";
   else cout<<"Pozitia elementului cautat : "<<adrElementGasitFloat-vectorFloat<<endl;
   cout<<endl;
   delete[] vectorFloat;
  */
  getch();
  return 0;
}