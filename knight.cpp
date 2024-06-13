
#include "knight.h"
#include <fstream>
#include <vector>

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;}
bool isMountainArray(int arr[], int size){
    int counttttt=0;
        if (size==1){return 1;}
    int max=arr[0];
    int pos=0;
        for (int i=0; i<size; i++){
        if (arr[i]>=max){max=arr[i];
                    pos=i;}}
        for (int i=0; i<pos; i++){
        if(arr[i]<arr[i+1]){
//        cout <<arr[i]<<" "<<arr[i+1]<<endl;
    counttttt=counttttt+1;}}
        for (int i=pos; i<size-1; i++){
        if(arr[i]>arr[i+1]){
//         cout <<arr[i]<<" "<<arr[i+1]<<endl;
    counttttt=counttttt+1;}}
//        cout <<"coutttt="<<counttttt<<endl;
        if (counttttt==size-1){return 1;}
    return 0;}
bool isPrime(int n){
    if (n <= 1)
        return 0;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return 0;
    return 1;}
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
int a[5]; 
int Koopa[30]; 
int got=0;
struct knight{
    int HP;
    int level;
    int remedy;
    int maidenkiss;
    int phoenixdown;
    int rescue;};
string string3;
typedef knight KN;
KN arr_kn[30];
for (int i=0; i<30; i++){
    Koopa[i]=-1;}
int checkk=0;
string p1, p2;
ifstream file1;
file1.open(file_input);
getline(file1, p1);
getline(file1, p2);
file1.close();
int lenn=p2.length();
int lennn=(lenn/2)+1;
//đọc file và input vào mảng a[] chứa thông tin hiệp sĩ
 ifstream file;  
    file.open(file_input);
file>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
for (int i=0; i<lennn; i++){
    file>>Koopa[i+1];}
file.close();
ifstream MushGhost;
MushGhost.open(file_input);
getline(MushGhost, string3);
getline(MushGhost, string3);
getline(MushGhost, string3);
MushGhost.close();
string string3mushghost=string3.substr(0, string3.find(","));
for (int i=0; i<string3.length(); i++){
    if(string3[i]==','){string3[i]='-';
    break;}}
string string3asclepiuspack=string3.substr(string3.find("-")+1, string3.find("t")-2);
string3asclepiuspack=string3asclepiuspack.substr(0, string3asclepiuspack.find(","));
string string3merlin=string3.substr(string3.find(",")+1);
arr_kn[0].HP=a[0];
arr_kn[0].level=a[1];
arr_kn[0].remedy=a[2];
arr_kn[0].maidenkiss=a[3];
arr_kn[0].phoenixdown=a[4];
arr_kn[0].rescue=-1;
int thuaShaman=0, thuaVajsh=0;
//xử lí mảng file mushghost
int khongcout=0;
int n2=0;
ifstream fileMushGhost;
fileMushGhost.open(string3mushghost);
fileMushGhost>>n2;
int arrFileMushGhost[n2];
char tempp;
for (int oi=0; oi<n2; oi++){
    arrFileMushGhost[oi]=0;}
for (int oi=0; oi<n2; oi++){
    fileMushGhost>>arrFileMushGhost[oi];
  fileMushGhost>>tempp;}
fileMushGhost.close();
//xử lí mảng file asclepiusPack
int r1, c1;
ifstream fileasclepiusPack;
fileasclepiusPack.open(string3asclepiuspack);
fileasclepiusPack>>r1>>c1;
int arrayAsclepiusPack[r1][c1]; //mảng 2 chiều chứa số nguyên
for (int i=0; i<r1; i++){
    for (int j=0; j<c1; j++){
        fileasclepiusPack>>arrayAsclepiusPack[i][j];}}
fileasclepiusPack.close();
//xử lí mảng merlin
int n9;
ifstream fileMerlin;
fileMerlin.open(string3merlin);
fileMerlin>>n9;
string stringMerlin[n9];
for (int i=0; i<n9; i++){
    fileMerlin>>stringMerlin[i];}
fileMerlin.close();





