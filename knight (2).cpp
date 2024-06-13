
#include "knight.h"
#include <fstream>
#include <vector>
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
}

bool isMountainArray(int arr[], int size)
{
int count=0;
    for (int i=0; i<size-1; i++){
        if (arr[i]<arr[i+1]){
            count=count+1;
        }
    if (count==size-1){return 1;}
    }    
int count1=0;
    for (int i=0; i<size-1; i++){
        if (arr[i]>arr[i+1]){
            count=count+1;
        }
    if (count==size-1){return 1;}
    }    


    int flag = 0, i = 0;
    for (i = 1; i < size; i++)
        if (arr[i] <= arr[i - 1])
            break;
 
    if (i == size || i == 1)
        return false;
 
    for (; i < size; i++)
        if (arr[i] >= arr[i - 1])
            break;
    return i == size;
}





bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return 0;
 
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return 0;
 
    return 1;
}





void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
int a[5];   //mảng a chứa 5 phần tử đầu (thông tin của hiệp sĩ)
int Koopa[15]; //mảng Koopa chứa hành trình đến Koopa
struct knight{
    int HP;
    int level;
    int remedy;
    int maidenkiss;
    int phoenixdown;
    int rescue;
};
string string1, string2, string3;
typedef knight KN;
KN arr_kn[10];   //Mảng có kiểu kn
//mảng arr_kn[0] tương ứng với trạng thái đầu tiên của hiệp sĩ
//đọc thông tin dòng 1 và truyền vào biến arr_kn[0]
for (int i=0; i<20; i++){
    Koopa[i]=-1;
}



//đọc file và input vào mảng a[] chứa thông tin hiệp sĩ
 ifstream file;  
    file.open(file_input);
    
file>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
for (int i=0; i<15; i++){
    file>>Koopa[i+1];
}
file.close();

ifstream MushGhost;
MushGhost.open(file_input);
getline(MushGhost, string1);
getline(MushGhost, string2);
getline(MushGhost, string3);
MushGhost.close();








string string3mushghost=string3.substr(0, string3.find(","));
for (int i=0; i<string3.length(); i++){
    if(string3[i]==','){string3[i]=' ';
    break;}
}

string string3asclepiuspack=string3.substr(string3.find(" ")+1, string3.find(",")-1);
string string3merlin=string3.substr(string3.find(",")+1);

arr_kn[0].HP=a[0];
arr_kn[0].level=a[1];
arr_kn[0].remedy=a[2];
arr_kn[0].maidenkiss=a[3];
arr_kn[0].phoenixdown=a[4];
arr_kn[0].rescue=-1;


/*
cout <<endl<<"string1="<<string1;
cout <<endl<<"string2="<<string2;
cout <<endl<<"string3="<<string3;
cout <<endl<<"string3mushghost="<<string3mushghost<<endl;
cout <<endl<<"string3asclepiuspack="<<string3asclepiuspack<<endl;
cout <<endl<<"string3merlinpack="<<string3merlin<<endl;
*/




 //TEST: cout Koopa[i];
for (int i=0; i<20; i++){
   // cout <<endl<<"Koopa["<<i<<"]="<<Koopa[i];
}


