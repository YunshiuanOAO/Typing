#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;
int main(){
    int k,i,j,t;
    clock_t a,b;
    int num[10];
    char p[80][80];
    char op;
    string w;
    FILE *f1=fopen("Quention Bank.txt","r");

    fscanf(f1,"%d",&k);

    for(i=0;i<k;i++){
        fscanf(f1,"%s",p[i]);
    }
    fclose(f1);
    while(1){
        cout <<"英文單字打字訓練"<<endl;
        cout <<"訓練是十個單字為一次"<<endl;
        cout <<"按s開始"<<endl;
        cout <<"按q離開"<<endl;
        cin >> op;
        switch(op){
            case 's':
                a=clock();
                srand(time(NULL));
                for(i=0;i<10;i++){
                    while(1){
                        t=rand()%k;
                        for(j=0;j<i;j++){
                            if(num[j]==t)break;
                        }
                        if(j==i)break;
                    }
                    num[i]=t;

                    while(1){
                        cout << p[t] << endl;
                        cin >> w;
                        if( w==(string)p[t] )break;
                        cout << "打錯囉" << endl;
                    }
                }
                b=clock();
                cout << double(b-a)/CLOCKS_PER_SEC<< "秒" << endl;
                break;
            case 'q':
                return 0;
                break;
        }
        system("pause");
        system("cls");
    }
}
