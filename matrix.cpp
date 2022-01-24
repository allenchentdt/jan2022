/******** Thuật Toán ********
1. Với mỗi ứng viên vị trí (m[p]=1) thì tính số ảnh hưởng v[p] đến các vị trí xung quanh
(left,upleft,downleft,right,upright,downright).
2. Tìm vị trí (p_max) có số ảnh hưởng lớn nhất affect_max.
3. Xoá bỏ ứng viên vị trí này (gán m[p]=0) và tính toán lại số ảnh hưởng của các vị trí xung quanh.
4. Lặp lại bước 1-3 cho đến khi affect_max=0.
5. Các vị trí còn lại sẽ không bị ảnh hưởng hay gây ảnh hưởng đến bất kỳ vị trí nào.
********************************************/

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;

int arrange(bool m[], int rows, int cols) {
   int count=0;//to count the selected postions
   int p,left,upleft,downleft,right,upright,downright;//postion value in the 1D array 
   int p_max;//postion with the max_affect
   int affect_max;
   int size;//size of the matrix

   if(cols==1){
      for(p=0;p<=rows-1;p++) if(m[p]==1) count++;
      return count;
   }

   if(cols==2){
      if(rows==1){/* 1x2 matrix */
         if(m[0]==1) return 1;
         else if(m[1]==1) return 1;
         else return 0;
      }
      if(rows==2){/* 2x2 matrix */
         vector< set<short> > v(4);
         if(m[0]==1){
            if(m[1]==1) v[0].insert(1);
            if(m[3]==1) v[0].insert(3);
         }
         if(m[1]==1){
            if(m[0]==1) v[1].insert(0);
            if(m[2]==1) v[1].insert(2);
         }
         if(m[2]==1){
            if(m[3]==1) v[2].insert(3);
            if(m[1]==1) v[2].insert(1);
         }
         if(m[3]==1){
            if(m[2]==1) v[3].insert(2);
            if(m[0]==1) v[3].insert(0);
         }
          
	 /*Find the positions with affect_max>0 to remove it*/
         do{
            p_max=0;affect_max=0;
            for(p=0;p<4;p++) if(m[p]==1 && v[p].size() > affect_max) {affect_max = v[p].size(); p_max=p;}
            if(affect_max > 0) {m[p_max]=0; for(auto x:v[p_max]) v[x].erase(p_max);}
         }while(affect_max > 0);
         
         for(p=0;p<4;p++) if(m[p]==1) count++;
         return count;
      }
      if(rows>=3){/* rows*2 matrix */
         size = rows*2;
         vector< set<short> > v(size);
         
         /*upleft corner*/
         p=0;
         if(m[p]==1){
            right=p+1;downright=right+cols;
            if(m[right]==1) v[p].insert(right);
            if(m[downright]==1) v[p].insert(downright);
         }
         /*upright corner*/
         p=cols-1;
         if(m[p]==1){
            left=p-1;downleft=left+cols;
            if(m[left]==1) v[p].insert(left);
            if(m[downleft]==1) v[p].insert(downleft);
         }
         /*downleft corner*/
         p=(rows-1)*cols+0;
         if(m[p]==1){
            right=p+1;upright=right-cols;
            if(m[right]==1) v[p].insert(right);
            if(m[upright]==1) v[p].insert(upright);
         }
         /*downright corner*/
         p=(rows-1)*cols+(cols-1);
         if(m[p]==1){
            left=p-1;upleft=left-cols;
            if(m[left]==1) v[p].insert(left);
            if(m[upleft]==1) v[p].insert(upleft);
         }

         /*left column*/
         for(p=1*cols;p<=(rows-2)*cols;p+=cols) if(m[p]==1){
            upright=p-cols+1;downright=p+cols+1;
            if(m[upright]==1) v[p].insert(upright);
            if(m[downright]==1) v[p].insert(downright);
         }
         /*right column*/
         for(p=1*cols+(cols-1);p<=(rows-2)*cols+(cols-1);p+=cols) if(m[p]==1){
               upleft=p-cols-1; downleft=p+cols-1;
               if(m[upleft]==1) v[p].insert(upleft);
               if(m[downleft]==1) v[p].insert(downleft);
            }

         /*Find the positions with affect_max>0 to remove it*/
         do{
            p_max=0;affect_max=0;
            for(p=0;p<size;p++) if(m[p]==1 && v[p].size() > affect_max){ affect_max = v[p].size(); p_max=p;}
            if(affect_max > 0) {m[p_max]=0; for(auto x:v[p_max]) v[x].erase(p_max);}
         }while(affect_max>0);

         for(p=0;p<size;p++) if(m[p]==1) count++;
         return count;
      }
   }
   
   if(cols>=3){
      if(rows==1){/* 1xcols matrix*/
         int size = cols*1;
         vector< set<short> > v(size);

         /*left corner*/
         p=0;
         if(m[p]==1){
            right=p+1;
            if(m[right]==1) v[p].insert(right);
         }
         /*right corner*/
         p=cols-1;
         if(m[p]==1){
            left=p-1;
            if(m[left]==1) v[p].insert(left);
         }
         /*first row*/
         for(p=1;p<=cols-2;p++) if(m[p]==1){
            right=p+1;left=p-1;
            if(m[right]==1) v[p].insert(right);
            if(m[left]==1) v[p].insert(left);
         }
       
         /*Find the positions with affect_max>0 to remove it*/
         do{
            p_max=0;affect_max=0;
            for(p=0;p<size;p++) if(m[p]==1 && v[p].size() > affect_max) {affect_max = v[p].size(); p_max=p;}
            if(affect_max > 0) {m[p_max]=0; for(auto x:v[p_max]) v[x].erase(p_max);}
         }while(affect_max > 0);

         for(p=0;p<size;p++) if(m[p]==1) count++;
         return count;         
      }
      if(rows==2){/* 2xcols matrix */
         size = rows*cols;
         vector< set<short> > v(size);
          
         /*upleft corner*/
         p=0;
         if(m[p]==1){
            right=p+1;downright=right+cols;
            if(m[right]==1) v[p].insert(right);
            if(m[downright]==1) v[p].insert(downright);
         }
         /*upright corner*/
         p=cols-1;
         if(m[p]==1){
            left=p-1;downleft=left+cols;
            if(m[left]==1) v[p].insert(left);
            if(m[downleft]==1) v[p].insert(downleft);
         }
         /*downleft corner*/
         p=(rows-1)*cols+0;
         if(m[p]==1){
            right=p+1;upright=right-cols;
            if(m[right]==1) v[p].insert(right);
            if(m[upright]==1) v[p].insert(upright);
         }
         /*downright corner*/
         p=(rows-1)*cols+(cols-1);
         if(m[p]==1){
            left=p-1;upleft=left-cols;
            if(m[left]==1) v[p].insert(left);
            if(m[upleft]==1) v[p].insert(upleft);
         }

         /*fisrt row*/
         for(p=1;p<=cols-2;p++) if(m[p]==1){
            right=p+1;downright=right+cols;left=p-1;downleft=left+cols;
            if(m[right]==1) v[p].insert(right);
            if(m[left]==1) v[p].insert(left);
            if(m[downright]==1) v[p].insert(downright);
            if(m[downleft]==1) v[p].insert(downleft);
         }
         /*last row*/
         for(p=(rows-1)*cols+1;p<=(rows-1)*cols+(cols-2);p++) if(m[p]==1){
            right=p+1;upright=right-cols;left=p-1;upleft=left-cols;
            if(m[right]==1) v[p].insert(right);
            if(m[left]==1) v[p].insert(left);
            if(m[upright]==1) v[p].insert(upright);
            if(m[upleft]==1) v[p].insert(upleft);
         }
         
         /*Find the positions with affect_max>0 to remove it*/
         do{
            p_max=0;affect_max=0;
            for(p=0;p<size;p++) if(m[p]==1 && v[p].size() > affect_max) {affect_max = v[p].size(); p_max=p;}
            if(affect_max > 0) {m[p_max]=0; for(auto x:v[p_max]) v[x].erase(p_max);}
         }while(affect_max > 0);

         for(p=0;p<size;p++) if(m[p]==1) count++;
         return count;
      }
      if(rows>=3){/* rows x cols matrix where rows,cols>=3 */
         size = rows*cols;
         vector< set<short> > v(size);

         /*upleft corner*/
         p=0;
         if(m[p]==1){
            right=p+1;downright=right+cols;
            if(m[right]==1) v[p].insert(right);
            if(m[downright]==1) v[p].insert(downright);
         }
         /*upright corner*/
         p=cols-1;
         if(m[p]==1){
            left=p-1;downleft=left+cols;
            if(m[left]==1) v[p].insert(left);
            if(m[downleft]==1) v[p].insert(downleft);
         }
         /*downleft corner*/
         p=(rows-1)*cols+0;
         if(m[p]==1){
            right=p+1;upright=right-cols;
            if(m[right]==1) v[p].insert(right);
            if(m[upright]==1) v[p].insert(upright);
         }
         /*downright corner*/
         p=(rows-1)*cols+(cols-1);
         if(m[p]==1){
            left=p-1;upleft=left-cols;
            if(m[left]==1) v[p].insert(left);
            if(m[upleft]==1) v[p].insert(upleft);
         }

         /*fisrt row*/
         for(p=1;p<=cols-2;p++) if(m[p]==1){
            right=p+1;downright=right+cols;left=p-1;downleft=left+cols;
            if(m[right]==1) v[p].insert(right);
            if(m[left]==1) v[p].insert(left);
            if(m[downright]==1) v[p].insert(downright);
            if(m[downleft]==1) v[p].insert(downleft);
         }
         /*last row*/
         for(p=(rows-1)*cols+1;p<=(rows-1)*cols+(cols-2);p++) if(m[p]==1){
            right=p+1;upright=right-cols;left=p-1;upleft=left-cols;
            if(m[right]==1) v[p].insert(right);
            if(m[left]==1) v[p].insert(left);
            if(m[upright]==1) v[p].insert(upright);
            if(m[upleft]==1) v[p].insert(upleft);
         }
         
         /*left column*/
         for(p=1*cols;p<=(rows-2)*cols;p+=cols) if(m[p]==1){
            upright=p-cols+1;downright=p+cols+1;
            if(m[upright]==1) v[p].insert(upright);
            if(m[downright]==1) v[p].insert(downright);
         }
         /*right column*/
         for(p=1*cols+(cols-1);p<=(rows-2)*cols+(cols-1);p+=cols) if(m[p]==1){
               upleft=p-cols-1; downleft=p+cols-1;
               if(m[upleft]==1) v[p].insert(upleft);
               if(m[downleft]==1) v[p].insert(downleft);
            }
         
         /*inside position*/
         int r,c;
         for(r=1;r<=rows-2;r++)
            for(c=1;c<=cols-2;c++){ 
               p=r*cols+c;
               if(m[p]==1){
                  left=p-1;upleft=left-cols;downleft=left+cols; right=p+1;upright=right-cols;downright=right+cols;
                  if(m[left]==1) v[p].insert(left);
                  if(m[upleft]==1) v[p].insert(upleft);
                  if(m[downleft]==1) v[p].insert(downleft);
                  if(m[right]==1) v[p].insert(right);
                  if(m[upright]==1) v[p].insert(upright);
                  if(m[downright]==1) v[p].insert(downright);
               }  
            }
         /*Find the positions with affect_max>0 to remove it*/
         do{
            p_max=0;affect_max=0;
            for(p=0;p<size;p++) if(m[p]==1 && v[p].size() > affect_max) {affect_max = v[p].size(); p_max=p;}
            if(affect_max>0){m[p_max]=0; for(auto x:v[p_max]) v[x].erase(p_max);}
         }while(affect_max>0);

         for(p=0;p<size;p++) if(m[p]==1) count++;
         return count;
      } 
   }   
}

int main(){
   ifstream fin;
   ofstream fout;
   int rows=0,cols=0,size,p,r;
   string msg;
   
   /*Calculate rows and cols*/
   fin.open("input.txt");
   while(getline(fin,msg)){
      p=0;
      for(r=0;r<msg.length();r++) if(msg[r] == '0' || msg[r] == '1') { cols++; p++; }
      if(p>0) rows++;
   }
   fin.close();
   cols=cols/rows;

   /*Read the data into 1D matrix*/
   size = rows * cols;
   bool *m = new bool[size];
   fin.open("input.txt");
   for(p=0;p<size;p++) fin >> m[p];
   fin.close();
   
   /*Output the max number of seats*/  
   fout.open("output.txt");
   int count = arrange(m,rows,cols);
   fout << count; 
   fout.close();
   
   return 0;
}