for (int i=1; i<20; i++){
    arr_kn[i].HP=arr_kn[i-1].HP;
    arr_kn[i].level=arr_kn[i-1].level;
    arr_kn[i].maidenkiss=arr_kn[i-1].maidenkiss;
    arr_kn[i].remedy=arr_kn[i-1].remedy;
    arr_kn[i].phoenixdown=arr_kn[i-1].phoenixdown;
    arr_kn[i].rescue=arr_kn[i-1].rescue;

int b=(i)%10;
int levelO=(i)>6?(b<5?b:5):b;
 //Khai báo baseDamage + dame;
        float baseDamage;
    if(Koopa[i]==1){baseDamage=1;}
    else if (Koopa[i]==2){baseDamage=1.5;}
    else if (Koopa[i]==3){baseDamage=4.5;}
    else if (Koopa[i]==4){baseDamage=7.5;}
    else if (Koopa[i]==5){baseDamage=9.5;}
        float damage=baseDamage*levelO*10;
int n1=((arr_kn[i-1].level+arr_kn[i-1].phoenixdown)%5+1)*3;
int s1=0;





for (int i=1; i<=n1; i++){
  s1=s1+99-2*(i-1);
}

if ((Koopa[i-4]==6)&&(arr_kn[i-1].phoenixdown==0)&&(arr_kn[i-2].phoenixdown==0)&&(arr_kn[i-3].phoenixdown==0)){
    arr_kn[i].HP=arr_kn[i-1].HP*5;
}
//nếu 3 sự kiện trước đó gặp Shaman, và không có phoenixdown
//xử lí




//Arthur thắng tất cả
int Arthur=0;
if (arr_kn[0].HP==999){Arthur=1;}
if (Arthur==1){
    if((Koopa[i]==1)||(Koopa[i]==2)||(Koopa[i]==3)||(Koopa[i]==4)||(Koopa[i]==5)){
        arr_kn[i].level=arr_kn[i-1].level+1;
        if (arr_kn[i].HP>10){arr_kn[i].HP=10;}
        continue;
    }
    else if ((Koopa[i]==6)||(Koopa[i]==7)){
        arr_kn[i].level=arr_kn[i-1].level+2;
        if (arr_kn[i].level>10){arr_kn[i].level=10;}
        continue;
    }
    else if (Koopa[i]==99){
        arr_kn[i].level=10;
        continue;
    }
}
//Lancetot
int Lancetot=0;
if (isPrime(arr_kn[0].HP)){Lancetot=1;}
//nếu Lancetot gặp code từ 1->5, level + 1; continue
if(Lancetot==1){
    if((Koopa[i]==1)||(Koopa[i]==2)||(Koopa[i]==3)||(Koopa[i]==4)||(Koopa[i]==5)){
        arr_kn[i].level=arr_kn[i-1].level+1;
        if (arr_kn[i].HP>10){arr_kn[i].HP=10;}
        continue;
    }
    else if ((Koopa[i]==6)||(Koopa[i]==7)){
        arr_kn[i].level=arr_kn[i-1].level+2;
        if (arr_kn[i].level>10){arr_kn[i].level=10;}
        continue;
    }
}




//xử lí mảng file mushghost
int n2;
int arrFileMushGhost[n2];

ifstream fileMushGhost;
fileMushGhost.open(string3mushghost);
fileMushGhost>>n2;
char tempp;
string ss, sss; //string sss dùng để chứa dòng 2 file mushghost
//getline(fileMushGhost, ss);
//getline(fileMushGhost, sss);
for (int i=0; i<n2; i++){
    fileMushGhost>>arrFileMushGhost[i];
    fileMushGhost>>tempp;
}
fileMushGhost.close();
//cout <<endl<<"n2="<<n2;


//xử lí mảng file asclepiusPack
int r1, c1;
ifstream fileasclepiusPack;
fileasclepiusPack.open(string3asclepiuspack);
fileasclepiusPack>>r1>>c1;
//cout <<endl<<"r1="<<r1<<endl<<"c1="<<c1;
int arrayAsclepiusPack[r1][c1]; //mảng 2 chiều chứa số nguyên
for (int i=0; i<r1; i++){
    for (int j=0; j<c1; j++){
        fileasclepiusPack>>arrayAsclepiusPack[i][j];
    }
}
fileasclepiusPack.close();
/*
for (int i=0; i<r1; i++){
    for (int j=0; j<c1; j++){
        cout <<"a["<<i<<"]["<<j<<"]="<<arrayAsclepiusPack[i][j]<<" ";
    }
    cout <<endl;
}
*/



//xử lí mảng merlin
int n9;
ifstream fileMerlin;
fileMerlin.open(string3merlin);
fileMerlin>>n9;
string stringMerlin[n9];
for (int i=0; i<n9; i++){
    fileMerlin>>stringMerlin[i];
}

fileMerlin.close();

for (int i=0; i<n9; i++){
  //  cout<<endl<<stringMerlin[i];
}








for (int i=0; i<n2; i++){
   // cout<<"arrFileMushGhost["<<i<<"]="<<arrFileMushGhost[i]<<endl;
}


//tìm vị trí phần tử lớn và nhỏ nhất trong mảng arrFileMushGhost (maxi, mini)
int maxi=0;
int mini=0;
int max=arrFileMushGhost[0];
int min=arrFileMushGhost[0];
for (int i=1; i<n2; i++){
if (arrFileMushGhost[i]>=max){
    max=arrFileMushGhost[i];
    maxi=i;
  //  cout<<endl<<"max="<<max<<endl<<"maxi="<<maxi;
}
if (arrFileMushGhost[i]<=min){
    min=arrFileMushGhost[i];
    mini=i;
 //   cout<<endl<<"min="<<min<<endl<<"mini="<<mini;
}
}
//tìm mtx mti
int mtx=-2;
int mti=-3;
if (isMountainArray(arrFileMushGhost, n2)){
mtx=arrFileMushGhost[0];
for (int i=0; i<n2; i++){
    if (arrFileMushGhost[i]>=mtx){
        mtx=arrFileMushGhost[i];           //cập nhật giá trị mtx = max đỉnh núi
        mti=i;                             //vị trí của mtx là mti=i
    }
}
}
//cout <<endl<<"mtx="<<mtx<<endl<<"mti="<<mti;

//tìm maxi2 và mini2
int arrFileMushGhost2[n2]; //copy arr
for (int i=0; i<n2; i++){
arrFileMushGhost2[i]=arrFileMushGhost[i];
}
for (int i=0; i<n2; i++){
   if (arrFileMushGhost2[i]<0){
    arrFileMushGhost2[i]=-arrFileMushGhost2[i];
   }
   arrFileMushGhost2[i]=(17*arrFileMushGhost2[i]+9)%257;
}
//cout <<"--------------";
for (int i=0; i<n2; i++){
   // cout <<"arrFileMushGhost2["<<i<<"]="<<arrFileMushGhost2[i]<<endl;
}
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
    }
}
//cout <<"maxi2="<<maxi2<<endl<<"mini2="<<mini2;