for (int i=1; i<30; i++){
    arr_kn[i].HP=arr_kn[i-1].HP;
    arr_kn[i].level=arr_kn[i-1].level;
    arr_kn[i].maidenkiss=arr_kn[i-1].maidenkiss;
    arr_kn[i].remedy=arr_kn[i-1].remedy;
    arr_kn[i].phoenixdown=arr_kn[i-1].phoenixdown;
    arr_kn[i].rescue=arr_kn[i-1].rescue;

if (khongcout==1){khongcout=0;}
if ((Koopa[i+1]==0)&&(Koopa[i+2]==-1)){
    khongcout=1;}
if ((arr_kn[i].HP>0)&&(Koopa[i+1]==-1)){
    arr_kn[i].rescue=1;}
if ((arr_kn[i].HP<=0)&&(Koopa[i+1]==-1)){
    arr_kn[i].rescue=0;}


if (((Koopa[i]==0)&&(Koopa[i+1]==-1))&&(Koopa[i-1]==7)&&(thuaVajsh!=0)){
    arr_kn[i].level=1;
    display(arr_kn[i].HP, arr_kn[i].level , arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
    continue;
}



/*
//test
//cout <<"string3asclepiuspack = "<<string3asclepiuspack<<endl;
//cout <<"string3mushghost = "<<string3mushghost<<endl;
//cout <<"string3merlin = "<<string3merlin<<endl;
//cout <<"n2 = "<<n2<<endl;
for (int i=0; i<20; i++){
   // cout<<"arrFileMushGhost["<<i<<"]="<<arrFileMushGhost[i]<<endl;
}
cout<<"====================================";
cout <<"i="<<i<<endl;
cout <<"Koopa["<<i<<"]="<<Koopa[i]<<endl;
cout<<"thuaShaman="<<thuaShaman<<endl;
cout<<"thuaVajsh="<<thuaVajsh<<endl;
*/

if (Koopa[i]==-1){return;}
//Arthur thắng tất cả
int Arthur=0;
if (arr_kn[0].HP==999){Arthur=1;}
if (Arthur==1){
    if((Koopa[i]==1)||(Koopa[i]==2)||(Koopa[i]==3)||(Koopa[i]==4)||(Koopa[i]==5)){
        arr_kn[i].level=arr_kn[i-1].level+1;
        if (arr_kn[i].level>10){arr_kn[i].level=10;}
        if(khongcout!=1){
display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
        continue;}}
    else if ((Koopa[i]==6)||(Koopa[i]==7)){
        arr_kn[i].level=arr_kn[i-1].level+2;
        if (arr_kn[i].level>10){arr_kn[i].level=10;}
        if(khongcout!=1){
display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
        continue;}}
    else if (Koopa[i]==99){
        arr_kn[i].level=10;
        if(khongcout!=1){
display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
        continue;}}
}
//Lancetot
int Lancetot=0;
if (isPrime(arr_kn[0].HP)){Lancetot=1;}
if(Lancetot==1){
    if((Koopa[i]==1)||(Koopa[i]==2)||(Koopa[i]==3)||(Koopa[i]==4)||(Koopa[i]==5)){
        arr_kn[i].level=arr_kn[i-1].level+1;
        if (arr_kn[i].level>10){arr_kn[i].level=10;}
        if(khongcout!=1){
display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
        continue;}
    }
    else if ((Koopa[i]==6)||(Koopa[i]==7)){
        arr_kn[i].level=arr_kn[i-1].level+2;
        if (arr_kn[i].level>10){arr_kn[i].level=10;}
        if(khongcout!=1){
display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
        continue;}
    }
}
int b=(i)%10;
int levelO=(i)>6?(b>5?b:5):b;
 //Khai báo baseDamage + dame;
        float baseDamage;
    if(Koopa[i]==1){baseDamage=1;}
    if (Koopa[i]==2){baseDamage=1.5;}
    if (Koopa[i]==3){baseDamage=4.5;}
    if (Koopa[i]==4){baseDamage=7.5;}
    if (Koopa[i]==5){baseDamage=9.5;}
        float damage=baseDamage*levelO*10;
int n1=((arr_kn[i-1].level+arr_kn[i-1].phoenixdown)%5+1)*3;
int s1=0;
if (Koopa[i]==-1){break;}
for (int i=1; i<=n1; i++){s1=s1+99-2*(i-1);}
//tìm vị trí phần tử lớn và nhỏ nhất trong mảng arrFileMushGhost (maxi, mini)
int maxi=0;
int mini=0;
int max=arrFileMushGhost[0];
int min=arrFileMushGhost[0];
for (int i=1; i<n2; i++){
if (arrFileMushGhost[i]>=max){
    max=arrFileMushGhost[i];
    maxi=i;}
if (arrFileMushGhost[i]<=min){
    min=arrFileMushGhost[i];
    mini=i;}
}
//tìm mtx mti
for (int i=0; i<n2; i++){
//    cout<<"arrFileMushGhost[i]="<<arrFileMushGhost[i]<<endl;
}
int mtx;
int mti; 
if (isMountainArray(arrFileMushGhost, n2)){
   // cout <<"eys";
mtx=arrFileMushGhost[0];
mti=0;
for (int iu=1; iu<n2; iu++){
    if (arrFileMushGhost[iu]>=mtx){
        mtx=arrFileMushGhost[iu];           //cập nhật giá trị mtx = max đỉnh núi
        mti=iu;                             //vị trí của mtx là mti=i
}}}
else {mtx=-2; mti=-3;}
if (n2==1){
    mtx=arrFileMushGhost[0];
    mti=0;}
//tìm maxi2 và mini2
int arrFileMushGhost2[n2]; //copy arr
for (int i=0; i<n2; i++){
arrFileMushGhost2[i]=arrFileMushGhost[i];
}
for (int i=0; i<n2; i++){
   if (arrFileMushGhost2[i]<0){
arrFileMushGhost2[i]=-arrFileMushGhost2[i];
}
arrFileMushGhost2[i]=(17*arrFileMushGhost2[i]+9)%257;}
int max2=arrFileMushGhost2[n2-1];
int min2=arrFileMushGhost2[n2-1];
int maxi2=0;
int mini2=0;
for (int i=n2-1; i>=0; i--){
    if (max2<=arrFileMushGhost2[i]){
        max2=arrFileMushGhost2[i];
            maxi2=i;
    }
    if (min2>=arrFileMushGhost2[i]){
        min2=arrFileMushGhost2[i];
        mini2=i;
    }}
//tìm max2_3x và max2_3i
int max2_3x=-10000;
int max2_3i=arrFileMushGhost2[0];
int maxcode4=arrFileMushGhost2[0];
for (int i=0; i<=2; i++){
if (maxcode4<arrFileMushGhost2[i]){
    maxcode4=arrFileMushGhost2[i];}
}
for (int i=0; i<=2; i++){
    if(max2_3x<arrFileMushGhost2[i]){
        if(arrFileMushGhost2[i]!=maxcode4){
            max2_3x=arrFileMushGhost2[i];
            max2_3i=i;
        }
    }
}

for (int i=0; i<n2; i++){
    if(arrFileMushGhost2[i]==max2_3x){  //trường hợp có 2 số đầu giống nhau => tìm số đầu tiên
        max2_3i=i;
        break;
    }
}

if ((arrFileMushGhost2[0]==arrFileMushGhost2[1])&&(arrFileMushGhost2[1]==arrFileMushGhost2[2])||(n2==1)||(n2==0)){
    max2_3x=-5;
    max2_3i=-7;
}
if (thuaShaman>0){thuaShaman=thuaShaman+1;}
//Xử lí 6 7
//========================
if (thuaVajsh>0){thuaVajsh=thuaVajsh+1;}
if (thuaVajsh==5){
    thuaVajsh=0;
    arr_kn[i].level=arr_kn[i-4].level;
    if (arr_kn[i].level>10){arr_kn[i].level=10;}}

if ((thuaShaman!=0)&&(thuaShaman!=4)&&(Koopa[i+1]!=-1)){
    if (thuaShaman==4){
        thuaShaman=0; 
        if(arr_kn[i].HP>0){arr_kn[i].HP=(arr_kn[i].HP)*5;  }  
        if(arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;}}         
    if((Koopa[i]==6)||(Koopa[i]==7)){
        if(khongcout!=1){
            display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
                continue;}} //bỏ qua nếu vẫn còn là tí hon hoặc ếch
}
//nếu gặp code = 0; rescue = 1; display, return
    if (Koopa[i]==0){
    if (thuaShaman==4){
thuaShaman=0; 
if(arr_kn[i].HP>0){
if(arr_kn[i].HP>0){arr_kn[i].HP=(arr_kn[i].HP)*5;  }  
if(arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;}
                  }
                            }
if (arr_kn[i].HP>0){arr_kn[i].rescue=1;}
if (arr_kn[i].HP<=0){arr_kn[i].rescue=0;}
display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
        return;
        break;}
//=======================================Gặp code từ 1=>5
if ((0<Koopa[i])&&(Koopa[i]<6)){
    
    if((arr_kn[i-1].level>levelO)&&(arr_kn[i-1].level<10)){arr_kn[i].level=arr_kn[i-1].level+1;
        }     
    else if (arr_kn[i-1].level==levelO){arr_kn[i].level=arr_kn[i-1].level;
        }                     //nếu hòa
    else if (arr_kn[i-1].level<levelO){                                                       //nếu thua
        arr_kn[i].HP=arr_kn[i-1].HP-damage;                        //máu của hiệp sĩ ở mảng i bị trừ sau sự kiện thứ i
        }}
//========================================
//nếu gặp Shaman code = 6
if ((Koopa[i]==6)&&(thuaShaman==0)){
    //nếu thắng, level + 2
    if((arr_kn[i-1].level>levelO)){arr_kn[i].level=arr_kn[i-1].level+2;
    if(arr_kn[i].level>10){arr_kn[i].level=10;}} 
    //nếu hòa, level = level    
    else if (arr_kn[i-1].level==levelO){arr_kn[i].level=arr_kn[i-1].level;} 
    //nếu thua
if (arr_kn[i-1].level<levelO){
        if (arr_kn[i-1].remedy>=1){arr_kn[i].remedy=arr_kn[i-1].remedy-1;
        } //nếu thua Shaman và có remedy
        else if(arr_kn[i-1].remedy<1){
            if((thuaShaman==0)&&(thuaVajsh==0)){
            if(arr_kn[i-1].HP>=5){arr_kn[i].HP=(arr_kn[i-1].HP)/5;}                                                            //nếu thua và không có remedy
            if ((arr_kn[i-1].HP>0)&&(arr_kn[i-1].HP<5)){arr_kn[i].HP=1;}
                thuaShaman=1;}

        }
    }
}
//===================================================
//gặp Siren Vajsh (code=7);
else if ((Koopa[i]==7)&&(thuaVajsh==0)){  
//nếu thắng, level + 2
    if((arr_kn[i-1].level>levelO)){arr_kn[i].level=arr_kn[i-1].level+2;
    if(arr_kn[i].level>10){arr_kn[i].level=10;}} 
    //nếu hòa, level = level    
    else if (arr_kn[i-1].level==levelO){arr_kn[i].level=arr_kn[i-1].level;} 
    //nếu thua
    else if (arr_kn[i-1].level<levelO){
            if(arr_kn[i-1].maidenkiss>=1){arr_kn[i].maidenkiss=arr_kn[i-1].maidenkiss-1; //biến thành ếch và có maidenkiss
} 
            else if(arr_kn[i-1].maidenkiss<1){
                      if((thuaShaman==0)&&(thuaVajsh==0)){      
thuaVajsh=1;}                        }
}
}
//===================================================
//nhặt được MushMario
if (Koopa[i]==11){
arr_kn[i].HP=arr_kn[i-1].HP+(s1%100);
for (int k=1; k<1000; k++){
    if (isPrime(arr_kn[i].HP+k)){
        arr_kn[i].HP=arr_kn[i].HP+k;
        break;}
                            }
if (arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;}
}
//===================================================
//nhặt được Fibonacci MushFibo (code=12)
if (Koopa[i]==12){
int fibonacci [50];  //khai báo mảng chứa số fibonacci
fibonacci[0]=0;
fibonacci[1]=1;
fibonacci[2]=1;
for (int o=3; o<50; o++){                
fibonacci[o]=fibonacci[o-1]+fibonacci[o-2];}
for (int l=0; l<50; l++){
    if (fibonacci[l]>=arr_kn[i].HP){
        arr_kn[i].HP=fibonacci[l-1];
        break;
    }
}}
//====================Gặp Broser (99)
if (Koopa[i]==99){
    if ((Arthur==1)||((Lancetot==1)&&(arr_kn[i-1].level>=8))||(arr_kn[i-1].level==10)){
        arr_kn[i].level=10;
    }
    else {//Nếu thua Brơser, cout thông tin trước đó và rescue =0; break;
    if (thuaShaman==4){
thuaShaman=0; 
if(arr_kn[i].HP>0){arr_kn[i].HP=(arr_kn[i].HP)*5;  }
if(arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;
}
}
if (khongcout!=1){
    display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
        break;}
}}
//============================================================
//nhặt MushGhost (code=13)
char array[100];
string s2;
stringstream ss2;
ss2<<Koopa[i];
ss2>>s2;
for (int i=0; i<s2.length(); i++){
array[i]=s2[i];}
if ((array[0]=='1')&&(array[1]=='3'))//nếu gặp mã là 13, ms bắt đầu từ arr[2]
{
int hpp=arr_kn[i-1].HP;
int phoenixxx=arr_kn[i-1].phoenixdown;
for (int j=2; j<s2.length(); j++){
        if (array[j]=='1'){//gặp nấm loại 1
              hpp=hpp-(maxi+mini);
//cout <<"maxi="<<maxi<<endl<<"mini="<<mini<<endl;
        }
        if (array[j]=='2'){//gặp nấm loại 2
             hpp=hpp-(mtx+mti);
//cout <<"mtx="<<mtx<<endl<<"mti="<<mti<<endl;
        }
        if (array[j]=='3'){//gặp nấm loại 3
            hpp=hpp-(maxi2+mini2);
//cout <<"maxi2="<<maxi2<<endl<<"mini2="<<mini2<<endl;
        }
        if (array[j]=='4'){//gặp nấm loại 4
            hpp=hpp-(max2_3x+max2_3i);
//cout <<"max2_3x="<<max2_3x<<endl<<"max2_3i="<<max2_3i<<endl;
        }
    if (hpp>arr_kn[0].HP){hpp=arr_kn[0].HP;}
    if ((hpp<=0)&&(phoenixxx>=1)){
        hpp=arr_kn[0].HP;
phoenixxx=phoenixxx-1;}
    else if (hpp>0){phoenixxx=phoenixxx;}
    else if (hpp<=0&&phoenixxx<1) {arr_kn[i].rescue=0;}
    arr_kn[i].phoenixdown=phoenixxx;
    arr_kn[i].HP=hpp;
    if(arr_kn[i].HP<0){break;}
}
}
//===============================================================
//Gặp code 15 16 17
if (Koopa[i]==15||Koopa[i]==16||Koopa[i]==17){
if (Koopa[i]==15){
    arr_kn[i].remedy=arr_kn[i-1].remedy+1;
    if (arr_kn[i].remedy>99){arr_kn[i].remedy=99;}}
else if (Koopa[i]==16){
    arr_kn[i].maidenkiss=arr_kn[i-1].maidenkiss+1;
    if (arr_kn[i].maidenkiss>99){arr_kn[i].maidenkiss=99;}}
else if (Koopa[i]==17){
    arr_kn[i].phoenixdown=arr_kn[i-1].phoenixdown+1;
    if (arr_kn[i].phoenixdown>99){arr_kn[i].phoenixdown=99;}}
if ((thuaShaman!=0)&&(arr_kn[i].remedy>=1)){thuaShaman=0; arr_kn[i].remedy=arr_kn[i].remedy-1;
arr_kn[i].HP=arr_kn[i].HP*5;}
if ((thuaVajsh!=0)&&(arr_kn[i].maidenkiss>=1)){thuaVajsh=0; arr_kn[i].maidenkiss=arr_kn[i].maidenkiss-1;
for (int x=0; x<5; x++){if(arr_kn[i-x].level!=1){arr_kn[i].level=arr_kn[i-x].level; break;}}

}
}
//==========================================================
//Gặp code 19 
if (Koopa[i]==19){
//nếu trước đó có sự kiện 19 => bỏ qua.
int check=i;
int countx=0;
for (int j=0; j<check; j++){
    if (Koopa[j]==19){
        countx=countx+1;}}
if (countx>0){
display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
    continue;}
int count19=0;
arr_kn[i].remedy=arr_kn[i-1].remedy;
arr_kn[i].maidenkiss=arr_kn[i-1].maidenkiss;
arr_kn[i].phoenixdown=arr_kn[i-1].phoenixdown;
for (int m=0; m<r1; m++){
    count19=0; //giải phóng biến count19;
    for (int n=0; n<c1; n++){
        if (arrayAsclepiusPack[m][n]==16){
arr_kn[i].remedy=arr_kn[i].remedy+1;
if(arr_kn[i].remedy>99){arr_kn[i].remedy=99;}      
            count19=count19+1;
        }
        if (arrayAsclepiusPack[m][n]==17){
arr_kn[i].maidenkiss=arr_kn[i].maidenkiss+1;
if(arr_kn[i].maidenkiss>99){arr_kn[i].maidenkiss=99;}  
            count19=count19+1;
        }
        if (arrayAsclepiusPack[m][n]==18){
arr_kn[i].phoenixdown=arr_kn[i].phoenixdown+1;
if(arr_kn[i].phoenixdown>99){arr_kn[i].phoenixdown=99;}  
            count19=count19+1;
        }
        if (count19==3){break;}
    }}
if (((Koopa[i-1]==7)&&(arr_kn[i-2].maidenkiss<1)||(Koopa[i-2]==7)&&(arr_kn[i-3].maidenkiss<1)&&(arr_kn[i-2].maidenkiss<1)||(Koopa[i-3]==7)&&(arr_kn[i-4].maidenkiss<1)&&(arr_kn[i-3].maidenkiss<1)&&(arr_kn[i-2].maidenkiss<1))&&(arr_kn[i].maidenkiss>=1)){
    for (int j=0; j<3; j++){
        if (arr_kn[i-j].level>1){arr_kn[i]=arr_kn[i-j];}
    }
}
if ((thuaVajsh!=0)&&(thuaVajsh!=4)&&(Koopa[i+1]!=-1)){
        if((Koopa[i]==6)||(Koopa[i]==7)){
        if (thuaShaman==4){
thuaShaman=0; 
if(arr_kn[i].HP>0){arr_kn[i].HP=(arr_kn[i].HP)*5;  }
        if(arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;
}
}
        if(khongcout!=1){
display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
        continue;}} //bỏ qua nếu vẫn còn là tí hon hoặc ếch
}

if (thuaShaman==4){
thuaShaman=0; 
if(arr_kn[i].HP>0){arr_kn[i].HP=(arr_kn[i].HP)*5;  }
if(arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;
}
}
        if(khongcout!=1){
display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
        continue;}
}
//gặp Merlin (18)

        if (Koopa[i]==18){
            checkk=checkk+1;
        }
    
if (Koopa[i]==18&&(checkk!=1)&&(khongcout!=1)){display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);continue;}
else if ((Koopa[i]==18)&&(checkk==1)){
   

//cout<<"check="<<checkk<<endl;
int hppp=arr_kn[i-1].HP;
for (int m=0; m<n9; m++){
    int cao=0;
    for (int o=0; o<stringMerlin[m].length(); o++){
        if((stringMerlin[m][o]=='m')||(stringMerlin[m][o]=='M')){cao=1;
        break;}}   
if (cao==1){
    for (int o=0; o<stringMerlin[m].length(); o++){
        if((stringMerlin[m][o]=='E')||(stringMerlin[m][o]=='e')){cao=2;
        break;}}}
if (cao==2){
    for (int o=0; o<stringMerlin[m].length(); o++){
        if((stringMerlin[m][o]=='R')||(stringMerlin[m][o]=='r')){cao=3;
        break;}}}
if (cao==3){
    for (int o=0; o<stringMerlin[m].length(); o++){
        if((stringMerlin[m][o]=='L')||(stringMerlin[m][o]=='l')){cao=4;
        break;}}}
if (cao==4){
    for (int o=0; o<stringMerlin[m].length(); o++){
        if((stringMerlin[m][o]=='I')||(stringMerlin[m][o]=='i')){cao=5;
        break;}}}
if (cao==5){
    for (int o=0; o<stringMerlin[m].length(); o++){
        if((stringMerlin[m][o]=='n')||(stringMerlin[m][o]=='N')){cao=6;
        break;}}}
//cout<<"cao="<<cao<<endl;
if(cao==6){hppp=hppp+2;}
for (int o=0; o<stringMerlin[m].length(); o++){
if ((stringMerlin[m][o]=='M')&&(stringMerlin[m][o+1]=='e')&&(stringMerlin[m][o+2]=='r')&&(stringMerlin[m][o+3]=='l')&&(stringMerlin[m][o+4]=='i')&&(stringMerlin[m][o+5]=='n')){
    hppp=hppp+1;
    break;
}
if ((stringMerlin[m][o+0]=='m')&&(stringMerlin[m][o+1]=='e')&&(stringMerlin[m][o+2]=='r')&&(stringMerlin[m][o+3]=='l')&&(stringMerlin[m][o+4]=='i')&&(stringMerlin[m][o+5]=='n')){
    hppp=hppp+1;
    break;
}      
}   
        if(hppp>arr_kn[0].HP){hppp=arr_kn[0].HP;}
    arr_kn[i].HP=hppp;
}



if (thuaShaman==4){
thuaShaman=0; 
if(arr_kn[i].HP>0){arr_kn[i].HP=(arr_kn[i].HP)*5;  } 
if(arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;
}
}
        if(khongcout!=1){
display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
        continue;}
if(arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;}
if (thuaShaman==4){
thuaShaman=0; 
if(arr_kn[i].HP>0){arr_kn[i].HP=(arr_kn[i].HP)*5;  }  
if(arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;
}}
        if(khongcout!=1){
display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
        continue;}
}


//===========================================================
if (Koopa[i+1]==-1){if(arr_kn[i].HP>0){arr_kn[i].rescue=1;
if (thuaShaman==4){
thuaShaman=0; 
if(arr_kn[i].HP>0){arr_kn[i].HP=(arr_kn[i].HP)*5;  }
if(arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;
}
}
if (khongcout!=1){
    display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
        break;}
}
};
if ((arr_kn[i].HP<1)&&(arr_kn[i].phoenixdown<1)){
    arr_kn[i].rescue=0;
 if (thuaShaman==4){
thuaShaman=0; 
if(arr_kn[i].HP>0){arr_kn[i].HP=(arr_kn[i].HP)*5;  }  
if(arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;
}}
if (khongcout!=1){ 
    display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
        break;}
       }
else if ((arr_kn[i].HP>0)&&(Koopa[i+1]!=-1))
{arr_kn[i].rescue=-1;
if (thuaShaman==4){
thuaShaman=0; 
if(arr_kn[i].HP>0){arr_kn[i].HP=(arr_kn[i].HP)*5;  }  
if(arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;
}}
        if(khongcout!=1){
display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
        continue;}
        }
if ((arr_kn[i].HP<=0)&&(arr_kn[i-1].phoenixdown>=1)){
    if (Koopa[i+1]==0){
    arr_kn[i].rescue=1;
arr_kn[i].HP=arr_kn[0].HP;
arr_kn[i].phoenixdown=arr_kn[i-1].phoenixdown-1;
if (thuaShaman==4){
thuaShaman=0; 
if(arr_kn[i].HP>0){arr_kn[i].HP=(arr_kn[i].HP)*5;  }   
    if(arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;
}}
if (khongcout!=1){
    display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
        break;}}
else {
arr_kn[i].HP=arr_kn[0].HP;
arr_kn[i].phoenixdown=arr_kn[i-1].phoenixdown-1;
if (thuaShaman==4){
thuaShaman=0; 
if(arr_kn[i].HP>0){arr_kn[i].HP=(arr_kn[i].HP)*5;  }  
if(arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;
}}
display(arr_kn[i].HP, arr_kn[i].level, arr_kn[i].remedy, arr_kn[i].maidenkiss, arr_kn[i].phoenixdown, arr_kn[i].rescue);
    }
}
}
}
