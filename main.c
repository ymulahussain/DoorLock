#include <stdio.h>
#define PIN 1089
int main() {
    int doorState, rL, yL, gL, lock, timer = 0, entryPin, errcount=0,buzzer;
    printf("enter door state:\n");
    scanf("%d", &doorState);
    for(timer;timer<=10;timer++){
     if (doorState==0){
        rL = 0, yL = 0, gL = 1, lock = 0, timer--;
      }else if(doorState==1) {
        lock=0,gL=1,yL=0,rL=0;
        if (timer==10){
            lock=1;yL=1, gL=0,rL=0;
            printf("enter code to access office\n");
            scanf("%d",&entryPin);
          if (entryPin==PIN){
            lock=0, gL=1, yL=rL=0;
            doorState=0;
          }else{
            errcount++;
            if(errcount<4){
              rL=1,yL=0,gL=0,lock=1,buzzer=1;
            }
          }
        }
     }
    }
}