//tìm max2_3x và max2_3i
int max2_3x=-10000;
int max2_3i=arrFileMushGhost2[0];
int maxcode4=arrFileMushGhost2[0];
for (int i=0; i<=2; i++){
if (maxcode4<arrFileMushGhost2[i]){
    maxcode4=arrFileMushGhost2[i];
}
}
//cout <<endl<<maxcode4<<endl; đúng
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

if ((arrFileMushGhost2[0]==arrFileMushGhost2[1])&&(arrFileMushGhost2[1]==arrFileMushGhost2[2])){
    max2_3x=-5;
    max2_3i=-7;
}
//cout <<endl<<"max2_3x="<<max2_3x<<endl;
//cout <<endl<<"max2_3i="<<max2_3i<<endl;


//nếu gặp code = 0; rescue = 1; display, return
    if (Koopa[i]==0){
                   
    arr_kn[i].rescue=1;
      cout << "HP=" << arr_kn[i].HP
        << ", level=" << arr_kn[i].level
        << ", remedy=" << arr_kn[i].remedy
        << ", maidenkiss=" << arr_kn[i].maidenkiss
        << ", phoenixdown=" << arr_kn[i].phoenixdown
        << ", rescue=" << arr_kn[i].rescue << endl;
        exit(0);
        break;
    }
