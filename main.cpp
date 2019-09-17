#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdio>
#include <string>
using namespace std;
int **matriz;
int x,y;
struct robot{
    int x;
    int y;
    int direccion; 

};
enum direcciones{N,E,S,O};
direcciones direccion;

void print(int **elements,int x,int y){
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            cout<<elements[i][j]<<" ";
        }
        cout<<endl;
    }
}

string que_tipo(int a){
    switch (a){
        case 0:return "N";
        case 1:return "E";
        case 2:return "S";
        case 3:return "W";
    }
    return "falso";
}


void mover_robot(robot a,char orden,string accion){
    
    
    if (orden=='N'){
        a.direccion=0;
        
    }else{
        if (orden=='E'){
            a.direccion=1;
        }
        else{
            if (orden=='S'){
                a.direccion=2;
            }
            else{
                a.direccion=3;
            }
        }
    }
    
    
    for (int i=0;i<accion.length();i++){
        // cout<<"iteracion"<<i<<endl;
        // cout<<a.direccion<<endl;
        switch(accion[i]){
            case 'R':{
                if (a.direccion==3){
                    a.direccion=0;
                }else{
                    // cout<<"direccion"<<a.direccion<<endl;
                    a.direccion+=1;
                    // cout<<a.direccion<<endl;
                }
                break;
                }
            case 'L':{
                if (a.direccion==0){
                    a.direccion=3;
                }else{
                    a.direccion-=1;
                }break;
             }
            case 'F':{
                // cout<<"no se que estoy haciendo"<<a.direccion<<endl;
                switch(a.direccion){
                    case 0:{
                        if (a.y==y ){
                            if (matriz[a.x][a.y]==1){
                                //print(matriz,x,y);
                                break;
                            }else{
                                matriz[a.x][a.y]=1;
                                cout<<a.x<<" "<<a.y<<" "<<que_tipo(a.direccion)<<" LOST";
                                //print(matriz,x,y);
                                return;
                            }
                        }else{
                            a.y+=1;    
                            //print(matriz,x,y);
                            break;
                        }
                        
                        };


                    case 1:{
                        //cout<<"numero"<<a.x+1<<" el rango es "<<x<<endl;
                        if (a.x==x ){
                            //cout<<"HOLA"<<endl;
                            if (matriz[a.x][a.y]==1){
                                //print(matriz,x,y);
                                break;
                            }else{
                                matriz[a.x][a.y]=1;
                                cout<<a.x<<" "<<a.y<<" "<<que_tipo(a.direccion)<<" LOST";
                                //print(matriz,x,y);
                                return;
                            }
                        }else{
                            //print(matriz,x,y);
                            a.x+=1;
                            //cout<<a.x<<","<<a.y<<endl;
                            break;
                        }
                        
                        };
                    case 2:{
                        if (a.y==0){
                            if (matriz[a.x][a.y]==1){
                                //print(matriz,x,y);

                                break;
                            }else{
                                matriz[a.x][a.y]=1;
                                
                                cout<<a.x<<" "<<a.y<<" "<<que_tipo(a.direccion)<<" LOST";
                                //print(matriz,x,y);
                                return;
                            }
                        }else{
                            a.y-=1;
                            //print(matriz,x,y);
                            break;
                        }
                        
                        };
                    case 3:{
                        if (a.x==0){
                            if (matriz[a.x][a.y]==1){
                                //print(matriz,x,y);

                                break;
                            }else{
                                matriz[a.x][a.y]=1;
                                
                                cout<<a.x<<" "<<a.y<<" "<<que_tipo(a.direccion)<<" LOST";
                                //print(matriz,x,y);
                                return;
                            }
                        }else{
                            //print(matriz,x,y);
                            a.x-=1;
                            break;
                        }
                        
                        };
                    
                }
            }
            


        }

    if (i==accion.length()-1){
        cout<<a.x<<" "<<a.y<<" "<<que_tipo(a.direccion);
    }

    }
}


int main(){
    cin>>x;
    cin>>y;

    
    matriz=new int*[x+1];
    for (int i=0;i<x+1;i++){
        matriz[i]=new int[y+1];
        
    }

    for (int i=0;i<x+1;i++){
        for (int j=0;j<y+1;j++){
            matriz[i][j]=0;
        }
    }
    robot a;    
    string accion;
    char orden;
    
    while(cin.peek()!=-1){
        cin>>a.x>>a.y>>orden>>accion;
        mover_robot(a,orden,accion); 
        cout<<endl;

        cin.ignore();
    }


    


}