//=======================================Gặp code từ 1=>5
else if ((0<Koopa[i])&&(Koopa[i]<6)){
    
    if((arr_kn[i-1].level>levelO)&&(arr_kn[i-1].level<10)){arr_kn[i].level=arr_kn[i-1].level+1;
        }     //nếu level arr_kn[i-1]>levelO và <10, arr[i]=+1
    else if (arr_kn[i-1].level==levelO){arr_kn[i].level=arr_kn[i-1].level;
        }                     //nếu hòa
    else if (arr_kn[i-1].level<levelO){                                                       //nếu thua
        arr_kn[i].HP=arr_kn[i-1].HP-damage;                        //máu của hiệp sĩ ở mảng i bị trừ sau sự kiện thứ i
        
}
}
//========================================
//nếu gặp Shaman code = 6
else if (Koopa[i]==6){
    //nếu thắng, level + 2
    if((arr_kn[i-1].level>levelO)){arr_kn[i].level=arr_kn[i-1].level+2;
    if(arr_kn[i].level>10){arr_kn[i].level=10;}
        } 
    //nếu hòa, level = level    
    else if (arr_kn[i-1].level==levelO){arr_kn[i].level=arr_kn[i-1].level;
        } 
    //nếu thua
    else if (arr_kn[i-1].level<levelO){
        if (arr_kn[i-1].remedy>=1){arr_kn[i].remedy=arr_kn[i-1].remedy-1;} //nếu thua Shaman và có remedy
        else if(arr_kn[i-1].remedy<1){                                                            //nếu thua và không có remedy
                arr_kn[i].HP=(arr_kn[i-1].HP)/5;
                arr_kn[i+1].HP=(arr_kn[i-1].HP)/5;
                arr_kn[i+2].HP=(arr_kn[i-1].HP)/5;
                //arr_kn[i+3].HP=arr_kn[i+2].HP*5;                  //nhân 5 máu lại sau 3 vòng
                if (arr_kn[i+3].HP>arr_kn[0].HP){arr_kn[i+3].HP=arr_kn[0].HP;
                }
                if ((Koopa[i+1]==6)||(Koopa[i+1]==7)){continue;} //bỏ qua nếu biến thành tí hon/ ếch
        }
    }
}
//===================================================
//gặp Siren Vajsh (code=7);
else if (Koopa[i]==7){  
//nếu thắng, level + 2
    if((arr_kn[i-1].level>levelO)){arr_kn[i].level=arr_kn[i-1].level+2;
    if(arr_kn[i].level>10){arr_kn[i].level=10;}
        } 
    //nếu hòa, level = level    
    else if (arr_kn[i-1].level==levelO){arr_kn[i].level=arr_kn[i-1].level;
        } 
    //nếu thua
    else if (arr_kn[i-1].level<levelO){
            if(arr_kn[i-1].maidenkiss>=1){arr_kn[i].maidenkiss=arr_kn[i-1].maidenkiss-1; //biến thành ếch và có maidenkiss
} 
            else if(arr_kn[i-1].maidenkiss<1){arr_kn[i].level=1;
            arr_kn[i+1].level=1;
            arr_kn[i+2].level=1;  //biến thành ếch không có maidenkiss, level i i+1 i+2 = 1
            arr_kn[i+3].level=arr_kn[i-1].level;                            //level i+3 trở về như i-1
            if ((Koopa[i+1]==6)||(Koopa[i+1]==7)){continue;}        //bỏ qua nếu biến thành tí hon/ ếch
            }                        
    }
}
//===================================================
//nhặt được MushMario
else if (Koopa[i]==11){
arr_kn[i].HP=arr_kn[i-1].HP+(s1%100);
if (arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;}
}
//===================================================
//nhặt được Fibonacci MushFibo (code=12)
else if (Koopa[i]==12){
int fibonacci [100];  //khai báo mảng chứa số fibonacci
fibonacci[0]=0;
fibonacci[1]=1;
fibonacci[2]=1;
for (int i=3; i<100; i++){                
fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
}
int f=0; //biến f dùng để xác định mảng i chứa fibonacci >HP
for (int j=0; j<100; j++){
if (fibonacci[j]>arr_kn[i].HP){f=j-1;}       //nếu fibonacci [j]>HP, HP=fibonnaci [j-1] (giảm về số fibonacci gần nhất)
}
arr_kn[i].HP=fibonacci[f];
}

//====================Gặp Broser (99)
else if (Koopa[i]==99){
    if ((Arthur==1)||((Lancetot==1)&&(arr_kn[i-1].level>=8))||(arr_kn[i-1].level==10)){
        arr_kn[i].level=10;
    }
    else {//Nếu thua Brơser, cout thông tin trước đó và rescue =0; break;
        cout << "HP=" << arr_kn[i-1].HP
        << ", level=" << arr_kn[i-1].level
        << ", remedy=" << arr_kn[i-1].remedy
        << ", maidenkiss=" << arr_kn[i-1].maidenkiss
        << ", phoenixdown=" << arr_kn[i-1].phoenixdown
        << ", rescue=0" << endl;
        break;
    }
}




//============================================================
//nhặt MushGhost (code=13)
char array[100];
string s2;
stringstream ss2;
ss2<<Koopa[i];
ss2>>s2;
for (int i=0; i<s2.length(); i++){
array[i]=s2[i];
}
for (int i=0; i<s2.length(); i++){
   // cout <<"array["<<i<<"]="<<array[i]<<endl;
}
if ((array[0]=='1')&&(array[1]=='3'))//nếu gặp mã là 13, ms bắt đầu từ arr[2]
{
   // cout <<"===================="<<endl;
 //   cout <<endl<<s2.length();
int hpp=arr_kn[i-1].HP;
for (int j=2; j<s2.length(); j++){
        if (array[j]=='1'){//gặp nấm loại 1
              hpp=hpp-(maxi+mini);
        }
        else if (array[j]=='2'){//gặp nấm loại 2
             hpp=hpp-(mtx+mti);
        }
        else if (array[j]=='3'){//gặp nấm loại 3
            hpp=hpp-(maxi2+mini2);
        }
        else if (array[j]=='4'){//gặp nấm loại 4
            hpp=hpp-(max2_3x+max2_3i);
        }
    if ((hpp<0)&&(arr_kn[i-1].phoenixdown>1)){
        hpp=arr_kn[0].HP;
        arr_kn[i].phoenixdown=arr_kn[i-1].phoenixdown-1;
    }
    else {arr_kn[i].rescue=0;}
    arr_kn[i].HP=hpp;
}
}












//===============================================================
//Gặp code 15 16 17
else if (Koopa[i]==15){
    arr_kn[i].remedy=arr_kn[i-1].remedy+1;
    if (arr_kn[i].remedy>99){arr_kn[i].remedy=99;}}
else if (Koopa[i]==16){
    arr_kn[i].maidenkiss=arr_kn[i-1].maidenkiss+1;
    if (arr_kn[i].maidenkiss>99){arr_kn[i].maidenkiss=99;}}
else if (Koopa[i]==17){
    arr_kn[i].phoenixdown=arr_kn[i-1].phoenixdown+1;
    if (arr_kn[i].phoenixdown>99){arr_kn[i].phoenixdown=99;}
}
//==========================================================
//Gặp code 19 
else if (Koopa[i]==19){


//nếu trước đó có sự kiện 19 => bỏ qua.
int check=i;
int countx=0;
for (int j=0; j<check; j++){
    if (Koopa[j]==19){
        countx=countx+1;
    }
}
if (countx>0){
    continue;
}
//==
int count19=0;
int remedy19=arr_kn[i-1].remedy;
int maidenkiss19=arr_kn[i-1].maidenkiss;
int phoenixdown19=arr_kn[i-1].phoenixdown;
for (int m=0; m<r1; m++){
    count19=0; //giải phóng biến count19;
    for (int n=0; n<c1; n++){
        if (arrayAsclepiusPack[m][n]==16){
            remedy19=remedy19+1;
            if (remedy19>99){remedy19=99;}
            arr_kn[i].remedy=remedy19;
            
            count19=count19+1;



        }
        if (arrayAsclepiusPack[m][n]==17){
            maidenkiss19=maidenkiss19+1;
            if (maidenkiss19>99){maidenkiss19=99;}
            arr_kn[i].maidenkiss=maidenkiss19;
            count19=count19+1;
        }
        if (arrayAsclepiusPack[m][n]==18){
            phoenixdown19=phoenixdown19+1;
            if (phoenixdown19>99){phoenixdown19=99;}
            arr_kn[i].phoenixdown=phoenixdown19;
            count19=count19+1;
        }
        if (count19==3){break;}
    }
}


if (((Koopa[i-1]==6)&&(arr_kn[i-2].remedy<1)||(Koopa[i-2]==6)&&(arr_kn[i-3].remedy<1)&&(arr_kn[i-2].remedy<1)||(Koopa[i-3]==6)&&(arr_kn[i-4].remedy<1)&&(arr_kn[i-3].remedy<1)&&(arr_kn[i-2].remedy<1))&&(arr_kn[i].remedy>=1)){
    arr_kn[i].HP=arr_kn[i-1].HP*5;
}
if (((Koopa[i-1]==7)&&(arr_kn[i-2].maidenkiss<1)||(Koopa[i-2]==7)&&(arr_kn[i-3].maidenkiss<1)&&(arr_kn[i-2].maidenkiss<1)||(Koopa[i-3]==7)&&(arr_kn[i-4].maidenkiss<1)&&(arr_kn[i-3].maidenkiss<1)&&(arr_kn[i-2].maidenkiss<1))&&(arr_kn[i].maidenkiss>=1)){
    for (int j=0; j<3; j++){
        if (arr_kn[i-j].level>1){arr_kn[i]=arr_kn[i-j];}
    }
}

  cout << "HP=" << arr_kn[i].HP
        << ", level=" << arr_kn[i].level
        << ", remedy=" << arr_kn[i].remedy
        << ", maidenkiss=" << arr_kn[i].maidenkiss
        << ", phoenixdown=" << arr_kn[i].phoenixdown
        << ", rescue=" << arr_kn[i].rescue << endl;



}
//gặp Merlin (18)

else if (Koopa[i]==18){
    int checkk=0;
    for (int p=0; i<i; p++){
        if (Koopa[p]==18){
            checkk=1;
        }
    }
    if (checkk==1){continue;}
int hppp=arr_kn[i-1].HP;
for (int m=0; m<n9; m++){

            if ((stringMerlin[m][0]=='M')||(stringMerlin[m][0]=='m')){
                if ((stringMerlin[m][1]=='E')||(stringMerlin[m][1]=='e')){
                    if ((stringMerlin[m][2]=='R')||(stringMerlin[m][2]=='r')){
                        if ((stringMerlin[m][3]=='L')||(stringMerlin[m][3]=='l')){
                            if ((stringMerlin[m][4]=='I')||(stringMerlin[m][4]=='i')){
                                if ((stringMerlin[m][5]=='N')||(stringMerlin[m][5]=='n')){
                                        hppp=hppp+2;
                                }
                            }
                        }
                    }
                }
            }

if ((stringMerlin[m][0]=='M')&&(stringMerlin[m][1]=='e')&&(stringMerlin[m][2]=='r')&&(stringMerlin[m][3]=='l')&&(stringMerlin[m][4]=='i')&&(stringMerlin[m][5]=='n')){
    hppp=hppp+1;
}
if ((stringMerlin[m][0]=='m')&&(stringMerlin[m][1]=='e')&&(stringMerlin[m][2]=='r')&&(stringMerlin[m][3]=='l')&&(stringMerlin[m][4]=='i')&&(stringMerlin[m][5]=='n')){
    hppp=hppp+1;
}      
            
        
    arr_kn[i].HP=hppp;
}
if(arr_kn[i].HP>arr_kn[0].HP){arr_kn[i].HP=arr_kn[0].HP;}
  cout << "HP=" << arr_kn[i].HP
        << ", level=" << arr_kn[i].level
        << ", remedy=" << arr_kn[i].remedy
        << ", maidenkiss=" << arr_kn[i].maidenkiss
        << ", phoenixdown=" << arr_kn[i].phoenixdown
        << ", rescue=" << arr_kn[i].rescue << endl;
}

//===========================================================
if (Koopa[i+1]==0){};
if ((arr_kn[i].HP<1)&&(arr_kn[i-1].phoenixdown<1)){
    arr_kn[i].rescue=0;
  cout << "HP=" << arr_kn[i].HP
        << ", level=" << arr_kn[i].level
        << ", remedy=" << arr_kn[i].remedy
        << ", maidenkiss=" << arr_kn[i].maidenkiss
        << ", phoenixdown=" << arr_kn[i].phoenixdown
        << ", rescue=" << arr_kn[i].rescue << endl;
        break;
       }
else if ((arr_kn[i].HP>0)&&(Koopa[i+1]!=0))
{arr_kn[i].rescue=-1;
//cout <<"code=2;"<<"i="<<i;
  cout << "HP=" << arr_kn[i].HP
        << ", level=" << arr_kn[i].level
        << ", remedy=" << arr_kn[i].remedy
        << ", maidenkiss=" << arr_kn[i].maidenkiss
        << ", phoenixdown=" << arr_kn[i].phoenixdown
        << ", rescue=" << arr_kn[1].rescue << endl;
        
        }
else if ((arr_kn[i].HP<=0)&&(arr_kn[i-1].phoenixdown>=1)){
    if (Koopa[i+1]==0){
    arr_kn[i].rescue=1;
arr_kn[i].HP=arr_kn[0].HP;
arr_kn[i].phoenixdown=arr_kn[i-1].phoenixdown-1;
  cout << "HP=" << arr_kn[i].HP
        << ", level=" << arr_kn[i].level
        << ", remedy=" << arr_kn[i].remedy
        << ", maidenkiss=" << arr_kn[i].maidenkiss
        << ", phoenixdown=" << arr_kn[i].phoenixdown
        << ", rescue=" << arr_kn[i].rescue << endl;
        break;
    }
    else {
    arr_kn[i].rescue=-1;
arr_kn[i].HP=arr_kn[0].HP;
arr_kn[i].phoenixdown=arr_kn[i-1].phoenixdown-1;
  cout << "HP=" << arr_kn[i].HP
        << ", level=" << arr_kn[i].level
        << ", remedy=" << arr_kn[i].remedy
        << ", maidenkiss=" << arr_kn[i].maidenkiss
        << ", phoenixdown=" << arr_kn[i].phoenixdown
        << ", rescue=" << arr_kn[i].rescue << endl;
    }
        }
}
}
